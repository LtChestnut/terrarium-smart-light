#include "white.h"

#include <Arduino.h>

#include "config.h"
#include "pins.h"

namespace white {
namespace {
constexpr uint32_t kMax = (1u << WHITE_PWM_BITS) - 1;
uint32_t s_last = UINT32_MAX;
}  // namespace

void begin() {
  // R8 (100k) holds the LGS63032EP EN pin low, so the strings stay off until here.
  if (!ledcAttach(PIN_WHITE_PWM, WHITE_PWM_FREQ_HZ, WHITE_PWM_BITS)) {
    Serial.println("[white] LEDC attach failed");
  }
  write(0);
}

void write(float duty) {
  uint32_t counts = 0;
  if (duty > 0.0f) {
    if (duty > 1.0f) duty = 1.0f;
    const float d = WHITE_MIN_DUTY + (1.0f - WHITE_MIN_DUTY) * duty;
    counts = static_cast<uint32_t>(d * kMax + 0.5f);
    if (counts == 0) counts = 1;
  }
  if (counts == s_last) return;
  s_last = counts;
  ledcWrite(PIN_WHITE_PWM, counts);
}

}  // namespace white
