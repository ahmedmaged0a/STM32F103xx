/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	28 JUL 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef INCLUDE_STM32_F103C8_GPIO_DRIVER_H_
#define INCLUDE_STM32_F103C8_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

/*
* ==============================================================================================
* 								Configuration Pin Structure.
* ==============================================================================================
*/
typedef struct
{
	uint16_t GPIO_PinNumber; 	/*<<Specifies the GPIO pins to be configured based on @ref GPIO_PINS_Define.>>*/
	uint8_t	 GPIO_PinMode;		/*<<Specifies the GPIO Mode to be configured based on @ref GPIO_MODE_Define.>>*/
	uint8_t	 GPIO_PinSpeed;		/*<<Specifies the GPIO Pin Speed to be configured based on @ref GPIO_Speed_Define.>>*/

}GPIO_PinConfig_t;

/*
* ==============================================================================================
* 								Handle Structure For GPIO PIN.
* ==============================================================================================
*/


typedef struct
{
	GPIO_RegDef_t	 *PGPIOx;				/*!<< holds the base address of GPIO port to which the pin belongs >>*/
	GPIO_PinConfig_t GPIO_PinConfig_t;		/*!<< holds GPIO pin configuration settings >>*/
}GPIO_Handle_t;


//-----------------------------
//Macros Configuration References
//-----------------------------

/*
* ==============================================================================================
* 								@ref GPIO_PIN_Define
* 								Here You Can Select You Pin Number.
* ==============================================================================================
*/
#define GPIO_PIN_0						((uint16_t)0x0001)    /*<< PIN_0   Selected >>*/
#define GPIO_PIN_1						((uint16_t)0x0002)    /*<< PIN_1   Selected >>*/
#define GPIO_PIN_2						((uint16_t)0x0004)    /*<< PIN_2   Selected >>*/
#define GPIO_PIN_3						((uint16_t)0x0008)    /*<< PIN_3   Selected >>*/
#define GPIO_PIN_4						((uint16_t)0x0010)    /*<< PIN_4   Selected >>*/
#define GPIO_PIN_5						((uint16_t)0x0020)    /*<< PIN_5   Selected >>*/
#define GPIO_PIN_6						((uint16_t)0x0040)    /*<< PIN_6   Selected >>*/
#define GPIO_PIN_7						((uint16_t)0x0080)    /*<< PIN_7   Selected >>*/
#define GPIO_PIN_8						((uint16_t)0x0100)    /*<< PIN_8   Selected >>*/
#define GPIO_PIN_9						((uint16_t)0x0200)    /*<< PIN_9   Selected >>*/
#define GPIO_PIN_10						((uint16_t)0x0400)    /*<< PIN_10  Selected >>*/
#define GPIO_PIN_11						((uint16_t)0x0800)    /*<< PIN_11  Selected >>*/
#define GPIO_PIN_12						((uint16_t)0x1000)    /*<< PIN_12  Selected >>*/
#define GPIO_PIN_13						((uint16_t)0x2000)    /*<< PIN_13  Selected >>*/
#define GPIO_PIN_14						((uint16_t)0x4000)    /*<< PIN_14  Selected >>*/
#define GPIO_PIN_15						((uint16_t)0x8000)    /*<< PIN_15  Selected >>*/
#define GPIO_PIN_ALL					((uint16_t)0xFFFF)    /*<< PIN_ALL Selected >>*/

/*
* ==============================================================================================
* 								@ref GPIO_MODE_Define
* 								Here You Can Select The Mode for your GPIO_PIN.
* 								[0] = Analog mode
* 								[1] = Floating input (reset state)
* 								[2] = Input with pull-up
* 								[3] = Input with pull-down
* 								[4] = General purpose output push-pull
* 								[5] = General purpose output Open-drain
* 								[6] = Alternate function output Push-pull
* 								[7] = Alternate function output Open-drain
* 								[8] = Alternate function input
* ==============================================================================================
*/

#define GPIO_MODE_ANALOG				0x00000000UL   	// Select Analog mode
#define GPIO_MODE_INPUT_FLO				0x00000001UL 	// Select Floating input (reset state)
#define GPIO_MODE_INPUT_PU				0x00000002UL 	// Select Input with pull-up
#define GPIO_MODE_INPUT_PD				0x00000003UL 	// Select Input with pull-down
#define GPIO_MODE_OUTPUT_PP				0x00000004UL 	// Select General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD				0x00000005UL 	// Select General purpose output Open-drain
#define GPIO_MODE_OUTPUT_AF_PP			0x00000006UL 	// Select Alternate function output Push-pull
#define GPIO_MODE_OUTPUT_AF_OD			0x00000007UL 	// Select Alternate function output Open-drain
#define GPIO_MODE_INPUT_AF				0x00000008UL 	// Alternate function input

/*
* ==============================================================================================
* 								@ref GPIO_SPEED_Define
* 								Here You Can Select The Speed for your GPIO_PIN.
* 								[1] = Output mode, max speed 10 MHz.
* 								[2] = Output mode, max speed 2 MHz.
* 								[3] = Output mode, max speed 50 MHz.
* ==============================================================================================
*/

#define GPIO_SPEED_10M					0x00000001U   	// Select Output mode, max speed 10 MHz
#define GPIO_SPEED_2M					0x00000002U 	// Select Output mode, max speed 2 MHz
#define GPIO_SPEED_50M					0x00000003U 	// Select Output mode, max speed 50 MHz


/*@ref Module_REF_NAME_define
*/
/*
* ==============================================================================================
* 								APIs Supported by "MCAL GPIO DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/

ES_t    GPIO_enuPeriClockControl(GPIO_RegDef_t *PGPIOx , uint8_t Copy_u8Clockstatus);

ES_t    GPIO_enuInit(GPIO_Handle_t *PGPIOHandle);

ES_t	GPIO_enuDeInit(GPIO_RegDef_t *PGPIOx);

ES_t    GPIO_enuReadFromInputPin(GPIO_RegDef_t *PGPIOx  , uint16_t Copy_u16PinNumber,uint8_t *Copy_Pu8PinValue);

ES_t    GPIO_enuWriteToOutputPin(GPIO_RegDef_t *PGPIOx  , uint16_t Copy_u16PinNumber , uint8_t Copy_u8PinValue);

ES_t    GPIO_enuReadFromInputPort(GPIO_RegDef_t *PGPIOx , uint16_t *Copy_Pu16PortValue);

ES_t    GPIO_enuWriteToOutputPort(GPIO_RegDef_t *PGPIOx , uint16_t Copy_u16PortValue);

ES_t    GPIO_enuToggleOutputPin(GPIO_RegDef_t *PGPIOx   , uint16_t Copy_u16PinNumber);

#endif /* INCLUDE_STM32_F103C6_GPIO_DRIVER_H_ */
