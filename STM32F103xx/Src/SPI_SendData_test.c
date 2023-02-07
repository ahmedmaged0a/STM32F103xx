/**
 ******************************************************************************
 * @file           : SPI_SendData_test.c
 * @author         : Ahmed Maged
 * @brief          : DMA Test
 *******************************************************************************/
#include "STM32f103xx_GPIO_driver.h"
#include "STM32F103xx_SPI_driver.h"
#include <string.h>

void SPI_GPIOInit(void)
{
	/*Bit 0 SPI1_REMAP: SPI1 remapping
	This bit is set and cleared by software. It controls the mapping of SPI1 NSS, SCK, MISO,
	MOSI alternate functions on the GPIO ports.
	0: No remap (NSS/PA4, SCK/PA5, MISO/PA6, MOSI/PA7)
	1: Remap (NSS/PA15, SCK/PB3, MISO/PB4, MOSI/PB5)*/
	GPIO_Handle_t SPIPins;
	SPIPins.PGPIOx = GPIOB;
	SPIPins.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_1;
	SPIPins.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	SPIPins.GPIO_PinConfig_t.GPIO_PinSpeed = GPIO_SPEED_10M;
	GPIO_enuInit(&SPIPins);
	//SCK
	SPIPins.PGPIOx = GPIOA;
	SPIPins.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_OUTPUT_PP;
	SPIPins.GPIO_PinConfig_t.GPIO_PinNumber =GPIO_SPEED_10M;
	SPIPins.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_5;
	GPIO_enuInit(&SPIPins);
	//MOSI
	SPIPins.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_7;
	GPIO_enuInit(&SPIPins);
	//MISO
	SPIPins.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_6;
	GPIO_enuInit(&SPIPins);
	//NSS
	SPIPins.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_4;
	GPIO_enuInit(&SPIPins);
}
void SPI1_Init(void)
{
	SPI_Handle_t SPI1Config;
	SPI1Config.pSPIx=SPI1;
	SPI1Config.SPIConfig.SPI_BusConfig=SPI_BUS_CONFIG_FD;
	SPI1Config.SPIConfig.SPI_DeviceMode=SPI_DEVICE_MODE_MASTER;
	SPI1Config.SPIConfig.SPI_SclkSpeed=SPI_SCLK_SPEED_DIV2;
	SPI1Config.SPIConfig.SPI_DFF = SPI_DFF_16BITS;
	SPI1Config.SPIConfig.SPI_CPHA = SPI_CPOL_LOW;
	SPI1Config.SPIConfig.SPI_CPOL = SPI_CPOL_LOW;
	SPI1Config.SPIConfig.SPI_SSM = SPI_SSM_EN;
	SPI_Init(&SPI1Config);
}
int main(void)
{
	char user_input[] = "Hello Maged";
	SPI_GPIOInit();
	SPI1_Init();
	SPI_SSIControl(SPI1, ENABLE);
	SPI_PeripheralControl(SPI1, ENABLE);
	SPI_SendData(SPI1 ,(uint8_t*)user_input, strlen(user_input));
	while(1)
	{

	}
	return 0;
}
