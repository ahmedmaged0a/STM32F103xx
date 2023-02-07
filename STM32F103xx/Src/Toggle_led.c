/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include <STM32f103xx_GPIO_driver.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void wait_ms(uint32_t time)
{
	uint32_t i , j;
	for(i=0 ; i<time ; i++)
		for(j=0;j<500;j++);
}
void clock_init(void)
{
	//enable clock GPIO
	GPIOA_PERI_CLOCK_ENABLE();

	GPIOB_PERI_CLOCK_ENABLE();
}
void GPIO_init(void)
{
	GPIO_Handle_t PIN_Config;
	//PORTA

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_1;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	GPIO_enuInit(&PIN_Config);

	//GPIOA->CRL &= (0x00000000);

	//PORTB pin1 output push-pull
	PIN_Config.PGPIOx = GPIOB;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_1;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_10M;
	GPIO_enuInit(&PIN_Config);

	//PORTA pin13...input floating
	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_8;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_INPUT_FLO;
	GPIO_enuInit(&PIN_Config);

	//PORTB pin1 output push-pull
	PIN_Config.PGPIOx = GPIOB;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_13;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_10M;
	GPIO_enuInit(&PIN_Config);

}

int main(void)
{
	clock_init();
	GPIO_init();
	 uint8_t Local_u8Read1=0, Local_u8Read2=0;
	while(1)
	{
		GPIO_enuReadFromInputPin(GPIOA, GPIO_PIN_1,&Local_u8Read1);
		if(Local_u8Read1 == 1 )
		{
			GPIO_enuWriteToOutputPin(GPIOB, GPIO_PIN_1,GPIO_PIN_SET);
			//while(Local_u8Read1);
			wait_ms(200);
			GPIO_enuWriteToOutputPin(GPIOB, GPIO_PIN_1,GPIO_PIN_RESET);
			wait_ms(200);
		}
		 GPIO_enuReadFromInputPin(GPIOA, GPIO_PIN_8,&Local_u8Read2);
		if(Local_u8Read2==1)
		{
			GPIO_enuWriteToOutputPin(GPIOB, GPIO_PIN_13,GPIO_PIN_SET);
			wait_ms(200);
			GPIO_enuWriteToOutputPin(GPIOB, GPIO_PIN_13,GPIO_PIN_RESET);
			wait_ms(200);
		}

		wait_ms(500);

	}
}

