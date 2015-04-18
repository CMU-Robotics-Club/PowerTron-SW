#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "hacs_platform_resources.h"
#include "hacs_platform.h"
#include "ads7229.h"
#include "ltc2641.h"

int hacs_console_cmd_dispatch(char *buf)
{
    int retval = -1;
    
    if (buf[0] == 'a') {
      if (buf[1] == 'c' && buf[2] == '\0') {
        printf("%4x\n", ads7229_convert_and_read(ADS7229_CURRENT_FB));
        retval = 0;
      } else if (buf[1] == 'v' && buf[2] == '\0') {
        printf("%4x\n", ads7229_convert_and_read(ADS7229_VOLTAGE_FB));
        retval = 0;
      } else if (buf[1] == 'c' && buf[2] == 'f' && buf[3] == '\0') {
        printf("%4x\n", ads7229_read_config(ADS7229_CURRENT_FB));
        retval = 0;
      } else if (buf[1] == 'v' && buf[2] == 'f' && buf[3] == '\0') {
        printf("%4x\n", ads7229_read_config(ADS7229_VOLTAGE_FB));
        retval = 0;
      }
    } else if (buf[0] == 'd') {
      if (buf[1] == ' ') {
        ltc2641_set_output(strtol(&buf[2], NULL, 10));
        retval = 0;
      } else if (buf[1] == 'r' && buf[2] == '\0') {
        uint16_t i;
        for (i = 0; i < 512; i++) {
          ltc2641_set_output(i << 3);
          vTaskDelay(MS_TO_TICKS(4));
        }
        for (i = 511; i > 0; i--) {
          ltc2641_set_output(i << 3);
          vTaskDelay(MS_TO_TICKS(4));
        }
        retval = 0;
      } else if (buf[1] == 'f' && buf[2] == ' ') {
          uint32_t delay_cycle = strtol(&buf[3], NULL, 10);
          uint32_t num_period = 65536 / delay_cycle;
          uint32_t n;

          for (int i = 0; i < num_period; i++) {
            ltc2641_set_output(0);
            n = 0;
            while(n++ > delay_cycle);
            ltc2641_set_output(4095);
            n = 0;
            while(n++ > delay_cycle);
          }
      }
    }

    return retval;
}
