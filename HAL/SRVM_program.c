/*
 * SRVM_program.c
 *
 *  Created on: Jan 28, 2024
 *      Author: nadia
 */
#define F_CPU 16000000UL
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "SRVM_interface.h"

#include "DIO_interface.h"
//#include "TIMER1_interface.h"

void SRVM_init(void)
{
DIO_setPinDirection(DIO_PORTD,DIO_PIN5,DIO_PIN_OUTPUT);
}
void SRVM_on(u8 angle)
{
	if(angle<=0)
	{
		angle=1;
	}
	float local_delay=(1009.0f*(float)angle)/50.0;
	DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_HIGH);
	_delay_us(local_delay);
	DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_LOW);


	//TMR1_init();
	//TMR1_setPWM_mode14(50,angle);
	//TMR1_start();
}
void SRVM_stop(void)
{
//TMR1_stop();
	DIO_setPinValue(DIO_PORTD,DIO_PIN5,DIO_PIN_LOW);
}



