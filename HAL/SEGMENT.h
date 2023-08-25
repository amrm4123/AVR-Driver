




#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "DIO_INTRFACE.h"

#define  ONE_SEGMENT             0
#define  TWO_SEGMENT             1
#define  MULTI_SEGMENT           2
#define  DECODER_MULTI_SEGMENT   3

/************SELECT SEGMENT TYPE***********/
#define SEGMENT_TYPE   MULTI_SEGMENT

/************SEGMENT CONFIGRATION***********/

#define  ONE_SEGMENT_PORT        PORTA
#define	 TWO_SEGMENT_PORT        PORTB
#define  MULTI_SEGMENT_PORT      PORTD
#define  ENABLE_PORT             PORTB
#define  EN1           0
#define  EN2           1


static u8 decNumbers[];
static u8 SegNumbers[];
void segmant_desplay(u8 n);




#endif /* SEGMENT_H_ */