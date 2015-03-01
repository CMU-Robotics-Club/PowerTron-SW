#include "hacs_platform_resources.h"
#include "hacs_gpio.h"
#include "hacs_spi_master.h"
#include "ads7229.h"

#define ADS7229_CFG_WRITE	(0xE000)
#define ADS7229_READ_DATA	(0xD000)

void ads7229_init() {
	gpio_init_pin(ADS7229_CS_PORT, ADS7229_CS_PIN, HACS_GPIO_MODE_OUTPUT_PP,
								HACS_GPIO_NO_PULL);
	gpio_init_pin(ADS7229_CONVST_PORT, ADS7229_CONVST_PIN, HACS_GPIO_MODE_OUTPUT_PP,
								HACS_GPIO_NO_PULL);
	gpio_init_pin(ADS7229_EOC_PORT, ADS7229_EOC_PIN, HACS_GPIO_MODE_INPUT,
								HACS_GPIO_PULL_DOWN);

	// default pin state
	gpio_write_high(ADS7229_CS_PORT, ADS7229_CS_PIN);
	gpio_write_high(ADS7229_CONVST_PORT, ADS7229_CONVST_PIN);

	// default config
	ads7229_config(ADS7229_CFG_DEFAULT);
}

void ads7229_config(uint16_t cfg_word) {
	uint8_t data[2];
	cfg_word = (cfg_word & 0x0FFF) | ADS7229_CFG_WRITE;
	data[0] = cfg_word >> 8; // MSB first
	data[1] = cfg_word & 0x00FF;

	gpio_write_low(ADS7229_CS_PORT, ADS7229_CS_PIN);
	spi_master_write(HACS_SPI_ADS7229, data, sizeof(data));
	gpio_write_high(ADS7229_CS_PORT, ADS7229_CS_PIN);

}

static uint16_t read_result() {
	uint8_t rbuf[2];
	uint8_t wbuf[2];

	wbuf[0] = ADS7229_READ_DATA >> 8;
	wbuf[1] = ADS7229_READ_DATA & 0x00FF;

	spi_master_exchange(HACS_SPI_ADS7229, wbuf, rbuf, sizeof(wbuf));

	return (((uint16_t)rbuf[0]) << 8) | rbuf[1];
}

uint16_t ads7229_convert_and_read() {
	// start the conversion
	gpio_write_low(ADS7229_CONVST_PORT, ADS7229_CONVST_PIN);

	// wait for conversion complete. TODO: make this non-blocking
	while(!gpio_read_pin(ADS7229_EOC_PORT, ADS7229_EOC_PIN));
	gpio_write_high(ADS7229_CONVST_PORT, ADS7229_CONVST_PIN);

	// read the result
	return read_result();
}