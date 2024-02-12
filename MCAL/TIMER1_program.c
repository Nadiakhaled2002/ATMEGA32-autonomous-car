/*
 * TIMER1_program.c
 *
 *  Created on: Jan 27, 2024
 *      Author: nadia
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIR_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_interface.h"
#include "TIMER1_config.h"




void TMR1_init(u8 mode)
{
	//TIFR=0b00000000;
	//TIFR |= (1 << 0);
	//TIMSK |= (1 << 0);
	//GIR_enable();
	switch(mode)
	{
	case normal_ICP:
	{
	//SELECT MODE=normal
	 CLR_BIT(TCCR1B,WGM13);
	 CLR_BIT(TCCR1B,WGM12);
	 CLR_BIT(TCCR1A,WGM11);
	 CLR_BIT(TCCR1A,WGM10);
	 //clear counter
	 TCNT=0;
	break;
	}
	case PWM:
	{
		//SELECT MODE=FAST PWM MODE 14
		 SET_BIT(TCCR1B,WGM13);
		 SET_BIT(TCCR1B,WGM12);
		 SET_BIT(TCCR1A,WGM11);
		 CLR_BIT(TCCR1A,WGM10);
		 //non inverting
	     SET_BIT(TCCR1A,COM1A1);
	     CLR_BIT(TCCR1A,COM1A0);
	     break;
	}
	}


}
void TMR1_intEnable(void)
{
	 //ENABLE ovf
	 SET_BIT(TIMSK,TOIE1);
	 //ENABLE INPUT CAPTURE INTERRUPT
	 SET_BIT(TIMSK,TICIE1);
}
void TMR1_inputCapture(u8 EDGE)
{

switch(EDGE)
{
case risingEdge:
{
	SET_BIT(TCCR1B,ICES1);
	break;
}
case fallingEdge:
{
	CLR_BIT(TCCR1B,ICES1);
	break;
}



}


}
void TMR1_disableIC(void)
{
	CLR_BIT(TIMSK,TICIE1);
	CLR_BIT(TIMSK,TOIE1);


}
void TMR1_start(u8 mode)
{
	switch(mode)
	{
	case normal_ICP:
	{
	//ICP mode
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	break;
	}
	case PWM:
	{
	//pwm
	CLR_BIT(TCCR1B,CS12);
	SET_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	break;
	}
	}

}

void TMR1_setCompareMatchValueA(u16 compareValue)
{

	OCR1A=compareValue;


}
void TMR1_setPWM_mode14(u16 freq_HZ,float duty)
{
	if(duty<=100)
	{
		ICR1=((1000000UL/freq_HZ)/4)-1;
		//non inverting and time =4 microsec
		OCR1A=((duty*(ICR1+1))/100)-1;




	}
}

void TMR1_stop(void)
{

//clear clock
     CLR_BIT(TCCR1B,CS12);
	 CLR_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS10);



}














