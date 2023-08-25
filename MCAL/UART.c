

#include "UART.h"


static void(*rxc_isr)(void) = (void *) 0x00 ;
static void(*txc_isr)(void) = (void *) 0x00 ;


void UART_Init(void)
{
	
	
	
	//baud rate 9600
	UBRRL=51;
	
	
	//enable trans,receiver
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}

void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}

u8 UART_Receive(void)
{
	
	while(!READ_BIT(UCSRA,RXC));
	return UDR;
}

void UART_Send_NoBlock(u8 data)
{
	UDR = data ;
}
u8 UART_Receive_NoBlock(u8 *data)
{
	if(CHECK_IF_BIT_SET_MODIFIED(UCSRA,RXC))
	{
		*data = UDR ;
		return 1 ;
	}
	else
	{
		return 0 ;
	}
}
void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE) ;
}
void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE) ;
}
void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE) ;
}
void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE) ;
}
void UART_RXI_SetCallBack(void(*ptr)(void))
{
	rxc_isr = ptr ;
}
void UART_TXI_SetCallBack(void(*ptr)(void))
{
	txc_isr = ptr ;
}
ISR(UART_RX_vect)
{
	rxc_isr() ;
}
ISR(UART_TX_vect)
{
	txc_isr() ;
}




/*
void UART_SendString(u8 *str)
{
	while(*str != '\0')
	{
		UART_Send(*str);
		str++;
	}
}

void UART_ReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = UART_Receive();
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_Receive();
	}
	str[i] = '\0';
}

void UART_SendLong(u32 data)
{
	u8 number_of_digits = 0  ,r = 0 ,i = 0 , x = 0  ;
	u32 rev = 0  ;
	while(data)
	{
		
		r = data % 10 ;
		data /= 10 ;
		rev = rev * 10 + r ;
		
		number_of_digits ++ ;
	}
	for(i = 0 ; i < number_of_digits ; i++)
	{
		x = rev % 10 ;
		UART_Send(x + '0') ;
		rev /= 10 ;
	}

	
}
u32 UART_ReceiveLong(void)
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


void UATR_SendString_CS(u8*str)
{
	u8 i=0;
	u16 chick=0;
	while(str[i])
	{
		i++;
	}
	UART_Send(i);
	i=0;
	while(str[i])
	{
		UART_Send(str[i]);
		chick +=str[i];
		i++;
	}
	UART_SendString(str);
}
*/