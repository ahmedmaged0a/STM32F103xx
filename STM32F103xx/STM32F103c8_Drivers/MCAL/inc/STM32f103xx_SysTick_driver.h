/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	13 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef MCAL_INC_STM32F103XX_SYSTICK_DRIVER_H_
#define MCAL_INC_STM32F103XX_SYSTICK_DRIVER_H_

#include "STM32F103x8.h"
/*
* ==============================================================================================
* 								APIs Supported by "SysTick DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/

/*<<Specifies the Copy_u8Clock to be configured based on @ref Sys_AHB_define .>>*/
ES_t MSTK_enuInit (uint8_t Copy_u8Clock);

ES_t MSTK_enuSetBusyWait (uint32_t Copy_u32Ticks);

ES_t MSTK_enuSetIntervalSingle (uint32_t Copy_u32Ticks , void (*Copy_Vptr)(void));

ES_t MSTK_enuSetIntervalPeriodic (uint32_t Copy_u32Ticks , void (*Copy_Vptr)(void));

ES_t MSTK_enuStopInterval (void);

ES_t MSTK_enuGetElapsedTime (uint32_t *Copy_Pu32Time);

ES_t MSTK_enuGetRemainigTime (uint32_t *Copy_Pu32Time);

void _delay_ms(uint32_t Copy_u32Time);

//@ref Sys_AHB_define
#define SYS_AHB_0		0
#define SYS_AHB_8		8

#endif /* MCAL_INC_STM32F103XX_SYSTICK_DRIVER_H_ */
