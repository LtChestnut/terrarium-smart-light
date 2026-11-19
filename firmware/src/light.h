// Light model: the state a Tapo L530 exposes, mapped onto this board's two channels.
//
// Channel mapping (the board has a fixed-CCT white string plus an RGB ring, no tunable white):
//  - White mode (color_temp > 0): the white string runs at `brightness`. The string is fixed
//    at WHITE_NATIVE_K, so colour temperature is emulated as an RGB *tint* added on top: warm
//    amber below WHITE_NATIVE_K, cool blue above, growing towards the ends of the range. The
//    plants' full-spectrum light is never reduced by a colour-temperature change.
//  - Colour mode (color_temp == 0): saturation crossfades white -> RGB. 0 % = the white string
//    only, 100 % = the RGB ring only, in hue `hue`. `brightness` scales both.
//  - All requests are faded in perceptual space and pass through power::limit().
#pragma once

#include <stdint.h>

#include "config.h"

namespace light {

struct State {
  bool on = false;
  uint8_t brightness = DEFAULT_BRIGHTNESS;  // 1..100
  uint16_t hue = 0;                     // 0..360
  uint8_t saturation = 100;             // 0..100
  uint16_t colorTemp = WHITE_NATIVE_K;  // Kelvin; 0 = colour mode
  char nickname[48] = {};               // UTF-8, plain (not base64)
};

// A partial update, as in Tapo set_device_info: only fields with their flag set change.
struct Patch {
  enum : uint8_t { On = 1, Brightness = 2, Hue = 4, Saturation = 8, ColorTemp = 16, Nickname = 32 };
  uint8_t mask = 0;
  State v;
};

void begin();
State get();
// Applies, clamps and persists (debounced) a patch. Returns the resulting state.
State apply(const Patch &p);
// Revision counter, bumped on every state change.
uint32_t revision();

}  // namespace light
