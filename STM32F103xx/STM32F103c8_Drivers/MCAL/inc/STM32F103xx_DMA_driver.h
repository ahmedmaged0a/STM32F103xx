/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	22 DEC 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef MCAL_INC_STM32F103XX_DMA_DRIVER_H_
#define MCAL_INC_STM32F103XX_DMA_DRIVER_H_
//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"

/*
* ==============================================================================================
* 								DMA1 Configurations Structure.
* ==============================================================================================
*/
typedef struct
{
	uint8_t  DMA1_ChannelNumber; 	/*<<Specifies the DMA1_ChannelNumber to be configured based on @ref DMA1_CHANNELx.>>*/
	uint8_t	 DMA1_Direction;		/*<<Specifies the DMA1_Direction to be configured based on @ref DIRECTIONS.>>*/
	uint8_t	 DMA1_Priority;		    /*<<Specifies the DMA1_Priority to be configured based on @ref DMA_Priority.>>*/
	uint8_t	 DMA1_MSIZE;		    /*<<Specifies the DMA1_MSIZE to be configured based on @ref DMA_SIZE.>>*/
	uint8_t	 DMA1_PSIZE;		    /*<<Specifies the DMA1_PSIZE to be configured based on @ref DMA_SIZE.>>*/
	uint8_t  DMA1_MEM_INC;			/*<<Specifies the DMA1_MEM_INC to be configured as [ENABLE OR DISABLE].>>*/
	uint8_t  DMA1_PERI_INC;			/*<<Specifies the DMA1_PERI_INC to be configured as [ENABLE OR DISABLE].>>*/
	uint8_t  DMA1_CIRCULAR;         /*<<Specifies the DMA1_CIRCULAR to be configured as [ENABLE OR DISABLE].>>*/
}DMA_Handle_t;

/*
* ==============================================================================================
* 								@ref DMA1_CHANNELx
* 								Here You Can Select Your Channel Number.
* ==============================================================================================
*/
#define CHANNEL1  1
#define CHANNEL2  2
#define CHANNEL3  3
#define CHANNEL4  4
#define CHANNEL5  5
#define CHANNEL6  6
#define CHANNEL7  7
/*
* ==============================================================================================
* 								@ref DIRECTIONS
* 								Here You Can Select the Direction.
* ==============================================================================================
*/
#define MEM_TO_MEM   0
#define PREI_TO_MEM  1
#define MEM_TO_PREI  2
/*
* ==============================================================================================
* 								@ref DMA_Priority
* 								Here You Can Select the Priority of Channel.
* ==============================================================================================
*/
#define DMA_LOW         0
#define DMA_MEDIUM      1
#define DMA_HIGH        2
#define DMA_VERY_HIGH   3
/*
* ==============================================================================================
* 								@ref DMA_SIZE
* 								Here You Can Select the Memory Size and Peripheral Size.
* ==============================================================================================
*/
#define BYTE       0  //8-bit
#define HALF_WORD  1  //16-bit
#define WORD       2  //32-bit

/*
* ==============================================================================================
* 								APIs Supported by "DMA Drivers"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/
ES_t DMA_enuConfigurationSetup (DMA_Handle_t *PDMAHandle);

ES_t DMA_enuEnable  (uint8_t Copy_u8ChannelNumber);

ES_t DMA_enuDisable (uint8_t Copy_u8ChannelNumber);

ES_t DMA_enuInterruptEnable  (uint8_t Copy_u8ChannelNumber , uint8_t Copy_u8InterruptSource);

ES_t DMA_enuSetAddress (uint8_t Copy_u8ChannelNumber , uint32_t *Copy_Pu32PeriphralAddress , uint32_t *Copy_Pu32MemoryAddress,uint16_t Copy_u16NDT);

ES_t DMA_enuReadFlag (uint8_t Copy_u8ChannelNumber,uint8_t Copy_u8Flag , uint8_t *Copy_u8Read);

void DMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) );
#endif /* MCAL_INC_STM32F103XX_DMA_DRIVER_H_ */
