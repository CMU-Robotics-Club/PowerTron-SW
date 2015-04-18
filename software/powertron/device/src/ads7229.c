#include "hacs_platform_resources.h"
#include "hacs_gpio.h"
#include "hacs_spi_master.h"
#include "ads7229.h"

#define ADS7229_CFG_WRITE	(0xE000)
#define ADS7229_READ_DATA	(0xD000)
#define ADS7229_READ_CFR	(0xC000)
#define ADS7229_DEFAULT_MODE (0xF000)

const hacs_spi_t ads7229_instances[] = {
	[ADS7229_CURRENT_FB] = HACS_SPI_ADS7229_0,
	[ADS7229_VOLTAGE_FB] = HACS_SPI_ADS7229_1,
};

GPIO_TypeDef* const ads7229_convst_port[] = {
	[ADS7229_CURRENT_FB] = ADS7229_0_CONVST_PORT,
	[ADS7229_VOLTAGE_FB] = ADS7229_1_CONVST_PORT,
};

const uint16_t ads7229_convst_pin[] = {
	[ADS7229_CURRENT_FB] = ADS7229_0_CONVST_PIN,
	[ADS7229_VOLTAGE_FB] = ADS7229_1_CONVST_PIN,
};

GPIO_TypeDef* const ads7229_eoc_port[] = {
	[ADS7229_CURRENT_FB] = ADS7229_0_EOC_PORT,
	[ADS7229_VOLTAGE_FB] = ADS7229_1_EOC_PORT,
};

const uint16_t ads7229_eoc_pin[] = {
	[ADS7229_CURRENT_FB] = ADS7229_0_EOC_PIN,
	[ADS7229_VOLTAGE_FB] = ADS7229_1_EOC_PIN,
};

void ads7229_init(ads7229_device_t dev) {
	gpio_init_pin(ads7229_eoc_port[dev], ads7229_eoc_pin[dev], HACS_GPIO_MODE_INPUT,
								HACS_GPIO_PULL_DOWN);

	// set CONVST to 1 for auto trigger
	gpio_init_pin(ads7229_convst_port[dev], ads7229_convst_pin[dev], HACS_GPIO_MODE_OUTPUT_PP,
								HACS_GPIO_NO_PULL);
	gpio_write_high(ads7229_convst_port[dev], ads7229_convst_pin[dev]);

	// default config
	ads7229_config(dev, ADS7229_CFG_DEFAULT);
}

void ads7229_config(ads7229_device_t dev, uint16_t cfg_word) {
	uint8_t data[2];
	cfg_word = (cfg_word & 0x0FFF) | ADS7229_CFG_WRITE;
	data[0] = cfg_word >> 8; // MSB first
	data[1] = cfg_word & 0x00FF;

	spi_master_assert_cs(ads7229_instances[dev]);
	spi_master_write(ads7229_instances[dev], data, sizeof(data));
	spi_master_deassert_cs(ads7229_instances[dev]);
}

static uint16_t read_result(ads7229_device_t dev, uint16_t cmd) {
	uint8_t rbuf[2];
	uint8_t wbuf[2];

	wbuf[0] = cmd >> 8;
	wbuf[1] = cmd & 0x00FF;

	spi_master_assert_cs(ads7229_instances[dev]);
	spi_master_exchange(ads7229_instances[dev], wbuf, rbuf, sizeof(wbuf));
	spi_master_deassert_cs(ads7229_instances[dev]);

	return (((uint16_t)rbuf[0]) << 8) | rbuf[1];
}

uint16_t ads7229_convert_and_read(ads7229_device_t dev) {
	// start the conversion
	gpio_write_low(ads7229_convst_port[dev], ads7229_convst_pin[dev]);
	// wait for conversion complete. TODO: make this non-blocking
	while(!gpio_read_pin(ads7229_eoc_port[dev], ads7229_eoc_pin[dev]));
	gpio_write_high(ads7229_convst_port[dev], ads7229_convst_pin[dev]);

	// read the result
	return read_result(dev, ADS7229_READ_DATA);
}

uint16_t ads7229_read_config(ads7229_device_t dev) {
	return read_result(dev, ADS7229_READ_CFR);
}