#include "stm32f10x.h"                  // Device header

void LED_Init(void)
{
	
	//打开GPIOEB的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure1.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure1);

	

	GPIO_InitTypeDef GPIO_InitStructure2;
	GPIO_InitStructure2.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure2.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure2.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure2);

	
	 
}

void LED1_ON(void){

	GPIO_ResetBits(GPIOE,GPIO_Pin_5);
}

void LED1_OFF(void){

	GPIO_SetBits(GPIOE,GPIO_Pin_5);
}

void LED1_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin_5)==0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_5);
	}
	else
	{
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
	}
}




void LED0_ON(void){

	GPIO_ResetBits(GPIOB,GPIO_Pin_5);
}

void LED0_OFF(void){

	GPIO_SetBits(GPIOB,GPIO_Pin_5);
}

void LED0_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5)==0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	}
}

