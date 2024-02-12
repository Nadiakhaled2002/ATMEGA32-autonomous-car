/*
 * USS_program.c
 *
 *  Created on: Jan 31, 2024
 *      Author: nadia
 *
*/
#define F_CPU 16000000UL
#include"STD_TYPES.h"
#include"BIT_MATH.H"
#include <string.h>
#include <util/delay.h>

//#include "LCD_interface.h"
#include "USS_config.h"
#include "USS_interface.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "GIR_interface.h"
#include "DIO_interface.h"


static volatile u16 capt1,capt2;
static volatile u8 flag=0;
static volatile u16 ov;
static volatile u16 ovf;
void USS_init(void)
{

	//LCD_init();

	DIO_setPinDirection(TRIG_PORT,TRIG_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(ECHO_PORT,ECHO_PIN,DIO_PIN_INPUT);
	//DIO_activePinInPullUpResistance(ECHO_PORT,ECHO_PIN);
	GIR_disable();
	TMR1_init(normal_ICP);
	TMR1_intEnable();
	TMR1_inputCapture(risingEdge);
	TMR1_start(normal_ICP);
	GIR_enable();
}
void GetDistance(u16*dist)
{
   static u16 count;
	static u16 distance;

    	DIO_setPinValue(TRIG_PORT,TRIG_PIN,DIO_PIN_HIGH);
    		_delay_ms(10);
    		DIO_setPinValue(TRIG_PORT,TRIG_PIN,DIO_PIN_LOW);
		if(flag==2)
		{
			flag=0;
			//time -->count:time2-tim1 *overflow that happened during cycle *tick time*ticks
			count = ((unsigned long)capt2+(unsigned long)(ovf*65536))-(unsigned long)capt1;
			//distance =time/speed of ultrasonic wave
			distance = (double)count/932.95;
if(distance>=2 && distance<=80)
{
			*dist=distance;
}
else if(distance>90)
{
	*dist=100;
}
			ovf=0;ov=0;

			TMR1_intEnable();
			TMR1_inputCapture(risingEdge);


}
}
void USS_stop(void)
{
	TMR1_stop();
}

void __vector_9(void)__attribute__((signal));
void __vector_9(void)
{
	ov++;
}

void __vector_6(void)__attribute__((signal));
void __vector_6(void)
{
	if(flag==0)
	{
		//time 1-->rising edge
		capt1=ICR1;
		TMR1_inputCapture(fallingEdge);
		ov=0;
	}else if(flag==1)
	{
		//time2-->falling edge
		capt2=ICR1;
		ovf=ov;
		TMR1_disableIC();
	}
	flag++;
}


