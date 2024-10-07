/*
 * Systick.c
 *
 *  Created on: Oct 5, 2024
 *      Author: bhimashankar
 */
#include "stm32f4xx.h"
#include "led.h"

uint32_t jiffies = 0;
void SysTick_Handler(void) {
	jiffies++;
	GPIOD->ODR ^= BV(LED_RED_PIN); // ---> Oscilloscope/Analyzer
}
void SysTick_Delay(uint32_t ms) {
	uint32_t until = jiffies + ms;
	while(jiffies < until)
		;
}
