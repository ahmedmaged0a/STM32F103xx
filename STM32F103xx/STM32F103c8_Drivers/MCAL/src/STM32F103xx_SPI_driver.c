/*
 * STM32F103xx_SPI_driver.c
 *
 *  Created on: Jan 29, 2023
 *      Author: Ahmed Maged
 */
#include "STM32F103xx_SPI_driver.h"
#include "MACROS.h"
/*
 * ==============================================================================================
 * 								Helper Functions {Private}
 * ==============================================================================================
 */
static void SPI_TXE_Interrupt_Handle(SPI_Handle_t* SPI_Handle);
static void SPI_RXNE_Interrupt_Handle(SPI_Handle_t* SPI_Handle);
static void SPI_OVR_Interrupt_Handle(SPI_Handle_t* SPI_Handle);
/*********************************************************************
 * @fn      		  - SPI_Init
 *
 * @brief             -This Function used to Setup The Configuration That Entered by user
 *
 * @param[in]         -pSPIHandle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -Local_enuErrorState
 *
 * @Note              -
 */
ES_t SPI_Init(SPI_Handle_t *pSPIHandle)
{
	ES_t Local_enuErrorState = ES_NOK;
	SPI1_PERI_CLOCK_ENABLE();
	//Configure SPI_CR1 REG
	if(pSPIHandle != NULL)
	{
		//1.Device Mode Configuration Setup
		pSPIHandle->pSPIx->SPI_CR1 |= (pSPIHandle->SPIConfig.SPI_DeviceMode<<SPI_CR1_MSTR);
		//2.Bus_Config Configuration Setup
		switch(pSPIHandle->SPIConfig.SPI_BusConfig)
		{
		case SPI_BUS_CONFIG_FD:
			CLEAR_BIT(pSPIHandle->pSPIx->SPI_CR1,SPI_CR1_BIDIMODE);
			break;
		case SPI_BUS_CONFIG_HD:
			SET_BIT(pSPIHandle->pSPIx->SPI_CR1,SPI_CR1_BIDIMODE);
			break;
		case SPI_BUS_CONFIG_SIMPLEX_RXONLY:
			CLEAR_BIT(pSPIHandle->pSPIx->SPI_CR1,SPI_CR1_BIDIMODE);
			SET_BIT(pSPIHandle->pSPIx->SPI_CR1,SPI_CR1_RXONLY);
			break;
		}
		//3.Clock Configuration Setup [Serial Clock Speed]
		pSPIHandle->pSPIx->SPI_CR1 |= (pSPIHandle->SPIConfig.SPI_SclkSpeed<<SPI_CR1_BR);
		//4.DFF Configuration setup
		pSPIHandle->pSPIx->SPI_CR1 |= (pSPIHandle->SPIConfig.SPI_DFF<<SPI_CR1_DFF);
		//5.CPHA Configuration setup
		pSPIHandle->pSPIx->SPI_CR1 |= (pSPIHandle->SPIConfig.SPI_CPHA<<SPI_CR1_CPHA);
		//4.CPOL Configuration setup
		pSPIHandle->pSPIx->SPI_CR1 |= (pSPIHandle->SPIConfig.SPI_CPOL<<SPI_CR1_CPOL);
		//4.SSM Configuration setup
		pSPIHandle->pSPIx->SPI_CR1 |= (pSPIHandle->SPIConfig.SPI_SSM<<SPI_CR1_SSM);
		Local_enuErrorState=ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/*********************************************************************
 * @fn      		  - SPI_SendData
 *
 * @brief             -This Function used to Send Data from TxBuffer
 *
 * @param[in]         -*pSPIx
 * @param[in]         -*pTxBuffer
 * @param[in]         -Lenght_Data [in bytes]
 *
 * @return            -Local_enuErrorState
 *
 * @Note              - This Fuction Done Using Polling
 */
ES_t SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer,uint32_t Lenght_Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(pSPIx != NULL  && pTxBuffer !=NULL)
	{
		while(Lenght_Data)
		{
			//1. wait for TXE become 1 means that buffer is empty
			while(!GET_BIT(pSPIx->SPI_SR,SPI_SR_TXE));
			//2. Check if DFF is 1 means user want to send 8 bits or 16 bits in DR
			if(GET_BIT(pSPIx->SPI_CR1,SPI_CR1_DFF)==SET)//16-bits DR
			{
				//Load 2 Bytes[16-bits] into DR Register
				pSPIx->SPI_DR = *((uint16_t *)pTxBuffer); //type casting to send 16 bits
				Lenght_Data--;//Decrease the first byte sent
				Lenght_Data--;//Decrease the second byte sent
				(uint16_t*)pTxBuffer++;//increment buffer address by 2 bytes
			}
			else//8-bits DR
			{
				//Load 1 Byte[8-bits] into DR Register
				pSPIx->SPI_DR = *(pTxBuffer);
				Lenght_Data--;//Decrease 1 byte
				pTxBuffer++;//increment buffer address by 1 bytes
			}

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/*********************************************************************
 * @fn      		  - SPI_ReceiveData
 *
 * @brief             -This Function used to Receive Data at RxBuffer
 *
 * @param[in]         -*pSPIx
 * @param[in]         -*pRxBuffe
 * @param[in]         -Lenght_Data [in bytes]
 *
 * @return            -Local_enuErrorState
 *
 * @Note              -This Function Done Using Polling
 */
ES_t SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer,uint32_t Lenght_Data)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(pSPIx != NULL  && pRxBuffer !=NULL)
	{
		while(Lenght_Data)
		{
			//1. wait for TXE become 1 means that buffer is empty
			while(!GET_BIT(pSPIx->SPI_SR,SPI_SR_RXNE));
			//2. Check if DFF is 1 means user want to send 8 bits or 16 bits in DR
			if(GET_BIT(pSPIx->SPI_CR1,SPI_CR1_DFF)==SET)//16-bits DR
			{
				//Load 2 Bytes[16-bits] into DR Register
				*((uint16_t *)pRxBuffer)=pSPIx->SPI_DR ; //type casting to send 16 bits
				Lenght_Data--;//Decrease the first byte sent
				Lenght_Data--;//Decrease the second byte sent
				(uint16_t*)pRxBuffer++;//increment buffer address by 2 bytes
			}
			else//8-bits DR
			{
				//Load 1 Byte[8-bits] into DR Register
				*(pRxBuffer)=pSPIx->SPI_DR  ;
				Lenght_Data--;//Decrease 1 byte
				pRxBuffer++;//increment buffer address by 1 bytes
			}

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/*********************************************************************
 * @fn      		  - SPI_PeripheralControl
 *
 * @brief             -This Function used to Enable or Disable Interrupt
 *
 * @param[in]         -*pSPIx
 * @param[in]         -SPI_ENorDI
 * @param[in]         -
 *
 * @return            -Local_enuErrorState
 *
 * @Note              -
 */
ES_t SPI_PeripheralControl(SPI_RegDef_t *pSPIx,uint8_t SPI_ENorDI)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(pSPIx != NULL)
	{
		if(SPI_ENorDI == ENABLE)
		{
			SET_BIT(pSPIx->SPI_CR1,SPI_CR1_SPE);
		}
		else
		{
			CLEAR_BIT(pSPIx->SPI_CR1,SPI_CR1_SPE);
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/*********************************************************************
 * @fn      		  - SPI_SSIControl
 *
 * @brief             -This Function used to Enable or Disable SSI
 *
 * @param[in]         -*pSPIx
 * @param[in]         -SPI_ENorDI
 * @param[in]         -
 *
 * @return            -Local_enuErrorState
 *
 * @Note              -
 */
ES_t SPI_SSIControl(SPI_RegDef_t *pSPIx,uint8_t SPI_ENorDI)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(pSPIx != NULL)
	{
		if(SPI_ENorDI == ENABLE)
		{
			SET_BIT(pSPIx->SPI_CR1,SPI_CR1_SSI);
		}
		else
		{
			CLEAR_BIT(pSPIx->SPI_CR1,SPI_CR1_SSI);
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/*********************************************************************
 * @fn      		  - SPI_AsySendData
 *
 * @brief             -This Function used to Send Data Using Interrupt
 *
 * @param[in]         -*pSPIHandle
 * @param[in]         -*pTxBuffe
 * @param[in]         -Lenght_Data [in bytes]
 *
 * @return            -uint8_t
 *
 * @Note              -This Function Done Using Interrupt
 */
uint8_t SPI_AsySendData(SPI_Handle_t *pSPIHandle,uint8_t *pTxBuffer,uint32_t Length_Data)
{
	uint8_t Local_u8SPIState = pSPIHandle->TxState;
	if(Local_u8SPIState != SPI_BUSY_IN_TX)
	{
		//**Save Tx Adress in Global Varibale and Save Data len Which will use by interrupt
		pSPIHandle->pTxBuffer=pTxBuffer;
		pSPIHandle->TxLen = Length_Data;
		//**Make SPI as Busy in Transmit
		pSPIHandle->TxState = SPI_BUSY_IN_TX;
		//**Enable TXEIE to get interrupt when TXE in set in SR Reg
		SET_BIT(pSPIHandle->pSPIx->SPI_CR2,SPI_CR2_TXEIE);
	}


	return Local_u8SPIState;
}
/*********************************************************************
 * @fn      		  - SPI_AsyReceiveData
 *
 * @brief             -This Function used to Receive Data at RxBuffer
 *
 * @param[in]         -*pSPIHandle
 * @param[in]         -*pRxBuffe
 * @param[in]         -Lenght_Data [in bytes]
 *
 * @return            -uint8_t
 *
 * @Note              -This Function Done Using Interrupt
 */
uint8_t SPI_AsyReceiveData(SPI_Handle_t *pSPIHandle,uint8_t *pRxBuffer,uint32_t Length_Data)
{
	uint8_t Local_u8SPIState = pSPIHandle->RxState;
	if(Local_u8SPIState != SPI_BUSY_IN_RX)
	{
		//**Save Tx Adress in Global Varibale and Save Data len Which will use by interrupt
		pSPIHandle->pRxBuffer=pRxBuffer;
		pSPIHandle->RxLen = Length_Data;
		//**Make SPI as Busy in Receive
		pSPIHandle->RxState = SPI_BUSY_IN_RX;
		//**Enable RXNEIE to get interrupt when TXE in set in SR Reg
		SET_BIT(pSPIHandle->pSPIx->SPI_CR2,SPI_CR2_RXNEIE);
	}


	return Local_u8SPIState;
}
/*********************************************************************
 * @fn      		  - SPI_IRQHandling
 *
 * @brief             -This Function used to Handle SPI Interrupt
 *
 * @param[in]         -*pHandle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -void
 *
 * @Note              -
 */
void SPI_IRQHandling(SPI_Handle_t *pHandle)
{
	uint8_t Local_u8Flag1,Local_u8Flag2;
	//**Check For TXE
	Local_u8Flag1 = GET_BIT(pHandle->pSPIx->SPI_SR,SPI_SR_TXE);
	Local_u8Flag2 = GET_BIT(pHandle->pSPIx->SPI_CR2,SPI_CR2_TXEIE);
	if(Local_u8Flag1 && Local_u8Flag2)
	{
		//TXE Handle
		SPI_TXE_Interrupt_Handle(pHandle);
	}
	//**Check For RXNE
	Local_u8Flag1 = GET_BIT(pHandle->pSPIx->SPI_SR,SPI_SR_RXNE);
	Local_u8Flag2 = GET_BIT(pHandle->pSPIx->SPI_CR2,SPI_CR2_RXNEIE);
	if(Local_u8Flag1 && Local_u8Flag2)
	{
		//RXNE Handle
		SPI_RXNE_Interrupt_Handle(pHandle);
	}
	//**Check For OVR Flag
	Local_u8Flag1 = GET_BIT(pHandle->pSPIx->SPI_SR,SPI_SR_OVR);
	Local_u8Flag2 = GET_BIT(pHandle->pSPIx->SPI_CR2,SPI_CR2_ERRIE);
	if(Local_u8Flag1&&Local_u8Flag2)
	{
		//OVR Handle
		SPI_OVR_Interrupt_Handle(pHandle);
	}
}
/*********************************************************************
 * @fn      		  - SPI_TXE_Interrupt_Handle
 *
 * @brief             -This Function used to Handle TXE Interrupt
 *
 * @param[in]         -*SPI_Handle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -void
 *
 * @Note              -
 */
static void SPI_TXE_Interrupt_Handle(SPI_Handle_t* SPI_Handle)
{
	if(GET_BIT(SPI_Handle->pSPIx->SPI_CR1,SPI_CR1_DFF)==SET)//16-bits DR
	{
		//Load 2 Bytes[16-bits] into DR Register
		SPI_Handle->pSPIx->SPI_DR = *((uint16_t *)SPI_Handle->pTxBuffer); //type casting to send 16 bits
		SPI_Handle->TxLen--;//Decrease the first byte sent
		SPI_Handle->TxLen--;//Decrease the second byte sent
		(uint16_t*)SPI_Handle->pTxBuffer++;//increment buffer address by 2 bytes
	}
	else//8-bits DR
	{
		//Load 1 Byte[8-bits] into DR Register
		SPI_Handle->pSPIx->SPI_DR = *(SPI_Handle->pTxBuffer);
		SPI_Handle->TxLen--;//Decrease 1 byte
		SPI_Handle->pTxBuffer++;//increment buffer address by 1 bytes
	}
	if(!SPI_Handle->TxLen)
	{
		//Close SPI Transmission and inform the user that Tx in done sent data
		//1-Close Interrupt(no interrupt nedded all data has been sent)
		CLEAR_BIT(SPI_Handle->pSPIx->SPI_CR2,SPI_CR2_TXEIE);
		SPI_Handle->pTxBuffer = NULL;
		SPI_Handle->TxLen=0;
		SPI_Handle->TxState=SPI_READY;
		SPI_CallBackFunction(SPI_Handle, SPI_EVENT_TX_CMPLT);
	}
}
/*********************************************************************
 * @fn      		  - SPI_RXNE_Interrupt_Handle
 *
 * @brief             -This Function used to Handle RXNE Interrupt
 *
 * @param[in]         -*SPI_Handle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -void
 *
 * @Note              -
 */
static void SPI_RXNE_Interrupt_Handle(SPI_Handle_t* SPI_Handle)
{
	if(GET_BIT(SPI_Handle->pSPIx->SPI_CR1,SPI_CR1_DFF)==SET)//16-bits DR
	{
		//Load 2 Bytes[16-bits] into DR Register
		*((uint16_t *)SPI_Handle->pRxBuffer)=SPI_Handle->pSPIx->SPI_DR;  //type casting to send 16 bits
		SPI_Handle->RxLen--;//Decrease the first byte sent
		SPI_Handle->RxLen--;//Decrease the second byte sent
		(uint16_t*)SPI_Handle->pRxBuffer++;//increment buffer address by 2 bytes
	}
	else//8-bits DR
	{
		//Load 1 Byte[8-bits] into DR Register
		*(SPI_Handle->pRxBuffer)=SPI_Handle->pSPIx->SPI_DR;
		SPI_Handle->RxLen--;//Decrease 1 byte
		SPI_Handle->pRxBuffer++;//increment buffer address by 1 bytes
	}
	if(!SPI_Handle->RxLen)
	{
		//Close SPI Transmission and inform the user that Tx in done sent data
		//1-Close Interrupt(no interrupt nedded all data has been sent)
		CLEAR_BIT(SPI_Handle->pSPIx->SPI_CR2,SPI_CR2_RXNEIE);
		SPI_Handle->pRxBuffer = NULL;
		SPI_Handle->RxLen=0;
		SPI_Handle->RxState=SPI_READY;
		SPI_CallBackFunction(SPI_Handle, SPI_EVENT_RX_CMPLT);
	}
}
/*********************************************************************
 * @fn      		  - SPI_OVR_Interrupt_Handle
 *
 * @brief             -This Function used to Handle OVR Interrupt Error
 *
 * @param[in]         -*SPI_Handle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -void
 *
 * @Note              -
 */
static void SPI_OVR_Interrupt_Handle(SPI_Handle_t* SPI_Handle)
{
	uint8_t Local_u8Read;
	//Clear Flag
	if(SPI_Handle->TxState != SPI_BUSY_IN_TX)
	{
		Local_u8Read = SPI_Handle->pSPIx->SPI_DR;
		Local_u8Read = SPI_Handle->pSPIx->SPI_SR;
	}
	(void)Local_u8Read;
	SPI_CallBackFunction(SPI_Handle, SPI_EVENT_OVR_ERR);

}
/*********************************************************************
 * @fn      		  - SPI_CloseTransmission
 *
 * @brief             -This Function used to Stop data transmission
 *
 * @param[in]         -*pSPIHandle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -void
 *
 * @Note              -
 */
void SPI_CloseTransmission(SPI_Handle_t *pSPIHandle)
{
	//Close SPI Transmission and inform the user that Tx in done sent data
	//1-Close Interrupt(no interrupt nedded all data has been sent)
	CLEAR_BIT(pSPIHandle->pSPIx->SPI_CR2,SPI_CR2_TXEIE);
	pSPIHandle->pTxBuffer = NULL;
	pSPIHandle->TxLen=0;
	pSPIHandle->TxState=SPI_READY;
}
/*********************************************************************
 * @fn      		  - SPI_CloseReceive
 *
 * @brief             -This Function used to Stop data Receive
 *
 * @param[in]         -*pSPIHandle
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -void
 *
 * @Note              -
 */
void SPI_CloseReceive(SPI_Handle_t *pSPIHandle)
{
	//Close SPI Transmission and inform the user that Tx in done sent data
	//1-Close Interrupt(no interrupt nedded all data has been sent)
	CLEAR_BIT(pSPIHandle->pSPIx->SPI_CR2,SPI_CR2_RXNEIE);
	pSPIHandle->pRxBuffer = NULL;
	pSPIHandle->RxLen=0;
	pSPIHandle->RxState=SPI_READY;
}
/*********************************************************************
 * @fn      		  - SPI_CallBackFunction
 *
 * @brief             -This Function used to Send Acknowledge to application
 *
 * @param[in]         -*pSPIHandle
 * @param[in]         -APP_EVENT
 * @param[in]         -
 *
 * @return            -void
 *
 * @Note              -This Function weak function which mean user can override on it
 * 						in application function
 */
__weak void SPI_CallBackFunction(SPI_Handle_t *pSPIHandle,uint8_t APP_EVENT)
{

}
