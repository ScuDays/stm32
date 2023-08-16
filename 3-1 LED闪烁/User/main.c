#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main(void)
{
	
	//打开GPIOE和GPIOEB的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	//设置推挽模式
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	//设置5号端口
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	//设置速率
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	//初始化GPIOE 5号端口
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	//初始化GPIOB 5号端口
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	//设置推挽模式
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	//设置5号端口
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	//设置速率
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	//初始化GPIOB 8号端口
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	
	
	
//	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
//	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
//	GPIO_SetBits(GPIOE,GPIO_Pin_5);
//	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	
	
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	 
	while(1)
	{
		GPIO_WriteBit(GPIOE,GPIO_Pin_5,Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOE,GPIO_Pin_5,Bit_SET);
		Delay_ms(500);
		
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_RESET);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,Bit_SET);
		Delay_ms(500);
		
	
		
		
	}
 
		
}
