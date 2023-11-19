/*
 * F407_GPIO_Drivers.h
 *
 *  Created on: March 17, 2023
 *      Author: Ayuba Tahiru
 */

#ifndef INC_F407_GPIO_DRIVERS_H_
#define INC_F407_GPIO_DRIVERS_H_

#include "stm32f407.h"


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

/*****************************************************************************************************************
 * 										APIs Supported Drivers
 * ***************************************************************************************************************/
// Enable Clock
void GPIO_PCLK_Control(GPIOx_RegDef_t *pGPIOx, uint8_t ED);

// Initialization and De-Initialization
void GPIO_Init(GPIO_Handle_t *pGPIOxHandle);
void GPIO_DeInit(GPIOx_RegDef_t *pGPIOx);  //Reset from RCC RESET register


//Read, Write data
uint8_t GPIO_ReadFromInputPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIOx_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t PinValue);
void GPIO_WriteToOutputPort(GPIOx_RegDef_t *pGPIOx, uint16_t PortValue);
void GPIO_TogglePin(GPIOx_RegDef_t *pGPIOx, uint8_t PinNumber);


// IRQ Configuration and Handling
void GPIO_IRQConfig(uint8_t IRQ_Number, uint8_t IRQ_Priority, uint8_t IRQ_ED);
void GPIO_IRQHandling(uint8_t PinNumber);


#endif /* INC_F407_GPIO_DRIVERS_H_ */
