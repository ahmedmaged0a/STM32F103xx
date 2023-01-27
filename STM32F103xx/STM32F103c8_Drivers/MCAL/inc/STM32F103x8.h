/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	28 JUL 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef INCLUDE_STM32F103X6_H_
#define INCLUDE_STM32F103X6_H_

#define __vo	volatile
//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include "stdint.h"

//-----------------------------
//Base addresses for Core Peripherals
//-----------------------------
#define NVIC_BASE 			(0xE000E100)
#define SCB_BASE			(0xE000ED00)
#define SYSTICK_BASE		(0xE000E010)
/**********************************START:Processor Specific Details **********************************/

//================================= NVIC =============================================
/*
 * ARM Cortex Mx Processor NVIC ISERx register Addresses
 */

#define NVIC_ISER		((__vo uint32_t *)NVIC_BASE)
/*
 * ARM Cortex Mx Processor NVIC ICERx register Addresses
 */
#define NVIC_ICER		((__vo uint32_t *)NVIC_BASE+0x080)
/*
 * ARM Cortex Mx Processor NVIC ISPRx register Addresses
 */
#define NVIC_ISPR		((__vo uint32_t *)NVIC_BASE+0x100)
/*
 * ARM Cortex Mx Processor NVIC ICPRx register Addresses
 */
#define NVIC_ICPR		((__vo uint32_t *)NVIC_BASE+0x180)
/*
 * ARM Cortex Mx Processor NVIC IABRx register Addresses
 */
#define NVIC_IABR		((__vo uint32_t *)NVIC_BASE+0x200)
/*
 * ARM Cortex Mx Processor NVIC IPRx register Addresses
 */
#define NVIC_IPR		((__vo uint32_t *)NVIC_BASE+0x300)

//================================= SCB ==============================================
/*
 * ARM Cortex Mx Processor SCB AIRCR register Addresses
 */
#define SCB_AIRCR		*((__vo uint32_t *)SCB_BASE+0x0C)

//================================= SysTick =============================================
typedef struct
{
	__vo uint32_t	CTRL;							// Address offset = 0x00
	__vo uint32_t	LOAD;						    // Address offset = 0x04
	__vo uint32_t	VAL;						    // Address offset = 0x08
	__vo uint32_t	CALIB;					        // Address offset = 0x0C

}SysTick_RegDef_t;

#define	SYSTICK		((SysTick_RegDef_t *)SYSTICK_BASE)
/**********************************END:Processor Specific Details **********************************/
//0xE000 E010
//-----------------------------
//Base addresses for Memories
//-----------------------------

#define FLASH_MEMORY_BASE						0x08000000UL
#define SYS_MEMORY_BASE							0x1FFFF000UL
#define SRAM_MEMORY_BASE						0x20000000UL

#define CORTEX_M3_INTERNAL_PERIPHRALS_BASE		0XE0000000UL

//-----------------------------
//Base addresses for BUS Peripherals
//-----------------------------
#define PERIPHRALS_BASE									0x40000000UL
#define APB1_PREPHERALS_BASE							PERIPHRALS_BASE
#define APB2_PREPHERALS_BASE							0x40010000UL
#define AHB_PREPHERALS_BASE								0x40018000UL

//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------

#define RCC_BASE			(AHB_PREPHERALS_BASE+0x9000U)
#define DMA1_BASE			(PERIPHRALS_BASE+0x20000U)
//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------

//-------AFIO-------
#define AFIO_BASE			(APB2_PREPHERALS_BASE)
//-------EXTI-------
#define EXTI_BASE			(APB2_PREPHERALS_BASE+0x0400U)
//-------GPIO-------
#define GPIOA_BASE			(APB2_PREPHERALS_BASE+0x0800U)
#define GPIOB_BASE			(APB2_PREPHERALS_BASE+0x0C00U)
#define GPIOC_BASE			(APB2_PREPHERALS_BASE+0x1000U)
#define GPIOD_BASE			(APB2_PREPHERALS_BASE+0x1400U)
#define GPIOE_BASE			(APB2_PREPHERALS_BASE+0x1800U)

//-----------------------------
//Base addresses for APB1 Peripherals
//-----------------------------


//=======================================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register: struct
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-------RCC_REG-------
typedef struct
{
	__vo uint32_t	CR;											// Address offset = 0x00
	__vo uint32_t	CFGR;										// Address offset = 0x04
	__vo uint32_t	CIR;										// Address offset = 0x08
	__vo uint32_t	APB2RSTR;									// Address offset = 0x0C
	__vo uint32_t	APB1RSTR;									// Address offset = 0x10
	__vo uint32_t	AHBENR;										// Address offset = 0x14
	__vo uint32_t	APB2ENR;									// Address offset = 0x18
	__vo uint32_t	APB1ENR;									// Address offset = 0x1C
	__vo uint32_t	BDCR;										// Address offset = 0x20

}RCC_RegDef_t;

//-------GPIO_REG-------
typedef struct
{
	__vo uint32_t	CRL;										// Address offset = 0x00
	__vo uint32_t	CRH;										// Address offset = 0x04
	__vo uint32_t	IDR;    									// Address offset = 0x08
	__vo uint32_t	ODR;										// Address offset = 0x0C
	__vo uint32_t	BSRR;										// Address offset = 0x10
	__vo uint32_t	BRR;										// Address offset = 0x14
	__vo uint32_t	LCKR;										// Address offset = 0x18

}GPIO_RegDef_t;

//-------AFIO_REG-------
typedef struct
{
	__vo uint32_t	EVCR;										// Address offset = 0x00
	__vo uint32_t	MAPR;										// Address offset = 0x04
	__vo uint32_t	EXTICR1;									// Address offset = 0x08
	__vo uint32_t	EXTICR2;									// Address offset = 0x0C
	__vo uint32_t	EXTICR3;									// Address offset = 0x10
	__vo uint32_t	EXTICR4;									// Address offset = 0x14
	uint32_t	RESERVED_1;									// Address offset = 0x18
	__vo uint32_t	MAPR2;										// Address offset = 0x1C

}AFIO_RegDef_t;

//-------EXTI_REG-------
typedef struct
{
	__vo uint32_t	IMR;										// Address offset = 0x00
	__vo uint32_t	EMR;										// Address offset = 0x04
	__vo uint32_t	RTSR;										// Address offset = 0x08
	__vo uint32_t	FTSR;										// Address offset = 0x0C
	__vo uint32_t	SWIER;										// Address offset = 0x10
	__vo uint32_t	PR;											// Address offset = 0x14

}EXTI_RegDef_t;


//-------GPIO_REG-------
/*
 * Note Address offset = (DMA_BASE+OFFSIT)+ 0x14 × (channel number – 1)
 * */
typedef struct
{
	__vo uint32_t  CCRx ;      					                // Address offset = 0x00
	__vo uint32_t  CNDTRx;									    // Address offset = 0x04
	__vo uint32_t  CPARx;									    // Address offset = 0x08
	__vo uint32_t  CMARx;									    // Address offset = 0x0C
	__vo uint32_t  Reserved;									    // Address offset = 0x10
}DMA1_Channel;
typedef struct
{
	__vo uint32_t  ISR ;      					                // Address offset = 0x08
	__vo uint32_t  IFCR;									    // Address offset = 0x0C
	DMA1_Channel  CHANNEL[7];									// Address offset = 0x10
}DMA1_RegDef_t;
//============================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-------GPIO-------
#define GPIOA				((GPIO_RegDef_t *)GPIOA_BASE)
#define GPIOB				((GPIO_RegDef_t *)GPIOB_BASE)
#define GPIOC				((GPIO_RegDef_t *)GPIOC_BASE)
#define GPIOD				((GPIO_RegDef_t *)GPIOD_BASE)
#define GPIOE				((GPIO_RegDef_t *)GPIOE_BASE)
//-------RCC-------
#define RCC					((RCC_RegDef_t *)RCC_BASE)
//-------EXTI-------
#define EXTI				((EXTI_RegDef_t *)EXTI_BASE)
//-------AFIO-------
#define AFIO				((AFIO_RegDef_t *)AFIO_BASE)
//-------AFIO-------
#define DMA				     ((DMA1_RegDef_t *)DMA1_BASE)
//============================================================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-------GPIO-------
#define GPIOA_PERI_CLOCK_ENABLE()		(RCC->APB2ENR |= (1<<2))
#define GPIOB_PERI_CLOCK_ENABLE()		(RCC->APB2ENR |= (1<<3))
#define GPIOC_PERI_CLOCK_ENABLE()		(RCC->APB2ENR |= (1<<4))
#define GPIOD_PERI_CLOCK_ENABLE()		(RCC->APB2ENR |= (1<<5))
#define GPIOE_PERI_CLOCK_ENABLE()		(RCC->APB2ENR |= (1<<6))

//-------AFIO-------
#define AFIO_PERI_CLOCK_ENABLE()		(RCC->APB2ENR |=(1<<0))

//------DMA---------
#define DMA_PERI_CLOCK_ENABLE()			(RCC->AHBENR |= (1<<0))
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//macros to reset GPIOx Peripherals:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

#define GPIOA_REG_RESET() do{ (RCC->APB2RSTR |= (1<<2)); (RCC->APB2RSTR &= ~ (1<<2)); }while(0)
#define GPIOB_REG_RESET() do{ (RCC->APB2RSTR |= (1<<3)); (RCC->APB2RSTR &= ~ (1<<3)); }while(0)
#define GPIOC_REG_RESET() do{ (RCC->APB2RSTR |= (1<<4)); (RCC->APB2RSTR &= ~ (1<<4)); }while(0)
#define GPIOD_REG_RESET() do{ (RCC->APB2RSTR |= (1<<5)); (RCC->APB2RSTR &= ~ (1<<5)); }while(0)
#define GPIOE_REG_RESET() do{ (RCC->APB2RSTR |= (1<<6)); (RCC->APB2RSTR &= ~ (1<<6)); }while(0)


//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//clock disable Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//-------GPIO-------
#define GPIOA_PERI_CLOCK_DISABLE()		(RCC->APB2ENR &=~ (1<<2))
#define GPIOB_PERI_CLOCK_DISABLE()		(RCC->APB2ENR &=~ (1<<3))
#define GPIOC_PERI_CLOCK_DISABLE()		(RCC->APB2ENR &=~ (1<<4))
#define GPIOD_PERI_CLOCK_DISABLE()		(RCC->APB2ENR &=~ (1<<5))
#define GPIOE_PERI_CLOCK_DISABLE()		(RCC->APB2ENR &=~ (1<<6))

//-------AFIO-------
#define AFIO_PERI_CLOCK_DISABLE()		(RCC->APB2ENR &=~0)

//------DMA---------
#define DMA_PERI_CLOCK_DISABLE()		(RCC->AHBENR &=~ (1<<0))

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Error States:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
typedef enum
{
	ES_NOK,
	ES_OK,
	ES_NULL_POINTER,
	ES_OUTOFRANGE
}ES_t;

typedef enum
{
	ES_GPIO_LOCK_ERROR,
	ES_GPIO_LOCKED
}ELOCK_t;


/*
 * Returns PORTx Code for given GPIOx base Address
 * */
#define EXTI_GPIOx_TO_CODE(x)	((x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:\
								(x==GPIOE)?4:0)

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
//Generic[Private] Macros:
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

//Macros For SCB Register
#define NVIC_GROUP_4_SUB_0		 0x05FA0300
#define NVIC_GROUP_3_SUB_1		 0x05FA0400
#define NVIC_GROUP_2_SUB_2		 0x05FA0500
#define NVIC_GROUP_1_SUB_3		 0x05FA0600
#define NVIC_GROUP_0_SUB_4		 0x05FA0700

#define NO_PRIORTY_BITS_IMP		4

#define STK_PERIODIC 			1
#define STK_SINGLE 				0

#define ENABLE 				 1
#define DISABLE 			 0
#define SET					 ENABLE
#define RESET 	 	 		 DISABLE
#define GPIO_PIN_SET		 SET
#define GPIO_PIN_RESET 		 RESET

#define  DMA_GIF    0
#define  DMA_TCIF   1
#define  DMA_HTIF   2
#define  DMA_TEIF   3

#define  DMA_TCIE   1
#define  DMA_HTIE   2
#define  DMA_TEIE   3

#define DMA1_ENABLE  0
#define DMA1_DISABLE 1

#endif /* INCLUDE_STM32F103X6_H_ */
