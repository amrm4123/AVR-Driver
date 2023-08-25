



#include "SPI.h"


void SPI_InitMaster(void)
{
	//master
	SET_BIT(SPCR,MSTR);
	//clock
	//polarity
	//phase
	
	//Enable
	SET_BIT(SPCR,SPE);
	
}
void SPI_InitSlave(void)
{
	//slave
	CLEAR_BIT(SPCR,MSTR);
	
	//clock
	
	//Enable
	SET_BIT(SPCR,SPE);
	
}

u8 SPI_SendReceive(u8 data)
{
	
	SPDR=data;
	while(!READ_BIT(SPSR,SPIF));
	return SPDR;
}

u8 SPI_ReceiveNoblock(void)
{
	return SPDR;
}

void SPI_SendNoblock(u8 data)
{
	SPDR=data;
}

u8 SPI_ReceivePeridicChecking(u8 *pdata)
{
	if(READ_BIT(SPSR,SPIF))
	{
		*pdata=SPDR;
		return 1;
	}
	return 0;
}

void SPI_Interrupt_Enable(void)
{
	SET_BIT(SPCR,SPIE);
}
void SPI_Interrupt_Disable(void)
{
	CLEAR_BIT(SPCR,SPIE);
}

