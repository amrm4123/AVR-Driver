/*
 * EXInterrupt.h
 *
 * Created: 10/9/2020 5:33:21 PM
 *  Author: amr
 */ 


#ifndef EXINTERRUPT_H_
#define EXINTERRUPT_H_

#include "stdTypes.h"
#include "MemMap.h"
#include "Utils.h"

typedef enum{

LOW_LEVEL=0,
ANY_LOGIC_CHANGE,
FALLING_EDGE,
RISING_EDGE,
}TriggerEdge_type;

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}ExInterruptSource_type;



void EXI_Enable(ExInterruptSource_type source);
void EXI_Disable(ExInterruptSource_type source);
void EXI_TriggerEdge(ExInterruptSource_type source,TriggerEdge_type edge);
void EXI_SetCallBack(void(*localpf)(void),ExInterruptSource_type source);



#endif /* EXINTERRUPT_H_ */