/*
 * ADC.c
 *
 * Created: 10/5/2020 8:01:36 PM
 *  Author: amr
 */ 


#include "ADC.h"

//static u8 ADC_Flag=0;

void ADC_Init(ADC_Vref_type vref,ADC_scaler_type scaler)
{
	switch(vref)
	{
		case VREF_VCC:
		SET_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_AREF:
		CLEAR_BIT(ADMUX,REFS0);
		CLEAR_BIT(ADMUX,REFS1);
		break;
		case VREF_V256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;
	}
	//ADC SCALER SELECT
	scaler=scaler&0x07;
	ADCSRA=ADCSRA&0xf8;//0b11111000
	ADCSRA=ADCSRA|scaler;
	CLEAR_BIT(ADCSRA,ADLAR);
	
	//ADC ENABLE
	SET_BIT(ADCSRA,ADEN);
	
	
	
}


u16 ADC_Read(ADC_CH_TYPE ch)
{
	//select ch
	ADMUX=ADMUX&0xE0;//0b11100000
	ADMUX=ADMUX|ch;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	//POLLING
	while(READ_BIT(ADCSRA,ADSC));
	
	return ADC;
}

/*

void ADC_Startconv(ADC_CH_TYPE ch)
{
	if(ADC_Flag)
	{
		ADMUX=ADMUX&0xE0;//0b11100000
		ADMUX=ADMUX|ch;
		//start conversion
		SET_BIT(ADCSRA,ADSC);
		ADC_Flag=1;
	}
}

u16 ADC_GetRead(void)
{
	while(READ_BIT(ADCSRA,ADSC));
	
	return ADC;
}

u8 ADC_GetReadNoBlock(u16*pdate)
{
	if(READ_BIT(ADCSRA,ADSC)==0)
	{
		*pdate=ADC;
		ADC_Flag=0;
		return 1;
		
	}
	else
	{
		return 0;
	}
}


*/