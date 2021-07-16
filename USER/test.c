#include "sys.h"
#include "delay.h" 
#include "usart.h"
#include "timer.h"
#include "gray.h"
#include "motor.h"

u8  Vi=40;
u8 aaa=1;

int main(void)
{  
	Stm32_Clock_Init(336,8,2,7); 
	delay_init(168);		 
	uart_init(84,9600);		
	uart3_init(42,9600);	 	
	TIM2_Int_Init(1000-1,840-1);
	TIM8_PWM_Init(100-1,84-1);
	TIM3_PWM_Init(2000-1,840-1);
	TIM4_PWM_Init(2000-1,840-1);
	gray_int();
	Motor_int();
	OLED_Init();
	
	OLED_ShowString(50,0,"L  C");
	
	PWM1=120;
	
	guiwei();
	Track_Flag=0;
//	Move(4,4);
//	Move(0,0);
	Begin();
//	Set_Pwm(-45,40,40,-45);
   	while(1)
	{
//		RGB();
	}
}
















