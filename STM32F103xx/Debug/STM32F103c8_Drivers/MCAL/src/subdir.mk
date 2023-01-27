################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103c8_Drivers/MCAL/src/STM32F103xx_DMA_driver.c \
../STM32F103c8_Drivers/MCAL/src/STM32f103xx_EXTI_driver.c \
../STM32F103c8_Drivers/MCAL/src/STM32f103xx_GPIO_driver.c \
../STM32F103c8_Drivers/MCAL/src/STM32f103xx_NVIC_driver.c \
../STM32F103c8_Drivers/MCAL/src/STM32f103xx_RCC_driver.c \
../STM32F103c8_Drivers/MCAL/src/STM32f103xx_SysTick_driver.c 

OBJS += \
./STM32F103c8_Drivers/MCAL/src/STM32F103xx_DMA_driver.o \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_EXTI_driver.o \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_GPIO_driver.o \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_NVIC_driver.o \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_RCC_driver.o \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_SysTick_driver.o 

C_DEPS += \
./STM32F103c8_Drivers/MCAL/src/STM32F103xx_DMA_driver.d \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_EXTI_driver.d \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_GPIO_driver.d \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_NVIC_driver.d \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_RCC_driver.d \
./STM32F103c8_Drivers/MCAL/src/STM32f103xx_SysTick_driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103c8_Drivers/MCAL/src/STM32F103xx_DMA_driver.o: ../STM32F103c8_Drivers/MCAL/src/STM32F103xx_DMA_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/MCAL/src/STM32F103xx_DMA_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103c8_Drivers/MCAL/src/STM32f103xx_EXTI_driver.o: ../STM32F103c8_Drivers/MCAL/src/STM32f103xx_EXTI_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/MCAL/src/STM32f103xx_EXTI_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103c8_Drivers/MCAL/src/STM32f103xx_GPIO_driver.o: ../STM32F103c8_Drivers/MCAL/src/STM32f103xx_GPIO_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/MCAL/src/STM32f103xx_GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103c8_Drivers/MCAL/src/STM32f103xx_NVIC_driver.o: ../STM32F103c8_Drivers/MCAL/src/STM32f103xx_NVIC_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/MCAL/src/STM32f103xx_NVIC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103c8_Drivers/MCAL/src/STM32f103xx_RCC_driver.o: ../STM32F103c8_Drivers/MCAL/src/STM32f103xx_RCC_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/MCAL/src/STM32f103xx_RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103c8_Drivers/MCAL/src/STM32f103xx_SysTick_driver.o: ../STM32F103c8_Drivers/MCAL/src/STM32f103xx_SysTick_driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/MCAL/src/STM32f103xx_SysTick_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

