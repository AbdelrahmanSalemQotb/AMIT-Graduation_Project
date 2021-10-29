/*
 * INT_Functions.c
 *
 *  Created on: Oct 29, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "Temperature_Sensor_Interface.h"
#include "Temperature_Setting_Interface.h"
extern u8 Heating_LED_Count;
extern u8 TEMP_SENSOR;
void TIMER1_CTC_FUNCTION (void)
{
	Heating_LED_Count++;

	switch (FirstButtonFlag) {
	case 51:					/* 5 sec in setting mode only */
		FirstButtonFlag=FALSE;
		break;
	case FALSE:

		break;
	default:
		FirstButtonFlag++;
		if (19==SettingMode_Segment_Counter)
		{
			SettingMode_Segment_Counter=0;
		}
		else
		{
			SettingMode_Segment_Counter++;
		}

		break;
	}
}

void ADC_INT_FUNCTION (void)
{
	TEMP_SENSOR=TemperatureSensor_u8GetTempAverage();
}
