// RGB pixel chain driver (XL-5050RGBW-WS2812B-HM, WS2812B protocol), RMT on RGB_DIN.
//
// Low-level only. Nothing outside light.cpp's output stage may call show(): every brightness
// request goes through power::limit() first.
#pragma once

#include <stdint.h>

namespace rgb {

struct Pixel {
  uint8_t r, g, b;
};

void begin();
// Sends the frame if it differs from the last one. `n` is clamped to NUM_PIXELS.
void show(const Pixel *pixels, int n);

}  // namespace rgb
