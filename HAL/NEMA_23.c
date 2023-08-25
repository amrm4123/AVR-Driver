
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "NEMA_23.h"




void spin_cw(void)
{
	DIO_WritePin(dir_pin,HIGH);
}

void spin_ccw(void)
{
	DIO_WritePin(dir_pin,LOW);
}

void step_angle(u16 n,u16 angle)
{
	u16 i=0;
	u16 step =0;
	step=(360*angle)/200;
	
	for(i=0 ; i<(n*step) ; i++)
	{
		DIO_WritePin(step_pin,HIGH);
		_delay_ms(500);
		DIO_WritePin(step_pin,LOW);
		_delay_ms(500);
	}
	
	
}


void step_angle_2(u16 angle)
{
	u16 i=0;
	u16 step =0;
	step=(360*angle)/200;
			
	for(i=0;i<step;i++)
		{
			DIO_WritePin(step_pin,HIGH);
			_delay_ms(500);
			DIO_WritePin(step_pin,LOW);
			_delay_ms(500);
		}
	
}