/*
 * S6D0129.h
 *
 *  Created on: 14 февр. 2016 г.
 *      Author: kot
 */

#ifndef S6D0129_H_
#define S6D0129_H_

#include <stdio.h>
#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_rcc.h>


#define S6D0129_DISPLAY_0_DATAPORT     GPIOA
#define S6D0129_DISPLAY_0_D0pin        GPIO_PIN_0
#define S6D0129_DISPLAY_0_D1pin        GPIO_PIN_1
#define S6D0129_DISPLAY_0_D2pin        GPIO_PIN_2
#define S6D0129_DISPLAY_0_D3pin        GPIO_PIN_3
#define S6D0129_DISPLAY_0_D4pin        GPIO_PIN_4
#define S6D0129_DISPLAY_0_D5pin        GPIO_PIN_5
#define S6D0129_DISPLAY_0_D6pin        GPIO_PIN_6
#define S6D0129_DISPLAY_0_D7pin        GPIO_PIN_7
#define S6D0129_DISPLAY_0_D8pin        GPIO_PIN_8

#define S6D0129_DISPLAY_0_CTRLPORT     GPIOC
#define S6D0129_DISPLAY_0_RSTpin       GPIO_PIN_7
#define S6D0129_DISPLAY_0_CSpin        GPIO_PIN_11
#define S6D0129_DISPLAY_0_RSpin        GPIO_PIN_6
#define S6D0129_DISPLAY_0_WRpin        GPIO_PIN_8
#define S6D0129_DISPLAY_0_RDpin        GPIO_PIN_9


#define S6D0129_RESET                 0x01
#define S6D0129_READID                0xD3
#define S6D0129_SLEEP_OUT             0x11
#define S6D0129_GAMMA                 0x26
#define S6D0129_DISPLAY_OFF           0x28
#define S6D0129_DISPLAY_ON            0x29
#define S6D0129_COLUMN_ADDR           0x2A
#define S6D0129_PAGE_ADDR             0x2B
#define S6D0129_GRAM                  0x2C
#define S6D0129_MAC                   0x36
#define S6D0129_PIXEL_FORMAT          0x3A
#define S6D0129_WDB                   0x51
#define S6D0129_WCD                   0x53
#define S6D0129_RGB_INTERFACE         0xB0
#define S6D0129_FRC                   0xB1
#define S6D0129_BPC                   0xB5
#define S6D0129_DFC                   0xB6
#define S6D0129_POWER1                0xC0
#define S6D0129_POWER2                0xC1
#define S6D0129_VCOM1                 0xC5
#define S6D0129_VCOM2                 0xC7
#define S6D0129_POWERA                0xCB
#define S6D0129_POWERB                0xCF
#define S6D0129_PGAMMA                0xE0
#define S6D0129_NGAMMA                0xE1
#define S6D0129_DTCA                  0xE8
#define S6D0129_DTCB                  0xEA
#define S6D0129_POWER_SEQ             0xED
#define S6D0129_3GAMMA_EN             0xF2
#define S6D0129_INTERFACE             0xF6
#define S6D0129_PRC                   0xF7
#define S6D0129_565_PIXEL_FORMAT      0x55
#define S6D0129_666_PIXEL_FORMAT      0x66



class S6D0129{
//-----Private Declarations----------------------------------------------------
    //private:
public:
    inline void CS1_(void);
    inline void CS0_(void);
    inline void RS1_(void);
    inline void RS0_(void);
    inline void RST1_(void);
    inline void RST0_(void);
    inline void RD1_(void);
    inline void RD0_(void);
    inline void WR1_(void);
    inline void WR0_(void);
    void dataLinesAsInput_(void);
    void dataLinesAsOutput_(void);
    void sendData(uint16_t data);
    GPIO_TypeDef *dataport_;
    GPIO_TypeDef *ctrlport_;
//----Public Declarations------------------------------------------------------
    public:
    uint32_t    getChipID(void);
    int32_t     setDataPort(GPIO_TypeDef *dataport);
    int32_t     setControlPort(GPIO_TypeDef *ctrlport);
    int32_t     initialize(void);
    uint8_t     get8bitData(void);
    void        sendCommand(uint16_t command);
    void        comData(uint16_t command,uint16_t data);
    void        set666pixel(uint8_t r,uint8_t g,uint8_t b);
    void        set565pixel(uint8_t r,uint8_t g,uint8_t b);
    void        setWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);




};











#endif /* S6D0129_H_ */
