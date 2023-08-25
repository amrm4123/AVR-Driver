

#define  F_CPU 8000000UL
#include <util/delay.h>
#include "SEGMENT.h"


static u8 SegNumbers[]={ 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, };
static u8 decNumbers[]={0b000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000,0b1001,};
	
#if (SEGMENT_TYPE==ONE_SEGMENT)

void segmant_desplay(u8 n)
{
	ONE_SEGMENT_PORT =~ SegNumbers[n];
}

#elif(SEGMENT_TYPE==TWO_SEGMENT)

void segmant_desplay(u8 n)
{
	ONE_SEGMENT_PORT=~( SegNumbers[n % 10]);
	TWO_SEGMENT_PORT=~ (SegNumbers[ n / 10]);
}

#elif (SEGMENT_TYPE==MULTI_SEGMENT)

void segmant_desplay(u8 n)
{
	SET_BIT(ENABLE_PORT,EN2);
	CLEAR_BIT(ENABLE_PORT,EN1);
	MULTI_SEGMENT_PORT=SegNumbers[n/10];
	_delay_ms(1);
	SET_BIT(ENABLE_PORT,EN1);
	CLEAR_BIT(ENABLE_PORT,EN2);
	MULTI_SEGMENT_PORT=SegNumbers[n%10];
	_delay_ms(1);
}

#elif(SEGMENT_TYPE == DECODER_MULTI_SEGMENT)

void segmant_desplay(u8 n)
{
	SET_BIT(ENABLE_PORT,EN2);
	CLEAR_BIT(ENABLE_PORT,EN1);
	MULTI_SEGMENT_PORT=decNumbers[n/10];
	_delay_ms(1);
	SET_BIT(ENABLE_PORT,EN1);
	CLEAR_BIT(ENABLE_PORT,EN2);
	MULTI_SEGMENT_PORT=decNumbers[n%10];
	_delay_ms(1);
}

#endif