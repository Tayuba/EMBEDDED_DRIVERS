/*
 * F407_SPI_Drivers.c
 *
 *  Created on: March 1, 2023
 *      Author: Ayuba Tahiru
 */
//#include 	"F407_SPI_Drivers.h"
#include 	"stm32f407.h"


// Private Functions
static void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPIxHandle);
static void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPIxHandle);
static void SPI_OVERRUN_InterruptHandle(SPI_Handle_t *pSPIxHandle);

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
/********************************************************************************
 * @fn					-SPI_DataReceive
 *
 * @brief				-Receive data
 *
 * @param[in]			-Takes SPI register address
 * @param[in]			-Rx buffer register address
 * @param[in]			-Takes Data length
 *
 * @return				-returns nothing(None)
 *
 * @Note				-This is a blocking / Polling call function
 */
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
/********************************************************************************
 * @fn					-SPI_IRQInterruptConfig
 *
 * @brief				-Configure Interrupt
 *
 * @param[in]			-Takes IRQ number of the interrupt
 * @param[in]			-
 * @param[in]			-Enable or Disable the IRQof the interrupt
 *
 * @return				-returns nothing(None)
 *
 * @Note				-I only programmed NVIC register up to 2 because
						 the total number of interrupts in F407 is less than 90
 */
void SPI_IRQInterruptConfig(uint8_t IRQ_Number, uint8_t IRQ_ED){
	if (IRQ_ED == ENABLE){
		//Enable Interrupts
		if (IRQ_Number <= 31){
			//Enable ISER_0
			*NVIC_ISER0_ADDR |= (1 << IRQ_Number);

		}else if (IRQ_Number > 31 && IRQ_Number < 64){
			//Enable ISER_1
			*NVIC_ISER1_ADDR |= (1 << IRQ_Number % 32);

		}else if (IRQ_Number > 64 && IRQ_Number < 96){
			//Enable ISER_2
			*NVIC_ISER2_ADDR |= (1 << IRQ_Number % 64);

		}
	}//Disable Interrupts
	else {
		if (IRQ_Number <= 31){
			//Enable ICER_0
			*NVIC_ICER0_ADDR |= (1 << IRQ_Number);

		}else if (IRQ_Number > 31 && IRQ_Number < 64){
			//Enable ICER_1
			*NVIC_ICER1_ADDR |= (1 << IRQ_Number % 32);

		}else if (IRQ_Number >= 64 && IRQ_Number < 96){
			//Enable ICER_2
			*NVIC_ICER2_ADDR |= (1 << IRQ_Number % 64);

		}
	}

}


// IRQ Priority Configuration
/********************************************************************************
 * @fn					-SPI_IRQPriorityConfig
 *
 * @brief				-Configure Interrupt Priority
 *
 * @param[in]			-Takes the priority of IRQ of the interrupt
 * @param[in]			-Takes IRQ number of the interrupt
 * @param[in]			-
 *
 * @return				-returns nothing(None)
 *
 * @Note				-NVIC Priority register up to 60 with each register divided into 4
 *  * @Note				-NVIC Priority register up to 60 with each register divided into 4
 */
void SPI_IRQPriorityConfig(uint8_t IRQ_Priority, uint8_t IRQ_Number){
	//1. Select the Interrupt Priority Register (IPRx)
	uint8_t iprx = IRQ_Number / 4; // shift to next byte, that is address of selected register
	uint8_t iprx_bits = IRQ_Number % 4; // get the starting bit of the selected register, hence the section
	uint8_t iprx_noBits = 8; // number of bits in each priority register section

	uint8_t amount_shift = (iprx_noBits * iprx_bits) + (iprx_noBits - IMPLEMENTABLE_SECTION_BITS_PR); // number of bits section + implementable bits section

	*(NVIC_IPR_BASEADDR + iprx) |= (IRQ_Priority << amount_shift);

}


// Data Sending with Interrupt
/********************************************************************************
 * @fn					-SPI_DataSendIT
 *
 * @brief				-Send data with interrupt mode
 *
 * @param[in]			-Takes SPI handle
 * @param[in]			-Tx buffer register address
 * @param[in]			-Takes Data length
 *
 * @return				-Current state of Tx
 *
 * @Note				- This function store info which will be later send my interrupt handler.
 * 						  This makes it non blocking function.
 */
uint8_t SPI_DataSendIT(SPI_Handle_t *pSPIxHandle, uint8_t *pTxBuffer, uint32_t DataLen){
	uint8_t state = pSPIxHandle->TxState;

	if(state != SPI_BUSY_IN_TX){
		// 1. Save the Tx buffer address and DataLen info in a global variable
		pSPIxHandle->pTxBuffer = pTxBuffer;
		pSPIxHandle->TxLen = DataLen;

		// 2. Mark SPI as Busy in Tx so that no other code can call it!
		pSPIxHandle->TxState = SPI_BUSY_IN_TX;

		// 3. Enable TXEIE control bit in order to get interrupt when TXE flag is set
		pSPIxHandle->pSPIx->CR2 |= (1 << SPI_CR2_TXEIE);
	}
	return state;
}

// Data receiving with Interrupt
/********************************************************************************
 * @fn					-SPI_DataReceiveIT
 *
 * @brief				-Receive data with interrupt mode
 *
 * @param[in]			-Takes SPI handle
 * @param[in]			-Rx buffer register address
 * @param[in]			-Takes Data length
 *
 * @return				-Current state of Rx
 *
 * @Note				-
 */
uint8_t  SPI_DataReceiveIT(SPI_Handle_t *pSPIxHandle, uint8_t *pRxBuffer, uint32_t DataLen){
	uint8_t state = pSPIxHandle->RxState;

	if(state != SPI_BUSY_IN_RX){
		// 1. Save the Tx buffer address and DataLen info in a global variable
		pSPIxHandle->pRxBuffer = pRxBuffer;
		pSPIxHandle->RxLen = DataLen;

		// 2. Mark SPI as Busy in Tx so that no other code can call it!
		pSPIxHandle->RxState = SPI_BUSY_IN_RX;

		// 3. Enable TXEIE control bit in order to get interrupt when TXE flag is set
		pSPIxHandle->pSPIx->CR2 |= (1 << SPI_CR2_RXNEIE);
	}
	return state;
}


// IRQ Handling
/********************************************************************************
 * @fn					-SPI_IRQHandling
 *
 * @brief				-Handle Interrupt pin
 *
 * @param[in]			-Takes interrupt pin to handle
 * @param[in]			-
 * @param[in]			-
 *
 * @return				-returns nothing(None)
 *
 * @Note				-None
 */
void SPI_IRQHandling(SPI_Handle_t *pSPIxHandle){
/*
 * Check and decode the event that caused interrupts by checking SR
 * */
	uint8_t temp1, temp2;
	// 1. Check TXE status
	temp1 = pSPIxHandle->pSPIx->SR & (1 << SPI_SR_TXE);
	temp2 = pSPIxHandle->pSPIx->CR2 & (1 << SPI_CR2_TXEIE);

	if(temp1 && temp2){
		// Then handle TXE Flag
		SPI_TXE_InterruptHandle(pSPIxHandle);

	}

	// 2. Check RXNE status
	temp1 = pSPIxHandle->pSPIx->SR & (1 << SPI_SR_RXNE);
	temp2 = pSPIxHandle->pSPIx->CR2 & (1 << SPI_CR2_RXNEIE);

	if(temp1 && temp2){
		// Then handle RXNE Flag
		SPI_RXNE_InterruptHandle(pSPIxHandle);

	}

	// 3. Check Overrun error flag
	temp1 = pSPIxHandle->pSPIx->SR & (1 << SPI_SR_OVR);
	temp2 = pSPIxHandle->pSPIx->CR2 & (1 << SPI_CR2_ERRIE);

	if(temp1 && temp2){
		// Then handle Overrun Flag
		SPI_OVERRUN_InterruptHandle(pSPIxHandle);

	}

	// TODO: More Flags can later be handled
}

// Helping Functions
/********************************************************************************
 * @fn1					-SPI_TXE_InterruptHandle
 * @fn2					-SPI_RXNE_InterruptHandle
 * @fn3					-SPI_OVERRUN_InterruptHandle
 *
 * @brief				-Handle various errors and flag of SPI
 *
 * @param[in]			-Takes SPI handler
 * @param[in]			-
 * @param[in]			-
 *
 * @return				-returns nothing(None)
 *
 * @Note				-Help to modularized code
 */
// Function 1
void SPI_TXE_InterruptHandle(SPI_Handle_t *pSPIxHandle){
	// 1. Check DFF size
	if (pSPIxHandle->pSPIx->CR1 & (1 << SPI_CR1_DFF)){
		// 16 Bits DFF
		//Load Data from Tx buffer into DR
		pSPIxHandle->pSPIx->DR = *((uint16_t*)pSPIxHandle->pTxBuffer);
		pSPIxHandle->TxLen--;
		pSPIxHandle->TxLen--;
		(uint16_t*)pSPIxHandle->pTxBuffer++;
	}else{
		// 8 Bits DFF size
		pSPIxHandle->pSPIx->DR = *pSPIxHandle->pTxBuffer;
		pSPIxHandle->TxLen--;
		pSPIxHandle->pTxBuffer++;
	}

	// Transmission is over
	if(!pSPIxHandle->TxLen){
		// Close transmission
		SPI_CloseTx(pSPIxHandle);

		// Inform application
		SPI_Callback(pSPIxHandle, SPI_TX_EVENT_CMPLT);
	}

}

// Function 2
void SPI_RXNE_InterruptHandle(SPI_Handle_t *pSPIxHandle){
	// 1. Check DFF size
	if (pSPIxHandle->pSPIx->CR1 & (1 << SPI_CR1_DFF)){
		// 16 Bits DFF
		//Read Data from Tx buffer into DR
		*((uint16_t*)pSPIxHandle->pRxBuffer) = pSPIxHandle->pSPIx->DR;
		pSPIxHandle->RxLen--;
		pSPIxHandle->RxLen--;
		(uint16_t*)pSPIxHandle->pRxBuffer++;
	}else{
		// 8 Bits DFF size
		*pSPIxHandle->pRxBuffer = pSPIxHandle->pSPIx->DR;
		pSPIxHandle->RxLen--;
		pSPIxHandle->pRxBuffer++;
	}

	// Reception is over
	if(!pSPIxHandle->RxLen){
		// Close Reception
		SPI_CloseRx(pSPIxHandle);

		// Inform application
		SPI_Callback(pSPIxHandle, SPI_RX_EVENT_CMPLT);
	}

}

// Function 3
void SPI_OVERRUN_InterruptHandle(SPI_Handle_t *pSPIxHandle){

	// Clear OVR Flag
	if(pSPIxHandle->TxState!= SPI_BUSY_IN_TX){
		// Read DR followed by SR
		SPI_OVRFlagClear(pSPIxHandle);

	}


	// Inform application
	SPI_Callback(pSPIxHandle, SPI_OVERRUN_EVENT_CMPLT);
}

// Clear Overrun Flag
void SPI_OVRFlagClear(SPI_Handle_t *pSPIxHandle){
	uint8_t temp;
	// Read DR followed by SR
	temp = pSPIxHandle->pSPIx->DR;
	temp = pSPIxHandle->pSPIx->SR;
	(void)temp;
}

// Close Transmission
void SPI_CloseTx(SPI_Handle_t *pSPIxHandle){
	pSPIxHandle->pSPIx->CR2 &= ~(1 << SPI_CR2_TXEIE);
	pSPIxHandle->pTxBuffer = NULL;
	pSPIxHandle->TxLen = 0;
	pSPIxHandle->TxState = SPI_READY;
}

// Close Reception
void SPI_CloseRx(SPI_Handle_t *pSPIxHandle){

	pSPIxHandle->pSPIx->CR2 &= ~(1 << SPI_CR2_RXNEIE);
	pSPIxHandle->pTxBuffer = NULL;
	pSPIxHandle->RxLen = 0;
	pSPIxHandle->RxState = SPI_READY;
}

__weak void SPI_Callback(SPI_Handle_t *pSPIxHandle, uint8_t SPI_EVENT_Type){
	/* This is a weak implementation, application may override this function*/
}
