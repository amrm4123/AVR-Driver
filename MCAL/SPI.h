/*
 * SPI.h
 *
 * Created: 11/27/2020 4:45:21 PM
 *  Author: amrm4
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "MemMap.h"
#include "Utils.h"
#include "stdTypes.h"




void SPI_InitMaster(void);
void SPI_InitSlave(void);
u8 SPI_SendReceive(u8 data);
void SPI_Interrupt_Enable(void);
void SPI_Interrupt_Disable(void);

#endif /* SPI_H_ */