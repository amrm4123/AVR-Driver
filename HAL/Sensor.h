/*
 * Sensor.h
 *
 * Created: 10/7/2020 6:31:37 PM
 *  Author: amr
 */ 


#ifndef SENSOR_H_
#define SENSOR_H_

#include "ADC.h"
#include "stdTypes.h"
#define  POT  CH_0
#define  LM_35  CH_1

u16 POT_Read(void);

u16 TEMP_Read(void);


#endif /* SENSOR_H_ */