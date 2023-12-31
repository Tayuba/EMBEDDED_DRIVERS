/*
 * main_app.c
 *
 *  Created on: Nov 7, 2023
 *      Author: user
 */

#include "stm32f4xx_hal.h"
#include "main_app.h"
#include <string.h>

void SystemClockConfig(void);
void UART2_Init(void);
void Error_handler(void);
uint8_t convertToCaps(uint8_t data);

// Handle defined
UART_HandleTypeDef Huart2;

char *data_tx = "Running Application...\r\n";


int main(void){
	HAL_Init();
	SystemClockConfig();
	UART2_Init();

	uint16_t length_of_data = strlen(data_tx);
	if (HAL_UART_Transmit(&Huart2, (uint8_t *)data_tx, length_of_data, HAL_MAX_DELAY) != HAL_OK){
		Error_handler();
	}

	uint8_t rcvd;
	uint8_t data_buffer[100];
	uint32_t cnt = 0;

	while(1){
		HAL_UART_Receive(&Huart2, &rcvd, 1, HAL_MAX_DELAY);

		if (rcvd == '\r'){
			break;
		}

		else {
			data_buffer[cnt++] = convertToCaps(rcvd);
		}

	}
	data_buffer[cnt++] = '\r';
	HAL_UART_Transmit(&Huart2, data_buffer, cnt, HAL_MAX_DELAY);


	while(1);
	return 0;
}

void SystemClockConfig(void){

}


void UART2_Init(void){
	// Linking
	Huart2.Instance = USART2;

	// Parameter Initialization
	Huart2.Init.BaudRate = 115200;
	Huart2.Init.WordLength = UART_WORDLENGTH_8B;
	Huart2.Init.StopBits = UART_STOPBITS_1;
	Huart2.Init.Parity = UART_PARITY_NONE;
	Huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	Huart2.Init.Mode = UART_MODE_TX_RX;

	if (HAL_UART_Init(&Huart2) != HAL_OK){
		Error_handler();
	}
}

uint8_t convertToCaps(uint8_t data){
	if (data >= 'a' && data <= 'z'){
		data = data - ('a' - 'A');
	}

	return data;
}

void Error_handler(void){
	while(1);
}


