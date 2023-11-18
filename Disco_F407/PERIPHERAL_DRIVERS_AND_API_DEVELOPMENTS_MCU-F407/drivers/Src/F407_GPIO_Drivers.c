/*
 * F407_GPIO_Drivers.c
 *
 *  Created on: March 17, 2023
 *      Author: Ayuba Tahiru
 */


#include 	"F407_GPIO_Drivers.h"
/*********** GPIOx Pin Configuration  **********/
typedef struct {
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinOType;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinAltFuncMode;
}GPIOx_PinConfig_t;


/*********** GPIOx Handle **********/
typedef struct {
	GPIOx_RegDef_t *pGPIOx;				/* Holds the base address of the GPIO port of which the pin belongs */
	GPIOx_PinConfig_t GPIO_PinConfig;	/* Holds the pin configuration of GPIOx */
}GPIO_Handle_t;
