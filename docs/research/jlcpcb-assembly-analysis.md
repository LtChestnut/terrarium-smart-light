# JLCPCB / LCSC Assembly Cost Analysis (5 boards)

> **Outcome (v0.4, 2026-11-17):** the design now follows this analysis, with all LEDs moved to LCSC parts.
> - The M6 holes are non-plated.
> - All passives, diodes and LEDs are LCSC parts that JLCPCB places: 13 lines, 41 placements per board (16 white LEDs since v0.5; the cost is unchanged, because the extra LEDs are the same LCSC line and cost ~$0.008 each).
> - Only U1, J1 and U2 are hand-soldered.
>
> Updated estimate for 5 boards, excluding the bare PCB and shipping:
>
> | Item | Cost |
> |---|---|
> | JLCPCB setup + stencil | $9.71 |
> | Extended fees: L1, RT1, white LED, RGB LED (4 × $3.07) | $12.28 |
> | LCSC parts | ~$4.30 |
> | Joints | ~$0.61 |
> | **JLCPCB subtotal** | **≈ $27** |
> | DigiKey hand parts: XIAO $26.90, J1 $3.40, U2 $1.55 | ≈ $32 |
> | **Total** | **≈ $59** |
>
> That compares with ~$79–86 for the all-DigiKey, all-hand-assembled build, and you now hand-solder 3 parts per board instead of 34. The sections below are the original analysis.

Date: 2026-11-17. LCSC/JLCPCB prices come from the jlcsearch index of JLCPCB's catalogue and from JLCPCB part pages. DigiKey prices come from earlier lookups at the 5-board quantity. All prices are USD, exclude shipping, and are **estimates; re-check them in the live quote before ordering**.

## 1. JLCPCB Economic PCBA rules that matter here

| Item | Economic PCBA |
|---|---|
| Setup fee | $8.18 per order |
| Stencil | $1.53 (internal; you don't receive it) |
| SMT joints | $0.0016 each |
| Basic parts | No loading fee |
| Preferred Extended parts | No loading fee |
| Extended parts | **$3.07 per unique part number** (per order, not per placement) |
| Sides / layers | Top side only, 2/4/6 layers, 0.8–1.6 mm, 2–50 boards |
| **Castellated holes / edge plating** | **Not supported** |

**Blocker: the M6 mounting holes.** They currently break out through the board edge as plated half-holes, which counts as castellated holes / edge plating.
- Economic PCBA won't accept them. The order would fall to Standard PCBA: $25.56 setup + $8.21 stencil + $1.53 for every unique part, Basic included. That makes assembly clearly uneconomic for 5 boards.
- The bare PCB also attracts a castellated-hole upcharge (one report puts it at about $36), whoever assembles it.
- **Fix before ordering anything:** either make the edge notches **non-plated** (lose the plated ground contact), or pull the plated holes fully inside the outline (smaller PCD or a smaller pad).

Sources:
- [JLCPCB assembly price](https://jlcpcb.com/help/article/pcb-assembly-price)
- [JLCPCB: reduce prototype assembly cost](https://jlcpcb.com/blog/reduce-pcb-assembly-cost-prototype)
- [JLCPCB castellated holes](https://jlcpcb.com/help/article/what-is-castellated-holes)

## 2. Part-by-part: DigiKey vs LCSC/JLCPCB

| Ref | Current part (DigiKey) | DigiKey, 5 boards | LCSC / JLCPCB match | JLC type | LCSC, 5 boards | JLC Economic? | Verdict |
|---|---|---|---|---|---|---|---|
| D1, D2 | B140-13-F | ~$2.50 | **SS14** C2480 (40 V 1 A SMA, same footprint) | **Basic** | ~$0.20 | Yes | **JLC** |
| D3 | 1N4148W-7-F | ~$0.90 | **1N4148W** C81598 (SOD-123) | **Basic** | ~$0.06 | Yes | **JLC** |
| C1, C3 | CL31A226KPHNNNE 22 µF 10 V | ~$3.00 | **CL31A226KAHNNNE** C12891 (22 µF **25 V**, 1206) | **Basic** | ~$1.03 | Yes | **JLC** (better part) |
| C2 | GRM31CR71H105KA61L 1 µF 50 V | ~$1.25 | **CL31B105KBHNNNE** C1848 (1 µF 50 V X7R 1206) | **Basic** | ~$0.31 | Yes | **JLC** |
| C4–C9 | CC0603KRX7R9BB104 100 nF | ~$1.50 | **CC0603KRX7R9BB104** C14663 (identical) | **Basic** | ~$0.25 | Yes | **JLC** |
| R1, R2 | RMCF0805FT5K10 | ~$1.00 | **0805W8F5101T5E** C27834 (5.1k 1 %) | **Basic** | ~$0.06 | Yes | **JLC** |
| R4 | RC0805FR-0710KL | ~$0.50 | **0805W8F1002T5E** C17414 (10k 1 %) | **Basic** | ~$0.02 | Yes | **JLC** |
| R3 | RC0805FR-071R5L 1.5 Ω | ~$0.50 | 0805W8F150KT5E C17392 | Extended | ~$0.02 + $3.07 | Yes | **Hand** |
| RT1 | NCP21XV103J03RA NTC | ~$1.00 | CMFB103J3950HANT C338623 (10k B3950) | Extended | ~$0.10 + $3.07 | Yes | **Hand** |
| L1 | SRN4018-100M | ~$1.85 | YNR4030-100M C340393 (10 µH, Isat 1.95 A, 4×4 mm) or SRN4018TA-100M C2044417 | Extended | ~$0.35 + $3.07 | Yes | **Hand** (YNR4030 is a better part; worth adopting even from LCSC) |
| U2 | AP3032KTR-G1 | ~$1.55 | AP3032KTR-G1 C264086 (identical) | Extended | ~$1.34 + $3.07 | Yes | **Hand** |
| J1 | GCT USB4135-GF-A | ~$3.40 | Not stocked. TYPE-C 6P alternatives (e.g. C2927028, ~$0.05) need a footprint change | Extended | ~$0.25 + $3.07 | Yes | **Hand** |
| LED1–7 | SunLike S1S0-3030409503 | ~$19 | C17521270 is listed but **not in stock** | Extended | n/a | n/a | **Hand** (DigiKey) |
| LED8–13 | Inolux IN-PI554FCH | ~$13.50 | C22219545 is listed but **not in stock**. WS2812B / XL-5050RGBC parts are **Standard-only** at JLC. XL-5050RGBW-2812B-HM C48586675 (~$0.07) is Economic, but it is **RGBW** with a different protocol and pinout | Extended | ~$2.10 + $3.07 | RGBW only | **Hand**, unless you want RGBW (§4) |
| U1 | XIAO ESP32-C6 | ~$27 | Not at LCSC | n/a | n/a | n/a | **Hand** (DigiKey, or ~$5 each from Seeed/AliExpress) |

Rule of thumb: an Extended part is only worth it when **(DigiKey − LCSC) × 5 boards × qty per board > $3.07**. On this BOM, the only line that passes is the RGB LEDs, and only via the RGBW swap.

## 3. Scenarios (5 boards, parts + assembly only)

| | A. All hand-assembled, DigiKey parts | B. JLC places the Basic parts only | C. B + RGBW LEDs by JLC |
|---|---|---|---|
| DigiKey parts | ~$79 (all) | ~$68 (removes ~$10.65 of Basic lines) | ~$55 |
| JLC setup + stencil | — | $9.71 | $9.71 |
| JLC parts + joints | — | ~$2.30 | ~$4.40 |
| JLC Extended fees | — | — | $3.07 |
| Your own stencil or paste | ~$7 stencil, optional | Syringe paste for the hand parts (the board is already populated) | Same as B |
| **Total** | **~$79–86** | **~$80** | **~$72** |
| Placements per board you do yourself | 34 | 19 | 13 |
| Design changes | none | swap 7 lines to the Basic LCSC parts | B + new RGBW symbol/footprint + SK6812-RGBW firmware |

The XIAO accounts for ~$27 of every column. Buying it from Seeed or AliExpress saves ~$5–10 on any route.

## 4. Conclusions

1. **The cost is roughly the same either way.** Option B (JLC places only the free Basic passives) is within a few dollars of doing everything yourself. JLC's $9.71 fixed fee eats almost exactly the ~$10 saved on passives.
   - **The real gain is labour:** JLC places 15 of the 34 parts per board, all the small ones (0603/0805/SOD-123/SMA).
   - **What you still do:** the 3030 LEDs, the 5050 LEDs, U2, L1, J1, R3, RT1 and the XIAO.
2. **Full JLC assembly isn't possible** with the chosen parts. SunLike, IN-PI554FCH, the XIAO and the GCT USB-C aren't stocked at LCSC/JLC. Swapping them for LCSC-stocked parts costs about $3.07 each in fees and loses the parts we chose for good reasons (full spectrum, the hand-solderable connector).
3. **The only clear money saver is option C:** replace the RGB pixels with XINGLIGHT XL-5050RGBW-2812B-HM (Economic-eligible). It saves ~$8 per 5 boards and gives an extra warm-white channel. But it changes the symbol and footprint, its 3.3 V data threshold needs checking, and the firmware needs SK6812-style RGBW. Probably not worth it for 5 boards.
4. **Worth doing whichever route you pick:**
   - Switch D1/D2 to **SS14** and C1/C3 to **CL31A226KAHNNNE (25 V)**. They are equal or better parts, so the BOM works for both DigiKey and JLC.
   - Consider the **YNR4030-100M** inductor (Isat 1.95 A vs 1.4 A) if you buy any parts from LCSC.
5. **The M6 plated edge holes block Economic PCBA and add a castellation upcharge to the bare PCB.** Decide on them before ordering anything (§1).

## 5. Files
- `hardware/bom/jlcpcb_bom_basic_parts.csv`: JLCPCB-format BOM (Comment, Designator, Footprint, LCSC Part #) for option B. A CPL (placement) file still has to be exported from the PCB once layout is final.
