#include "reg.h"

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
}

void init_mco1(void)
{
	/* Set MCO1, select HSE as output source and no division */
	RCC->CFGR &= ~RCC_CFGR_MCO1;
	RCC->CFGR |= RCC_CFGR_MCO1_HSE;
	RCC->CFGR &= ~RCC_CFGR_MCO1_PRE;
	RCC->CFGR |= RCC_CFGR_MCO1_PRE_DIV1;
}

void init_systick(void)
{
	SYSTICK->RVR = 0x3D08FF; // 3999999 (~= 4000000)
	SYSTICK->CVR = 0x0;
	SYSTICK->CSR = 0x7;
}
