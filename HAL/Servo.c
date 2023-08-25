
#include "Servo.h"



void SERVO_Init(void)
{
	
	ICR1=19999;
	OCR1A=999;
	
}
void SERVO_SetAngle(u8 angle)
{
	
	OCR1A=((u32)angle*1000)/180+999;
	
}