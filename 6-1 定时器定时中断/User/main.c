////#include "stm32f10x.h"                  // Device header
////#include "Delay.h"
////#include "Buzzer.h"
////#include "LightSensor.h"
////#include "CountSensor.h"

////int main(void)
////{	
////	LED_Init();
////	LED0_ON();
////	CountSensor_Init();
////	while(1){
////	
////	}
//// 
////		
////}


//#include "led.h"
//#include "delay.h"
//#include "key.h"
//#include "sys.h"
//#include "lcd.h"
//#include "usart.h"

// 

// int main(void)
// {	 
// 	u8 x=0;
//	u8 lcd_id[12];			//存放LCD ID字符串
//	delay_init();	    	 //延时函数初始化	  
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
//	uart_init(115200);	 	//串口初始化为115200
// 	LED_Init();			     //LED端口初始化
//	LCD_Init();
//	POINT_COLOR=RED;
//	sprintf((char*)lcd_id,"LCD ID:%04X",lcddev.id);//将LCD ID打印到lcd_id数组。 

//	LCD_Clear(BLUE);
//	POINT_COLOR=RED;	  
//	LCD_ShowString(30,40,210,24,24,"Hello World"); 
//	LCD_ShowString(30,70,200,16,16,"TFTLCD TEST");
//	LCD_ShowString(30,90,200,16,16,"ATOM@ALIENTEK");
// 	LCD_ShowString(30,110,200,16,16,lcd_id);		//显示LCD ID	      					 
//	LCD_ShowString(30,130,200,12,12,"2015/1/14");	      					 
//	  
//	
//	
//}
// 


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
	
 	printNum=0;			//存放LCD ID字符串
	delay_init();	    	 //延时函数初始化
	LED_Init();
	LED0_ON();
	CountSensor_Init();	 
	
	uart_init(115200);	 	//串口初始化为115200
	LCD_Init();
	POINT_COLOR=RED;
	LCD_Clear(WHITE);
	POINT_COLOR=RED;	

	Timer_Init();
	while(1){
		
		LCD_ShowNum(30,40,a,2,24);
		 
		
	} 		 
		
} 

 