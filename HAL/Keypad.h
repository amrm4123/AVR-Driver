




#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_INTRFACE.h"
#include "stdTypes.h"


#define FIRST_OUT		PINA0
#define FIRST_IN		PINB0

#define  DEFAULT_KEY		'.'


u8 KEYPAD_Entry(void) ;


#endif /* KEYPAD_H_ */