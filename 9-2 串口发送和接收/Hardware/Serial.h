#include "stm32f10x.h"  
#ifndef __Serial_H
#define __Serial_H


void Serial_Init(void);


void Serial_SendByte(uint8_t);
uint8_t Serial_GetRxFlag(void);
uint8_t Serial_GetRxData(void);

void USART1_IRQHandler(void);

#endif
