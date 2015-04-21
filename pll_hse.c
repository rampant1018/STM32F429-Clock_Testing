#include "reg.h"

#define PLL_M 8
#define PLL_N 192
#define PLL_P 8
#define PLL_Q 7

void rcc_clock_init(void)
{
	/* Enable HSE */
	RCC->CR |= RCC_CR_HSEON;

	/* Wait until HSE ready */
	while(!(RCC->CR & RCC_CR_HSERDY));

	/* Set HPRE, no division */
	RCC->CFGR &= ~RCC_CFGR_HPRE;
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	/* Select HSE as System clock */
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_HSE;

	/* Configure the main PLL */
	RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
		       (RCC_PLLCFGR_PLLSRC_HSE) | (PLL_Q << 24);

	/* Enable the main PLL */
	RCC->CR |= RCC_CR_PLLON;
										
	/* Wait till the main PLL is ready */
	while((RCC->CR & RCC_CR_PLLRDY) == 0);

	/* Configure Flash prefetch, Instruction cache, Data cache and wait state */
	FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_1WS;

	/* Select the main PLL as system clock source */
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL;

	/* Wait till the main PLL is used as system clock source */
	while ((RCC->CFGR & RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
}

void init_mco1(void)
{
	/* Set MCO1, select PLL as output source and division by 2 */
	RCC->CFGR &= ~RCC_CFGR_MCO1;
	RCC->CFGR |= RCC_CFGR_MCO1_PLL;
	RCC->CFGR &= ~RCC_CFGR_MCO1_PRE;
	RCC->CFGR |= RCC_CFGR_MCO1_PRE_DIV2;
}

void init_systick(void)
{
	SYSTICK->RVR = 0xB71AFF; // 11999999 (~= 12000000)
	SYSTICK->CVR = 0x0;
	SYSTICK->CSR = 0x7;
}
