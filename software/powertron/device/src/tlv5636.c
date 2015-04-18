#include "hacs_platform_resources.h"
#include "hacs_spi_master.h"
#include "hacs_gpio.h"
#include "tlv5636.h"
#include "FreeRTOS.h"
#include "task.h"

#define TLV5636_CMD_WRITE_CTRL	(0x9000)
#define TLV5636_CMD_WRITE_DATA	(0x0000)

#define TLV5636_DEFAULT_MODE		((uint16_t)(TLV5636_FAST_MODE | TLV5636_PWR_NORMAL))

void tlv5636_init() {
	// Init chip select
	gpio_init_pin(TLV5636_FS_PORT, TLV5636_FS_PIN, HACS_GPIO_MODE_OUTPUT_PP,
								HACS_GPIO_NO_PULL);
	gpio_write_high(TLV5636_FS_PORT, TLV5636_FS_PIN);

	// default power up configuration
	tlv5636_config(TLV5636_REF_2048);
}

void tlv5636_config(tlv5636_ref_t ref) {
	uint16_t temp = 0;
	uint8_t data[2];

	temp = TLV5636_CMD_WRITE_CTRL | TLV5636_DEFAULT_MODE| (uint16_t)ref;
	data[0] = temp >> 8; // MSB first
	data[1] = temp & 0x00FF;

	gpio_write_low(TLV5636_FS_PORT, TLV5636_FS_PIN);
	spi_master_write(HACS_SPI_TLV5636, data, sizeof(data));
	gpio_write_high(TLV5636_FS_PORT, TLV5636_FS_PIN);
}

void tlv5636_set_output(uint16_t out) {
	uint8_t data[2];

	out = (out & 0x0FFF) | TLV5636_CMD_WRITE_DATA | TLV5636_DEFAULT_MODE;
	data[0] = out >> 8; // MSB first
	data[1] = out & 0x00FF;

	gpio_write_low(TLV5636_FS_PORT, TLV5636_FS_PIN);
	spi_master_write(HACS_SPI_TLV5636, data, sizeof(data));
	gpio_write_high(TLV5636_FS_PORT, TLV5636_FS_PIN);
}
