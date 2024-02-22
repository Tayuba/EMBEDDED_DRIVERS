################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/stm32SendData_toArduino.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/stm32SendData_toArduino.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/stm32SendData_toArduino.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"T:/EMBEDDED_DRIVERS/Disco_F407/PERIPHERAL_DRIVERS_AND_API_DEVELOPMENTS_MCU-F407/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/stm32SendData_toArduino.cyclo ./Src/stm32SendData_toArduino.d ./Src/stm32SendData_toArduino.o ./Src/stm32SendData_toArduino.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

