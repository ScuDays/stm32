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
	
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
    //LED_Init();			     //LED端口初始化

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
 


	
		

 