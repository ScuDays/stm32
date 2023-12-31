#include "stm32f10x.h"  
#ifndef __Serial_H
#define __Serial_H

extern uint8_t Serial_TxPacket[4];
extern uint8_t Serial_RxPacket[4];

void Serial_Init(void);


void Serial_SendByte(uint8_t);
void Serial_SendArray(uint8_t *arr, uint16_t length);
void Serial_SendPacket(void);

uint8_t Serial_GetRxFlag(void);
void USART1_IRQHandler(void);

#endif
