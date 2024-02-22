################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/Src/F407_GPIO_Drivers.c \
../drivers/Src/F407_SPI_Drivers.c 

OBJS += \
./drivers/Src/F407_GPIO_Drivers.o \
./drivers/Src/F407_SPI_Drivers.o 

C_DEPS += \
./drivers/Src/F407_GPIO_Drivers.d \
./drivers/Src/F407_SPI_Drivers.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/Src/%.o drivers/Src/%.su drivers/Src/%.cyclo: ../drivers/Src/%.c drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"T:/EMBEDDED_DRIVERS/Disco_F407/PERIPHERAL_DRIVERS_AND_API_DEVELOPMENTS_MCU-F407/drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-Src

clean-drivers-2f-Src:
	-$(RM) ./drivers/Src/F407_GPIO_Drivers.cyclo ./drivers/Src/F407_GPIO_Drivers.d ./drivers/Src/F407_GPIO_Drivers.o ./drivers/Src/F407_GPIO_Drivers.su ./drivers/Src/F407_SPI_Drivers.cyclo ./drivers/Src/F407_SPI_Drivers.d ./drivers/Src/F407_SPI_Drivers.o ./drivers/Src/F407_SPI_Drivers.su

.PHONY: clean-drivers-2f-Src

