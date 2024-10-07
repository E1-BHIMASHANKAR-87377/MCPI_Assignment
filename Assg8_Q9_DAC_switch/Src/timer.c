/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 30, 2024
*/


#include "timer.h"
//#include "led.h"

void Timer_Init(uint32_t ms) {
	//* Enable Timer APB clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	//* Set Timer clock -- PCLK = TCLK = 16 MHz : * Set PR = 16000
	TIM6->PSC = (PR-1);
	//* Calculate number of clocks to count (CNT).
	uint32_t cnt = (TCLK / 1000) * ms / PR;
	//* Set CNT in ARR.
	TIM6->ARR = (cnt-1);
	//* Reset Timer Counter to 0.
	TIM6->CNT = 0;
	//* Enable Timer Interrupt in DIER.
	TIM6->DIER |= TIM_DIER_UIE;
	//Update event to Trigger (CR2 = 0b010).
	TIM6->CR2 |= BV(5);
	//* Enable Timer Interrupt in NVIC.
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	//* Start Timer in CR1.
	TIM6->CR1 |= TIM_CR1_CEN;
	/*Timer_Init()
1. Enable Timer peripheral.
2. Set Prescalar, ARR (for 20ms delay). Reset timer counter.
3. Enable Timer update interrupt in timer (DIER) and NVIC.
4. Update event to Trigger (CR2 = 0b010).
5. Start the timer in (CR1).*/
}
int flag  =0;
void TIM6_DAC_IRQHandler(void) {
	//* Check if UIF flag is set (in SR).
	if(TIM6->SR & TIM_SR_UIF) {
		//* Clear UIF in SR (Ack)
			flag=1;

		 TIM6->SR &= ~TIM_SR_UIF;
		// Perform interrupt handling -- Toggle LED
		//LedToggle(LED_BLUE_PIN);

	}
}
