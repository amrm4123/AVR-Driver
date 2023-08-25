/*
 * Timer2.c
 *
 * Created: 6/13/2021 7:06:16 PM
 *  Author: amrm4
 */ 

#include "Timer2.h"

static void(*Fptr_OC)(void)=0x00;
static void(*Fptr_OVF)(void)=0x00;



void Timer2_Init(Timer2Mode_type mode,Timer2Scaler_type scaler,OC2Mode_type oc_mode)
{
	switch(mode)
	{
		case TIMER2_NORMAL_MODE:
			CLEAR_BIT(TCCR2,WGM20);
			CLEAR_BIT(TCCR2,WGM21);
		break;
			
		case TIMER2_PHASECORRECT_MODE:
			SET_BIT(TCCR2,WGM20);
			CLEAR_BIT(TCCR2,WGM21);
		break;
		
		case TIMER2_CTC_MODE:
			CLEAR_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);
		break;
		case TIMER2_FASTPWM_MODE:
			SET_BIT(TCCR2,WGM20);
			SET_BIT(TCCR2,WGM21);
		break;
		 	
	}
	switch(scaler)
	{
		case TIMER0_STOP:
			CLEAR_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_SCALER_1:
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_SCALER_8:
			CLEAR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_SCALER_64:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		break;
		case TIMER0_SCALER_256:
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		break;
		case TIMER0_SCALER_1024:
			SET_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		break;
		case EXTERNALl_FALLING:
			CLEAR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		break;
		case EXTERNAL_RISING:
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		break;	
	}
	
	TCCR2&=0XF8; //0b11111000
	
	switch(oc_mode)
	{
		case OCO_DISCONNECTED:
			CLEAR_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR0,COM21);
		break;
		case OCO_TOGGLE:
			SET_BIT(TCCR2,COM20);
			CLEAR_BIT(TCCR2,COM21);
		break;
		case OCO_NON_INVERTING:
			CLEAR_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		break;
		case OCO_INVERTING:
			SET_BIT(TCCR2,COM20);
			SET_BIT(TCCR2,COM21);
		break;
	}
	
}
void Timer2_OV_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE0);
}
void Timer2_OV_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}
void Timer2_OC_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE0);
}
void Timer2_OC_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE0);
}
void Timer2_OC_SetCallBack(void(*local_pf)(void))
{
	Fptr_OC=local_pf;
}
void Timer2_OVF_SetCallBack(void(*local_pf)(void))
{
	Fptr_OVF=local_pf;
}
ISR(TIMER2_OVF_vect)
{

	Fptr_OVF();

}
ISR(TIMER2_OC_vect)
{
	
	Fptr_OC();
	
}

