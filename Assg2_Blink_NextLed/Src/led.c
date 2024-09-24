/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 19, 2024
*/

#include "led.h"

void LedInit() {
	// enable GPIOD clock -- RCC AHB1ENR[GPIO_CLKEN] = 1
	RCC->AHB1ENR |= BV(GPIO_LED_CLKEN);
	// config GPIOD.pin as output -- MODER[2*pin+1:2*pin] - 01
	GPIO_LED->MODER &= ~(BV(12*2+1)|BV(13*2+1)|BV(14*2+1)|BV(15*2+1));
	GPIO_LED->MODER |= (BV(13*2)|BV(14*2)|BV(15*2)|BV(12*2));
	// config GPIOD.pin as pushpull -- OTYPER[pin] - 0
	GPIO_LED->OTYPER &= ~(BV(12)|BV(13)|BV(14)|BV(15));
	// config GPIOD.pin as low-speed -- OSPEEDR[2*pin+1:2*pin] - 00
	GPIO_LED->OSPEEDR &= ~(BV(12*2+1) | BV(12*2)|BV(13*2+1) | BV(13*2)|BV(14*2+1) | BV(14*2)|BV(15*2+1) | BV(15*2));
	// config GPIOD.pin with no pullup & pulldown resistor PUPDR[2*pin+1:2*pin] -- 00
	GPIO_LED->PUPDR &= ~(BV(12*2+1) | BV(12*2)|BV(13*2+1) | BV(13*2)|BV(14*2+1) | BV(14*2)|BV(15*2+1) | BV(15*2));
}

void LedOn(uint32_t pin) {
	// GPIOD.pin -- ODR[pin] = 1
	GPIO_LED->ODR |= BV(pin);
}

void LedOff(uint32_t pin) {
	// GPIOD.pin -- ODR[pin] = 0
	GPIO_LED->ODR &= ~BV(pin);
}

void LedBlink(uint32_t pin, uint32_t delayMs) {
	LedOn(pin);
	DelayMs(delayMs);
	LedOff(pin);
}

void LedToggle(uint32_t pin) {
	// GPIOD.pin -- ODR[pin] ^= 1
	GPIO_LED->ODR ^= BV(pin);
}



