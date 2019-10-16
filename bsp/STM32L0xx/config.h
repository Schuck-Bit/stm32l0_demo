/**************************************************************************************************
* Filename:             osal_bsp.h
* Revised:        
* Revision:       
* Description:    
**************************************************************************************************/
#ifndef _CONFIG_H
#define _CONFIG_H

#ifdef __cplusplus

extern "C"
{
  
#endif

#include <stdio.h>    
 


    
#define USING_DEBUG
#ifdef USING_DEBUG
    #define os_log(...) printf(__VA_ARGS__)
   
#else
    #define os_log(...)
   
#endif

#ifndef USING_DEBUG
# define assert(p) ((void)0)
#else
# define assert(p) do { \
    if (!(p)) { \
        os_log("BUG at assert(%s)\n", #p); \
    }       \
 } while (0)
#endif



//例程选择(若果IO口不共用可以同时打开)
#define APP_EXAMPLE

#ifdef APP_EXAMPLE

    #define APP_GPIO_TOGGLE //GPIO口状态切换
    #ifdef APP_GPIO_TOGGLE //如果使用gpio_toggle例程，就要启用LED文件
        #define  USING_GPIO_TOGGLE
    #endif
    #define APP_USART
    #ifdef APP_USART 
        #define  USING_USART1
    #endif
 
 
#endif


 
   
#ifdef __cplusplus
}
#endif

#endif 
