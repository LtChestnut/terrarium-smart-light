# Hardware

KiCad 10 project: `Terrarium Smart Light.kicad_pro`

| File | Contents |
|---|---|
| `Terrarium Smart Light.kicad_sch` | Root sheet: four hierarchical sheets wired together |
| `power_input.kicad_sch` | USB-C power-only sink (J1, SHOU HAN TYPE-C 6P), CC Rd resistors, XIAO feed diode |
| `mcu.kicad_sch` | Seeed XIAO ESP32-C6 (U1) |
| `white_led_driver.kicad_sch` | LGS63032EP boost driver (OVP divider at 31 V), 16 × OSRAM DURIS E 2835 3000 K CRI 90 (2 parallel strings of 8), NTC |
| `rgb_leds.kicad_sch` | 6 × XINGLIGHT XL-5050RGBW-2812B-HM addressable RGB chain, 2N7002 data level shifter |
| `libs/Terrarium_Smart_Light.kicad_sym` | Project symbols: Seeed_XIAO_ESP32C6, LGS63032EP |
| `libs/Terrarium_Smart_Light.pretty` | Project footprints: XIAO-ESP32-C6-SMD_EdgePads, LED_OSRAM_DURIS_E_2835, USB_C_Receptacle_SHOUHAN_TYPE-C-6P (LED_Seoul_SunLike_S1S0-3030 kept, unused) |
| `libs/Terrarium_Smart_Light.3dshapes` | Simplified 3D model for the OSRAM 2835 |
| `resources/` | XIAO STEP model, J1 drawing, `datasheets/` (PDFs; markdown copies in `docs/datasheets`) |
| `bom/bom.csv` | Master BOM (with `LCSC Part #`) |
| `bom/jlcpcb_bom.csv` | Parts for JLCPCB Economic assembly (LCSC numbers) |
| `bom/digikey_bom_5x.csv` | Hand-soldered parts for 5 boards (U1 only) |
| `fabrication-toolkit-options.json` | Saved Fabrication-Toolkit plugin options |
| `production/` | Fabrication-Toolkit output. **Not in git**: regenerate it for every order (see below) |

Checks:

```
kicad-cli sch erc "Terrarium Smart Light.kicad_sch"
kicad-cli pcb drc --schematic-parity --refill-zones "Terrarium Smart Light.kicad_pcb"
kicad-cli sch export bom -o bom/bom.csv --fields "Reference,Value,Footprint,Manufacturer,MFG Part Number,Supplier,Supplier Part Number,${QUANTITY}" --group-by "Value,MFG Part Number" "Terrarium Smart Light.kicad_sch"
```

## Generating production files (JLCPCB, Fabrication-Toolkit)

The [Fabrication-Toolkit](https://github.com/bennymeg/Fabrication-Toolkit) plugin builds everything JLCPCB needs from the board. It takes the gerbers, drill files, BOM and pick-and-place data straight from the PCB. It reads the **`LCSC Part #`** field on each footprint; every JLCPCB-placed part has one, while U1 (the XIAO, hand-soldered) and H1–H4 (holes) don't.

### 1. Install the plugin (once)
1. Open KiCad and go to **Tools → Plugin and Content Manager**.
2. Search for **Fabrication Toolkit**, click **Install**, then **Apply Pending Changes**.
3. Restart the PCB editor. A Fabrication Toolkit button appears in its top toolbar. It's also under **Tools → External Plugins**.

### 2. Before generating
1. **Update the PCB from the schematic** (F8), so the footprint fields (`LCSC Part #`, values) are current.
2. **Refill all zones** (press B).
3. **Run DRC** with "Test for parity between PCB and schematic" ticked. It should report 0 errors and 0 unconnected items. Silkscreen warnings are optional fixes.
4. **Save the board.**

### 3. Generate
1. Click the **Fabrication Toolkit** button.
2. The options saved in `fabrication-toolkit-options.json` are already right for this board:
   - **Auto fill:** on (refills zones first).
   - **Auto translate:** on (applies the plugin's JLCPCB rotation corrections).
   - **Exclude DNP:** off.
   - **Extra layers:** none.
3. Click **Generate**. The output goes to `hardware/production/`:

| File | Use |
|---|---|
| `Terrarium_Smart_Light.zip` | Gerbers and drill files, for the PCB order |
| `bom.csv` | Assembly BOM (LCSC part numbers) |
| `positions.csv` | Pick-and-place (CPL) file |
| `designators.csv`, `netlist.ipc` | Reference files. The IPC netlist can be uploaded for JLCPCB's electrical test |

### 4. Order on jlcpcb.com
**PCB:** upload `Terrarium_Smart_Light.zip` and set:
- **Layers:** 4.
- **Thickness:** 1.6 mm.
- **Stack-up:** JLC04161H-7628, which the DRC rules assume.
- **Via covering:** tented is fine. The 4-layer vias aren't via-in-pad filled (that's only free on 6+ layers), so leave "via-in-pad" off.
- **Edge plating / castellated holes:** none. The M3 edge holes are non-plated, which is what makes the board eligible for Economic assembly.

**PCB Assembly:** choose **Economic**, **top side**, and upload `bom.csv` and `positions.csv`. Then:
- **U1 (XIAO):** shows as unmatched, because it has no LCSC number. Leave it unplaced; it's soldered by hand.
- **Placement preview:** check every rotation, especially the 2835 LEDs and their polarity mark, the WS2812B pixels (pin 1), Q1 (SOT-23), D1/D2 (cathode bar), U2 (pin 1) and J1. If one is wrong, fix it in JLCPCB's preview, or add a rotation offset field on that footprint (see the plugin README) and regenerate.
- **Extended parts:** confirm stock in the quote. J1, U2, L1, RT1 and the LEDs are Extended; the rest are Basic.

Every order needs fresh output, which is why `production/` is in `.gitignore`.

The design rationale is in [../docs/plan.md](../docs/plan.md).
