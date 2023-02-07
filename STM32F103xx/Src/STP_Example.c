/**
 ******************************************************************************
 * @file           : STP_Example.c
 * @author         : Ahmed Maged
 * @brief          : Serial to parallel test
 *******************************************************************************/
#include "STP_74HC595.h"
#include "STM32f103xx_SysTick_driver.h"
int main(void)
{
	RCC_enuInitConfig();
	GPIOA_PERI_CLOCK_ENABLE();
	// AHB = EXT = 8MHZ & CLOCK OF MSTK = AHB / 8 = 8MHZ / 8 = 1MHZ = 1 Micro For Each Count
	MSTK_enuInit(SYS_AHB_8);
	STP_strHandle STP_Handle;
	//DATA
	STP_Handle.STP_PortConfig.STP_u8SDataPort=GPIOA;
	STP_Handle.STP_PinConfig.STP_u8SDataPin = GPIO_PIN_0;
	//Shift Reg
	STP_Handle.STP_PortConfig.STP_u8ShClockPort=GPIOA;
	STP_Handle.STP_PinConfig.STP_u8ShClockPin = GPIO_PIN_1;
	//Store Reg
	STP_Handle.STP_PortConfig.STP_u8StClockPort=GPIOA;
	STP_Handle.STP_PinConfig.STP_u8StClockPin = GPIO_PIN_2;
	STP_enuInit(&STP_Handle);

	uint8_t counter = 0;
	while(1)
	{
		for (counter = 0 ; counter<8;counter++)
		{
			STP_enuSendSynchronus(&STP_Handle,(1<<counter));
			MSTK_enuSetBusyWait(300000);
		}
	}
return 0;
}

