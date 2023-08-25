

#include "Ultrasonic.h"


static volatile u16 t1,t2,flag=0,c=0;


void ULTRASONIC_Init(void)
{
	/*you can use timer in another mode except modes using ICR as top */
	
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_DISCONNECTED);
	Timer1_OVF_SetCallBack(Func_OVF);
	Timer1_ICU_SetCallBack(Func_OVF);
	
}

u8 ULTRASONIC_GetDistance()
{
	u8 distance;
	u16 time;
	//TCNT1=0
	c=0;
	flag=0;
	DIO_WritePin(ultrasonic_pin,HIGH);
	_delay_us(10);
	DIO_WritePin(ultrasonic_pin,LOW);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	while(flag<2);
	time=t2-t1+((u32)c*65535);
	distance=time/58;
	Timer1_ICU_InterruptDisable();
	return distance;

}

void ULTRASONIC_Start()
{
	
	if(flag==0)
	{
		DIO_WritePin(ultrasonic_pin,HIGH);
		_delay_us(10);
		DIO_WritePin(ultrasonic_pin,LOW);
		Timer1_InputCaptureEdge(RISING);
		Timer1_ICU_InterruptEnable();
		Timer1_OVF_InterruptEnable();
		
	}
	
}



static void Func_ICU(void)
{
	if (flag==0)
	{
		t1=ICR1;
		Timer1_InputCaptureEdge(FALLING);
		flag=1;
	}
	else if (flag==1)
	{
		t2=ICR1;
		flag=2;
		Timer1_InputCaptureEdge(RISING);
		Timer1_OVF_InterruptDisable();
		Timer1_ICU_InterruptDisable();
		
	}
	
	
}

static void Func_OVF(void)
{
	c++;
}














