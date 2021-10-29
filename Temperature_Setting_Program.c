/*
 * Temperature_Setting_Program.c
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "Temperature_Setting_Interface.h"
#include "util/delay.h"
#include "DIO_Interface.h"
#include "Push_Buttons_Interface.h"
#include "Seven_Segment_Interface.h"

u8 FirstButtonFlag=0;
u8 CurrentSetTemp=60;
u8 Button_Increase_Pressed_Flag=0;
u8 Button_Decrease_Pressed_Flag=0;
u8 SettingMode_Segment_Counter =0; ////////////////////////

void TemperatureSetting_voidTempSettingModeRun (void)
{
	if (TRUE==Button_Increase_Pressed_Flag)
	{
		/* Reset Timer Flag To Stop Setting mode after 5 SEC */
		FirstButtonFlag=TRUE;
		Button_Increase_Pressed_Flag=FALSE;
		/* MAX TEMPERATURE SET IS 75 */
		if (75!=CurrentSetTemp)
		{
			CurrentSetTemp+=5;
		}
		else
		{
			CurrentSetTemp=75;
		}
	}
	else if (TRUE==Button_Decrease_Pressed_Flag)
	{
		/* Reset Timer Flag To Stop Setting mode after 5 SEC */
		FirstButtonFlag=TRUE;
		Button_Decrease_Pressed_Flag=FALSE;
		/* MIN TEMPERATURE SET IS 35 */
		if (35!=CurrentSetTemp)
		{
			CurrentSetTemp-=5;
		}
		else
		{
			CurrentSetTemp=35;
		}

	}
	else
	{

	}
	if (10>SettingMode_Segment_Counter)
	{
		SevenSegment_voidSendNumber(CurrentSetTemp);
	}
	else
	{

	}
}



