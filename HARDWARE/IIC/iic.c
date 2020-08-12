#include "iic.h"


void IIC_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(	RCC_APB2Periph_GPIOB, ENABLE );	//使能GPIOB时钟
    
    
    RCC_APB2PeriphClockCmd(	RCC_APB2Periph_AFIO, ENABLE );
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);//关闭JTAG，释放PB3,PB4,PA15
    
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB,GPIO_Pin_3|GPIO_Pin_4); 	//输出高
}

void delay_2us(void)
{
    //一个NOP是1/72us  所以72个NOP是1us
    u32 i=0;  
    for(i=0;i<2;i++)
    {  
        __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
        __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
        __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
        __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
        __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();  
        __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
        __NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();__NOP();
   
    }  
}
void IIC_Start(void)
{
	SDA_OUT();
	IIC_SDA_OUT=1;	  	  
	IIC_SCL=1;
	delay_2us();
 	IIC_SDA_OUT=0;
	delay_2us();
	IIC_SCL=0;
	delay_2us();
}	  


void IIC_Stop(void)
{
	SDA_OUT();
	IIC_SCL=0;
    delay_2us();
	IIC_SDA_OUT=0;
 	delay_2us();
	IIC_SCL=1; 
    delay_2us();
	IIC_SDA_OUT=1;
	delay_2us();						   	
}

u8 IIC_Wait_Ack(void)
{
	u8 waitTime=0;
	SDA_IN();  
	IIC_SDA_OUT=1;
    delay_2us();	   
	IIC_SCL=1;
    delay_2us(); 
	while(IIC_SDA_IN)
	{
		waitTime++;
		if(waitTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL=0;   
	return 0;  
} 

void IIC_Ack(void)
{
	IIC_SCL=0;
    delay_2us();
	SDA_OUT();
	IIC_SDA_OUT=0;//发送0是ACK
	delay_2us();
	IIC_SCL=1;
	delay_2us();
	IIC_SCL=0;
    delay_2us();
}

void IIC_NAck(void)
{
	IIC_SCL=0;
    delay_2us();
	SDA_OUT();
	IIC_SDA_OUT=1;//发送1是nACK
	delay_2us();
	IIC_SCL=1;
	delay_2us();
	IIC_SCL=0;
    delay_2us();
}

void IIC_Send_Byte(u8 dat)
{                        
    u8 t;   
	SDA_OUT(); 
    IIC_SCL=0;	
    for(t=0;t<8;t++)
    {      
        
		delay_2us();
        IIC_SDA_OUT=(dat&0x80)>>7;
        dat<<=1;
        IIC_SCL=1;        
		delay_2us();
		IIC_SCL=0;
		delay_2us();	
    }
    //IIC_SCL=0;
} 

u8 IIC_Read_Byte(u8 ack)
{
	u8 i,receive=0;
	IIC_SDA_OUT=1;
    SDA_IN();
    for(i=0;i<8;i++ )
	{
        receive<<=1;
        
        IIC_SCL=0; 
        delay_2us();
		IIC_SCL=1;
        delay_2us();
        if(IIC_SDA_IN)receive++;//最低位置1   
    }
    IIC_SCL=0; 
    if (!ack)
        IIC_NAck();
    else
        IIC_Ack();  
    return receive;
}





