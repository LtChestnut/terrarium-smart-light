# Component Research Notes

These notes back up the decisions in [../plan.md](../plan.md). Stock and prices were checked on DigiKey (UK/regional sites) on 2026-11-16. **Check the live page again before ordering.**

## MCU: Seeed Studio XIAO ESP32-S3
- 21 × 17.8 mm module with castellated pads that solders directly onto the board as an SMD part. It has its own USB-C for programming and power.
- The 5V pin is USB VBUS and works as both input and output. Seeed recommends a **diode between an external 5 V source and the 5V pin** to stop the supply back-feeding the USB host.
- The 3V3 regulator delivers up to ~700 mA.
- Antenna: U.FL connector with a supplied FPC antenna; there is no on-board antenna.
- Sources:
  - [Seeed XIAO ESP32-S3 getting started](https://wiki.seeedstudio.com/xiao_esp32s3_getting_started)
  - [Seeed pin multiplexing](https://wiki.seeedstudio.com/xiao_esp32s3_pin_multiplexing/)
  - [XIAO ESP32S3 Sense schematic V1.51](https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32S3/new-res/202003753_XIAO%20ESP32S3%20Sense_V1.51_SCH_260611.pdf)
  - [Core Electronics forum: diodes for powering the XIAO S3](https://forum.core-electronics.com.au/t/diodes-for-powering-esp32s3-xiao/21715)

## White LED driver

### Rejected after datasheet check: Diodes AP3031KTR-G1 (OVP only 15.5–19.5 V, so max ~4 LEDs). Chosen: AP3032KTR-G1 (OVP 27 V); see plan.md and datasheets/AP3032.md
- Boost LED driver, TSOT-23-6. 2.7–16 V in, up to 37 V out, 1.4 A switch (the limit depends on duty cycle). 1 MHz. Has an OVP pin, UVLO, soft-start, current limit and thermal shutdown. PWM dimming.
- DigiKey UK: Active, 14,236 in stock, **£0.28 each for 1, £0.188 each for 10** (cut tape).
- **To check in the datasheet:**
  - V_FB (assumed ~0.2 V)
  - the switch limit vs duty cycle curve at D ≈ 0.86
  - the CTRL PWM frequency range
  - whether CTRL has an internal pull-down
  - the OVP threshold
- Sources:
  - [Diodes AP3031](https://diodes.com/part/view/AP3031)
  - [DigiKey AP3031KTR-G1](https://www.digikey.co.uk/en/products/detail/diodes-incorporated/AP3031KTR-G1/4470853)

### Alternatives considered
| Part | Vin / Vout / switch | Dimming | Price (qty 1) | Notes |
|---|---|---|---|---|
| TI TPS61169DCKR | 2.7–5.5 V / 38 V / 1.2 A min, 1.8 A typ | CTRL PWM sets the FB reference (flicker-free) | ~$1.54 | Often out of stock at DigiKey. SC70-5. [TI](https://www.ti.com/product/TPS61169), [DigiKey](https://www.digikey.sg/en/products/detail/texas-instruments/TPS61169DCKR/5048578) |
| TI LM3410 | 2.7–5.5 V / 24 V / 2.8 A | PWM on DIM | expensive | 24 V limits the string to 6–7 LEDs. No OVP on SOT-23. [TI](https://www.ti.com/product/LM3410) |
| SG Micro SGM3732 | 38 V / 1.35 A | PWM | ~$0.10 (LCSC) | **Not on DigiKey.** [SG Micro](https://www.sg-micro.com/product/SGM3732) |
| Diodes AP3019A | 38 V / 550 mA | PWM | cheap | Switch current too low. [DigiKey](https://www.digikey.co.uk/en/products/detail/diodes-incorporated/AP3019AKTR-G1/4470850) |
| Microchip MIC2289 | 34 V / 750 mA | Analog, PWM | | Switch current too low. [DigiKey](https://www.digikey.com/en/products/detail/microchip-technology/MIC2289C-34YD6-TR/1640288) |

### Why not other topologies
- **Resistor + MOSFET from 5 V:** this uses the fewest parts, but about 40 % of the power is lost as heat (5 V supply vs a 2.9 V LED).
- **Buck driver per LED (e.g. Diodes PAM2804):** efficient, but each channel needs its own IC, inductor and capacitors, and high current goes into a few LEDs, which concentrates the heat.
- **Boost to a series string:** one IC, all LEDs at the same current, high efficiency. **Chosen** (AP3032).

## White LEDs
- **Samsung horticulture LEDs are EOL.** All LM301H EVO and LH351H 660 nm are marked outdated at DigiKey, with a last ship date of 2025-12-31 and no substitute. Samsung is exiting general lighting LEDs.
  - [DigiKey forum thread](https://forum.digikey.com/t/samsung-horticulture-led-status-outdated-on-all/62178)
  - [Samsung EOL notice](https://mm.digikey.com/Volume0/opasdata/d220001/medias/docus/6878/EOL_LIGT-EOL2024-002.pdf)
- **Lumileds LUXEON SunPlus 2835 Horticulture White, L1SP-PNK1002800000:**
  - 2.85 V @ 120 mA test current, 480 mA maximum, 120° beam.
  - Active, ~7k in stock, £0.49 each for 1, £0.338 each at 10.
  - The spectrum is not shown on DigiKey and "PNK" may mean a pink-shifted spectrum, so check the datasheet.
  - [DigiKey](https://www.digikey.co.uk/en/products/detail/lumileds/L1SP-PNK1002800000/9805576)
- **Luminus MP-3030-21C2 Salud:**
  - CRI 90 white, 3000–5000 K. 5.3 V typical @ 45 mA, 120 mA DC maximum, 120°. About £0.22 each.
  - It is a 6 V class part, so only 3–4 fit in series under the LM3410's 24 V limit.
  - [DigiKey](https://www.digikey.co.uk/en/products/detail/luminus-devices-inc/MP-3030-21C2-40-90/11685984)
  - [Datasheet](https://www.mouser.com/datasheet/2/245/Luminus_MP3030_21C2_Datasheet-2025101.pdf)
- **Cree J Series JB3030C:**
  - Up to 3.33 µmol/J; footprint-compatible with the LM301B/H.
  - Not stocked at DigiKey (lead-time only).
  - [Cree horticulture feature sheet](https://www.mouser.lt/pdfDocs/Cree-LED-Horticulture-Feature-Sheet.pdf)
- **Chosen: Seoul SunLike 3030.** It is a sunlight-matched full-spectrum LED, CRI 95: 3.05 V @ 65 mA, 150 mA max, 120°.
  - 5000 K: S1S0-3030509503-0000003S-00001, ~$0.74 each for 1. [DigiKey](https://www.digikey.com.br/en/products/detail/seoul-semiconductor-inc/S1S0-3030509503-0000003S-00001/9687052)
  - 4000 K: S1S0-3030409503-…, £0.57 each for 1, £0.393 each for 10, 6.8k stock. The UK site has a "constrained supply" note. [DigiKey](https://www.digikey.co.uk/en/products/detail/seoul-semiconductor-inc/S1S0-3030409503-0000003S-00001/9687051)
  - 3000 K and 2700 K are also listed.
  - The 6 V-class SunLike STW9C2SB is "quote required", so it was rejected.
- **Nichia Optisolis NF2W757GT-F1** (CRI 98+, 3030): not stocked at DigiKey and RS is dropping it. Lumitronix/Ledrise still sell it, so it is the backup. [Ledrise](https://www.ledrise.eu/blog/nichia-optisolis/)
- **Lumileds SunPlus …PNK…** was rejected because it is a pink horticulture spectrum, not full spectrum.

## Other XIAO / small ESP32 modules (antenna)
- **XIAO ESP32-C6:**
  - On-board ceramic antenna plus U.FL, selected by an RF switch: GPIO3 enables the switch (active low), and GPIO14 selects (low = on-board, which is the default).
  - On the official PlatformIO platform, the switch may start disabled, which leaves Wi-Fi weak until the firmware enables it.
  - Sources: [Seeed C6 wiki](https://wiki.seeedstudio.com/xiao_esp32c6_getting_started), [C6 Wi-Fi/antenna usage](https://wiki.seeedstudio.com/xiao_wifi_usage_esp32c6/), [Zephyr board doc](https://docs.zephyrproject.org/latest/boards/seeed/xiao_esp32c6/doc/index.html)
- **XIAO ESP32-C5:** U.FL external antenna only, same 21 × 17.8 mm form factor. [Seeed C5 wiki](https://wiki.seeedstudio.com/xiao_esp32c5_getting_started/)
- **Waveshare ESP32-S3-Zero:**
  - 23.5 × 18 mm, castellated, on-board ceramic antenna (no U.FL).
  - Not footprint-compatible with XIAO.
  - [Waveshare wiki](https://waveshare.com/wiki/ESP32-S3-Zero)

## Addressable RGB
- **Inolux IN-PI554FCH:** 5050 WS2812B-compatible pixel and the easiest package to hand solder.
  - DigiKey: **Active, 107k in stock, cut tape from qty 1: $0.77 each for 1, $0.538 each for 10.**
  - So the "MOQ in the thousands" only applies to full reels (1000+).
- Smaller options: IN-PI55TAT (2020) and IN-PI15TAT5R5G5B (1515, ~$0.53 each). Both are harder to hand solder.
- [DigiKey IN-PI15TAT5R5G5B](https://www.digikey.com.au/en/products/detail/inolux/IN-PI15TAT5R5G5B/14555725)
- **To check:** IN-PI554FCH datasheet V_IH, current per channel, and viewing angle.

## USB-C power receptacle
- Requirement: power only (6-pin), right angle, 3 A, and preferably no through-hole parts (components go on one side only and the back must stay flat for the heatsink).
- **GCT USB4135-GF-A:**
  - DigiKey describes it as "USB C REC GF RA 6P SMT & SMT SHELL". 3 A, 48 V.
  - Active, ~5.9k in stock, £0.51 each.
  - The "solder retention tab" still needs checking against the mechanical drawing.
  - [DigiKey](https://www.digikey.co.uk/en/products/detail/gct/USB4135-GF-A/16036157)
- **Alternatives to check:**
  - Same Sky UJC-HP-3-SMT-TR: [DigiKey](https://www.digikey.ca/en/products/detail/same-sky-formerly-cui-devices/UJC-HP-3-SMT-TR/12173367)
  - Same Sky UJC-HP-G-5-SMT-TR: [DigiKey](https://www.digikey.com/en/products/detail/same-sky-formerly-cui-devices/UJC-HP-G-5-SMT-TR/16629548)
  - Linkplex LUB-C115D-007-G-19
- **Rejected:**
  - Molex 2171750001: active and 3 A, but listed with through-hole mounting. [DigiKey](https://www.digikey.ca/en/products/detail/molex/2171750001/13913766)
  - Same Sky UJC-V-G-SMT-2-P6-TR: obsolete.
- **CC sink:** 5.1 kΩ Rd to GND on each CC pin. The Type-C spec's sink-side voltage bands for detecting the advertised current are:

| Advertised current | CC voltage |
|---|---|
| Default USB | 0.25–0.61 V |
| 1.5 A | 0.70–1.16 V |
| 3.0 A | 1.31–2.04 V |

## Light requirement sanity check
- Typical low-light terrarium plants (mosses, ferns, fittonia, peperomia) need ~50–150 µmol/m²/s PPFD over a 10–14 h photoperiod.
- Modern white LEDs produce ~2.5–3 µmol/J.
- About 4.5 W of LEDs over a 30 × 30 cm floor gives ≈ 90 PPFD at the floor, which is adequate.
