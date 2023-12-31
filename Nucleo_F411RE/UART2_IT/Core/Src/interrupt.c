/*
 * interrupt.c
 *
 *  Created on: Nov 7, 2023
 *      Author: user
 */
#include "main_app.h"

extern UART_HandleTypeDef Huart2;

void SysTick_Handler(void){
	HAL_IncTick();

	HAL_SYSTICK_IRQHandler();
}


void USART2_IRQHandler(void){
	HAL_UART_IRQHandler(&Huart2);
}
