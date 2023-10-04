 #include "stm32f10x.h"                  // Device header

 #include "PWM.h"


 void PWM_Init(u16 arr,u16 psc){

     TIM_OCInitTypeDef TIM_OCInitStructure;
     TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
  
    
     //使能定时器
     RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
     //打开GPIOEB的时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟
   
     GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);
	
     /*初始化引脚*/
     //看ppt就知道要用推挽输出
     GPIO_InitTypeDef GPIO_InitStructure;

 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
 	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
 	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOB,&GPIO_InitStructure);
     /*初始化TIM3*/
     //滤波器分频
     TIM_TimeBaseInitStructure.TIM_ClockDivision = 0 ;
     TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up  ;
     //这两个都有一个数的偏差，所以需要减去1
     //设置自动重装器的值
     TIM_TimeBaseInitStructure.TIM_Period = arr;
     //设置PSC预分频器的值
     TIM_TimeBaseInitStructure.TIM_Prescaler = psc;

     //重复计数器，高级定时器才有，这里不用设置，给个0就行
     //TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
     TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
  
 	//初始化TIM3 Channel2 PWM模式 

     //如果加上下面注释的一行就会出问题，不知道为什么。
     //TIM_OCStructInit(&TIM_OCInitStructure);
     TIM_OCInitStructure.TIM_Pulse = 10;

     TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
     TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_High;
     TIM_OCInitStructure.TIM_OutputNState = TIM_OutputState_Enable;
		
     TIM_OC2Init(TIM3,&TIM_OCInitStructure);
     //使能TIM3在CCR2上的预装载寄存器
     TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
    
     //对特定TIM使能
     TIM_Cmd(TIM3, ENABLE);
 }
    
void PWM_SetCompare2(uint16_t Compare){
	TIM_SetCompare2(TIM3,Compare);
}

