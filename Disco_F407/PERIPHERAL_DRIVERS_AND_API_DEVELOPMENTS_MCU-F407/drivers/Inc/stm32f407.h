/*
 * stm32f407.h
 *
 *  Created on: March 17, 2023
 *      Author: Ayuba Tahiru
 */

#ifndef INC_STM32F407_H_
#define INC_STM32F407_H_

#include <stdint.h>

#define __vol volatile

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


//APB2 Offset Addresses
#define TIM1_OFFSETADDR					x00000000UL								/* TIM1 Offset */
#define TIM8_OFFSETADDR					x00000400UL								/* TIM8 Offset */
#define USART1_OFFSETADDR				x00001000UL								/* USART1 Offset */
#define USART6_OFFSETADDR				x00001400UL								/* USART6 Offset */
#define ADC1_ADC2_ADC3_OFFSETADDR		x00002000UL								/* ADC1 - ADC2 - ADC3Offset */
#define SDIO_OFFSETADDR					x00002C00UL								/* SDIO Offset */
#define SPI1_OFFSETADDR					x00003000UL								/* SPI1 Offset */
#define SPI4_OFFSETADDR					x00003400UL								/* SPI4Offset */
#define SYSCFG_OFFSETADDR				x00003800UL								/* SYSCFG Offset */
#define EXTI_OFFSETADDR					x00003C00UL								/* EXTI Offset */
#define TIM9_OFFSETADDR					x00004000UL								/* TIM9 Offset */
#define TIM10_OFFSETADDR				x00004400UL								/* TIM10 Offset */
#define TIM11_OFFSETADDR				x00004800UL								/* TIM11 Offset */
#define SPI5_OFFSETADDR					x00005000UL								/* SPI5 Offset */
#define SPI6_OFFSETADDR					x00005400UL								/* SPI6 Offset */
#define SAI1_OFFSETADDR					x00005800UL								/* SAI1 Offset */
#define LCD_TFT_OFFSETADDR				x00006800UL								/* LCD-TFT Offset */


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
#define SPI1_BASEADDR					(APB2_BASEADDR + SPI1_OFFSETADDR)		/* SPI1 Base Address */
#define USART1_BASEADDR					(APB2_BASEADDR + USART1_OFFSETADDR)		/* USART1 Base Address */
#define USART6_BASEADDR					(APB2_BASEADDR + USART6_OFFSETADDR)		/* USART6 Base Address */
#define EXTI_BASEADDR					(APB2_BASEADDR + EXTI_OFFSETADDR)		/* EXTI Base Address */
#define SYSCFG_BASEADDR					(APB2_BASEADDR + SYSCFG_OFFSETADDR)		/* SYSCFG Base Address */

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


/**********			Base Addresses of RCC 		**********/
#define RCC_BASEADDR					(AHB1_BASEADDR + RCC_OFFSETADDR)		/* RCC Base Address */


/**********			Base Addresses of Peripheral Hanging on AHB2 Bus 		**********/


/**********			Base Addresses of Peripheral Hanging on AHB1 Bus 		**********/



/**********			Peripheral Registers Definition Structures					**********/
// GPIOx Definition Structures
typedef struct {
	__vol uint32_t MODER;				/* GPIO port mode register,										Address Offset 0x00 */
	__vol uint32_t OTYPER;				/* GPIO port output type register,								Address Offset 0x04 */
	__vol uint32_t OSPEEDR;				/* GPIO port output speed register,								Address Offset 0x08 */
	__vol uint32_t PUPDR;				/* GPIO port pull-up/pull-down register,						Address Offset 0x0C */
	__vol uint32_t IDR;					/* GPIO port input data register,								Address Offset 0x10 */
	__vol uint32_t ODR;					/* GPIO port output data register,								Address Offset 0x14 */
	__vol uint32_t BSRR;				/* GPIO port bit set/reset register,							Address Offset 0x18 */
	__vol uint32_t LCKR;				/* GPIO port configuration lock register,						Address Offset 0x1C */
	__vol uint32_t AFR[2];				/* GPIO alternate function low-high register AFRL[0], AFRH[1],	Address Offset 0x20 - 0x24 */
}GPIOx_RegDef_t;

// GPIOx Peripheral Definition
#define GPIOA	((GPIOx_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB	((GPIOx_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC	((GPIOx_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD	((GPIOx_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE	((GPIOx_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF	((GPIOx_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG	((GPIOx_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH	((GPIOx_RegDef_t*) GPIOH_BASEADDR)
#define GPIOI	((GPIOx_RegDef_t*) GPIOI_BASEADDR)
#define GPIOJ	((GPIOx_RegDef_t*) GPIOJ_BASEADDR)
#define GPIOK	((GPIOx_RegDef_t*) GPIOK_BASEADDR)


// RCC Definition Structures
typedef struct{
	__vol uint32_t CR;				/* RCC clock control register,									Address Offset 0x00 */
	__vol uint32_t PLLCFGR;			/* RCC PLL configuration register,								Address Offset 0x04 */
	__vol uint32_t CFGR;			/* GRCC clock configuration register,							Address Offset 0x08 */
	__vol uint32_t CIR;				/* RCC clock interrupt register,								Address Offset 0x0C */
	__vol uint32_t AHB1RSTR;		/* GRCC AHB1 peripheral reset register,							Address Offset 0x10 */
	__vol uint32_t AHB2RSTR;		/* RCC AHB2 peripheral reset register,							Address Offset 0x14 */
	__vol uint32_t AHB3RSTR;		/* RCC AHB3 peripheral reset register,							Address Offset 0x18 */
		  uint32_t Reserved;		/* Reserved,													Address Offset 0x1C */
	__vol uint32_t APB1RSTR;		/* RCC APB1 peripheral reset register,							Address Offset 0x20 */
	__vol uint32_t APB2RSTR;		/* RCC APB2 peripheral reset register,							Address Offset 0x24 */
	__vol uint32_t Reserved1[2];	/* Reserved: Reserved[0] and Reserved[1],						Address Offset 0x28 - 0x2C */
	__vol uint32_t AHB1ENR;			/* RCC AHB1 peripheral clock enable register,					Address Offset 0x30 */
	__vol uint32_t AHB2ENR;			/* RCC AHB2 peripheral clock enable register,					Address Offset 0x34 */
	__vol uint32_t AHB3ENR;			/* RCC AHB3 peripheral clock enable register,					Address Offset 0x38 */
		  uint32_t Reserved2;		/* Reserved,													Address Offset 0x3C */
	__vol uint32_t APB1ENR;			/* RRCC APB1 peripheral clock enable register,					Address Offset 0x40 */
	__vol uint32_t APB2ENR;			/* RCC APB2 peripheral clock enable register,					Address Offset 0x44 */
	__vol uint32_t Reserved3[2];	/* Reserved: Reserved[0] and Reserved[1],						Address Offset 0x48 - 0x4C */
	__vol uint32_t AHB1LPENR;		/* RCC AHB1 peripheral clock enable in low power mode register,	Address Offset 0x50 */
	__vol uint32_t AHB2LPENR;		/* RCC AHB2 peripheral clock enable in low power mode register,	Address Offset 0x54 */
	__vol uint32_t AHB3LPENR;		/* RCC AHB3 peripheral clock enable in low power mode register,	Address Offset 0x58 */
		  uint32_t Reserved4;		/* Reserved,													Address Offset 0x5C */
	__vol uint32_t APB1LPENR;		/* RCC APB1 peripheral clock enable in low power mode register,	Address Offset 0x60 */
	__vol uint32_t APB2LPENR;		/* RCC APB2 peripheral clock enabled in low power mode register,Address Offset 0x64 */
	__vol uint32_t Reserved5[2];	/* Reserved: Reserved[0] and Reserved[1],						Address Offset 0x68 - 0x6C */
	__vol uint32_t BDCR;			/* RCC Backup domain control register,							Address Offset 0x70 */
	__vol uint32_t CSR;				/* RCC clock control & status register,							Address Offset 0x74 */
		  uint32_t Reserved6[2];	/* Reserved: Reserved[0] and Reserved[1],						Address Offset 0x78 - 0x7C */
	__vol uint32_t SSCGR;			/* RCC spread spectrum clock generation register,				Address Offset 0x80 */
	__vol uint32_t PLLI2SCFGR;		/* RCC PLLI2S configuration register,							Address Offset 0x84 */
}RCC_RegDef_t;

// RCC Peripheral Definition
#define RCC 	((RCC_RegDef_t*) RCC_BASEADDR)

/**********			Clock Enable and Disable Macros					**********/
//GPIOx Enable Macro
#define GPIOA_PER_CLOCK_ENABLE()	( RCC->AHB1ENR |= (1 <<0 ))

#endif /* INC_STM32F407_H_ */
