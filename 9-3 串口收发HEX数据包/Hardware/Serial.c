#include "Serial.h"
#include "stdio.h"


uint8_t Serial_TxPacket[4];
uint8_t Serial_RxPacket[4];
uint8_t Serial_RxFlag;

void Serial_Init(void){

    //开启时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

		//这里模式使用GPIO_Mode_Out_PP就不行，使用GPIO_Mode_AF_PP就可以
    GPIO_InitTypeDef GPIO_InitStructure;
		GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
		GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
		GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitTypeDef USART_InitStruture;
    USART_InitStruture.USART_BaudRate = 9600;
    USART_InitStruture.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
    USART_InitStruture.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
    USART_InitStruture.USART_Parity = USART_Parity_No;
    USART_InitStruture.USART_StopBits = USART_StopBits_1;
    USART_InitStruture.USART_WordLength = USART_WordLength_8b;
	
    USART_Init(USART1, &USART_InitStruture);

    USART_Cmd(USART1,ENABLE);
}

void Serial_SendByte(uint8_t Byte){
    USART_SendData(USART1, Byte);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void Serial_SendArray(uint8_t *arr, uint16_t length){
      for(uint16_t i = 0; i < length; i ++){
        Serial_SendByte(arr[i]);
      } 
}
void Serial_SendPacket(void){
    Serial_SendByte(0xFF);
    Serial_SendArray(Serial_TxPacket, 4);
    Serial_SendByte(0xFE);
}

int fputc(int ch, FILE *f){
    Serial_SendByte(ch);
    return ch;
    
}
