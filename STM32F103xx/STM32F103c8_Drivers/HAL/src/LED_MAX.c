/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	15 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/
#include "../../../STM32F103c8_Drivers/HAL/inc/LED_MAX.h"

#include "../../../STM32F103c8_Drivers/Include/MACROS.h"
#include "../../../STM32F103c8_Drivers/MCAL/inc/STM32f103xx_GPIO_driver.h"
#include "../../../STM32F103c8_Drivers/MCAL/inc/STM32f103xx_SysTick_driver.h"
#include "../../MCAL/inc/STM32F103x8.h"
/*
 * ==============================================================================================
 * 								Helper Functions {Private}
 * ==============================================================================================
 */
static void SetRowsValues(LED_MRX_Handle_t *LED_MRX_Handle,uint8_t Copy_u8Data);
static void DisableAllColumns(LED_MRX_Handle_t *LED_MRX_Handle);

/**================================================================
 * @Fn			- HLED_MRX_voidInit
 * @brief 		- This Function used to Initialize the Configuration for LED Matrix Columns and Rows
 * @param [in] 	- LED_MRX_Handle Which contain the configuration
 * @retval 		- none
 */
void HLED_MRX_voidInit(LED_MRX_Handle_t *LED_MRX_Handle)
{
	GPIO_Handle_t PIN_Config;
	uint8_t Local_u8Iterator = 0;
	/*
	 * ==============================================================================================
	 * 								ROWS_Setup
	 * ==============================================================================================
	 */
	for(Local_u8Iterator = 0 ; Local_u8Iterator<8 ; Local_u8Iterator++)
	{
		/*ROW[Local_u8Iterator] Configuration*/
		PIN_Config.PGPIOx = LED_MRX_Handle->LED_MRX_ROWS_PORTs[Local_u8Iterator];
		PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = LED_MRX_Handle->LED_MRX_ROWS_PINs[Local_u8Iterator];
		PIN_Config.GPIO_PinConfig_t.GPIO_PinMode =GPIO_MODE_OUTPUT_PP;
		PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed=GPIO_SPEED_2M;
		GPIO_enuInit(&PIN_Config);
	}
	/*
	 * ==============================================================================================
	 * 								Columns_Setup
	 * ==============================================================================================
	 */
	for(Local_u8Iterator = 0 ; Local_u8Iterator<8 ; Local_u8Iterator++)
	{
		/*COL[Local_u8Iterator] Configuration*/
		PIN_Config.PGPIOx = LED_MRX_Handle->LED_MRX_COLS_PORTs[Local_u8Iterator];
		PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = LED_MRX_Handle->LED_MRX_COLS_PINs[Local_u8Iterator];
		PIN_Config.GPIO_PinConfig_t.GPIO_PinMode =GPIO_MODE_OUTPUT_PP;
		PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed=GPIO_SPEED_2M;
		GPIO_enuInit(&PIN_Config);
	}

}
/**================================================================
 * @Fn			- HLED_MRX_voidDisplay
 * @brief 		- This Function used to Display Values on LED Matrix
 * @param [in] 	- LED_MRX_Handle Which contain the configuration
 * @param [in] 	- Copy_u8Data Which contain Data need to Display
 * @retval 		- none
 */
void HLED_MRX_voidDisplay(LED_MRX_Handle_t *LED_MRX_Handle,uint8_t *Copy_u8Data)
{
	uint8_t Local_u8Iterator = 0;
	while(1)
	{
		for(Local_u8Iterator=0; Local_u8Iterator <8 ; Local_u8Iterator++)
		{
			//Disable all columns by set {HIGH}
			DisableAllColumns(LED_MRX_Handle);
			//Display Rows Values
			SetRowsValues(LED_MRX_Handle, Copy_u8Data[Local_u8Iterator]);
			//Enable Column [i]
			GPIO_enuWriteToOutputPin(LED_MRX_Handle->LED_MRX_COLS_PORTs[Local_u8Iterator], LED_MRX_Handle->LED_MRX_COLS_PINs[Local_u8Iterator], GPIO_PIN_RESET);
			//Delay 2.5ms
			MSTK_enuSetBusyWait(2500);
		}
	}

}
/**================================================================
 * @Fn			- SetRowsValues[Which is private function]
 * @brief 		- This Function used to Display Values on Rows
 * @param [in] 	- LED_MRX_Handle Which contain the configuration
 * @param [in] 	- Copy_u8Data Which contain Data need to Display
 * @retval 		- none
 */
static void SetRowsValues(LED_MRX_Handle_t *LED_MRX_Handle,uint8_t Copy_u8Data)
{
	uint8_t Local_u8Iterator = 0;
	uint8_t Local_u8BIT=0;
	for(Local_u8Iterator=0; Local_u8Iterator <8 ; Local_u8Iterator++)
	{
		Local_u8BIT = GET_BIT(Copy_u8Data,Local_u8Iterator);
		GPIO_enuWriteToOutputPin(LED_MRX_Handle->LED_MRX_ROWS_PORTs[Local_u8Iterator], LED_MRX_Handle->LED_MRX_ROWS_PINs[Local_u8Iterator],Local_u8BIT);
	}

}
/**================================================================
 * @Fn			- DisableAllColumns[Which is private function]
 * @brief 		- This Function used to Disable All Columns
 * @param [in] 	- LED_MRX_Handle Which contain the configuration
 * @retval 		- none
 */
static void DisableAllColumns(LED_MRX_Handle_t *LED_MRX_Handle)
{
	uint8_t Local_u8Iterator = 0;
	for(Local_u8Iterator=0; Local_u8Iterator <8 ; Local_u8Iterator++)
	{
		GPIO_enuWriteToOutputPin(LED_MRX_Handle->LED_MRX_COLS_PORTs[Local_u8Iterator], LED_MRX_Handle->LED_MRX_COLS_PINs[Local_u8Iterator], GPIO_PIN_SET);

	}

}
