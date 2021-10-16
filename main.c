/*
 * main.c
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "Temperature_Sensor_Interface.h"
#include "Temperature_Setting_Interface.h"
#include "Seven_Segment_Interface.h"
#include "DIO_Interface.h"
#include "util/delay.h"
#include "Push_Bottoms_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "TIMER1_Config.h"
#include "TIMER1_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "Heating_elelment_interface.h"
#include "Cooling_element_Interface.h"

void TIMER1_CTC_FUNCTION (void);
void ADC_INT_FUNCTION (void);

u8 TEMP_SENSOR=0;
int main(void)
{
	/* PASS CALLBACK FUNCTIONS OF EXTERNAL INTERRUPTS */
	EXTI0_voidSet_CallbackFunction(PushBottoms_voidEnable_Disable);
	EXTI1_voidSet_CallbackFunction(PushBottoms_u8IsIncrease_Bottom_Pressed);
	EXTI2_voidSet_CallbackFunction(PushBottoms_u8IsDecrease_Bottom_Pressed);
	/* PASS CALLBACK FUNCTION OF TIMER1 */
	TIMER1_voidSetCTCB_CallBackFunction(TIMER1_CTC_FUNCTION);
	/* PASS CALLBACK FUNCTION OF ADC */
	ADC_voidSet_CallbackFunction(ADC_INT_FUNCTION);

	/* Cooling/Heating element init */
	COOLING_voidInit();
	HEATING_voidInit();

	SevenSegment_voidInitPins();
	PushBottoms_voidInit();
	EXTI_voidINT0_Init();
	TemperatureSensor_voidInit();

	while(1)
	{
		switch (EnableDisableFlag) {
		case TRUE:
		{
			if (FALSE==FirstBottomFlag)
			{
				/* Enter Temperature sensor read mode
				 * And Heating Cooling system */
				if (TEMP_SENSOR<=(CurrentSetTemp-5))
				{
					HEATING_voidEnable();
					COOLING_voidDisable();
				}
				else if(TEMP_SENSOR>=(CurrentSetTemp+5))
				{
					COOLING_voidEnable();
					HEATING_voidDisable();
				}

				/* Reading TEMP Sensor Average in ADC interrupt
				 * And Display it here */
				SevenSegment_voidSendNumber(TEMP_SENSOR);
			}
			else
			{
				/* Disable HEATING COOLING SYSTEM */
				COOLING_voidDisable();
				HEATING_voidDisable();
				HEATING_COOLING_voidLED_Disable();

				/* Enter temperature setting mode */
				TemperatureSetting_voidTempSettingModeRun();

			}
		}
		break;
		case FALSE:
			SevenSegment_voidDisable();
			/* Disable HEATING COOLING SYSTEM */
			COOLING_voidDisable();
			HEATING_voidDisable();
			HEATING_COOLING_voidLED_Disable();
			break;
		default:
			break;
		}



	}

	return 0;
}

void TIMER1_CTC_FUNCTION (void)
{
	ADC_voidStartConversion(Input_Channel_ADC_ADC1,MODES_ADC_SINGLE_CONVERSION);

	Heating_LED_Count++;

	switch (FirstBottomFlag) {
	case 51:					/* 5 sec in setting mode only */
		FirstBottomFlag=FALSE;
		break;
	case FALSE:

		break;
	default:
		FirstBottomFlag++;
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
