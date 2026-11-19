# Firmware

PlatformIO / Arduino firmware for the Seeed XIAO ESP32-C6 (primary) or ESP32-S3. It joins Wi-Fi and **emulates a TP-Link Tapo L530 colour bulb** over the local KLAP v2 protocol. The [tapo_light_display](../../tapo_light_display) knob, python-kasa and Home Assistant can then control the terrarium light like any other Tapo bulb, with no cloud or hub. The design is in [docs/plan.md](../docs/plan.md).

## Setup

1. Copy `include/secrets.example.h` to `include/secrets.h` (git-ignored) and fill in:
   - **Wi-Fi:** 2.4 GHz only.
   - **Tapo email and password:** the **same account the knob uses**. Both ends derive the KLAP auth hash from these credentials, so if they differ the knob's handshake fails. Nothing is sent to TP-Link.
   - Optionally a fixed IP (`LIGHT_IP` etc.).
2. Give the light a stable address: either set `LIGHT_IP`, or add a DHCP reservation on the router. The boot log prints the IP and MAC.
3. Add that IP to the knob's `TAPO_BULB_IPS` in `tapo_light_display/src/secrets.h` and reflash the knob. The light then shows up as another bulb page, named by its nickname (default "Terrarium").

```
pio run -d firmware                          # build (default env: xiao_esp32c6)
pio run -d firmware -t upload                # flash
pio device monitor -d firmware               # serial log, 115200
pio test -d firmware -e xiao_esp32c6         # on-device KLAP crypto tests (python-kasa vectors)
pio run -d firmware -e xiao_esp32s3          # S3 build
```

`pio` may not be on PATH; on Windows use `%USERPROFILE%\.platformio\penv\Scripts\pio.exe`.

## How the Tapo controls map onto this board

The board has a **fixed-CCT white string** (OSRAM DURIS E 2835, 3000 K, CRI 90+) and an **RGB ring**, but no tunable white. It reports itself as an L530 with `color_temp_range` 2500–6500 K, the same range the knob uses by default, and maps the controls like this:

| Tapo control | What the light does |
|---|---|
| On/off, brightness | The white string, faded with a gamma curve |
| **Colour temperature** (white mode) | The white string stays at the requested brightness and the **RGB ring adds a tint**: amber below 3000 K, sky blue above, growing towards the ends of the range. At 3000 K the ring is off. The plants' high-CRI light never drops because of a CCT change |
| **Colour** (hue/saturation) | Saturation crossfades white to RGB. **100 % (the knob's colour wheel) = RGB ring only, white off**, which is what a real L530 does in colour mode. Lower saturation (the Tapo app's pastel colours) mixes in the white string |

This is a tint, not a real colour-temperature change. The ring is 6 pixels against ~170 lm of white, so the effect is subtle at high brightness and clearer when dimmed. `CCT_TINT_MAX` in `include/config.h` sets its strength; set it to 0 to accept and report CCT with no visible effect.

Other behaviour:
- **State survives power cycles** (NVS, saved 5 s after the last change), like Tapo's "last state" default.
- **Power budget:** every frame goes through `power::limit()` before it reaches the drivers.
  - The budget comes from the USB-C CC advertisement (plan section 3).
  - White is served first; the ring gets what's left.
  - With nothing on the power USB-C (J1), the LEDs stay off. Set `POWER_OVERRIDE_MA` for chargers that under-advertise, such as USB-A adapters.
- **Thermal:** NTC derating from 60 °C (to 25 % at 80 °C), shutdown at 90 °C until the board cools to 75 °C, and half power if the thermistor reads open or short. The L530 `overheated` flag reports the shutdown.
- `get_device_info` carries an extra `terrarium` object (board temperature, power source, budget, estimated LED current, whether output is limited). Tapo clients ignore unknown keys.
- Supported methods: `get_device_info`, `set_device_info`, `component_nego`, `get_device_usage` (zeros), and python-kasa's `multipleRequest`. Anything else returns error −1010 (unknown method).
- A status line is printed to serial every 30 s.

## Code map

| File | Role |
|---|---|
| `include/pins.h` | All GPIOs (C6 / S3 / C3), matching plan section 6.5 |
| `include/config.h` | Tunables: PWM, CCT emulation, fades, power budget, thermal limits |
| `include/secrets.h` | Git-ignored credentials (template `secrets.example.h`) |
| `src/main.cpp` | Boot order: outputs → Wi-Fi → Tapo server; periodic status |
| `src/light.*` | Tapo-visible state, the channel mapping above, NVS persistence, the 200 Hz fade/output task |
| `src/power.*` | CC source detection, NTC derating, `limit()`: the only path to the drivers |
| `src/white.*` | LEDC PWM, 20 kHz / 11-bit, on LGS63032EP EN; minimum non-zero duty 5 % |
| `src/rgb.*` | RMT WS2812B driver |
| `src/net.*` | Wi-Fi station |
| `src/klap.*` | KLAP v2 crypto, device side (derivation as in the knob's client / python-kasa) |
| `src/tapo_server.*` | HTTP on port 80: handshake1/2, a 4-session table, seq replay check, 403 → client re-handshakes |
| `src/tapo_device.*` | The JSON methods |
| `scripts/short_includes.py` | Windows build fix, see below |
| `test/test_klap/` | Unity tests run on the device |

## Notes

- **Platform:** pioarduino 53.03.10 (Arduino-ESP32 3.1.0), the same release as the knob. It has no XIAO C6 board file, so the C6 env is `esp32-c6-devkitc-1` with Seeed's `XIAO_ESP32C6` variant and 4 MB flash. The variant's `initVariant()` selects the on-board antenna (GPIO3/GPIO14 low).
- **Windows build fix:** RISC-V gcc re-expands every `-I` onto the assembler's command line. With Arduino 3.1.0's ~300 C6 include dirs, that line is ~34 KB, over Windows' 32 KB limit ("cannot execute … as.exe: CreateProcess: No such file or directory"). `scripts/short_includes.py` emits those dirs as `-iprefix` / `-iwithprefixbefore`, which the compiler treats like `-I` but doesn't pass on to `as`.
- **Discovery:** the light doesn't answer Tapo UDP discovery (port 20002), so the Tapo app and `kasa discover` won't list it. Clients reach it by IP: `kasa --host <ip> --username … --password …`.

## Not done yet / bring-up checks

- Not yet run on hardware. The crypto tests use the knob's python-kasa vectors but haven't been run on a board.
- Things to tune at bring-up:
  - `WHITE_MIN_DUTY`: the lowest duty at which the LGS63032EP lights both strings evenly.
  - Whether 11-bit PWM is smooth enough at the low end; temporal dithering is planned but not implemented.
  - Pixel colour balance.
  - Check the CC thresholds against real chargers.
- Planned modules from plan section 7: schedule (NTP, photoperiod), provisioning / web UI / OTA, MQTT.
