/*
 * DAC.c
 *
 *  Created on: Oct 6, 2024
 *      Author: bhimashankar
 */
#include "DAC.h"

void DAC_Init(void) {
	/*DAC_Init()
	1. Enable GPIOA peripheral. (DAC1_OUT=PA4, DAC2_OUT=PA5)

	2. Set GPIO mode to Analog. (MODER = 0b11).
	3. Enable DAC peripheral (APB1).
	4. Enable DAC channel, Output buffer, Enable trigger, and select Trigger (TIM6=0b000) (CR).
	5. Set DAC register to initial value. (DHRxR)*/
	//1. Enable GPIOA peripheral. (DAC1_OUT=PA4)
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		//2. Set GPIO mode to Analog. (MODER = 0b11).
		GPIOA->MODER |= BV(4*2) | BV(4*2+1);
		//3. Enable DAC peripheral (APB1).
		RCC->APB1ENR |= RCC_APB1ENR_DACEN;
		//4. Enable DAC channel, Output buffer, Enable trigger, and select Trigger (Software=0b111) (CR).
		DAC1->CR = DAC_CR_EN1|DAC_CR_TEN1;
		DAC1 ->CR &=~(DAC_CR_TSEL1_0|DAC_CR_TSEL1_1|DAC_CR_TSEL1_2);
}
void DAC_SetValue(uint16_t val) {
	//1. Set value in DAC register. (DHRxR)

	DAC1->DHR12R1 = val;
	//2. Trigger conversion (in SWTRIGR).
	//DAC1->SWTRIGR |= DAC_;
}


