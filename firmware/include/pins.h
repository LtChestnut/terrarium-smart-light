// All GPIO assignments. Must match the schematic (hardware/mcu.kicad_sch) and the pin table
// in docs/plan.md section 6.5. The board only uses XIAO pins that exist on the C6, S3 and C3.
#pragma once

#include <sdkconfig.h>
#include <stdint.h>

//                                 XIAO pin   Net         Function
#if defined(CONFIG_IDF_TARGET_ESP32C6)
constexpr uint8_t PIN_CC1 = 0;        // D0     CC1         USB-C CC1 sense (ADC)
constexpr uint8_t PIN_CC2 = 1;        // D1     CC2         USB-C CC2 sense (ADC)
constexpr uint8_t PIN_NTC = 2;        // D2     NTC         Board thermistor (ADC)
constexpr uint8_t PIN_RGB_DIN = 21;   // D3     RGB_DIN     WS2812-style pixel data
constexpr uint8_t PIN_WHITE_PWM = 19; // D8     WHITE_PWM   LGS63032EP EN (PWM dimming)
// GPIO3 (RF switch enable, LOW) and GPIO14 (antenna select, LOW = on-board ceramic) are set
// by the XIAO_ESP32C6 variant's initVariant() before setup() runs.
#elif defined(CONFIG_IDF_TARGET_ESP32S3)
constexpr uint8_t PIN_CC1 = 1;
constexpr uint8_t PIN_CC2 = 2;
constexpr uint8_t PIN_NTC = 3;
constexpr uint8_t PIN_RGB_DIN = 4;
constexpr uint8_t PIN_WHITE_PWM = 7;
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
// Fallback only: GPIO8 is a strapping pin (must be high at boot; the R8 EN pull-down
// fights it). There is no PlatformIO env for the C3.
constexpr uint8_t PIN_CC1 = 2;
constexpr uint8_t PIN_CC2 = 3;
constexpr uint8_t PIN_NTC = 4;
constexpr uint8_t PIN_RGB_DIN = 5;
constexpr uint8_t PIN_WHITE_PWM = 8;
#else
#error "Unsupported target: build for a XIAO ESP32-C6, S3 or C3"
#endif
