/*
 * Systick.h
 *
 *  Created on: Oct 5, 2024
 *      Author: bhimashankar
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
volatile extern uint32_t jiffies;
void SysTick_Handler(void);
void SysTick_Delay(uint32_t ms);

#endif /* SYSTICK_H_ */
