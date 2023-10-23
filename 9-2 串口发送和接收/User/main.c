
#include "Serial.h"



 int main(void)
 {	 	
 	//printNum=0;			
	//delay_init();	    	
	//LED_Init();
	//LED0_ON();
	Serial_Init();
	
 	//uart_init(9600);
	// LCD_Init();
	// POINT_COLOR=RED;
	// LCD_Clear(WHITE);
	// POINT_COLOR=RED;	

	//Serial_SendByte(0X41);
	//Serial_SendByte('A');
	//printf("Num=%d\r\n", 666);
	Serial_TxPacket[0] = 0x01;
	Serial_TxPacket[1] = 0x02;
	Serial_TxPacket[2] = 0x03;
	Serial_TxPacket[3] = 0x04;
	Serial_SendPacket();
	while(1){
		if(Serial_GetRxFlag() == 1){
			Serial_SendByte('A');
		}
		
		
	}		 
		
} 

 