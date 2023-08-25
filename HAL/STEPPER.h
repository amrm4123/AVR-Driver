




#ifndef STEPPER_H_
#define STEPPER_H_

#define F_CPU 8000000UL
#define STEPPER_UNI_DELAY 5
#include "util/delay.h"


#define  BI_POLER      0
#define  UNI_POLER     1

/**********SELECT MOTOR TYPE************/
#define MOTOR_TYPE   UNI_POLER   

/**********PINS CONGIGRATION***********/

#define COIL1A			PINA0
#define COIL1B			PINA1
#define COIL2A			PINA2 
#define COIL2B			PINA3

#define COIL3A			PINB0
#define COIL3B			PINB1
#define COIL4A			PINB2
#define COIL4B			PINB3



void STEPPER_CW(void) ;
void STEPPER_CCW(void) ;

void STEPPER_CW_HalfStep(void) ; 
void STEPPER_CW_Withangle(u16 angle);
void STEPPER_CCW_Withangle(u16 angle);

#endif /* STEPPER_H_ */