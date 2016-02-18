/*
 * dummy.h
 *
 *  Created on: 14 февр. 2016 г.
 *      Author: kot
 */

#ifndef INCLUDE_DUMMY_H_
#define INCLUDE_DUMMY_H_


extern  void vApplicationIdleHook( void );
extern  void vApplicationMallocFailedHook( void );
extern  void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName );
extern  void vApplicationTickHook( void );



#endif /* INCLUDE_DUMMY_H_ */
