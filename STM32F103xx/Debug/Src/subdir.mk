################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/DAC_Test.c \
../Src/DMA_Test1.c \
../Src/EXTI_Test.c \
../Src/STP_Example.c \
../Src/SysTick_Test.c \
../Src/TestLEDMRX.c \
../Src/Toggle_led.c 

OBJS += \
./Src/DAC_Test.o \
./Src/DMA_Test1.o \
./Src/EXTI_Test.o \
./Src/STP_Example.o \
./Src/SysTick_Test.o \
./Src/TestLEDMRX.o \
./Src/Toggle_led.o 

C_DEPS += \
./Src/DAC_Test.d \
./Src/DMA_Test1.d \
./Src/EXTI_Test.d \
./Src/STP_Example.d \
./Src/SysTick_Test.d \
./Src/TestLEDMRX.d \
./Src/Toggle_led.d 


# Each subdirectory must supply rules for building sources it contributes
Src/DAC_Test.o: ../Src/DAC_Test.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/DAC_Test.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/DMA_Test1.o: ../Src/DMA_Test1.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/DMA_Test1.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/EXTI_Test.o: ../Src/EXTI_Test.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/EXTI_Test.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/STP_Example.o: ../Src/STP_Example.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/STP_Example.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/SysTick_Test.o: ../Src/SysTick_Test.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/SysTick_Test.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/TestLEDMRX.o: ../Src/TestLEDMRX.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/TestLEDMRX.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/Toggle_led.o: ../Src/Toggle_led.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/STM32F103c8_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/Toggle_led.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

