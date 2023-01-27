/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	1 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/


#ifndef MCAL_INC_STM32F103XX_RCC_DRIVER_H_
#define MCAL_INC_STM32F103XX_RCC_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"
/*
* ==============================================================================================
* 								Configuration RCC.
* ==============================================================================================
*/

#define RCC_CLOCK_TYPE	RCC_HSE		/*<<Specifies the RCC to be configured based on @ref RCC_ClockType.>>*/

#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT  RCC_PLL_IN_HSI_DIV_2	/*<<Select value only if you have PLL as input clock source based on @ref RCC_PLLINPUT. >>*/
#endif

#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL  NO_CLOCK_FACTOR 	/*<<Select value only if you have PLL as input clock source based on @ref RCC_MULVAL.>>*/
#endif

#define CLOCK_SEQURITY_SYSTEM		DISABLE
//================================================================================================



/*
* ==============================================================================================
* 								@ref RCC_ClockType.
* 								Here You Can Select You Clock Type.
* ==============================================================================================
*/
#define RCC_HSI				0
#define RCC_HSE				1
#define RCC_HSE_BYPASS		2
#define RCC_PLL				3

/*
* ==============================================================================================
* 								@ref RCC_PLL_INPUT.
* 								Here You Can Select You PLL input.
* ==============================================================================================
*/
#define RCC_PLL_IN_HSI_DIV_2	0
#define RCC_PLL_IN_HSE_DIV_2	1
#define RCC_PLL_IN_HSE			2

/*
* ==============================================================================================
* 								@ref RCC_MULVAL.
* 								Here You Can Select You PLL_MUL Value.
* ==============================================================================================
*/
#define NO_CLOCK_FACTOR              0X0
#define PLL_Clock_MULTIPLE_BY_4      0X1
#define PLL_Clock_MULTIPLE_BY_5      0X3
#define PLL_Clock_MULTIPLE_BY_6      0X4
#define PLL_Clock_MULTIPLE_BY_7      0X5
#define PLL_Clock_MULTIPLE_BY_8      0X6
#define PLL_Clock_MULTIPLE_BY_9      0X7

/*
* ==============================================================================================
* 								APIs Supported by "MCAL RCC DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/
ES_t RCC_enuInitConfig(void);
#endif /* MCAL_INC_STM32F103XX_RCC_DRIVER_H_ */
