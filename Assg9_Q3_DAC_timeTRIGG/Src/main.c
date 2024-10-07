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
#include "DAC.h"
#include "timer.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
		int val;
		SystemInit();
		DAC_Init();
		while(1) {
			start:
			for(val = 0; val < 4096; val += 16,flag=0) {
				DAC_SetValue(val);

				Timer_Init(100);
				while(!flag);
			}
			while(val==4096){
				for(; val > 0; val -= 16,flag=0) {
					DAC_SetValue(val);

					Timer_Init(100);
					while(!flag);
					if(val==0)
						goto start;
				}

			}

		}
		return 0;


}

