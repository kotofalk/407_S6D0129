/*
 * dummy.cpp
 *
 *  Created on: 14 ����. 2016 �.
 *      Author: kot
 */

#include <FreeRTOS.h>
#include <task.h>


extern  void vApplicationIdleHook( void )
{
}

extern  void vApplicationMallocFailedHook( void )
{
    for( ;; );
}

extern void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName )
{
    ( void ) pcTaskName;
    ( void ) xTask;

    for( ;; );
}

extern  void vApplicationTickHook( void )
{
}

