/*
 * GIR_program.c
 *
 *  Created on: Jan 6, 2024
 *      Author: nadia
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GIR_interface.h"
#include "GIR_private.h"

void GIR_enable(void)
{
	SET_BIT(SREG,I);

}

void GIR_disable(void)
{
	CLR_BIT(SREG,I);

}
