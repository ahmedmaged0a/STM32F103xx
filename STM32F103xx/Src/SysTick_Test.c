/**
 ******************************************************************************
 * @file           : SysTick_Test.c
 * @author         : Ahmed Maged
 * @brief          : Test SysTick Driver
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
/*#include <STM32f103xx_RCC_driver.h>
#include <STM32f103xx_GPIO_driver.h>
#include <STM32f103xx_SysTick_driver.h>
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void clock_init(void)
{
	RCC_enuInitConfig();
	GPIOA_PERI_CLOCK_ENABLE();
	GPIOB_PERI_CLOCK_ENABLE();
}
void GPIO_init(void)
{
	GPIO_Handle_t PIN_Config;
	PIN_Config.PGPIOx = GPIOA;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_1;
	PIN_Config.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_2M;
	GPIO_enuInit(&PIN_Config);

}
int main(void)
{
	clock_init();
	GPIO_init();
	MSTK_enuInit(SYS_AHB_8);
	//MSTK_enuSetIntervalSingle(1000000, Toggle);
	while(1)
	{
		GPIO_enuToggleOutputPin(GPIOA, GPIO_PIN_1);
		_delay_ms(1000);
		GPIO_enuToggleOutputPin(GPIOA, GPIO_PIN_1);
		_delay_ms(1000);
	}

}*/
