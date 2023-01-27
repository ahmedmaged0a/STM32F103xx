/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	26 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef HAL_INC_STP_74HC595_H_
#define HAL_INC_STP_74HC595_H_
#include "STM32f103xx_GPIO_driver.h"
/*
* ==============================================================================================
* 					Configuration Pin Structure for Serial To Parallel (IC74HC595).
* ==============================================================================================
*/
typedef struct
{
	uint16_t STP_u8SDataPin;   /*!<< holds Which Pin Will You Use To Connect Data Pin>>*/
	uint16_t STP_u8ShClockPin; /*!<< holds Which Pin Will You Use To Connect Shift_Clock Pin>>*/
	uint16_t STP_u8StClockPin; /*!<< holds Which Pin Will You Use To Connect Store_Clock Pin>>*/
}STP_pinConfig_t;
/*
* ==============================================================================================
* 					Configuration Port Structure for Serial To Parallel (IC74HC595).
* ==============================================================================================
*/
typedef struct
{
	GPIO_RegDef_t	 *STP_u8SDataPort;   /*!<< holds Which Port Will You Use To Connect Data Pin>>*/
	GPIO_RegDef_t	 *STP_u8ShClockPort; /*!<< holds Which Port Will You Use To Connect Shift_Clock Pin>>*/
	GPIO_RegDef_t	 *STP_u8StClockPort; /*!<< holds Which Port Will You Use To Connect Store_Clock Pin>>*/
}STP_PortConfig_t;
/*
* ==============================================================================================
* 					Configuration Handling (IC74HC595).
* ==============================================================================================
*/
typedef struct
{
	STP_pinConfig_t 	STP_PinConfig;	/*!<< holds The Pin Configuration For Specific 3 pin in 74HC595>>*/
	STP_PortConfig_t 	STP_PortConfig; /*!<< holds The Port Configuration For Specific 3 pin in 74HC595>>*/
}STP_strHandle;

/*
* ==============================================================================================
* 								APIs Supported by "HAL 74HC595-IC DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/

ES_t STP_enuInit(STP_strHandle *Copy_PstrHandle);

ES_t STP_enuSendSynchronus(STP_strHandle *Copy_PstrHandle,uint8_t Copy_u8Data);

#endif /* HAL_INC_STP_74HC595_H_ */
