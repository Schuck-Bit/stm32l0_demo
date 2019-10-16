#ifndef _COLA_DEVICE_H_
#define _COLA_DEVICE_H_


#include "cola_init.h"

enum LED_state
{
    LED_OFF,
    LED_ON,
    LED_TOGGLE,

};
enum DEV_sleep
{
	DEV_SLEEP= 0x00,
    DEV_DEEP_SLEEP = 0x01,
	
};


struct serial_configure
{
    int baud_rate;
};


typedef struct cola_device  cola_device_t;

struct cola_device_ops
{
    int  (*init)   (cola_device_t *dev);
    int  (*open)   (cola_device_t *dev, int oflag);
    int  (*close)  (cola_device_t *dev);
    int  (*read)   (cola_device_t *dev, int pos, void *buffer, int size);
    int  (*write)  (cola_device_t *dev, int pos, const void *buffer, int size);
    int  (*control)(cola_device_t *dev, int cmd, void *args);
    int  (*config) (cola_device_t *dev,void *pos,void *args);

};

struct cola_device
{
    const char * name;
    struct cola_device_ops *dops;
    struct cola_device *next;
};

/*
    Çý¶¯×¢²á
*/
int cola_device_register(cola_device_t *dev);
/*
    Çý¶¯²éÕÒ
*/
cola_device_t *cola_device_find(const char *name);
/*
    Çý¶¯¶Á
*/
int cola_device_read(cola_device_t *dev,  int pos, void *buffer, int size);
/*
    Çý¶¯Ð´
*/
int cola_device_write(cola_device_t *dev, int pos, const void *buffer, int size);
/*
    Çý¶¯¿ØÖÆ
*/
int cola_device_ctrl(cola_device_t *dev,  int cmd, void *arg);
/*
    Çý¶¯ÅäÖÃ
*/
int cola_device_config(cola_device_t *dev,void *pos,void *args);

#endif 
