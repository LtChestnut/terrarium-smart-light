#include "light.h"

#include <Arduino.h>
#include <Preferences.h>
#include <math.h>
#include <string.h>

#include <atomic>

#include "config.h"
#include "power.h"
#include "rgb.h"
#include "white.h"

namespace light {
namespace {

constexpr uint32_t kSaveDelayMs = 5000;  // debounce NVS writes while a knob is turning
constexpr uint32_t kStateVersion = 1;

SemaphoreHandle_t s_mu = nullptr;
State s_state;
std::atomic<uint32_t> s_rev{1};
uint32_t s_dirtyAtMs = 0;
bool s_dirty = false;

struct Lock {
  Lock() { xSemaphoreTake(s_mu, portMAX_DELAY); }
  ~Lock() { xSemaphoreGive(s_mu); }
};

// Linear drive targets: white duty 0..1 and the ring colour 0..1 per component.
struct Frame {
  float w = 0, r = 0, g = 0, b = 0;
};

void load() {
  Preferences p;
  if (!p.begin("light", true)) {
    strlcpy(s_state.nickname, DEVICE_NICKNAME, sizeof(s_state.nickname));
    return;
  }
  if (p.getUInt("ver", 0) == kStateVersion) {
    s_state.on = p.getBool("on", false);
    s_state.brightness = p.getUChar("bri", DEFAULT_BRIGHTNESS);
    s_state.hue = p.getUShort("hue", 0);
    s_state.saturation = p.getUChar("sat", 100);
    s_state.colorTemp = p.getUShort("ct", WHITE_NATIVE_K);
  }
  if (p.getString("nick", s_state.nickname, sizeof(s_state.nickname)) == 0) {
    strlcpy(s_state.nickname, DEVICE_NICKNAME, sizeof(s_state.nickname));
  }
  p.end();
}

void save(const State &st) {
  Preferences p;
  if (!p.begin("light", false)) return;
  p.putUInt("ver", kStateVersion);
  p.putBool("on", st.on);
  p.putUChar("bri", st.brightness);
  p.putUShort("hue", st.hue);
  p.putUChar("sat", st.saturation);
  p.putUShort("ct", st.colorTemp);
  p.putString("nick", st.nickname);
  p.end();
}

// Perceptual brightness 1..100 % -> linear 0..1.
float curve(uint8_t pct) { return powf(pct / 100.0f, GAMMA); }

void hueToRgb(uint16_t hue, float &r, float &g, float &b) {
  const float h = (hue % 360) / 60.0f;
  const float x = 1.0f - fabsf(fmodf(h, 2.0f) - 1.0f);
  switch (static_cast<int>(h)) {
    case 0: r = 1; g = x; b = 0; break;
    case 1: r = x; g = 1; b = 0; break;
    case 2: r = 0; g = 1; b = x; break;
    case 3: r = 0; g = x; b = 1; break;
    case 4: r = x; g = 0; b = 1; break;
    default: r = 1; g = 0; b = x; break;
  }
}

Frame targetFor(const State &st) {
  Frame f;
  if (!st.on) return f;
  const float lvl = curve(st.brightness);
  if (st.colorTemp > 0) {
    f.w = lvl;
    // Tint for the colour temperature the white string can't produce itself.
    float t = 0, cr = 0, cg = 0, cb = 0;
    if (st.colorTemp < WHITE_NATIVE_K) {
      t = float(WHITE_NATIVE_K - st.colorTemp) / (WHITE_NATIVE_K - CT_MIN_K);
      cr = 1.0f; cg = 0.35f; cb = 0.02f;   // amber
    } else if (st.colorTemp > WHITE_NATIVE_K) {
      t = float(st.colorTemp - WHITE_NATIVE_K) / (CT_MAX_K - WHITE_NATIVE_K);
      cr = 0.25f; cg = 0.45f; cb = 1.0f;   // sky blue
    }
    t = t > 1 ? 1 : t;
    const float k = t * CCT_TINT_MAX * lvl;
    f.r = cr * k; f.g = cg * k; f.b = cb * k;
  } else {
    const float s = st.saturation / 100.0f;
    float r, g, b;
    hueToRgb(st.hue, r, g, b);
    f.w = lvl * (1.0f - s);
    f.r = r * s * lvl; f.g = g * s * lvl; f.b = b * s * lvl;
  }
  return f;
}

// Fade in perceptual space (linear^(1/gamma)) at a fixed full-scale rate.
float toP(float lin) { return lin > 0 ? powf(lin, 1.0f / GAMMA) : 0.0f; }
float toL(float p) { return p > 0 ? powf(p, GAMMA) : 0.0f; }
float slew(float cur, float target, float step) {
  if (cur < target) return cur + step < target ? cur + step : target;
  return cur - step > target ? cur - step : target;
}

uint8_t to8(float v) {
  const int x = static_cast<int>(v * 255.0f + 0.5f);
  return x < 0 ? 0 : (x > 255 ? 255 : x);
}

void outputTask(void *) {
  const float step = 1000.0f / (FADE_MS * OUTPUT_HZ);
  const TickType_t period = pdMS_TO_TICKS(1000 / OUTPUT_HZ);
  Frame p;  // current perceptual levels
  uint32_t n = 0;
  TickType_t wake = xTaskGetTickCount();
  for (;;) {
    if (n++ % (OUTPUT_HZ / 10) == 0) power::update();

    State st;
    bool doSave = false;
    {
      Lock l;
      st = s_state;
      if (s_dirty && millis() - s_dirtyAtMs >= kSaveDelayMs) {
        s_dirty = false;
        doSave = true;
      }
    }
    if (doSave) save(st);

    const Frame t = targetFor(st);
    p.w = slew(p.w, toP(t.w), step);
    p.r = slew(p.r, toP(t.r), step);
    p.g = slew(p.g, toP(t.g), step);
    p.b = slew(p.b, toP(t.b), step);

    float w = toL(p.w);
    const rgb::Pixel c{to8(toL(p.r)), to8(toL(p.g)), to8(toL(p.b))};
    rgb::Pixel px[NUM_PIXELS];
    for (auto &x : px) x = c;
    power::limit(w, px, NUM_PIXELS);  // the only path to the drivers
    white::write(w);
    rgb::show(px, NUM_PIXELS);

    vTaskDelayUntil(&wake, period);
  }
}

}  // namespace

void begin() {
  s_mu = xSemaphoreCreateMutex();
  load();
  Serial.printf("[light] restored: %s, %u %%, %s\n", s_state.on ? "on" : "off", s_state.brightness,
                s_state.colorTemp ? "white" : "colour");
  white::begin();
  rgb::begin();
  power::begin();
  xTaskCreate(outputTask, "output", 4096, nullptr, 5, nullptr);
}

State get() {
  Lock l;
  return s_state;
}

uint32_t revision() { return s_rev.load(); }

State apply(const Patch &p) {
  Lock l;
  State &s = s_state;
  const State &v = p.v;
  if (p.mask & Patch::On) s.on = v.on;
  if (p.mask & Patch::Brightness) s.brightness = v.brightness < 1 ? 1 : (v.brightness > 100 ? 100 : v.brightness);
  if (p.mask & Patch::Hue) s.hue = v.hue % 361;
  if (p.mask & Patch::Saturation) s.saturation = v.saturation > 100 ? 100 : v.saturation;
  if (p.mask & Patch::ColorTemp) {
    uint16_t k = v.colorTemp;
    if (k != 0) k = k < CT_MIN_K ? CT_MIN_K : (k > CT_MAX_K ? CT_MAX_K : k);
    s.colorTemp = k;
  } else if (p.mask & (Patch::Hue | Patch::Saturation)) {
    s.colorTemp = 0;  // a colour without a temperature means colour mode, as on the L530
  }
  if (p.mask & Patch::Nickname) strlcpy(s.nickname, v.nickname, sizeof(s.nickname));
  s_dirty = true;
  s_dirtyAtMs = millis();
  s_rev.fetch_add(1);
  return s;
}

}  // namespace light
