/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	1 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/


#ifndef MCAL_INC_STM32F103XX_NVIC_DRIVER_H_
#define MCAL_INC_STM32F103XX_NVIC_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"

/*
* ==============================================================================================
* 								APIs Supported by "NVIC DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/
/*> Interrupt_ID That You Send As param  = Position in Vector Table @ref Interrupt_ID */

ES_t MNVIC_enuEnableInterrupt  	( uint8_t Copy_u8InterruptID );

ES_t MNVIC_enuDisableInterrupt 	( uint8_t Copy_u8InterruptID );

ES_t MNVIC_enuSetPending        ( uint8_t Copy_u8InterruptID );

ES_t MNVIC_enuClearPending      ( uint8_t Copy_u8InterruptID );

uint8_t MNVIC_enuGetActive      ( uint8_t Copy_u8InterruptID );

ES_t NVIC_enuSetPriority  (uint8_t Copy_u8InterruptID , uint8_t Copy_u8InterruptPriority);


/*@ref Interrupt_ID
*/
#define 	Interrupt_WWDG                  0
#define 	Interrupt_PVD                   1
#define 	Interrupt_TAMPER                2
#define 	Interrupt_RTC                   3
#define 	Interrupt_FLASH                 4
#define 	Interrupt_RCC_                  5
#define 	Interrupt_EXTI0                 6
#define 	Interrupt_EXTI1                 7
#define 	Interrupt_EXTI2                 8
#define 	Interrupt_EXTI3                 9
#define 	Interrupt_EXTI4              	  10
#define 	Interrupt_DMA1_Channel1      	  11
#define 	Interrupt_DMA1_Channel2         12
#define 	Interrupt_DMA1_Channel3         13
#define 	Interrupt_DMA1_Channel4         14
#define 	Interrupt_DMA1_Channel5      	  15
#define 	Interrupt_DMA1_Channel6      	  16
#define 	Interrupt_DMA1_Channel7     	  17
#define 	Interrupt_ADC1_2            	  18
#define 	Interrupt_USB_HP_CAN_TX0    	  19
#define  	Interrupt_CAN_RX1               21
#define  	Interrupt_CAN_SCE               22
#define     Interrupt_EXTI5                 23
#define     Interrupt_EXTI6                 23
#define     Interrupt_EXTI7                 23
#define     Interrupt_EXTI8                 23
#define     Interrupt_EXTI9                 23
#define  	Interrupt_TIM1_BRK              24
#define  	Interrupt_TIM1_UP               25
#define  	Interrupt_TIM1_TRG_COM          26
#define  	Interrupt_TIM1_CC               27
#define  	Interrupt_TIM2                  28
#define  	Interrupt_TIM3                  29
#define  	Interrupt_TIM4                  30
#define  	Interrupt_I2C1_EV               31
#define  	Interrupt_I2C1_ER               32
#define  	Interrupt_I2C2_EV               33
#define  	Interrupt_I2C2_ER               34
#define  	Interrupt_SPI1                  35
#define  	Interrupt_SPI2                  36
#define  	Interrupt_USART1                37
#define  	Interrupt_USART2                38
#define  	Interrupt_USART3                39
#define  	Interrupt_EXTI10          	  40
#define  	Interrupt_EXTI11            	  40
#define  	Interrupt_EXTI12           	  40
#define  	Interrupt_EXTI13            	  40
#define  	Interrupt_EXTI14            	  40
#define  	Interrupt_EXTI15            	  40
#define  	Interrupt_RTCAlarm              41
#define  	Interrupt_USBWakeup             42
#define  	Interrupt_TIM8_BRK              43
#define  	Interrupt_TIM8_UP               44
#define  	Interrupt_TIM8_TRG_COM          45
#define  	Interrupt_TIM8_CC               46
#define  	Interrupt_ADC3                  47
#define  	Interrupt_FSMC                  48
#define  	Interrupt_SDIO                  49
#define  	Interrupt_TIM5                  50
#define  	Interrupt_SPI3                  51
#define  	Interrupt_UART4                 52
#define  	Interrupt_UART5                 53
#define  	Interrupt_TIM6                  54
#define  	Interrupt_TIM7                  55
#define  	Interrupt_DMA2_Channel1         56
#define  	Interrupt_DMA2_Channel2         57
#define  	Interrupt_DMA2_Channel3         58
#define  	Interrupt_DMA2_Channel4_5       59


#endif /* MCAL_INC_STM32F103XX_NVIC_DRIVER_H_ */
