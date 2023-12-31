/*
 * main_app.c
 *
 *  Created on: Nov 7, 2023
 *      Author: user
 */


#include "main_app.h"
#include <string.h>

#define TRUE 1
#define FALSE 0

void SystemClockConfig(void);
void UART2_Init(void);
void Error_handler(void);
uint8_t convertToCaps(uint8_t data);
//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);

// Handle defined
UART_HandleTypeDef Huart2;

char *data_tx = "Running Application...\r\n";

uint8_t data_buffer[100];
uint8_t rcvd;
uint32_t cnt = 0;
uint8_t rep_Complete = FALSE;

int main(void){
	HAL_Init();
	SystemClockConfig();
	UART2_Init();

	uint16_t length_of_data = strlen(data_tx);
	if (HAL_UART_Transmit(&Huart2, (uint8_t *)data_tx, length_of_data, HAL_MAX_DELAY) != HAL_OK){
		Error_handler();
	}

	while(rep_Complete != TRUE){
		HAL_UART_Receive_IT(&Huart2, &rcvd, 1);
	}


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

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if (rcvd == '\r'){
		rep_Complete = TRUE;
		data_buffer[cnt++] = '\r';
		HAL_UART_Transmit(huart, data_buffer, cnt, HAL_MAX_DELAY);
	}
	else{
		data_buffer[cnt++] = convertToCaps(rcvd);
	}

}

void Error_handler(void){
	while(1);
}


