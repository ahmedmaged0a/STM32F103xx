/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	26 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

/**================================================================
 * @Fn			- STP_enuInit
 * @brief 		- This Function Used To Initialize pins which connected to [Data , Clock Shift,Clock Store]
 * @param [in] 	- Copy_PstrHandle Which Handle Pins And Port
 * @retval 		- Error State to Check That Function Works Without Error
 */
#include "../../../STM32F103c8_Drivers/HAL/inc/STP_74HC595.h"

#include "../../../STM32F103c8_Drivers/MCAL/inc/STM32f103xx_SysTick_driver.h"
ES_t STP_enuInit(STP_strHandle *Copy_PstrHandle)
{
	ES_t Local_enuErrorState = ES_NOK;
	GPIO_Handle_t PIN_Config;
	if(Copy_PstrHandle != NULL)
	{
		//For Data pin in HC74HC595
			PIN_Config.PGPIOx = Copy_PstrHandle->STP_PortConfig.STP_u8SDataPort;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = Copy_PstrHandle->STP_PinConfig.STP_u8SDataPin;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
			GPIO_enuInit(&PIN_Config);
		//For Shift Clock pin in HC74HC595
			PIN_Config.PGPIOx = Copy_PstrHandle->STP_PortConfig.STP_u8ShClockPort;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = Copy_PstrHandle->STP_PinConfig.STP_u8ShClockPin;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
			GPIO_enuInit(&PIN_Config);
		//For Shift Clock pin in HC74HC595
			PIN_Config.PGPIOx = Copy_PstrHandle->STP_PortConfig.STP_u8StClockPort;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = Copy_PstrHandle->STP_PinConfig.STP_u8StClockPin;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
			PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
			GPIO_enuInit(&PIN_Config);

			Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
}


ES_t STP_enuSendSynchronus(STP_strHandle *Copy_PstrHandle,uint8_t Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;
		int8_t Local_s8Iterator=0;
		uint8_t Local_u8BitNum=0;
		for(Local_s8Iterator = 7 ; Local_s8Iterator >=0;Local_s8Iterator--)
		{
			//Send Data From STM Data Pin to IC_74HC595 (bit by bit)
			Local_u8BitNum = (1&(Copy_u8Data >> Local_s8Iterator));
			GPIO_enuWriteToOutputPin(Copy_PstrHandle->STP_PortConfig.STP_u8SDataPort, Copy_PstrHandle->STP_PinConfig.STP_u8SDataPin,Local_u8BitNum);

			//Shift Bits From LSB TO MSB By Send Pulse to shift register
			GPIO_enuWriteToOutputPin(Copy_PstrHandle->STP_PortConfig.STP_u8ShClockPort, Copy_PstrHandle->STP_PinConfig.STP_u8ShClockPin,SET);
			MSTK_enuSetBusyWait(10);
			GPIO_enuWriteToOutputPin(Copy_PstrHandle->STP_PortConfig.STP_u8ShClockPort, Copy_PstrHandle->STP_PinConfig.STP_u8ShClockPin,RESET);
			MSTK_enuSetBusyWait(10);
		}
		//Store Bits to physical pins By send pulse to store register
		GPIO_enuWriteToOutputPin(Copy_PstrHandle->STP_PortConfig.STP_u8StClockPort, Copy_PstrHandle->STP_PinConfig.STP_u8StClockPin,SET);
		MSTK_enuSetBusyWait(10);
		GPIO_enuWriteToOutputPin(Copy_PstrHandle->STP_PortConfig.STP_u8StClockPort, Copy_PstrHandle->STP_PinConfig.STP_u8StClockPin,RESET);
		MSTK_enuSetBusyWait(10);
	return Local_enuErrorState;
}
