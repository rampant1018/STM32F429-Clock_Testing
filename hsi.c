#include "reg.h"

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
}

void init_mco1(void)
{
	/* Set MCO1, select HSI as output source and no division */
	RCC->CFGR &= ~RCC_CFGR_MCO1;
	RCC->CFGR |= RCC_CFGR_MCO1_HSI;
	RCC->CFGR &= ~RCC_CFGR_MCO1_PRE;
	RCC->CFGR |= RCC_CFGR_MCO1_PRE_DIV1;
}
