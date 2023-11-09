/*
 * interrupt.c
 *
 *  Created on: Nov 7, 2023
 *      Author: user
 */


void SysTick_Handler(void){
	HAL_IncTick();

	HAL_SYSTICK_IRQHandler();
}
