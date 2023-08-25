/*
 * Ultrasonic.h
 *
 * Created: 11/5/2020 5:51:39 PM
 *  Author: amrm4
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#define  F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_INTRFACE.h"
#include "Timer.h"

#define ultrasonic_pin PIND6

/*
typedef enum
{
	

}ULTRASONIC_type;
*/

void ULTRASONIC_Init(void);
u8 ULTRASONIC_GetDistance();  //ULTRASONIC_type ultrasonic_pin
void ULTRASONIC_Start();      //ULTRASONIC_type ultrasonic_pin
static void Func_OVF(void);
static void Func_ICU(void);

#endif /* ULTRASONIC_H_ */