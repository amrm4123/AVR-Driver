/*
 * EEPROM.h
 *
 * Created: 1/9/2021 1:07:46 PM
 *  Author: amrm4
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "MemMap.h"
#include "stdTypes.h"


void EEPROM_write(u16 *Address, u8 Data);

u8 EEPROM_read(u16 *Address);


#endif /* EEPROM_H_ */