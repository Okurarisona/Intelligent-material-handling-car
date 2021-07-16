#include "sys.h"
#include "servo.h"

//TIM1 PWM部分初始化 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM1_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB2ENR|=1<<0;       //使能TIM1时钟   
	RCC->AHB1ENR|=1<<0;        //PORTA时钟使能 
	
	GPIO_Set(GPIOA,PIN8|PIN11,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//复用功能,上拉输出
	GPIO_AF_Set(GPIOA,8,1);	//PA8,AF1
	GPIO_AF_Set(GPIOA,11,1);	//PA11,AF1 
	
	TIM1->ARR=arr;             //设定计数器自动重装值 
	TIM1->PSC=psc;             //预分频器不分频
	TIM1->CCMR1|=6<<4;         //CH1 PWM1模式	
	TIM1->CCMR2|=6<<12;        //CH4 PWM1模式	
	
	TIM1->CCMR1|=1<<3;         //CH1预装载使能		  
	TIM1->CCMR2|=1<<11;        //CH4预装载使能	  
	
	TIM1->CCER|=1<<0;         //CH1输出使能	
	TIM1->CCER|=1<<12;        //CH4输出使能
	TIM1->BDTR|= 1<<15;       //TIM必须要这句话才能输出PWM
	TIM1->CR1|=1<<7;         //ARPE使能 
	TIM1->CR1|=1<<0;          //使能定时器 		
}
//TIM3 PWM部分初始化 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM3_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB1ENR|=1<<1;       //使能TIM3时钟   
	RCC->AHB1ENR|=1<<1;        //PORTB时钟使能 
	
	GPIO_Set(GPIOB,PIN0|PIN1|PIN4|PIN5,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//复用功能,上拉输出
	GPIO_AF_Set(GPIOB,0,2);	//PB0,AF2 
	GPIO_AF_Set(GPIOB,1,2);	//PB1,AF2 
	GPIO_AF_Set(GPIOB,4,2);	//PB4,AF2 
	GPIO_AF_Set(GPIOB,5,2);	//PB5,AF2 
	
	TIM3->ARR=arr;             //设定计数器自动重装值 
	TIM3->PSC=psc;             //预分频器不分频
	TIM3->CCMR1|=6<<4;         //CH1 PWM1模式	
	TIM3->CCMR1|=6<<12;        //CH2 PWM1模式	
	TIM3->CCMR2|=6<<4;         //CH3 PWM1模式	
	TIM3->CCMR2|=6<<12;        //CH4 PWM1模式	
	
	TIM3->CCMR1|=1<<3;         //CH1预装载使能	  
	TIM3->CCMR1|=1<<11;        //CH2预装载使能	 
	TIM3->CCMR2|=1<<3;         //CH3预装载使能	  
	TIM3->CCMR2|=1<<11;        //CH4预装载使能	  
	
	TIM3->CCER|=1<<0;         //CH1输出使能	
	TIM3->CCER|=1<<4;         //CH2输出使能	   
	TIM3->CCER|=1<<8;         //CH3输出使能	 
	TIM3->CCER|=1<<12;        //CH4输出使能
	TIM3->CR1|=1<<7;         //ARPE使能 
	TIM3->CR1|=1<<0;          //使能定时器 		
}

//TIM4 PWM部分初始化 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM4_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB1ENR|=1<<2;       //使能TIM4时钟   
	RCC->AHB1ENR|=1<<1;        //PORTB时钟使能 
	
	GPIO_Set(GPIOB,PIN6|PIN7|PIN8|PIN9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//复用功能,上拉输出
	GPIO_AF_Set(GPIOB,6,2);	//PB0,AF2 
	GPIO_AF_Set(GPIOB,7,2);	//PB1,AF2 
	GPIO_AF_Set(GPIOB,8,2);	//PB4,AF2 
	GPIO_AF_Set(GPIOB,9,2);	//PB5,AF2 
	
	TIM4->ARR=arr;             //设定计数器自动重装值 
	TIM4->PSC=psc;             //预分频器不分频
	TIM4->CCMR1|=6<<4;         //CH1 PWM1模式	
	TIM4->CCMR1|=6<<12;        //CH2 PWM1模式	
	TIM4->CCMR2|=6<<4;         //CH3 PWM1模式	
	TIM4->CCMR2|=6<<12;        //CH4 PWM1模式	
	
	TIM4->CCMR1|=1<<3;         //CH1预装载使能	  
	TIM4->CCMR1|=1<<11;        //CH2预装载使能	 
	TIM4->CCMR2|=1<<3;         //CH3预装载使能	  
	TIM4->CCMR2|=1<<11;        //CH4预装载使能	  
	
	TIM4->CCER|=1<<0;         //CH1输出使能	
	TIM4->CCER|=1<<4;         //CH2输出使能	   
	TIM4->CCER|=1<<8;         //CH3输出使能	 
	TIM4->CCER|=1<<12;        //CH4输出使能
	TIM4->CR1|=1<<7;         //ARPE使能 
	TIM4->CR1|=1<<0;          //使能定时器 		
}
//TIM5 PWM部分初始化 
//PWM输出初始化
//arr：自动重装值
//psc：时钟预分频数
void TIM5_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB1ENR|=1<<3;       //使能TIM5时钟   
	RCC->AHB1ENR|=1<<0;        //PORTA时钟使能 
	
	GPIO_Set(GPIOA,PIN1|PIN2|PIN3,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//复用功能,上拉输出
	GPIO_AF_Set(GPIOA,1,2);	//PB1,AF2 
	GPIO_AF_Set(GPIOA,2,2);	//PB4,AF2 
	GPIO_AF_Set(GPIOA,3,2);	//PB5,AF2 
	
	TIM5->ARR=arr;             //设定计数器自动重装值 
	TIM5->PSC=psc;             //预分频器不分频
	TIM5->CCMR1|=6<<4;         //CH1 PWM1模式	
	TIM5->CCMR1|=6<<12;        //CH2 PWM1模式	
	TIM5->CCMR2|=6<<4;         //CH3 PWM1模式	
	TIM5->CCMR2|=6<<12;        //CH4 PWM1模式	
	
	TIM5->CCMR1|=1<<3;         //CH1预装载使能	  
	TIM5->CCMR1|=1<<11;        //CH2预装载使能	 
	TIM5->CCMR2|=1<<3;         //CH3预装载使能	  
	TIM5->CCMR2|=1<<11;        //CH4预装载使能	  
	
	TIM5->CCER|=1<<0;         //CH1输出使能	
	TIM5->CCER|=1<<4;         //CH2输出使能	   
	TIM5->CCER|=1<<8;         //CH3输出使能	 
	TIM5->CCER|=1<<12;        //CH4输出使能
	TIM5->CR1|=1<<7;         //ARPE使能 
	TIM5->CR1|=1<<0;          //使能定时器 		
}
