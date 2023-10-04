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

 
extern u8 printNum;
int a = 0;
 int main(void)
 {	 	
	
 	u16 led0pwmval=0;
	u8 dir=1;	
	delay_init();	    	 //��ʱ������ʼ��	  
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
 	//                
	//LED_Init();    
	//PWM_Init();                                                                                      LED_Init();			     //LED�˿ڳ�ʼ��
 	PWM_Init(899 , 0);
//   	while(1)
//	{
// 		delay_ms(10);	 
//		if(dir)led0pwmval++;
//		else led0pwmval--;
// 		if(led0pwmval>300)dir=0;
//		if(led0pwmval==0)dir=1;										 
//		TIM_SetCompare2(TIM3,led0pwmval);		   
//	}	 	 

	 
	while(1){
	
		for(int i = 0; i<=100; i++){
			PWM_SetCompare2(i);
			delay_ms(10);
		}
		for(int i = 0; i<=100; i++){
			PWM_SetCompare2(100 - i);
			delay_ms(10);
		}
	}

	
		
} 

 