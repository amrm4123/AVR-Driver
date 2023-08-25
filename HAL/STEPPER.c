



#include "DIO_INTRFACE.h"
#include "Stepper.h"


#if(MOTOR_TYPE == BI_POLER)

void STEPPER_CW(void) 
{
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(1000) ; 
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(1000) ;
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(1000) ; 
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,HIGH) ;
	_delay_ms(1000) ; 
	
	
	DIO_WritePin(COIL1A,HIGH) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(1000) ;
	
	



}


void STEPPER_CCW(void) 
{
		DIO_WritePin(COIL1A,LOW) ;
		DIO_WritePin(COIL1B,LOW) ;
		DIO_WritePin(COIL2A,LOW) ;
		DIO_WritePin(COIL2B,HIGH) ;
		_delay_ms(1000) ;

	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,HIGH) ;
	DIO_WritePin(COIL2A,LOW) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(1000) ;
	
	DIO_WritePin(COIL1A,LOW) ;
	DIO_WritePin(COIL1B,LOW) ;
	DIO_WritePin(COIL2A,HIGH) ;
	DIO_WritePin(COIL2B,LOW) ;
	_delay_ms(1000) ;
	
		DIO_WritePin(COIL1A,HIGH) ;
		DIO_WritePin(COIL1B,LOW) ;
		DIO_WritePin(COIL2A,LOW) ;
		DIO_WritePin(COIL2B,LOW) ;
		_delay_ms(1000) ;
}


#elif (MOTOR_TYPE== UNI_POLER)


void STEPPER_CW(void)
{
		DIO_WritePin(COIL3A,HIGH) ;
		DIO_WritePin(COIL3B,LOW) ;
		DIO_WritePin(COIL4A,LOW) ;
		DIO_WritePin(COIL4B,LOW) ;
		_delay_ms(STEPPER_UNI_DELAY) ;

		DIO_WritePin(COIL3A,LOW) ;
		DIO_WritePin(COIL3B,HIGH) ;
		DIO_WritePin(COIL4A,LOW) ;
		DIO_WritePin(COIL4B,LOW) ;
		_delay_ms(STEPPER_UNI_DELAY) ;
		
		DIO_WritePin(COIL3A,LOW) ;
		DIO_WritePin(COIL3B,LOW) ;
		DIO_WritePin(COIL4A,HIGH) ;
		DIO_WritePin(COIL4B,LOW) ;
		_delay_ms(STEPPER_UNI_DELAY) ;
		
		DIO_WritePin(COIL3A,LOW) ;
		DIO_WritePin(COIL3B,LOW) ;
		DIO_WritePin(COIL4A,LOW) ;
		DIO_WritePin(COIL4B,HIGH) ;
		_delay_ms(STEPPER_UNI_DELAY) ;
		

}


void STEPPER_CCW(void)
{
	DIO_WritePin(COIL3A,LOW) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,HIGH) ;
	_delay_ms(STEPPER_UNI_DELAY) ;

	DIO_WritePin(COIL3A,LOW) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,HIGH) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	DIO_WritePin(COIL3A,LOW) ;
	DIO_WritePin(COIL3B,HIGH) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	DIO_WritePin(COIL3A,HIGH) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	

}


void STEPPER_CW_HalfStep(void) 
{
	// 1 
	DIO_WritePin(COIL3A,HIGH) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	// 1 & 2 
	
	DIO_WritePin(COIL3A,HIGH) ;
	DIO_WritePin(COIL3B,HIGH) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	//  2
	
	DIO_WritePin(COIL3A,HIGH) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	// 2 & 3 
	
	DIO_WritePin(COIL3A,LOW) ;
	DIO_WritePin(COIL3B,HIGH) ;
	DIO_WritePin(COIL4A,HIGH) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	// 3
	
	DIO_WritePin(COIL3A,LOW) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,HIGH) ;
	DIO_WritePin(COIL4B,LOW) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	// 3 & 4 
	
	DIO_WritePin(COIL3A,LOW) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,HIGH) ;
	DIO_WritePin(COIL4B,HIGH) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	
	// 4
	
	DIO_WritePin(COIL3A,LOW) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,HIGH) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
	

	// 3 & 4 	
	DIO_WritePin(COIL3A,HIGH) ;
	DIO_WritePin(COIL3B,LOW) ;
	DIO_WritePin(COIL4A,LOW) ;
	DIO_WritePin(COIL4B,HIGH) ;
	_delay_ms(STEPPER_UNI_DELAY) ;
}
#endif


void STEPPER_CW_Withangle(u16 angle)
{
	u16 i , n = ((512*angle)/360);
	for(i=0;i<n;i++)
	{
		STEPPER_CW();
	}
}

void STEPPER_CCW_Withangle(u16 angle)
{
	u16 i , n = ((512*angle)/360);
	for(i=n;i>0;i--)
	{
		STEPPER_CCW();
	}
}