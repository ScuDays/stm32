#include "stm32f10x.h"                  // Device header
void Buzzer_Init(void)
{
	
	//打开GPIOB的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure1.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure1);


}

void Buzzer_ON(void){

	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
}

void Buzzer_OFF(void){

	GPIO_SetBits(GPIOB,GPIO_Pin_8);
}

void Buzzer_Turn(void){
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_8)==0)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	}
}


