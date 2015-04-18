#ifndef _HACS_PIN_DEFINES_H_
#define _HACS_PIN_DEFINES_H_

#include "stm32f4xx_hal.h"

typedef GPIO_TypeDef* gpio_port_t;
typedef uint16_t gpio_pin_t;

/*** SPI ***/
#define HACS_NUM_SPI_PERIPH				(3)

extern SPI_TypeDef* const hacs_spi_instances[HACS_NUM_SPI_PERIPH];
extern GPIO_TypeDef* const hacs_spi_cs_port[HACS_NUM_SPI_PERIPH];
extern const uint16_t hacs_spi_cs_pin[HACS_NUM_SPI_PERIPH];

// hacs_spi_t is defined as an index
typedef enum {
	HACS_SPI_ADS7229_0 = 0,
	HACS_SPI_ADS7229_1,
	HACS_SPI_LTC2641,
} hacs_spi_t;

/*** GPIO ***/

#define ADS7229_0_CS_PORT 	GPIOC
#define ADS7229_0_CS_PIN 		GPIO_PIN_0

#define ADS7229_0_EOC_PORT 	GPIOC
#define ADS7229_0_EOC_PIN 	GPIO_PIN_10

#define ADS7229_0_CONVST_PORT 	GPIOC
#define ADS7229_0_CONVST_PIN 		GPIO_PIN_1

#define ADS7229_1_CS_PORT 	GPIOC
#define ADS7229_1_CS_PIN 		GPIO_PIN_6

#define ADS7229_1_EOC_PORT 	GPIOC
#define ADS7229_1_EOC_PIN 	GPIO_PIN_8

#define ADS7229_1_CONVST_PORT 	GPIOC
#define ADS7229_1_CONVST_PIN 		GPIO_PIN_7

#define LTC2641_CS_PORT		GPIOA
#define LTC2641_CS_PIN		GPIO_PIN_9

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

/* Definition for SPI2 resources */ // TODO
#define SPI2_MOSI_GPIO_CLK_ENABLE()     __GPIOA_CLK_ENABLE()
#define SPI2_MISO_GPIO_CLK_ENABLE()     __GPIOA_CLK_ENABLE()
#define SPI2_SCK_GPIO_CLK_ENABLE()      __GPIOB_CLK_ENABLE()

/* Definition for SPI2 pins */
#define SPI2_MOSI_PORT                  GPIOC
#define SPI2_MOSI_PIN                   GPIO_PIN_3
#define SPI2_MOSI_AF                    GPIO_AF5_SPI2 
#define SPI2_MISO_PORT                  GPIOC
#define SPI2_MISO_PIN                   GPIO_PIN_2
#define SPI2_MISO_AF                    GPIO_AF5_SPI2
#define SPI2_SCK_PORT                   GPIOB
#define SPI2_SCK_PIN                    GPIO_PIN_10
#define SPI2_SCK_AF                     GPIO_AF5_SPI2

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

/* Definition for SPI4 resources */
#define SPI4_MOSI_GPIO_CLK_ENABLE()     __GPIOC_CLK_ENABLE()
#define SPI4_MISO_GPIO_CLK_ENABLE()     __GPIOC_CLK_ENABLE()
#define SPI4_SCK_GPIO_CLK_ENABLE()      __GPIOB_CLK_ENABLE()

/* Definition for SPI4 pins */
#define SPI4_MOSI_PORT                  GPIOA
#define SPI4_MOSI_PIN                   GPIO_PIN_1
#define SPI4_MOSI_AF                    GPIO_AF5_SPI4
#define SPI4_MISO_PORT                  GPIOA
#define SPI4_MISO_PIN                   GPIO_PIN_11
#define SPI4_MISO_AF                    GPIO_AF6_SPI4
#define SPI4_SCK_PORT                   GPIOB
#define SPI4_SCK_PIN                    GPIO_PIN_13
#define SPI4_SCK_AF                     GPIO_AF6_SPI4

#endif
