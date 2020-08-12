#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK miniSTM32开发板
//按键驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/3
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////   	 


//#define KEY0 PCin(5)   	
//#define KEY1 PAin(15)	 
//#define WK_UP  PAin(0)	 
 

//#define KEY0  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_6)//读取按键0
//#define KEY1  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)//读取按键1
////#define KEY2  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//读取按键2 
//#define KEY3  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//读取按键3
#define KEY3 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3

#define KEY0_PRES	100		//KEY0  
#define KEY1_PRES	10		//KEY1 
#define KEY2_PRES	1		//WK_UP 
#define KEY3_PRES	1		//key3


#define key0 PBin(6)
#define key1 PBin(7)
#define key2 PBin(8)
#define key3 PAin(0)

void KEY_Init(void);//IO初始化
//u8 KEY0_Scan(u8 mode);  	//按键扫描函数	
//u8 KEY1_Scan(u8 mode);
//u8 KEY2_Scan(u8 mode);
//u8 KEY_Scan(u8 mode);
#endif
