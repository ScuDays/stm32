#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	
	//打开GPIOEB的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	
	
	
	GPIO_InitTypeDef GPIO_InitStructure;
	//设置推挽模式
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	//设置5号端口
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	//设置速率
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	//初始化GPIOB 8号端口
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	

	GPIO_SetBits(GPIOB,GPIO_Pin_8);
	Delay_s(2);
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	 

 
		
}
