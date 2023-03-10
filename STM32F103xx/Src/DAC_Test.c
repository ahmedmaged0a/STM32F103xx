/**
 ******************************************************************************
 * @file           : DAC_test.c
 * @author         : Auto-generated by Ahmed Maged
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

#include <STM32f103xx_RCC_driver.h>
#include <STM32f103xx_GPIO_driver.h>
#include <STM32f103xx_SysTick_driver.h>
#include "../Inc/file.h"

volatile uint16_t i=0;
void voidSetDAC(void)
{
	GPIO_Handle_t PIN_Config;
	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.PGPIOx->ODR = Y_raw[i];
	i++;
	if(i==34087)
	{
		i=0;
	}
}
void clock_init(void)
{
	RCC_enuInitConfig();  //Choose System Clock to HSE 8MHZ
	GPIOA_PERI_CLOCK_ENABLE(); // Enable Clock to GPIOA

}
void GPIO_init(void)
{
	GPIO_Handle_t PIN_Config;
	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_0;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_1;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_2;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_3;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_4;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_5;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_6;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_7;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);
}
int main(void)
{

	clock_init();
	GPIO_init();
	MSTK_enuInit(SYS_AHB_8);
	MSTK_enuSetIntervalPeriodic(125,voidSetDAC);
	while(1);

	return 0 ;
}
