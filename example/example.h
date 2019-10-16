#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

#include "config.h"

#ifdef APP_GPIO_TOGGLE 
    #include "..\..\example\1.app_gpio_toggle\app_gpio_toggle.h"
#endif


#ifdef APP_USART 
    #include "..\..\example\2.app_usart\app_usart.h"
#endif

#endif 
