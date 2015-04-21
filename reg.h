#ifndef __REG_H_
#define __REG_H_

#include <stdint.h>

#define __IO volatile

typedef struct {
	__IO uint32_t CR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	__IO uint32_t AHB3RSTR;
	uint32_t RES0;
	__IO uint32_t APB1RSTR;
	__IO uint32_t APB2RSTR;
	uint32_t RES1[2];
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
	__IO uint32_t AHB3ENR;
	uint32_t RES2;
	__IO uint32_t APB1ENR;
	__IO uint32_t APB2ENR;
	uint32_t RES3[2];
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
	__IO uint32_t AHB3LPENR;
	uint32_t RES4;
	__IO uint32_t APB1LPENR;
	__IO uint32_t APB2LPENR;
	uint32_t RES5[2];
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	uint32_t RES6[2];
	__IO uint32_t SSCGR;
	__IO uint32_t PLLI2SCFGR;
	uint32_t RES7;
	__IO uint32_t DCKCFGR;
} RCC_TypeDef;

typedef struct {
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEED;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFRL;
	__IO uint32_t AFRH;
} GPIO_TypeDef;

typedef struct {
	__IO uint32_t CR;
	__IO uint32_t CSR;
} PWR_TypeDef;

typedef struct {
	__IO uint32_t ACR;
	__IO uint32_t KEYR;
	__IO uint32_t OPTKEYR;
	__IO uint32_t SR;
	__IO uint32_t CR;
	__IO uint32_t OPTCR;
} FLASH_TypeDef;

typedef struct {
	__IO uint32_t CSR;
	__IO uint32_t RVR;
	__IO uint32_t CVR;
	__IO uint32_t CALIB;
} SYSTICK_TypeDef;

#define RCC     ((RCC_TypeDef *) (uint32_t)0x40023800)
#define GPIOA   ((GPIO_TypeDef *) (uint32_t)0x40020000)
#define GPIOC   ((GPIO_TypeDef *) (uint32_t)0x40020800)
#define GPIOG   ((GPIO_TypeDef *) (uint32_t)0x40021800)
#define PWR     ((PWR_TypeDef *) (uint32_t)0x40007000)
#define FLASH   ((FLASH_TypeDef *) (uint32_t)0x40023C00)
#define SYSTICK ((SYSTICK_TypeDef *) (uint32_t)0xE000E010)

/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY                    ((uint32_t)0x00000007)
#define FLASH_ACR_LATENCY_0WS                ((uint32_t)0x00000000)
#define FLASH_ACR_LATENCY_1WS                ((uint32_t)0x00000001)
#define FLASH_ACR_LATENCY_2WS                ((uint32_t)0x00000002)
#define FLASH_ACR_LATENCY_3WS                ((uint32_t)0x00000003)
#define FLASH_ACR_LATENCY_4WS                ((uint32_t)0x00000004)
#define FLASH_ACR_LATENCY_5WS                ((uint32_t)0x00000005)
#define FLASH_ACR_LATENCY_6WS                ((uint32_t)0x00000006)
#define FLASH_ACR_LATENCY_7WS                ((uint32_t)0x00000007)

#define FLASH_ACR_ICEN                       ((uint32_t)0x00000200)
#define FLASH_ACR_DCEN                       ((uint32_t)0x00000400)

/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION            ((uint32_t)0x00000001)
#define RCC_CR_HSIRDY           ((uint32_t)0x00000002)
#define RCC_CR_HSEON            ((uint32_t)0x00010000)
#define RCC_CR_HSERDY           ((uint32_t)0x00020000)
#define RCC_CR_HSEBYP           ((uint32_t)0x00040000)
#define RCC_CR_HSEON            ((uint32_t)0x00010000)
#define RCC_CR_PLLON            ((uint32_t)0x01000000)
#define RCC_CR_PLLRDY           ((uint32_t)0x02000000)

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLSRC      ((uint32_t)0x00400000)
#define RCC_PLLCFGR_PLLSRC_HSI  ((uint32_t)0x00000000)
#define RCC_PLLCFGR_PLLSRC_HSE  ((uint32_t)0x00400000)

/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define  RCC_CFGR_SW            ((uint32_t)0x00000003)
#define  RCC_CFGR_SW_HSI        ((uint32_t)0x00000000)
#define  RCC_CFGR_SW_HSE        ((uint32_t)0x00000001)
#define  RCC_CFGR_SW_PLL        ((uint32_t)0x00000002)

/*!< SWS configuration */
#define  RCC_CFGR_SWS           ((uint32_t)0x0000000C)
#define  RCC_CFGR_SWS_HSI       ((uint32_t)0x00000000)
#define  RCC_CFGR_SWS_HSE       ((uint32_t)0x00000004)
#define  RCC_CFGR_SWS_PLL       ((uint32_t)0x00000008)

/*!< HPRE configuration */
#define  RCC_CFGR_HPRE          ((uint32_t)0x000000F0)
#define  RCC_CFGR_HPRE_DIV1     ((uint32_t)0x00000000)
#define  RCC_CFGR_HPRE_DIV2     ((uint32_t)0x00000080)
#define  RCC_CFGR_HPRE_DIV4     ((uint32_t)0x00000090)
#define  RCC_CFGR_HPRE_DIV8     ((uint32_t)0x000000A0)
#define  RCC_CFGR_HPRE_DIV16    ((uint32_t)0x000000B0)
#define  RCC_CFGR_HPRE_DIV64    ((uint32_t)0x000000C0)
#define  RCC_CFGR_HPRE_DIV128   ((uint32_t)0x000000D0)
#define  RCC_CFGR_HPRE_DIV256   ((uint32_t)0x000000E0)
#define  RCC_CFGR_HPRE_DIV512   ((uint32_t)0x000000F0)

/*!< MCO1 configuration */
#define RCC_CFGR_MCO1           ((uint32_t)0x00600000);
#define RCC_CFGR_MCO1_HSI       ((uint32_t)0x00000000);
#define RCC_CFGR_MCO1_LSE       ((uint32_t)0x00200000);
#define RCC_CFGR_MCO1_HSE       ((uint32_t)0x00400000);
#define RCC_CFGR_MCO1_PLL       ((uint32_t)0x00600000);

#define RCC_CFGR_MCO1_PRE	((uint32_t)0x07000000)
#define RCC_CFGR_MCO1_PRE_DIV1  ((uint32_t)0x00000000)
#define RCC_CFGR_MCO1_PRE_DIV2  ((uint32_t)0x04000000)
#define RCC_CFGR_MCO1_PRE_DIV3  ((uint32_t)0x05000000)
#define RCC_CFGR_MCO1_PRE_DIV4  ((uint32_t)0x06000000)
#define RCC_CFGR_MCO1_PRE_DIV5  ((uint32_t)0x07000000)

/*!< MCO2 configuration */
#define RCC_CFGR_MCO2           ((uint32_t)0xC0000000);
#define RCC_CFGR_MCO2_SYSCLK    ((uint32_t)0x00000000);
#define RCC_CFGR_MCO2_PLLI2S    ((uint32_t)0x40000000);
#define RCC_CFGR_MCO2_HSE       ((uint32_t)0x80000000);
#define RCC_CFGR_MCO2_PLL       ((uint32_t)0xC0000000);

#define RCC_CFGR_MCO2_PRE       ((uint32_t)0x38000000)
#define RCC_CFGR_MCO2_PRE_DIV1  ((uint32_t)0x00000000)
#define RCC_CFGR_MCO2_PRE_DIV2  ((uint32_t)0x20000000)
#define RCC_CFGR_MCO2_PRE_DIV3  ((uint32_t)0x28000000)
#define RCC_CFGR_MCO2_PRE_DIV4  ((uint32_t)0x30000000)
#define RCC_CFGR_MCO2_PRE_DIV5  ((uint32_t)0x38000000)

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_GPIOAEN     ((uint32_t)0x00000001)
#define RCC_AHB1ENR_GPIOCEN     ((uint32_t)0x00000004)
#define RCC_AHB1ENR_GPIOGEN     ((uint32_t)0x00000040)

/********************  Bit definition for GPIO_MODER register  ****************/
#define GPIO_MODER8_ALTERNATE	((uint32_t)0x00020000)
#define GPIO_MODER9_ALTERNATE   ((uint32_t)0x00080000)
#define GPIO_MODER13_OUTPUT     ((uint32_t)0x04000000)

/********************  Bit definition for GPIO_OTYPER register  ***************/
#define GPIO_OTYPER8_PP         ((uint32_t)0x00000000)
#define GPIO_OTYPER9_PP         ((uint32_t)0x00000000)
#define GPIO_OTYPER13_PP        ((uint32_t)0x00000000)

/********************  Bit definition for GPIO_OSPEED register  ***************/
#define GPIO_OSPEED8_100MHZ	((uint32_t)0x00030000)
#define GPIO_OSPEED9_100MHZ	((uint32_t)0x000C0000)
#define GPIO_OSPEED13_100MHZ    ((uint32_t)0x0C000000)

/********************  Bit definition for GPIO_PUPDR register  ****************/
#define GPIO_PUPDR8_NO          ((uint32_t)0x00000000)
#define GPIO_PUPDR9_NO          ((uint32_t)0x00000000)
#define GPIO_PUPDR13_NO         ((uint32_t)0x00000000)

/********************  Bit definition for GPIO_AFRH register  *****************/
#define GPIO_AFRH8_AF0          ((uint32_t)0x00000000)
#define GPIO_AFRH9_AF0          ((uint32_t)0x00000000)


#endif
