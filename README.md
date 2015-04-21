Clock_Testing on STM32F429-Discovery
==================================
This project is target for rcc settings on stm32f429-discovery development board.
You can find more test data in [Hackpad - Clock-Testing on STM32F429](https://hackpad.com/Clock-Testing-on-STM32F429-cDTpY6JkEVV).

Instructions
============
There are four targets which are based on different rcc settings:
* HSI
```
make hsi
make flash
```
* HSE
```
make hse
make flash
```
* PLL used HSI as source
```
make pll_hsi
make flash
```
* PLL used HSE as source
```
make pll_hse
make flash
```

After flash the image into stm32f429, you can connect oscilloscope to MCO1(PA8) and MCO2(PC9) to observe the signal 
generated by the clock. The default setting of MCO2's clock source is `SYSCLK`, and MCO1's clock source is depending on 
which target you built.

PLL
===
According to the formula in ST Reference Manual RM0090, PLL clock outputs depends on `VCO clock`, `PLL_N`, `PLL_M`, `PLL_P`, `PLL_Q`:
* f(VCO clock) = f(PLL clock input) * (PLL_N / PLL_M)
* f(PLL general clock output) = f(VCO clock) / PLL_P
* f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock) / PLL_Q

Following is the default setting for PLL in this project, both pll output 24MHz:
* pll_hsi(frequency of HSI is 16MHz)
```
PLL_M = 16
PLL_N = 192
PLL_P = 8
PLL_Q = 7
```
* pll_hse(frequency of HSE is 8MHz)
```
PLL_M = 8
PLL_N = 192
PLL_P = 8
PLL_Q = 7
```

Flash
=====
According to ST reference Manual RM0090 Section 3.4.1, latency of flash memory should be set depending on cpu clock frequency. So if you speed up the PLL clock frequency, you should check the latency is set correctly.
For example, if use the following settings for PLL used HSE as source:
```
PLL_M = 8
PLL_N = 336
PLL_P = 2
PLL_Q = 7
==> f(PLL general clock ouput) = 168MHz
```
Then the flash latency should be 5 wait states(WS).

SysTick
=======
`SysTick` will be triggered every 500ms in the default settings. There are two source you can choose for `SysTick`:
* external clock => Cortex System timer(HCLK / 8)
* processor clock => HCLK
