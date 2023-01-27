################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/TestLEDMRX.c 

OBJS += \
./Src/TestLEDMRX.o 

C_DEPS += \
./Src/TestLEDMRX.d 


# Each subdirectory must supply rules for building sources it contributes
Src/TestLEDMRX.o: ../Src/TestLEDMRX.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/Stm32f103c6_Drivers/MCAL/inc" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/Stm32f103c6_Drivers/Include" -I"C:/Users/bayer/STM32CubeIDE/workspace_1.4.0/STM32F103xx/Stm32f103c6_Drivers/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Src/TestLEDMRX.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

