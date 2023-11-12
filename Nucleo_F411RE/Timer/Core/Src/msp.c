/*
 * msp.c
 *
 *  Created on: 02-Jun-2018
 *      Author: Ayuba
 */


#include "main_app.h"

void HAL_MspInit(void)
{
 //Here will do low level processor specific inits.
	//1. Set up the priority grouping of the arm cortex mx processor
	HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

	//2. Enable the required system exceptions of the arm cortex mx processor
	SCB->SHCSR |= 0x7 << 16; //usage fault, memory fault and bus fault system exceptions

	//3. configure the priority for the system exceptions
	HAL_NVIC_SetPriority(MemoryManagement_IRQn,0,0);
	HAL_NVIC_SetPriority(BusFault_IRQn,0,0);
	HAL_NVIC_SetPriority(UsageFault_IRQn,0,0);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim){
	//1. Enable clock for the Timer
	__HAL_RCC_TIM3_CLK_ENABLE();

	//2. Enable IRQ of Timer
	HAL_NVIC_EnableIRQ(TIM3_IRQn);

	//3. Setup Priority of IRQ Number
	HAL_NVIC_SetPriority(TIM3_IRQn, 15, 0);
}
