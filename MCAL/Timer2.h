/*
 * Timer2.h
 *
 * Created: 6/13/2021 7:06:37 PM
 *  Author: amrm4
 */ 


#ifndef TIMER2_H_
#define TIMER2_H_

#include "MemMap.h"
#include "stdTypes.h"
#include "Utils.h"

typedef enum{
	TIMER2_STOP=0,
	TIMER2_SCALER_1,
	TIMER2_SCALER_8,
	TIMER2_SCALER_64,
	TIMER2_SCALER_256,
	TIMER2_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer2Scaler_type;

typedef enum
{
	TIMER2_NORMAL_MODE=0,
	TIMER2_PHASECORRECT_MODE,
	TIMER2_CTC_MODE,
	TIMER2_FASTPWM_MODE

}Timer2Mode_type;
typedef enum
{
	OCO_DISCONNECTED=0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING

}OC2Mode_type;



void Timer2_Init( Timer2Mode_type mode,Timer2Scaler_type scaler,OC2Mode_type oc_mode);
void Timer2_OV_InterruptEnable(void);
void Timer2_OV_InterruptDisable(void);
void Timer2_OC_InterruptEnable(void);
void Timer2_OC_InterruptDisable(void);
void Timer2_OC_SetCallBack(void(*local_pf)(void));
void Timer2_OVF_SetCallBack(void(*local_pf)(void));



#endif /* TIMER2_H_ */

