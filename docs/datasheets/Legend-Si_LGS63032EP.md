# Legend-Si LGS6303x (LGS63032EP) constant-current boost driver (U2)

- Source PDF: <https://www.lcsc.com/datasheet/C5370937.pdf>
- Pages: 20
- Converted: 2026-11-19 by automatic text extraction (pypdf). Tables, figures and pin diagrams may be garbled or missing; check the original PDF for anything critical (pinouts, footprints, absolute maximum ratings).

## Page 1

```text
                                                                                               LGS6303X

                                                                                                             Rev.C V1.  2

                                       60V    /2A  升压型             LED 恒流驱动器

                                            Check for Samples: LGS 6303X
特性                                                            描述

■          宽输入/输出电压范围：3.0V                            -60V     LGS6303X 是一种集成功率             开关的升压型            DC-DC LED
■          支持 PWM 调光及模拟调光                                     驱动芯片，                 具有 3V 到 60V      的宽输入电压范围，                               集成了
■          内置 350mΩ低侧金属氧化物半导体场效应晶体管                           软起动，从而最大限度地减少对外部浪涌抑制组件的需
■          最高         94%  升压效率                               求，使其成为宽输入电源范围         LED  驱动的理想选择。
■          逐周期峰值限流保护                                          输出电流可以通过外部电阻调整。                    LGS6303X 具有集成
■        SKIP 模式提供极高的轻负载效率                                    式 350mΩ功率开关，可提供                   2A 的输入峰值电流能力，
■          提供超小的封装  SOT23-6  封装以及增强散热的                        具有出色的负载和线路瞬态响应。具备 SKIP 控制模式，
     ESOP8 封装。                                                将低静态电流与高开关频率相结合，可在广泛的负载电
■          内置软启动电路，防止电流过冲                                     流范围内实现高效率。
■          热关断保护                                              附加功能包括：软启动，       可调节输出过压保护，                             热关机，
■          输入欠压保护                                             UVLO 欠压锁定，逐周期峰值限流保护。
■          可调节输出过压保护                                          LGS6303X 可通过选取不同阻值的采样电阻     RSET  实现
■          内部环路补偿有助于减小解决方案尺寸、降低成本                             对输出电流高精度的数字和模拟调节，                 包括两种具体型
     和设计复杂性                                                   号 LGS63030 和 LGS63032：
■          所有端口都具备±2000V(HBM)ESD                                     保护■        LGS63030           支持模拟输                  入(    0.6V~1.2V  )的 DC 调光。
■          结温范围为-                  40℃     至+1    25℃         ■        LGS63032             支持数字输 入 (100HZ~100KHZ      ) 的
                                                                   PWM 调光，         高频 PWM 输入下无屏闪。调光比在
应用                                                                 PWM  频率为 100HZ  时高达 25000        :1。调光深度

■          升压型车灯                                                   可达 0.1%.
■          智能调光 LED 灯                                         LGS6303X 可以提供小尺寸 6 引脚 SOT23-6 封装以及
■        MR16 LED 射灯                                          增强散热 8 引脚 ESOP8 封装。

                      4.7uH
                                                              采购信息

   V IN         6              1     SS26
   3V~60V         V IN     SW                                 LGS6303       (    )     封装信息
     4.7uF/100V    LGS6303X           300K      10uF                                   B6:SOT23-6
                               5                                                       EP:ESOP8
                           OVP                                                 调光版本0:模拟调光
                                              6.2K
                4              3                                               2:数字调光
                  EN        FB
 DC/P WM              GND                        LED灯串
                         2     RS ENSE                              编号             封装         顶部标识          说明

                                                               LGS63030B6       SOT23-6        63030        YX：
                                                               LGS63030EP        ESOP8         63030       出厂信
注：E       N 不可悬空，E                 N  为低压引脚，不使用调光需从 VIN 分压，需要                                    YX
EN 大于 1.2V 小于 6V.  OVP 引脚高于 1V 判定过压保护。FB 为 0.2V。                                                             息
                                                               LGS63032B6       SOT23-6        63032
             SOT23-6 封装典型应用拓扑                                  LGS63032EP        ESOP8         63032
                                                                                                 YX

产品数据信息截止到手册发布日期。参数规格以最新版本信息为准。如有更改恕不另行通知。                                                                       www.Legend-Si.com
LGS6303X                                                                            棱晶半导体（南京）有限公司  1
```

## Page 2

```text
        Legend-si                                                                            LGS6303X
        www.Legend  -si.com                                                                           Rev.C V1  .2
绝对最大值（†）                        引脚排列

表 3.1
 参数                                                                      范围 SW  1             6   VIN    FB   1              8     EN
 引脚至 GND 电压（V    IN,SW）            -0.3V~60V                                                            GND   2              7    OVP
 引脚至 GND 电压（FB,EN,OVP）    -0.3V~6V                                       GND    2             5   OVP               GND
                                                                                                         SW   3              6     NC
 开关管最大电流                               2A                                 FB    3             4   EN
                                                                                                         SW                                           VIN45
 储存温度                                          -65℃         to 150℃
 工作温度                                          -40℃         to 12  5℃              SOT23-  6                     ESOP8
 ESD 额定值（H              BM）                          ±2KV                                    图 3.1 封装与引脚排列
 ESD 额定值（C              DM）                      ±500V

                                                                        根据功率选择：5~10W                       选   SOT23-6        封装
†  注：          如果器件工作条件超过上述“绝对最大值”，可能引起器件永
久性损坏。这仅是极限参数，不建议器件在极限值或超过上述极限值的                                           10W                          以上选        ESOP8

条件下工作。器件长时间工作在极限条件下可能会影响其可靠性。
ESD     警告
                 ESD(静电放电）敏感器件。

                 带电器件和电路板可能会在没有察觉的情况下放电。尽管

                 本产品具有专利或专有保护电路，但在遇到高能量  ESD

                 时，器件可能会损坏。因此，应当采取适当的 ESD 防范

                 措施，以避免器件性能下降或功能丧失。

                         Top View

表 3.2  引脚功能描述

            引脚编号
    SOT23                    ESOP   引脚名称                                                                                                        说明

       1                    3,4                   SW            内部功率开关节点。外部连接功率电感、肖特基二极管。
       2                     2                 GND           接地引脚。

       3                     1                   FB             反馈输入引脚。连接至外部电阻器，输出恒流值可通过𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆设定，输出⁄                   。
                                                  电流由𝑉𝑉𝐹𝐹𝐹𝐹和𝑅𝑅   𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆决定，可由此公式进行设定：           𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂  = 𝑉𝑉𝐹𝐹𝐹𝐹 𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆 (𝐴𝐴)
       4                     8                   EN             调光输入引脚，                 可输入直流和 PWM方波来进行调光，详见“调光设置”。
                                                  不使用调光可直接分压
       5                     7                 OVP                 过压保护引脚，连接至输出脚和地的分压电阻。此引脚电压高于     1V，
       6                     5                  VIN            驱动器电源输入引脚，使用 4.7uF      或更大的陶瓷贴片尽量近旁路 VIN 和
                                                  GND。
       -                     6                   NC            不需要外接器件，请保证该引脚悬空。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       2
```

## Page 3

```text
           Legend-si                                                                            LGS6303X
           www.Legend  -si.com                                                                           Rev.C V1  .2
技术规格

除非有特殊说明，否则极限值适用于-           40℃至    +125℃的工作结温度（T          J）范围。最小和最大限值通过试验，验证和统计
相关性规定。典型值代表 TJ=25℃时最可能的参数规范，仅供参考。所有电压都是相对于 GND。

表 4
 参数                                                                        测试条件                                           最小值      典型值      最大值      单位
 输入特性
 VIN                   推荐输入电压范围                                                                          3.0                             60                              V
 VUVLO                 输入欠压锁定                             上升沿                   Rising                                                        3.0                        V
                                              下降沿                   Falling                                                       2.6                                    V
 lQ                    静态工作电流                                        No load，    No switch,VIN=12V    ,                                   180                            uA
                                                                           EN=2V,FB=1V.
 IS                    关机电流                                       EN=0,VIN=12V                                         10                                                uA
 开关特性
 RDS(ON)               BOOST 上管 RDSON                  TJ= 25℃                                       330                350                410                           mΩ
 VFB                   FB 反馈电压                                                                                   0.195             0.2           0.205                   V
 FSW                   开关频率                                      PWM Operation                            1.05             1.2           1.35                            MHZ
 FSW_FB                软起动下开关频率                                              VIN=12V，EN=1                                              1   4⁄ 𝐹𝐹𝑠𝑠𝑠𝑠                     MHZ
 DMAX                  最大占空比                                                                                     85                90                                    %
 lLIMIT.SW(Peak)       SW 电流限制                                                                                                1.5             1.7           2.1          A
 VFB                   FB 反馈电压                                                                                   0.195             0.2           0.205                   V
 IFB.BIAS              FB 偏置电流                                                                                                   50                                      nA
 ISW.LKG               SW 漏电流                                                                                                                                4           uA
 使能/调光(3               V≤VIN    ≤60V        )
 VEN_min               模拟调光下限电压                                              3V≤VIN    ≤60V                                  0.6             0.62           0.65         V
 VEN_max               模拟调光上限电压                                              3V≤VIN    ≤60V                              1.2             1.22           1.25             V
 VEN_H                 数字调光上升沿                           63032                EN=0          EN=1                      0.31             0.5             0.54              V
 VEN_L                 数字调光下降沿                           63032                EN=1          EN=0                      0.25             0.35             0.38             V
 t                     EN 最小识别脉冲时间                                                                                    400                                                nS
 IEN                   EN 输入电流                                               VEN=5V                                      5                              10               uA

 过压保护
 VOVP                  过压保护电压                         上升沿                                                                                   1                              V
                                                           下降沿                                                                                   0.86                             V
 全局热保护特性
 TOTP-R                过温保护                                       TJ Rising                                                      150                                 ℃
 TOTP-F                过温保护解除                               TJ Falling                                                     120                             ℃

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       3
```

## Page 4

```text
        Legend-si                                                                            LGS6303X
        www.Legend  -si.com                                                                           Rev.C V1  .2
功能框图

                                                              VIN

                                                                                     LGS6303X

  EN                      I/O           EN          Bandgap        Vref            OSC          CLK
                                                      OTP

                                                                                                                         SW

               Vref      EA
   FB

                                                                                   R/S

                                                                    CLK

 OVP                OVP

                                                                     Slop
                                                                Compensation

                                                             GND

                                                       图 6  内部功能框图

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       4
```

## Page 5

```text
          Legend-si                                                                            LGS6303X
          www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：典型应用电路

                                                       4.7uH

       V IN                                                                                     SS26
                                        6   V IN                    SW       1
       3V   ~60   V
             4.7uF/100V                       LGS6303X                                       300   K                  10uF
                                                                 OVP         5
                                                                                                                 6.2K

                                         4   EN                     FB       3
   DC/P WM                                             GND                                                                LED灯串
                                                              2             RS ENSE

                                                        图 7    DC-     DC 升压模式典型应用拓扑

NOTE：

■      反馈输入引脚。连接至外部电阻器，输出横流值可通过𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆设定，输出电流由 VFB 和𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆决定，可由此公式进行设
      定：𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂  = 0.2 𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆 (𝐴𝐴)⁄                   。

■          输入电容推荐使用 4.7uF 的 X7R 或 X5R 的陶瓷电容，并尽量贴近电源输入引脚和    GND 引脚放置。
参考物料清单

              器件                                                       型号                                                                                     备注                                                                    说明
       输入电容                                   4.7u  f                                 必备陶瓷电容，耐压大于输入电压两倍                                                                                       选用器件后请实
       输出电容                                  10u    F                               必备陶瓷电容，耐压大于输出电压两倍                                                                            际测试。

    电流设置电阻                                                                         需考虑功率计算，                               选用功率         要求够的电阻
      续流二极管                                SS2     6                                    60V/2A  肖特基二极管
   过压点设置电阻                                    300K:6.2K                                 OVP 引脚电压        1V 触发保护

          电感                                              4.7μ  H                 饱和电流大于               2A

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       5
```

## Page 6

```text
      Legend-si                                                                            LGS6303X
      www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：高效率恒流升压驱动         器（概述）

概述

LGS6303X 是一种集成功率             开关的升压型            DC-DC LED 驱动芯片，具有 3V 到 60V      的宽输入电压范围，集成了软起动，
从而最大限度地减少对外部浪涌抑制组件的需求，    使其成为宽输入电源范围 LED 驱动的理想选择。输出电流可以通过
外部电阻调整。
具有集成式 350mΩ功率开关,     可提供 2A 的输入峰值电流能力，具有出色的负载和线路瞬态响应。具备                   SKIP 控制模式，
将低静态电流与高开关频率相结合，可在广泛的负载电流范围内实现高效率。
附加功能包括：软启动，可调节输出过压保护，热关机，UVLO                                                      欠压锁定，逐周期峰值限流保护。

设定输出电流                                             输入欠压保护（VULO                ）

LGS6303X  输出电流可通过外置采样电阻                                             分压器调节输在器件 VIN   引脚上包含一个内部欠压锁定电路。当 VIN
出电流的大小，其输出电流的精度可达±3%         。建议的输                 电压低于 UVLO 的下降阈值，会触发 UVLO 保护，关闭
出电流取值见下表。                                          稳压器输出。该 UVLO 的上升阈值约为 3.0V  ，V    IN 达到
输出电流则可根据               VFB 和选择的R   Sence来计算输出电流值，  此电压以上移除 UVLO 后，控制器会进入软启动过程。
VFB 典型值是        0.2V：
                                                   最大占空比 DMAX
               𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂  =  𝑉𝑉𝐹𝐹𝐹𝐹𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆（ 𝑉𝑉）
                                                   当输入电压升至接近输出电压时，                        BOOST 切换到最大占

表 8  输出电流             设定快速配置                       空比工作状态，此时，低端 N 沟道 MOSFET 处于打开状

     IOUT           RSENCE         设定误差（1                           ） 态，将关断时间缩至最短。在最大占空比工作条件下，由
   10mA       20Ω    10mA        0%                于输入电压是输出                               电压值和（1-𝐷𝐷𝑀𝑀𝑀𝑀𝑀𝑀）的乘积，因此，输
   20mA       10Ω    20mA        0%
   50mA      3.9Ω    51mA       -2%                出电压骤降至调节范围以下。
  100mA        2Ω   100mA        0%
  200mA        1Ω   200mA        0%                软启动(Soft-              Start)
  300mA     0.68Ω   294mA       -2%
  400mA      0.5Ω   400mA        0%                LGS6303X  的软启动可防止在启动过程中变换器输入电

（1）也可选择其他的采样电阻和高精密电阻，                                以达到更高设定精度。 源的欠阻尼过冲。当芯片启动时，内部电路产生一个软启
                                                   动电压(           SS)      ，同时开关频率降为最大开关频率的 1/4，电
SKIP 跳脉冲模式                                         流以固定的上升速率上升。在软启动期间，输出电压将按
LGS6303X 内置跳脉冲电路；在轻负载时，该电路接通；                      比例跟踪内部节点电压斜坡。
仅在必要时切换，将输出电压保持在规定范围内。这样可                          当它小于内部参考(REF)时，SS 覆盖 REF，因此误差放
以降低开关损耗，让驱动    器在轻负载条件下保持较高效率。                     大器使用 SS 作为参考。当 SS 超过 REF 时，REF          恢复
在跳脉冲模式下, 当输出电压跌至规定值以下                              控制。在整个启动阶段，开关电流限制依然有效，可以非
时,LGS     6303X 进入 PWM 模式，并停留数个振荡器周期，              常可靠的避免上电即短路的情形。
使输出电压升至规定范围。在突发脉冲之间的等待时间内，                         当输出有非常大的电容（例如 2200uf 甚至更大）时，输
功率开关断开，由输出电容提供所有负载电流。由于输出                          出电压上升速度会比 SS 慢，受限于最大开关限流，启动
电压会不             定期地骤降和恢复，因此这种模式下的输出电压             到目标电压设定值的时间会延长。

纹波大于            PWM 工作模式下的纹波。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       6
```

## Page 7

```text
       Legend-si                                                                            LGS6303X
       www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：高效率恒流升压驱动         器（概述）

                                                            LGS63032  的调光频率支持范围更广，可到                   100KHZ       ，
EN 的调光使用说             明                                     调光比也更高，有  PWM   调光需要的更推荐选择

EN 是 BOOST 的使能输入引脚。将 EN 驱动至高电平                              LGS63032。
状态，可打开驱动器；将        EN 驱动至低电平状态，可关                           对于 LGS63032         的 PWM  调光实时平均输出电流计算
闭驱动器。此引脚内部设有               800K 下拉。外部逻辑信号                   公式：
也可用于驱动 EN 输入，以进行系统排序和保护。由于                                   𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂  = 0.2 ×𝐷𝐷     �0% ≤ 𝐷𝐷 ≤ 100%，0.6𝑉𝑉 ≤ 𝑉𝑉𝐸𝐸𝐸𝐸 ≤ 6𝑉𝑉�
内部下拉较弱，如需可靠关闭可外设下拉电阻，不建议                                            𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆
                                                            其中：
将此引脚空悬。                                                     D               为 PWM 的占空比。
表 9 引脚 EN 工作状态

    引脚                             方向                      引脚状态                                         功能 开关限流保护

 EN（Pin4）      输入                           BOOST 输出开启      稳压器输出具备逐周期过流限制。当 SW 电流触发
                                     高低                   BOOST 输出关闭
                                                            l LIMIT.SW(Peak),BOOST 输出会进入逐周期限流状态。
LGS63030 的模拟    调光

LGS63030 是支持通过复用            EN 引脚来实现 LED 的模
拟调光（0.6V      ~1.2V  ）。通过直流电压来实现模拟调光，
EN 端可以加一个直流电压 VEN 来调小 LED 输出电流，
最大输出 LED 电流由采样电阻决定，L              ED 模拟调光实
时平均输出电流计算公式：

    𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂  = 0.2 × (𝑉𝑉𝐸𝐸𝐸𝐸 −0.6)     (0.6𝑉𝑉 ≤ 𝑉𝑉𝐸𝐸𝐸𝐸 ≤ 1.2𝑉𝑉)
             0.6 ×𝑅𝑅𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆𝑆                                        图 9 BOOST 输出过流于 Mtop 行为描述
当 VEN 大于 1.2V    小于耐压值 6V 时，LED 电流保持        100%            ILIMIT.SW(Peak)与电感大小和输入压差相关，I                                                                          LIMIT.SW(Peak)仅
等于设置的 LED 最大平均电流。                                           为参考最小值。当长时间过流或短路时，将可能触发全
                                                            局 OTP 保护。
LGS63032    的 PWM    调光

LGS63032 支持 PWM 调光，通过 PWM 调光，LED 的
输出电流可以从  0%到  100%变化。             LED  的亮度是由
PWM 信号的占空比决定的。例如 PWM 信号 25%占空
比，LED           的平均电流为(0.2/RSence)的  25%。建议设置
PWM 调光频率在 120Hz 以上，以避免人的眼睛可以看
到 LED 的闪烁。PWM 调光比模拟调光的优势在于不改
变 LED 的色度。具体支持               EN 调光范围为：
■        LGS63032  支持数字输入（1       00HZ~100KHZ       ）的
    PWM 调光，高频 PWM 输入下无屏闪。调光比在
    PWM 频率为 100HZ 时高达 25000        :1。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       7
```

## Page 8

```text
      Legend-si                                                                            LGS6303X
      www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：高效率恒流升压驱动         器（概述）

OTP 过热保护

热过载保护电路将结温限制在  150℃(            典型值）以下。在
极端条件下（即高环境温度和/或高功耗）     ,当结温开始升
至 150℃以上时，过温保护即被激活，系统将会强制关闭
稳压器输出（如果 EN 被使能）。当结温降至 130°C         以下
时，OTP           状态就会解锁，稳压器输出重新开启，输出电
流恢复为正常工作值。热过载保护旨在保护器件免受瞬间
偶然过载条件发生时的影响。
本器件的保证工作结温范围为-    40°C      至 125°C       。高结温会
降低工作寿命；结温长时间高 125°      C  时，器件寿命会缩
短。请注意，与这些规格一致的最高环境温度取决于具体
工作条件以及电路板布局、额定封装热阻和其他环境因素。
结温(T            J，单位为℃)                       根据环境温度(T                                   A，单位为℃)                       和功耗
(PD 单位为 W)计算，计算公式如下：

               𝑻𝑻𝑱𝑱 = 𝑻𝑻𝑨𝑨 +�𝑷𝑷𝑫𝑫 ×𝜽𝜽𝑱𝑱𝑨𝑨 �

其中 θJA(单位为℃/W     )为封装热阻。
输出过压保护（OVP   ）

输出过压保护电路防止 LED 灯珠断开而损坏芯片。根据
LED  灯珠的实际数量，     通过外部电路的比例设定过压保
护阈值。           OVP  触发点电压典型值为  1V，恢复点电压为
0.86V     。

   VOUT                OVPR1
                                  +

                    R2      1V    -

                 图 10       设置 OVP 电压
过压保护阈值可根据以下公式计算：

            𝑉𝑉𝑂𝑂𝑂𝑂𝑂𝑂_𝑂𝑂𝑂𝑂𝑂𝑂  = �1 +𝑅𝑅1𝑅𝑅2� × 1（ 𝑉𝑉）

建议过压保护阈值设置在正常输出电压的               1.3~  1.5 倍。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       8
```

## Page 9

```text
      Legend-si                                                                            LGS6303X
      www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：高效率恒流升压驱动器（概述）

                                                  过正常工作时电感电流峰 30%—40%。电感的峰值电流
输入电容 CIN                                          可依照以下公式计算：
输入电容典型值为 4.7μ  F，       若需进一步减小输入/输出                                         𝐸𝐸 2         𝐸𝐸  )
                                                   𝐼𝐼𝐿𝐿(𝑂𝑂𝐸𝐸𝑀𝑀𝑃𝑃) = 𝑉𝑉𝑂𝑂𝑂𝑂𝑂𝑂𝑉𝑉𝐼𝐼×𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂(𝑀𝑀𝑀𝑀𝑀𝑀) +� 𝑉𝑉𝐼𝐼𝑉𝑉𝑂𝑂𝑂𝑂𝑂𝑂�× (𝑉𝑉𝑂𝑂𝑂𝑂𝑂𝑂 −𝑉𝑉𝐼𝐼2 ×𝑓𝑓𝑆𝑆𝑆𝑆 ×𝐿𝐿
纹波，可选用更大的电容。             额定电压必须大于 IC   所要                    𝐸𝐸

求的最大输入电压，最好在最大输入电压两倍以上（1）。                        功率二极管        D
在开关频率下输入电容的容抗需尽可能的小，建议使用                          LGS6303      X  在  SW  引脚和输出之间需要一个外部续流
X5R 或 X7R 的陶瓷电容。为了尽可能的减小潜在输入                      二极管。所选二极管的反向电压额定值必须大于
噪声问题，请将这颗陶瓷电容靠进 IN   和 GND  引脚放                   VOUTMAX，二极管的峰值额定电流必须大于最大电感电
置，以减少由 CIN 与 IN/GND  引脚形成的环路面积。                   流。由于肖特基二极管具有较低的正向电压降和较快的
（1    ）陶瓷电容的直流偏压效应使得电容有效值下降。                      开关速度，因此推荐使用肖特基二极管以获得最佳效率。
输出电容 COUT

选择输出电容处理输出电流纹波噪声，为了最好的性能
要求，推荐使用容值 10μ    F  ，材质为 X5R 或 X7R 的陶
瓷电容。如若使用芯片需要使用            PWM 调光模式，为解
决输出电容在该情况下由于压电效应产生的啸叫问题，
有以下两种方式减小该问题：
（1）推荐使用钽电容，薄膜电容等不具备压电效应的
电容器或者瓷片插件电容代替陶瓷电容，此方法舍弃了
MLCC 轻薄的优势，因此在实际应用中需要考虑体积空
间、可靠性和成本等问题。
（ 2 ）在需要使用  PWM   调光的场景中建议使用
LGS6303      2，该芯片可以使用的调光频率较高可以避开
人耳识别范围，从而达到消除电容啸叫的目的。
功率电感        L

电感的选择需要考虑以下几个方面：
(1)  选择电感提供所需的电流纹波。建议选择电流纹波
约为当前最大输出电流  20~50%，电感计算公式如下：
              𝐸𝐸 2
        𝐿𝐿 = � 𝑉𝑉𝐼𝐼𝑉𝑉𝑂𝑂𝑂𝑂𝑂𝑂�×        (𝑉𝑉𝑂𝑂𝑂𝑂𝑂𝑂 −𝑉𝑉𝐼𝐼𝐸𝐸)𝑓𝑓𝑆𝑆𝑆𝑆 ×𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂(𝑀𝑀𝑀𝑀𝑀𝑀) ×𝐾𝐾

    其中𝑓𝑓     𝑆𝑆𝑆𝑆为开关频率，𝐼𝐼𝑂𝑂𝑂𝑂𝑂𝑂(𝑀𝑀𝑀𝑀𝑀𝑀)为 LED 电流，常数
𝐾𝐾是电感电流纹波的百分比。
    对于 LGS6303      X ,典型应用电路中的  Boost 拓扑电
感最佳选择范围是 4.7µH    到 47µH，为了最佳的环路稳
定与效率曲线，推荐电感值为 4.7µH  。
(2)  为保证电路安全，必须选择电感的饱和电流额定值
大于满载条件下的峰值电流，推荐选取电感饱和电流超

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       9
```

## Page 10

```text
         Legend-si                                                                            LGS6303X
         www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：典型应用特征

如无特殊说明，则 L=4.7μ  H，COUT=10μF，TA=25℃

                                            Figure 11.1 Efficiency vs Input Voltage
     100%                                                                  100%

      95%                                                                    95%

                                                                             90%
      90%                                                                    85%

      85%                                                                    80%

      80%                                                                    75%
                                                   3pcs LED                  70%                                         3pcs LED
      75%                                          5pcs LED                  65%                                         5pcs LED
                                                   9pcs LED                                                              9pcs LED
      70%                                                                    60%
             3               8              13             18             23       3            8           13          18          23          28
                            Input Voltage(V)                                                       Input Voltage(V)

                  Figure 12.1.a IOUT=200mA                                               Figure 12.1.b IOUT=400mA

                                          Figure 11.2 LED Current vs Input Voltage
    0.203                                                                  0.406
                                                   3pcs LED                                                               3pcs LED
    0.202                                          5pcs LED                0.404                                          5pcs LED

    0.201                                          9pcs LED                0.402                                          9pcs LED

    0.200                                                                  0.400

    0.199                                                                  0.398

    0.198                                                                  0.396

    0.197                                                                  0.394
             3               8              13             18             23       3            8           13          18          23          28
                            Input Voltage(V)                                                       Input Voltage(V)

                  Figure 12.2.a IOUT=200mA                                               Figure 12.2.a IOUT=400mA

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       10
```

## Page 11

```text
        Legend-si                                                                            LGS6303X
        www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：典型应用特征

如无特殊说明，则 L=4.7μ  H，COUT=10μF，TA=25℃
                                        Figure 12.1 63030 Analog Dimming Curve
        250                                                                  450
                                                                             400
        200                                                                  350

                                                                             300
        150                                                                  250

        100                                                                  200
                                                                             150
          50                                                                 100
                                                                              50
           0                                                                    0
               0         0.5         1         1.5         2         2.5           0         0.5         1         1.5         2         2.5
                            EN Voltage(V)                                                        EN Voltage(V)

   Figure 13.1.a LGS6303      0, VIN=5V,3pcs LED Series                Figure 13.1.b LGS6303      0, VIN=5V,3pcs LED Series
                                         Figure 12.2  63032 PWM Dimming Curve
       200                                                                  400

       175                                                                  350
       150                                                                  300
       125                                                                  250

       100                                                                  200
         75                                                                 150
         50                             100Hz Dimming                       100                             100Hz Dimming
                                        1kHz Dimming                                                        1kHz Dimming
         25                             10kHz Dimming                        50                             10kHz Dimming
          0                             100kHz Dimming                         0                            100kHz Dimming
             0%      20%     40%     60%     80%    100%                         0%      20%     40%     60%     80%    100%
                            PWM Duty Cycle                                                       PWM Duty Cycle

    Figure 13.2.c    LGS6303       2,VIN=5V,3pcs LED Series             Figure 13.2.e    LGS6303       2,VIN=5V,3pcs LED Series

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       11
```

## Page 12

```text
        Legend-si                                                                            LGS6303X
        www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：典型应用特征

如无特殊说明，则 L=4.7μ  H，COUT=10μF，TA=25℃
                                   Figure 13.1 EN Start-Up/Shut- down Waveforms

  Figure 14.1.a V   IN=5V, I OUT=400mA,3pcs LED Series             Figure 14.1.b V   IN=5V, I OUT=400mA,3pcs LED Series
                                   Figure 13.2 Vin Start-Up/Shut- down Waveforms

  Figure 14.2.a VIN=5V, I OUT=400mA,3pcs LED Series                Figure 14.2.b VIN=5V, I OUT=400mA,3pcs LED Series
                                           Figure 13.3 Switching Waveforms

  Figure 14.3.a VIN=5V, I OUT=400mA,3pcs LED Series                 Figure 14.3.b VIN=5V, I OUT=10mA,3pcs LED Series
                          CCM Mode                                                     Pulse Skip Mode

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       12
```

## Page 13

```text
        Legend-si                                                                            LGS6303X
        www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：典型应用特征

如无特殊说明，则 L=4.7μ  H，COUT=10μF，TA=25℃
                                                Figure 14.1 OTP Waveforms

  Figure 15.1.a VIN=5V, I OUT=400mA      ,3pcs LED Series           Figure 15.1.b VIN=5V, I OUT=400mA    ,3pcs LED Series
                                          Figure 14.2 PWM Dimming Transient

  Figure 15.2.a LGS6303      0, VIN=5V, I OUT=400mA    ,3pcs        Figure 15.2.b LGS6303      2, VIN=5V, I OUT=400mA      ,3pcs
                          LED Series                                                        LED Series
                                                Figure 14.3 OVP Waveforms

  Figure 15.3.a VIN=5V, I OUT=400mA,3pcs LED Series,               Figure 15.3.b VIN=5V, I OUT=400mA    ,3pcs LED Series,

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       13
```

## Page 14

```text
      Legend-si                                                                            LGS6303X
      www.Legend  -si.com                                                                           Rev.C V1  .2
应用信息：参考布局

概述

LGS6303X 的高集成度使 PCB 板布局非常简单和容易。较差的布局会影响 LGS6303X 的性能，造成电磁干扰(EMI )             、
电磁兼容性(EMC)差、地跳以及电压损耗，进而影响稳压调节和稳定性。为了优化其电气和热性能，应运用下列规则来
实现良好的 PCB 布局布线，确保最佳性能：

■        必须将高频陶瓷输入电容 CIN 尽量近距离放在 VIN、                   ■        为使过孔传导损耗最小并降低模块热应力，应使用
   GND 引脚旁边，以尽量降低高频噪声。                                     多个过孔来实现顶层和其他电源层或地层之间的

■        必须减小与 SW 引脚相关的 PCB 敷铜面积，以避                        互连。
   免潜在的噪声干扰问题。                                          ■       FB  引脚阻抗较高，引线轨迹应尽量短并且远离高

■        对高电流路径应使用较大  PCB  覆铜区域，包括                         噪声 LX 节点或屏蔽起来。
   GND 引脚。这有助于最大限度地减少 PCB 传导损                           ■       ESOP8  封装芯片底部散热焊盘加过孔开窗有助于
   耗和热应力。                                                  芯片散热提高效率。

                                                                                  EN
                                                   FB       GND
                                                                                  OVP
                                                   GND

                                                   SW                NC

                                                   SW                              VIN

                                   GND
                                                                                   GND

                    VIAS TO GROUND PLANE

                                    图 15.1 Boost 型 ESOP8 封装典型应用        PCB 参考布局

                                                 GND  SW

                                         FB

                        VIAS TO GROUND PLANE                                VIN
                                                EN  OVP

                                    图 15.2 Boost 型 SOT23-6 封装典型应用        PCB 参考布局

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       14
```

## Page 15

```text
        Legend-si                                                                            LGS6303X
        www.Legend  -si.com                                                                           Rev.C V1  .2
封装外形描述(       ESOP8)

具备底部 EPAD 的 8 引脚塑封 SOIC

                                     6.2                                                                    C
                                     5.8TYP                                            SEATING PLANE

              A                            PIN 1 ID                                                    0.1 C
                                           AREA
                                                                    6X  1.27
                   1                                        8

             5.0                                                     2X
             4.8                                                    3.81
           NOTE 3

                   4
                                                          5          0.51
                                       4.0                        8X 0.31
                      B                3.8                            0.1   C  A   B                     1.7 MAX
                                     NOTE 4

                                                                   0.25 TYP
                                                                   0.10

                                   SEE DETAIL  A

                    4                                       5
                                                                EXPOSED
                                                                THERMAL   PAD

              3.1                                                                   0.25
              2.5                                                          GAG E PLANE

                                                                                                                      0.15
                   1                                        8                   0 - 8             1.27                0.00
                                                                                                  0.40
                                                                                                       DETAIL   A
                                       2.6                                                              TYPI CAL
                                       2.0

注：

（1    ）             所有的数据单位都是亳米，括号内的任何尺寸仅供参考。
（2    ）             本图如有更改，恕不另行通知。
（3    ）             此尺寸不包括塑模毛边，突起，或水口毛刺。
（4    ）             此尺寸不包括塑模毛边。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       15
```

## Page 16

```text
       Legend-si                                                                            LGS6303X
       www.Legend  -si.com                                                                           Rev.C V1  .2
封装外形描述(       SOT23-6)

1.45mm  高度  6 引脚 SOT-23   塑封

注：

（1    ）             所有的数据单位都是亳米，括号内的任何尺寸仅供参考。
（2    ）             本图如有更改，恕不另行通知。
（3    ）             此尺寸不包括塑模毛边，突起，或水口毛刺。
（4    ）             此尺寸不包括塑模毛边。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       16
```

## Page 17

```text
       Legend-si                                                                            LGS6303X
       www.Legend  -si.com                                                                           Rev.C V1  .2
器件封装焊盘布局举例(           ESOP8)

具备底部 EPAD 的 8 引脚塑封 SOIC

                                                          (2.71)          SOLDER MASK
                              8X (.061)                SOLDER MASK        DEFINED PAD
                                  [1.55]                 OPENING                 SEE

                                        1                                        DETAILS

                                                                               8
                                                     EP
                            8X (.024)                                                     (3.4)
                                [0.6]
                                                                                  (1.3)  OPENING
                                                                                  TYP

                                                                                                  (R.002) TYP
                                                                               5                    [0.05]
                        6X (.050)       4

                            [1.27]                        SYMM
                                ( 0.2)TYP
                                     VIA
                                                (1.3)TYP

                                                          (.213)
                                                          [5.4]
                                              LAND PATTERN EXAMPLE
                                                EXPOSED METAL SHOWN
                                                        SCALE:8X

                     METAL                 SOLDER MASK          SOLDER MASK                    METAL UN DER
                                           OPENING                   OPENING                   SOLDER MASK

             EXPOSED                                           EXPOSED
                METAL                                             METAL
                                 .0028MAX                                           .0028MIN
                                 [0.07]                                             [0.07]
                                 ALL AROUND                                         ALL AROUN D

                           NON SOLDER MASK                                       SOLDER MASK
                                DEFINED                                            DEFINED

                                                 SOLDER MASK DETAILS

注：

（1    ）             基于 IPC-7351 依赖于久经考验的数学算法，综合考虑了制造、组装和元件容差，从而精确计算的焊盘图形                                      。
（2    ）             信号焊盘之间和周围的焊接掩膜公差可能因电路板制造而异。
（3    ）             金属垫的尺寸可能因爬电要求而异。
（4    ）             通孔是可选的，取决于应用，请参阅器件数据表。如果使用了过孔，请参考此视图中所示的过孔位置。建议
     填充、或用锡膏盖住焊盘下的过孔。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       17
```

## Page 18

```text
       Legend-si                                                                            LGS6303X
       www.Legend  -si.com                                                                           Rev.C V1  .2
器件封装焊盘布局举例(           SOT23-6)

1.45mm  高度  6 引脚 SOT-23   塑封

注：

（1    ）             基于 IPC-7351 依赖于久经考验的数学算法，综合考虑了制造、组装和元件容差，从而精确计算的焊盘图形                                      。
（2    ）             信号焊盘之间和周围的焊接掩膜公差可能因电路板制造而异。
（3    ）             金属垫的尺寸可能因爬电要求而异。

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       18
```

## Page 19

```text
          Legend-si                                                                            LGS6303X
          www.Legend  -si.com                                                                           Rev.C V1  .2
TAPE AND REEL INFORMALEGEND-SION

*ALL dimensions are nominal

                     Package        Package                            Reel          A0          B0         K0          P1         W          Pin1
     Device            Type         Drawing       Pins       SPQ       Width        (mm)       (mm)        (mm)       (mm)       (mm)      Quadrant
                                                                     W1(mm)
  LGS63030              SOT23  -6          B6              6       3000       180.0         8.4         3.2         3.2         1.4         1.4            Q3

  LGS63032              SOT23  -6          B6              6       3000       180.0         8.4         3.2         3.2         1.4         1.4            Q3
  LGS63030              ESOP8L         EP                8       4000        330           6.5         5.3         2.1           8           12            Q1

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       19
```

## Page 20

```text
       Legend-si                                                                            LGS6303X
       www.Legend  -si.com                                                                           Rev.C V1  .2

                                                   免责声明

     和 Legend-si 是棱晶半导体有限公司的商标，Legend                               -si 拥有多项专利、商标、商业机密和其他知识产权。Legend                                                                                             -si
对公司产品提供可靠性数据（包括数据表）、设计资源（包括参考设计）、应用或其他设计建议、技术支持和其他资源，但不
就本司任何产品用于任何特定目的做出担保。Legend                               -si  不承担任何因产品的使用产生的责任，包括使用方须遵守的法律法
规和安全使用标准。
对于在规格书中提到的产品参数，在不同的应用条件下实际性能可能会产生变化。任何参数的配置和使用必须经由客户的技
术支持进行验证，对本文档所涉及的内容进行变更，恕不另行通知。Legend                  -si  对您的使用授权仅限于产品的应用，除此之
外不得复制或展示所述资源，L                                                          egend-si  也不提供任何人或第三方机构的知识产权授权许可。如因使用所述资源而产生任何
索赔、赔偿、成本、债务及任何损失，L                                                                            egend-si 对此概不负责，并且您须赔偿由此对 Legend-si 造成的损害。
Legend-si 所提供产品均受 Legend-si 的销售条款以及 www.Legend-si.com 上或随附 Legend-si 产品提供的其他可适用条
款的约束。L                      egend-si 提供所述资源并不扩展或以其他方式更改 Legend-si 针对 Legend-si 产品所发布的可适用的担保范围
或担保免责声明。
Legend-si 反对并拒绝您可能提出的任何其他或不同的条款。

邮寄地址：江苏省南京市浦口区江淼路                                                  88 号腾飞大厦 C 座 1403 室           电话：025-        58196091

                                            棱晶半导体（南京）有限公司

棱晶半导体（南京）有限公司                                                                                             www.Legend-Si.com
LGS6303X                                                                         LGS6303X      Product data sheet       20
```
