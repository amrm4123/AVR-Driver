///*
 //* I2C.h
 //*
 //* Created: 1/4/2021 10:55:02 AM
 //*  Author: amrm4
 //*/ 
//
//
#ifndef I2C_H_
#define I2C_H_

#include "MemMap.h"
#include "stdTypes.h"
#include "Utils.h"
#define F_CPU 8000000UL							/* Define CPU clock Frequency e.g. here its 8MHz */
/* Include AVR std. library file */
#include <util/delay.h>							/* Include inbuilt defined Delay header file */
#include <math.h>								/* Include math function */
#define SCL_CLK 100000L							/* Define SCL clock frequency */
#define BITRATE(TWSR)	((F_CPU/SCL_CLK)-16)/(2*pow(4,(TWSR&((1<<TWPS0)|(1<<TWPS1))))) /* Define bit rate *///
//
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // ( slave address + Write have been sent ) + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // ( slave address + Read have been sent ) + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Data byte has been transmitted and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK
#define TW_MR_DATA_NACK  0x58 // MAster received data but don't send ACK

typedef enum
{
	I2C_RX,
	I2C_TX
} I2c_Status_t;




void _I2C_Init();								/* I2C initialize function */
u8 _I2C_Start(u8 write_address);			/* I2C start function */
u8 _I2C_Repeated_Start(u8 read_address);	/* I2C repeated start function */
void _I2C_Stop();								/* I2C stop function */
void _I2C_Start_Wait(u8 write_address);		/* I2C start wait function */
u8 _I2C_Write(u8 data);					/* I2C write function */
char _I2C_Read_Ack();							/* I2C read ack function */
char _I2C_Read_Nack();							/* I2C read nack function */


//#endif /* I2C_H_ */