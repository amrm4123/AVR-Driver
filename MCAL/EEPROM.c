/*
 * EEPROM.c
 *
 * Created: 1/9/2021 1:07:31 PM
 *  Author: amrm4
 */ 

#include "EEPROM.h"



void EEPROM_write(u16 *Address, u8 Data)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = *Address;
	EEDR = Data;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}

u8 EEPROM_read(u16 *Address)
{
/* Wait for completion of previous write */
while(EECR & (1<<EEWE))
;
/* Set up address register */
EEAR = *Address;
/* Start eeprom read by writing EERE */
EECR |= (1<<EERE);
/* Return data from data register */
return EEDR;
}