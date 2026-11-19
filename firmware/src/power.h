// Power budget: the one gate every LED output passes through.
//
// - USB-C source capability from the CC pins (5.1 kOhm Rd, plan section 3)
// - Board temperature from the NTC, with derating and a latched over-temperature shutdown
// - limit(): scales a requested frame so the estimated LED current fits the budget.
//   White (the plants' light) is served first; the RGB ring gets what is left.
#pragma once

#include <stdint.h>

#include "rgb.h"

namespace power {

enum class Source : uint8_t { None, Default, Usb1A5, Usb3A };

struct Status {
  Source source = Source::None;
  uint16_t ccMv = 0;            // the higher of CC1/CC2
  uint16_t budgetMa = 0;        // LED budget in use (after any override)
  float boardC = 25.0f;
  bool ntcFault = false;
  bool overTemp = false;        // latched shutdown
  float thermalFactor = 1.0f;   // 0..1 applied to all LED output
  uint16_t lastEstimateMa = 0;  // estimated LED current of the last limited frame
  bool limited = false;         // the last frame was scaled down
};

void begin();
// Samples the ADCs. Call at ~10 Hz (the output task does).
void update();
Status status();
const char *sourceName(Source s);

// In-place: white duty 0..1, pixels 0..255. Returns true if the frame was scaled.
bool limit(float &white, rgb::Pixel *pixels, int n);

}  // namespace power
