/*
 * ADC.h
 *
 * Created: 10/5/2020 8:01:56 PM
 *  Author: amr
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "MemMap.h"
#include "stdTypes.h"
#include "Utils.h"

typedef enum{
	VREF_VCC,
	VREF_AREF,
	VREF_V256,
}ADC_Vref_type;


typedef enum{
	ADC_SCALER_2=1,
	ADC_SCALER_4=2,
	ADC_SCALER_8=3,
	ADC_SCALER_16=4,
	ADC_SCALER_32=5,
	ADC_SCALER_64=6,
	ADC_SCALER_128=7,
}ADC_scaler_type;


typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	}ADC_CH_TYPE;

u16 ADC_Read(ADC_CH_TYPE ch);
void ADC_Init(ADC_Vref_type vref,ADC_scaler_type scaler);



#endif /* ADC_H_ */