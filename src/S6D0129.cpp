/*
 * S6D0129.c
 *
 *  Created on: 14 февр. 2016 г.
 *      Author: kot
 */

#include <stm32f4xx_hal.h>
#include <stm32f4xx_hal_gpio.h>
#include <stm32f4xx_hal_rcc.h>
#include <S6D0129.h>



void    simpledelay(volatile long i){
    while (--i!=0)
            {;}

}


    inline void S6D0129::CS1_(void){
        S6D0129_DISPLAY_0_CTRLPORT->BSRR=S6D0129_DISPLAY_0_CSpin;
//        HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_CSpin, GPIO_PIN_SET);
    }
    inline void S6D0129::CS0_(void){
       S6D0129_DISPLAY_0_CTRLPORT->BSRR=(uint32_t)S6D0129_DISPLAY_0_CSpin << 16;
//        HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_CSpin, GPIO_PIN_RESET);
    }
    inline void S6D0129::RS1_(void){
        S6D0129_DISPLAY_0_CTRLPORT->BSRR=S6D0129_DISPLAY_0_RSpin;
//        HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_RSpin, GPIO_PIN_SET);
    }
    inline void S6D0129::RS0_(void){
        S6D0129_DISPLAY_0_CTRLPORT->BSRR=(uint32_t)S6D0129_DISPLAY_0_RSpin << 16;
//        HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_RSpin, GPIO_PIN_RESET);
    }

    inline void S6D0129::RST1_(void){
        S6D0129_DISPLAY_0_CTRLPORT->BSRR=S6D0129_DISPLAY_0_RSTpin;
//        HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_RSTpin, GPIO_PIN_SET);
    }
    inline void S6D0129::RST0_(void){
        S6D0129_DISPLAY_0_CTRLPORT->BSRR=(uint32_t)S6D0129_DISPLAY_0_RSTpin << 16;
 //       HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_RSTpin, GPIO_PIN_RESET);
    }

    inline void S6D0129::RD1_(void){
        asm volatile ("nop");
//        S6D0129_DISPLAY_0_CTRLPORT->BSRR=S6D0129_DISPLAY_0_RDpin;
       HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_RDpin, GPIO_PIN_SET);
    }
    inline void S6D0129::RD0_(void){
        S6D0129_DISPLAY_0_CTRLPORT->BSRR=(uint32_t)S6D0129_DISPLAY_0_RDpin << 16;
 //       HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_RDpin, GPIO_PIN_RESET);
        asm volatile ("nop");
        asm volatile ("nop");
        asm volatile ("nop");
        asm volatile ("nop");
        asm volatile ("nop");
        asm volatile ("nop");
        asm volatile ("nop");
        asm volatile ("nop");
        asm volatile ("nop");


    }
    inline void S6D0129::WR1_(void){
        asm volatile ("nop");
//       S6D0129_DISPLAY_0_CTRLPORT->BSRR=S6D0129_DISPLAY_0_WRpin;
        HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_WRpin, GPIO_PIN_SET);
    }
    inline void S6D0129::WR0_(void){
 //       S6D0129_DISPLAY_0_CTRLPORT->BSRR=(uint32_t)S6D0129_DISPLAY_0_WRpin << 16;
        HAL_GPIO_WritePin(S6D0129_DISPLAY_0_CTRLPORT, S6D0129_DISPLAY_0_WRpin, GPIO_PIN_RESET);
    }

    int32_t    S6D0129::setDataPort(GPIO_TypeDef *dataport){
        if IS_GPIO_ALL_INSTANCE(dataport){
            dataport_ = dataport;
            return 0;
        }
        return -1;
    }
    int32_t    S6D0129::setControlPort(GPIO_TypeDef *ctrlport){
        if IS_GPIO_ALL_INSTANCE(ctrlport){
            ctrlport_ = ctrlport;
            return 0;
        }
        return -1;
    }
    void S6D0129::dataLinesAsInput_(void){
        GPIO_InitTypeDef GPIO_InitStruct;
        GPIO_InitStruct.Pull = GPIO_NOPULL ;
        GPIO_InitStruct.Mode = GPIO_MODE_INPUT ;
        GPIO_InitStruct.Pin = S6D0129_DISPLAY_0_D0pin|S6D0129_DISPLAY_0_D1pin|
                                S6D0129_DISPLAY_0_D2pin|S6D0129_DISPLAY_0_D3pin|
                                S6D0129_DISPLAY_0_D4pin|S6D0129_DISPLAY_0_D5pin|
                                S6D0129_DISPLAY_0_D6pin|S6D0129_DISPLAY_0_D7pin|
                                S6D0129_DISPLAY_0_D8pin;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
        HAL_GPIO_Init(S6D0129_DISPLAY_0_DATAPORT, &GPIO_InitStruct);
    }
    void S6D0129::dataLinesAsOutput_(void){
        GPIO_InitTypeDef GPIO_InitStruct;
        GPIO_InitStruct.Pull = GPIO_NOPULL ;
        GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
        GPIO_InitStruct.Pin = S6D0129_DISPLAY_0_D0pin|S6D0129_DISPLAY_0_D1pin|
                                S6D0129_DISPLAY_0_D2pin|S6D0129_DISPLAY_0_D3pin|
                                S6D0129_DISPLAY_0_D4pin|S6D0129_DISPLAY_0_D5pin|
                                S6D0129_DISPLAY_0_D6pin|S6D0129_DISPLAY_0_D7pin|
                                S6D0129_DISPLAY_0_D8pin;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(S6D0129_DISPLAY_0_DATAPORT, &GPIO_InitStruct);
    }


    void S6D0129::sendCommand(uint16_t command){
        //RD1_();
        RS0_();
        sendData(command);
        RS1_();
    }

    inline
    void S6D0129::sendData(uint16_t data){
        WR1_();
    simpledelay(10000);
        S6D0129_DISPLAY_0_DATAPORT->ODR = (S6D0129_DISPLAY_0_DATAPORT->
                                           ODR&0xFFFFFE00)|(data>>8);
        simpledelay(10000);
        WR0_();
        simpledelay(10000);
        asm volatile ("nop");
        asm volatile ("nop");
        WR1_();
        simpledelay(10000);
        S6D0129_DISPLAY_0_DATAPORT->ODR = (S6D0129_DISPLAY_0_DATAPORT->
                                           ODR&0xFFFFFE00)|((data<<1)&0x1FF);
        simpledelay(10000);
        WR0_();
        simpledelay(10000);
        asm volatile ("nop");
        asm volatile ("nop");
        WR1_();
    }

    void S6D0129::comData(uint16_t command,uint16_t data)
    {
        sendCommand(command);
        sendData(data);
    }

    uint8_t    S6D0129::get8bitData(void){
        uint8_t data = 0;
        dataLinesAsInput_();
        RS1_();
        WR1_();
        RD0_();
        RD1_();
        RD0_();
        data = (uint8_t)S6D0129_DISPLAY_0_DATAPORT->IDR;
        RD1_();
        dataLinesAsOutput_();
        return data;
    }

    uint32_t    S6D0129::getChipID(void){
        uint32_t chipID;
        sendCommand(S6D0129_READID);
        dataLinesAsInput_();
        RS1_();
        RD0_();
        RD1_();

        RD0_();
        chipID= (uint8_t)S6D0129_DISPLAY_0_DATAPORT->IDR;
        RD1_();
        chipID<<=8;
        RD0_();
        chipID|= (uint8_t)S6D0129_DISPLAY_0_DATAPORT->IDR;
        RD1_();
        chipID<<=8;
        RD0_();
        chipID|= (uint8_t)S6D0129_DISPLAY_0_DATAPORT->IDR;
        RD1_();

        dataLinesAsOutput_();
        return chipID;
    }

    int32_t S6D0129::initialize(void){


            if (S6D0129_DISPLAY_0_DATAPORT == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_DATAPORT == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_DATAPORT == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_DATAPORT == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_DATAPORT == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
            else return -1;
            if (S6D0129_DISPLAY_0_CTRLPORT == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_CTRLPORT == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_CTRLPORT == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_CTRLPORT == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
            else if (S6D0129_DISPLAY_0_CTRLPORT == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
            else return -1;

            GPIO_InitTypeDef GPIO_InitStruct;
            GPIO_InitStruct.Pull = GPIO_NOPULL ;
            GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP ;
            GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
            GPIO_InitStruct.Pin = S6D0129_DISPLAY_0_RSTpin|S6D0129_DISPLAY_0_RSpin|
                                    S6D0129_DISPLAY_0_WRpin|S6D0129_DISPLAY_0_RDpin|
                                    S6D0129_DISPLAY_0_CSpin;
            HAL_GPIO_Init(S6D0129_DISPLAY_0_CTRLPORT, &GPIO_InitStruct);
            dataLinesAsOutput_();


            /* Force reset */
            RST1_();
            simpledelay(1000000);
            RST0_();
            simpledelay(1000000);
            RST1_();
            simpledelay(1000000);
            CS1_();
            WR1_();
            RST1_();
            CS0_();
            RD1_();
            /* Delay for RST response */
            simpledelay(1000000);
            RS1_();
                //************* Start Initial Sequence **********//

            RS0_();
            sendData(0x0000);
            sendData(0x0000);
            sendData(0x0000);
            sendData(0x0000);
            RS1_();
            comData(0x0000,0x0001);
            simpledelay(1000000);
            comData(0x0011,0x2E00);
            comData(0x0014,0x040B);
            comData(0x0010,0x1040);
            simpledelay(1000000);
            comData(0x0013,0x0040);
            simpledelay(1000000);
            comData(0x0013,0x0060);
            simpledelay(1000000);
            comData(0x0013,0x0070);
            simpledelay(1000000);
            comData(0x0011,0x3704);
            comData(0x0010,0x1600);
            simpledelay(1000000);
            comData(0x0001,0x0927);
            comData(0x0002,0x0700);
            comData(0x0003,0x1030);     //(0x1030,0x1010)
            comData(0x0007,0x0004);
            comData(0x0008,0x0505);
            comData(0x0009,0x0000);
            comData(0x000B,0x0000);
            comData(0x000C,0x0000);
            comData(0x0040,0x0000);
            comData(0x0046,0xEF00);
            comData(0x0047,0x013F);
            comData(0x0048,0x0000);
            simpledelay(1000000);
            comData(0x0030,0x0000);
            comData(0x0031,0x0006);
            comData(0x0032,0x0000);
            comData(0x0033,0x0000);
            comData(0x0034,0x0707);
            comData(0x0035,0x0700);
            comData(0x0036,0x0303);
            comData(0x0037,0x0007);
            comData(0x0038,0x1100);
            comData(0x0039,0x1100);
            comData(0x0007,0x0015);
            simpledelay(1000000);
            comData(0x0007,0x0017);
            simpledelay(1000000);
            comData(0x0020,0x0000);
            simpledelay(1000000);            //Set Address... LSB 0x10 (76560)
            comData(0x0021,0x0000);
            simpledelay(1000000);      //Set Address... HSB 0x12B
            sendData(0x0022);

            //CS1_();

            simpledelay(10000000);



            simpledelay(10000000);


           return 0;
        }

        void S6D0129::setWindow(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2){

        }

