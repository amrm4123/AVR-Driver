/*
 * UART_Services.c
 *
 * Created: 11/18/2020 6:47:49 PM
 *  Author: Mohamed
 */ 

// send : 
#include "UART_Services.h"
#define DEBUG 0

static void uart_sendstring_isr(void) ; // used in setcall back tx function 
static void uart_receivestring_isr(void) ;  // used in setcall back rx function 
static u8 *pSendData = (void *) 0x00 ;
volatile static u8 *pRecData = (void *) 0x00 ;


void UART_SendString(u8 *x)
{
	while(*x != '\0')
	{
		UART_Send(*x++) ;
	}
	UART_Send('#') ; 
}
void UART_ReceiveString(u8 *strptr)
{
	u16 i = 0 ;
	for(i = 0 ; (strptr[i] = UART_Receive() ) != '#' ; i++) ;
	strptr[i] = '\0' ;
	
}

void  UART_ReceiveString_WithLength(u8 *strptr , u16 length)
{
	u8 i = 0 ;
	for(i = 0 ; i < length ; i++)
	{
		strptr[i] = UART_Receive() ;
	}
	strptr[i] = '\0' ;
}
/************** Functions associated with TTL ( Prolific and Bluetooth module) *************/

void UART_SendLong_TTL(u32 data)
{
	u8 number_of_digits = 0  ,r = 0 ,i = 0 , x = 0  ;
	u32 rev = 0  ;
	while(data)
	{
		/********* Reversing the number ***********/
		r = data % 10 ;
		data /= 10 ;
		rev = rev * 10 + r ;
		/*****************************************/
		number_of_digits ++ ;
	}
	for(i = 0 ; i < number_of_digits ; i++)
	{
		x = rev % 10 ;
		UART_Send(x + '0') ;
		rev /= 10 ;
	}

	
}
u32 UART_ReceiveLong_TTL(void)
{
	u8 i = 0 ;
	u8 byte_rec = 0  ;
	u32 sum = 0  ;
	for(i = 0 ;(byte_rec = UART_Receive()) != '#' ; i++)
	{
		sum *= 10 ;
		sum += (byte_rec - '0') ;
	}

	
	return sum ;
}
u8 UART_Receive_NoBlock_TTL(u8 * ch)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*ch = UDR ;
		return 1 ; // receive completed
	}
	else
	{
		return 0 ;
	}
}
void UART_SendString_WithLength_CheckSum_TTL(u8 *str) 
{
	u8 i = 0 ; 
	u32 sum = 0 ; 
	while(str[i])
	{
		i++ ; 
	}
	UART_SendLong_TTL(i) ; 
	#if DEBUG 
	UART_SendString("\r\n") ; 
	#endif
	i = 0 ; 
	while(str[i])
	{
		UART_Send(str[i]) ; 
		sum += str[i] ; 
		i++ ;
	}
	UART_Send('\0') ; 
	#if DEBUG 
	UART_SendString("\r\n") ; 
	#endif
	UART_SendLong(sum) ; 
	#if DEBUG 
	UART_SendString("\r\n") ;
	UART_SendString("\r\n") ;
	#endif
	
	// mtnsash t3ml el recieve bta3ha

}
/*******************************************************************************************/
void UART_SendLong(u32 data) 
{
	UART_Send((u8) data) ;
	UART_Send((u8) (data >> 8)) ;
	UART_Send((u8) (data >> 16)) ;
	UART_Send((u8) (data >> 24)) ;
}
u32 UART_ReceiveLong(void) 
{
	u8 byte_1 = UART_Receive() ;
	u8 byte_2 = UART_Receive() ;
	u8 byte_3 = UART_Receive() ;
	u8 byte_4 = UART_Receive() ;
	u32 number = byte_1 | ((u32)byte_2<<8) | ((u32)byte_3<<16) | ((u32)byte_4 << 24) ; 
	return number ;  
}
void UART_SendString_CS(u8 *str)
{
	u8 i = 0 ; 
	u16 sum = 0 ; 
	for(i = 0 ; str[i] ; i++) 
	{
		sum += str[i] ; 
	}
	UART_Send(i) ; 
	for(i = 0 ; str[i] ; i++)
	{
		UART_Send(str[i]) ; 
	}
	UART_Send(sum) ; 
	UART_Send(sum >> 8) ; 
}
u8 UART_ReceiveString_CS(u8 *str)
{
	u8 length = 0  , byte_1 , byte_2 ; 
	u8 i = 0 ; 
	u16 sum_rec = 0  , sum = 0 ; 
	length = UART_Receive() ; 
	for(i = 0 ; i < length ; i++)
	{
		str[i] = UART_Receive() ; 
		sum += str[i] ; 
	}
	//str[i] = '\0' ; 
	byte_1 = UART_Receive() ; 
	byte_2 = UART_Receive() ; 
	sum_rec = (u16) byte_1 | (u16) (byte_2 << 8) ; 
	if(sum == sum_rec)
	{
		return 1 ; 
	}
	else
	{
		return 0 ; 
	}
	
}
static void uart_sendstring_isr(void) // used in setcall back tx function
{
	static u8 i = 1;
	if(pSendData[i] != '\0')
	{
		UART_Send_NoBlock(pSendData[i]) ;
		i++ ;
	}
	else
	{
		i = 1 ; // to make the function be used the next time ;)
	}

}

void UART_SendString_Using_Interrupt(u8 *str)
{
	UART_TXI_SetCallBack(uart_sendstring_isr) ;
	UART_Send(str[0]) ;
	pSendData = str ;
}

static void uart_receivestring_isr(void)
{
	static u8 i = 0 ; 

		pRecData[i] = UDR ; 
		i++ ; 

}

void UART_ReceiveString_Interrupt(u8* str)
{
	UART_RXI_SetCallBack(uart_receivestring_isr) ;
	pRecData = str ; 
}
