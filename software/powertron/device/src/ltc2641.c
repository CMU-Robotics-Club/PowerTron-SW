#include "hacs_platform_resources.h"
#include "hacs_spi_master.h"
#include "hacs_gpio.h"
#include "ltc2641.h"

void ltc2641_init() {

}

void ltc2641_set_output(uint16_t out) {
	uint8_t data[2];

	out = (out & 0xFFF) << 4; // left-adjusted 12 bit data
	data[0] = out >> 8; // MSB first
	data[1] = out & 0x00FF;

	spi_master_assert_cs(HACS_SPI_LTC2641);
	spi_master_write(HACS_SPI_LTC2641, data, sizeof(data));
	spi_master_deassert_cs(HACS_SPI_LTC2641);
}