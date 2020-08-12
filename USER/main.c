#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "oled.h"
#include "FDC2214.h"
#include "timer.h"
#include "control.h"
#include "show.h"

void FDC2214_GetData(void);
u32 ch0,ch1,ch2,ch3;
double fre=0,cap3_first=0;
int main(void)
{ 
	Stm32_Clock_Init(9); 	//系统时钟设置78
	delay_init();//延时函数初始化	
  uart_init(72,921600);//串口初始化   789
  TIM1_36Mhz_Init();//stm32定时器1输出一个36mhz方波，作为fdc2214的时钟。如果板载了40mhz的晶振，这个就不需要了。
  OLED_Init();
  IIC_Init();
  FDC2214_Init(); 
//	KEY_Init();
	OLED_Clear();
	delay_ms(100);
	FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
	cap3_first=FDC2214_getcap(ch3);//读初始值
	printf("cap3_first=%f \r\n",cap3_first);
	while(1)
	{
		FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
		CPChannel_Control();
//	 FDC2214_GetData();
// //       printf("\r\nCH0~3(%d , %d , %d , %d)",ch0,ch1,ch2,ch3);
//		printf("CH3:	%d	",ch3);
////		 fre=FDC2214_CalculateFrequency(FDC2214_Channel_3,ch3);
////		printf("fre:	%f	",fre);
//	   cap_old=232021045.248/(ch3);
//	   cap_new=cap_old*cap_old;
//		printf("cap:	%f \r\n",cap_new);
//	 				if( ch3>39074313 )
//						printf("没有手\r\n");
//					else
//						printf("有!\r\n");
//	  	OLED_ShowString(0,1,"cap:");
//		  OLED_ShowNum(50,1,cap_new,4,12);      //显示整数部分	   		
			delay_ms(500);	 //延时300ms
	}
 }
void FDC2214_GetData(void)
{
    FDC2214_GetChannelData(FDC2214_Channel_0, &ch0);  
    FDC2214_GetChannelData(FDC2214_Channel_1, &ch1);
    FDC2214_GetChannelData(FDC2214_Channel_2, &ch2);
    FDC2214_GetChannelData(FDC2214_Channel_3, &ch3);
}
