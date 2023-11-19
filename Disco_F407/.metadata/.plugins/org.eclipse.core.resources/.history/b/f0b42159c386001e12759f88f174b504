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

/*****************************************************************************************************************
 * 										APIs Supported Drivers
 * ***************************************************************************************************************/
//Clock, Initialization and De-Initialization
void GPIO_PCLK_Control(void);
void GPIO_Init(void);
void GPIO_DeInit(void);


//Read, Write data
void GPIO_ReadFromInputPin(void);
void GPIO_ReadFromInputPort(void);
void GPIO_WriteToOutputPin(void);
void GPIO_WriteToOutputPort(void);
void GPIO_TogglePin(void);

// IRQ Configuration and Handling
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);
