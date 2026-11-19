// Terrarium Smart Light: high-CRI white strings (LGS63032EP) + RGB ring, controlled over the LAN by
// the tapo_light_display knob (or python-kasa / Home Assistant) as an emulated Tapo L530.
#include <Arduino.h>
#include <WiFi.h>

#include "config.h"
#include "light.h"
#include "net.h"
#include "power.h"
#include "tapo_server.h"

namespace {

constexpr uint32_t kStatusIntervalMs = 30 * 1000;
uint32_t s_lastStatusMs = 0;

void printStatus() {
  const light::State st = light::get();
  const power::Status ps = power::status();
  Serial.printf("[status] %s %u%% %s | %s (CC %u mV) budget %u mA, LEDs ~%u mA%s | board %.1f C%s%s x%.2f | %s\n",
                st.on ? "ON" : "off", st.brightness,
                st.colorTemp ? (String(st.colorTemp) + "K").c_str()
                             : (String("hue ") + st.hue + " sat " + st.saturation).c_str(),
                power::sourceName(ps.source), ps.ccMv, ps.budgetMa, ps.lastEstimateMa,
                ps.limited ? " LIMITED" : "", ps.boardC, ps.ntcFault ? " NTC-FAULT" : "",
                ps.overTemp ? " OVERTEMP" : "", ps.thermalFactor,
                net::online() ? WiFi.localIP().toString().c_str() : "offline");
}

}  // namespace

void setup() {
  Serial.begin(115200);
  delay(1500);  // let USB CDC enumerate so the boot log isn't lost
  Serial.printf("\n[boot] Terrarium Smart Light v%s (%s)\n", FW_VERSION, ESP.getChipModel());

  light::begin();  // outputs first: restores the last state (Tapo "last_states" default)
  if (net::begin()) tapo_server::begin();
}

void loop() {
  if (millis() - s_lastStatusMs >= kStatusIntervalMs) {
    s_lastStatusMs = millis();
    printStatus();
  }
  delay(100);
}
