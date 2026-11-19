#include "tapo_device.h"

#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <mbedtls/base64.h>
#include <mbedtls/sha256.h>
#include <string.h>

#include "config.h"
#include "light.h"
#include "power.h"

namespace tapo_device {
namespace {

// SmartErrorCode values as python-kasa names them.
constexpr int kOk = 0;
constexpr int kJsonDecodeFail = -1003;
constexpr int kParamsError = -1008;
constexpr int kUnknownMethod = -1010;

String b64(const char *s) {
  size_t n = 0;
  const size_t len = strlen(s);
  std::string out(4 * ((len + 2) / 3) + 1, '\0');
  mbedtls_base64_encode(reinterpret_cast<uint8_t *>(&out[0]), out.size(), &n,
                        reinterpret_cast<const uint8_t *>(s), len);
  out.resize(n);
  return String(out.c_str());
}

bool unb64(const char *s, char *out, size_t outLen) {
  size_t n = 0;
  if (mbedtls_base64_decode(reinterpret_cast<uint8_t *>(out), outLen - 1, &n,
                            reinterpret_cast<const uint8_t *>(s), strlen(s)) != 0)
    return false;
  out[n] = '\0';
  return true;
}

// Stable 40-hex-digit device id derived from the MAC (real devices use an opaque id).
String deviceId() {
  uint8_t mac[6];
  WiFi.macAddress(mac);
  uint8_t h[32];
  mbedtls_sha256(mac, sizeof(mac), h, 0);
  char hex[41];
  for (int i = 0; i < 20; ++i) snprintf(hex + 2 * i, 3, "%02X", h[i]);
  return hex;
}

String macDashes() {
  String m = WiFi.macAddress();  // AA:BB:CC:DD:EE:FF
  m.replace(':', '-');
  return m;
}

int signalLevel(int rssi) { return rssi > -50 ? 3 : rssi > -70 ? 2 : 1; }

void deviceInfo(JsonObject r) {
  const light::State st = light::get();
  const power::Status ps = power::status();
  const int rssi = WiFi.RSSI();

  r["device_id"] = deviceId();
  r["fw_ver"] = FW_VERSION " terrarium";
  r["hw_ver"] = "1.0";
  r["type"] = TAPO_DEVICE_TYPE;
  r["model"] = TAPO_MODEL;
  r["mac"] = macDashes();
  r["hw_id"] = "";
  r["fw_id"] = "";
  r["oem_id"] = "";
  r["ip"] = WiFi.localIP().toString();
  r["time_diff"] = 0;
  r["ssid"] = b64(WiFi.SSID().c_str());
  r["rssi"] = rssi;
  r["signal_level"] = signalLevel(rssi);
  r["specs"] = "";
  r["lang"] = "en_US";
  r["avatar"] = "bulb";
  r["region"] = "";
  r["nickname"] = b64(st.nickname);
  r["has_set_location_info"] = false;

  r["device_on"] = st.on;
  r["brightness"] = st.brightness;
  r["hue"] = st.hue;
  r["saturation"] = st.saturation;
  r["color_temp"] = st.colorTemp;
  JsonArray range = r["color_temp_range"].to<JsonArray>();
  range.add(CT_MIN_K);
  range.add(CT_MAX_K);
  r["dynamic_light_effect_enable"] = false;
  r["overheated"] = ps.overTemp;
  JsonObject def = r["default_states"].to<JsonObject>();
  def["type"] = "last_states";
  def["state"].to<JsonObject>();

  // Not part of the Tapo schema; clients ignore unknown keys. Handy for diagnostics.
  JsonObject x = r["terrarium"].to<JsonObject>();
  x["board_c"] = static_cast<int>(ps.boardC * 10) / 10.0f;
  x["ntc_fault"] = ps.ntcFault;
  x["thermal_factor"] = ps.thermalFactor;
  x["source"] = power::sourceName(ps.source);
  x["cc_mv"] = ps.ccMv;
  x["budget_ma"] = ps.budgetMa;
  x["led_ma"] = ps.lastEstimateMa;
  x["limited"] = ps.limited;
  x["native_k"] = WHITE_NATIVE_K;
}

int setDeviceInfo(JsonObjectConst p) {
  light::Patch patch;
  bool colourOrLevel = false;
  if (p["device_on"].is<bool>()) {
    patch.mask |= light::Patch::On;
    patch.v.on = p["device_on"];
  }
  if (p["brightness"].is<int>()) {
    const int v = p["brightness"];
    if (v < 1 || v > 100) return kParamsError;
    patch.mask |= light::Patch::Brightness;
    patch.v.brightness = v;
    colourOrLevel = true;
  }
  if (p["hue"].is<int>()) {
    const int v = p["hue"];
    if (v < 0 || v > 360) return kParamsError;
    patch.mask |= light::Patch::Hue;
    patch.v.hue = v;
    colourOrLevel = true;
  }
  if (p["saturation"].is<int>()) {
    const int v = p["saturation"];
    if (v < 0 || v > 100) return kParamsError;
    patch.mask |= light::Patch::Saturation;
    patch.v.saturation = v;
    colourOrLevel = true;
  }
  if (p["color_temp"].is<int>()) {
    const int v = p["color_temp"];
    if (v < 0 || v > 10000) return kParamsError;
    patch.mask |= light::Patch::ColorTemp;
    patch.v.colorTemp = v;
    // color_temp 0 alongside hue/sat is how clients select colour mode; on its own it
    // isn't a colour change.
    if (v) colourOrLevel = true;
  }
  if (p["nickname"].is<const char *>()) {
    if (!unb64(p["nickname"], patch.v.nickname, sizeof(patch.v.nickname))) return kParamsError;
    patch.mask |= light::Patch::Nickname;
  }
  // Changing level or colour switches the light on unless the request says otherwise.
  if (colourOrLevel && !(patch.mask & light::Patch::On)) {
    patch.mask |= light::Patch::On;
    patch.v.on = true;
  }
  if (!patch.mask) return kParamsError;
  light::apply(patch);
  return kOk;
}

void componentNego(JsonObject r) {
  static const struct {
    const char *id;
    int ver;
  } kComponents[] = {
      {"device", 2}, {"brightness", 1}, {"color", 1}, {"color_temperature", 1}, {"default_states", 1},
  };
  JsonArray list = r["component_list"].to<JsonArray>();
  for (const auto &c : kComponents) {
    JsonObject o = list.add<JsonObject>();
    o["id"] = c.id;
    o["ver_code"] = c.ver;
  }
}

void deviceUsage(JsonObject r) {
  for (const char *k : {"time_usage", "power_usage", "saved_power"}) {
    JsonObject o = r[k].to<JsonObject>();
    o["today"] = 0;
    o["past7"] = 0;
    o["past30"] = 0;
  }
}

// Runs one method; fills `result` and returns the error code.
int dispatch(const char *method, JsonObjectConst params, JsonObject result) {
  if (!method) return kParamsError;
  if (!strcmp(method, "get_device_info")) {
    deviceInfo(result);
    return kOk;
  }
  if (!strcmp(method, "set_device_info")) return setDeviceInfo(params);
  if (!strcmp(method, "component_nego")) {
    componentNego(result);
    return kOk;
  }
  if (!strcmp(method, "get_device_usage")) {
    deviceUsage(result);
    return kOk;
  }
  return kUnknownMethod;
}

}  // namespace

std::string handle(const char *request, size_t len) {
  JsonDocument req;
  JsonDocument resp;
  if (deserializeJson(req, request, len)) {
    resp["error_code"] = kJsonDecodeFail;
  } else {
    const char *method = req["method"];
    if (method && !strcmp(method, "multipleRequest")) {
      // python-kasa batches queries: {"requests":[{"method":..,"params":..},..]}
      JsonArray out = resp["result"]["responses"].to<JsonArray>();
      for (JsonObjectConst r : req["params"]["requests"].as<JsonArrayConst>()) {
        JsonObject o = out.add<JsonObject>();
        o["method"] = r["method"];
        const int ec = dispatch(r["method"], r["params"], o["result"].to<JsonObject>());
        o["error_code"] = ec;
        if (ec != kOk) o.remove("result");
      }
      resp["error_code"] = kOk;
    } else {
      const int ec = dispatch(method, req["params"], resp["result"].to<JsonObject>());
      if (ec != kOk) resp.remove("result");
      resp["error_code"] = ec;
      if (method && strcmp(method, "get_device_info") != 0) {
        Serial.printf("[tapo] %s -> %d\n", method, ec);
      }
    }
  }
  std::string out;
  serializeJson(resp, out);
  return out;
}

}  // namespace tapo_device
