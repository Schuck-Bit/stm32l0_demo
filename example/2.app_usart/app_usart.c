#include "cola_device.h"
#include "cola_os.h"
#include "example.h"


#ifdef APP_USART
static task_t timer_1s;
static task_t usart_task;
static cola_device_t *app_usart_dev;

//led每1s状态改变一次
static void timer_1s_cb(uint32_t event)
{
    os_log("app_usart running...\r\n");
}

//usart 主函数任务管理
static void usart_task_event(uint32_t event)
{
    uint8_t tmp[32] = {0};
    int err = 0;
    if(event & SIG_DATA)
    {
        err = cola_device_read(app_usart_dev,0,tmp,1);
        if(err)
        {
            cola_device_write(app_usart_dev,0,tmp,err);
        }
    }
    
}
static void usart_config(void)
{
    app_usart_dev = cola_device_find("usart1");
    assert(app_usart_dev);
    struct  serial_configure cfg;
    cfg.baud_rate = 9600;
    cola_device_config(app_usart_dev,&usart_task,&cfg);
}


void app_usart_init(void)
{
    cola_timer_create(&timer_1s,timer_1s_cb);
    cola_timer_start(&timer_1s,TIMER_ALWAYS,1000);
    cola_task_create(&usart_task,usart_task_event);
    usart_config();
}

#endif
