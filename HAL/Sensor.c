/*
 * Sensor.c
 *
 * Created: 10/7/2020 6:31:12 PM
 *  Author: amr
 */ 



#include "Sensor.h"

#include<stdio.h>
#include "LCD.h"
double vin;
double vout;
char output[6];

u16 POT_Read(void)
{
	u16 adc=ADC_Read(POT);
	u16 volt=((u32)adc*5000)/1024;
	return volt;
	
}

u16 TEMP_Read(void)
{
	u16 adc=ADC_Read(LM_35);
	u16 volt=((u32)adc*5000)/1024;
	u16 temp=volt;
	return temp;
	
	
}

