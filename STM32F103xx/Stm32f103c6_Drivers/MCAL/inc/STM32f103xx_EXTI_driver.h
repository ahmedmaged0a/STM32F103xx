/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	1 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/


#ifndef MCAL_INC_STM32F103XX_EXTI_DRIVER_H_
#define MCAL_INC_STM32F103XX_EXTI_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "Stm32f103x6.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------

/*
* ==============================================================================================
* 								Configuration EXT Interrupt pin Structure.
* ==============================================================================================
*/
typedef struct
{
	GPIO_RegDef_t	*EXTI_PportNumber; 	 /*!<< holds the base address of GPIO port to which the EXT_LINE belongs >>*/
	uint8_t 		 EXTI_u8LineNumber;  /*<<Specifies the External Interrupt Line to be configured based on @ref EXTI_LINE_Define.>>*/
	uint8_t 		 EXTI_u8TriggerMode; /*<<Specifies the External Interrupt Triggering Mode based on @ref EXTI_TRIGGER_Define.>>*/

}EXTI_Config_t;




//-----------------------------
//Macros Configuration References
//-----------------------------

/*
* ==============================================================================================
* 								@ref EXTI_TRIGGER_Define.
* 								Here You Can Select You External Interrupt Triggering Mode.
* ==============================================================================================
*/
#define EXTI_TRIGGER_RISHING	0
#define EXTI_TRIGGER_FALLING	1
#define EXTI_TRIGGER_ONCHANGE	2


/*
* ==============================================================================================
* 								@ref EXTI_LINE_Define.
* 								Here You Can Select You External Interrupt Line.
* ==============================================================================================
*/
#define EXTI_LINE_0							0     /*<< LINE_0   Selected >>*/
#define EXTI_LINE_1							1     /*<< LINE_1   Selected >>*/
#define EXTI_LINE_2							2     /*<< LINE_2   Selected >>*/
#define EXTI_LINE_3							3     /*<< LINE_3   Selected >>*/
#define EXTI_LINE_4							4     /*<< LINE_4   Selected >>*/
#define EXTI_LINE_5							5     /*<< LINE_5   Selected >>*/
#define EXTI_LINE_6							6     /*<< LINE_6   Selected >>*/
#define EXTI_LINE_7							7     /*<< LINE_7   Selected >>*/
#define EXTI_LINE_8							8     /*<< LINE_8   Selected >>*/
#define EXTI_LINE_9							9     /*<< LINE_9   Selected >>*/
#define EXTI_LINE_10						10    /*<< LINE_10  Selected >>*/
#define EXTI_LINE_11						11    /*<< LINE_11  Selected >>*/
#define EXTI_LINE_12						12    /*<< LINE_12  Selected >>*/
#define EXTI_LINE_13						13    /*<< LINE_13  Selected >>*/
#define EXTI_LINE_14						14    /*<< LINE_14  Selected >>*/
#define EXTI_LINE_15						15    /*<< LINE_15  Selected >>*/

/*@ref Module_REF_NAME_define
*/
/*
* ==============================================================================================
* 								APIs Supported by "MCAL EXTI DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/

ES_t  EXTI_enuInitConfig   		(EXTI_Config_t * Copy_EXTHandle);
ES_t  EXTI_enuEnableMask   		(uint8_t Copy_u16EXTILine);
ES_t  EXTI_enuDisableMask  		(uint8_t Copy_u16EXTILine);
ES_t  EXTI_enuSoftWareTrigger	(uint8_t Copy_u16EXTILine);
/*
* ==============================================================================================
* 										CallBack Functions Prototypes
* ==============================================================================================
*/
/*
ES_t  EXTI0_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI1_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI2_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI3_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI4_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI5_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI6_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI7_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI8_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI9_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI10_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI11_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI12_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI13_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI14_enuCallBack   		(void (*Copy_Vptr) (void));
ES_t  EXTI15_enuCallBack   		(void (*Copy_Vptr) (void));*/
#endif /* MCAL_INC_STM32F103XX_EXTI_DRIVER_H_ */
