#include "action.h"
#include "sys.h"


void guiwei(void)
{
	PWM2=210;	PWM3=230 ;	PWM4=110;delay_ms(600);PWM5=150;delay_ms(600);	
}

void Servo_Get_1(void)
{
	PWM5=220;
	PWM1=190;
	PWM2=110;
	PWM3=250 ;	PWM4=165;	delay_ms(400);
	PWM1=120;delay_ms(600);
	guiwei();
}
void Servo_Get_2(void)
{
	PWM5=220;
	PWM1=190;
	PWM2=120;delay_ms(400);
	PWM3=230 ;	PWM4=175;	delay_ms(400);
	PWM1=120;delay_ms(600);
	guiwei();
}
void Servo_Get_3(void)
{
	PWM5=220;
	PWM1=190;
	PWM2=155;delay_ms(400);
	PWM2=155;	PWM3=150 ;	PWM4=215;	delay_ms(400);
	PWM1=120;delay_ms(600);PWM4=180;delay_ms(400);
	guiwei();
}
void Get_1(void)
{
	Track_Flag=4;
	Track_Flag=3;
	delay_ms(100);
	Track_Flag=11;
	delay_ms(400);
	Track_Flag=0;
	Servo_Get_1();
	LEFT(1);
	
}
void Get_2(void)
{
	Track_Flag=4;
	for(;(D1&&D7)!=1;);delay_ms(50);
	Track_Flag=11;
	delay_ms(400);
	Track_Flag=0;
	Servo_Get_2();
	LEFT(1);
}
void Get_3(void)
{
	Track_Flag=4;
	for(;(D1&&D7)!=1;);delay_ms(50);
	Track_Flag=11;
	delay_ms(400);
	Track_Flag=0;
	Servo_Get_3();
	LEFT(1);
}
void Put(void)
{
	int i;
	Track_Flag=11;
	PWM1=120;
	PWM2=130;
	PWM5=88;delay_ms(500);
	Track_Flag=0;
	for(i=0;i<5;i++)
	{
		PWM3+=2 ;	PWM4+=9;	delay_ms(50);
	}
	
	PWM2=130;	PWM3=240 ;	PWM4=155;	delay_ms(400);
	PWM1=190;delay_ms(600);
	guiwei();
}

//int Go(u8 n)
//{
//	switch(n)
//	{
//		case 1:
//			Get_1();
//			Move(1,6);
//			break;
//		case 2:
//			Get_2();
//			Move(3,6);
//			break;
//		case 3:
//			Get_3();
//			Move(5,6);
//			break;
//		default : break;
//	}
//}

void Begin(void)
{
	int i;
	RGB();
	Set_Pwm(0,50,50,0);
	for(;(B2&&B6)!=1;);delay_ms(200);
	for(;(C3||C4||C5)!=1;);
	Track_Flag=12;delay_ms(300);
	Move(0,1);
	Move(2,1);

	for(i=0;i<=2;i++)
	{
		switch(i)
		{
			case 0:Get_3();break;
			case 1:Get_2();break;
			case 2:Get_1();break;
			default : break;
		}
		switch(target_RGB[i])
		{
			case 1:Move(1,6);break;
			case 2:Move(3,6);break;
			case 3:Move(5,6);break;
			default : break;
		}
		Put();
		Move(2,1);
	}
	Move(0,1);
	Move(0,0);
	Track_Flag=5;
	Set_Pwm(0,-50,-50,0);
	for(;(B2&&B6)!=1;);
	delay_ms(300);
	Track_Flag=0;
}

