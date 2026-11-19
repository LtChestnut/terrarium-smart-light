# Seeed Studio XIAO series (ESP32-C6) datasheet (U1)

- Source PDF: <https://files.seeedstudio.com/wiki/XIAO/Seeed-Studio-XIAO-Series-SOM-Datasheet.pdf>
- Pages: 34
- Converted: 2026-11-19 by automatic text extraction (pypdf). Tables, figures and pin diagrams may be garbled or missing; check the original PDF for anything critical (pinouts, footprints, absolute maximum ratings).

## Page 1

```text
                                                                                                 0 / 34

·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 2

```text
Foreword

Why need this SoM User Manual?

     The SoM User Manual opens-sources XIAO hardware and software materials, providing professional product design
guidelines to help you accelerate your ideas off the ground.
     XIAO is a series of dev boards with a compact design, thumb-sized form factor, powerful processors, and rich peripherals. As a
complete microcontroller, it can act as a building block for larger compute systems so as to simplify the process of designing and
building complex electronic systems by providing a pre-integrated and tested platform. By adopting XIAO, you can focus on creating
the unique features and functions of your system, without having to worry about the time and effort involved in integrating and testing
the individual components.
     The potential of XIAO Series in various vertical application scenarios has been explored, including mechanical keyboards,
trackers, detection tools, wearable devices, and healthcare devices, to name a few. XIAO Series is fully ready to be integrated into
differentiated devices as a board-level circuit that provides core components of an embedded processing system.
     This User Manual can provide everything needed from module selection to the final manufacturing. The introduction (1.) will
provide general information about the whole XIAO Series and the outstanding features of each XIAO module. Thorough and complete
file lists of each XIAO are presented in Table of Contents (2.3.4.5) respectively through which you can easily pinpoint the information
of the XIAO that you decide to incorporate into your design. Notification              (6.) mainly focuses on the points that need your special
attention when using XIAO. PCBA Service (7.) is where you can make the ideas become substantial and commercial products.
Application (8.) displays doable application directions to give you some inspiration.

Brief Selection Guide of XIAO

     XIAO means Tiny in Chinese. The whole series includes XIAO SAMD21, XIAO RP2040, XIAO nRF52840, XIAO nRF52840
Sense, and XIAO ESP32C3. As the most classic one among XIAO, XIAO SAMD21 has strong stability and compatibility, XIAO
SAMD21 has been sought after and applied by musical gadgets. XIAO RP2040 is compatible with the Raspberry Pi RP2040
ecosystem and has been widely used in mechanical keyboards. Supporting Bluetooth 5.0, XIAO nRF52840 shows its potential in
environmental data collection, detection tools, and smart home devices in which wireless communication plays an important role.
XIAO nRF52840 Sense features an onboard microphone and 3-axis IMU and also supports Bluetooth 5.0, which makes it perfect for
TinyML and AIoT projects. XIAO ESP32C3 is a low-cost, high-performance RISC-V IoT development board that supports
Bluetooth&WiFi, it has shown its power in becoming a powerful module on trackers.

       Name                XIAO SAMD21                XIAO RP2040               XIAO nRF52840            XIAO nRF52840 Sense                XIAO ESP32C3

                        - A universal mini dev     - Compatible with         - Mini low-power            - Advanced version of            - Budget-friendly and
  One-Sentence          board with strong          the Raspberry Pi          consumption dev             XIAO nRF52840 with               high-performance
   Description          stability and              RP2040 ecosystem          board supporting            onboard microphone and           RISC-V WiFi&BLE
                        compatibility                                        Bluetooth 5.0               3-axis IMU                       dev board
                        - Controller for 3D                                  - Environmental data                                         - Smart home
 Recommended            Printers                   - Mechanical              collection                  - TinyML and AIoT                devices
   Application          - Trackers                 - Keyboards               - Detection tools           projects                         - AIoT projects
                        - Musical gadgets                                    - Smart home devices

Seeed Ecosystem

     Seeed Studio is the IoT hardware partner for digital innovators. Seeed works closely with global technology ecosystems to
provide hardware modules, devices, and related services. We grow ideas into differentiating products by providing easily acce                            ssible
technologies with quality and delivery guaranteed. We combine Shenzhen’s agile manufacturing resources with Seeed’s global sales
experience, including sourcing, manufacturing, marketing, logistics, and warehousing services. It is Seeed’s mission to becom                            e the
most reliable hardware platform and to empower digital pioneers to achieve their digital transformation goals. Whether it is a bare
idea, a feasible prototype, or a mature product, Seeed serves anyone looking for robust customization and manufacturing.

                                                                               1 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 3

```text
                                                                                                              Table of Content

FOREWORD ......................................................................................................................................................................................................................................... 1

         Why need this SoM User Manual? ............................................................................................................................................................................................... 1
         Brief Selection Guide of XIAO ...................................................................................................................................................................................................... 1
         Seeed Ecosystem......................................................................................................................................................................................................................... 1

TABLE OF CONTENT .......................................................................................................................................................................................................................... 2

1.  INTRODUCTION .............................................................................................................................................................................................................................. 4

    1.1 Features of XIAO Series ............................................................................................................................................................................................................. 4
    1.2 Description of XIAO SoM ............................................................................................................................................................................................................ 4
         Seeed Studio XIAO SAMD21 ....................................................................................................................................................................................................... 4
         Seeed Studio XIAO RP2040 ........................................................................................................................................................................................................ 5
         Seeed Studio XIAO nRF52840 / Sense ....................................................................................................................................................................................... 6
         Seeed Studio XIAO ESP32C3 ..................................................................................................................................................................................................... 7
    1.3. XIAO Series Comparison Table................................................................................................................................................................................................. 8
    1.4. Ordering Information .................................................................................................................................................................................................................. 9

2. SEEED STUDIO XIAO SAMD21 .................................................................................................................................................................................................... 10

    2.1 Functional Introduction ............................................................................................................................................................................................................. 10
         2.1.1 Chip Datasheet .................................................................................................................................................................................................................. 10
         2.1.2 Pinout Reference ............................................................................................................................................................................................................... 10
         2.1.3 Power Consumption .......................................................................................................................................................................................................... 10
         2.1.4 Operating Voltage ............................................................................................................................................................................................................. 10
         2.1.5 Hardware and Software Feature ....................................................................................................................................................................................... 10
         Additional Functionality of XIAO SAMD21 ................................................................................................................................................................................. 10
         Software Tutorials....................................................................................................................................................................................................................... 10
         2.1.6 Bootloader ......................................................................................................................................................................................................................... 11
         Enter Bootloader Method: wire shoring RST connectors ........................................................................................................................................................... 11
         2.1.7 Programming Languages .................................................................................................................................................................................................. 11
    2.2 File Resources .......................................................................................................................................................................................................................... 12
         2.2.1 PCBA ................................................................................................................................................................................................................................. 12
         2.2.2 Structure ............................................................................................................................................................................................................................ 12

3. SEEED STUDIO XIAO RP2040 ..................................................................................................................................................................................................... 14

    3.1 Functional Introduction ............................................................................................................................................................................................................. 14
         3.1.1 Chip Datasheet .................................................................................................................................................................................................................. 14
         3.1.2 Pinout Reference ............................................................................................................................................................................................................... 14
         3.1.3 Power Consumption .......................................................................................................................................................................................................... 14
         3.1.4 Operating Voltage and Supply Voltage ............................................................................................................................................................................. 14
         3.1.5 Hardware and Software Feature ....................................................................................................................................................................................... 14
         Software Resources ................................................................................................................................................................................................................... 15
         3.1.6 Bootloader ......................................................................................................................................................................................................................... 15
         3.1.7 Programming Languages .................................................................................................................................................................................................. 15
    3.2 File Resources .......................................................................................................................................................................................................................... 15
         3.2.1 PCBA ................................................................................................................................................................................................................................. 15
         3.2.2 Structure ............................................................................................................................................................................................................................ 15
         3.2.3 Certification........................................................................................................................................................................................................................ 16

4. SEEED STUDIO XIAO NRF52840/SENSE .................................................................................................................................................................................... 18

    4.1 Functional Introduction ............................................................................................................................................................................................................. 18
         4.1.1 Chip Datasheet .................................................................................................................................................................................................................. 18
         4.1.2 Pinout Reference ............................................................................................................................................................................................................... 18
         4.1.3 Power Consumption .......................................................................................................................................................................................................... 18
         Power Consumption Verification ................................................................................................................................................................................................ 18
         4.1.4 Operating Voltage ............................................................................................................................................................................................................. 18
         4.1.5 Charging Current ............................................................................................................................................................................................................... 18
         4.1.6 Hardware and Software Feature ....................................................................................................................................................................................... 18
         Hardware Additional Functionality .............................................................................................................................................................................................. 18

                                                                                                                                              2 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 4

```text
         Software Features ...................................................................................................................................................................................................................... 19
         4.1.7 Bootloader ......................................................................................................................................................................................................................... 19
         4.1.8 Programming Languages .................................................................................................................................................................................................. 19
         Two Arduino Libraries ................................................................................................................................................................................................................ 19
    4.2 File Resources .......................................................................................................................................................................................................................... 19
         4.2.1 PCBA ................................................................................................................................................................................................................................. 19
         4.2.2 Certification........................................................................................................................................................................................................................ 20

5. SEEED STUDIO XIAO ESP32C3 ................................................................................................................................................................................................... 22

    5.1 Functional Introduction ............................................................................................................................................................................................................. 22
         5.1.1 Chip Datasheet .................................................................................................................................................................................................................. 22
         5.1.2 Pinout Reference ............................................................................................................................................................................................................... 22
         5.1.3 Power Consumption .......................................................................................................................................................................................................... 22
         5.1.4 Operating Voltage ............................................................................................................................................................................................................. 22
         5.1.5 Charging Current ............................................................................................................................................................................................................... 23
         5.1.6 Hardware and Software Feature ....................................................................................................................................................................................... 23
         Hardware .................................................................................................................................................................................................................................... 23
         Software Tutorial ........................................................................................................................................................................................................................ 23
         5.1.7 Bootloader ......................................................................................................................................................................................................................... 23
         5.1.8 Programming Languages .................................................................................................................................................................................................. 23
    5.2 File Resources .......................................................................................................................................................................................................................... 24
         5.2.1 PCBA ................................................................................................................................................................................................................................. 24
         5.2.2 Structure ............................................................................................................................................................................................................................ 24

6. NOTIFICATION ............................................................................................................................................................................................................................... 26

    XIAO SAMD21 and XIAO RP2040 ................................................................................................................................................................................................. 26
    XIAO nRF52840/Sense .................................................................................................................................................................................................................. 26
         Q1: My Arduino IDE is stuck when uploading code to the board ............................................................................................................................................... 26
         Q2: My board is not showing up as a serial device on Arduino IDE                                                       .......................................................................................................................................... 26

7. PCBA SERVICE ............................................................................................................................................................................................................................. 28

    7.1 Turnkey PCB Assembly - Complete PCBA Quotation in Seconds........................................................................................................................................... 28
         Seeed Fusion Turnkey PCB Assembly Service Prototype to Mass Production                                                                     ........................................................................................................................ 28
    7.2 OEM / ODM / and other design Services ................................................................................................................................................................................. 28
         What is the Seeed OEM Service? .............................................................................................................................................................................................. 28
         What are the benefits of Seeed OEM service? .......................................................................................................................................................................... 29
    7.3 Seeed Licensed Products Program .......................................................................................................................................................................................... 29
         What is Licensed Products Program .......................................................................................................................................................................................... 29
         Success Stories with Seeed Licensed Products Program ......................................................................................................................................................... 30
    7.4 Seeed Studio XIAO Series Co-invent Campaign ..................................................................................................................................................................... 30
         7.4.1 POWER-UP PCBA #19: Speed up TinyML development with Seeed XIAO RP2040 and FREE Prototypes with Seeed Fusion                                                                                                                         ................................... 30
         How to apply ............................................................................................................................................................................................................................... 30
         7.4.2 POWER-UP PCBA #18: Open up new IoT possibilities with Seeed XIAO BLE for TinyML and Seeed Fusion PCBA service                                                                                                                  ....................................... 31
         How to apply ............................................................................................................................................................................................................................... 31

8. APPLICATION ................................................................................................................................................................................................................................ 32

                                                                                                                                           3 / 34

         ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 5

```text
1.      Introduction

     A System-on-Module (SoM) is a type of computer system that is integrated onto a single module and is designed to be used as a
building block for larger systems. Seeed Studio XIAO is a series of thumb               -sized System-on-Modules (SoM) that provides various core
components of an embedded processing system, including the processor core, communication interface, and memory module to a
single printed circuit board (PCB) ready for production.
     “XIAO” means tiny in Chinese, tiny but powerful. Powerful and popular chips like SAMD21, nRF52840, RP2040, and ESP32C3
empower XIAO modules. Its compact and fully-integrated design makes it possible for many applications. In addition, all SMD
components are placed on the same side of the board so that designers can easily integrate XIAO into their own boards for rapid
mass production.

1.1 Features of XIAO Series

    ●   Ultra Small Size: XIAO series come in a standard thumb-sized form factor, only 21x17.5mm. Made for space-constrained
      scenarios.
    ●   Rich Interface: Up to 11 available IOs support multiple interfaces, including analog, digital, IIC, UART, SPI, and more.
    ●   Powerful and Popular MCUs: Powerful core with a strong performance for diverse and complex applications.
    ●   SMD Design: Single-sided components, surface mounting design. Easily integrate XIAO into other boards for mass production.

1.2 Description of XIAO SoM

Seeed Studio XIAO SAMD21

     Seeed Studio XIAO SAMD21 carries the powerful ATSAMD21G18A-MU and has 14 PINs, which can be used for 11 digital
interfaces, 11 mock interfaces, 10 PWM interfaces (d1-d10), 1 DAC output pin D0, 1 SWD pad interface, 1 I2C interface, 1 SPI
interface, 1 UART interface, Serial communication indicator (T/R), Blink light (L) through pin multiplexing. It needs to be noted that
these functions are achieved through pin reuse. The colors of LEDs (Power, L, RX, TX) are green, yellow, blue, and blue. Moreover,
Seeed Studio XIAO SAMD21 has a Type-C interface that can supply power and download code. There are two reset contact point,
you can short-connect them to reset the board.

                                                                              4 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 6

```text
                       Item                                                                      Value
                       CPU                                        ARM Cortex-M0+ CPU(SAMD21G18) running at up to 48MHz
                Flash Memory                                                                     256KB
                     SRAM                                                                        32KB
               Digital I/O Pins                                                                    11
               Analog I/O Pins                                                                     11
                 I2C interface                                                                      1
                 SPI interface                                                                      1
                    QTouch                                                           7 (A0,A1,A6,A7,A8,A9,A10)
               UART interface                                                                       1
    Power supply and downloading                                                                Type-C
                   interface
                     Power                                                                    3.3V/5V DC
                 Dimensions                                                                20×17.5×3.5mm
         Programming Language                                                 Arduino, CircuitPython and Micropython

                                              Table 1: Present Key Specification of XIAO SAMD21

Seeed Studio XIAO RP2040

     The Seeed Studio XIAO RP2040 is as small as the Seeed Studio XIAO SAMD21 but it's more powerful. It carries a powerful
Dual-core RP2040 processor that can flexible clock running up to 133 MHz which is a low-power microcontroller. There is also 264KB
of SRAM, and 2MB of onboard Flash memory which can provide more programs to save and run. Apart from that, this little board has
good performance in processing but needs less power. There are 14 GPIO PINs on Seeed Studio XIAO RP2040, which include 11
digital pins, 4 analog pins, 11 PWM Pins,1 I2C interface, 1 UART interface, 1 SPI interface, 1 SWD Bonding pad interface.

                          Item                                                                      Value
                          CPU                                              Dual-core ARM Cortex M0+ processor up to 133MHz
                   Flash Memory                                                                       2MB
                         SRAM                                                                       264KB
                   Digital I/O Pins                                                                    11
                  Analog I/O Pins                                                                      4
                      PWM Pins                                                                         11
                     I2C interface                                                                     1
                    SPI interface                                                                      1
                   UART interface                                                                      1
 Power supply and downloading interface                                                             Type-C
                         Power                                                                    3.3V/5V DC
                     Dimensions                                                                20×17.5×3.5mm
            Programming Language                                                     Arduino/Circuitpython/Micropython

                                              Table 2: Present Key Specification of XIAO RP2040

                                                                         5 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 7

```text
Seeed Studio XIAO nRF52840 / Sense

     Seeed Studio XIAO nRF52840 is equipped with a powerful Nordic nRF52840 MCU which integrates Bluetooth 5.0
connectivity. Meanwhile, it has a small and exquisite form-factor that can be used for wearable devices and Internet of Things
projects. The single-sided surface-mountable design and the onboard Bluetooth antenna can greatly facilitate the rapid
deployment of IoT projects.
     In addition, there is an advanced version of this board, Seeed Studio XIAO nRF52840 Sense. It is integrated with two extra
onboard sensors. One of them is a Pulse Density Modulation (PDM) Digital Microphone. It can receive audio data in real time
which allows it to be used for audio recognition. The other one is a 6-axis Inertial Measurement Unit (IMU), this IMU can be very
useful in TinyML projects like gesture recognition. These onboard sensors provide great convenience for users while the board                        is
ultra-small.
     Compared to Seeed Studio XIAO RP2040, Seeed Studio XIAO nRF52840 contains richer interfaces. The first thing to note is
that the Near Field Communication (NFC) interface is functional on the board. Secondly, there is a tiny reset button on the side of
the Type-C interface. On the other side, there is a 3-in-one LED (User LED) along with a Charge LED to indicate the charging status
when a battery is connected. There are 11 digital I/O that can be used as PWM pins and 6 analog I/O that can be used as ADC
pins. It supports all three common serial interfaces such as          UART, I2C, and SPI. Same as Seeed Studio XIAO RP2040, it has an
onboard 2 MB flash which means it can also be programmed using Arduino, MicroPython, CircuitPython, or other programming
languages.

                        (Notice: 6 Dof IMU and PDM Microphone are only available on XIAO nRF52840 SENSE)
              Item                    Seeed Seeed Studio XIAO nRF52840                           Seeed Seeed Studio XIAO nRF52840
                                                                                                                        Sense
          Processor                               nRF52840 M4F@64MHz                                         nRF52840 M4F@64MHz

 Wireless Connectivity                             Bluetooth 5.0/BLE/NFC                                      Bluetooth 5.0/BLE/NFC

            Memory                    256 KB RAM, 1MB Flash 2MB onboard Flash                    256 KB RAM, 1MB Flash 2MB onboard Flash

      Built-in Sensors                                         N/A                              6 DOF IMU (LSM6DS3TR-C), PDM Microphone

          Interfaces                                     I2C/UART/SPI                                               I2C/UART/SPI

                                                                            6 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 8

```text
               Item                    Seeed Seeed Studio XIAO nRF52840                           Seeed Seeed Studio XIAO nRF52840
                                                                                                                         Sense
    PWM/Analog Pins                                            11/6                                                        11/6

     Onboard Buttons                                      Reset Button                                                Reset Button

       Onboard LEDs                               3-in-one LED/ Charge LED                                   3-in-one LED/ Charge LED

   Battery Charge Chip                                      BQ25101                                                     BQ25101
        Programming                         Arduino/ MicroPython/ CircuitPython                         Arduino/ MicroPython/ CircuitPython
          Languages

                                            Table 3: Present Key Specification of XIAO nRF52840/Sense

Seeed Studio XIAO ESP32C3

     Seeed Studio XIAO ESP32C3 is an IoT mini development board based on the Espressif ESP32-C3 WiFi/Bluetooth dual-
mode chip. ESP32-C3 is a 32-bit RISC-V CPU, which includes an FPU (Floating Point Unit) for 32-bit single-precision arithmetic
with powerful computing      power. It has excellent radio frequency performance, supporting              IEEE 802.11 b/g/n WiFi      , and Bluetooth 5
(LE) protocols. This board comes included with an external antenna to increase the signal strength for your wireless applications. It
also has a small and exquisite form factor combined with a single            -sided surface-mountable design. It is equipped with rich interfaces
and has 11 digital I/Os that can be used as          PWM pins and 4 analog I/Os that can be used as ADC pins. It supports four serial
interfaces such as    UART, I2C, SPI, and I2S       . There is also a small    reset button and a bootloader mode button               on the board.
     XIAO ESP32C3 is fully compatible with the           Grove Shield for Seeeduino XIAO          except for the Seeeduino XIAO Expansion board             ,
the SWD spring contacts on the board will not be compatible. With regard to the features highlighted above, XIAO ESP32C3 is
positioned as a high-performance, low-power, cost-effective IoT mini development board, suitable for low-power IoT applications and
wireless wearable applications.

                                                                             7 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 9

```text
                Item                                                 Seeed Seeed Studio ESP32C3
            Processor                                                 ESP32-C3 32-bit RISC-V @160MHz
     Wireless Connectivity                                                  WiFi and Bluetooth 5 (LE)
              Memory                                                   400KB SRAM, 4MB onboard Flash
        Built-in Sensors                                                               N/A
             Interfaces                                                        I2C/UART/SPI/I2S
       PWM/Analog Pins                                                                 11/4
        Onboard Buttons                                                      Reset and Boot Button
         Onboard LEDs                                                              Charge LED
      Battery Charge Chip                                                            Built-in
  Programming Languages                                                              Arduino

                                          Table 4: Present Key Specification of XIAO ESP32C3

1.3. XIAO Series Comparison Table

                        Seeed Studio           Seeed Studio            Seeed Studio            Seeed Studio           Seeed Studio
                       XIAO SAMD21             XIAO RP2040           XIAO nRF52840           XIAO nRF52840           XIAO ESP32C3
                                                                                                   Sense

                                                               Hardware

   Processor               SAMD21                   RP2040                nRF52840                nRF52840                ESP32C3

       RAM               32 KB SRAM             264 KB SRAM              256 KB RAM              256 KB RAM             400 KB SRAM

   Flash(chip)               256KB                     ×                     1MB                     1MB                     4MB

 Flash(onboar                   ×                     2MB                    2MB                     2MB                       ×
         d)

     Built-in                   ×                      ×                       ×              IMU, Microphone                  ×
     Sensors

  PWM/Analog                 11/11                    11/4                   11/6                    11/6                    11/4
       Pins

 I2C/UART/SPI                   √                      √                       √                       √                       √

    Bluetooth                   ×                      ×                       √                       √                       √

       WiFi                     ×                      ×                       ×                       ×                       √

 Reset Button          √ (Contact Point)               √                       √                       √                       √

  Boot Button          √ (Contact Point)               √                       √                       √                       √

    User LED                    √                      √                       √                       √                       ×

                                                                    8 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 10

```text
                        Seeed Studio            Seeed Studio             Seeed Studio            Seeed Studio            Seeed Studio
                       XIAO SAMD21              XIAO RP2040            XIAO nRF52840           XIAO nRF52840            XIAO ESP32C3
                                                                                                      Sense

                                                                Hardware

     Battery                    ×                        ×                       √                       √                       √
  Charge LED

     Baterry                    ×                        ×                       √                       √                       √
    Charge IC

   Low power                    ×                        ×                     <5μA                    <5μA                    <44μA
      mode

                                                      Programming Languages

     Arduino                    √                        √                       √                       √                       √

 CircuitPython                  √                        √                       √                       √                       ×

  MicroPython                   ×                        √                       √                       √                       ×

                                                     Table 5: XIAO Series Comparison

1.4. Ordering Information

                        Name                                              SKU                                    Product Life
        Seeed Studio XIAO SAMD21                                       102010328                                    3 years+*
         Seeed Studio XIAO RP2040                                      102010428                                    3 years+*
        Seeed Studio XIAO nRF52840                                     102010448                                    3 years+*
   Seeed Studio XIAO nRF52840 Sense                                    102010469                                    3 years+*
        Seeed Studio XIAO ESP32C3                                      113991054                                    3 years+*

Note*: Count from the release date of this User Manual.
    Currently, our minimum order quantity (MOQ) is set at 500 pieces. However, we may adjust this requirement in the futur
e based on various factors and situations and update here.

                                                                      9 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 11

```text
2. Seeed Studio XIAO SAMD21

2.1 Functional Introduction

2.1.1 Chip Datasheet

     A low-power, high-performance Microchip's ARM® Cortex®-M0+ based flash microcontroller, the ATSAMD21G18 is ideal for a
wide range of home automation, consumer, metering, and industrial applications. It features:
     ● 256KB of flash and 32KB of SRAM
     ● Up to 48MHz operating frequency
     ● Six serial communication modules (SERCOM) configurable as UART/USART, SPI or I2C, three 16-bit timer/counters, 32-bit
Real-Time Clock and calendar, 20 PWM channels, one 14-channel 12-bit ADC, one 10-bit DAC
     ● Full Speed USB Device and embedded Host
     ● Support for up to 120 touch channels
     ● 1.62V to 3.63V power supply

                                                           Download Datasheet

2.1.2 Pinout Reference

2.1.3 Power Consumption

     Normal: 14.5mA

2.1.4 Operating Voltage

     Operating Voltage is 5 V (Type-C)

2.1.5 Hardware and Software Feature

Additional Functionality of XIAO SAMD21

     DAC (Digital to Analogue Converter): Support battery supply, but only one time, since the board doesn't have a battery charge
chip

Software Tutorials

     Seeed Studio XIAO SAMD21 as USB device (TinyUSB)
     SPI Communication on Seeed Studio XIAO SAMD21
     TinyML on Seeed Studio XIAO SAMD21
     Seeed Studio XIAO SAMD 21 DAPLink
     How to use Seeed Studio XIAO SAMD21 to log in to your Raspberry PI

                                                                         10 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 12

```text
     How to unbrick a dead xiao using raspberry pi
     There are two documentations on the usage of Seeed Studio XIAO SAMD21 which focus on different areas, check the table
below for reference:

                     Documentation by Seeed                                                        Documentation by Nanase

                              Pinout Diagram                                                                     Interface

            Seeed Studio XIAO SAMD21 Getting Started                                   Seeed Studio XIAO SAMD21 with MicroSD Card(SPI)

              Seeed Studio XIAO SAMD21 GPIO Usage                                          Seeed Studio XIAO SAMD21 with GPS(UART)

               Seeed Studio XIAO SAMD21 Resources                                                          Single Cycle IOBUS

    This is a document written by @nanase_coder. (Translated by Seeed from the original Japanese document: コインサイズ Arduino                   互換機 Seeed
Studio XIAO SAMD21 を使ってみた).

2.1.6 Bootloader

     ●  Standard Bootloader for common PC port identification.
     ●  UF2 Bootloader for CircuitPython        usage of PC port identification.

Enter Bootloader Method: wire shoring RST connectors

     Sometimes the Seeed Studio XIAO SAMD21 port may disappear when the user programming process fails. we can solve this
problem by the following operation:
     ●  Connect the Seeed Studio XIAO SAMD21 to your computer.
     ●  Use tweezers or short lines to short the RST pins in the diagram twice.
     ●  The orange LED lights flicker on and light up.
     At this point, the chip enters Bootloader mode and the burning port appears again.                Because the samd21 chip has two partitions,
one is the Bootloader and the other is the user program. The product will burn a bootloader code in the system memory when it
leaves the factory. We can switch modes by performing the above steps.

2.1.7 Programming Languages

     XIAO SAMD21 supports Arduino, CircuitPython, and MicroPython. Detailed tutorials are provided for each programming
language.
     Arduino on Seeed Studio XIAO SAMD21
     CircuitPython on Seeed Studio XIAO SAMD21
     MicroPython on Seeed Studio XIAO SAMD21

                                                                            11 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 13

```text
2.2 File Resources

2.2.1 PCBA

2.2.1.1 Footprint

     [LBR] Seeed Studio XIAO SAMD21 Footprint Eagle

2.2.1.2 Schematic

     [PDF] Seeed Studio XIAO SAMD21 Schematic

2.2.1.3 KiCAD Libraries

     [ZIP] Seeed Studio XIAO SAMD21 KiCAD Libraries

2.2.1.4 Eagle Libraries

     [ZIP] Seeed Studio XIAO SAMD21 Eagle Libraries

2.2.1.5 Dimension in DXF

     [DXF] Seeed Studio XIAO SAMD21 Dimension in DXF

2.2.1.6 Factory Firmware

     [ZIP] Seeed Studio XIAO SAMD21 Factory firmware

2.2.1.7 Pinout Sheet

     [XLSX] Seeed Studio XIAO SAMD21 pinout sheet

2.2.2 Structure

     2.2.2.1 STL File

     [ZIP] Seeed Studio XIAO SAMD21 STL File

     2.2.3 Certification

     This file includes CE, EU DoC, FCC, RoHS, and UK DoC.
     [ZIP] Seeed Studio XIAO SAMD21 Certification

     For Custom Clearance, you may need:

                                  HSCODE                                                                        8543709990

                                USHSCODE                                                                        8543709301

                                EUHSCODE                                                                        8543709099

                                    COO                                                                            CHINA

                                                                             12 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 14

```text
                                                                                              13 / 34

·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 15

```text
3. Seeed Studio XIAO RP2040

3.1 Functional Introduction

3.1.1 Chip Datasheet

     RP2040 is the debut microcontroller from Raspberry Pi. It brings signature values of high performance, low cost, and ease of use
to the microcontroller space. With a large on-chip memory, symmetric dual-core processor complex, deterministic bus fabric, and rich
peripheral set augmented with our unique Programmable I/O (PIO) subsystem, it provides professional users with unrivalled power
and flexibility. With detailed documentation, a polished USB-C port, and a UF2 bootloader in ROM, it has the lowest possible barrier
to entry for beginner and hobbyist users.

                                                              Download Datasheet

3.1.2 Pinout Reference

3.1.3 Power Consumption

     Normal: 28.9 mA

3.1.4 Operating Voltage and Supply Voltage

      Operating Voltage is 5V (Type C)

3.1.5 Hardware and Software Feature

     If you want to reset the Seeed Studio XIAO RP2040, perform the following steps:
     ●  Connect the Seeed Studio XIAO RP2040 to your computer.
     ●  Press the "R" pins once.
     Please note: The behavior of the built-in programmable Single-colour LEDs (two are blue, one is green) is reversed to the one
on an Arduino. On the Seeed Studio XIAO RP2040, the pin has to be pulled low to enable it.

                                                                            14 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 16

```text
Software Resources

     TinyML on SEEED XIAO RP2040 (Motion Recognition)

3.1.6 Bootloader

     ●  Standard Bootloader for common PC port identification
     ●  UF2 Bootloader for CircuitPython usage of PC port identification

     Enter Bootloader Method: Hold "B" button then connect to PC.
     Sometimes the Seeed Studio XIAO RP2040 port may disappear when user is programming process fails. we can solve this
problem by the following operation:
     ●  Long press the "B" button.
     ●  Connect the Seeed Studio XIAO PR2040 to your computer.
     ●  The computer will appear a disk driver.
     At this point, the chip enters Bootloader mode and the burn port appears again. Because the RP2040 chip has two partitions, one
is the Bootloader and the other is the user program. The product will burn a bootloader code in the system memory when it leaves the
factory. We can switch modes by performing the above steps.

3.1.7 Programming Languages

     Seeed Studio XIAO RP2040 has supported Arduino, MicroPython, and CircuitPython programming, and we provide examples for
each programming language. You can choose to select from the contents on the left side of the page, or click the hyperlink below:
     ●  Seeed Studio XIAO RP2040 with Arduino
     ●  Seeed Studio XIAO RP2040 with MicroPython
     ●  Seeed Studio XIAO RP2040 with CircuitPython

3.2 File Resources

3.2.1 PCBA

3.2.1.1 Footprint

     [LBR] Seeed Studio XIAO RP2040 Footprint Eagle

3.2.1.2 Schematic

     [PDF] Seeed Studio XIAO RP2040 Schematic

3.2.1.3 KiCAD Libraries

     [ZIP] Seeed Studio XIAO RP2040 KiCAD Libraries

3.2.1.4 Eagle Libraries

     [ZIP] Seeed Studio XIAO RP2040 Eagle Libraries

3.2.1.5 Dimension in DXF

     [DXF] Seeed Studio XIAO RP2040 Dimension in DXF

3.2.1.6 Pinout Sheet

     [XLSX] Seeed Studio XIAO RP2040 pinout sheet

3.2.2 Structure

3.2.2.1 STL File

     [ZIP] Seeed Studio XIAO RP2040 STL File

                                                                             15 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 17

```text
3.2.3 Certification

     This file includes CE, EU DoC, FCC, RoHS, and UK DoC.
     [ZIP] Seeed Studio XIAO RP2040 Certification

     For Custom Clearance, you can refer to:

                                    HSCODE                                                                             8543709990

                                  USHSCODE                                                                             8543709301

                                  EUHSCODE                                                                             8543709099

                                       COO                                                                                 CHINA

                                                                                  16 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 18

```text
                                                                                             17 / 34

·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 19

```text
4. Seeed Studio XIAO nRF52840 / Sense

4.1 Functional Introduction

4.1.1 Chip Datasheet

     The nRF52840 SoC is the most advanced member of the nRF52 Series. It meets the challenges of sophisticated applications
that need protocol concurrency and a rich and varied set of peripherals and features.  It offers generous memory availability for both
Flash and RAM, which are prerequisites for such demanding applications.

                                                           Download Datasheet

4.1.2 Pinout Reference

4.1.3 Power Consumption

     XIAO nRF52840: Low power model: <5uA;  Normal: 10.38mA
     XIAO nRF52840 Sense: Low power model: <5uA; Normal: 10.38mA

Power Consumption Verification

     The Seeed Studio XIAO nRF52840 is low power consumption and here we provide a method to verify. It is highly recommended
to use the Seeed nRF52 Boards library here. A step-by-Step tutorial is provided in our wiki.

4.1.4 Operating Voltage

     XIAO nRF52840: Type C: 5V; Battery: 3.7V Li-ion
     XIAO nRF52840 Sense: Type C: 5V; Battery: 3.7V Li-ion

4.1.5 Charging Current

     XIAO nRF52840: 50mA ± 5mA
     XIAO nRF52840 Sense: 50mA ± 5mA

4.1.6 Hardware and Software Feature

Hardware Additional Functionality

     ● NFC (Near Field Communication) Function (Antenna Required)
     ● 6-Axis IMU (for XIAO nRF52840 Sense)
     ● PDM Microphone (for XIAO nRF52840 Sense)

                                                                         18 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 20

```text
Software Features

     ● Access the SWD Pins for Debugging and Reflashing Bootloader
     ● NFC Usage on Seeed Studio XIAO nRF52840 (Sense)
     ● The 6-Axis IMU Usage on Seeed Studio XIAO nRF52840 Sense
     ● The PDM Microphone Usage on Seeed Studio XIAO nRF52840 Sense
     ● Pin Multiplexing on Seeed Studio XIAO nRF52840 (Sense)
     ● Bluetooth Usage (Seeed nRF52 Boards Library): Seeed Studio XIAO nRF52840 and Seeed Studio XIAO nRF52840 Sense
both support Bluetooth connectivity.
             a. For Seeed nRF52 Boards Library
             b. For Seeed nRF52 mbed-enabled Boards Boards

4.1.7 Bootloader

     ● Standard Bootloader for common PC port identification
     ● UF2 Bootloader for CircuitPython usage of PC port identification

4.1.8 Programming Languages

     XIAO nRF52840/Sense support Arduino, CircuitPython, and MicroPython.
     ● Seeed Studio XIAO nRF52840/Sense with CircuitPython
     ● Getting Started with Seeed Studio XIAO nRF52840/Sense on Arduino IDE
     ● Seeed Studio XIAO nRF52840/Sense with MicroPython
     Note: it is not an official MicroPython support, we will update an official wiki in the future.

Two Arduino Libraries

     Seeed Studio XIAO nRF52840 assembles many functions in one tiny board and sometimes may not perform the best of them.
Hence, Seeed has published two Arduino libraries to let it maximize the power of each function. Therefore:
     ● It is recommended to use the Seeed nRF52 Boards library if you want to apply the Bluetooth function and "Low Energy Cost
Function".
     ● It is recommended to use the Seeed nRF52 mbed-enabled Boards library if you want to use it in embedded Machine Learning
Applications or apply "IMU & PDM advanced function".
     ● Both libraries support very well when comes to basic usages, such as LED, Digital, Analog, Serial, I2C, and SPI.

4.2 File Resources

4.2.1 PCBA

4.2.1.1 Footprint

     [LBR] Seeed Studio XIAO nRF52840 Eagle footprint
     [LBR] Seeed Studio XIAO nRF52840 Sense Eagle footprint

4.2.1.2 Schematic

     [PDF] Seeed Studio XIAO nRF52840 Schematic
     [PDF] Seeed Studio XIAO nRF52840 Sense Schematic

4.2.1.3 Dimension in DXF

     [DXF] Seeed Studio XIAO nRF52840 Dimension in DXF
     [DXF] Seeed Studio XIAO nRF52840 Sense Dimension in DXF

4.2.1.4 Pinout Sheet

     [XLSX] Seeed Studio XIAO nRF52840 pinout sheet
     [XLSX] Seeed Studio XIAO nRF52840 Sense pinout sheet

                                                                           19 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 21

```text
4.2.2 Certification

     [ZIP] Seeed Studio XIAO nRF52840 Certification files
     [ZIP] Seeed Studio XIAO nRF52840 Sense Certification files
     This file includes CE, EU DoC, FCC, RoHS, TELEC, and UK DoC.

     For Custom Clearance, you may need:

                                    HSCODE                                                                            8543709990

                                  USHSCODE                                                                            8543709301

                                  EUHSCODE                                                                            8543709099

                                      COO                                                                                CHINA

                                                                                 20 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 22

```text
                                                                                             21 / 34

·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 23

```text
5. Seeed Studio XIAO ESP32C3

5.1 Functional Introduction

5.1.1 Chip Datasheet

     ESP32-C3 is a single-core Wi-Fi and Bluetooth 5 (LE) microcontroller SoC, based on the open-source RISC-V architecture. It
strikes the right balance of power, I/O capabilities, and security, thus offering the optimal cost-effective solution for connected devices.
The availability of Wi-Fi and Bluetooth 5 (LE) connectivity not only makes the device's configuration easy, but also facilitates a variety
of use cases based on dual connectivity.

                                                              Download Datasheet

5.1.2 Pinout Reference

5.1.3 Power Consumption

     Low power model: <44uA

     Normal: 25.7mA

5.1.4 Operating Voltage

     Type C: 5V
     Battery: 3.7V Li-ion

                                                                            22 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 24

```text
5.1.5 Charging Current

     380mA±30mA

5.1.6 Hardware and Software Feature

Hardware

     Battery Charge Chip: ETA4054. The XIAO ESP32C3 is capable of using a 3.7V lithium battery as the power supply input. You
can refer to the following diagram for the wiring method.

     Attention: Please be careful not to short-circuit the positive and negative terminals and burn the battery and equipment when
soldering.
     Instructions on the use of batteries:
     1. Please use qualified batteries that meet the specifications.
     2. XIAO can be connected to your computer device via a data cable while using the battery, rest assured that XIAO has a built-in
circuit protection chip, which is safe.
     3. The XIAO ESP32C3 will not have any LED on when it is battery-powered (unless you have written a specific program), please
do not judge whether the XIAO ESP32C3 is working or not by the condition of the LED, please judge it reasonably by your program.

Software Tutorial

     ●  WiFi Usage on Seeed Studio XIAO ESP32C3
     ●  Bluetooth Usage on Seeed Studio XIAO ESP32C3
     ●  Pin Multiplexing on Seeed Studio XIAO ESP32C3

5.1.7 Bootloader

     ●  Standard Bootloader for common PC port identification
     ●  Enter Bootloader Method: Hold "BOOT" Buttion then connect to PC

     You can simply connect the board to a PC via USB Type-C and reflash the bootloader with factory firmware by using ESP RF
Test Tool. Step by step wiki is provided to guide you           to reflash the bootloader with factory firmware.

5.1.8 Programming Languages

     ●  Getting Started with Seeed Studio XIAO ESP32C3

                                                                              23 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 25

```text
5.2 File Resources

5.2.1 PCBA

5.2.1.1 Footprint

     [LBR] Seeed Studio XIAO ESP32C3 Eagle footprint

5.2.1.2 Schematic

     [PDF] Seeed Studio XIAO ESP32C3 Schematic

5.2.1.3 KiCAD Libraries

     [ZIP] Seeed Studio XIAO ESP32C3 KiCAD Libraries

5.2.1.4 Eagle Libraries

     [ZIP] Seeed Studio XIAO ESP32C3 Eagle Libraries

5.2.1.5 Dimension in DXF

     [DXF] Seeed Studio XIAO ESP32C3 Dimension in DXF

5.2.1.6 Factory Firmware

     [ZIP] Seeed Studio XIAO ESP32C3 Factory firmware

5.2.1.7 Pinout Sheet

     [XLSX] Seeed Studio XIAO ESP32C3 pinout sheet

5.2.2 Structure

5.2.2.1 STL File

     [ZIP] Seeed Studio XIAO ESP32C3 STL File

5.2.2.2 3D File

     [STEP] Seeed Studio XIAO ESP32C3 3D Model

5.2.3 Certification

     [ZIP] Seeed Studio XIAO ESP32C3 Certification files
     This file includes CE, EU DoC, FCC,  REACH, TELEC RoHS, and UK DoC.

     For Custom Clearance, you can refer to:

                                 HSCODE                                                                       8543709990

                               USHSCODE                                                                       8543709301

                               EUHSCODE                                                                       8543709099

                                    COO                                                                          CHINA

                                                                            24 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 26

```text
                                                                                              25 / 34

·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 27

```text
6. Notification

XIAO SAMD21 and XIAO RP2040

                                                                     Fig. XIAO SAMD21

                                                                      Fig. XIAO RP2040

     Caution: For general I/O pins, the working voltage of MCU is 3.3V. Voltage input connected to general I/O pins may cause chip
damage if it's higher than 3.3V.  For power supply pins, the built-in DC-DC converter circuit able to change 5V voltage into 3.3V
allows the power of the device with a 5V supply via VIN-PIN and 5V-PIN.
     Interrupt
     All pins on Seeed Studio XIAO SAMD21 support interrupts, but two pins cannot be used at the same time: 5 pin and 7 pins. For
more detail about Interrupt please check here.
     Pin Multuiplexing
     We don't need to configure the pins ourselves, after using the pins, you can call a function directly. Detailed codes are provided
within wiki page.

XIAO nRF52840/Sense

Q1: My Arduino IDE is stuck when uploading code to the board

     You can first try to reset the board by clicking the "Reset Button" once. If that does not work, rapidly click it twice to enter
bootloader mode. If that also doesn't work, disconnect the board from the PC, and connect the board again.

Q2: My board is not showing up as a serial device on Arduino IDE

     You can first try to reset the board by clicking the "Reset Button" once. If that does not work, rapidly click it twice to enter
bootloader mode.
     The XIAO ESP32C3 does not support USB HID as the ESP32C3 does not support USB HID. But BLE HID is supported.

                                                                              26 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 28

```text
                                                                                              27 / 34

·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 29

```text
7. PCBA Service

     Committed to providing one-stop electronic hardware services for over a decade, Seeed Fusion has the expertise and
engineering insight to deliver streamlined PCB assembly at low costs and is equipped with a wide range of value-added services and
capabilities.

7.1 Turnkey PCB Assembly - Complete PCBA Quotation in Seconds

     ● One-stop PCB Manufacture, Parts Procurement, and Assembly
     ● Quality Guaranteed: Free DFA review and free functional testing for one piece
     ● Pre-Purchase Components and store them in Seeed's facilities until required
     ● Open Parts Library (OPL) - Locally available parts for faster and cheaper PCBA
     ● Mature supply chain management and global sourcing capabilities
     ● Over 10 SMT assembly lines and 12 years in-house expertise
     ● Free express shipping worldwide

Seeed Fusion Turnkey PCB Assembly Service Prototype to Mass Production

     PCB Fabrication, components procurement and assembly, all-in-one from one simple platform.

                                                       Get a smart quote online now

   Case Study: Gas/Smoke Detector, Alarm system with real-time leakage monitoring using Seeed Studio’s XIAO RP2040.

7.2 OEM / ODM / and other design Services

     ● Rich R&D resources and product-to-market experience
     ● Proven expertise with custom Raspberry Pi, NVIDIA, STM               -based designs, and more
     ● Integrated agile manufacturing and supply ch         ain for fast product launches
     ● Over 1000+ successful product launches

What is the Seeed OEM Service?

     Seeed provides complete Original Equipment Manufacturing services for a wide variety of electronic hardware, lifting your des                       ign
from paper to production.     Offering the entire package from PCB manufacture, parts procurement, turn                -key assembly, mechanical
parts manufacture, packaging services, and quality inspections down to shipping provisions, complete with dedicated account
managers and expert engineers, Se         eed can help you realize your ideas economically and efficiently.

                                                                            28 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 30

```text
What are the benefits of Seeed OEM service?

     ●  In-House Supply Chain Team
     ●  Reliable Production Line
     ●  Strict Quality Control System
     ●  Product Tracing System
     ●  Reliability Testing

                                Co-create with Seeed Fusion OEM to Realize Your Great Project Ideas Now!

* Seeed OEM has a well-developed production process, testing, and delivery process.

7.3 Seeed Licensed Products Program

What is Licensed Products Program

     Seeed licensing means that the licensor (cooperative partner) grants its own products (software or hardware), trademarks,
brands, etc. to the licensee (Seeed) in the form of a contract. Seeed will assist with all electronics manufacturing includin                      g structural
parts, testing, and certification, provide engineering and quality assurance services, and promotion, sales, and distribution                         around the
world using Seeed’s own network and channels. Seeed will ensure that your product is well looked after from start to fin                          ish.

                                                    Co-invent with Seeed to launch your creation

                                                                               29 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 31

```text
Success Stories with Seeed Licensed Products Program

     Seeed assists with all electronics manufacturing including structural parts, testing, and certification, provides engineering and
quality assurance services, and promotion, sales, and distribution around the world using Seeed’s own network and channels to help
these three keyboards go to market.

7.4 Seeed Studio XIAO Series Co-invent Campaign

7.4.1 POWER-UP PCBA #19: Speed up TinyML development with Seeed XIAO RP2040 and FREE
Prototypes with Seeed Fusion

     XIAO RP2040 opens up more powerful XIAO applications with direct support for MicroPython and CircuitPython. To support and
inspire more XIAO RP2040 projects, Seeed Fusion is offering 2 free PCBA prototypes with the Seeed Fusion PCBA service. Don’t let
this amazing opportunity pass you by.

How to apply

     Each person is limited to two PCBA boards 100% FREE for one design. The custom design must include Seeed XIAO RP2040.
     Please click the link and fill in the form: https://forms.gle/8dmLqtdXCiPvZ8Av9. Please be noted that when you are preparing the
BOM file, just add the Seeed SKU 102010428 or the part number Seeed XIAO RP2040 to your BOM file. Add the order to the cart
then contact our customer support (fusion@seeed.io) to obtain the corresponding cash coupon for settlemen                     t.
     Case Study 1 – DIY 6-keys Macropad using Seeed XIAO RP2040 & Fusion PCBA
     Case Study 2 – 8-keys KEM Keyboard Extender Maker project using Seeeduino XIAO & PCBA
     Case Study 3 – 8-Keys Keyboard for Handwiring ‘Le Pinceau’ using Seeed XIAO BLE-nRF52840 & Fusion PCBA
     Case Study 4 – Seeed Studio XIAO RP2040 18 Key Numpad

                                                                           30 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 32

```text
     Case Study 5 – Cistercian keyboard
     Case Study 6 – Slice36 Minimalist Split Keyboard
     Case Study 7 – First Hummingbird of the season
     Case Study 8 – Custom-programmable, mini keyboards with Seeed XIAO RP2040
     (Know more Case details here)

7.4.2 POWER-UP PCBA #18: Open up new IoT possibilities with Seeed XIAO BLE for TinyML and Seeed
Fusion PCBA service

     In order to stimulate enthusiasm and help commercial customers land more productive and valuable landing projects.  Seeed is
sponsoring Seeed XIAO BLE -nRF52840 designs with the Seeed Fusion PCBA service. Get one piece of your Prototype Seeed XIAO
BLE design manufactured for free with Seeed Fusion PCBA Service.

How to apply

     All you need to do is fill in the form and complete your Seeed XIAO BLE design and each person is limited to two PCBA boards
100% FREE for one design. The custom design must include Seeed XIAO BLE -nRF52840 .
     Please click the link and fill in the form: https://forms.gle/qKQhz7te5JDPPkdD8.
     When preparing the BOM file, just add the Seeed SKU 102010448 or the part number Seeed XIAO BLE nRF52840 to your BOM
file. Add the order to the cart then contact our customer support (fusion@seeed.io) to obtain the corresponding cash coupon for
settlement.

                                                                             31 / 34

    ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 33

```text
8. Application

     As introduced in the foreword, XIAO has been chosen and applied to many project prototypes, some of which have demonstrated
its tremendous potential for addressing practical challenges. These projects have fallen under 5 main categories which has proven a
huge success. If you are considering commercial prototypes related to these areas, the XIAO project collection can offer you a great
deal of confidence and reassurance in your endeavors.
     1. DIY XIAO Mechanical Keyboard
     2. Unleash XIAO's Musical Potential: A Budget-Friendly Eurorack Solution, MIDI Keyboard Integration, and More!
     3. Unleash the Power of Tracking with XIAO: The Unmissable Solution for Accurate, Reliable, and Affordable Tracking
     4. XIAO in Healthcare: Solutions for Sun Damage, FoG Issues, Heartbeat Monitoring, and Blood Oxygen & Heart Rate
Measurement
     5. XIAO-Powered Detection Tools: Anomaly Detection & Motion Classification for Containers in Transit, AI-driven Yogurt
Production, and Gas Leak Detection Robot

                                                                               32 / 34

     ·PCBA Service Email: fusion@seeed.io         ·Technical Support Email: techsupport@seeed.io            ·Business Enquiry Email: distribution@seeed.cc
```

## Page 34

```text

```
