# CLAUDE.md

Guidance for Claude Code when working in this repository.

## Project
A terrarium grow light. A 56 mm circular PCB (centred at 50,50 mm; 4× M3 **non-plated** mounting holes centred on the board edge on a 28.8 × 48.0 mm rectangle; a slot under the XIAO USB plug) carries a Seeed Studio XIAO module (ESP32-C6 recommended; the footprint also accepts the S3 and C3), soldered by its castellations. It also carries a Legend-Si LGS63032EP constant-current boost driver for 16 warm, high-CRI white LEDs as two parallel strings of 8 (ams OSRAM DURIS E 2835 3000 K CRI 90+, dimmable), and a chain of WS2812B-protocol RGB pixels (XINGLIGHT 5050). It has two USB-C ports: the XIAO's own (programming) and a power-only USB-C sink on the board (5 V, up to 3 A).

**The source of truth for the design is [docs/plan.md](docs/plan.md).** Update it whenever a design decision changes; its "Open decisions" table records what has and hasn't been agreed.

## Hard constraints (do not violate without asking)
- **Components on one side only.** Multilayer (4-layer planned) and vias are fine. The bottom side has no components so it can sit flat on a heatsink.
- **Avoid through-hole parts.** Anything that pokes through must be trimmed flush so the back stays flat.
- **Main white LEDs must be full spectrum (sunlight-like, high CRI), not pink/purple horticulture parts, and dimmable.**
- **Minimise component count and assembly cost.**
  - Assembly is **JLCPCB Economic PCBA** (top side only) for every part stocked at LCSC. Only U1 (XIAO) is hand-soldered.
  - Prefer **JLCPCB Basic or Preferred-Extended** parts: they have no loading fee. Each unique Extended part costs ~$3.07 per order.
  - Economic PCBA does **not** allow castellated or edge-plated holes, so keep holes that cut the outline non-plated.
  - Reuse the same part value where possible to keep BOM lines down.
  - 0805 is the default passive size; 0603 is allowed for small decoupling caps. Avoid QFN/BGA.
- **Sourcing:**
  - JLCPCB-placed parts come from LCSC and must be in stock and Economic-eligible. Check the JLCPCB part page's "PCBA Type": many WS2812B parts are "Standard only".
  - Hand-soldered parts (just the XIAO) come from Seeed/AliExpress or DigiKey.
  - Before adding a part, confirm it is **Active and in stock**. Samsung horticulture LEDs went EOL in 2025, so don't assume a well-known part is still available.
- **LEDs must be wide angle** (≥115°).
- **Power:** total draw must stay within the USB-C budget the firmware detects from the CC pins (see plan section 3).

## Layout
- `docs/`: plan and research notes (`docs/research/`). Cite sources for part data.
- `hardware/`: KiCad project (`Terrarium Smart Light.kicad_pro`) with a hierarchical schematic (root plus `power_input`, `mcu`, `white_led_driver` and `rgb_leds` sheets). Project symbol and footprint libraries are in `hardware/libs/` (`Terrarium_Smart_Light.kicad_sym` / `.pretty`), registered via the project `sym-lib-table` and `fp-lib-table`. The BOM is in `hardware/bom/` and Gerbers go in `hardware/fab/`.
- `docs/datasheets/`: every component datasheet converted to markdown (automatic text extraction, so check the original PDF for drawings, pinouts and land patterns).
- `enclosure/`: enclosure STEP exports. The enclosure is designed in Onshape (link in README.md); the Onshape document is the source of truth.
- `firmware/`: PlatformIO project, Arduino framework, with environments for the XIAO ESP32-C6 (primary) and ESP32-S3.

## Firmware conventions
- Pin assignments live in one header (`firmware/include/pins.h`) and must match the schematic and the pin table in docs/plan.md.
- Wi-Fi credentials and secrets go in `firmware/include/secrets.h` (gitignored). Never commit them.
- Every brightness request goes through the power-budget module. No code writes PWM or pixel values directly.
- Build: `pio run -d firmware`; upload: `pio run -d firmware -t upload`; monitor: `pio device monitor -d firmware`.

## Hardware conventions
- KiCad 9 (or the latest stable). Put custom symbols and footprints in the project-local library, not the global one.
- Run ERC and DRC clean before committing a layout change. The board is 4-layer (JLC04161H-7628 stack-up) and the JLCPCB 4-layer rules are already set: Board Setup minimums in the `.kicad_pro`, plus extra rules in `Terrarium Smart Light.kicad_dru`. Use vias of 0.45 mm or larger with 0.2 mm or larger holes (smaller costs extra at JLCPCB). Power nets use the `Power` net class.
- Keep copper out of the XIAO antenna area on every layer.

## Schematic conventions
- Hierarchical sheets, one per function. Sheets connect through sheet pins wired on the root sheet.
- **Prefer wires over net labels.** Use hierarchical labels only at sheet boundaries. Use power symbols only for GND (plus PWR_FLAGs).
- Every symbol must have `Datasheet`, `Manufacturer`, `MFG Part Number`, `Supplier` and `Supplier Part Number` populated.
- **Every part JLCPCB should place must also have an `LCSC Part #` field** (e.g. `C14663`). The [Fabrication-Toolkit](https://github.com/bennymeg/Fabrication-Toolkit) plugin builds the JLCPCB BOM/CPL from it. Hand-soldered parts (Supplier = DigiKey) leave it out.
- If no KiCad library symbol exists for a part, or its pin numbering doesn't match the part, create one in the project library. Always check the pinout against the datasheet: WS2812B clones differ, and the Inolux IN-PI554FCH did not match the stock WS2812B symbol.
- After schematic changes, run `kicad-cli sch erc` (target: 0 errors and 0 warnings) and re-export the BOMs to `hardware/bom/`:
  - `bom.csv`: master BOM
  - `jlcpcb_bom.csv`: LCSC parts
  - `digikey_bom_5x.csv`: hand-soldered parts
- Then update the PCB from the schematic and run DRC with `--schematic-parity`.
