/*
Author: Nilesh Ghule <nilesh@sunbeaminfo.com>
Course: PG-DESD @ Sunbeam Infotech
Date: Sep 23, 2024
*/

#ifndef UART_H_       //header guard
#define UART_H_

#include "stm32f4xx.h"

// UART2
// 	UART2 -- TX=PA.2 and RX=PA.3
//	APB1ENR -- UART clock

#define UART			USART2

#define GPIO_UART		GPIOA
#define UART_TX_PIN		2
#define UART_RX_PIN		3

#define GPIO_UART_CLKEN		0
#define UART_CLKEN			17

//#define FPCLK				16000000
#define UBRR_9600			0x683
#define UBRR_38400			0x1A1
#define UBRR_115200			0x8B

void UartInit(uint32_t baud);
void UartPutch(uint8_t ch);
void UartPuts(char str[]);
uint8_t UartGetch(void);
void UartGets(char str[]);
void UartPutint(int);

///////////
#define GPIO_LED		GPIOD
#define LED_GREEN_PIN	12
#define LED_ORANGE_PIN	13
#define LED_RED_PIN		14
#define LED_BLUE_PIN	15

#define GPIO_LED_CLKEN	3

void LedInit();
void LedOn(uint32_t pin);
void LedOff(uint32_t pin);
void LedBlink(uint32_t pin, uint32_t delayMs);
void LedToggle(uint32_t pin);
/////////////////////////
#endif /* UART_H_ */




