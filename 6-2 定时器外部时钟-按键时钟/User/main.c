


#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "CountSensor.h"
#include "LED.h"
#include "Timer.h"

 
extern u8 printNum;
int a = 0;
 int main(void)
 {	 	
	
 	printNum=0;			//���LCD ID�ַ���
	delay_init();	    	 //��ʱ������ʼ��
	LED_Init();
	LED0_ON();
	//CountSensor_Init();	 
	
	uart_init(115200);	 	//���ڳ�ʼ��Ϊ115200
	LCD_Init();
	POINT_COLOR=RED;
	LCD_Clear(WHITE);
	POINT_COLOR=RED;	

	Timer_Init();
	while(1){
		
		LCD_ShowNum(30,40,a,2,24);
		LCD_ShowNum(30,80,TImer_GetCounter(),5,24)
		
	} 		 
		
} 

 