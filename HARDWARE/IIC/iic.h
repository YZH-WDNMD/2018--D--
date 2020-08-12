#ifndef __IIC_H
#define __IIC_H
#include "sys.h"

#define IIC_SCL         PBout(4)
#define IIC_SDA_OUT     PBout(3)
#define IIC_SDA_IN      PBin(3)

#define SDA_OUT()       {GPIOB->CRL&=0XFFFF0FFF;GPIOB->CRL|=(u32)3<<12;}//推挽输出
#define SDA_IN()        {GPIOB->CRL&=0XFFFF0FFF;GPIOB->CRL|=(u32)8<<12;}//上拉输入


void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
u8 IIC_Wait_Ack(void);
void IIC_Ack(void);
void IIC_NAck(void);
void IIC_Send_Byte(u8 dat);
u8 IIC_Read_Byte(u8 ack);

void delay_2us(void);
#endif
