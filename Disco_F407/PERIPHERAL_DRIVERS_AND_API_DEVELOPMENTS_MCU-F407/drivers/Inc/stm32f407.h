/*
 * stm32f407.h
 *
 *  Created on: March 17, 2023
 *      Author: Ayuba Tahiru
 */

#ifndef INC_STM32F407_H_
#define INC_STM32F407_H_

/**********			Addresses Offsets		**********/
//Buses Offset Addresses
#define APB2_OFFSETADDR					x00010000UL								/* Advanced Peripheral Bus Two(2) Offset */
#define AHB1_OFFSETADDR					x00020000UL								/* Advanced High-performance Bus One(1) Offset */
#define AHB2_OFFSETADDR					x50000000UL								/* Advanced High-performance Bus Two(2) Offset */
#define AHB3_OFFSETADDR					xA0000000UL								/* Advanced High-performance Bus Three(3) Offset */

//AHB1 Offset Addresses
#define GPIOA_OFFSETADDR				x00000000UL								/* GPIOA Offset */
#define GPIOB_OFFSETADDR				x00000400UL								/* GPIOB Offset */
#define GPIOC_OFFSETADDR				x00000800UL								/* GPIOC Offset */
#define GPIOD_OFFSETADDR				x00000C00UL								/* GPIOD Offset */
#define GPIOE_OFFSETADDR				x00001000UL								/* GPIOE Offset */
#define GPIOF_OFFSETADDR				x00001400UL								/* GPIOF Offset */
#define GPIOG_OFFSETADDR				x00001800UL								/* GPIOG Offset */
#define GPIOH_OFFSETADDR				x00001C00UL								/* GPIOH Offset */
#define GPIOI_OFFSETADDR				x00002000UL								/* GPIOI Offset */
#define GPIOJ_OFFSETADDR				x00002400UL								/* GPIOJ Offset */
#define GPIOK_OFFSETADDR				x00002800UL								/* GPIOK Offset */
#define CRC_OFFSETADDR					x00003000UL								/* CRC Offset */
#define RCC_OFFSETADDR					x00003800UL								/* RCC Offset */
#define FLASHINTERFACE_OFFSETADDR		x00003C00UL								/* Flash interface register Offset */
#define BKPSRAM_OFFSETADDR				x00004000UL								/* BKPSRAM Offset */
#define DMA1_OFFSETADDR					x00006000UL								/* DMA1 Offset */
#define DMA2_OFFSETADDR					x00006400UL								/* DMA2 Offset */
#define ETHERNETMAC_OFFSETADDR			x00008000UL								/* ETHERNET MAC Offset */
#define DMA2D_OFFSETADDR				x0000B000UL								/* DMA2D Offset */
#define USBOTGHS_OFFSETADDR				x00040000UL								/* USB OTG HS Offset */

//APB1 Offset Addresses
#define TIM2_OFFSETADDR					x00000000UL								/* TIM2 Offset */
#define TIM3_OFFSETADDR					x00000400UL								/* TIM3 Offset */
#define TIM4_OFFSETADDR					x00000800UL								/* TIM4 Offset */
#define TIM5_OFFSETADDR					x00000C00UL								/* TIM5 Offset */
#define TIM6_OFFSETADDR					x00001000UL								/* TIM6 Offset */
#define TIM7_OFFSETADDR					x00001400UL								/* TIM7 Offset */
#define TIM12_OFFSETADDR				x00001800UL								/* TIM12 Offset */
#define TIM13_OFFSETADDR				x00001C00UL								/* TIM13 Offset */
#define TIM14_OFFSETADDR				x00002000UL								/* TIM14 Offset */
#define RTC_BKP_OFFSETADDR				x00002800UL								/* RTC & BKP Registers Offset */
#define WWDG_OFFSETADDR					x00002C00UL								/* WWDG Offset */
#define IWDG_OFFSETADDR					x00003000UL								/* IWDG Offset */
#define I2S2ext_OFFSETADDR				x00003400UL								/* I2S2ext Offset */
#define SPI2_I2S2_OFFSETADDR			x00003800UL								/* SPI2 / I2S2 Offset */
#define SPI3_I2S3_OFFSETADDR			x00003C00UL								/* SPI3 / I2S3 Offset */
#define I2S3ext_OFFSETADDR				x00004000UL								/* I2S3ext Offset */
#define USART2_OFFSETADDR				x00004400UL								/* USART2 Offset */
#define USART3_OFFSETADDR				x00004800UL								/* USART3 Offset */
#define UART4_OFFSETADDR				x00004C00UL								/* UART4 Offset */
#define UART5_OFFSETADDR				x00005000UL								/* UART5 Offset */
#define I2C1_OFFSETADDR					x00005400UL								/* I2C1 Offset */
#define I2C2_OFFSETADDR					x00005800UL								/* I2C2 Offset */
#define I2C3_OFFSETADDR					x00005C00UL								/* I2C3 Offset */
#define CAN1_OFFSETADDR					x00006400UL								/* CAN1 Offset */
#define CAN2_OFFSETADDR					x00006800UL								/* CAN2 Offset */
#define PWR_OFFSETADDR					x00007000UL								/* PWR Offset */
#define DAC_OFFSETADDR					x00007400UL								/* DAC Offset */
#define UART7_OFFSETADDR				x00007800UL								/* UART7 Offset */
#define UART8_OFFSETADDR				x00007C00UL								/* UART8 Offset */


/**********			Base Addresses of Flash and SRAm		**********/
#define FLASH_BASEADDR					0x08000000UL							/* Main memory Base Address */
#define SRAM1_BASEADDR					0x20000000UL							/* Main RAM (112KB) Base Address */
#define SRAM2_BASEADDR					0x2001C000UL							/* Auxiliary RAM Base Address (112KB x 1024 bytes = 1C000 in Hex)" SRAM1_BASEADDR + 1C000 = RAM2_BASEADDR" */
#define ROM_BASEADDR					0x1FFF0000UL							/* System memory Base Address */


/**********			Base Addresses of Peripheral Buses 		**********/
#define APB1_BASEADDR					0x40000000UL							/* Advanced Peripheral Bus Base Address */
#define APB2_BASEADDR					(APB1_BASEADDR + APB2_OFFSETADDR)		/* Advanced Peripheral Bus  One(1) Base Address */
#define AHB1_BASEADDR					(APB1_BASEADDR + AHB1_OFFSETADDR)		/* Advanced High-performance Bus  One(1) Base Address */
#define AHB2_BASEADDR					(APB1_BASEADDR + AHB2_OFFSETADDR)		/* Advanced High-performance Bus  Two(2) Base Address */
#define AHB3_BASEADDR					(APB1_BASEADDR + AHB3_OFFSETADDR)		/* Advanced High-performance Bus  Three(3) Base Address */


/**********			Base Addresses of Peripheral Hanging on APB1 Bus 		**********/
#define I2C1_BASEADDR					(APB1_BASEADDR + I2C1_OFFSETADDR)		/* I2C1 Base Address */
#define I2C2_BASEADDR					(APB1_BASEADDR + I2C2_OFFSETADDR)		/* I2C2 Base Address */
#define I2C3_BASEADDR					(APB1_BASEADDR + I2C3_OFFSETADDR)		/* I2C3 Base Address */
#define SPI2_BASEADDR					(APB1_BASEADDR + SPI2_I2S2_OFFSETADDR)	/* SPI2_I2S2 Base Address */
#define SPI3_BASEADDR					(APB1_BASEADDR + SPI3_I2S3_OFFSETADDR)	/* SPI3_I2S3 Base Address */
#define USART2_BASEADDR					(APB1_BASEADDR + USART2_OFFSETADDR)		/* USART2 Base Address */
#define USART3_BASEADDR					(APB1_BASEADDR + USART3_OFFSETADDR)		/* USART2 Base Address */
#define UART4_BASEADDR					(APB1_BASEADDR + UART4_OFFSETADDR)		/* UART4 Base Address */
#define UART5_BASEADDR					(APB1_BASEADDR + UART5_OFFSETADDR)		/* UART5 Base Address */

/**********			Base Addresses of Peripheral Hanging on APB2 Bus 		**********/


/**********			Base Addresses of Peripheral Hanging on AHB1 Bus 		**********/
#define GPIOA_BASEADDR					(AHB1_BASEADDR + GPIOA_OFFSETADDR)		/* GPIOA Base Address */
#define GPIOB_BASEADDR					(AHB1_BASEADDR + GPIOB_OFFSETADDR)		/* GPIOB Base Address */
#define GPIOC_BASEADDR					(AHB1_BASEADDR + GPIOC_OFFSETADDR)		/* GPIOC Base Address */
#define GPIOD_BASEADDR					(AHB1_BASEADDR + GPIOD_OFFSETADDR)		/* GPIOD Base Address */
#define GPIOE_BASEADDR					(AHB1_BASEADDR + GPIOE_OFFSETADDR)		/* GPIOE Base Address */
#define GPIOF_BASEADDR					(AHB1_BASEADDR + GPIOF_OFFSETADDR)		/* GPIOF Base Address */
#define GPIOG_BASEADDR					(AHB1_BASEADDR + GPIOG_OFFSETADDR)		/* GPIOG Base Address */
#define GPIOH_BASEADDR					(AHB1_BASEADDR + GPIOH_OFFSETADDR)		/* GPIOH Base Address */
#define GPIOI_BASEADDR					(AHB1_BASEADDR + GPIOI_OFFSETADDR)		/* GPIOI Base Address */
#define GPIOJ_BASEADDR					(AHB1_BASEADDR + GPIOJ_OFFSETADDR)		/* GPIOJ Base Address */
#define GPIOK_BASEADDR					(AHB1_BASEADDR + GPIOK_OFFSETADDR)		/* GPIOK Base Address */


/**********			Base Addresses of Peripheral Hanging on AHB2 Bus 		**********/


/**********			Base Addresses of Peripheral Hanging on AHB1 Bus 		**********/
#endif /* INC_STM32F407_H_ */
