/*
 * toggleLED_MY_API.c
 *
 *  Created on: March 17, 2023
 *      Author: Ayuba Tahiru
 */


#include "stm32f407.h"

void delay(void);

int main(void){
	GPIO_Handle_t LED_D12;

	LED_D12.pGPIOx = GPIOD;
	LED_D12.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	LED_D12.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	LED_D12.GPIO_PinConfig.GPIO_PinSpeed = GPIO_OSPEEDR_MEDIUM;
	LED_D12.GPIO_PinConfig.GPIO_PinOType= GPIO_OTYPE_PP;
//	LED_D12.GPIO_PinConfig.GPIO_PinOType= GPIO_OTYPER_OD;
	LED_D12.GPIO_PinConfig.GPIO_PinPuPdControl= GPIO_NO_PUPD;


	// CALLING My API
	GPIO_PCLK_Control(GPIOD, ENABLE);		// Enable the clock
	GPIO_Init(&LED_D12);					// Initialize the GPIOD

	while(1){
		GPIO_TogglePin(GPIOD, GPIO_PIN_NO_12);
		delay();
	}

    /* Loop forever */
	for(;;);
}

void delay(void){
	for (uint32_t i = 0; i <500000; i++){

	}
}
