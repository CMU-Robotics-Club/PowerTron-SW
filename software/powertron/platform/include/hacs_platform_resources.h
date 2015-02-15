#ifndef _HACS_PIN_DEFINES_H_
#define _HACS_PIN_DEFINES_H_

#include "stm32f4xx_hal.h"

/*** SPI ***/
#define HACS_NUM_SPI_PERIPH				(2)

extern SPI_TypeDef* const hacs_spi_instances[HACS_NUM_SPI_PERIPH];

// hacs_spi_t is defined as an index
typedef enum {
	HACS_SPI_NRF24 = 0,
	HACS_SPI_ADS1120,
} hacs_spi_t;

/*** GPIO ***/

// The CS pin for SPI
#define NRF24_CS_PORT                   GPIOC
#define NRF24_CS_PIN                    GPIO_PIN_9
// CE pin for NRF24L01
#define NRF24_CE_PORT                   GPIOC
#define NRF24_CE_PIN                    GPIO_PIN_5
// IRQ pin for NRF24L01
#define NRF24_IRQ_PORT                  GPIOC
#define NRF24_IRQ_PIN                   GPIO_PIN_4

/* Definition for USART2 clock resources */
#define USART2_RX_GPIO_CLK_ENABLE()     __GPIOA_CLK_ENABLE()
#define USART2_TX_GPIO_CLK_ENABLE()     __GPIOA_CLK_ENABLE() 

/* Definition for USART2 Pins */
#define USART2_TX_PIN                   GPIO_PIN_2
#define USART2_TX_PORT                  GPIOA  
#define USART2_TX_AF                    GPIO_AF7_USART2
#define USART2_RX_PIN                   GPIO_PIN_3
#define USART2_RX_PORT                  GPIOA 
#define USART2_RX_AF                    GPIO_AF7_USART2

/* Definition for SPI3 resources */
#define SPI3_MOSI_GPIO_CLK_ENABLE()     __GPIOC_CLK_ENABLE()
#define SPI3_MISO_GPIO_CLK_ENABLE()     __GPIOC_CLK_ENABLE()
#define SPI3_SCK_GPIO_CLK_ENABLE()      __GPIOC_CLK_ENABLE()

/* Definition for SPI3 pins */
#define SPI3_MOSI_PORT                  GPIOC
#define SPI3_MOSI_PIN                   GPIO_PIN_12
#define SPI3_MOSI_AF                    GPIO_AF6_SPI3
#define SPI3_MISO_PORT                  GPIOC
#define SPI3_MISO_PIN                   GPIO_PIN_11
#define SPI3_MISO_AF                    GPIO_AF6_SPI3
#define SPI3_SCK_PORT                   GPIOC
#define SPI3_SCK_PIN                    GPIO_PIN_10
#define SPI3_SCK_AF                     GPIO_AF6_SPI3



// [SURG] Temporary
/*
#define ADS7229_CS_PORT
#define ADS7229_CS_PIN

#define ADS7229_EOC_PORT
#define ADS7229_EOC_PIN

#define ADS7229_CONVST_PORT
#define ADS7229_CONVST_PIN
*/

#define TLV5636_FS_PORT		GPIOA
#define TLV5636_FS_PIN		GPIO_PIN_12


#endif
