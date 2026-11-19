#include "power.h"

#include <Arduino.h>
#include <math.h>

#include "config.h"
#include "pins.h"

namespace power {
namespace {

Status s_st;
portMUX_TYPE s_mux = portMUX_INITIALIZER_UNLOCKED;

Source s_candidate = Source::None;
uint8_t s_candidateCount = 0;
bool s_tempInit = false;

// Plan section 3: voltage across the 5.1 kOhm Rd for each Rp advertisement.
// Readings in the gaps between bands keep the previous classification.
bool classify(uint16_t mv, Source &out) {
  if (mv < 200) { out = Source::None; return true; }
  if (mv >= 250 && mv <= 610) { out = Source::Default; return true; }
  if (mv >= 700 && mv <= 1160) { out = Source::Usb1A5; return true; }
  if (mv >= 1310 && mv <= 2040) { out = Source::Usb3A; return true; }
  return false;
}

uint16_t budgetFor(Source s) {
  if (POWER_OVERRIDE_MA > 0) return POWER_OVERRIDE_MA;
  switch (s) {
    case Source::Default: return BUDGET_DEFAULT_MA;
    case Source::Usb1A5: return BUDGET_1A5_MA;
    case Source::Usb3A: return BUDGET_3A_MA;
    default: return BUDGET_NONE_MA;
  }
}

float ntcCelsius(uint16_t mv, bool &fault) {
  constexpr float kSupplyMv = 3300.0f;
  fault = mv < 30 || mv > kSupplyMv - 30;
  if (fault) return NAN;
  const float r = NTC_R_FIXED * mv / (kSupplyMv - mv);
  const float invT = 1.0f / 298.15f + logf(r / NTC_R25) / NTC_BETA;
  return 1.0f / invT - 273.15f;
}

float derate(float c) {
  if (c <= DERATE_START_C) return 1.0f;
  if (c >= DERATE_END_C) return DERATE_MIN_FACTOR;
  const float t = (c - DERATE_START_C) / (DERATE_END_C - DERATE_START_C);
  return 1.0f - t * (1.0f - DERATE_MIN_FACTOR);
}

}  // namespace

const char *sourceName(Source s) {
  switch (s) {
    case Source::Default: return "USB default";
    case Source::Usb1A5: return "USB-C 1.5A";
    case Source::Usb3A: return "USB-C 3A";
    default: return "none";
  }
}

void begin() {
  analogReadResolution(12);
  analogSetPinAttenuation(PIN_CC1, ADC_11db);
  analogSetPinAttenuation(PIN_CC2, ADC_11db);
  analogSetPinAttenuation(PIN_NTC, ADC_11db);
  // Seed the classification so LEDs restored at boot don't wait for the debounce.
  for (int i = 0; i < 3; ++i) update();
}

void update() {
  const uint16_t cc1 = analogReadMilliVolts(PIN_CC1);
  const uint16_t cc2 = analogReadMilliVolts(PIN_CC2);
  const uint16_t cc = cc1 > cc2 ? cc1 : cc2;  // only the connected CC line carries Rp
  const uint16_t ntcMv = analogReadMilliVolts(PIN_NTC);

  Source src = Source::None;
  const bool inBand = classify(cc, src);

  bool fault = false;
  const float c = ntcCelsius(ntcMv, fault);

  portENTER_CRITICAL(&s_mux);
  s_st.ccMv = cc;
  // Debounce: 3 consecutive in-band readings of the same class (~0.3 s). Dropping to None is
  // immediate, since the LED supply is gone.
  if (inBand) {
    if (src == Source::None) {
      s_st.source = Source::None;
      s_candidateCount = 0;
    } else if (src == s_candidate) {
      if (s_candidateCount < 3 && ++s_candidateCount == 3) s_st.source = src;
    } else {
      s_candidate = src;
      s_candidateCount = 1;
    }
  }
  s_st.budgetMa = budgetFor(s_st.source);

  s_st.ntcFault = fault;
  if (!fault) {
    s_st.boardC = s_tempInit ? s_st.boardC * 0.8f + c * 0.2f : c;
    s_tempInit = true;
  }
  if (s_st.boardC >= SHUTDOWN_C) s_st.overTemp = true;
  else if (s_st.boardC <= SHUTDOWN_RELEASE_C) s_st.overTemp = false;
  s_st.thermalFactor = s_st.overTemp ? 0.0f : fault ? NTC_FAULT_FACTOR : derate(s_st.boardC);
  portEXIT_CRITICAL(&s_mux);
}

Status status() {
  portENTER_CRITICAL(&s_mux);
  const Status s = s_st;
  portEXIT_CRITICAL(&s_mux);
  return s;
}

bool limit(float &white, rgb::Pixel *px, int n) {
  portENTER_CRITICAL(&s_mux);
  const float factor = s_st.thermalFactor;
  const float budget = s_st.budgetMa;
  portEXIT_CRITICAL(&s_mux);

  bool limited = false;
  float rgbScale = factor;
  white *= factor;
  if (factor < 1.0f) limited = true;

  // White first.
  float whiteMa = white * WHITE_FULL_MA;
  if (whiteMa > budget) {
    white = budget / WHITE_FULL_MA;
    whiteMa = budget;
    limited = true;
  }

  // RGB gets the remainder (each pixel draws PIXEL_IDLE_MA even when dark).
  float sum = 0;
  for (int i = 0; i < n; ++i) sum += px[i].r + px[i].g + px[i].b;
  const float rgbMa = sum * factor / 255.0f * PIXEL_CHANNEL_MA;
  const float left = budget - whiteMa - n * PIXEL_IDLE_MA;
  if (rgbMa > 0 && rgbMa > left) {
    rgbScale *= left > 0 ? left / rgbMa : 0.0f;
    limited = true;
  }
  if (rgbScale < 1.0f) {
    for (int i = 0; i < n; ++i) {
      px[i].r = static_cast<uint8_t>(px[i].r * rgbScale);
      px[i].g = static_cast<uint8_t>(px[i].g * rgbScale);
      px[i].b = static_cast<uint8_t>(px[i].b * rgbScale);
    }
  }

  float est = white * WHITE_FULL_MA + n * PIXEL_IDLE_MA;
  for (int i = 0; i < n; ++i) est += (px[i].r + px[i].g + px[i].b) / 255.0f * PIXEL_CHANNEL_MA;

  portENTER_CRITICAL(&s_mux);
  s_st.lastEstimateMa = static_cast<uint16_t>(est);
  s_st.limited = limited;
  portEXIT_CRITICAL(&s_mux);
  return limited;
}

}  // namespace power
