



#ifndef NEMA_23_H_
#define NEMA_23_H_

#include "DIO_INTRFACE.h"
#include "stdTypes.h"
#include "MemMap.h"


#define dir_pin PINA0     //set as an output
#define step_pin PINA1    //set as an output


void spin_cw(void);

void spin_ccw(void);

void step_angle(u16 n , u16 angle);

void step_angle_2(u16 angle);    //step = 57.6


#endif /* NEMA_23_H_ */