#include <string.h>
#include <stdio.h>
#include "hacs_platform_resources.h"
#include "hacs_spi_master.h"

int hacs_console_cmd_dispatch(char *buf)
{
    uint8_t data[2];
    char *num;
    int dac_out;
    uint16_t temp;

    if (buf[0] == 'a' && buf[1] == '\0') {
        return 0;
    } else if (buf[0] == 'd' && buf[1] == '0' && buf[2] == '\0') {
        data[0] = 0xD0;
        data[1] = 0x02;

        HAL_GPIO_WritePin(TLV5636_FS_PORT, TLV5636_FS_PIN, GPIO_PIN_RESET);
        spi_master_write(HACS_SPI_NRF2s4, data, 2);
        HAL_GPIO_WritePin(TLV5636_FS_PORT, TLV5636_FS_PIN, GPIO_PIN_SET);

    } else if (buf[0] == 'd' && buf[1] == ' ') {
      num = &buf[2];
      dac_out = strtol(num, NULL, 10);
      
      temp = 0x0FFF & ((uint16_t)dac_out);
      temp |= 0x4000; // fast mode; normal operation
      data[0] = (temp & 0xFF00) >> 8;
      data[1] = temp & 0x00FF;

      printf("data %4x\n\r", *((uint16_t*)data));

      HAL_GPIO_WritePin(TLV5636_FS_PORT, TLV5636_FS_PIN, GPIO_PIN_RESET);
      spi_master_write(HACS_SPI_NRF24, data, 2);
      HAL_GPIO_WritePin(TLV5636_FS_PORT, TLV5636_FS_PIN, GPIO_PIN_SET);
    }

    return 0;
}
