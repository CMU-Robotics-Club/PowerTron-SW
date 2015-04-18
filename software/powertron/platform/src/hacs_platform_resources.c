#include "hacs_platform.h"
#include "hacs_platform_resources.h"
#include "stm32f4xx_hal.h"

// Revise this table to allocate SPI peripherals
SPI_TypeDef* const hacs_spi_instances[HACS_NUM_SPI_PERIPH] = {
	[HACS_SPI_ADS7229_0] = SPI2,
	[HACS_SPI_ADS7229_1] = SPI3,
	[HACS_SPI_LTC2641] = SPI4,
};

GPIO_TypeDef* const hacs_spi_cs_port[HACS_NUM_SPI_PERIPH] = {
	[HACS_SPI_ADS7229_0] = ADS7229_0_CS_PORT,
	[HACS_SPI_ADS7229_1] = ADS7229_1_CS_PORT,
	[HACS_SPI_LTC2641] = LTC2641_CS_PORT,
};

const uint16_t hacs_spi_cs_pin[HACS_NUM_SPI_PERIPH] = {
	[HACS_SPI_ADS7229_0] = ADS7229_0_CS_PIN,
	[HACS_SPI_ADS7229_1] = ADS7229_1_CS_PIN,
	[HACS_SPI_LTC2641] = LTC2641_CS_PIN,
};
