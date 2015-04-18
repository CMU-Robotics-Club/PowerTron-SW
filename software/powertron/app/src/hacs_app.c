#include "hacs_platform.h"
#include "hacs_app.h"
#include "hacs_console.h"
#include "FreeRTOS.h"
#include "task.h"

#include "hacs_gpio.h"

static void led_task(void *param) {
	gpio_init_pin(GPIOA, GPIO_PIN_5, HACS_GPIO_MODE_OUTPUT_PP,
								HACS_GPIO_NO_PULL);

	while(1) {
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		vTaskDelay(MS_TO_TICKS(500));
	}
}

void hacs_app_init(void)
{
	xTaskCreate(hacs_console_task, "console", 1024, NULL, 6, NULL );
	xTaskCreate(led_task, "led", 64, NULL, 6, NULL);
}
