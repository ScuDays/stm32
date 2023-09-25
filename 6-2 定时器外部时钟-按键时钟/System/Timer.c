#include <stm32f10x.h>
#include <Timer.h>

extern int a;
void Timer_Init(void)
{
   
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
    //开启GPIO外设时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
    GPIO_PinAFConfig(GPIOE, GPIO_PinSource, GPIO_AF_TIM3);

    //设置外部时钟
    TIM_ETRClockMode2Config(TIM3,TIM_ExtTRGPolarity_Inverted,TIM_ExtTRGPolarity_NonInverted,0X00);

    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    //滤波器分频
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up  ;

    //这两个都有一个数的偏差，所以需要减去1
    //设置自动重装器的值
    TIM_TimeBaseInitStructure.TIM_Period = 10 - 1;
    //设置PSC预分频器的值
    TIM_TimeBaseInitStructure.TIM_Prescaler = 1 - 1;
    //重复计数器，高级定时器才有，这里不用设置，给个0就行
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

    TIM_ClearFlag(TIM3, TIM_IT_Update);
    TIM_ITConfig(TIM3,TIM_EventSource_Update,ENABLE);


    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(TIM3, ENABLE);

}

uint16_t TImer_GetCounter(void)
{
    return TImer_GetCounter();
}

void TIM3_IRQHandler(void){
    if(TIM_GetITStatus(TIM3, TIM_IT_Update) == SET){

        a++;
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
    }
}