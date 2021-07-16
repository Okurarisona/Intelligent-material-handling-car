#include "sys.h"
#include "servo.h"

//TIM1 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM1_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB2ENR|=1<<0;       //ʹ��TIM1ʱ��   
	RCC->AHB1ENR|=1<<0;        //PORTAʱ��ʹ�� 
	
	GPIO_Set(GPIOA,PIN8|PIN11,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//���ù���,�������
	GPIO_AF_Set(GPIOA,8,1);	//PA8,AF1
	GPIO_AF_Set(GPIOA,11,1);	//PA11,AF1 
	
	TIM1->ARR=arr;             //�趨�������Զ���װֵ 
	TIM1->PSC=psc;             //Ԥ��Ƶ������Ƶ
	TIM1->CCMR1|=6<<4;         //CH1 PWM1ģʽ	
	TIM1->CCMR2|=6<<12;        //CH4 PWM1ģʽ	
	
	TIM1->CCMR1|=1<<3;         //CH1Ԥװ��ʹ��		  
	TIM1->CCMR2|=1<<11;        //CH4Ԥװ��ʹ��	  
	
	TIM1->CCER|=1<<0;         //CH1���ʹ��	
	TIM1->CCER|=1<<12;        //CH4���ʹ��
	TIM1->BDTR|= 1<<15;       //TIM����Ҫ��仰�������PWM
	TIM1->CR1|=1<<7;         //ARPEʹ�� 
	TIM1->CR1|=1<<0;          //ʹ�ܶ�ʱ�� 		
}
//TIM3 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM3_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB1ENR|=1<<1;       //ʹ��TIM3ʱ��   
	RCC->AHB1ENR|=1<<1;        //PORTBʱ��ʹ�� 
	
	GPIO_Set(GPIOB,PIN0|PIN1|PIN4|PIN5,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//���ù���,�������
	GPIO_AF_Set(GPIOB,0,2);	//PB0,AF2 
	GPIO_AF_Set(GPIOB,1,2);	//PB1,AF2 
	GPIO_AF_Set(GPIOB,4,2);	//PB4,AF2 
	GPIO_AF_Set(GPIOB,5,2);	//PB5,AF2 
	
	TIM3->ARR=arr;             //�趨�������Զ���װֵ 
	TIM3->PSC=psc;             //Ԥ��Ƶ������Ƶ
	TIM3->CCMR1|=6<<4;         //CH1 PWM1ģʽ	
	TIM3->CCMR1|=6<<12;        //CH2 PWM1ģʽ	
	TIM3->CCMR2|=6<<4;         //CH3 PWM1ģʽ	
	TIM3->CCMR2|=6<<12;        //CH4 PWM1ģʽ	
	
	TIM3->CCMR1|=1<<3;         //CH1Ԥװ��ʹ��	  
	TIM3->CCMR1|=1<<11;        //CH2Ԥװ��ʹ��	 
	TIM3->CCMR2|=1<<3;         //CH3Ԥװ��ʹ��	  
	TIM3->CCMR2|=1<<11;        //CH4Ԥװ��ʹ��	  
	
	TIM3->CCER|=1<<0;         //CH1���ʹ��	
	TIM3->CCER|=1<<4;         //CH2���ʹ��	   
	TIM3->CCER|=1<<8;         //CH3���ʹ��	 
	TIM3->CCER|=1<<12;        //CH4���ʹ��
	TIM3->CR1|=1<<7;         //ARPEʹ�� 
	TIM3->CR1|=1<<0;          //ʹ�ܶ�ʱ�� 		
}

//TIM4 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM4_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB1ENR|=1<<2;       //ʹ��TIM4ʱ��   
	RCC->AHB1ENR|=1<<1;        //PORTBʱ��ʹ�� 
	
	GPIO_Set(GPIOB,PIN6|PIN7|PIN8|PIN9,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//���ù���,�������
	GPIO_AF_Set(GPIOB,6,2);	//PB0,AF2 
	GPIO_AF_Set(GPIOB,7,2);	//PB1,AF2 
	GPIO_AF_Set(GPIOB,8,2);	//PB4,AF2 
	GPIO_AF_Set(GPIOB,9,2);	//PB5,AF2 
	
	TIM4->ARR=arr;             //�趨�������Զ���װֵ 
	TIM4->PSC=psc;             //Ԥ��Ƶ������Ƶ
	TIM4->CCMR1|=6<<4;         //CH1 PWM1ģʽ	
	TIM4->CCMR1|=6<<12;        //CH2 PWM1ģʽ	
	TIM4->CCMR2|=6<<4;         //CH3 PWM1ģʽ	
	TIM4->CCMR2|=6<<12;        //CH4 PWM1ģʽ	
	
	TIM4->CCMR1|=1<<3;         //CH1Ԥװ��ʹ��	  
	TIM4->CCMR1|=1<<11;        //CH2Ԥװ��ʹ��	 
	TIM4->CCMR2|=1<<3;         //CH3Ԥװ��ʹ��	  
	TIM4->CCMR2|=1<<11;        //CH4Ԥװ��ʹ��	  
	
	TIM4->CCER|=1<<0;         //CH1���ʹ��	
	TIM4->CCER|=1<<4;         //CH2���ʹ��	   
	TIM4->CCER|=1<<8;         //CH3���ʹ��	 
	TIM4->CCER|=1<<12;        //CH4���ʹ��
	TIM4->CR1|=1<<7;         //ARPEʹ�� 
	TIM4->CR1|=1<<0;          //ʹ�ܶ�ʱ�� 		
}
//TIM5 PWM���ֳ�ʼ�� 
//PWM�����ʼ��
//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM5_PWM_Init(u32 arr,u32 psc)
{
	
	RCC->APB1ENR|=1<<3;       //ʹ��TIM5ʱ��   
	RCC->AHB1ENR|=1<<0;        //PORTAʱ��ʹ�� 
	
	GPIO_Set(GPIOA,PIN1|PIN2|PIN3,GPIO_MODE_AF,GPIO_OTYPE_PP,GPIO_SPEED_100M,GPIO_PUPD_PU);//���ù���,�������
	GPIO_AF_Set(GPIOA,1,2);	//PB1,AF2 
	GPIO_AF_Set(GPIOA,2,2);	//PB4,AF2 
	GPIO_AF_Set(GPIOA,3,2);	//PB5,AF2 
	
	TIM5->ARR=arr;             //�趨�������Զ���װֵ 
	TIM5->PSC=psc;             //Ԥ��Ƶ������Ƶ
	TIM5->CCMR1|=6<<4;         //CH1 PWM1ģʽ	
	TIM5->CCMR1|=6<<12;        //CH2 PWM1ģʽ	
	TIM5->CCMR2|=6<<4;         //CH3 PWM1ģʽ	
	TIM5->CCMR2|=6<<12;        //CH4 PWM1ģʽ	
	
	TIM5->CCMR1|=1<<3;         //CH1Ԥװ��ʹ��	  
	TIM5->CCMR1|=1<<11;        //CH2Ԥװ��ʹ��	 
	TIM5->CCMR2|=1<<3;         //CH3Ԥװ��ʹ��	  
	TIM5->CCMR2|=1<<11;        //CH4Ԥװ��ʹ��	  
	
	TIM5->CCER|=1<<0;         //CH1���ʹ��	
	TIM5->CCER|=1<<4;         //CH2���ʹ��	   
	TIM5->CCER|=1<<8;         //CH3���ʹ��	 
	TIM5->CCER|=1<<12;        //CH4���ʹ��
	TIM5->CR1|=1<<7;         //ARPEʹ�� 
	TIM5->CR1|=1<<0;          //ʹ�ܶ�ʱ�� 		
}
