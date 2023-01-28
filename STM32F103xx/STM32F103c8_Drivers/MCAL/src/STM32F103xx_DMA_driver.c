/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	22 DEC 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/
#include"MACROS.h"
#include "STM32F103x8.h"
#include "STM32F103xx_DMA_driver.h"
/*
 * ==============================================================================================
 * 								Helper Functions {Private}
 * ==============================================================================================
 */
static void DMA_SvidClearFlag (uint8_t Copy_u8ChannelNumber,uint8_t Copy_u8Flag);
/*
 * ==============================================================================================
 * 								CallBack For Channel 1
 * ==============================================================================================
 */
void ( *DMA_CallBackChannel1 )( void );
/**================================================================
 * @Fn			- DMA_enuConfigurationSetup
 * @brief 		- This Function used to make a configuration setup entered by user from application layer
 * @param [in] 	- PDMAHandle Which contain the configuration
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t DMA_enuConfigurationSetup (DMA_Handle_t *PDMAHandle)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(PDMAHandle != NULL)
	{
		//Disable DMA Before Setup the Configuation
		//Address offset: 0x08 + 0d20 × (channel number – 1)
		CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,0);
		/*
		* ==============================================================================================
		* 							Start Configuration Setup
		* ==============================================================================================
		*/

		//1-Directions
		switch(PDMAHandle->DMA1_Direction)
		{
		case MEM_TO_MEM :
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,14);
			break;
		case PREI_TO_MEM:
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,4);
			break;
		case MEM_TO_PREI:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,4);
			break;
		}
		//Memory Increment or not
		if(PDMAHandle->DMA1_MEM_INC == ENABLE)
		{
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,7);
		}
		else
		{
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,7);
		}
		//Peripheral Increment or not
		if(PDMAHandle->DMA1_PERI_INC == ENABLE)
		{
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,6);
		}
		else
		{
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,6);
		}
		//2-Enable Circular DMA OR NOT
		switch(PDMAHandle->DMA1_CIRCULAR)
		{
		case ENABLE :
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,5);
			break;
		case DISABLE:
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,5);
			break;
		}
		//3-Memory Size Select
		switch(PDMAHandle->DMA1_MSIZE)
		{
		case BYTE :
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,10);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,11);
			break;
		case HALF_WORD:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,10);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,11);
			break;
		case WORD:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,11);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,10);
			break;
		}
		//3-Peripheral Size Select
		switch(PDMAHandle->DMA1_PSIZE)
		{
		case BYTE :
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,8);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,9);
			break;
		case HALF_WORD:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,8);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,9);
			break;
		case WORD:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,9);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,8);
			break;
		}
		//3-Channel Priority
		switch(PDMAHandle->DMA1_Priority)
		{
		case DMA_LOW :
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,12);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,13);
			break;
		case DMA_MEDIUM:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,12);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,13);
			break;
		case DMA_HIGH:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,13);
			CLEAR_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,12);
			break;
		case DMA_VERY_HIGH:
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,13);
			SET_BIT(DMA->CHANNEL[PDMAHandle->DMA1_ChannelNumber-1].CCRx,12);
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- DMA_enuEnable
 * @brief 		- This Function Used to Enable DMA Channel
 * @param [in] 	- Copy_u8ChannelNumber Which is the Channel Number
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t DMA_enuEnable  (uint8_t Copy_u8ChannelNumber)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8ChannelNumber < 8)
	{
		//Clear All Flags
		DMA_SvidClearFlag(Copy_u8ChannelNumber, DMA_GIF);
		DMA_SvidClearFlag(Copy_u8ChannelNumber, DMA_TCIF);
		DMA_SvidClearFlag(Copy_u8ChannelNumber, DMA_HTIF);
		DMA_SvidClearFlag(Copy_u8ChannelNumber, DMA_TEIF);
		//Enable Channel
		SET_BIT(DMA->CHANNEL[Copy_u8ChannelNumber-1].CCRx,0);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- DMA_enuDisable
 * @brief 		- This Function Used to Disable DMA Channel
 * @param [in] 	- Copy_u8ChannelNumber Which is the Channel Number
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t DMA_enuDisable (uint8_t Copy_u8ChannelNumber)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8ChannelNumber < 8)
	{
		//Disable Channel
		CLEAR_BIT(DMA->CHANNEL[Copy_u8ChannelNumber-1].CCRx,0);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- DMA_enuInterruptEnable
 * @brief 		- This Function Used to Enable Interrupt Source on Interrupt Channel
 * @param [in] 	- Copy_u8ChannelNumber Which is the Channel Number
 * @param [in] 	- Copy_u8InterruptSource Which is Interrupt Source
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t DMA_enuInterruptEnable  (uint8_t Copy_u8ChannelNumber , uint8_t Copy_u8InterruptSource)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8ChannelNumber < 8)
	{
		//Enable Interrupt on @Copy_u8InterruptSource
		SET_BIT(DMA->CHANNEL[Copy_u8ChannelNumber-1].CCRx,Copy_u8InterruptSource);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}
/**================================================================
 * @Fn			- DMA_enuSetAddress
 * @brief 		- This Function Used to Transfer Data Between Two Locations in Memory EX:[P32->M32]
 * @param [in] 	- Copy_u8ChannelNumber Which is the Channel Number
 * @param [in] 	- Copy_Pu32PeriphralAddress Which is The Peripheral Address (Source)
 * @param [in] 	- Copy_Pu32MemoryAddress Which is The Memory Address (Destination)
 * @param [in] 	- Copy_u16NDT Which is Block Length
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t DMA_enuSetAddress (uint8_t Copy_u8ChannelNumber , uint32_t *Copy_Pu32PeriphralAddress , uint32_t *Copy_Pu32MemoryAddress,uint16_t Copy_u16NDT)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_Pu32MemoryAddress != NULL && Copy_Pu32PeriphralAddress != NULL)
	{
		CLEAR_BIT(DMA->CHANNEL[Copy_u8ChannelNumber-1].CCRx,0);
		DMA->CHANNEL[Copy_u8ChannelNumber-1].CPARx=(uint32_t)Copy_Pu32PeriphralAddress;
		DMA->CHANNEL[Copy_u8ChannelNumber-1].CMARx=(uint32_t)Copy_Pu32MemoryAddress;
		DMA->CHANNEL[Copy_u8ChannelNumber-1].CNDTRx=Copy_u16NDT;
	    Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
/*
 * ==============================================================================================
 * 								Helper Functions {Private}
 * ==============================================================================================
 */
static void DMA_SvidClearFlag (uint8_t Copy_u8ChannelNumber,uint8_t Copy_u8Flag)
{
	Copy_u8ChannelNumber = (Copy_u8ChannelNumber-1)*4;
	SET_BIT(DMA->IFCR,(Copy_u8ChannelNumber+Copy_u8Flag));
}
/**================================================================
 * @Fn			- DMA_enuSetAddress
 * @brief 		- This Function Used to Transfer Data Between Two Locations in Memory EX:[P32->M32]
 * @param [in] 	- Copy_u8ChannelNumber Which is the Channel Number
 * @param [in] 	- Copy_u8Flag Which is The Flag you want to read
 * @param [in] 	- Copy_u8Read Which is The Pointer to variable that u used to return flag value
 * @retval 		- ErrorState which indicates that function works without errors
 */
ES_t DMA_enuReadFlag (uint8_t Copy_u8ChannelNumber,uint8_t Copy_u8Flag , uint8_t *Copy_u8Read)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(Copy_u8Read!=NULL)
	{
		Copy_u8ChannelNumber = (Copy_u8ChannelNumber-1)*4;
		*Copy_u8Read=GET_BIT(DMA->IFCR,(Copy_u8ChannelNumber+Copy_u8Flag));
		 Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}


	return Local_enuErrorState;
}
/*
 * ==============================================================================================
 * 								Used To Set user Function to be called in Handler
 * ==============================================================================================
 */
void DMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) )
{
	DMA_CallBackChannel1 = Ptr ;
}
/*
 * ==============================================================================================
 * 								IRQHandler For DMA_Channel1
 * ==============================================================================================
 */
void DMA1_Channel1_IRQHandler(void){
	DMA_SvidClearFlag(1, DMA_GIF);
	DMA_SvidClearFlag(1, DMA_TCIF);
	DMA_CallBackChannel1();
}
