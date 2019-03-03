#ifndef __TIM_H
#define __TIM_H
#include "stm32f10x.h"

void Tim3_Config(void);
void Tim4_Config(void);
void Tim2_Config(void);

void Delay_Ms(u32 time,u8 led_num);
void Delay_Us(u32 time);
void Delay_125Ns(u32 time);
void Delay_300Ns(u32 time);
#endif
