#include "stm32f10x.h"                  // Device header


void LightSensor_Init(void){

	//打开GPIOF的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);

	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure1.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure1.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOF,&GPIO_InitStructure1);

}


uint8_t LightSensor_Get(void){
	return GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_8);
	
}

