/*
 * TimerServices.h
 *
 * Created: 10/23/2020 1:02:11 PM
 *  Author: amrm4
 */ 


#ifndef TIMERSERVICES_H_
#define TIMERSERVICES_H_

#include "Timer.h"
#include "DIO_INTRFACE.h"
void PWM_Init(void);
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_Duty(u16 duty);

void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void));

void PWM_Measure(u32* Pfreq,u8* Pduty);
void PWM_Measure2(u32* Pfreq,u8* Pduty);
static void Func_ICU(void);
#endif /* TIMERSERVICES_H_ */