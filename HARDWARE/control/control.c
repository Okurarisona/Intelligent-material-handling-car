#include "control.h"
#include "sys.h"



int Track_Flag=0;	
int Key_ON=0;
int move_x=0;
int move_y=0;

void Tracking(void)
{
	switch(Track_Flag)
	{
		case 0: Set_Pwm(0,0,0,0);	
			break;
		case 1:	FRONT_Track(1);		
			break;
		case 2: BACK_Track(1);		
			break;
		case 3: LEFT_Track(1);		
			break;
		case 4: RIGHT_Track(1);		
			break;
		case 5: 
			break;
		
		case 6: BACK_BZ(1);		
			break;
		case 7: FRONT_BZ(1);		
			break;
		case 8: RIGHT_BZ(1);		
			break;
		case 9: LEFT_BZ(1);	
			break;
		case 10:
			break;
		case 11:RIGHT_BZ(1);		
				LEFT_BZ(1);		
			break;
		case 12:
				if(Key_ON<30)
				{
					BACK_BZ(1);		
					FRONT_BZ(1);
					Key_ON++;
				}
				else if(Key_ON>0)
				{				
					RIGHT_BZ(1);	
					LEFT_BZ(1);		
					Key_ON--;
				}
			break;
		default : break;
	}
	
}	
void FRONT_Track(int data)
{
	int V=40;
	if(FRONT_DATA==8)							Set_Pwm(V,V,V,V);
	else if(FRONT_DATA==12)						Set_Pwm(V+15,V,V-10,V);
	else if((FRONT_DATA==6)||(FRONT_DATA==4)) 	Set_Pwm(V+20,V,V-15,V);
	else if((FRONT_DATA==2)||(FRONT_DATA==3))	Set_Pwm(V+25,V,V-20,V);
	else if(FRONT_DATA==1)						Set_Pwm(V+40,V,V-25,V);
	
	else if(FRONT_DATA==24)						Set_Pwm(V-10,V,V+15,V);
	else if((FRONT_DATA==48)||(FRONT_DATA==16)) Set_Pwm(V-15,V,V+20,V);
	else if((FRONT_DATA==32)||(FRONT_DATA==96))	Set_Pwm(V-20,V,V+25,V);
	else if(FRONT_DATA==64)						Set_Pwm(V-25,V,V+40,V);
	else										Set_Pwm(V,V,V,V);
	
}
void BACK_Track(int data)
{
	int V=-40;
	if(BACK_DATA==8)							Set_Pwm(V,V,V,V);
	else if(BACK_DATA==12)						Set_Pwm(V,V+5,V,V-10);
	else if((BACK_DATA==6)||(BACK_DATA==4)) 	Set_Pwm(V,V+10,V,V-15);
	else if((BACK_DATA==2)||(BACK_DATA==3))	Set_Pwm(V,V+15,V,V-20);
	else if(BACK_DATA==1)						Set_Pwm(V,V+20,V,V-30);
	
	else if(BACK_DATA==24)						Set_Pwm(V,V-10,V,V+5);
	else if((BACK_DATA==48)||(BACK_DATA==16)) Set_Pwm(V,V-15,V,V+10);
	else if((BACK_DATA==32)||(BACK_DATA==96))	Set_Pwm(V,V-20,V,V+15);
	else if(BACK_DATA==64)						Set_Pwm(V,V-30,V,V+20);
	else										Set_Pwm(V,V,V,V);
	

}
void RIGHT_Track(int data)
{
	int V=45;
//	if(RIGHT_DATA==20)												Set_Pwm(V,-V,-V,V);
//	else if(RIGHT_DATA==12)											Set_Pwm(V,-V,-V-10,V-5);
//	else if((RIGHT_DATA==6)||(RIGHT_DATA==4)||(RIGHT_DATA==10)) 	Set_Pwm(V,-V,-V-15,V-10);
//	else if((RIGHT_DATA==2)||(RIGHT_DATA==3))						Set_Pwm(V,-V,-V-20,V-15);
//	else if(RIGHT_DATA==1)											Set_Pwm(V,-V,-V-30,V-20);
//	
//	else if(RIGHT_DATA==24)											Set_Pwm(V,-V,-V+5,V+10);
//	else if((RIGHT_DATA==48)||(RIGHT_DATA==16)||(RIGHT_DATA==40))	Set_Pwm(V,-V,-V+10,V+15);
//	else if((RIGHT_DATA==32)||(RIGHT_DATA==96)||(RIGHT_DATA==80))	Set_Pwm(V,-V,-V+15,V+20);
//	else if(RIGHT_DATA==64)											Set_Pwm(V,-V,-V+20,V+30);
//	else															Set_Pwm(V,-V,-V,V);	
	
	if((RIGHT_DATA==20)||(RIGHT_DATA==28))												Set_Pwm(V+10,-V,-V-5,V);
	else if((RIGHT_DATA==12)||(RIGHT_DATA==10)||(RIGHT_DATA==14))						Set_Pwm(V+10,-V,-V-10-5,V-5);
	else if((RIGHT_DATA==6)||(RIGHT_DATA==4)||(RIGHT_DATA==7)||(RIGHT_DATA==5))			Set_Pwm(V+10,-V,-V-15-5,V-10);
	else if((RIGHT_DATA==2)||(RIGHT_DATA==3))											Set_Pwm(V+10,-V,-V-20-5,V-15);
	else if((RIGHT_DATA==1)||(RIGHT_DATA==5))											Set_Pwm(V+10,-V,-V-30-5,V-20);
	
	else if((RIGHT_DATA==24)||(RIGHT_DATA==40)||(RIGHT_DATA==80))						Set_Pwm(V+10,-V,-V+5-5,V+10);
	else if((RIGHT_DATA==48)||(RIGHT_DATA==16)||(RIGHT_DATA==160)||(RIGHT_DATA==224)) 	Set_Pwm(V+10,-V,-V+10-5,V+15);
	else if((RIGHT_DATA==32)||(RIGHT_DATA==96))											Set_Pwm(V+10,-V,-V+15-5,V+20);
	else if((RIGHT_DATA==64)||(RIGHT_DATA==80))											Set_Pwm(V+10,-V,-V+20-5,V+30);
	else															Set_Pwm(V,-V,-V,V);	
}

void LEFT_Track(int data)
{
	int V=45;
//	if(LEFT_DATA==20)											Set_Pwm(-V,V,V,-V);
//	else if(LEFT_DATA==12)										Set_Pwm(-V+5,V+10,V,-V);
//	else if((LEFT_DATA==6)||(LEFT_DATA==4)||(LEFT_DATA)==10) 	Set_Pwm(-V+10,V+15,V,-V);
//	else if((LEFT_DATA==2)||(LEFT_DATA==3)||(LEFT_DATA)==5)		Set_Pwm(-V+15,V+20,V,-V);
//	else if(LEFT_DATA==1)										Set_Pwm(-V+20,V+30,V,-V);
//	
//	else if(LEFT_DATA==24)										Set_Pwm(-V-10,V-5,V,-V);
//	else if((LEFT_DATA==48)||(LEFT_DATA==16)||(LEFT_DATA)==40) 	Set_Pwm(-V-15,V-10,V,-V);
//	else if((LEFT_DATA==32)||(LEFT_DATA==96)||(LEFT_DATA)==80)	Set_Pwm(-V-20,V-15,V,-V);
//	else if(LEFT_DATA==64)										Set_Pwm(-V-10,V-5,V,-V);
//	else 														Set_Pwm(-V,V,V,-V);
	
	if((LEFT_DATA==20)||(LEFT_DATA==28))												Set_Pwm(-V,V,V,-V);
	else if((LEFT_DATA==12)||(LEFT_DATA==10)||(LEFT_DATA==14))							Set_Pwm(-V+5,V+10,V,-V);
	else if((LEFT_DATA==6)||(LEFT_DATA==4)||(LEFT_DATA==7)||(LEFT_DATA==5))				Set_Pwm(-V+10,V+15,V,-V);
	else if((LEFT_DATA==2)||(LEFT_DATA==3))												Set_Pwm(-V+15,V+20,V,-V);
	else if((LEFT_DATA==1)||(LEFT_DATA==5))												Set_Pwm(-V+20,V+30,V,-V);
	
	else if((LEFT_DATA==24)||(LEFT_DATA==40)||(LEFT_DATA==80))							Set_Pwm(-V-10,V-5,V,-V);
	else if((LEFT_DATA==48)||(LEFT_DATA==16)||(LEFT_DATA==160)||(LEFT_DATA==224)) 		Set_Pwm(-V-15,V-10,V,-V);
	else if((LEFT_DATA==32)||(LEFT_DATA==96))											Set_Pwm(-V-20,V-15,V,-V);
	else if((LEFT_DATA==64)||(LEFT_DATA==80))											Set_Pwm(-V-10,V-5,V,-V);
	else 														Set_Pwm(-V,V,V,-V);
}



void BACK_BZ(int data)
{

	if(BACK_DATA==8)							{Motor_B(0);Motor_D(0);}
	else if(BACK_DATA==12)						{Motor_B(30);Motor_D(-30);}
	else if((BACK_DATA==6)||(BACK_DATA==4)) 	{Motor_B(35);Motor_D(-35);}
	else if((BACK_DATA==2)||(BACK_DATA==3))		{Motor_B(40);Motor_D(-40);}
	else if(BACK_DATA==1)						{Motor_B(50);Motor_D(-50);}
	
	else if(BACK_DATA==24)						{Motor_B(-30);Motor_D(30);} 
	else if((BACK_DATA==48)||(BACK_DATA==16)) 	{Motor_B(-35);Motor_D(35);}
	else if((BACK_DATA==32)||(BACK_DATA==96))	{Motor_B(-40);Motor_D(40);}
	else if(BACK_DATA==64)						{Motor_B(-50);Motor_D(50);}
	
}

void FRONT_BZ(int data)
{
	if(FRONT_DATA==8)							{Motor_A(0);Motor_A(0);}
	else if(FRONT_DATA==12)						{Motor_A(30);Motor_C(-30);}
	else if((FRONT_DATA==6)||(FRONT_DATA==4)) 	{Motor_A(35);Motor_C(-35);}
	else if((FRONT_DATA==2)||(FRONT_DATA==3))	{Motor_A(40);Motor_C(-40);}
	else if(FRONT_DATA==1)						{Motor_A(50);Motor_C(-50);}
	
	else if(FRONT_DATA==24)						{Motor_A(-30);Motor_C(30);} 
	else if((FRONT_DATA==48)||(FRONT_DATA==16)) {Motor_A(-35);Motor_C(35);}
	else if((FRONT_DATA==32)||(FRONT_DATA==96))	{Motor_A(-40);Motor_C(40);}
	else if(FRONT_DATA==64)						{Motor_A(-50);Motor_C(50);}
}
void RIGHT_BZ(int data)
{
	if((RIGHT_DATA==20)||(RIGHT_DATA==28))												{Motor_D(0);Motor_C(0);}
	else if((RIGHT_DATA==12)||(RIGHT_DATA==10)||(RIGHT_DATA==14))						{Motor_D(-30);Motor_C(-30);}
	else if((RIGHT_DATA==6)||(RIGHT_DATA==4)||(RIGHT_DATA==7)||(RIGHT_DATA==5))			{Motor_D(-30);Motor_C(-30);}
	else if((RIGHT_DATA==2)||(RIGHT_DATA==3))											{Motor_D(-35);Motor_C(-35);} 
	else if((RIGHT_DATA==1)||(RIGHT_DATA==5))											{Motor_D(-40);Motor_C(-40);}
	
	else if((RIGHT_DATA==24)||(RIGHT_DATA==40)||(RIGHT_DATA==80))						{Motor_D(30);Motor_C(30);} 
	else if((RIGHT_DATA==48)||(RIGHT_DATA==16)||(RIGHT_DATA==160)||(RIGHT_DATA==224)) 	{Motor_D(30);Motor_C(30);}
	else if((RIGHT_DATA==32)||(RIGHT_DATA==96))											{Motor_D(35);Motor_C(35 );}
	else if((RIGHT_DATA==64)||(RIGHT_DATA==80))											{Motor_D(40);Motor_C(40);}
	
}
void LEFT_BZ(int data)
{
	if((LEFT_DATA==20)||(LEFT_DATA==28))												{Motor_A(0);Motor_B(0);}
	else if((LEFT_DATA==12)||(LEFT_DATA==10)||(LEFT_DATA==14))							{Motor_A(30);Motor_B(30);}
	else if((LEFT_DATA==6)||(LEFT_DATA==4)||(LEFT_DATA==7)||(LEFT_DATA==5))				{Motor_A(30);Motor_B(30);}
	else if((LEFT_DATA==2)||(LEFT_DATA==3))												{Motor_A(35);Motor_B(35);} 
	else if((LEFT_DATA==1)||(LEFT_DATA==5))												{Motor_A(40);Motor_B(40);}
	
	else if((LEFT_DATA==24)||(LEFT_DATA==40)||(LEFT_DATA==80))							{Motor_A(-30);Motor_B(-30);} 
	else if((LEFT_DATA==48)||(LEFT_DATA==16)||(LEFT_DATA==160)||(LEFT_DATA==224)) 		{Motor_A(-30);Motor_B(-30);}
	else if((LEFT_DATA==32)||(LEFT_DATA==96))											{Motor_A(-35);Motor_B(-35 );}
	else if((LEFT_DATA==64)||(LEFT_DATA==80))											{Motor_A(-40);Motor_B(-40);}
	
}

void FRONT(int n)
{
	Track_Flag=1;
	while(n)
	{
		
		delay_ms(200);for(;(C1&&C7)!=1;);
		delay_ms(200);for(;(D3||D4||D5)!=1;);
		n--;
	}
	Track_Flag=12;
}

void BACK(int n)
{
	Track_Flag=2;
	while(n)
	{
		delay_ms(200);for(;(A1&&A7)!=1;);
		delay_ms(200);for(;(D3||D4||D5)!=1;);
		n--;
	}
	Track_Flag=12;
}

void LEFT(int n)
{
	Track_Flag=3;
	while(n)
	{
		delay_ms(200);for(;(B1&&B7)!=1;);
		delay_ms(200);for(;(A3||A4||A5)!=1;);
		n--;
	}
	Track_Flag=12;
}

void RIGHT(int n)
{
	Track_Flag=4;
	while(n)
	{
		delay_ms(200);for(;(D1&&D7)!=1;);
		delay_ms(200);for(;(A3||A4||A5)!=1;);
		n--;
	}
	Track_Flag=12;
}

void Move(int x,int y)
{
	int num_x,num_y;
	num_x=x-move_x;
	num_y=y-move_y;
	move_x=x;
	move_y=y;
	if(num_x<0)
	{
		num_x=0-num_x;
		BACK(num_x);
		delay_ms(600);
	}
	else 
	{
		FRONT(num_x);
		delay_ms(600);
	}
	if(num_y<0)
	{
		num_y=0-num_y;
		RIGHT(num_y);
		delay_ms(600);
	}
	else 
	{
		LEFT(num_y);
		delay_ms(600);
	}
}
	


