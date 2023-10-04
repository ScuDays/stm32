#include "stm32f10x.h"                  // Device header

#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "CountSensor.h"
#include "LED.h"
#include "Timer.h"
#include "PWM.h"
#include "IC.h"

 
extern u8 printNum;
int a = 0;
 int main(void)
 {	 	
	
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
    //LED_Init();			     //LED�˿ڳ�ʼ��

	PWM_Init(100 - 1 , 720 - 1);

	IC_Init(65536 - 1, 72 - 1);

	LCD_Init();
	POINT_COLOR=RED;
	LCD_Clear(WHITE);
	POINT_COLOR=RED;	
	 
	while(1)
	{
	LCD_ShowNum(30,80,IC_GetFreq(),5,24);
	}
 		
		
} 
 


	
		

 