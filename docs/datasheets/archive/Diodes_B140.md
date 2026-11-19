# Diodes B120/B-B160/B Schottky Rectifiers - B140 (D1, D2)

- Source PDF: <https://www.diodes.com/assets/Datasheets/B120_B-B160_B.pdf>
- Pages: 6
- Converted: 2026-11-16 by automatic text extraction (pypdf). Tables, figures and pin diagrams may be garbled or missing; check the original PDF for anything critical (pinouts, footprints, absolute maximum ratings).

## Page 1

```text
                                                                                                                                               B120/B - B160/B

                                                                                     1.0A SURFACE-MOUNT SCHOTTKY BARRIER RECTIFIER

Product Summary                                                                              Features and Benefits

                                                                                             •     Guard Ring Die Construction for Transient Protection
B120/B, B130/B, B140/B                                                                       •     Ideally Suited for Automated Assembly
      VRRM (V)               IO (A)             VF Max (V)          IR Max (mA)              •     Low Power Loss, High Efficiency
                                               TA = +25°C           TA = +25°C               •     Surge Overload Rating to 30A Peak
      20/30/40                 1.0                  0.5                  0.5                 •     For Use in Low-Voltage, High-Frequency Inverters, Free
                                                                                                   Wheeling, and Polarity Protection Application
B150/B, B160/B                                                                               •     Lead-Free Finish; RoHS Compliant (Notes 1 & 2)
      VRRM (V)               IO (A)             VF Max (V)          IR Max (mA)              •     Halogen and Antimony Free. “Green” Device (Notes 3)
                                               TA = +25°C           TA = +25°C               •     For automotive applications requiring specific change
        50/60                  1.0                  0.7                  0.5                       control (i.e. parts qualified to AEC        -Q100/101/104/200, PPAP
                                                                                                   capable, and manufactured in IATF 16949 certified facilities),
                                                                                                   please contact us or your local Diodes representative.
                                                                                                   https://www.diodes.com/quality/product-definitions/

Description and Applications                                                                 Mechanical Data
This   Schottky     barrier   rectifier   is   designed   to   meet   the   general
requirements  of  commercial  applications.  It  is  ideally  suited  for  use               •     Package: SMA/SMB
as:                                                                                          •     Package Material: Molded Plastic. UL Flammability Classification
                                                                                                   Rating 94V-0
•     Polarity protection diodes                                                             •     Moisture Sensitivity: Level 1 per J-STD-020
•     Re-circulating diodes                                                                  •     Terminals: Lead Free Plating (Matte Tin Finish).           Solderable per
•     Switching diodes                                                                             MIL-STD-202, Method 208
                                                                                             •     Polarity: Cathode Band or Cathode Notch
                                                                                             •     Weight:  SMA 0.064 grams (Approximate)
                                                                                                               SMB 0.093 grams (Approximate)

                                                                     Top View               Bottom View
 Ordering Information (Note 4)

               Part Number*                                                  Package                                                           Packing
                                                                                                                                  Qty.                         Carrier
               B1XX-13-F                                                        SMA                                               5,000                     Tape & Reel
               B120-13-F-N                                                      SMA                                               5,000                     Tape & Reel
               B140-13-F-N                                                      SMA                                               5,000                     Tape & Reel
               B160-13-F-N                                                      SMA                                               5,000                     Tape & Reel
               B1XXB-13-F                                                       SMB                                               3,000                     Tape & Reel
               B120B-13-F-N                                                     SMB                                               3,000                     Tape & Reel
               B140B-13-F-N                                                     SMB                                               3,000                     Tape & Reel

 *XX = Device Type, e.g., B120-13-F (SMA Package); B120B-13-F (SMB Package).
 Notes:      1. EU Directive 2002/95/EC (RoHS), 2011/65/EU (RoHS 2) & 2015/863/EU (RoHS 3) compliant. All applicable RoHS exemptions applied.
             2. See https://www.diodes.com/quality/lead-free/ for more information about Diodes Incorporated’s definitions of Halogen- and Antimony-free, "Green" and
                Lead-free.
             3. Halogen- and Antimony-free "Green” products are defined as those which contain <900ppm bromine, <900ppm chlorine (<1500ppm total Br + Cl) and
                 <1000ppm antimony compounds.
             4. For packaging details, go to our website at https://www.diodes.com/design/support/packaging/diodes-packaging/.
             *  If products manufactured in a specific region are required, select part numbers with the -N, -V, or -W suffix. These suffixes identify the wafer fabrication
                 and assembly/test locations as defined in our Supply Resiliency information.

 Marking Information

                                                                            B1X0 = Product Type Marking Code, e.g., B120 (SMA Package)
                                                             YWW            B1X0B = Product Type Marking Code, e.g., B160B (SMB Package)
                                                                                   = Manufacturers’ Code Marking
                                                       B1X0(B)              YWW = Date Code Marking
                                                                            Y = Last Digit of Year (ex: 3 for 2023)
                                                                            WW = Week Code (01 to 53)
                                                                            A bar or underline around the date code or product type marking code
                                                                            denotes assembly site if marked.
 B120/B - B160/B                                                                      1 of 6                                                                      October 2026

 Document number: DS13002 Rev. 21 - 2                                          www.diodes.com                               © 2026 Copyright Diodes Incorporated. All Rights Reserved.
```

## Page 2

```text
                                                                                                                                               B120/B - B160/B

 Maximum Ratings (@TA = +25°C, unless otherwise specified.)
 Single phase, half wave, 60Hz, resistive or inductive load
 For capacit   ive load, derate current by 20%.
                                 Characteristic                                      Symbol        B120/B       B130/B        B140/B       B150/B        B160/B         Unit
  Peak Repetitive Reverse Voltage                                                     VRRM
  Working Peak Reverse Voltage                                                        VRWM            20           30            40           50            60            V
  DC Blocking Voltage                                                                   VR
  RMS Reverse Voltage                                                                VR(RMS)          14           21            28           35            42            V
  Average Rectified Output Current @ TT = +130°C                                        IO                                      1.0                                       A
  Non-Repetitive Peak Forward Surge Current 8.3ms                                      IFSM                                      30                                       A
  Single Half Sine    Wave Superimposed on Rated Load

 Thermal Characteristics

                                 Characteristic                                      Symbol        B120/B       B130/B        B140/B       B150/B        B160/B         Unit
  Typical Thermal Resistance Junction to Terminal (Note              5)                RJT                                      20                                     °C/W
  Operating and Storage Temperature Range                                            TJ, TSTG                              -65 to +150                                    °C

 Electrical Characteristics                        (@TA = +25°C, unless otherwise specified.)

                                 Characteristic                                       Symbol          Min         Typ         Max        Unit           Test Condition
  Forward Voltage Drop                              B120/B, B130/B, B140/B               VF            —           —          0.5         V      IF = 1.0A
                                                              B150/B, B160/B                           —           —          0.7                IF = 1.0A
  Leakage Current (Note 6)                                                               I             —           —          0.5        mA      @ Rated VR, TA = +25°C
                                                                                          R            —           —           10                @ Rated VR, TA = +100°C
  Total Capacitance                                                                      CT            —          110          —          pF     VR = 4V, f = 1MHz
 Notes:      5. Thermal Resistance: Junction to terminal, unit mounted on PC board with 5.0      mm2 (0.013mm thick) copper pads as heat sink.
             6. Short duration pulse test used to minimize self-heating effect.

                       Figure 1.                                                                                 Figure 2.

 B120/B - B160/B                                                                      2 of 6                                                                     October 2026
 Document number: DS13002 Rev. 21 - 2                                         www.diodes.com                               © 2026 Copyright Diodes Incorporated. All Rights Reserved.
```

## Page 3

```text
                                                                                                                                                  B120/B - B160/B

                       Figure 3.                                                                                   Figure 4.

                                                                     1MHz

                                                                                                                                                               (°C)
                 Figure 5.                                                                                      Figure 6.

                                              Single Half Sine Wave

       Figure 7.

B120/B - B160/B                                                                        3 of 6                                                                        October 2026
Document number: DS13002 Rev. 21 - 2                                           www.diodes.com                                © 2026 Copyright Diodes Incorporated. All Rights Reserved.
```

## Page 4

```text
                                                                                                                                             B120/B - B160/B

Package Outline Dimensions

Please see http://www.diodes.com/package-outlines.html for the latest version.

                                                                                     SMA

                                                                                                                               SMA

                                                                                                                      Dim        Min      Max
                                                                                                                       A        2.29      2.92
                                                                                                                       B        4.00      4.60
                                                                                                                       C        1.27      1.63
                                                                                                                       D        0.15      0.31
                                                                                                                       E        4.80      5.59

                                                                                                                       G        0.05      0.20
                                                                                                                       H        0.76      1.52
                                                                                                                        J       1.96       2.40
                                                                                                                    All Dimensions in mm

                                                                                     SMB

                                                                                                                                      SMB
                                                                                                                            Dim        Min       Max
                                                                                                                              A       2.00       2.50

                                                                                                                             A1       0.05       0.20
                                                                                                                              b       1.96       2.21
                                                                                                                              c       0.15       0.31
                                                                                                                              D       3.30       3.94
                                                                                                                              E       5.00       5.59
                                                                                                                             E1       4.06       4.57
                                                                                                                              L       0.76       1.52
                                                                                                                           All Dimensions in mm

B120/B - B160/B                                                                     4 of 6                                                                     October 2026
Document number: DS13002 Rev. 21 - 2                                         www.diodes.com                              © 2026 Copyright Diodes Incorporated. All Rights Reserved.
```

## Page 5

```text
                                                                                                                                         B120/B - B160/B

Suggested Pad Layout

Please see http://www.diodes.com/package-outlines.html for the latest version.

                                                                                  SMA

                                                                                                                                     Value
                                                                                                               Dimensions           (in mm)
                                                                                                                     C                4.00
                                                                                                                     G                1.50
                                                                                                                     X                2.50
                                                                                                                    X1                6.50

                                                                                                                     Y                1.70

                                                                                  SMB

                                                                                                              Dimensions              Value
                                                                                                                                    (in mm)
                                                                                                                     C                 4.30
                                                                                                                     G                 1.80
                                                                                                                     X                 2.50
                                                                                                                    X1                 6.80
                                                                                                                     Y                 2.30

B120/B - B160/B                                                                   5 of 6                                                                   October 2026
Document number: DS13002 Rev. 21 - 2                                      www.diodes.com                              © 2026 Copyright Diodes Incorporated. All Rights Reserved.
```

## Page 6

```text
                                                                                                                                                   B120/B - B160/B

                                                                             IMPORTANT NOTICE

1.          DIODES INCORPORATED (Diodes) AND ITS SUBSIDIARIES MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
REGARDS TO ANY INFORMATION CONTAINED IN THIS DOCUMENT, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NON                                         -INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
RIGHTS (AND THEIR EQUIVALENTS UNDER THE LAWS OF ANY JURISDICTION).

2.          The Information contained herein is for informational purpose only and is provided only to illustrate the operation of Diodes                                 ’ products
described herein and application examples. Diodes does not assume any liability arising out of the application or use of this                                    document or any
product described herein. This document is intended for skilled and technically trained engineering customers and users who d                                   esign with Diodes’
products. Diodes’ products may be used to facilitate safety              -related applications; however, in all instances customers and users are responsible for
(a) selecting the appropriate Diodes products for their applications, (b) evaluating the suitability of Diodes’ products for                         their intended applications,
(c) ensuring their applications, which incorporate Diodes’ products, comply the applicable legal and regulatory requirements                                as well as safety and
functional-safety  related  standards,  and  (d)  ensuring  they  design  with  appropriate  safeguards  (including  testing,  validation,  quality  co                          ntrol
techniques,  redundancy,  malfunction  prevention,  and  appropriate  treatment  for  aging  degradation)  to  minimize  the  risks  associ                         ated  with  their
applications.

3.          Diodes  assumes  no  liability  for  any  application-related information,  support,  assistance  or  feedback that  may  be  provided  by  Diodes
from time to time. Any customer or user of this document or products described herein will assume all risks and liabilities a                                 ssociated with such
use, and will hold Diodes and all companies whose products are represented herein or on Diodes’ websites, harmless against al                                       l damages and
liabilities.

4.          Products  described  herein  may  be  covered  by  one  or  more  United  States,  international  or  foreign  patents  and  pending  patent
applications. Product names and markings noted herein may also be covered by one or more United States, international or fore                                       ign trademarks
and  trademark  applications.       Diodes  does  not  convey  any  license  under  any  of  its  intellectual  property  rights  or  the  rights  of  any  third  parties
(including third parties whose products and services may be described in this document or on Diodes’ website) under this docu                                 ment.

5.          Diodes’       products       are       provided       subject       to       Diodes’       Standard       Terms       and       Conditions       of       Sale
(https://www.diodes.com/about/company/terms-and-conditions/terms-and-conditions-of-sales/) or other applicable terms. This document does not
alter  or  expand  the  applicable  warranties  provided  by  Diodes.  Diodes  does  not  warrant  or  accept  any  liability  whatsoever  in  r                     espect  of  any
products purchased through unauthorized sales channel.

6.          Diodes’ products and technology may not be used for or incorporated into any products or systems whose manufacture, use or sa                                         le is
prohibited under any applicable laws and regulations. Should customers or users use Diodes’ products in contravention of any                                    applicable laws or
regulations,  or  for  any  unintended  or  unauthorized  application,  customers  and  users  will  (a)  be solely  responsible  for  any  da                   mages,  losses  or
penalties arising in connection therewith or as a result thereof, and (b) indemnify and hold Diodes and its representatives a                                 nd agents harmless
against any and all claims, damages, expenses, and attorney fees arising out of, directly or indirectly, any claim relating t                         o any noncompliance with
the applicable laws and regulations, as well as any unintended or unauthorized application.

7.          While efforts have been made to ensure the information contained in this document is accurate, complete and current, it may c                                      ontain
technical inaccuracies, omissions and typographical errors. Diodes does not warrant that information contained in this docume                                  nt is error-free and
Diodes is under no obligation to update or otherwise correct this information. Notwithstanding the foregoing, Diodes reserves                                    the right to make
modifications,  enhancements,  improvements,  corrections  or  other  changes  without  further  notice  to  this  document  and  any  produ                           ct  described
herein. This document is written in English but may be translated into multiple languages for reference. Only the English version of                                 this document
is the final and determinative format released by Diodes.

8.          Any  unauthorized  copying,  modification,  distribution,  transmission,  display  or  other  use  of  this  document  (or  any  portion  her                      eof)  is
prohibited.  Diodes  assumes  no  responsibility  for  any  losses  incurred  by  the  customers  or  users  or  any  third  parties  arising  f                     rom  any  such
unauthorized use.

9.  This  Notice  may  be        periodically    updated  with  the  most  recent          version   available    at  https://www.diodes.com/about/company/terms                -and-
conditions/important-notice

The Diodes logo is a registered trademark of Diodes Incorporated in the United States and other countries.
All other trademarks are the property of their respective owners.
© 2026 Diodes Incorporated. All Rights Reserved.

www.diodes.com

B120/B - B160/B                                                                         6 of 6                                                                        October 2026
Document number: DS13002 Rev. 21 - 2                                            www.diodes.com                                © 2026 Copyright Diodes Incorporated. All Rights Reserved.
```
