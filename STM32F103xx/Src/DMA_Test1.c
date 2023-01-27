/**
 ******************************************************************************
 * @file           : DMA_Example.c
 * @author         : Ahmed Maged
 * @brief          : DMA Test
 *******************************************************************************/
#include <STM32f103xx_RCC_driver.h>
#include <STM32f103xx_NVIC_driver.h>
#include <STM32F103xx_DMA_driver.h>
uint32_t arr4[500]={1,2,5,4,8,9,5,7};
int main(void)
{
	DMA_Handle_t DMA_Config_t;
	DMA_Config_t.DMA1_CIRCULAR=DISABLE;
	DMA_Config_t.DMA1_ChannelNumber=1;
	DMA_Config_t.DMA1_Direction = MEM_TO_MEM;
	DMA_Config_t.DMA1_MEM_INC=ENABLE;
	DMA_Config_t.DMA1_PERI_INC=ENABLE;
	DMA_Config_t.DMA1_MSIZE=WORD;
	DMA_Config_t.DMA1_PSIZE=WORD;
	DMA_Config_t.DMA1_Priority=DMA_VERY_HIGH;
	uint32_t arr1[500] = {5,1,4,5,3,5,1,4,5,3,5,1,4,5,3,1,1,1,5,8};
	uint32_t arr2[500]=  {0};

	uint32_t arr3[500] = {0};

	RCC_enuInitConfig();
	//Enable DMA Clock
	DMA_PERI_CLOCK_ENABLE();
	//Setup Configuration
	DMA_enuConfigurationSetup(&DMA_Config_t);
	//Enable DMA Interrupt
	MNVIC_enuEnableInterrupt(Interrupt_DMA1_Channel1);
	//Setup Data
	DMA_enuSetAddress(CHANNEL1, arr1, arr2, 500);
	//Enable Interrupt
	DMA_enuInterruptEnable(CHANNEL1, DMA_TCIE);
	//Start
	DMA_enuEnable(CHANNEL1);

	//Processor Work
	for(uint16_t i = 0 ; i<500;i++)
	{
		arr4[i] = arr3[i];
	}
	while(1)
	{

	}
	return 0;
}
