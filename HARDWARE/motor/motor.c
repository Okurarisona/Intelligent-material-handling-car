#include "motor.h"
#include "sys.h"
/**************************************************************************
函数功能：电机PWM初始化
入口参数：u32 arr,u32 psc
返回  值：无
**************************************************************************/
void TIM8_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB2ENR|=1<<1;       //使能TIM8时钟   
	RCC->AHB1ENR|=1<<2;        //PORTC时钟使能 
	
	GPIO_Set(GPIOC,PIN6|PIN7|PIN8|PIN9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//复用功能,上拉输出
	GPIO_AF_Set(GPIOC,6,3);	//PC6,AF3 
	GPIO_AF_Set(GPIOC,7,3);	//PC7,AF3 
	GPIO_AF_Set(GPIOC,8,3);	//PC8,AF3 
	GPIO_AF_Set(GPIOC,9,3);	//PC9,AF3 
	
	TIM8->ARR=arr;             //设定计数器自动重装值 
	TIM8->PSC=psc;             //预分频器不分频
	TIM8->CCMR1|=6<<4;         //CH1 PWM1模式	
	TIM8->CCMR1|=6<<12;        //CH2 PWM1模式	
	TIM8->CCMR2|=6<<4;         //CH3 PWM1模式	
	TIM8->CCMR2|=6<<12;        //CH4 PWM1模式	
	
	TIM8->CCMR1|=1<<3;         //CH1预装载使能	  
	TIM8->CCMR1|=1<<11;        //CH2预装载使能	 
	TIM8->CCMR2|=1<<3;         //CH3预装载使能	  
	TIM8->CCMR2|=1<<11;        //CH4预装载使能	  
	
	TIM8->CCER|=1<<0;         //CH1输出使能	
	TIM8->CCER|=1<<4;         //CH2输出使能	   
	TIM8->CCER|=1<<8;         //CH3输出使能	 
	TIM8->CCER|=1<<12;        //CH4输出使能
	TIM8->BDTR|= 1<<15;       //TIM必须要这句话才能输出PWM
	TIM8->CR1|=1<<7;         //ARPE使能 
	TIM8->CR1|=1<<0;          //使能定时器 		
}

/**************************************************************************
函数功能：电机方向IO口初始化
入口参数：无
返回  值：无
**************************************************************************/
void Motor_int(void)
{
	RCC->AHB1ENR|=1<<5;   	//使能PORTF时钟	
	GPIO_Set(GPIOF,PIN4|PIN5|PIN6|PIN7|PIN12|PIN13|PIN14|PIN15,GPIO_MODE_OUT,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//上拉输出
}


/**************************************************************************
函数功能：赋值给PWM寄存器
入口参数：4轮PWM
返回  值：无
**************************************************************************/
void Set_Pwm(int moto1,int moto2,int moto3,int moto4)
{
		if(moto1!=0)
		{
    	if(moto1<0)			AIN2=0,			AIN1=1;
			else 	          AIN2=1,			AIN1=0;
		}
		else AIN2=1,			AIN1=1;
			PWMA=myabs(moto1);
		if(moto2!=0)
		{
		  if(moto2<0)	BIN1=0,			BIN2=1;
			else        BIN1=1,			BIN2=0;
		}
		else BIN1=1,			BIN2=1;
			PWMB=myabs(moto2);	
		if(moto3!=0)
		{
		  if(moto3<0)	CIN1=1,			CIN2=0; 
			else         CIN1=0,			CIN2=1;
		}
		else CIN1=1,			CIN2=1;
			PWMC=myabs(moto3);	
		if(moto4!=0)
		{
		  if(moto4<0)		DIN1=1,			DIN2=0;
			else        	DIN1=0,			DIN2=1;
		}
		else DIN1=1,			DIN2=1;
			PWMD=myabs(moto4);
}
void Motor_A(int a)
{
	if(a!=0)
	{
	if(a<0)			AIN2=0,			AIN1=1;
		else 	          AIN2=1,			AIN1=0;
	}
	else AIN2=1,			AIN1=1;
	PWMA=myabs(a);
}
void Motor_B(int b)
{
		if(b!=0)
		{
		  if(b<0)	BIN1=0,			BIN2=1;
			else        BIN1=1,			BIN2=0;
		}
		else BIN1=1,			BIN2=1;
		PWMB=myabs(b);
}
void Motor_C(int c)
{
	if(c!=0)
	{
		if(c<0)	CIN1=1,			CIN2=0; 
		else         CIN1=0,			CIN2=1;
	}
	else CIN1=1,			CIN2=1;
	PWMC=myabs(c);	
}
void Motor_D(int d)
{
		if(d!=0)
		{
		  if(d<0)		DIN1=1,			DIN2=0;
			else        	DIN1=0,			DIN2=1;
		}
		else DIN1=1,			DIN2=1;
		PWMD=myabs(d)+5;

}
/**************************************************************************
函数功能：绝对值函数
入口参数：int
返回  值：unsigned int
**************************************************************************/
int myabs(int a)
{ 		   
	int temp;
	if(a<0)  temp=-a;  
	else temp=a;
	return temp;
}



























