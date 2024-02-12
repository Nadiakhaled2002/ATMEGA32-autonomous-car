/*
 * TIMER1_interface.h
 *
 *  Created on: Jan 27, 2024
 *      Author: nadia
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"



#define PWM	        	0
#define normal_ICP		1

#define risingEdge      0
#define fallingEdge     1


void TMR1_init(u8 mode);
void TMR1_inputCapture(u8 EDGE);
void TMR1_intEnable(void);
void TMR1_disableIC(void);
void TMR1_start(u8 mode);
void TMR1_stop(void);
void TMR1_setCompareMatchValueA(u16 compareValue);
void TMR1_setPWM_mode14(u16 freq_HZ,float duty);





#endif /* TIMER1_INTERFACE_H_ */
