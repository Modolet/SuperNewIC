#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;
u16 Count=0;
sbit FeedBack=P3^7;
u16 i,j;
void UsartInit()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XF3;				//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}
void main()
{	
	UsartInit();  //	串口初始化
	//P1 = 0x99;
	while(1);		
}
void Usart() interrupt 4
{
	u8 receiveData;
	receiveData=SBUF;//出去接收到的数据 键盘输入ASCALL码无控制字符，故从打印字符记为32为0x20为0x00
	if(Count%3==0){
		P0 = receiveData;//显示接受的数据
		Count++;
	}else if(Count%3==1){
		P1 = receiveData;
		Count++;
	}else if(Count%3==2){
		Count = 0;
		P2 = receiveData;
	}
	RI = 0;//清除接收中断标志位
	//if(Count%3==0)
	for(i=0;i<240;i++)
		for(j=0;j<240;j++);
	SBUF=FeedBack;//将接收到的数据放入到发送寄存器
	while(!TI);			 //等待发送数据完成
	TI=0;						 //清除发送完成标志位
	
}










