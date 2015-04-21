#include "reg.h"

#define PLL_M 16
#define PLL_N 192
#define PLL_P 8
#define PLL_Q 7

void rcc_clock_init(void)
{
	/* Enable HSI */
	RCC->CR |= RCC_CR_HSION;

	/* Wait until HSI ready */
	while(!(RCC->CR & RCC_CR_HSIRDY));

	/* Set HPRE, no division */
	RCC->CFGR &= ~RCC_CFGR_HPRE;
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

	/* Select HSI as System clock */
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_HSI;

	/* Configure the main PLL */
	RCC->PLLCFGR = PLL_M | (PLL_N << 6) | (((PLL_P >> 1) -1) << 16) |
		       (RCC_PLLCFGR_PLLSRC_HSI) | (PLL_Q << 24);

	/* Enable the main PLL */
	RCC->CR |= RCC_CR_PLLON;
										
	/* Wait till the main PLL is ready */
	while((RCC->CR & RCC_CR_PLLRDY) == 0);

	/* Configure Flash prefetch, Instruction cache, Data cache and wait state */
	FLASH->ACR = FLASH_ACR_ICEN | FLASH_ACR_DCEN | FLASH_ACR_LATENCY_0WS;

	/* Select the main PLL as system clock source */
	RCC->CFGR &= ~RCC_CFGR_SW;
	RCC->CFGR |= RCC_CFGR_SW_PLL;

	/* Wait till the main PLL is used as system clock source */
	while ((RCC->CFGR & RCC_CFGR_SWS ) != RCC_CFGR_SWS_PLL);
}

void init_mco1(void)
{
	/* Set MCO1, select HSE as output source and no division */
	RCC->CFGR &= ~RCC_CFGR_MCO1;
	RCC->CFGR |= RCC_CFGR_MCO1_PLL;
	RCC->CFGR &= ~RCC_CFGR_MCO1_PRE;
	RCC->CFGR |= RCC_CFGR_MCO1_PRE_DIV2;
}
