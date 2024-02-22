/*
 * stm32SendData_toArduino.c
 *
 *  Created on: Feb 21, 2024
 *      Author: Ayuba Tahiru
 */



#include "stm32f407.h"
#include <string.h>

void InitGPIO_toSPI2_Pins(void);
void Init_SPI2(void);
void delay(void);
void ButtenPush(void);

/*
 * PB12---->SPI2_NSS
 * PB13---->SPI2_SCK
 * PB14---->SPI2_MISO
 * PB15---->SPI2_MOSI
 *
 *Alternate Function Mode---->AF5
 * */

int main(void){
	// Data to send
	char data[] = "Ayuba Tahiru";

	// Function to Initialize GPIO as SPI2
	InitGPIO_toSPI2_Pins();



	// Function to Initialize SPI2
	Init_SPI2();

	// Initialize Button
	ButtenPush();


	while(1){
		// Enable SSOE
		SSOE_Config(SPI2, ENABLE);

		while(GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == FLAG_RESET);
		delay();

		// Enable SPI Protocol
		SPI_ProtocolEnable(SPI2, ENABLE);

		// Send Byte Info to Slave
		uint8_t data_Len = strlen(data);
		SPI_DataSend(SPI2, &data_Len, 1);

		// Send Data
		SPI_DataSend(SPI2, (uint8_t*)data, data_Len);

		// Tx Finished
		while(Check_FlagStatus(SPI2, SPI_BUSY_FLAG));
		SPI_ProtocolEnable(SPI2, DISABLE);

	}


	return 0;
}

void InitGPIO_toSPI2_Pins(void){
	// Call My API GPIO Handle typedef struct
	GPIO_Handle_t SPI_Pins, BTN_A0;

	// Select GPIO Port base address where SPI2 is connected
	SPI_Pins.pGPIOx = GPIOB;

/*
************** Configure GPIOB to become SPI *****************
* */
	// 1. Pin Mode set to Alternate function
	SPI_Pins.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_ALTFUNC;
	// 2. Select Alternate Function Number to be 5
	SPI_Pins.GPIO_PinConfig.GPIO_PinAltFuncMode = 5;
	// 3. Using Push Pull Output type for SPI
	SPI_Pins.GPIO_PinConfig.GPIO_PinOType = GPIO_OTYPE_PP;
	// 4. Pin Control
	SPI_Pins.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	// 5. Speed
	SPI_Pins.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEEDR_MEDIUM;

	/************** Pin Number Initialization *******************/
	// 1. SCK
	SPI_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_Init(&SPI_Pins);
	// 2. NSS
	SPI_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIO_Init(&SPI_Pins);
	// 3. MISO
	SPI_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GPIO_Init(&SPI_Pins);
	// 4. MOSI
	SPI_Pins.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;

	GPIO_Init(&SPI_Pins);
	GPIO_Init(&BTN_A0);						// Initialize the GPIOA
}

void Init_SPI2(void){
	// Call My API SPI2 Handle typedef struct
	SPI_Handle_t SPI2_Pins;

	// Select SPI2
	SPI2_Pins.pSPIx = SPI2;

/*
	************** Configure SPI2 *****************
* */
	// 1. SPI Bus as Full Duplex
	SPI2_Pins.SPI_PinConfig.SPI_BusConfig = SPI_BUS_CONFIG_FULL_DUPLEX;
	// 2. SPI Mode as Master
	SPI2_Pins.SPI_PinConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	// 3. SPI Speed as Maximum (2MHz)
	SPI2_Pins.SPI_PinConfig.SPI_SclkSpeed = SPI_SCLK_SPEED_DIV8;
	// 4. SPI DFF  as 8 Bits
	SPI2_Pins.SPI_PinConfig.SPI_DFF = SPI_DFF_8BITS;
	// 5. Clock Polarity
	SPI2_Pins.SPI_PinConfig.SPI_CPOL = SPI_CPOL_LOW;
	// 6. Clock Phase
	SPI2_Pins.SPI_PinConfig.SPI_CPHA = SPI_CPHA_LOW;
	// 7. Slave management
	SPI2_Pins.SPI_PinConfig.SPI_SSM = SPI_SSM_HW;

	// Initialize configuration
	SPI_Init(&SPI2_Pins);

}

void ButtenPush(void){

	GPIO_Handle_t BTN_A0;

	//Button Configuration
	BTN_A0.pGPIOx = GPIOA;
	BTN_A0.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	BTN_A0.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	BTN_A0.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEEDR_MEDIUM;
	BTN_A0.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;

	// CALLING My API
//	GPIO_PCLK_Control(GPIOA, ENABLE);		// Enable the clock
	GPIO_Init(&BTN_A0);						// Initialize the GPIOA
}

void delay(void){
	for (uint32_t i = 0; i <500000/2; i++){

	}
}

