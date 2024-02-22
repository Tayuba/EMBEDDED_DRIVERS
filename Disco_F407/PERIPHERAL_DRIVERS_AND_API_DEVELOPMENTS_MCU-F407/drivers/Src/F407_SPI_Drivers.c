/*
 * F407_SPI_Drivers.c
 *
 *  Created on: March 1, 2023
 *      Author: Ayuba Tahiru
 */
//#include 	"F407_SPI_Drivers.h"
#include 	"stm32f407.h"

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

// Enables the SPI Peripheral Protocol
void SPI_ProtocolEnable(SPIx_RegDef_t *pSPIx, uint8_t ED){
	if (ED == ENABLE){
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	}else{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}

// Set SSI
void SSI_Config(SPIx_RegDef_t *pSPIx, uint8_t ED){
	if (ED == ENABLE){
		pSPIx->CR1 |= (1 << SPI_CR1_SSI);
	}else{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
	}
}

// Config SSOE
void SSOE_Config(SPIx_RegDef_t *pSPIx, uint8_t ED){
	if (ED == ENABLE){
		pSPIx->CR2 |= (1 << SPI_CR2_SSOE);
	}else{
		pSPIx->CR2 &= ~(1 << SPI_CR2_SSOE);
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
	uint32_t temp = 0;

	// Enable Clock before use
	SPI_PCLK_Control(pSPIxHandle->pSPIx, ENABLE);

	// 1. Device mode
	temp |= (pSPIxHandle->SPI_PinConfig.SPI_DeviceMode << SPI_CR1_MSTR);

	// 2. Bus configuration
	if(pSPIxHandle->SPI_PinConfig.SPI_BusConfig == SPI_BUS_CONFIG_FULL_DUPLEX){
		// Clear BIDIMODE
		temp &= ~(1 << SPI_CR1_BIDIMODE);
	}else if(pSPIxHandle->SPI_PinConfig.SPI_BusConfig == SPI_BUS_CONFIG_HALP_DUPLEX){
		// Set BIDIMODE
		temp |= (1 << SPI_CR1_BIDIMODE);
	}else if(pSPIxHandle->SPI_PinConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RX){
		// Clear BIDIMODE
		temp &= ~(1 << SPI_CR1_BIDIMODE);
		// SetReceive-only mode)
		temp |= (1 << SPI_CR1_RXONLY );
	}

	// 3. SPI serial clock speed
	temp |= (pSPIxHandle->SPI_PinConfig.SPI_SclkSpeed << SPI_CR1_BR);

	// 4. Data frame format
	temp |= (pSPIxHandle->SPI_PinConfig.SPI_DFF << SPI_CR1_DFF);

	// 5. Clock polarity
	temp |= (pSPIxHandle->SPI_PinConfig.SPI_CPOL << SPI_CR1_CPOL);

	// 6. Clock polarity
	temp |= (pSPIxHandle->SPI_PinConfig.SPI_CPHA << SPI_CR1_CPHA);

	// 7. Clock polarity
	if (pSPIxHandle->SPI_PinConfig.SPI_SSM == SPI_SSM_SW){
		// Software slave management enabled
		temp |= (1 << SPI_CR1_SSM);
	}else if(pSPIxHandle->SPI_PinConfig.SPI_SSM == SPI_SSM_HW){
		// Software slave management disabled
		temp &= ~(1 << SPI_CR1_SSM);
	}

	// Assigned all configured bit fields to control register 1
	pSPIxHandle->pSPIx->CR1 = temp;


}

// De-Initialization
/********************************************************************************
 * @fn					-SPI_DeInit
 *
 * @brief				-De-Initialize the various configurations of a given SPI port
 *
 * @param[in]			-Takes SPI handle address
 * @param[in]			-
 * @param[in]			-
 *
 * @return				-returns nothing(None)
 *
 * @Note				-None
 */
void SPI_DeInit(SPIx_RegDef_t *pSPIx){
	if (pSPIx== SPI1){
		SPI1_RESET();
	}else if (pSPIx == SPI2){
		SPI2_RESET();
	}else if (pSPIx == SPI3){
		SPI3_RESET();
	}
}

uint8_t Check_FlagStatus(SPIx_RegDef_t *pSPIx, uint32_t FlagName){

	if(pSPIx->SR & FlagName){
		return FLAG_SET;
	}

	return FLAG_RESET;
}

// Data Sending
/********************************************************************************
 * @fn					-SPI_DataSend
 *
 * @brief				-Send data
 *
 * @param[in]			-Takes SPI register address
 * @param[in]			-Tx buffer register address
 * @param[in]			-Takes Data length
 *
 * @return				-returns nothing(None)
 *
 * @Note				-This is a blocking / Polling call function
 */
void SPI_DataSend(SPIx_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t DataLen){
	while (DataLen > 0){
		// 1. Wait for TXE to be empty
		while (Check_FlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);

		// 2. Check DFF size
		if (pSPIx->CR1 & (1 << SPI_CR1_DFF)){
			// 16 Bits DFF
			//Load Data from Tx buffer into DR
			pSPIx->DR = *((uint16_t*)pTxBuffer);
			DataLen --;
			DataLen --;
			(uint16_t*)pTxBuffer++;
		}else{
			// 8 Bits DFF size
			pSPIx->DR = *pTxBuffer;
			DataLen --;
			pTxBuffer++;
		}

	}
}

//Data Receiving
void SPI_DataReceive(SPIx_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t DataLen){
	while (DataLen > 0){
		// 1. Wait for RXNE to be set
		while (Check_FlagStatus(pSPIx, SPI_RXNE_FLAG) == FLAG_RESET);

		// 2. Check DFF size
		if (pSPIx->CR1 & (1 << SPI_CR1_DFF)){
			// 16 Bits DFF
			// Read Data from DR to RX buffer
			*((uint16_t*)pRxBuffer) = pSPIx->DR;
			DataLen --;
			DataLen --;
			(uint16_t*)pRxBuffer++;
		}else{
			// 8 Bits DFF size
			*pRxBuffer = pSPIx->DR;
			DataLen --;
			pRxBuffer++;
		}

	}
}

// IRQ Configuration and ISR Handling
void SPI_IRQInterruptConfig(uint8_t IRQ_Number, uint8_t IRQ_ED){

}
void SPI_IRQHandling(SPI_Handle_t *pSPIxHandle){

}
void SPI_IRQPriorityConfig(uint8_t IRQ_Priority, uint8_t IRQ_Number){

}
