#ifndef __MOTOR_H
#define __MOTOR_H
#include <sys.h>	 

#define PWMB 	TIM8->CCR1 //PC6
#define BIN2	PFout(15)
#define BIN1	PFout(14)
#define AIN1	PFout(7)
#define AIN2	PFout(6)
#define PWMA	TIM8->CCR2	//PC7

#define PWMD	TIM8->CCR3	//PC8
#define DIN2	PFout(13)
#define DIN1	PFout(12)
#define CIN1    PFout(5)
#define CIN2	PFout(4)
#define PWMC	TIM8->CCR4 //PC9  


void TIM8_PWM_Init(u32 arr,u32 psc);
int myabs(int a);
void Set_Pwm(int moto1,int moto2,int moto3,int moto4);
void Motor_int(void);
void Motor_A(int a);
void Motor_B(int b);
void Motor_C(int c);
void Motor_D(int d);


#endif

