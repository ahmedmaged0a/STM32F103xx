/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	1 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#include "STM32f103xx_EXTI_driver.h"

/*
* ==============================================================================================
*										Pointer to UserFunction From (APP Layer)
* ==============================================================================================
*/

static void (*EXTI0_pCallBack)(void);
static void (*EXTI1_pCallBack)(void);
static void (*EXTI2_pCallBack)(void);
static void (*EXTI3_pCallBack)(void);
static void (*EXTI4_pCallBack)(void);
static void (*EXTI5_pCallBack)(void);
static void (*EXTI6_pCallBack)(void);
static void (*EXTI7_pCallBack)(void);
static void (*EXTI8_pCallBack)(void);
static void (*EXTI9_pCallBack)(void);
static void (*EXTI10_pCallBack)(void);
static void (*EXTI11_pCallBack)(void);
static void (*EXTI12_pCallBack)(void);
static void (*EXTI13_pCallBack)(void);
static void (*EXTI14_pCallBack)(void);
static void (*EXTI15_pCallBack)(void);
/**================================================================
 * @Fn			- EXTI_enuInitConfig
 * @brief 		- This Function used to Initialize the Configuration for External Interrupt
 * @param [in] 	- Copy_EXTHandle Which contain the configuration
 * @retval 		- ErrorState which indicates that function works without errors
 * Note			-Stm32f103C6 MCU has  GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external pins from MCU
 */
ES_t  EXTI_enuInitConfig   		(EXTI_Config_t * Copy_EXTHandle)
{
	ES_t Local_enuErrorState = ES_NOK;
	uint8_t Local_u8EXTILine = Copy_EXTHandle->EXTI_u8LineNumber;
	uint8_t  Local_u8PortCode  = EXTI_GPIOx_TO_CODE(Copy_EXTHandle->EXTI_PportNumber);
	//Check That's no NULL Pointer
	if(Copy_EXTHandle != NULL)
	{
		//Make GPIO pin Configure as Alternative External Interrupt using AFIO
		//Enable AFIO clock
		AFIO_PERI_CLOCK_ENABLE();
		if(Local_u8EXTILine <= 3 )
		{
			//External interrupt configuration register 1
			//EXTIx[3:0]: EXTI x configuration (x= 0 to 3)
			AFIO->EXTICR1 &=~  (0xF << ((Local_u8EXTILine % 4) * 4));
			AFIO->EXTICR1 |= (Local_u8PortCode <<((Local_u8EXTILine % 4) * 4));

		}
		else if (Local_u8EXTILine <= 7 )
		{
			//External interrupt configuration register 1
			//EXTIx[3:0]: EXTI x configuration (x= 4 to 7)
			AFIO->EXTICR2 &=~  (0xF << ((Local_u8EXTILine % 4) * 4));
			AFIO->EXTICR2 |= (Local_u8PortCode <<((Local_u8EXTILine % 4) * 4));
		}
		else if (Local_u8EXTILine <= 11 )
		{
			//External interrupt configuration register 1
			//EXTIx[3:0]: EXTI x configuration (x= 8 to 11)
			AFIO->EXTICR3 &=~  (0xF << ((Local_u8EXTILine % 4) * 4));
			AFIO->EXTICR3 |= (Local_u8PortCode <<((Local_u8EXTILine % 4) * 4));
		}
		else if (Local_u8EXTILine <= 15 )
		{
			//External interrupt configuration register 1
			//EXTIx[3:0]: EXTI x configuration (x= 12 to 15)
			AFIO->EXTICR4 &=~  (0xF << ((Local_u8EXTILine % 4) * 4));
			AFIO->EXTICR4 |= (Local_u8PortCode <<((Local_u8EXTILine % 4) * 4));
		}
		switch(Copy_EXTHandle->EXTI_u8TriggerMode)
		{
		//Configure sense Control as Falling
		case EXTI_TRIGGER_FALLING:
			EXTI->FTSR |= (1<<Local_u8EXTILine);
			EXTI->RTSR &=~ (1<<Local_u8EXTILine);
			break;
			//Configure sense Control as Rising
		case EXTI_TRIGGER_RISHING:
			EXTI->FTSR &=~ (1<<Local_u8EXTILine);
			EXTI->RTSR |=  (1<<Local_u8EXTILine);
			break;
			//Configure sense Control as Rising&Falling
		case EXTI_TRIGGER_ONCHANGE:
			EXTI->FTSR |= (1<<Local_u8EXTILine);
			EXTI->RTSR |=  (1<<Local_u8EXTILine);
			break;
		}
		//Interrupt Mask on line x
		EXTI->IMR |= (1<<Local_u8EXTILine);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- EXTI_enuEnableMask
 * @brief 		- This Function used to Enable Interrupt Mask on line Copy_u8EXTILine
 * @param [in] 	- Copy_u8EXTILine it is the interrupt Line
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t  EXTI_enuEnableMask   		(uint8_t Copy_u8EXTILine)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8EXTILine <= 15)
	{
		//Interrupt Mask on line Copy_u8EXTILine
		EXTI->IMR |= (1<<Copy_u8EXTILine);
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- EXTI_enuDisableMask
 * @brief 		- This Function used to Disable Interrupt Mask on line Copy_u8EXTILine
 * @param [in] 	- Copy_u8EXTILine it is the interrupt Line
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t  EXTI_enuDisableMask  		(uint8_t Copy_u8EXTILine)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8EXTILine <= 15)
	{
		//Interrupt Mask (off) line Copy_u8EXTILine
		EXTI->IMR &=~ (1<<Copy_u8EXTILine);
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- EXTI_enuSoftWareTrigger
 * @brief 		- This Function used to Enable Software Trigger on EXT_LINE Copy_u8EXTILine
 * @param [in] 	- Copy_u8EXTILine which is the External interrupt Line
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t  EXTI_enuSoftWareTrigger	(uint8_t Copy_u8EXTILine)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8EXTILine <= 15)
	{
		// SWIERx: Software interrupt on line Copy_u8EXTILine
		EXTI->SWIER |= (1<<Copy_u8EXTILine);
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}
//=============================================================================================
/*
 * @Fn			- EXTx_enuCallBack
 * @brief 		- Used To Get Action With Function Called From APP Layers when interrupt happened
 * @param [in] 	- Copy_Vptr Which Contain the Address of UserFunction
 * @retval 		- ErrorState which indicates that function works without errors
 */
//=============================================================================================
ES_t  EXTI0_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI0_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI0_IRQHandler(void){

	EXTI0_pCallBack();
	EXTI->PR |= (1<<0);

}
ES_t  EXTI1_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI1_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI1_IRQHandler(void){

	EXTI1_pCallBack();
	EXTI->PR |= (1<<1);

}
ES_t  EXTI2_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI2_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI2_IRQHandler(void){

	EXTI2_pCallBack();
	EXTI->PR |= (1<<2);

}
ES_t  EXTI3_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI3_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI3_IRQHandler(void){

	EXTI3_pCallBack();
	EXTI->PR |= (1<<3);

}
ES_t  EXTI4_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI4_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI4_IRQHandler(void){

	EXTI4_pCallBack();
	EXTI->PR |= (1<<4);

}
ES_t  EXTI5_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI5_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}
void EXTI5_IRQHandler(void){

	EXTI5_pCallBack();
	EXTI->PR |= (1<<5);

}
ES_t  EXTI6_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI6_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI6_IRQHandler(void){

	EXTI6_pCallBack();
	EXTI->PR |= (1<<6);

}
ES_t  EXTI7_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI7_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI7_IRQHandler(void){

	EXTI7_pCallBack();
	EXTI->PR |= (1<<7);

}
ES_t  EXTI8_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI8_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI8_IRQHandler(void){

	EXTI8_pCallBack();
	EXTI->PR |= (1<<8);

}
ES_t  EXTI9_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI9_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI9_IRQHandler(void){

	EXTI9_pCallBack();
	EXTI->PR |= (1<<9);

}
ES_t  EXTI10_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI10_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI10_IRQHandler(void){

	EXTI10_pCallBack();
	EXTI->PR |= (1<<10);

}
ES_t  EXTI11_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI11_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI11_IRQHandler(void){

	EXTI11_pCallBack();
	EXTI->PR |= (1<<11);

}
ES_t  EXTI12_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI12_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI12_IRQHandler(void){

	EXTI12_pCallBack();
	EXTI->PR |= (1<<12);

}
ES_t  EXTI13_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI13_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI13_IRQHandler(void){

	EXTI13_pCallBack();
	EXTI->PR |= (1<<13);

}
ES_t  EXTI14_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI14_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI14_IRQHandler(void){

	EXTI14_pCallBack();
	EXTI->PR |= (1<<14);

}
ES_t  EXTI15_enuCallBack   		(void (*Copy_Vptr) (void))
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Vptr != NULL)
	{
		EXTI15_pCallBack = Copy_Vptr;
		Local_enuErrorState = ES_OK;
	}
	return Local_enuErrorState;
}
void EXTI15_IRQHandler(void){

	EXTI15_pCallBack();
	EXTI->PR |= (1<<15);

}
