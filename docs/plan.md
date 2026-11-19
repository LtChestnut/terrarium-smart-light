# Terrarium Smart Light: Design Plan

Status: **v0.6, LGS63032EP driver** (2026-11-17). The KiCad schematic and placed PCB in [hardware/](../hardware/) implement this plan:
- ERC: 0 errors, 0 warnings.
- Netlist checked pin by pin against the intended connections.
- PCB DRC with schematic parity: no errors apart from unrouted nets and cosmetic silkscreen.

The open decisions are in [section 10](#10-open-decisions).

Supporting material:
- Background research and sources: [research/component-research.md](research/component-research.md)
- Assembly cost analysis: [research/jlcpcb-assembly-analysis.md](research/jlcpcb-assembly-analysis.md)
- Datasheets converted to markdown: [datasheets/](datasheets/)
- BOMs: [hardware/bom/](../hardware/bom/)
  - `bom.csv`: master BOM
  - `jlcpcb_bom.csv`: parts for JLCPCB to place
  - `digikey_bom_5x.csv`: hand-soldered parts

Changes in v0.6:
- **White LED driver: Diodes AP3032 → Legend-Si LGS63032EP** (LCSC C5370937, ESOP-8 with exposed pad, Economic-eligible, ~$0.23). JLCPCB now places it, so only the XIAO and J1 are hand-soldered.
  - **Over-voltage protection** set by an R6/R7 divider: 100 kΩ / 3.3 kΩ trips at 1 V × (1 + 100/3.3) ≈ **31.3 V**. That is well above the ~23.4 V strings and below D2's 40 V and C2's 50 V ratings. It replaces the AP3032's fixed 27 V, which had only 2–3 V of margin.
  - **Switch current limit: 1.5 A minimum** (1.7 typ), up from the AP3032's 1.2 A. That leaves headroom up to ~180 mA total (90 mA per string, the LED maximum).
  - **Flicker-free dimming:** PWM on EN at 100 Hz–100 kHz is converted to a constant current. The firmware runs it at 20 kHz (LEDC) with a 5 % minimum duty.
  - **R8 100 kΩ EN pull-down**, because the internal 800 kΩ is weak.
  - **C2 is now 10 µF 50 V** (C13585, Basic) instead of 1 µF, as in the datasheet application circuit.
  - **New parts:** R6, R7, R8 (Basic), plus a new project symbol `LGS63032EP`. Footprint is `SOIC-8-1EP_3.9x4.9mm_P1.27mm_EP2.41x3.3mm`, matching the datasheet's 2.40 × 3.30 mm exposed pad. Add thermal vias into the exposed pad during routing (0.3 mm drill; the stock ThermalVias variant uses 0.2 mm, below the board minimum).

Changes in v0.5:
- **16 white LEDs instead of 7**, as two parallel strings of 8 on the one AP3032. That gives ~2.4× the light.
  - String A, LED1–LED8: inner ring, r = 18 mm, 45° pitch, with gaps at the top (XIAO USB) and bottom (driver pocket).
  - String B, LED9–LED16: outer ring, r = 26 mm, in pairs between the RGB pixels at 30/150/210/330°.
- **Current sense: R3 2.2 Ω ∥ R5 5.1 Ω (C17724)** = 1.54 Ω → 130 mA total, ~65 mA per string. Both are Basic parts. R5 changed from 1.0 Ω in series to 5.1 Ω in parallel.
- **RGB pixels renumbered LED17–LED22.**
- **Driver pocket rearranged** into the inner ring's bottom gap. U2, R3, R5, C2, L1 and D2 moved; D3, C3, RT1 and D1 nudged.
- **Firmware:** `WHITE_FULL_MA` 320 → 760 (5 V current of the white channel at 100 %).

Changes in v0.4:
- **Assembly route:** JLCPCB Economic PCBA places every part except U1 (XIAO), which you hand-solder. (J1 moved to JLCPCB on 2026-11-18 as the SHOU HAN TYPE-C 6P; U2 is the JLCPCB-placed LGS63032EP.) All JLCPCB-placed parts carry an `LCSC Part #` symbol field for the [Fabrication-Toolkit](https://github.com/bennymeg/Fabrication-Toolkit) plugin.
- **White LEDs: SunLike → ams OSRAM DURIS E 2835 GW JTLMS3.CM, 3000 K.**
  - CRI 90 minimum / 92 typical, R9 ≥ 50, 120°.
  - 90 mA max, so the string current drops to **62.5 mA**.
  - LCSC C30688624, about $0.008 each.
  - SunLike isn't stocked at LCSC/JLCPCB.
- **LED current set by R3 2.2 Ω + R5 1.0 Ω in series** (3.2 Ω → 62.5 mA). Both are JLCPCB Basic parts; a single 2.7–3.3 Ω would be Extended at $3.07.
- **RGB: Inolux IN-PI554FCH → XINGLIGHT XL-5050RGBW-2812B-HM** (LCSC C48586675, Economic-eligible).
  - Same WS2812B protocol (24-bit GRB); the "W" is the white diffused lens.
  - Standard WS2812B pinout, so it now uses KiCad's stock `LED:WS2812B` symbol and footprint.
- **Passives and diodes moved to JLCPCB Basic LCSC parts:**
  - B5819W (D1, D2); 2N7002 (Q1, data level shifter)
  - 22 µF **25 V** (C1, C3); 1 µF 50 V (C2); 100 nF (C4–C9)
  - UNI-ROYAL resistors
- **L1 → YNR4030-100M** (Isat 1.95 A; `L_Taiyo-Yuden_NR-40xx` footprint).
- **RT1 → FH CMFB103J3950HANT** (B = 3950 K).
- **Mounting holes are non-plated (NPTH)** (M3 since 2026-11-18), with no copper and no GND connection. Plated holes cut by the board edge count as castellations, which JLCPCB Economic PCBA doesn't allow.

Changes in v0.3:
- **Driver changed from AP3031 to AP3032.** The AP3031 datasheet gives an OVP of **15.5–19.5 V (17.5 V typical)**. The "37 V" figure quoted earlier was the SW pin rating, so the AP3031 cannot drive more than about 4 LEDs. The AP3032 is the same family with the same pinout, but its OVP is **27 V**. It costs £0.23 each for 1.
- **White string reduced to 7 LEDs at 133 mA**, to stay under the 27 V OVP.
- **White LEDs changed to SunLike 4000 K.** The 5000, 5700 and 6500 K SunLike parts are now obsolete at DigiKey; 4000 K is the coolest still active.
- **Dimming is CTRL PWM only.** The AP3032 supports PWM at 1 kHz and above (≥25 kHz) in standby mode, with an internal CTRL pull-down. The RC→FB option has been dropped.
- **Final parts chosen:**
  - Diodes B140 for both Schottkys (replaces SS16)
  - Bourns SRN4018-100M inductor
  - Stackpole 5.1 kΩ resistors (the Yageo part is out of stock)
  - Murata 1 µF capacitor (the Samsung part is out of stock)

---

## 1. Requirements

| # | Requirement | Notes |
|---|---|---|
| R1 | Full-spectrum white LEDs, **dimmable** | Sunlight-like spectrum (not pink). Wide angle (≥115°) |
| R2 | Addressable RGB LEDs | Wide angle. Buyable in single units |
| R3 | **Components on one side only** | 2- or 4-layer PCB and vias are fine. A flat back lets the board sit on a heatsink |
| R4 | Board size | **56 mm round** (originally 30–40 mm, then 70 mm; compacted to one symmetric LED ring with M3 holes on the edge, 2026-11-18; 52 mm is possible but tight to route) |
| R5 | MCU: small castellated ESP32 module (Seeed XIAO family) | Programmed through its own USB-C |
| R6 | Separate USB-C port for LED power, 5 V | Sized in section 3 |
| R7 | **Minimum component count; cheap assembly** | JLCPCB Economic PCBA for everything stocked at LCSC; hand-solder only U1 (XIAO) |
| R8 | All parts buyable in small quantities | LCSC (via JLCPCB) for the assembled parts, DigiKey for the hand-soldered parts |
| R9 | Low cost | Only a few boards will be made |

## 2. Architecture

The schematic is hierarchical, with four sub-sheets:

| Sheet | File | Contents |
|---|---|---|
| Power Input | `power_input.kicad_sch` | J1 USB-C sink, R1/R2 CC Rd, D1 XIAO feed |
| MCU | `mcu.kicad_sch` | U1 XIAO ESP32-C6 |
| White LED Driver | `white_led_driver.kicad_sch` | U2 LGS63032EP, L1, D2, C1, C2, R3 ∥ R5, OVP divider R6/R7, EN pull-down R8, 16 white LEDs (LED1, 2, 4, 5, 7, 8, 10, 11, 12, 13, 15, 16, 18, 19, 21, 22; 2 strings of 8), NTC divider (R4, RT1) |
| RGB LEDs | `rgb_leds.kicad_sch` | LED3, 6, 9, 14, 17, 20 (XINGLIGHT 5050 chain), Q1/R9 level shifter, C3, C4–C9 |

```
            USB-C J1 (power only, 5 V)                 XIAO USB-C (programming / debug)
                    │ VBUS                                   │
        CC1/CC2 ─ 5.1k Rd ×2 ─┬─► ADC (current advert.)       │
                    │         │                              │
   ┌────────────────┼─────────┼─────────────┐                │
   ▼                ▼         ▼             ▼                ▼
 LGS63032EP      RGB chain    D1 Schottky ──► XIAO 5V pin ◄── (XIAO VBUS)
 CC driver       (5 V; data via     │
   │             Q1 level shifter)  └── XIAO 3V3 LDO → ESP32-C6
   ▼                 ▲
 2 × 8 OSRAM 2835    │ DATA (3.3 V)
 parallel strings    │
   ▲ PWM → EN        │
   └──── XIAO GPIO ──┘
```

### Main choices

1. **White LEDs: 16 × ams OSRAM DURIS E 2835 GW JTLMS3.CM 3000 K as two parallel strings of 8 (~65 mA each), driven by one Legend-Si LGS63032EP constant-current boost converter.**
   - **Why this LED:**
     - Warm 3000 K with a broad spectrum: CRI 90 minimum, 92 typical, and R9 ≥ 50 (good deep-red content for plants).
     - 120° beam.
     - In stock at LCSC (C30688624, ~6k) for about $0.008 each, and eligible for JLCPCB Economic assembly.
   - **Drop-in upgrade:** GW JTLMS3.GM, same footprint and electrical class, **CRI 97**, but ~20 % less light (18.5 lm vs 23.5 lm at 60 mA). LCSC C34162565 (3000 K) / C36216698 (2700 K), lower stock.
   - **Why LGS63032EP (ESOP-8 with exposed pad, LCSC C5370937, ~$0.23, Economic-eligible):**
     - 3–60 V in (UVLO 3.0 V), 1.2 MHz, V_FB = 0.2 V ±2.5 %.
     - **1.5 A minimum switch current limit** (1.7 typ, 2.1 max), 350 mΩ internal switch.
     - **Adjustable OVP:** 1 V reference on the OVP pin with an output divider, set to ~31 V here.
     - Soft-start, UVLO, cycle-by-cycle current limit and thermal shutdown built in.
     - Maximum duty cycle **85 % minimum**. With 5 V in, that caps a string at ~9 LEDs, so 8 is comfortable.
   - **Dimming (R1):** PWM on EN at 100 Hz–100 kHz is converted to a constant LED current, so it is flicker-free with a 25,000:1 range. The firmware uses 25 kHz.
     - R8 (100 kΩ) holds EN low while the ESP32 boots. The internal 800 kΩ pull-down is too weak to rely on.
     - The firmware drives 0–100 % with a perceptual (gamma) curve and smooth fades.
   - **Alternatives considered:** AP3032 (27 V fixed OVP, 1.2 A min), DIO5661 (37 V OVP but only 1.0 A min), LGS63030EP (same chip, but PWM ≤ 1 kHz). TPS61169 and SGM3732 aren't at JLCPCB.
2. **RGB: XINGLIGHT XL-5050RGBW-2812B-HM 5050 pixels** (LCSC C48586675, Economic-eligible, ~$0.07).
   - WS2812B protocol (24-bit GRB, 800 kHz) and the standard WS2812B pinout (1 VDD, 2 DOUT, 3 VSS, 4 DIN), so it uses KiCad's stock `LED:WS2812B` symbol and footprint.
   - V_IH = 0.7 × VDD (3.5 V at 5 V), so the 3.3 V data goes through a 2N7002 level shifter (Q1/R9, section 4.3).
   - 120° viewing angle.
3. **USB-C power port: sink-only, two 5.1 kΩ Rd resistors, no PD controller.** The CC pins also go to ADC inputs so the firmware can read how much current the charger offers.
4. **XIAO powered from the board's VBUS through a Schottky diode (D1)** into its 5V pin, as Seeed recommends.
5. **XIAO-agnostic pin use.** The pins used work with the C6 (recommended), S3 and C3 (section 6.5).

## 3. Power budget: is 5 V / 2 A enough?

**Yes.** Worst case at full brightness on every channel:

| Load | Calculation | Current at 5 V |
|---|---|---|
| White, 2 strings × 8 LEDs @ 130 mA total | (8 × 2.9 V + 0.2 V) × 0.130 A = 3.04 W out, ÷ 0.8 efficiency = 3.8 W | **0.76 A** |
| RGB, 6 × 5050 @ ~36–60 mA full white | 6 × 0.06 A | **0.36 A** |
| XIAO, Wi-Fi TX peaks | | **~0.3 A** |
| **Total** | | **~1.4 A (7 W)** |

- 5 V / 2 A covers the whole design. Recommend a USB-C 5 V / 3 A charger anyway.
- **The catch:** USB-A chargers used with an A-to-C cable advertise "Default USB" (500/900 mA) on CC even when they can supply 2 A. The firmware starts in that conservative budget and offers a user override.
- The firmware sets its budget from what the CC pins advertise:

| CC reading (across 5.1 kΩ) | Source advertises | LED budget |
|---|---|---|
| < 0.2 V | nothing attached | LEDs off |
| 0.25 – 0.61 V | Default USB (0.5/0.9 A) | ~0.4 A |
| 0.70 – 1.16 V | 1.5 A | ~1.2 A (everything on, RGB capped) |
| 1.31 – 2.04 V | 3.0 A | full |

## 4. Circuit detail (as drawn)

### 4.1 Power Input sheet
- **J1:** SHOU HAN TYPE-C 6P (LCSC C456012, JLCPCB Extended, Economic-eligible, ~$0.04), a 6-pin power-only receptacle rated 5 V 3 A. Replaced the hand-soldered GCT USB4135-GF-A on 2026-11-18.
  - Footprint `USB_C_Receptacle_SHOUHAN_TYPE-C-6P` (project library) follows the drawing's recommended layout (DWG 1006-FGBXXX, [hardware/USB-C datasheet.pdf](../hardware/USB-C%20datasheet.pdf)): signal pads at x = ±0.5/±1.5/±2.7 mm, 6.45 mm behind the front face; four plated shell slots 0.6 × 1.4 mm at x = ±4.32, y = −2.6/−6.4 mm.
  - The shell legs are 0.80 mm long (the "short leg" variant), so they don't reach through the 1.6 mm board and the back stays flat. Plated slots are ordinary plated holes, not edge plating, so Economic PCBA accepts them.
  - The shell is tied to GND. The front face sits 0.2 mm beyond the board edge.
- **R1, R2:** 5.1 kΩ 1 % 0805 from CC1 and CC2 to GND. CC1 and CC2 go to XIAO D0 and D1.
- **D1:** B5819W (40 V 1 A Schottky, SOD-123, LCSC C8598 Basic; was SS14/SMA until 2026-11-18). Anode on VBUS, cathode on the XIAO 5V pin (net `XIAO_5V`).
- **H1–H4:** M3 non-plated mounting holes (`MountingHole_3.2mm_M3`), with no electrical connection.
- There is no fuse or TVS, to keep the part count down.

### 4.2 White LED Driver sheet
| Ref | Part | Value / note |
|---|---|---|
| U2 | Legend-Si LGS63032EP (LCSC C5370937) | ESOP-8 + exposed pad. Pins: 1 FB, 2 GND, 3/4 SW, 5 VIN, 6 NC (leave floating), 7 OVP, 8 EN, EP = GND (thermal vias to the planes) |
| L1 | YJYCOIN YNR4030-100M (LCSC C340393) | 10 µH, 1.5 A rated, Isat 1.95 A, 100 mΩ, 4 × 4 × 3 mm. Footprint `L_Taiyo-Yuden_NR-40xx`; check it against the YNR4030 datasheet before ordering |
| D2 | B5819W (C8598) | 40 V 1 A Schottky, SOD-123 (130 mA average, ~1 A peak). OVP limits the output to ~31 V |
| C1 | 22 µF 25 V X5R 1206 (C12891) | U2 input capacitor and main 5 V bulk capacitor. Place next to U2 |
| C2 | 10 µF 50 V X5R 1206 (C13585) | Output capacitor (datasheet uses 10 µF) |
| R6, R7 | 100 kΩ + 3.3 kΩ 0805 (C149504, C26010) | OVP divider from VOUT to GND, trips at 31.3 V. ~0.23 mA bleed |
| R8 | 100 kΩ 0805 (C149504) | EN pull-down, keeps the white LEDs off at boot |
| R3 ∥ R5 | 2.2 Ω ∥ 5.1 Ω 1 % 0805 (C17521, C17724) | I_total = 0.2 V / 1.54 Ω = **130 mA**, ~65 mA per string (the LED maximum is 90 mA at Tj = 25 °C) |
| LED1–8, LED9–16 | OSRAM DURIS E 2835 3000 K CRI 90 (C30688624) | Two parallel strings of 8, V ≈ 23.4 V |
| R4, RT1 | 10 k 0805 (C17414) + 10 k NTC B3950 (C338623) | Divider from 3V3 to XIAO D2. Place RT1 among the white LEDs. Firmware B = 3950 K |

- **Checks:**
  - Duty cycle ≈ 0.80–0.83, inside the 85 % minimum maximum duty.
  - Input current ≈ 0.76 A, and the ripple at 1.2 MHz with 10 µH is ≈ 0.34 A, so the peak is ≈ 0.93 A.
  - That is against the **1.5 A minimum** switch limit and the 1.95 A inductor saturation.
  - Headroom: ~180 mA total (90 mA per string) would peak at ~1.2 A, still inside the limit. Change R5 to set it.
  - To go the other way, R5 = 10 Ω (Basic, C17415) gives 1.8 Ω → 111 mA total.
- **Parallel strings:** the FB node sees only the total current, so the split between strings depends on how well their forward voltages match.
  - An 8-LED string has ~30 Ω dynamic resistance at this current, so a 0.2 V mismatch gives only ~7 mA imbalance.
  - Heat matters too: Vf falls ~2 mV/K per LED, so a 10 K hotter string takes ~5 mA more.
  - Worst case is ~75 mA in one string, still under the 90 mA maximum.
  - Use LEDs from one reel (same Vf bin), which JLCPCB will do anyway.
- **Current sense: no Kelvin connection needed.**
  - At 200 mV across 1.54 Ω, ~10 mΩ of trace adds ~0.7 % error, well inside the ±2.5 % V_FB tolerance.
  - Layout rules: run the FB trace from the R3/R5 top pads directly to U2 pin 1 (FB), away from SW, L1 and D2. Return the R3/R5 GND pads to the plane next to U2 GND rather than through the C1/C2 switching-current loop.
- **OVP:** strings are ~23.4 V typical, ~24.2 V worst-case bin, and the divider trips at ~31.3 V, giving ~7 V of margin. It protects D2, C2 and U2 if both strings open.
  - It does **not** catch one string opening: the other string then takes the full current (130 mA > 90 mA max). Power new boards up current-limited and check that both rings light.

### 4.3 RGB LEDs sheet
- **LED3, LED6, LED9, LED14, LED17, LED20** (renumbered 2026-11-19; were LED17–LED22): 6 × XINGLIGHT XL-5050RGBW-2812B-HM.
- **3.3 V data:** the datasheet gives V_IH = 0.7 × VDD, which is 3.5 V at 5 V, so 3.3 V data on a 5 V pixel is out of spec. Since 2026-11-19 a single-MOSFET level shifter fixes this (it replaced the D3 / 1N4148W diode trick that ran LED17 at ~4.3 V):
  - **Q1:** 2N7002 SOT-23 (JSCJ, C8545, JLCPCB Basic). Gate to 3V3, source to the XIAO's RGB_DIN, drain to DIN of the first pixel (LED20, upper-left).
  - **R9:** 3.3 kΩ 0805 pull-up from the drain to 5 V (same part as R7, C26010).
  - **Operation (non-inverting):** XIAO low → V_GS = 3.3 V → Q1 on → DIN low. XIAO high → V_GS = 0 → Q1 off → R9 pulls DIN to 5 V. No firmware change.
  - **Timing:** the falling edge is driven by Q1. The rising edge is ~2.2 × 3.3 kΩ × ~15 pF ≈ 110 ns, well inside the WS2812 T0H of 400 ± 150 ns. Low-state current is 1.5 mA.
  - **Margin:** V_GS(th) is 2.5 V per the JLCPCB/LCSC listings (check the JSCJ datasheet), so 3.3 V on the gate leaves ~0.8 V of overdrive, ample for 1.5 mA.
  - All six pixels now run directly from the 5 V rail. If the XIAO runs from its own USB with J1 unplugged, R9 has no supply, so DIN can't be driven above the unpowered pixel's VDD (only Q1's body diode could conduct).
- **C3:** 22 µF 1206 (same part as C1), bulk capacitor for the chain.
- **C4–C9:** 100 nF 0603 X7R (C14663), one per pixel, as in the datasheet application circuit. Each pixel switches its RGB channels with fast PWM edges, so place each capacitor right at its pixel's VDD/VSS pads.

### 4.4 MCU sheet
- **U1:** XIAO ESP32-C6. The project footprint `XIAO-ESP32-C6-SMD_EdgePads` is Seeed's official SMD footprint with the 10 bottom pads (JTAG, BOOT, EN, battery) removed, so nothing can short under the module.
- Unused pins (D4–D7, D9, D10) are marked no-connect.

### 4.5 BOM

The full BOM is in [hardware/bom/bom.csv](../hardware/bom/bom.csv). Each schematic symbol carries `Datasheet`, `Manufacturer`, `MFG Part Number`, `Supplier` and `Supplier Part Number`. Every LCSC part also carries **`LCSC Part #`**, which the Fabrication-Toolkit plugin reads for the JLCPCB BOM.

**JLCPCB places these** ([hardware/bom/jlcpcb_bom.csv](../hardware/bom/jlcpcb_bom.csv)): 17 lines, 47 parts per board.

| Qty | Refs | Part | LCSC | JLCPCB type |
|---|---|---|---|---|
| 1 | U2 | Legend-Si LGS63032EP ESOP-8 | C5370937 | Extended |
| 1 | J1 | SHOU HAN TYPE-C 6P power-only USB-C | C456012 | Extended |
| 2 | C1, C3 | Samsung CL31A226KAHNNNE 22 µF 25 V 1206 | C12891 | Basic |
| 1 | C2 | Samsung CL31A106KBHNNNE 10 µF 50 V 1206 | C13585 | Basic |
| 2 | R6, R8 | UNI-ROYAL 0805W8F1003T5E 100k | C149504 | Basic |
| 2 | R7, R9 | UNI-ROYAL 0805W8F3301T5E 3.3k | C26010 | Basic |
| 6 | C4–C9 | YAGEO CC0603KRX7R9BB104 100 nF 0603 | C14663 | Basic |
| 2 | D1, D2 | JSCJ B5819W | C8598 | Basic |
| 1 | Q1 | JSCJ 2N7002 SOT-23 | C8545 | Basic |
| 2 | R1, R2 | UNI-ROYAL 0805W8F5101T5E 5.1k | C27834 | Basic |
| 1 | R3 | UNI-ROYAL 0805W8F220KT5E 2.2 Ω | C17521 | Basic |
| 1 | R4 | UNI-ROYAL 0805W8F1002T5E 10k | C17414 | Basic |
| 1 | R5 | UNI-ROYAL 0805W8F510KT5E 5.1 Ω | C17724 | Basic |
| 1 | L1 | YJYCOIN YNR4030-100M | C340393 | Extended |
| 1 | RT1 | FH CMFB103J3950HANT NTC | C338623 | Extended |
| 16 | LED1–16 | ams OSRAM GW JTLMS3.CM-G8GW-XX57-1-60-R33 | C30688624 | Extended |
| 6 | LED17–22 | XINGLIGHT XL-5050RGBW-2812B-HM | C48586675 | Extended |

**You hand-solder these** ([hardware/bom/digikey_bom_5x.csv](../hardware/bom/digikey_bom_5x.csv)):

| Qty | Refs | Part | DigiKey PN |
|---|---|---|---|
| 1 | U1 | Seeed XIAO ESP32-C6 (113991254) | 1597-113991254-ND |

- **J1** is now placed by JLCPCB (C456012), so the XIAO is the only hand-soldered part and no DigiKey order is needed if the XIAO comes from Seeed/AliExpress.
- **XIAO:** buying it from Seeed or AliExpress is ~$5–10 cheaper than DigiKey.
- **H1–H4:** mounting holes, excluded from every BOM.

## 5. White LED selection (full spectrum, not pink)

Requirements: warm, broad spectrum (high CRI, not pink), wide angle, bright enough, and stocked at LCSC so JLCPCB Economic can place it.

| Candidate (LCSC) | Spectrum | Electrical | Stock / price | Verdict |
|---|---|---|---|---|
| **ams OSRAM DURIS E 2835 GW JTLMS3.CM-G8GW-XX57** (C30688624) | 3000 K, **CRI 90 min / 92 typ, R9 ≥ 50** | 2.9 V @ 60 mA, **90 mA max**, 23.5 lm typ @ 60 mA (135 lm/W), 120° | ~6k, ~$0.008 | **Chosen** |
| ams OSRAM DURIS E 2835 GW JTLMS3.GM (C34162565 3000 K / C36216698 2700 K) | **CRI 97 min / 98 typ** ("full spectrum") | 2.95 V @ 60 mA, 90 mA max, 18.5 lm typ, 120° | ~1.2k / ~850, $0.02–0.06 | Same-footprint upgrade if spectrum matters more than brightness |
| OSRAM DURIS S 5 GW JTLPS1.EM (C5220765) | 3000 K, CRI 80 | 3 V, 150 mA | ~10k | Rejected: CRI 80 |
| Cree J Series JE2835BWT-N-B27EA (C17436093) | 2700 K, **CRI 70** | 2.86 V, 150 mA | ~4.6k | Rejected: low CRI |
| Seoul SunLike 3030 (C17521270) | CRI 95 | 150 mA | Listed but **not in stock** | Not available at LCSC |
| Generic warm 2835 "1 W" parts | CRI unspecified (~80) | | plentiful | Rejected: no CRI spec |

- **Footprint:** `LED_OSRAM_DURIS_E_2835` (project library), from datasheet v1.4 p16:
  - Cathode pad 2.12 × 2.10 mm, a 0.50 mm gap, anode pad 0.92 × 2.10 mm.
  - Pad 1 is the cathode. The small corner notches in the drawing are omitted.
  - The pads sit under the body, which is fine because JLCPCB places them.
- **Is it bright enough? (target: 15 cm diameter container, mosses and ferns)**
  - Light output: 16 × 23.5 lm × ~1.07 (at ~65 mA) ≈ **400 lm**, which is ≈ 6.4 µmol/s (warm high-CRI white ≈ 0.016 µmol/s per lm).
  - Floor area: ≈ 0.018 m², with ~50–75 % of the light landing on it.
  - That gives **~180–270 PPFD at 100 %**, or ~8–12 mol/m²/day over 12 h.
  - Mosses want ~50–150 PPFD (2–5 mol/m²/day), and ferns ~50–200 PPFD (3–6 mol/m²/day). **Plenty of headroom:** expect to run at ~35–60 %.
  - The firmware default is **50 % for 10–12 h/day**.
  - **Less heat or lower peak current:** raise R5 to 10 Ω (Basic C17415) for 111 mA total, or cap the maximum in firmware.
  - **For a larger tank:** add a second driver channel.

## 6. Mechanical, thermal, PCB

### 6.1 PCB stack-up and design rules (decision D1: done 2026-11-18)
**4-layer FR4, 1.6 mm**, set up in the KiCad board to match JLCPCB's **JLC04161H-7628** stack-up (select it when ordering):

| Layer | Thickness | Use |
|---|---|---|
| F.Cu (L1) | 35 µm (1 oz) | All components and signals |
| prepreg 7628 | 0.2104 mm | |
| In1.Cu (L2) | 15 µm (0.5 oz) | Solid GND plane |
| core | 1.065 mm | |
| In2.Cu (L3) | 15 µm (0.5 oz) | 5 V (VBUS) pour plus a few signals |
| prepreg 7628 | 0.2104 mm | |
| B.Cu (L4) | 35 µm (1 oz) | Solid GND / thermal copper, **no components**. It pastes flat onto the heatsink |

**DRC rules (JLCPCB 4-layer, no-surcharge values; [capabilities page](https://jlcpcb.com/capabilities/pcb-capabilities), checked 2026-11-18):**

| Rule | Value | Where |
|---|---|---|
| Min clearance / track | 0.1 / 0.1 mm (JLC: 0.09) | Board Setup |
| Via | ≥ 0.45 mm diameter with ≥ 0.2 mm hole (smaller costs extra) | Board Setup + `.kicad_dru` |
| Via hole-to-hole / hole-to-track | 0.2 / 0.2 mm | Board Setup |
| Pad hole-to-hole (different parts) | 0.45 mm | `.kicad_dru` |
| PTH hole to other-net copper | 0.28 mm | `.kicad_dru` |
| Plated pad annular ring | ≥ 0.15 mm | `.kicad_dru` |
| NPTH hole | ≥ 0.5 mm | `.kicad_dru` |
| Copper to board edge | 0.3 mm (JLC: 0.2) | Board Setup |
| Silk text | ≥ 1.0 mm high, 0.15 mm stroke | Board Setup (all footprint labels resized to match) |
| Solder-mask web | 0.1 mm | Board Setup |

- **Net classes:**
  - **Default:** 0.2 mm track, 0.15 mm clearance, 0.6/0.3 mm via.
  - **Power:** 0.5 mm track, 0.2 mm clearance, 0.8/0.4 mm via, for GND, VBUS, XIAO_5V, the SW node (`Net-(D2-A)`) and VOUT (`Net-(D2-K)`).
  - Pre-set track widths are 0.2/0.3/0.5/0.8 mm.
- **Thermal vias:**
  - **U2:** uses `SOIC-8-1EP_..._EP2.41x3.3mm_ThermalVias`, whose six 0.2 mm-drill / 0.5 mm vias in the exposed pad meet the no-surcharge via rule.
  - **Via-in-pad:** on 4-layer boards these are left **open (unfilled)**. JLCPCB's epoxy-filled and capped "POFV" via-in-pad is only free on 6+ layers. Small open vias wick a little solder, which is acceptable for an exposed pad.
  - **White LEDs:** put thermal vias *next to* the cathode pads, not in them.
- Keep the XIAO antenna area free of copper on all layers.

### 6.2 Heat
- **Heat estimate (v0.5, 16 OSRAM LEDs at ~65 mA each):**

| Source | Full white + full RGB | Normal use (white 50 %, RGB dim) |
|---|---|---|
| White LEDs (~45 % of the power becomes light) | ~1.7 W | ~0.8 W |
| U2 losses (switch, D2, L1 DCR, R3/R5) | ~0.75 W | ~0.4 W |
| RGB, 6 × 60 mA × 5 V | ~1.5 W | ~0.1 W |
| XIAO on Wi-Fi + LDO + D1 | ~0.5 W | ~0.4 W |
| **Total** | **~4.5 W** | **~1.7 W** |

- **Board rise, 56 mm board in still air:** the board has ~49 cm² of surface counting both sides (77 cm² at 70 mm), at h ≈ 10 W/m²K.
  - Normal use: ~30–35 °C.
  - White at full only: ~60 °C.
  - Everything at full: ~90 °C. **Not acceptable unmounted:** above ~50 % white, the board must be bolted to a heatsink or lid with the M3 holes.
  - The NTC derating is the backstop.
  - The LED heat is now spread over 16 packages (~0.1 W each), so junctions run only ~+4 °C above the board.
- **Heatsinking:**
  - Normal use (white ≤ 60 %) in open air: none beyond the 4-layer board's copper.
  - White at full for long periods, or an enclosed mount: bolt the board through the M3 holes to a ~100 × 100 mm metal plate or lid, with a thermal pad.
  - The OSRAM 90 mA rating is at Tj = 25 °C and needs derating when hot. At ~65 mA (worst-case string ~75 mA) there is margin, but keep the NTC derating in firmware.
- The NTC plus firmware derating protects against a poor mount.
- Conformal coat the finished board for humidity, avoiding the connectors, the buttons and the antenna.

### 6.3 MCU module and antenna (decision D7)
- **Seeed XIAO ESP32-C6 (chosen):** on-board ceramic antenna plus U.FL, selected by an RF switch (GPIO3 enables it and must be driven LOW; GPIO14 selects, LOW = on-board).
- **Firmware note:** the C6 needs Arduino-ESP32 3.x, which may mean the community `pioarduino` platform.
- Alternatives: XIAO S3 / C3 / C5 (U.FL only) and Waveshare *-Zero boards (not footprint-compatible). Details are in the research notes.

### 6.4 Board layout (56 mm round, M3 holes on the edge, 2026-11-18)
The board is a **56 mm circle** centred at (50, 50) mm. It was enlarged from the 52 mm minimum to make routing easier.

- **LED ring:** all 22 LEDs sit on one ring around the XIAO, mirror-symmetric about both axes so the light is even.
- **Holes:** four **M3** non-plated holes are centred **on the board edge** (half-hole notches), one per quadrant, between the outer white pair.
- **Placer:** `place7.py` in the scratch tools: `place7.py <board> 24.3 3.7 59 6 21.5 0.8 3.75`, i.e. ring r, edge margin, hole angle, pair half-angle, pair radius, LED-to-LED gap and pair pitch.

**Ring layout** (angles clockwise from +x, 90° = bottom)
- Each quadrant runs: RGB on the axis, white pair, RGB at r = 24.3 mm, then the outer white pair at r₂ = 21.5 mm around the hole at 59° ± 6°.
- Lower-right quadrant angles:
  - LEDs at 0 / 14.4 / 25.5 / 39.9 / 53.0 / 65.0°.
  - Hole at 59° on the edge.
- **Each white pair is a tight, parallel group:** both LEDs point along the radial direction at the pair's mid-angle, 3.75 mm apart centre to centre (0.26 mm courtyard gap).
  - The pair's centroid sits on the ring (r, or r₂ for the pairs under the holes) at the mid-angle: 19.95° for the inner pairs, 59° for the outer ones.
  - The first LED of each pair in string order is turned 180°, so the two pads of the in-pair series link sit side by side.
  - This copies the hand edits made at 52 mm.
- LEDs in the ring are 0.8 mm apart (courtyard to courtyard at the inner edge), up from 0.25 mm, to leave room between them for routing.

**Holes**
- 4 × M3 NPTH at (±14.42, ±24.00) mm, a 28.8 × 48.0 mm rectangle.
- Half of each 3.2 mm hole is outside the outline (a U-notch), so the screw head and washer clamp the board.
- `Terrarium Smart Light.kicad_dru` exempts H1–H4 from edge clearance.

**Size limit:** 52 mm is the smallest that passes, but only in a narrow window (hole angle 58–58.5°). At 56 mm, every hole angle from 58° to 60° passes, with r₂ from 21 to 22 mm.

**Changes made along the way**
- Standard machine-placement footprints replace the HandSolder variants.
- D1/D2 changed from SS14 (SMA) to **B5819W (SOD-123, C8598, Basic, 40 V 1 A)**.
- The XIAO footprint courtyard was enlarged to cover its castellation pads.
- D1 moved to the left pocket. The XIAO_5V net crosses under the module on an inner layer.
- C2/D2 moved 2 mm right and R8 moved left of D2, following the hand edits.

**Hand edits and later changes (2026-11-18, evening)**
- **XIAO raised 6.5 mm in total** (5.3 mm by hand, then 1.2 mm more): its centre is now ~6.5 mm above the board centre.
  - It is now limited by the top outer pairs: its top corners are 0.25 mm from the inner corners of the top outer pairs (LED1/LED2 and LED21/LED22).
  - Raising it further would need those pairs moved, which breaks the top/bottom symmetry, or a bigger board. Shifting the inner pairs and the RGBs toward the horizontal gained only 0.2 mm more.
- **Outer pairs moved out to r₂ = 22.15 mm**, as far as the M3 head courtyard allows.
- **White chains inverted:** both strings now start at the bottom.
  - VOUT feeds the bottom pairs; the FB node is at the top.
  - With the 2026-11-19 clockwise numbering, string A runs VOUT → LED11 (bottom-right) → … → LED1 (top-right) → FB, and string B runs VOUT → LED12 (bottom-left) → … → LED22 (top-left) → FB (final numbering, see the placement table).
  - The white LEDs were reflected about the horizontal axis, which keeps every pad adjacency.
- **Outline rebuilt:**
  - The slot is exactly square: |x| = 6.3 mm, bottom at y = −17.6 mm, 0.56 mm above the XIAO's edge.
  - 1 mm fillets at both slot-bottom corners and where the slot meets the circle.
- **Parts parked off-board by hand:** D1, R6 and R7, to be placed during routing.

**XIAO USB slot**
- A slot 12.6 mm wide runs from the XIAO's USB end (y = −10.5 mm) to the top edge.
- A USB-C plug's overmold (~6.5 mm tall, ≤ 12.35 mm wide) is centred on a receptacle only ~2 mm above the board, so it would otherwise hit the board.

| Item | Placement |
|---|---|
| U1 XIAO | Centred, USB-C pointing up (−y) over the slot |
| LED1–LED22 | **One sequence, numbered clockwise from the top-right of the slot** (2026-11-19). Whites: LED1, 2, 4, 5, 7, 8, 10, 11, 12, 13, 15, 16, 18, 19, 21, 22. RGB pixels: LED3 (upper-right), LED6 (right), LED9 (lower-right), LED14 (lower-left), LED17 (left), LED20 (upper-left). White pairs are parallel at 3.75 mm pitch; the first LED of each pair in string order is turned 180° |
| White strings | String A (right): VOUT → LED11 → LED10 → LED8 → LED7 → LED5 → LED4 → LED2 → LED1 → FB. String B (left): VOUT → LED12 → LED13 → LED15 → LED16 → LED18 → LED19 → LED21 → LED22 → FB |
| RGB data chain | Runs anticlockwise on screen so it doesn't cross the top slot: Q1 → LED20 → LED17 → LED14 → LED9 → LED6 → LED3 (LED3 DOUT is the open end). Caps C4–C9 increase clockwise with the pixels: C4 at LED3, C5 at LED6, C6 at LED9, C7 at LED14, C8 at LED17, C9 at LED20 |
| H1–H4 | Edge, at −121° (top-left), −59° (top-right), 59° (bottom-right), 121° (bottom-left) |
| C4–C9 | Just inside each RGB pixel |
| J1 | Bottom edge, centred, front face 0.2 mm beyond the edge (SHOU HAN TYPE-C 6P) |
| Below the XIAO | C1 (centre), R1/R2 (CC), R7 (OVP bottom), R6 (OVP top, left), R3/R5 (FB sense, right) |
| Driver (U2, L1, C3, D2, C2, R8) | Right pocket between the XIAO and the ring |
| D1, R4, RT1, Q1, R9 | Left pocket (Q1/R9 near the first pixel, LED20, upper-left) |

**RGB data chain routing (2026-11-19):** the five pixel-to-pixel links (DOUT → DIN, LED20 → LED17 → LED14 → LED9 → LED6 → LED3) are on **B.Cu** as 0.4 mm arcs.
- **At each DOUT pad** (inner row): an F.Cu stub runs to a 0.6/0.3 mm via at r = 20.65 mm, just inside the pixel and clear of its 100 nF cap.
- **At each DIN pad** (outer row): an F.Cu stub runs to a via under the pixel body at r = 25.3 mm, clear of the white-LED arcs at r ≈ 23.3 mm.
- **On B.Cu:** each link bends up to a concentric arc at **r = 24.0 mm**, then bends into the next pixel's DIN via.
  - r = 24.0 mm keeps clear of the GND vias at r ≥ 24.8 mm.
  - At the bottom it passes between J1's front and rear shell slots (radii 21.3–23.1 and 25.1–26.9 mm at x = ±4.32).
- **Still to route (if not done):** Q1 drain → LED20 DIN, and U1 pin 4 → Q1 source.

**Routing notes**
- The slot cuts every layer, so two nets must go around its end, under the XIAO on inner layers: VOUT to LED9 (string B starts top-left) and the RGB data LED19 → LED20.
- String B's FB return (LED16, bottom-left) crosses under J1's area on an inner layer to R3/R5.
- The XIAO module has bottom-side pads, so route under it on inner/bottom layers only.

**Before routing:** check where the XIAO C6's ceramic antenna sits and keep copper out from under it on all layers.

**XIAO bottom pads (C6)**
- Pads 15–24 are MTDI, MTDO, EN, GND, MTMS, MTCK, BOOT, 3V3_OUT, BAT+ and BAT−. **There is no USB D+/D−** (Seeed wiki); USB is only on the module's own USB-C.
- The project footprint omits these pads, so nothing on the main board sits under them.

### 6.5 Pin assignment (as drawn)

| XIAO pin | C6 GPIO | S3 GPIO | C3 GPIO | Net | Function |
|---|---|---|---|---|---|
| D0 | 0 | 1 | 2 | CC1 | CC1 sense (ADC) |
| D1 | 1 | 2 | 3 | CC2 | CC2 sense (ADC) |
| D2 | 2 | 3 | 4 | NTC | NTC (ADC) |
| D3 | 21 | 4 | 5 | RGB_DIN | RGB data |
| D8 | 19 | 7 | 8* | WHITE_PWM | White PWM → U2 EN (LGS63032EP) |
| 5V | — | — | — | XIAO_5V | From VBUS via D1 |
| 3V3 | — | — | — | 3V3 | NTC divider supply |
| D4–D7, D9, D10 | | | | — | No-connect (D6/D7 = UART) |

\*C3 GPIO8 is a strapping pin. The C3 is a fallback only.

## 7. Firmware plan (PlatformIO)

Status (2026-11-17): first version written in [firmware/](../firmware/); it builds for C6 and S3 but hasn't run on hardware yet. See [firmware/README.md](../firmware/README.md).

- **Platform:** pioarduino 53.03.10 (Arduino-ESP32 3.1.0, the same as the knob). Environments: `xiao_esp32c6` (primary) and `xiao_esp32s3`.
- **Peripherals:**
  - LEDC PWM on D8 at **20 kHz** (the LGS63032 accepts 100 Hz–100 kHz and converts it to a constant current), 11 bit. The lowest non-zero duty is **5 %** (2.5 µs), well above the LGS63032's 400 ns minimum EN pulse; shorter pulses would be ignored. Dithering for smooth low-end fades is still to do.
  - RMT-based WS2812B driver on D3.
  - Calibrated ADC for CC1, CC2 and the NTC.
  - C6 only: GPIO3 and GPIO14 are driven LOW by the Seeed variant's `initVariant()` before `setup()`.
- **Control: emulates a Tapo L530 bulb over the local KLAP v2 protocol** (decision D11), so the tapo_light_display knob, python-kasa and Home Assistant control it directly by IP. It uses the same Tapo account credentials as the knob.
- **Modules:**
  - Done: `power` (CC budget + NTC derating, the single gate to the drivers), `white`, `rgb`, `light` (Tapo state → channels, fades), `net` (Wi-Fi), `tapo_server` / `tapo_device` (KLAP).
  - To do: `schedule` (NTP, photoperiod), provisioning / web UI / OTA, `mqtt`.
- **Settings:** stored in NVS. Secrets are never committed to git.
- **Fail-safe:** without a network, keep running the last schedule, or fall back to 12 h on / 12 h off.

## 8. Milestones
1. ~~Plan sign-off~~
2. ~~Datasheet checks~~ (done for the LGS63032EP pinout/package, OSRAM 2835 land pattern, XINGLIGHT pinout and USB4135 footprint; still to check: YNR4030 land pattern vs the NR-40xx footprint)
3. **KiCad project:** ~~schematic~~ → ~~placement~~ → 4-layer 56 mm routing with DRC clean.
4. **PlatformIO project:** skeleton with pin map, PWM and pixel bring-up on a bare XIAO.
5. **Order:** JLCPCB 4-layer + Economic PCBA (Fabrication-Toolkit output), plus the XIAO (U1) from Seeed/AliExpress or DigiKey.
6. **Bring-up:** current-limited bench supply → whites → RGB → CC detection → thermal soak.
7. **Firmware features:** schedule, then web UI, then OTA, then MQTT.

## 9. Risks

| Risk | Mitigation |
|---|---|
| Overheating | 4-layer + thermal vias, NTC derating. White LEDs at 69 % of max current |
| One string opening (OVP can't see it) | Current-limited first power-up; check both rings. Or cap the total at ≤ 90 mA (R5 → 22 Ω) for full single-string safety |
| LCSC stock of the LGS63032EP (unconfirmed) | Check the quote. Fallback: LGS63030EP (C5280694, same pinout, PWM ≤ 1 kHz) |
| Parallel-string current imbalance | Same-reel LEDs; worst case ~75 mA vs 90 mA max (section 4.2) |
| On-board antenna detuned by the heatsink | Antenna at the board edge with keep-out. U.FL fallback |
| 3.3 V data unreliable | 2N7002 level shifter (Q1/R9). Fallback 74AHCT1G125 (Extended, ~$3 per order) |
| LCSC stock of the Extended parts (XINGLIGHT ~6k, OSRAM ~6k at last check) | Check the JLCPCB quote. CRI-97 OSRAM GM and other WS2812B 5050s are footprint-compatible fallbacks (WS2812B parts are Standard-only at JLCPCB) |
| YNR4030 land pattern differs from NR-40xx | Check against the LCSC C340393 datasheet before ordering |

## 10. Open decisions

| ID | Decision | Status |
|---|---|---|
| D1 | PCB stack-up | **Done:** 4-layer FR4 1.6 mm (JLC04161H-7628), JLCPCB DRC rules set (section 6.1) |
| D2 | White LED / CCT | **OSRAM DURIS E 2835 CM, 3000 K, CRI 90+** (LCSC). The CRI-97 GM variant is a footprint-compatible upgrade |
| D3 | White power | **One LGS63032EP, 16 LEDs as 2 × 8 parallel strings (~3 W of LEDs).** ~180–270 PPFD at full in the 15 cm container; run at ~35–60 % |
| D9 | Assembly route | **JLCPCB Economic PCBA** for all LCSC parts, including J1 (C456012, since 2026-11-18). Hand-solder only U1. M3 holes are non-plated so Economic accepts the board |
| D10 | U2 by JLCPCB too? | **Decided:** the LGS63032EP is placed by JLCPCB |
| D4 | Number of RGB pixels | 6 × 5050 (drawn) |
| D5 | NTC | Fitted (drawn) |
| D6 | White dimming | EN PWM 20 kHz, minimum duty 5 % → constant current (LGS63032), with R8 pull-down |
| D7 | MCU module | **XIAO ESP32-C6** (drawn). Pin use also suits S3 and C3 |
| D8 | Board size | **56 mm round**, one symmetric LED ring (r = 24.3 mm, outer pairs at 21.5 mm, pairs parallel), 4 × M3 NPTH half-holes on the edge (28.8 × 48.0 mm rectangle), USB slot under the XIAO plug (2026-11-18). **To confirm:** the hole pattern suits the mount |
| D11 | Control protocol / no tunable white | **Emulate a Tapo L530** (KLAP v2). It reports a 2500–6500 K range. CCT away from the 3000 K native white adds an RGB tint (amber/blue) on top of the white at full requested brightness. Colour mode crossfades white → RGB by saturation (100 % = RGB only, as on an L530). `CCT_TINT_MAX = 0` disables the tint. Proposed 2026-11-17; to be confirmed at bring-up |
