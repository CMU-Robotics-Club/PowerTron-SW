#include "hacs_platform.h"
#include "hacs_platform_resources.h"
#include "stm32f4xx_hal.h"

// Revise this table to allocate SPI peripherals
SPI_TypeDef* const hacs_spi_instances[HACS_NUM_SPI_PERIPH] = {
	[HACS_SPI_NRF24] = SPI3,
	[HACS_SPI_ADS1120] = SPI1,
};