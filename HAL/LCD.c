#define  F_CPU 8000000UL
#include <util/delay.h>
#include "MemMap.h"
#include "stdTypes.h"
#include "DIO_INTRFACE.h"
#include "Utils.h"
#include "LCD.h"


#if (LCD_MODE==LCD_8bit)
	
	void LCD_Writecommand(u8 command)
	{
		DIO_WritePin(RS,LOW);
		DIO_WritePin(RW,LOW);
		DIO_WritePort(LCD_PORT,command);
		DIO_WritePin(EN,HIGH);
		_delay_ms(2);
		DIO_WritePin(EN,LOW);
		_delay_ms(2);
		
	}

	void LCD_Writedate(u8 data)
	{
		DIO_WritePin(RS,HIGH);
		DIO_WritePin(RW,LOW);
		DIO_WritePort(LCD_PORT,data);
		DIO_WritePin(EN,HIGH);
		_delay_ms(2);
		DIO_WritePin(EN,LOW);
		_delay_ms(2);
		
	}

	void LCD_Init(void)
	{
		_delay_ms(50);
		LCD_Writecommand(0x38);
		_delay_ms(1);
		LCD_Writecommand(0x0f);//cursor
		_delay_ms(1);
		LCD_Writecommand(0x01);//clear
		_delay_ms(2);
		LCD_Writecommand(0x06);//DDRAM ADDRESS INCRE
		_delay_ms(2);
	}



#elif(LCD_MODE == LCD_4bit)


	void Lcd4_Port(u8 a)
	{
		if(a & 1)
		DIO_WritePin(D4,1);
		else
		DIO_WritePin(D4,0);
		
		if(a & 2)
		DIO_WritePin(D5,1);
		else
		DIO_WritePin(D5,0);
		
		if(a & 4)
		DIO_WritePin(D6,1);
		else
		DIO_WritePin(D6,0);
		
		if(a & 8)
		DIO_WritePin(D7,1);
		else
		DIO_WritePin(D7,0);
	}

	void LCD_Writecommand(u8 command)
	{
		DIO_WritePin(RS,LOW);
		DIO_WritePin(RW,LOW);
		Lcd4_Port(command>>4);
		DIO_WritePin(EN,HIGH);
		_delay_ms(2);
		DIO_WritePin(EN,LOW);
		_delay_ms(2);
		Lcd4_Port(command);
		DIO_WritePin(EN,HIGH);
		_delay_ms(2);
		DIO_WritePin(EN,LOW);
		_delay_ms(2);
	}

	void LCD_Writedate(u8 data)
	{
		DIO_WritePin(RS,HIGH);
		DIO_WritePin(RW,LOW);
		Lcd4_Port(data>>4);
		DIO_WritePin(EN,HIGH);
		_delay_ms(2);
		DIO_WritePin(EN,LOW);
		_delay_ms(2);
		Lcd4_Port(data);
		DIO_WritePin(EN,HIGH);
		_delay_ms(2);
		DIO_WritePin(EN,LOW);
		_delay_ms(2);
	}

	void LCD_Init(void)
	{
		_delay_ms(50);
		LCD_Writecommand(0x02);
		_delay_ms(1);
		LCD_Writecommand(0x28);
		_delay_ms(1);
		LCD_Writecommand(0x0f);//cursor 0x0c,0x0e,0x0f
		_delay_ms(1);
		LCD_Writecommand(0x01);//clear
		_delay_ms(2);
		LCD_Writecommand(0x06);//DDRAM ADDRESS INCRE
		_delay_ms(1);
	}


#endif


void LCD_Writestring (u8 * str)
{
	u8 i=0;
	while(str[i]!='\0')
	{
		LCD_Writedate(str[i]);
		i++;
	}
}

void LCD_WriteNumber(s16 num)
{
	u8 i=0;
	u8 mod = 0;
	u8 string[16];
	if (num==0)
	{
		LCD_Writedate('0');
	}
	else
	{
	if(num<0)
	{
		LCD_Writedate('-');
		num=num*(-1);
	}
	
	
		 while (num)
		 {
			 mod=num%10;
			 string[i]=mod;
			 num/=10;
			 i++;
		 }
		 
	for(;i>0;i--)
	{
		LCD_Writedate(string[i-1] +'0');
	}
	}
	
}

void LCD_3degitNumber(s16 num)
{
	u8 i=0;
	u8 mod = 0;
	u8 string[3]={48,48,48};
	
	while (num)
	{
		mod=num%10;
		string[i]=mod;
		num/=10;
		i++;
	}
	
	for(i=3;i>0;i--)
	{
		LCD_Writedate(string[i-1] +'0');
	}
}

void LCD_Clear ()
{
	LCD_Writecommand(0x01);
}

void LCD_GoTo(u8 line,u8 col)
{
	if(line==1)
	{
		LCD_Writecommand(0x80+col-1);
	}
	else if(line==2)
	{
		LCD_Writecommand(0x80+0x40+col-1);
	}
	else if(line==3)
	{
		LCD_Writecommand(0x80+0x14+col-1);
	}
	else if(line==4)
	{
		LCD_Writecommand(0x80+0x54+col-1);
	}
	
}

void LCD_CreateChar(u8 add ,u16 * pattern)
{
	u8 i;
	LCD_Writecommand(0x40+(add*8));
	for(i=0;i<8;i++)
	{
		LCD_Writecommand(pattern[i]);
	}
}

void LCD_WriteChar(u8 data)
{
	LCD_Writedate(data);
}


void LCD_WriteNumberInBinary(u8 num)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		LCD_Writedate(((num>>i)&1)+'0');
	}
}

void LCD_WriteNumber_4D(u16 num)
{
	
	LCD_Writedate(((num%10000)/1000)+'0');
	LCD_Writedate(((num%1000)/100)+'0');
	LCD_Writedate(((num%100)/10)+'0');
	LCD_Writedate(((num%10)/1)+'0');
	
}
