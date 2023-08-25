

#include "DC_MOTOR.h"


void DC_Motor(u16 duty,u16 freq)
{
	u32 t_on=0;u16 time=0;
	time=1000000/freq;
	ICR1=time;
	t_on=(time*duty)/100;
	OCR1A=t_on;
	OCR1B=time-t_on;
}