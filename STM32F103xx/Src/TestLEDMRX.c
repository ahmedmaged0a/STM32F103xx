/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	15 OCT 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/
#include "LED_MAX.h"
#include "STM32f103xx_RCC_driver.h"
#include "STM32f103xx_GPIO_driver.h"
#include "STM32f103xx_SysTick_driver.h"
uint8_t Data_Array[8] = {0,124,18,18,18,124,0,0};

int main(void)
{
	//NEW
	//Init Clock Source
	RCC_enuInitConfig();
	//Enable GPIOA,B Clock
	GPIOA_PERI_CLOCK_ENABLE();
	GPIOB_PERI_CLOCK_ENABLE();
	//LED Matrix Configurations
	LED_MRX_Handle_t LED_MRX_Config = {
			{GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7},
			{GPIOA,GPIOA,GPIOA,GPIOA,GPIOA,GPIOA,GPIOA,GPIOA},
			{GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10},
			{GPIOB,GPIOB,GPIOB,GPIOB,GPIOB,GPIOB,GPIOB,GPIOB},
	};
	//Init Systick
	MSTK_enuInit(SYS_AHB_8);
	//LED_Matrix Configurations Setups
	HLED_MRX_voidInit(&LED_MRX_Config);
	//Display Data on LED_Matrix
	HLED_MRX_voidDisplay(&LED_MRX_Config, Data_Array);

	return 0;
}

