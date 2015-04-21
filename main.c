#include "common.h"
#include "reg.h"

void __attribute__((interrupt)) systick_handler(void) {
	static int on = 0;

	if(!on) {
		GPIOG->BSRR = (1 << 13);
		on = 1;
	}
	else {
		GPIOG->BSRR = (1 << 29);
		on = 0;
	}
}

int main(void)
{
	rcc_clock_init();

	/* Set PA8 for MCO1 function */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER = GPIO_MODER8_ALTERNATE;
	GPIOA->OTYPER = GPIO_OTYPER8_PP;
	GPIOA->OSPEED = GPIO_OSPEED8_100MHZ;
	GPIOA->PUPDR = GPIO_PUPDR8_NO;
	GPIOA->AFRH = GPIO_AFRH8_AF0;

	/* Set PC9 as MCO2 function */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER = GPIO_MODER9_ALTERNATE;
	GPIOC->OTYPER = GPIO_OTYPER9_PP;
	GPIOC->OSPEED = GPIO_OSPEED9_100MHZ;
	GPIOC->PUPDR = GPIO_PUPDR9_NO;
	GPIOC->AFRH = GPIO_AFRH9_AF0;

	/* Set MCO1, depends on which rcc you used */
	init_mco1();

	/* Set MCO2, select SYSCLK as output source and no division */
	RCC->CFGR &= ~RCC_CFGR_MCO2;
	RCC->CFGR |= RCC_CFGR_MCO2_SYSCLK;
	RCC->CFGR &= ~RCC_CFGR_MCO2_PRE;
	RCC->CFGR |= RCC_CFGR_MCO2_PRE_DIV1;

	/* Set PG13 as general output function(LED) */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	GPIOG->MODER = GPIO_MODER13_OUTPUT;
	GPIOG->OTYPER = GPIO_OTYPER13_PP;
	GPIOG->OSPEED = GPIO_OSPEED13_100MHZ;
	GPIOG->PUPDR = GPIO_PUPDR13_NO;

	/* Set SysTick, trigger every 500ms */
	init_systick();

	while(1);

	return 0;
}
