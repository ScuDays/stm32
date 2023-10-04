
#include "stm32f10x.h"                  // Device header

#include "PWM.h"


void PWM_Init(u16 arr,u16 psc){

    TIM_OCInitTypeDef TIM_OCInitStructure;
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;  
    //ʹ�ܶ�ʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    //��GPIOEB��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
   
    GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);


	
    /*��ʼ������*/
    //��ppt��֪��Ҫ���������
    GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

   
    /*��ʼ��TIM3*/
    //�˲�����Ƶ
    TIM_TimeBaseInitStructure.TIM_ClockDivision = 0 ;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up  ;
    //����������һ������ƫ�������Ҫ��ȥ1
    //�����Զ���װ����ֵ
    TIM_TimeBaseInitStructure.TIM_Period = 720 - 1;
    //����PSCԤ��Ƶ����ֵ
    TIM_TimeBaseInitStructure.TIM_Prescaler = 100 - 1;

    //�ظ����������߼���ʱ�����У����ﲻ�����ã�����0����
    //TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
  
	//��ʼ��TIM3 Channel2 PWMģʽ 

    //�����������ע�͵�һ�оͻ�����⣬��֪��Ϊʲô��
    //TIM_OCStructInit(&TIM_OCInitStructure);
    TIM_OCInitStructure.TIM_Pulse = 10;

    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
    TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_OutputNState = TIM_OutputState_Enable;

    TIM_OC2Init(TIM3,&TIM_OCInitStructure);
    //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
    TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
    
    //���ض�TIMʹ��
    TIM_Cmd(TIM3, ENABLE);
}
void PWM_SetCompare2(uint16_t Compare){
	TIM_SetCompare2(TIM3,Compare);
}