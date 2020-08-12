#include "timer.h"


void TIM1_36Mhz_Init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;

    //初始化控制速度的PWM
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    TIM_TimeBaseStructure.TIM_Period = 1;
    TIM_TimeBaseStructure.TIM_Prescaler =0; 
    TIM_TimeBaseStructure.TIM_ClockDivision = 0; 
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); 


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_Pulse = 1;                           
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;    
    
    TIM_OC4Init(TIM1, &TIM_OCInitStructure); 
    TIM_CtrlPWMOutputs(TIM1,ENABLE);	
    TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable); 
   
    TIM_ARRPreloadConfig(TIM1, ENABLE);
    TIM_Cmd(TIM1, ENABLE); //使能TIM1外设
}



