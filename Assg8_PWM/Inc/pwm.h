/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Oct 1, 2024
*/

#ifndef PWM_H_
#define PWM_H_

#include "stm32f4xx.h"
extern int16_t ccr,i,SwitchExtiFlag;
#define TCLK		16000000
//#define PR			16
#define ARR_Val		100

#define GPIO_SWITCH				GPIOA
#define SWITCH_PIN				0
#define SWITCH_GPIO_CLKEN		0

#define SWITCH_EXTI				0


void PWM_Init(void);
void EXTI0_IRQHandler(void);
void SwitchInit(void);
#endif /* PWM_H_ */
