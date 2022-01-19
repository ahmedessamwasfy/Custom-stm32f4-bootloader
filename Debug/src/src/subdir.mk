################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/src/Bassic_Timer.c \
../src/src/DMA.c \
../src/src/EEprom_Emulation.c \
../src/src/Flash_Hal.c \
../src/src/GPT_2TO5.c \
../src/src/HelpFun.c \
../src/src/ImageHeader.c \
../src/src/SysTick.c \
../src/src/crc.c \
../src/src/exti.c \
../src/src/gpio.c \
../src/src/memcpy.c \
../src/src/myEXIT.c \
../src/src/myGPIO.c \
../src/src/myGeneral_Purpose_Timer_T2_T5.c \
../src/src/myIRQ.c \
../src/src/myRCC.c \
../src/src/myUSART1.c \
../src/src/nvic.c 

OBJS += \
./src/src/Bassic_Timer.o \
./src/src/DMA.o \
./src/src/EEprom_Emulation.o \
./src/src/Flash_Hal.o \
./src/src/GPT_2TO5.o \
./src/src/HelpFun.o \
./src/src/ImageHeader.o \
./src/src/SysTick.o \
./src/src/crc.o \
./src/src/exti.o \
./src/src/gpio.o \
./src/src/memcpy.o \
./src/src/myEXIT.o \
./src/src/myGPIO.o \
./src/src/myGeneral_Purpose_Timer_T2_T5.o \
./src/src/myIRQ.o \
./src/src/myRCC.o \
./src/src/myUSART1.o \
./src/src/nvic.o 

C_DEPS += \
./src/src/Bassic_Timer.d \
./src/src/DMA.d \
./src/src/EEprom_Emulation.d \
./src/src/Flash_Hal.d \
./src/src/GPT_2TO5.d \
./src/src/HelpFun.d \
./src/src/ImageHeader.d \
./src/src/SysTick.d \
./src/src/crc.d \
./src/src/exti.d \
./src/src/gpio.d \
./src/src/memcpy.d \
./src/src/myEXIT.d \
./src/src/myGPIO.d \
./src/src/myGeneral_Purpose_Timer_T2_T5.d \
./src/src/myIRQ.d \
./src/src/myRCC.d \
./src/src/myUSART1.d \
./src/src/nvic.d 


# Each subdirectory must supply rules for building sources it contributes
src/src/%.o: ../src/src/%.c src/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F42_43xxx -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -DUSE_STM32F429I_DISCO -c -I../src -I../Libraries/CMSIS/Include -I../Libraries/Device/ST/STM32F4xx/Include -I../Utilities/Common -I../Utilities/STM32F429I-Discovery -I"C:/Users/Ahmed Wasfy.DESKTOP-8255SRK/Documents/true studio/BootloaderV1/src/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

