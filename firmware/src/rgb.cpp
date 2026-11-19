#include "rgb.h"

#include <Arduino.h>
#include <string.h>

#include "config.h"
#include "pins.h"

namespace rgb {
namespace {

// XL-5050RGBW-WS2812B-HM timing (datasheet): T0H 0.20-0.35 us, T1H 0.55-1.2 us,
// T0L 0.55-1.2 us, T1L 0.20-0.35 us, bit >= 0.9 us, reset >= 80 us low. GRB order, MSB first.
// 0.3/0.7 and 0.7/0.3 us also sit inside the earlier IN-PI554FCH's windows (+-0.15 us).
// RMT at 10 MHz = 100 ns ticks.
constexpr uint32_t kRmtHz = 10000000;
constexpr rmt_data_t kBit0 = {3, 1, 7, 0};  // duration0, level0, duration1, level1
constexpr rmt_data_t kBit1 = {7, 1, 3, 0};

rmt_data_t s_symbols[NUM_PIXELS * 24];
Pixel s_last[NUM_PIXELS];
bool s_ok = false;
bool s_sent = false;

}  // namespace

void begin() {
  s_ok = rmtInit(PIN_RGB_DIN, RMT_TX_MODE, RMT_MEM_NUM_BLOCKS_1, kRmtHz);
  if (!s_ok) Serial.println("[rgb] RMT init failed");
  // Pixels power up dark but not always: send an explicit black frame.
  Pixel black[NUM_PIXELS] = {};
  show(black, NUM_PIXELS);
}

void show(const Pixel *px, int n) {
  if (!s_ok) return;
  if (n > NUM_PIXELS) n = NUM_PIXELS;
  Pixel frame[NUM_PIXELS] = {};
  memcpy(frame, px, n * sizeof(Pixel));
  if (s_sent && memcmp(frame, s_last, sizeof(frame)) == 0) return;

  rmt_data_t *sym = s_symbols;
  for (int i = 0; i < NUM_PIXELS; ++i) {
    const uint32_t grb = (uint32_t(frame[i].g) << 16) | (uint32_t(frame[i].r) << 8) | frame[i].b;
    for (int bit = 23; bit >= 0; --bit) *sym++ = (grb >> bit) & 1 ? kBit1 : kBit0;
  }
  // The line idles low after the frame; the output task's 5 ms period covers the 80 us reset.
  if (rmtWrite(PIN_RGB_DIN, s_symbols, NUM_PIXELS * 24, RMT_WAIT_FOR_EVER)) {
    memcpy(s_last, frame, sizeof(frame));
    s_sent = true;
  }
}

}  // namespace rgb
