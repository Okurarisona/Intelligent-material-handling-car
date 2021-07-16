#ifndef __SERVO_H
#define __SERVO_H
#include "sys.h"

#define PWM1   TIM3->CCR1 	//PB4
#define PWM2   TIM3->CCR2	//PB5
#define PWMG   TIM3->CCR3	//PB0
#define PWMH   TIM3->CCR4 	//PB1 

#define PWM3   TIM4->CCR1 	//PB6
#define PWM4   TIM4->CCR2	//PB7
#define PWM5   TIM4->CCR3	//PB8
#define PWM6   TIM4->CCR4 	//PB9 

#define PWM8   TIM5->CCR2	//PA1
#define PWM9   TIM5->CCR3	//PA2
#define PWM10   TIM5->CCR4 	//PA3 

#define PWM11   TIM1->CCR1 	//PA8
#define PWM7  TIM1->CCR4	//PA11 

void TIM1_PWM_Init(u32 arr,u32 psc);
void TIM3_PWM_Init(u32 arr,u32 psc);
void TIM4_PWM_Init(u32 arr,u32 psc);
void TIM5_PWM_Init(u32 arr,u32 psc);













#endif



















