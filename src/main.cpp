//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//


// ----------------------------------------------------------------------------
// подключаем библиотеку CMSIS
#include "stm32f4xx.h"
// Подключаем FreeRTOS
#include "FreeRTOS.h"
#include "BlinkLed.h"
#include "S6D0129.h"
#include "task.h"
#include "dummy.h"
#include <stdio.h>
#include <stdlib.h>
#include "diag/Trace.h"

// ----------------------------------------------------------------------------
//
// Standalone STM32F4 empty sample (trace via DEBUG).
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the DEBUG output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----- main() ---------------------------------------------------------------

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

#define BLINK_PORT_NUMBER         (3)
#define BLINK_PIN_NUMBER_GREEN    (12)
#define BLINK_PIN_NUMBER_ORANGE   (13)
#define BLINK_PIN_NUMBER_RED      (14)
#define BLINK_PIN_NUMBER_BLUE     (15)
#define BLINK_ACTIVE_LOW          (false)

S6D0129 display0;
BlinkLed blinkLeds[4] =
  {
    { BLINK_PORT_NUMBER, BLINK_PIN_NUMBER_GREEN, BLINK_ACTIVE_LOW },
    { BLINK_PORT_NUMBER, BLINK_PIN_NUMBER_ORANGE, BLINK_ACTIVE_LOW },
    { BLINK_PORT_NUMBER, BLINK_PIN_NUMBER_RED, BLINK_ACTIVE_LOW },
    { BLINK_PORT_NUMBER, BLINK_PIN_NUMBER_BLUE, BLINK_ACTIVE_LOW },
  };


void vTaskLED1(void *pvParameters) {

        for (;;) {
                blinkLeds[1].turnOn();

                vTaskDelay(800);
                blinkLeds[1].turnOff();
                vTaskDelay(250);

        }

}

void vTaskDisplayInit(void *pvParameters) {


    display0.initialize();
    vTaskDelete(NULL);

}

int
main(int argc, char* argv[])
{


  // At this stage the system clock should have already been configured
  // at high speed.

    // Send a greeting to the trace device (skipped on Release).
    trace_puts("Hello ARM World!");

    // At this stage the system clock should have already been configured
    // at high speed.
    trace_printf("System clock: %u Hz\n", SystemCoreClock);

    // Perform all necessary initialisations for the LEDs.
     for (size_t i = 0; i < (sizeof(blinkLeds) / sizeof(blinkLeds[0])); ++i)
       {
         blinkLeds[i].powerUp ();
       }


     for (size_t i = 0; i < (sizeof(blinkLeds) / sizeof(blinkLeds[0])); ++i)
       {
         blinkLeds[i].turnOn ();

       }


     // Enable GPIO Peripheral clock
     RCC->AHB1ENR |= (1<<5);

     GPIO_InitTypeDef GPIO_InitStructure;

     // Configure pin in output push/pull mode
     GPIO_InitStructure.Pin = GPIO_PIN_9;
     GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
     GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
     GPIO_InitStructure.Pull = GPIO_NOPULL;
     HAL_GPIO_Init (GPIOE, &GPIO_InitStructure);





      xTaskCreate( vTaskLED1, ( const char * ) "LED1", configMINIMAL_STACK_SIZE, NULL, 1,
                              ( xTaskHandle * ) NULL);
      xTaskCreate( vTaskDisplayInit, ( const char * ) "DispInit", configMINIMAL_STACK_SIZE, NULL, 2,
                              ( xTaskHandle * ) NULL);


      vTaskStartScheduler();



}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
