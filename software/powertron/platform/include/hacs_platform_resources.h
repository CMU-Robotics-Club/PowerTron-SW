#ifndef _HACS_PIN_DEFINES_H_
#define _HACS_PIN_DEFINES_H_

#include "stm32f4xx_hal.h"

typedef GPIO_TypeDef* gpio_port_t;
typedef uint16_t gpio_pin_t;

/*** SPI ***/
#define HACS_NUM_SPI_PERIPH				(2)

extern SPI_TypeDef* const hacs_spi_instances[HACS_NUM_SPI_PERIPH];

// hacs_spi_t is defined as an index
typedef enum {
	HACS_SPI_ADS7229 = 0,
	HACS_SPI_TLV5636,
} hacs_spi_t;

/*** GPIO ***/

#define ADS7229_CS_PORT 	GPIOC
#define ADS7229_CS_PIN 		GPIO_PIN_0

#define ADS7229_EOC_PORT 	GPIOC
#define ADS7229_EOC_PIN 	GPIO_PIN_4

#define ADS7229_CONVST_PORT 	GPIOC
#define ADS7229_CONVST_PIN 		GPIO_PIN_1


#define TLV5636_FS_PORT		GPIOA
#define TLV5636_FS_PIN		GPIO_PIN_9

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

/* Definition for SPI1 resources */ // TODO
#define SPI1_MOSI_GPIO_CLK_ENABLE()     __GPIOA_CLK_ENABLE()
#define SPI1_MISO_GPIO_CLK_ENABLE()     __GPIOA_CLK_ENABLE()
#define SPI1_SCK_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()

/* Definition for SPI1 pins */
#define SPI1_MOSI_PORT                  GPIOA
#define SPI1_MOSI_PIN                   GPIO_PIN_7
#define SPI1_MOSI_AF                    GPIO_AF5_SPI1 
#define SPI1_MISO_PORT                  GPIOA
#define SPI1_MISO_PIN                   GPIO_PIN_6
#define SPI1_MISO_AF                    GPIO_AF5_SPI1
#define SPI1_SCK_PORT                   GPIOA
#define SPI1_SCK_PIN                    GPIO_PIN_5
#define SPI1_SCK_AF                     GPIO_AF5_SPI1

/* Definition for SPI3 resources */
#define SPI3_MOSI_GPIO_CLK_ENABLE()     __GPIOC_CLK_ENABLE()
#define SPI3_MISO_GPIO_CLK_ENABLE()     __GPIOC_CLK_ENABLE()
#define SPI3_SCK_GPIO_CLK_ENABLE()      __GPIOB_CLK_ENABLE()

/* Definition for SPI3 pins */
#define SPI3_MOSI_PORT                  GPIOC
#define SPI3_MOSI_PIN                   GPIO_PIN_12
#define SPI3_MOSI_AF                    GPIO_AF6_SPI3
#define SPI3_MISO_PORT                  GPIOC
#define SPI3_MISO_PIN                   GPIO_PIN_11
#define SPI3_MISO_AF                    GPIO_AF6_SPI3
#define SPI3_SCK_PORT                   GPIOB
#define SPI3_SCK_PIN                    GPIO_PIN_12
#define SPI3_SCK_AF                     GPIO_AF7_SPI3

#endif
