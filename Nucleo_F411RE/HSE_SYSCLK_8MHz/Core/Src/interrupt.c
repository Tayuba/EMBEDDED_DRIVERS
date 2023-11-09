/*
 * interrupt.c
 *
 *  Created on: Nov 7, 2023
 *      Author: user
 */
#include "main_app.h"

void SysTick_Handler(void){
	HAL_IncTick();

	HAL_SYSTICK_IRQHandler();
}
