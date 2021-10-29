/*
 * Push_Buttons.c
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
extern u8 FirstButtonFlag;
extern u8 Button_Increase_Pressed_Flag;
extern u8 Button_Decrease_Pressed_Flag;

void PushButtons_voidInit (void)
{
	/* Set Buttons to input pulldown */
	DIO_u8SetPinDirection(DIO_PIN2,DIO_PORTB,PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PIN3,DIO_PORTD,PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PIN2,DIO_PORTD,PIN_INPUT); //

}
void PushButtons_u8IsIncrease_Button_Pressed (void)
{
	if (FALSE==FirstButtonFlag)
	{
		FirstButtonFlag=TRUE;
	}
	else
	{
		FirstButtonFlag=TRUE;
		Button_Increase_Pressed_Flag=1;
	}

}

void PushButtons_u8IsDecrease_Button_Pressed (void)
{
	if (FALSE==FirstButtonFlag)
	{
		FirstButtonFlag=TRUE;
	}
	else
	{
		FirstButtonFlag=TRUE;
		Button_Decrease_Pressed_Flag=1;
	}
}

void PushButtons_voidEnable_Disable (void)
{
	if (EnableDisableFlag==FALSE)
	{
		EnableDisableFlag=TRUE;
		/* run the code */


		/* Enable increase / decrease Buttons interrupt */
		EXTI_voidINT1_Init();
		EXTI_voidINT2_Init();

	}
	else
	{
		EnableDisableFlag=FALSE;
		/* Turn off 7-segment and temperature heat/cold */
		/* Disable increase / decrease Buttons interrupt */
		EXTI_voidINT1_Disable();
		EXTI_voidINT2_Disable();
	}
}

