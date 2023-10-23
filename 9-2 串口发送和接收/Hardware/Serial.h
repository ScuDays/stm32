#include "stm32f10x.h"  
#ifndef __Serial_H
#define __Serial_H

extern uint8_t Serial_TxPacket[];				//FF 01 02 03 04 FE
extern uint8_t Serial_RxPacket[];

void Serial_Init(void);


void Serial_SendByte(uint8_t);
void Serial_SendArray(uint8_t *Array, uint16_t Length);
void Serial_SendPacket(void);


uint8_t Serial_GetRxFlag(void);


void USART1_IRQHandler(void);

#endif
