/*
 * F407_SPI_Drivers.c
 *
 *  Created on: March 1, 2023
 *      Author: Ayuba Tahiru
 */
#include 	"F407_SPI_Drivers.h"

// Initialization and De-Initialization
// Enable Clock
/********************************************************************************
 * @fn					-SPI_PCLK_Control
 *
 * @brief				-Enable and Disable a clock of a given SPI port
 *
 * @param[in]			-Takes base address of a given GPIO
 * @param[in]			-Takes Enable value(1) or Disable value(0)
 * @param[in]			-
 *
 * @return				-returns nothing(None)
 *
 * @Note				-SPI port to be enable or disable base address must be passed
 */
void SPI_PCLK_Control(SPIx_RegDef_t *pSPIx, uint8_t ED){
	if (ED == ENABLE){
		if (pSPIx == SPI1){
			SPI1_PCLK_ENABLE();
		}else if (pSPIx == SPI2){
			SPI2_PCLK_ENABLE();
		}else if (pSPIx == SPI3){
			SPI3_PCLK_ENABLE();
		}
	}else {
		if (pSPIx == SPI1){
			SPI1_PCLK_DISABLE();
		}else if (pSPIx == SPI2){
			SPI2_PCLK_DISABLE();
		}else if (pSPIx == SPI3){
			SPI3_PCLK_DISABLE();
		}
	}

}

// Initialization
/********************************************************************************
 * @fn					-SPI_Init
 *
 * @brief				-Initialize the various configurations of a given SPI port
 *
 * @param[in]			-Takes SPI handle address
 * @param[in]			-
 * @param[in]			-
 *
 * @return				-returns nothing(None)
 *
 * @Note				-None
 */
void SPI_Init(SPI_Handle_t *pSPIxHandle){

}
void SPI_DeInit(SPIx_RegDef_t *pSPIx){

}


//Data Sending and Receiving
void SPI_DataSend(SPIx_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t DataLen){

}
void SPI_DataReceive(SPIx_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t DataLen){

}

// IRQ Configuration and ISR Handling
void SPI_IRQInterruptConfig(uint8_t IRQ_Number, uint8_t IRQ_ED){

}
void SPI_IRQHandling(SPI_Handle_t *pSPIxHandle){

}
void SPI_IRQPriorityConfig(uint8_t IRQ_Priority, uint8_t IRQ_Number){

}
