/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	29 DEC 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef MCAL_INC_STM32F103XX_SPI_DRIVER_H_
#define MCAL_INC_STM32F103XX_SPI_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"

/*
* ==============================================================================================
* 								SPI Configurations Structure.
* ==============================================================================================
*/
typedef struct
{
	uint8_t  SPI_DeviceMode; 	/*<<Specifies the SPI_DeviceMode to be configured based on @ref DEVICE_MODE.>>*/
	uint8_t	 SPI_SclkSpeed;	    /*<<Specifies SPI_SclkSpeed to be configured based on @ref SPI_SclkSpeed.>>*/
	uint8_t  SPI_BusConfig;     /*<<Specifies SPI_BusConfig to be configured based on @ref BUS_Config.>>*/
	uint8_t	 SPI_DFF;	     	/*<<Specifies SPI_DFF to be configured based on @ref SPI_DFF.>>*/
	uint8_t	 SPI_CPOL;	        /*<<Specifies SPI_CPOL to be configured based on @ref CPOL.>>*/
	uint8_t	 SPI_CPHA;		    /*<<Specifies SPI_CPHA to be configured based on @ref CPHA.>>*/
	uint8_t  SPI_SSM;		    /*<<Specifies SPI_SSM to be configured as SSM.>>*/
}SPI_Config_t;

typedef struct
{
	 SPI_RegDef_t *pSPIx; /*<<This holds the base address of peripheral>>*/
	 SPI_Config_t SPIConfig;/*<<This holds the Configurations of SPIx>>*/
	 uint8_t *pTxBuffer; /*<<To Store The Address of tx Buffer>>*/
	 uint8_t *pRxBuffer; /*<<To Store The Address of rx Buffer>>*/
	 uint8_t TxLen;/*<<To Store tx length>>*/
	 uint8_t RxLen;/*<<To Store rx length>>*/
	 uint8_t TxState;/*<<To Store TX buffer State (Ready or Busy)>>*/
	 uint8_t RxState;/*<<To Store RX buffer State (Ready or Busy)>>*/

}SPI_Handle_t ;

/*
* ==============================================================================================
* 								@ref DEVICE_MODE
* 								Select between {Master or Slave}
* ==============================================================================================
*/
#define SPI_DEVICE_MODE_MASTER    1
#define SPI_DEVICE_MODE_SLAVE     0

/*
* ==============================================================================================
* 								@ref SPI_BusConfig
* 								Select between {FullDoublex or HalfDoublex or Simplex }
* ==============================================================================================
*/

#define SPI_BUS_CONFIG_FD                1
#define SPI_BUS_CONFIG_HD                2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY    4  //simplex TX is nothing but FD only but cut MISO Line
/* ==============================================================================================
* 								@ref SPI_SclkSpeed
* 								Select Your Clock Speed
* ==============================================================================================
*/
#define SPI_SCLK_SPEED_DIV2             	0
#define SPI_SCLK_SPEED_DIV4             	1
#define SPI_SCLK_SPEED_DIV8             	2
#define SPI_SCLK_SPEED_DIV16             	3
#define SPI_SCLK_SPEED_DIV32             	4
#define SPI_SCLK_SPEED_DIV64             	5
#define SPI_SCLK_SPEED_DIV128             	6
#define SPI_SCLK_SPEED_DIV256             	7

/* ==============================================================================================
* 								@ref SPI_DFF
* 								Select SPI Data Frame
* ==============================================================================================
*/
#define SPI_DFF_8BITS 	0
#define SPI_DFF_16BITS  1

/* ==============================================================================================
* 								@ref CPOL
* 								Select Clock Polarity
* ==============================================================================================
*/
#define SPI_CPOL_HIGH 1
#define SPI_CPOL_LOW 0

/* ==============================================================================================
* 								@ref CPOL
* 								Select Clock Phase
* ==============================================================================================
*/
#define SPI_CPHA_HIGH 1
#define SPI_CPHA_LOW 0

/* ==============================================================================================
* 								@ref SSM
* 								Enable or Disable SSM
* ==============================================================================================
*/
#define SPI_SSM_EN     1
#define SPI_SSM_DI     0
/*
* ==============================================================================================
* 								@ref SPI_States
* 								Select between {Ready or Busy}
* ==============================================================================================
*/
#define SPI_READY		0
#define SPI_BUSY_IN_RX  1
#define SPI_BUSY_IN_TX  2
/*
* ==============================================================================================
* 								@ref Events
* ==============================================================================================
*/
#define SPI_EVENT_TX_CMPLT   1
#define SPI_EVENT_RX_CMPLT   2
#define SPI_EVENT_OVR_ERR    3
#define SPI_EVENT_CRC_ERR    4

/*
* ==============================================================================================
* 								APIs Supported by "SPI_Driver"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/

ES_t SPI_Init(SPI_Handle_t *pSPIHandle);

/*
 * Data Send And Receive based on Polling (Synchronous)
 * LEN_DATA: How Many bytes this API should send
 * TxBuffer : Pointer to Data Buffer
 * RxBuffer : Pointer to Data Buffer
 * */
ES_t SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer,uint32_t Lenght_Data);

ES_t SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer,uint32_t Lenght_Data);

ES_t SPI_PeripheralControl(SPI_RegDef_t *pSPIx,uint8_t SPI_ENorDI);

ES_t SPI_SSIControl(SPI_RegDef_t *pSPIx,uint8_t SPI_ENorDI);

ES_t SPI_AsySendData(SPI_Handle_t *pSPIHandle,uint8_t *pTxBuffeer,uint32_t Length_Data);

ES_t SPI_AsyReceiveData(SPI_Handle_t *pSPIHandle,uint8_t *pRxBuffeer,uint32_t Length_Data);

void SPI_IRQHandling(SPI_Handle_t *pHandle);

void SPI_CloseTransmission(SPI_Handle_t *pSPIHandle);

void SPI_CloseReceive(SPI_Handle_t *pSPIHandle);

void SPI_CallBackFunction(SPI_Handle_t *pSPIHandle,uint8_t APP_EVENT);

#endif /* MCAL_INC_STM32F103XX_SPI_DRIVER_H_ */
