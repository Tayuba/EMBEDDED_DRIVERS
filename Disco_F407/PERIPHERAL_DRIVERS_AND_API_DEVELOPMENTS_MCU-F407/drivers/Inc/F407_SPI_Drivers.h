/*
 * F407_SPI_Drivers.h
 *
 *  Created on: March 1, 2023
 *      Author: Ayuba Tahiru
 */

#ifndef INC_F407_SPI_DRIVERS_H_
#define INC_F407_SPI_DRIVERS_H_

#include "stm32f407.h"


/*********** SPIx Pin Configuration  **********/
typedef struct {
	uint8_t SPI_DeviceMode;					/*Check possible values @DeviceMode*/
	uint8_t SPI_BusConfig;					/*Check possible values @BusConfig*/
	uint8_t SPI_SclkSpeed;					/*Check possible values @SclkSpeed*/
	uint8_t SPI_DFF;						/*Check possible values @DFF*/
	uint8_t SPI_CPOL;						/*Check possible values @CPOL*/
	uint8_t SPI_CPHA;						/*Check possible values @CPHA*/
	uint8_t SPI_SSM;						/*Check possible values @SSM*/
}SPIx_PinConfig_t;


/*********** SPIx Handle **********/
typedef struct {
	SPIx_RegDef_t 	 *pSPIx;				/* Holds the base address of the SPI port of which the pin belongs */
	SPIx_PinConfig_t SPI_PinConfig;			/* Holds the pin configuration of SPIx */
	uint8_t 		 *pTxBuffer;			/* To store Tx buffer address*/
	uint8_t 		 *pRxBuffer;			/* To store Rx buffer address */
	uint32_t 		 TxLen;					/* To store Tx len */
	uint32_t 		 RxLen;					/* To store Rx len */
	uint8_t 		 TxState;				/* To store Tx state */
	uint8_t 		 RxState;				/* To store Rx state  */
}SPI_Handle_t;

/*
 * @DeviceMode
 */
#define SPI_DEVICE_MODE_SLAVE			0
#define SPI_DEVICE_MODE_MASTER			1



/*
 * @BusConfig
 */
#define SPI_BUS_CONFIG_FULL_DUPLEX		1
#define SPI_BUS_CONFIG_HALP_DUPLEX		2
#define SPI_BUS_CONFIG_SIMPLEX_RX		3



/*
 * @SclkSpeed
 * Control by Baud rate
 */
#define SPI_SCLK_SPEED_DIV2				0
#define SPI_SCLK_SPEED_DIV4				1
#define SPI_SCLK_SPEED_DIV8				2
#define SPI_SCLK_SPEED_DIV16			3
#define SPI_SCLK_SPEED_DIV32			4
#define SPI_SCLK_SPEED_DIV64			5
#define SPI_SCLK_SPEED_DIV128			6
#define SSPI_SCLK_SPEED_DIV256			7

/*
 * @DFF
 */
#define SPI_DFF_8BITS					0
#define SPI_DFF_16BITS					1

/*
 * @CPOL
 */
#define SPI_CPOL_LOW					0
#define SPI_CPOL_HIGH					1

/*
 * @CPHA
 */
#define SPI_CPHA_LOW					0
#define SPI_CPHA_HIGH					1

/*
 * @SSM
 */
#define SPI_SSM_HW						0
#define SPI_SSM_SW						1

// SPI Flags
#define SPI_TXE_FLAG  (1 << SPI_SR_TXE)
#define SPI_RXNE_FLAG  (1 << SPI_SR_RXNE)
#define SPI_BUSY_FLAG  (1 << SPI_SR_BSY)

/*
 * @SPI States
 * */
#define SPI_READY						0
#define SPI_BUSY_IN_RX					1
#define SPI_BUSY_IN_TX					2

/*
 * @Occurring Events
 */
#define SPI_TX_EVENT_CMPLT				1
#define SPI_RX_EVENT_CMPLT				2
#define SPI_OVERRUN_EVENT_CMPLT			3

/*****************************************************************************************************************
 * 										APIs Supported Drivers
 * ***************************************************************************************************************/
// Enable Clock
void SPI_PCLK_Control(SPIx_RegDef_t *pSPIx, uint8_t ED);

// Enable SPI Protocol
void SPI_ProtocolEnable(SPIx_RegDef_t *pSPIx, uint8_t ED);

// Config SSI
void SSI_Config(SPIx_RegDef_t *pSPIx, uint8_t ED);

// Config SSOE
void SSOE_Config(SPIx_RegDef_t *pSPIx, uint8_t ED);

// Check SPI Flags
uint8_t Check_FlagStatus(SPIx_RegDef_t *pSPIx, uint32_t FlagName);

// Clear Overrun Flag
void SPI_OVRFlagClear(SPI_Handle_t *pSPIxHandle);

// Close Transmission
void SPI_CloseTx(SPI_Handle_t *pSPIxHandle);

// Close Reception
void SPI_CloseRx(SPI_Handle_t *pSPIxHandle);

// Application callback
void SPI_Callback(SPI_Handle_t *pSPIxHandle, uint8_t SPI_EVENT_Type);

// Initialization and De-Initialization
void SPI_Init(SPI_Handle_t *pSPIxHandle);
void SPI_DeInit(SPIx_RegDef_t *pSPIx);  //Reset from RCC RESET register


//Data Sending and Receiving
void SPI_DataSend(SPIx_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t DataLen);
void SPI_DataReceive(SPIx_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t DataLen);

//Data Sending and Receiving with Interrupt
uint8_t  SPI_DataSendIT(SPI_Handle_t *pSPIxHandle, uint8_t *pTxBuffer, uint32_t DataLen);
uint8_t SPI_DataReceiveIT(SPI_Handle_t *pSPIxHandle, uint8_t *pRxBuffer, uint32_t DataLen);

// IRQ Configuration and ISR Handling
void SPI_IRQInterruptConfig(uint8_t IRQ_Number, uint8_t IRQ_ED);
void SPI_IRQHandling(SPI_Handle_t *pSPIxHandle);
void SPI_IRQPriorityConfig(uint8_t IRQ_Priority, uint8_t IRQ_Number);

#endif /* INC_F407_SPI_DRIVERS_H_ */
