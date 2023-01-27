################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103c8_Drivers/HAL/src/LED_MAX.c \
../STM32F103c8_Drivers/HAL/src/STP_74HC595.c 

OBJS += \
./STM32F103c8_Drivers/HAL/src/LED_MAX.o \
./STM32F103c8_Drivers/HAL/src/STP_74HC595.o 

C_DEPS += \
./STM32F103c8_Drivers/HAL/src/LED_MAX.d \
./STM32F103c8_Drivers/HAL/src/STP_74HC595.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103c8_Drivers/HAL/src/LED_MAX.o: ../STM32F103c8_Drivers/HAL/src/LED_MAX.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/HAL/src/LED_MAX.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103c8_Drivers/HAL/src/STP_74HC595.o: ../STM32F103c8_Drivers/HAL/src/STP_74HC595.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103c8_Drivers/HAL/src/STP_74HC595.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

