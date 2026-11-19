# terrarium-smart-light

An ESP32-based smart grow light for terrariums: a compact 56 mm round board with components on one side with full-spectrum white LEDs for plant growth, addressable RGB LEDs for effects, and Wi-Fi control.

## Features (planned)
- Seeed Studio XIAO module soldered directly to the board (ESP32-C6 recommended for its on-board antenna; the S3 and C3 also fit)
- Dimmable, wide-angle (120°) warm white LEDs (ams OSRAM DURIS E 2835, 3000 K, CRI 90+) on a constant-current boost driver (Legend-Si LGS63032EP, flicker-free PWM dimming)
- Addressable RGB pixels (WS2812-compatible) for sunrise/sunset, moonlight and effects
- A separate USB-C power port (5 V, works with any 2–3 A USB-C charger). The firmware reads the charger's advertised current and limits brightness to match
- 4-layer PCB with every component on one side (the back sits flat on a heatsink). JLCPCB Economic assembly places all LCSC parts; only the XIAO is hand-soldered
- Day/night schedule with sunrise and sunset ramps, a web UI, OTA updates, and Home Assistant via MQTT

## Repository layout
| Folder | Contents |
|---|---|
| [docs/](docs/) | Design plan ([docs/plan.md](docs/plan.md)) and research notes ([docs/research/](docs/research/)) |
| [hardware/](hardware/) | KiCad project, BOM, fabrication outputs |
| [firmware/](firmware/) | PlatformIO project for the XIAO (ESP32-C6 primary, S3 supported) |

## Status
Planning stage. See [docs/plan.md](docs/plan.md) for the architecture, power budget, BOM and open decisions.
