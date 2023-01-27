/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	15 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/
#ifndef HAL_INC_LED_MAX_H_
#define HAL_INC_LED_MAX_H_
#include "Stm32f103x6.h"
/*
* ==============================================================================================
* 								Configuration LED_MAX Structure.
* ==============================================================================================
*/
typedef struct
{
	//Note That The LSB is ROW0_PIN and MSB is ROW7_PIN
	uint16_t LED_MRX_ROWS_PINs[8];
	//Note That The LSB is ROW0_PORT and MSB is ROW7_PORT
	GPIO_RegDef_t *LED_MRX_ROWS_PORTs[8];
	//Note That The LSB is COL0_PIN and MSB is COL7_PIN
	uint16_t LED_MRX_COLS_PINs[8];
	//Note That The LSB is COL0_PORT and MSB is COL7_PORT
	GPIO_RegDef_t *LED_MRX_COLS_PORTs[8];

}LED_MRX_Handle_t;
/*
* ==============================================================================================
* 								APIs Supported by "LED_MATRIX DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/
void HLED_MRX_voidInit(LED_MRX_Handle_t *LED_MRX_Handle);
void HLED_MRX_voidDisplay(LED_MRX_Handle_t *LED_MRX_Handle,uint8_t *Copy_u8Data);
#endif
