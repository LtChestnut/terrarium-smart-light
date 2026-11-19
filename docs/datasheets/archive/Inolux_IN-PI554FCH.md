# Inolux IN-PI554FCH 5050 Addressable RGB LED (LED8-LED13)

- Source PDF: <http://www.inolux-corp.com/datasheet/SMDLED/Addressable%20LED/IN-PI554FCH.pdf>
- Pages: 19
- Converted: 2026-11-16 by automatic text extraction (pypdf). Tables, figures and pin diagrams may be garbled or missing; check the original PDF for anything critical (pinouts, footprints, absolute maximum ratings).

## Page 1

```text
                                                                5050 RGB LED 4-Pin With Integrated IC
                                                                                                           IN-PI554FCH

                                            INolux 5050 RGB LED
                                           4-Pin With Integrated IC
                                                     IN-PI554FCH

 Official Product           IN Part No. IN-PI554FCH              Customer Part No.                        Data Sheet No.
 Preliminary Product        ****************                      ****************                        IN-PI554FCH
 Specifications are subject to change without notice. Data and      Oct. 31, 2016      Version of 2.2        Page 1/19
 drawings herein are copyrighted.
```

## Page 2

```text
                                                                                5050 RGB LED 4-Pin With Integrated IC
                                                                                                                                      IN-PI554FCH

DISCLAIMER ......................................................................................................................................... 3

PRODUCT SPECIFICATIONS ............................................................................................................. 4

   ATTENTION: ELECTROSTATIC DISCHARGE (ESD) PROTECTION ................................................ 4

LABEL SPECIFICATIONS ................................................................................................................... 5

FEATURES .............................................................................................................................................. 6

   LED CHARACTERISTICS ........................................................................................................... 7
   RECOMMENDED OPERATING RANGES ........................................................................................ 7
   SWITCHING CHARACTERISTICS .................................................................................................. 8
   PACKAGE OUTLINE DIMENSION & PIN CONFIGURATION .............................................................. 9
   PIN DESCRIPTION .................................................................................................................... 9
   ABSOLUTE MAXIMUM RATINGS ............................................................................................... 10
   FUNCTIONAL DESCRIPTION ..................................................................................................... 10
   TIMING WAVEFORMS ............................................................................................................... 11
   CONSTANT CURRENT CHARACTERISTIC ................................................................................... 13
   TYPICAL APPLICATION CIRCUIT DIAGRAM ................................................................................. 14
   LED PERFORMANCE GRAPH .................................................................................................. 15

PRECAUTIONS .................................................................................................................................... 16

REVISION HISTORY .......................................................................................................................... 19

  Official Product                  IN Part No. IN-PI554FCH                      Customer Part No.                                   Data Sheet No.
  Preliminary Product               ****************                               ****************                                  IN-PI554FCH
  Specifications are subject to change without notice. Data and                      Oct. 31, 2016           Version of 2.2              Page 2/19
  drawings herein are copyrighted.
```

## Page 3

```text
                                                              5050 RGB LED 4-Pin With Integrated IC
                                                                                                       IN-PI554FCH

DISCLAIMER

INOLUX reserves the right to make changes without further notice to any products herein to
improve reliability, function or design. INOLUX does not assume any liability arising out of the
application or use of any product or circuit described herein; neither does it convey any
license under its patent rights, nor the rights of others.

LIFE SUPPORT POLICY

INOLUX’s products are not authorized for use as critical components in life support devices or
systems without the express written approval of the President of INOLUX or INOLUX
CORPORATION. As used herein:

1. Life support devices or systems are devices or systems which, (a) are intended for surgical
implant into the body, or (b) support or sustain life, and (c) whose failure to perform when
properly used in accordance with instructions for use provided in the labeling, can be
reasonably expected to result in a significant injury of the user.

2. A critical component in any component of a life support device or system whose failure to
perform can be reasonably expected to cause the failure of the life support device or system,
or to affect its safety or effectiveness.

 Official Product          IN Part No. IN-PI554FCH            Customer Part No.                       Data Sheet No.
 Preliminary Product       ****************                     ****************                      IN-PI554FCH
 Specifications are subject to change without notice. Data and   Oct. 31, 2016      Version of 2.2       Page 3/19
 drawings herein are copyrighted.
```

## Page 4

```text
                                                                          5050 RGB LED 4-Pin With Integrated IC
                                                                                                                           IN-PI554FCH

Product Specifications
                   Specification                                           Material                                  Quantity

 Iv                Red   ：750mcd typ.

                   Green   ：1350mcd typ.

                   Blue  ：750mcd typ.

                   @12mA/ Ta= 25°C; Tolerance ±10%

  λD               Red   ：624nm typ.

                   Green   ：524nm typ.

                   Blue  ：466nm typ.

                   @12mA/ Ta= 25° C; Tolerance ± 0.5nm

  Vf               Red   ：1.8-2.2 V

                   Green   ：2.8-3.2 V

                   Blue  ：2.8-3.2 V

                   @12mA/	Ta=	25°C;	Tolerance	±	0.05V

  Resin            Clear                                                   Epoxy Resin

  Carrier tape     EIA 481-1A specs                                        Conductive black tape

  Reel             EIA 481-1A specs                                        Conductive black                          1000pc/reel

  Label            IN standard                                             Paper

  Packing bag      220x240mm                                               Aluminum laminated bag/ no-zipper         One reel per bag

  Carton           IN standard                                             Paper                                     Non-specified

 Others:

 Each immediate box consists of 5 reels. The 5 reels may not necessarily have the same lot number or the same bin

 combinations of Iv,    λD and Vf. Each reel has a label identifying its specification; the immediate box consists of a product
 label as well.

 ATTENTION: Electrostatic Discharge (ESD) protection

                  The symbol to the left denotes that ESD precaution is needed. ESD protection for GaP and AlGaAs based

                  chips is necessary even though they are relatively safe in the presence of low static-electric discharge. Parts
                  built with AlInGaP, GaN, or/and InGaN based chips are STATIC SENSITIVE devices. ESD precaution must

 be taken during design and assembly.

 If manual work or processing is needed, please ensure the device is adequately protected from ESD during the process.

 Official Product                IN Part No. IN-PI554FCH                   Customer Part No.                             Data Sheet No.
 Preliminary Product             ****************                           ****************                             IN-PI554FCH
 Specifications are subject to change without notice. Data and                Oct. 31, 2016         Version of 2.2            Page 4/19
 drawings herein are copyrighted.
```

## Page 5

```text
                                                                   5050 RGB LED 4-Pin With Integrated IC
                                                                                                                 IN-PI554FCH

Label Specifications

▓     INolux P/N:

 I        N        -        P        I        5        5       4      F       C       H     -        X        X        X        X

             Product	                             Package	                           Color	             Customer	Code
     IN:	                          PI55:	                                     FCH:	 	                 XXXX:
     INolux	Corporation	           5.0	(L)	x	5.0	(W)	x1.6	(H)	mm	             Full	Color	             Customer	Specific	Code
                                   4:
                                   4-Pin	Version

 Official Product             IN Part No. IN-PI554FCH               Customer Part No.                          Data Sheet No.
 Preliminary Product          ****************                        ****************                         IN-PI554FCH
 Specifications are subject to change without notice. Data and         Oct. 31, 2016        Version of 2.2         Page 5/19
 drawings herein are copyrighted.
```

## Page 6

```text
                                                                        5050 RGB LED 4-Pin With Integrated IC
                                                                                                                        IN-PI554FCH

Features
1. 5050 with integrated high quality constant current IC and RGB LED chip.
2. Built-in IC, with high precision of constant current and internal RGB chips spectral processing in advance.
3. Single line data transmission（return to zero code）.
4. Specific Shaping Transmit Technology - number of LED stacked is not restricted.
5. Cascading Enhancement Technology - any 2 LED spacing can be up to 10 meters
6. Data transfer rate of 800 kbp/s at 30 frames per second.
7. RGB output port PWM control can achieve 256 grey level adjustments
9. Upon powering up, IC performs self-inspection then lights connection on the pin B lamp.
10. SA-I Anti-interference patent technology for single line data transmission.
11. Built-in power supply reverse connect protection module, reversed power input will not damage the IC.

 Official Product               IN Part No. IN-PI554FCH                  Customer Part No.                            Data Sheet No.
 Preliminary Product            ****************                          ****************                            IN-PI554FCH
 Specifications are subject to change without notice. Data and              Oct. 31, 2016         Version of 2.2          Page 6/19
 drawings herein are copyrighted.
```

## Page 7

```text
                                                                5050 RGB LED 4-Pin With Integrated IC
                                                                                                           IN-PI554FCH

LED Characteristics
                                                                                   (Ta=-25oC, unless otherwise specified)

  Light    Wavelength（nm）             Light                     Working current（mA）             Working voltage（V）
  color                               intensity（mcd）

    R           620-625                     500-1000                         12                            1.8-2.2

    G           520-525                     1000-1700                        12                            2.8-3.2

    B           465-470                     500-1000                         12                            2.8-3.2

Recommended Operating Ranges
                                                                              (Ta=-25oC, unless otherwise specified)

 Parameter                         Symbol       Min.     Typ.      Max         Unit           Test conditions

 Supply voltage                    VDD             -       5.2         -            V                        -

 R/G/B port pressure               Vds,max         -        -         26            V                        -

 DOUT drive capability             IDOH            -       49          -           mA         maximum source current

 DOUT drive capability             IDOL            -       -50         -           mA         maximum sink current

 High level input voltage          VIH           3.4        -           	           V                  VDD=5.0V

 Low level input voltage           VIL             -        -         1.6           V                  VDD=5.0V

 The frequency of PWM              FPWM            -       1.2         -          KHZ                        -

 Static power consumption          IDD             -        1          -           mA                        -

 Official Product           IN Part No. IN-PI554FCH              Customer Part No.                        Data Sheet No.
 Preliminary Product        ****************                      ****************                        IN-PI554FCH
 Specifications are subject to change without notice. Data and      Oct. 31, 2016      Version of 2.2        Page 7/19
 drawings herein are copyrighted.
```

## Page 8

```text
                                                                 5050 RGB LED 4-Pin With Integrated IC
                                                                                                             IN-PI554FCH

Switching Characteristics
                                                                               (Ta=-25oC, unless otherwise specified)

  Parameter                                       Symbol        Min.      Typ.     Max        Unit       Test conditions

  The speed of data transmission                    FDIN           -      800         -        KHZ

                                                    TPLH           -        -       500         ns
  DOUT transmission delay                                                                       ns            DIN→DOUT
                                                   TRPHL           -        -       500

                                                      Tr           -      100         -         ns              VDS=1.5
  IOUT Rise/Drop Time                                                                           ns            IOUT=13mA
                                                       Tf          -      100         -

 Official Product            IN Part No. IN-PI554FCH              Customer Part No.                        Data Sheet No.
 Preliminary Product         ****************                      ****************                        IN-PI554FCH
 Specifications are subject to change without notice. Data and       Oct. 31, 2016      Version of 2.2         Page 8/19
 drawings herein are copyrighted.
```

## Page 9

```text
                                                                 5050 RGB LED 4-Pin With Integrated IC
                                                                                                             IN-PI554FCH

Package Outline Dimension & Pin Configuration
  Outline Dim.

  Pin Configuration

Soldering terminals may shift in the x, y direction. Unit: mm Tolerance: +/-0.1mm

PIN Description
    Number                     Symbol                                        Function Description
         1                        VSS                                                  Ground
         2                        DIN                               Display data cascaded input (800k bps)
         3                        VDD                                     LED and Logic Power Supply
         4                        DO                                Display data cascaded output (800k bps)

 Official Product            IN Part No. IN-PI554FCH              Customer Part No.                         Data Sheet No.
 Preliminary Product         ****************                       ****************                        IN-PI554FCH
 Specifications are subject to change without notice. Data and       Oct. 31, 2016       Version of 2.2         Page 9/19
 drawings herein are copyrighted.
```

## Page 10

```text
                                                                      5050 RGB LED 4-Pin With Integrated IC
                                                                                                                     IN-PI554FCH

Absolute Maximum Ratings
(Ta = 25 oC, Vss=0V, unless otherwise specified)

  Parameter                                       Symbol                                       Range                          Unit

  Logic supply voltage                            VDD                                       +3.5～+5.5                         V

  Logic input voltage                             VIN                                         VDD+0.5                         V

  Operating temperature                           TOPT                                      −45 to +85                        °C

  Storage temperature                             TSTG                                     −50 to +150                        °C

  ESD pressure                                    VESD                                           4K                           V

Functional Description
The IN-PI554FCH sends signals in return to zero codes with a single-wire communication method.
When the power-on reset is completed, the IN-PI554FCH receives the data from the DIN pin.
When all the 24 bits of data have been received, IC no longer receive data, the DOUT port starts to forward the data to
the next chip as its input data. The DOUT pin is held LOW before the data forwarding. The three PWM output ports,
OUTR, OUTG and OUTB, drive Duty ratio output in a 0.6-ms period corresponding to the 24-bit data received
before.	If the input data from the DIN pin is a RESET code, the IN-PI554FCH will drive the newest received 24-bit
data for display. When the reset code is completed, the IN-PI554FCH will start receive the new 24-bit data. When 24
bits of data have been received, the IN-PI554FCH will forward the data through the DOUT pin. Before the RESET
signal is received, the output at the OUTR, OUTG and OUTB pins will remain unchanged. When a low level RESET
code longer than 80µs is received, the IN-PI554FCH will drive Duty ratio output corresponding to the newest 24-bit
data received The IN-PI554FCH employs an automatic shaping-forwarding technique, so the number of the cascaded
chips is not limited by the signal transfer, and is only limited by the panel refresh speed. For example, in a 1024-chip
cascaded design with the panel refresh time of 1024X3X8 X 1.25（us）=30ms, no flickering will appear.

 Official Product              IN Part No. IN-PI554FCH                 Customer Part No.                           Data Sheet No.
 Preliminary Product           ****************                         ****************                           IN-PI554FCH
 Specifications are subject to change without notice. Data and            Oct. 31, 2016        Version of 2.2         Page 10/19
 drawings herein are copyrighted.
```

## Page 11

```text
                                                                5050 RGB LED 4-Pin With Integrated IC
                                                                                                          IN-PI554FCH

Timing Waveforms
    1.   Input Code

    2.   The data transmission time (TH+TL=1.25µs±600ns):

                     Name                    Description                   Typ. value           error

                       T0H           0 code，high level time                   0.3µs           ±0.15µs
                       T1H           1 code，high level time                   0.6µs           ±0.15µs
                       T0L           0 code，low level time                    0.9µs           ±0.15µs
                       T1L           1 code，low level time                    0.6µs           ±0.15µs

                     Reset         Reset code，low level time                  80µs

    3.   Connection Scheme

 Official Product           IN Part No. IN-PI554FCH             Customer Part No.                        Data Sheet No.
 Preliminary Product        ****************                      ****************                       IN-PI554FCH
 Specifications are subject to change without notice. Data and     Oct. 31, 2016      Version of 2.2        Page 11/19
 drawings herein are copyrighted.
```

## Page 12

```text
                                                                      5050 RGB LED 4-Pin With Integrated IC
                                                                                                                     IN-PI554FCH

    4.   Data Transfer Format

    5.   24-bit data format

  G7     G6   G5     G4    G3   G2     G1   G0    R7     R6   R5    R4    R3    R2    R1    R0    B7    B6    B5    B4    B3    B2    B1    B0
    Note: The data is sent in the sequence of GRB, and the MSB is sent first.

 Official Product              IN Part No. IN-PI554FCH                 Customer Part No.                           Data Sheet No.
 Preliminary Product           ****************                         ****************                           IN-PI554FCH
 Specifications are subject to change without notice. Data and            Oct. 31, 2016        Version of 2.2         Page 12/19
 drawings herein are copyrighted.
```

## Page 13

```text
                                                                        5050 RGB LED 4-Pin With Integrated IC
                                                                                                                        IN-PI554FCH

Constant Current Characteristic
With excellent constant current characteristics,
     (1)  The differences of current between Channel is less than ±1.5℅
     (2)  The differences of current between Chip is less than ±3℅
     (3)  When the voltage of the load change, the output current is not affected, as shown in the figure below
     (4)  Below output port of the current Iout and add on the port voltage Vds curve relationship.
          The smaller the Iout current, the smaller in the condition of constant current need of Vds.

 Official Product               IN Part No. IN-PI554FCH                  Customer Part No.                            Data Sheet No.
 Preliminary Product            ****************                          ****************                            IN-PI554FCH
 Specifications are subject to change without notice. Data and              Oct. 31, 2016        Version of 2.2          Page 13/19
 drawings herein are copyrighted.
```

## Page 14

```text
                                                                  5050 RGB LED 4-Pin With Integrated IC
                                                                                                              IN-PI554FCH

Typical Application circuit diagram

 Official Product            IN Part No. IN-PI554FCH               Customer Part No.                         Data Sheet No.
 Preliminary Product         ****************                       ****************                         IN-PI554FCH
 Specifications are subject to change without notice. Data and        Oct. 31, 2016       Version of 2.2        Page 14/19
 drawings herein are copyrighted.
```

## Page 15

```text
                                                                  5050 RGB LED 4-Pin With Integrated IC
                                                                                                              IN-PI554FCH

LED Performance Graph

 Official Product            IN Part No. IN-PI554FCH              Customer Part No.                         Data Sheet No.
 Preliminary Product         ****************                       ****************                        IN-PI554FCH
 Specifications are subject to change without notice. Data and       Oct. 31, 2016       Version of 2.2        Page 15/19
 drawings herein are copyrighted.
```

## Page 16

```text
                                                            5050 RGB LED 4-Pin With Integrated IC
                                                                                                     IN-PI554FCH

Precautions
Please read the following notes before using the product:
1. Storage
1.1 Do not open moisture proof bag before the products are ready to use.
1.2 Before opening the package, the LEDs should be kept at 30℃ or less and 80%RH or less.
1.3 The LEDs should be used within a year.
1.4 After opening the package, the LEDs should be kept at 30℃ or less and 60%RH or less.
1.5 The LEDs should be used within 24 hours (1 day) after opening the package.
1.6 If the moisture adsorbent material has fabled away or the LEDs have exceeded the
storage time, baking treatment should be performed using the following conditions. Baking
treatment: 60±5℃ for 24 hours.

 Official Product          IN Part No. IN-PI554FCH           Customer Part No.                     Data Sheet No.
 Preliminary Product       ****************                   ****************                     IN-PI554FCH
 Specifications are subject to change without notice. Data and  Oct. 31, 2016     Version of 2.2      Page 16/19
 drawings herein are copyrighted.
```

## Page 17

```text
                                                                        5050 RGB LED 4-Pin With Integrated IC
                                                                                                                        IN-PI554FCH

2. Soldering Condition
Recommended soldering conditions:

   Profile Feature                                                         Lead-Free Solder

   Average Ramp-Up Rate (Ts max to Tp )                                    3℃/second max.

   Preheat: Temperature Min (Ts min)                                       150℃

   Preheat: Temperature Min (Ts max)                                       200℃

   Preheat: Time ( ts min to ts max )                                      60-180 seconds

   Time Maintained Above: Temperature (TL)                                 217 ℃

   Time Maintained Above: Time (t L)                                       60-150 seconds

   Peak/Classification Temperature (T P)                                   240 ℃

   Time Within 5℃ of Actual Peak Temperature ( tp)                         <10 seconds

   Ramp-Down Rate                                                          6℃/second max.

   Time 25 ℃ to Peak Temperature                                           <6 minutes max.

Note: Excessive soldering temperature and / or time might result in deformation of the LED
lens or catastrophic failure of the LED.

 Official Product               IN Part No. IN-PI554FCH                  Customer Part No.                            Data Sheet No.
 Preliminary Product            ****************                          ****************                            IN-PI554FCH
 Specifications are subject to change without notice. Data and              Oct. 31, 2016        Version of 2.2          Page 17/19
 drawings herein are copyrighted.
```

## Page 18

```text
                                                             5050 RGB LED 4-Pin With Integrated IC
                                                                                                      IN-PI554FCH

3. Soldering Iron
Each terminal is to go to the tip of soldering iron temperature less than 260℃ for 5 seconds
within once in less than the soldering iron capacity 25W. Leave two seconds and more
intervals, and do soldering of each terminal. Be careful because the damage of the product is
often started at the time of the hand solder.
4. Repairing
Repair should not be done after the LEDs have been soldered. When repairing is unavoidable,
a double-head soldering iron should be used (as below figure). It should be confirmed
beforehand whether the characteristics of the LEDs will or will not be damaged by repairing.

5. Caution in ESD
Static Electricity and surge damages the LED. It is recommended to use a wristband or anti-
electrostatic glove when handling the LED. All devices, equipment and machinery must be
properly grounded.

 Official Product          IN Part No. IN-PI554FCH            Customer Part No.                      Data Sheet No.
 Preliminary Product       ****************                    ****************                      IN-PI554FCH
 Specifications are subject to change without notice. Data and  Oct. 31, 2016      Version of 2.2      Page 18/19
 drawings herein are copyrighted.
```

## Page 19

```text
                                                                     5050 RGB LED 4-Pin With Integrated IC
                                                                                                                   IN-PI554FCH

Revision History
   Changes since last revision                                                     Page        Version No.         Revision Date
   Initial release                                                                    -               1.0             12-21-2015
   Update optical electrical characteristics                                                          2.0             06-10-2016

   Update data transmission time / intensity level/ handling                                          2.1             10-20-2016
   Update intensity level                                                                             2.2             10-31-2016

 Official Product              IN Part No. IN-PI554FCH                Customer Part No.                           Data Sheet No.
 Preliminary Product           ****************                        ****************                           IN-PI554FCH
 Specifications are subject to change without notice. Data and           Oct. 31, 2016        Version of 2.2         Page 19/19
 drawings herein are copyrighted.
```
