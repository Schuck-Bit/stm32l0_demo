#include <string.h>
#include "app.h"
#include "config.h"
#include "cola_device.h"
#include "cola_os.h"
#include "example.h"



void app_init(void)
{
#ifdef APP_GPIO_TOGGLE
    app_gpio_toggle_init();
#endif
#ifdef APP_USART
    app_usart_init();
#endif
}
