/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	28 JUL 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#include "../../../STM32F103c8_Drivers/MCAL/inc/STM32f103xx_GPIO_driver.h"

/**================================================================
 * @Fn			- Get_CRLH_Position
 * @brief 		- Helper function used to get the position of start bit in register
 * @param [in] 	- Pin_Number [0 --> 16]
 * @retval 		- none
 */
static uint8_t Get_CRLH_Position(uint16_t Pin_Number)
{
	switch (Pin_Number)
	{
	//CRL
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
		//CRH
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
	return 0;
};


/**================================================================
 * @Fn			- GPIO_CloclControl
 * @brief 		- This Function used to Enable or Disable Clock Based on User Input
 * @param [in] 	- GPIO_RegDef_t Which can be GPIO [A,B,C,D]
 * @param [in] 	- Copy_u8Clockstatus Which Contain status of clock {Enable | Disable}
 * @retval 		- ErrorState Value Which can be [OK...NOK]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */

ES_t GPIO_enuPeriClockControl(GPIO_RegDef_t *PGPIOx , uint8_t Copy_u8Clockstatus)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PGPIOx != NULL)
	{
		if (Copy_u8Clockstatus == ENABLE)
		{
			if(PGPIOx == GPIOA)
			{
				GPIOA_PERI_CLOCK_ENABLE();
				Local_enuErrorState = ES_OK;
			}
			else if(PGPIOx == GPIOB)
			{
				GPIOB_PERI_CLOCK_ENABLE();
				Local_enuErrorState = ES_OK;
			}
			else if(PGPIOx == GPIOC)
			{
				GPIOC_PERI_CLOCK_ENABLE();
				Local_enuErrorState = ES_OK;
			}
			else if(PGPIOx == GPIOD)
			{
				GPIOD_PERI_CLOCK_ENABLE();
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_NOK;
			}
		}
		else if (Copy_u8Clockstatus == DISABLE)
		{
			if(PGPIOx == GPIOA)
			{
				GPIOA_PERI_CLOCK_DISABLE();
				Local_enuErrorState = ES_OK;
			}
			else if(PGPIOx == GPIOB)
			{
				GPIOB_PERI_CLOCK_DISABLE();
				Local_enuErrorState = ES_OK;
			}
			else if(PGPIOx == GPIOC)
			{
				GPIOC_PERI_CLOCK_DISABLE();
				Local_enuErrorState = ES_OK;
			}
			else if(PGPIOx == GPIOD)
			{
				GPIOD_PERI_CLOCK_DISABLE();
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_NOK;
			}
		}
		else
		{
			Local_enuErrorState = ES_NOK;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}


/**================================================================
 * @Fn			- GPIO_Init
 * @brief 		- Initializes the GPIOx , PINy according to specified parameters in the Configuration Pin Structure [GPIO_PinConfig_t].
 * @param [in] 	- PGPIOHandle which contian PIN configuration and GPIOx which x can be (A..E depending on device used)
 * @param [out] 	- NONE
 * @retval 		- ErrorState Value Which can be [OK...NOK]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t GPIO_enuInit(GPIO_Handle_t *PGPIOHandle)
{
	ES_t Local_enuErrorState = ES_NOK;
	uint16_t Local_u8PinNumber = PGPIOHandle->GPIO_PinConfig_t.GPIO_PinNumber;
	uint8_t Local_u8PinMode = PGPIOHandle->GPIO_PinConfig_t.GPIO_PinMode;
	__vo uint32_t *Local_Pu32ConfigReg = NULL;

	if(PGPIOHandle != NULL)
	{
		//port configuration register low (GPIOx_CRL)  0>>7
		//port configuration register high (GPIOx_CRH)  8>>15
		Local_Pu32ConfigReg = (Local_u8PinNumber < GPIO_PIN_8)? &PGPIOHandle->PGPIOx->CRL:&PGPIOHandle->PGPIOx->CRH;
		//Clear CNF , MODE
		*Local_Pu32ConfigReg &= ~(0xF << Get_CRLH_Position(Local_u8PinNumber));
		//Check Pin is output or not
		if(Local_u8PinMode  == GPIO_MODE_OUTPUT_AF_OD || Local_u8PinMode == GPIO_MODE_OUTPUT_AF_PP || Local_u8PinMode == GPIO_MODE_OUTPUT_OD ||Local_u8PinMode == GPIO_MODE_OUTPUT_PP)
		{
			//Set CNF8[1:0] MODE8[1:0]
			*Local_Pu32ConfigReg |= ((((Local_u8PinMode - 4)<<2) | ((PGPIOHandle->GPIO_PinConfig_t.GPIO_PinSpeed)&0x0f)))<<Get_CRLH_Position(Local_u8PinNumber);
			Local_enuErrorState = ES_OK;
		}
		//if input mode
		else //MODE = 00
		{
			if(Local_u8PinMode == GPIO_MODE_INPUT_FLO || Local_u8PinMode == GPIO_MODE_ANALOG)
			{
				//Set CNF8[1:0] MODE8[1:0]
				(*Local_Pu32ConfigReg) |= ((((Local_u8PinMode)<<2) | 0x0) &0x0f)<<Get_CRLH_Position(Local_u8PinNumber);
				Local_enuErrorState = ES_OK;
			}
			else if (Local_u8PinMode == GPIO_MODE_INPUT_AF)
			{
				//Set CNF8[1:0] MODE8[1:0] acts as input floating
				(*Local_Pu32ConfigReg) |= ((((GPIO_MODE_INPUT_FLO)<<2) | 0x0) &0x0f)<<Get_CRLH_Position(Local_u8PinNumber);
				Local_enuErrorState = ES_OK;
			}
			else // PULL-UP or PULL-DOWN input
			{
				//Set CNF8[1:0] MODE8[1:0] acts as input floating
				(*Local_Pu32ConfigReg) |= ((((GPIO_MODE_INPUT_PU)<<2) | 0x0) &0x0f)<<Get_CRLH_Position(Local_u8PinNumber);

				if(Local_u8PinMode == GPIO_MODE_INPUT_PU ) // PUT 1 in ODR Register
				{
					PGPIOHandle->PGPIOx->ODR |= Local_u8PinNumber;
				}
				else// PUT 0 in ODR Register
				{
					PGPIOHandle->PGPIOx->ODR &=~ Local_u8PinNumber;
				}

				Local_enuErrorState = ES_OK;
			}
			Local_enuErrorState = ES_OK;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
};
/**================================================================
 * @Fn			- GPIO_DeInit
 * @brief 		- DeInitializes the GPIOx.
 * @param [in] 	- GPIOx which x can be (A..E depending on device used)
 * @param [out] 	- NONE
 * @retval 		- ErrorState Value Which can be [OK for DeInit successfully...NOK for error appears]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t GPIO_enuDeInit(GPIO_RegDef_t *PGPIOx)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PGPIOx != NULL)
	{
		if(PGPIOx == GPIOA)
		{
			GPIOA_REG_RESET();
		}
		else if(PGPIOx == GPIOB)
		{
			GPIOB_REG_RESET();
		}
		else if(PGPIOx == GPIOC)
		{
			GPIOC_REG_RESET();
		}
		else if(PGPIOx == GPIOD)
		{
			GPIOD_REG_RESET();
		}
		else if(PGPIOx == GPIOE)
		{
			GPIOE_REG_RESET();
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
};
/**================================================================
 * @Fn			- GPIO_ReadFromInputPin
 * @brief 		- Read specific pin in the GPIOx according to specified parameters in the Configuration Pin Structure [GPIO_PinConfig_t].
 * @param [in] 	- GPIOx which x can be (A..E depending on device used)
 * @param [in] 	- Copy_u16PinNumber Which Contain Pin Number [0....15]
 * @param [out] 	- *Copy_Pu16PinValue which get the value of specific pin in it
 * @retval 		- ErrorState Value Which can be [OK for get bit successfully ...NOK for errors appear]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t GPIO_enuReadFromInputPin(GPIO_RegDef_t *PGPIOx  , uint16_t Copy_u16PinNumber,uint8_t *Copy_Pu8PinValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PGPIOx != NULL && Copy_Pu8PinValue!=NULL)
	{
		if ((PGPIOx->IDR & Copy_u16PinNumber) != (uint32_t) GPIO_PIN_RESET)
		{
			*Copy_Pu8PinValue = GPIO_PIN_SET;
		}
		else
		{
			*Copy_Pu8PinValue  = GPIO_PIN_RESET;
		}
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
};
/**================================================================
 * @Fn			- GPIO_WriteToOutputPin
 * @brief 		- Write to  specific pin in the GPIOx according to specified parameters in the Configuration Pin Structure [GPIO_PinConfig_t].
 * @param [in] 	- GPIOx which x can be (A..E depending on device used)
 * @param [in] 	- Copy_u16PinNumber Which Contain Pin Number [0....15]
 * @param [in] 	- Copy_Pu16PinValue which contain the value to be written [0..1]
 * @retval 		- ErrorState Value Which can be [OK for write bit successfully ...NOK for errors appear]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t GPIO_enuWriteToOutputPin(GPIO_RegDef_t *PGPIOx  , uint16_t Copy_u16PinNumber , uint8_t Copy_u16PinValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PGPIOx != NULL)
	{
		if( Copy_u16PinValue !=  GPIO_PIN_RESET)
		{
			/*
			 * Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
				These bits are write-only and can be accessed in Word mode only.
				0: No action on the corresponding ODRx bit
				1: Set the corresponding ODRx bits
				t*/
			PGPIOx->BSRR = (uint32_t)Copy_u16PinNumber;
		}
		else
		{
			/*
			 *  Port x Reset bit y (y= 0 .. 15)
				These bits are write-only and can be accessed in Word mode only.
				0: No action on the corresponding ODRx bit
				1: Reset the corresponding ODRx bit
			 */
			PGPIOx->BRR = (uint32_t)Copy_u16PinNumber;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
};
/**================================================================
 * @Fn			- GPIO_ReadFromInputPort
 * @brief 		- Read GPIOx PORT Value
 * @param [in] 	- GPIOx which x can be (A..E depending on device used)
 * @param [out] 	- *Copy_Pu16PinValue which get the value from PORT
 * @retval 		- ErrorState Value Which can be [OK for read port successfully ...NOK for errors appear]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t GPIO_enuReadFromInputPort(GPIO_RegDef_t *PGPIOx , uint16_t *Copy_Pu16PortValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PGPIOx != NULL && Copy_Pu16PortValue != NULL)
	{
		*Copy_Pu16PortValue = PGPIOx->IDR;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
};
/**================================================================
 * @Fn			- GPIO_WriteToOutputPort
 * @brief 		- Write Value to GPIOx PORT
 * @param [in] 	- GPIOx which x can be (A..E depending on device used)
 * @param [in] 	- Copy_Pu16PinValue which contain the value to be written
 * @retval 		- ErrorState Value Which can be [OK for write to PORT successfully ...NOK for errors appear]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t GPIO_enuWriteToOutputPort(GPIO_RegDef_t *PGPIOx , uint16_t Copy_u16PortValue)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PGPIOx != NULL)
	{
		PGPIOx->ODR =  Copy_u16PortValue;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}


	return Local_enuErrorState;
};
/**================================================================
 * @Fn			- GPIO_ToggleOutputPin
 * @brief 		- Write Value to GPIOx PORT
 * @param [in] 	- GPIOx which x can be (A..E depending on device used)
 * @param [in] 	- Copy_u16PinNumber Which Contain Pin Number [0....15]
 * @retval 		- ErrorState Value Which can be [OK pin toggled successfully ...NOK for errors appear]
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t GPIO_enuToggleOutputPin(GPIO_RegDef_t *PGPIOx   , uint16_t Copy_u16PinNumber)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PGPIOx != NULL)
	{
		PGPIOx->ODR ^= Copy_u16PinNumber;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	return Local_enuErrorState;
};
