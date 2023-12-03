################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/toggle_interruptBT_MY_API.c 

OBJS += \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/toggle_interruptBT_MY_API.o 

C_DEPS += \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/toggle_interruptBT_MY_API.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"T:/EMBEDDED_DRIVERS/Disco_F407/PERIPHERAL_DRIVERS_AND_API_DEVELOPMENTS_MCU-F407/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/toggle_interruptBT_MY_API.cyclo ./Src/toggle_interruptBT_MY_API.d ./Src/toggle_interruptBT_MY_API.o ./Src/toggle_interruptBT_MY_API.su

.PHONY: clean-Src

