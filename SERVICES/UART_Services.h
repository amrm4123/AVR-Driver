/*
 * UART_Services.h
 *
 * Created: 11/18/2020 6:48:37 PM
 *  Author: Mohamed
 */ 

// send : 
#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"

void UART_SendString(u8 *x) ; 
void UART_ReceiveString(u8 *strptr) ; 
void  UART_ReceiveString_WithLength(u8 *strptr , u16 length) ; 
/************** Functions associated with TTL ( Prolific and Bluetooth module) *************/
void UART_SendLong_TTL(u32 data) ;
u32 UART_ReceiveLong_TTL(void) ;
u8 UART_Receive_NoBlock_TTL(u8 * ch) ;
void UART_SendString_WithLength_CheckSum_TTL(u8 *str) ;
/*******************************************************************************************/

/************ Functions associated with communicating between two mcus - on a binary level**/
void UART_SendLong(u32 data) ;
u32 UART_ReceiveLong(void) ;
void UART_SendString_CS(u8 *str) ; 
u8 UART_ReceiveString_CS(u8 *str) ; 
void UART_SendString_Using_Interrupt(u8 *str) ; 
void UART_ReceiveString_Interrupt(u8* str) ; 
/*******************************************************************************************/
#endif /* UART_SERVICES_H_ */