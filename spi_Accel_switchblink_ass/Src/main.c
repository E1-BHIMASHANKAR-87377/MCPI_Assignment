/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "accel.h"
#include "uart.h"
#include "i2c_lcd.h"
#include "led.h"
//#include "i2c.c"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void) {
	char str[32];
	LIS_Data val;
	LedInit();
	Lcd_Init();
	I2C_Init();
	SystemInit();
	//UartInit(9600); // initialize uart
	//UartPuts("LIS3DSH Accel Demo!\r\n");
	LIS_Init(); //initialize accel
	while(1) {
		if(LIS_IsDataAvail()) // check if new data avail
		{
			val = LIS_GetData(); // get the new data
			// print value
			sprintf(str, "X=%4d,Y=%4d\r\n", val.x, val.y);
			Lcd_Puts(LCD_LINE1, str);
			sprintf(str, "z=%4d\r\n",val.z);
			Lcd_Puts(LCD_LINE2, str);

			if(val.x >= 3000)
				LedBlink(LED_RED_PIN, 500);
			else if(val.y <= -3000)
				LedBlink(LED_BLUE_PIN, 500);
			else if(val.x <= -3000)
				LedBlink(LED_GREEN_PIN, 500);
			else if(val.y >= 3000)
				LedBlink(LED_ORANGE_PIN, 500);



		}
		DelayMs(1000);
	}
	return 0;
}
