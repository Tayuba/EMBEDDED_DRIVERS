/*
 * msp.c
 *
 *  Created on: Nov 7, 2023
 *      Author: user
 */
#include "stm32f4xx_hal.h"

void HAL_MspInit(void){
	/********	Low Level Processor Specific Intits **********/
	//1. Configure the priority grouping of ARM CORTEX Mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable required processor system exceptions
	SCB->SHCSR |=  0x7 << 16; // enabled: usgfaultene, busfaultena, and memfaulten system exception

	//3. Configure the priority of the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0, 0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0, 0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0, 0);

}

void HAL_UART_MspInit(UART_HandleTypeDef *huart){
	/********	Low Level USART2 Peripheral Intits **********/
	GPIO_InitTypeDef GPIO_UART;

	//1. Enable the clock for usart peripheral and GPIOA
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//2. Do pin muxing configuration
	GPIO_UART.Pin = GPIO_PIN_2;
	GPIO_UART.Mode = GPIO_MODE_AF_PP;
	GPIO_UART.Pull = GPIO_PULLUP;
	GPIO_UART.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_UART.Alternate = GPIO_AF7_USART2;
	HAL_GPIO_Init(GPIOA, &GPIO_UART);

	GPIO_UART.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOA, &GPIO_UART);

	//3. Enable IRQ and set up priority (NVIC settings)
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	HAL_NVIC_SetPriority(USART2_IRQn, 0, 0);

}
