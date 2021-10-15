/*
 * GIE_Program.c
 *
 *  Created on: Sep 14, 2021
 *      Author: msqotb
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GIE_Private.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);

}
