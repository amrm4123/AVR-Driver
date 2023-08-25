

#ifndef UART_H_
#define UART_H_

#define  F_CPU 8000000UL
#include "stdTypes.h"
#include "Utils.h"
#include "MemMap.h"


#define END_OF_STRING_CHAR			'#'
#define MAX_LIMIT_OF_CHARS			100


void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Receive(void);

void UART_Send_NoBlock(u8 data) ;
u8 UART_Receive_NoBlock(u8 *data) ;

void UART_RX_InterruptEnable(void) ;
void UART_RX_InterruptDisable(void) ;

void UART_TX_InterruptEnable(void) ;
void UART_TX_InterruptDisable(void) ;

void UART_RXI_SetCallBack(void(*ptr)(void)) ;
void UART_TXI_SetCallBack(void(*ptr)(void)) ;


#endif /* UART_H_ */