#include "stm32f10x.h" 
#include <IC.h>

void IC_Init(u16 arr, u16 psc){

    
    //打开定时器的时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5,ENABLE);
    //打开GPIOEB的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	TIM_OC2PreloadConfig(TIM5,TIM_OCPreload_Enable);
    /*初始化引脚*/ 
    //看ppt就知道要用推挽输出
    GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure1);

   
    /*初始化TIM5，配置时基单元*/
   
    //选择内部时钟 
    TIM_InternalClockConfig(TIM5);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up  ;
    //这两个都有一个数的偏差，所以需要减去1
    //设置自动重装器的值
    TIM_TimeBaseInitStructure.TIM_Period = arr;
    //设置PSC预分频器的值
    TIM_TimeBaseInitStructure.TIM_Prescaler = psc;
    //重复计数器，高级定时器才有，这里不用设置，给个0就行
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM5, &TIM_TimeBaseInitStructure);


    TIM_ICInitTypeDef TIM_ICInitStructure;
    //一共有四个通道，该函数指定哪个通道
    TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;
    //配置输入捕获的滤波器    
    TIM_ICInitStructure.TIM_ICFilter = 0xF;
    TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
    TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
    TIM_ICInitStructure.TIM_ICSelection  = TIM_ICSelection_DirectTI;

    TIM_ICInit(TIM5,&TIM_ICInitStructure);

    TIM_SelectInputTrigger(TIM5, TIM_TS_TI1FP1);
    TIM_SelectSlaveMode(TIM5, TIM_SlaveMode_Reset);
    
    TIM_Cmd(TIM5, ENABLE);

}

uint32_t IC_GetFreq(void){
    return 1000000 /  TIM_GetCapture1(TIM5);
}