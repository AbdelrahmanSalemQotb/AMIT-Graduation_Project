/*
 * Push_Bottoms.c
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "util/delay.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
u8 EnableDisableFlag=FALSE;
extern u8 FirstBottomFlag;
extern u8 Bottom_Increase_Pressed_Flag;
extern u8 Bottom_Decrease_Pressed_Flag;

void PushBottoms_voidInit (void)
{
	/* Set Bottoms to input pulldown */
	DIO_u8SetPinDirection(DIO_PIN2,DIO_PORTB,PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PIN3,DIO_PORTD,PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PIN2,DIO_PORTD,PIN_INPUT); //

}
void PushBottoms_u8IsIncrease_Bottom_Pressed (void)
{
	if (FALSE==FirstBottomFlag)
	{
		FirstBottomFlag=TRUE;
	}
	else
	{
		FirstBottomFlag=TRUE;
		Bottom_Increase_Pressed_Flag=1;
	}

}

void PushBottoms_u8IsDecrease_Bottom_Pressed (void)
{
	if (FALSE==FirstBottomFlag)
	{
		FirstBottomFlag=TRUE;
	}
	else
	{
		FirstBottomFlag=TRUE;
		Bottom_Decrease_Pressed_Flag=1;
	}
}

void PushBottoms_voidEnable_Disable (void)
{
	if (EnableDisableFlag==FALSE)
	{
		EnableDisableFlag=TRUE;
		/* run the code */


		/* Enable increase / decrease bottoms interrupt */
		EXTI_voidINT1_Init();
		EXTI_voidINT2_Init();

	}
	else
	{
		EnableDisableFlag=FALSE;
		/* Turn off 7-segment and temperature heat/cold */
		/* Disable increase / decrease bottoms interrupt */
		EXTI_voidINT1_Disable();
		EXTI_voidINT2_Disable();
	}
}

