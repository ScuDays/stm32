
#include "Serial.h"

uint8_t RxData;

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
	

	while(1){

		if(Serial_GetRxFlag() == 1){
			RxData = Serial_GetRxData();
			Serial_SendByte(RxData);		
		}
		
	} 		 
		
} 

 