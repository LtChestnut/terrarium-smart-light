# Datasheets (markdown)

The source PDFs are in [hardware/resources/datasheets/](../../hardware/resources/datasheets/), downloaded on 2026-11-19 from the LCSC datasheet server (`datasheet.lcsc.com`) or the Seeed wiki.

Each markdown file here was made from its PDF by automatic text extraction (pypdf). Text and tables are searchable, but **drawings, pinout diagrams and land patterns are not reliable**. For those, open the PDF.

## Current BOM

| File | Part | Refs | Source |
|---|---|---|---|
| [Seeed_XIAO_Series_SOM.md](Seeed_XIAO_Series_SOM.md) | Seeed Studio XIAO series (incl. ESP32-C6) | U1 | Seeed |
| [Seeed_XIAO_ESP32C6_Schematic.md](Seeed_XIAO_ESP32C6_Schematic.md) | XIAO ESP32-C6 v1.0 module schematic | U1 (reference) | Seeed |
| [Legend-Si_LGS63032EP.md](Legend-Si_LGS63032EP.md) | Legend-Si LGS6303x 60 V constant-current boost (Chinese-language) | U2 | LCSC C5370937 |
| [SHOUHAN_TYPE-C-6P.md](SHOUHAN_TYPE-C-6P.md) | SHOU HAN TYPE-C 6P power-only USB-C | J1 | LCSC C456012 |
| [OSRAM_GW_JTLMS3.CM.md](OSRAM_GW_JTLMS3.CM.md) | ams OSRAM DURIS E 2835 GW JTLMS3.CM, 3000 K CRI 90 | LED1–LED16 | LCSC C30688624 |
| [XINGLIGHT_XL-5050RGBW-2812B-HM.md](XINGLIGHT_XL-5050RGBW-2812B-HM.md) | XINGLIGHT 5050 addressable RGB (WS2812B protocol) | LED17–LED22 | LCSC C48586675 |
| [JSCJ_2N7002.md](JSCJ_2N7002.md) | JSCJ 2N7002 N-MOSFET SOT-23 | Q1 | LCSC C8545 |
| [JSCJ_B5819W.md](JSCJ_B5819W.md) | JSCJ B5819W SL Schottky 40 V 1 A SOD-123 | D1, D2 | LCSC C8598 |
| [YJYCOIN_YNR4030-100M.md](YJYCOIN_YNR4030-100M.md) | YJYCOIN YNR4030-100M 10 µH inductor | L1 | LCSC C340393 |
| [FH_CMFB103J3950HANT.md](FH_CMFB103J3950HANT.md) | Fenghua CMFB 10 kΩ B3950 NTC 0805 | RT1 | LCSC C338623 |
| [Samsung_CL31A226KAHNNNE.md](Samsung_CL31A226KAHNNNE.md) | Samsung MLCC catalogue (22 µF 25 V 1206) | C1, C3 | LCSC C12891 |
| [Samsung_CL31A106KBHNNNE.md](Samsung_CL31A106KBHNNNE.md) | Samsung MLCC catalogue (10 µF 50 V 1206) | C2 | LCSC C13585 |
| [YAGEO_CC0603KRX7R9BB104.md](YAGEO_CC0603KRX7R9BB104.md) | YAGEO CC X7R MLCC (100 nF 0603) | C4–C9 | LCSC C14663 |
| [UNI-ROYAL_0805W8F_thick_film.md](UNI-ROYAL_0805W8F_thick_film.md) | UNI-ROYAL 0805W8F thick-film resistors | R1–R9 | LCSC C17414 (same series for every value) |

- **Samsung catalogue:** LCSC links both Samsung parts to the same 84-page catalogue, so those two files are identical.
- **J1 drawing:** `hardware/resources/USB-C datasheet.pdf` (the SHOU HAN approval drawing you supplied) is the one the J1 footprint was built from.

## Superseded parts

Older conversions of parts that are no longer in the design are in [archive/](archive/), along with earlier copies of current parts:
- **No longer used:** AP3031, AP3032, Seoul SunLike, Inolux IN-PI554FCH, Diodes B140 and 1N4148W, Bourns SRN4018, Murata 1 µF and NTC, YAGEO RC resistors, GCT USB4135.
- **Older copies of current parts:** OSRAM, XINGLIGHT, LGS6303X, XIAO, YAGEO CC.
