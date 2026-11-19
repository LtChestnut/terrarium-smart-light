// Tunable constants. Any of them can be overridden at build time with -D<NAME>=<value>.
// Hardware values cite docs/plan.md; the ones marked "bring-up" need checking on a real board.
#pragma once

#define FW_VERSION "0.1.0"

// ---- Identity (what the Tapo knob / python-kasa see) ---------------------------------------
#ifndef DEVICE_HOSTNAME
#define DEVICE_HOSTNAME "terrarium-light"
#endif
#ifndef DEVICE_NICKNAME            // default name until a client renames it
#define DEVICE_NICKNAME "Terrarium"
#endif
#define TAPO_MODEL "L530"          // emulated model (colour + tunable white bulb)
#define TAPO_DEVICE_TYPE "SMART.TAPOBULB"
#define TAPO_SESSION_TIMEOUT_S 86400

// ---- White channel (LGS63032EP EN PWM, plan 4.2) ---------------------------------------------
#ifndef WHITE_PWM_FREQ_HZ
#define WHITE_PWM_FREQ_HZ 20000    // LGS63032 accepts 100 Hz-100 kHz, converted to constant current
#endif
#define WHITE_PWM_BITS 11          // 80 MHz / 20 kHz = 4000 counts -> 11 bits fits (12 would not)
#ifndef WHITE_MIN_DUTY
#define WHITE_MIN_DUTY 0.05f       // lowest non-zero duty: 5 % of 50 us = 2.5 us, well above the LGS63032's
#endif                             // 400 ns minimum EN pulse (shorter pulses are ignored)
#define WHITE_NATIVE_K 3000        // OSRAM DURIS E 2835 GW JTLMS3.CM CCT (plan section 5)

// ---- RGB pixels (XL-5050RGBW-WS2812B-HM, plan 4.3) -----------------------------------------
#define NUM_PIXELS 6

// ---- Colour temperature emulation -----------------------------------------------------------
// The white string has a fixed CCT. Requests away from WHITE_NATIVE_K keep the white at full
// requested brightness and add an RGB tint on top (warm amber below, cool blue above). At the
// end of the range the tint reaches CCT_TINT_MAX of the pixels' full drive, scaled by brightness.
#define CT_MIN_K 2500              // matches the knob's default ring range
#define CT_MAX_K 6500
#ifndef CCT_TINT_MAX
#define CCT_TINT_MAX 1.0f          // 0 = ignore colour temperature entirely (report it, no effect)
#endif

// ---- Fades ------------------------------------------------------------------------------------
#define FADE_MS 400                // full-scale transition time (perceptual space)
#define OUTPUT_HZ 200              // output task rate
#define GAMMA 2.2f

// ---- Power budget (plan section 3) -----------------------------------------------------------
#define WHITE_FULL_MA 760          // 5 V input current at 100 % duty: 2 strings x 8 LEDs,
                                   // (8 x 2.9 V + 0.2) x 130 mA / 0.8 / 5 V (R3 || R5 = 1.54R)
#define PIXEL_CHANNEL_MA 12        // XL-5050 constant current per colour (datasheet)
#define PIXEL_IDLE_MA 1            // datasheet 0.6 mA static, rounded up
// LED budget per advertised source current (leaves ~0.3 A for the XIAO's Wi-Fi peaks).
#define BUDGET_NONE_MA 0           // nothing on J1: LEDs have no supply
#define BUDGET_DEFAULT_MA 400      // "Default USB" (500/900 mA)
#define BUDGET_1A5_MA 1200
#define BUDGET_3A_MA 2700
// Treat the source as this many mA regardless of CC (e.g. a 2 A USB-A charger that only
// advertises Default USB). 0 = use the CC detection.
#ifndef POWER_OVERRIDE_MA
#define POWER_OVERRIDE_MA 0
#endif

// ---- Thermal derating (NTC RT1 near the white LEDs, plan 4.2 / 6.2) -------------------------
#define NTC_R_FIXED 10000.0f       // R4, 3V3 -> NTC node (high side)
#define NTC_R25 10000.0f           // RT1 FH CMFB103J3950HANT, NTC node -> GND
#define NTC_BETA 3950.0f
#define DERATE_START_C 60.0f       // full output below this board temperature
#define DERATE_END_C 80.0f         // DERATE_MIN_FACTOR at and above this
#define DERATE_MIN_FACTOR 0.25f
#define SHUTDOWN_C 90.0f           // LEDs off ...
#define SHUTDOWN_RELEASE_C 75.0f   // ... until the board cools to here
#define NTC_FAULT_FACTOR 0.5f      // thermistor open/short: run at half power

// ---- First-boot state (before anything is saved in NVS) --------------------------------------
#define DEFAULT_BRIGHTNESS 75      // plan section 5: the DURIS string runs at ~60-100 %
