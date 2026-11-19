// White string driver: LEDC PWM on the LGS63032EP EN pin (PWM -> constant-current dimming).
//
// Low-level only. Nothing outside light.cpp's output stage may call write(): every brightness
// request goes through power::limit() first (CLAUDE.md firmware conventions).
#pragma once

namespace white {

void begin();
// duty: 0..1 linear (fraction of the 130 mA total = 2 x ~65 mA string current). 0 = fully off; anything above 0
// is mapped onto WHITE_MIN_DUTY..1 so the lowest level still lights.
void write(float duty);

}  // namespace white
