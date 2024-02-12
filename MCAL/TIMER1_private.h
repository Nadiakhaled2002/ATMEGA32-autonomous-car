/*
 * TIMER1_private.h
 *
 *  Created on: Jan 27, 2024
 *      Author: nadia
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define TCCR1A      (*(volatile u8*)0x4F)
#define WGM10              0
#define WGM11              1
#define COM1A0             6
#define COM1A1             7

#define TCCR1B      (*(volatile u8*)0x4E)
#define CS10               0
#define CS11               1
#define CS12               2
#define WGM12              3
#define WGM13              4
#define ICES1              6

#define TCNT        (*(volatile u16*)0x4C)

#define OCR1A       (*(volatile u16*)0x4A)

#define ICR1        (*(volatile u16*)0x46)

#define TIMSK        (*(volatile u16*)0x59)
#define TOIE1               2
#define OCIE1B              3
#define OCIE1A              4
#define TICIE1              5

#define TIFR        (*(volatile u16*)0x58)

#endif /* TIMER1_PRIVATE_H_ */
