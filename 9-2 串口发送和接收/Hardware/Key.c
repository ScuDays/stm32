#include "stm32f10x.h" 
#include "Delay.h"

void Key_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;


    GPIO_Init(GPIOE,&GPIO_InitStructure);

}

uint8_t Key_GetNum(void)
{
    uint8_t KeyNum=0;

    //读取按键的输入
    if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)
    {
        //消除按键0按下时抖动
        delay_ms(20);
        //按键释放的时候才会执行，所以按键在按下的时候用while循环使其停顿
        while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0);
        //消除按键松开时抖动
        delay_ms(20);
        KeyNum=1;
    }

      //读取按键1的输入
    if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)
    {
        //消除按键按下时抖动
        delay_ms(20);
        //按键释放的时候才会执行，所以按键在按下的时候用while循环使其停顿
        while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0);
        //消除按键松开时抖动
        delay_ms(20);
        KeyNum=2;
    }

    return KeyNum;

} 
