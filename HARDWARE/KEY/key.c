#include "key.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK Mini STM32开发板
//按键输入 驱动代码		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2014/3/06
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									   
//////////////////////////////////////////////////////////////////////////////////	 
 	    
//按键初始化函数 
//PA15和PC5 设置成输入
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//使能PORTB时钟

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭jtag，使能SWD，可以用SWD模式调试
	
//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;//PB1
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
// 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB1
//	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_6;//PB6
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB6
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_7;//PB7
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB7
 
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8;//PB8
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOB8
	
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;//PC5
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOC5
	
} 

//void KEY_Init(void)
//{
//		RCC->APB2ENR|=1<<3;     //使能PORTB时钟
////	//RCC->APB2ENR|=1<<4;     //使能PORTC时钟
////	JTAG_Set(SWD_ENABLE);	//关闭JTAG,开启SWD
//	GPIOB->CRL&=0X00FFFF0F;	//PB67设置成输入	  
//	GPIOB->CRL|=0X88000080;   
//	GPIOB->CRH&=0XFFFFFFF0;	//PB8设置成输入	  
//	GPIOB->CRH|=0X000000F8;   
////	//GPIOA->CRH&=0X0FFFFFFF;	//PA15设置成输入	  
////	//GPIOA->CRH|=0X80000000; 			 
//	GPIOB->ODR|=1<<6;	   	//PA15上拉,PA0默认下拉
////	//GPIOC->CRL&=0XFF0FFFFF;	//PC5设置成输入	  
////	//GPIOC->CRL|=0X00800000;   
//	GPIOB->ODR|=1<<7;	   	//PC5上拉
//  GPIOB->ODR|=1<<1;	   	//PC5上拉 	
//	GPIOB->ODR|=1<<8;	   	//PC5上拉
//} 

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//返回值：
//0，没有任何按键按下
//KEY0_PRES，KEY0按下
//KEY1_PRES，KEY1按下
//WKUP_PRES，WK_UP按下 
//注意此函数有响应优先级,KEY0>KEY1>WK_UP!!

//u8 KEY_Scan(u8 mode)
//{	 
//	static u8 key_up=1;//按键按松开标志
//	if(mode)key_up=1;  //支持连按		  
//	if(key_up&&KEY3==0)
//	{
//		delay_ms(10);//去抖动 
//		key_up=0;
//		if(KEY3==0)return KEY3_PRES;
//	}else if(KEY3==1)key_up=1; 	     
//	return 0;// 无按键按下
//}



