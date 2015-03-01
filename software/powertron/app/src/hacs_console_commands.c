#include <string.h>
#include <stdlib.h>
#include "hacs_platform_resources.h"
#include "ads7229.h"
#include "tlv5636.h"

int hacs_console_cmd_dispatch(char *buf)
{
    if (buf[0] == 'a' && buf[1] == '\0') {
      printf("%4x\n", ads7229_convert_and_read());
    } else if (buf[0] == 'd' && buf[1] == ' ') {
      tlv5636_set_output(strtol(&buf[2], NULL, 10));
    }

    return 0;
}
