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
#include "util/delay.h"
#include "Heating_Cooling_Elements_Interface.h"
#include "INTERNAL_EEPROM_Interface.h"
#include "Push_Buttons_Interface.h"
#include "INT_Functions.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"
#include "TIMER1_Config.h"
#include "TIMER1_Interface.h"


#define EEPROM_TEMPERATURE_ADDRESS	125
u8 EEPROM_Temp_Data=0;
u8 TEMP_SENSOR=0;

int main(void)
{
	/* PASS CALLBACK FUNCTIONS OF EXTERNAL INTERRUPTS */
	EXTI0_voidSet_CallbackFunction(PushButtons_voidEnable_Disable);
	EXTI1_voidSet_CallbackFunction(PushButtons_u8IsIncrease_Button_Pressed);
	EXTI2_voidSet_CallbackFunction(PushButtons_u8IsDecrease_Button_Pressed);
	/* PASS CALLBACK FUNCTION OF TIMER1 */
	TIMER1_voidSetCTCB_CallBackFunction(TIMER1_CTC_FUNCTION);
	/* PASS CALLBACK FUNCTION OF ADC */
	ADC_voidSet_CallbackFunction(ADC_INT_FUNCTION);

	/* Cooling/Heating element init */
	COOLING_voidInit();
	HEATING_voidInit();
	/* Read EEPROM and check if EEPROM Have a Valid Temp_SET Data */
	EEPROM_Temp_Data=INTERNAL_EEPROM_voidReadByte(EEPROM_TEMPERATURE_ADDRESS);
	if (EEPROM_Temp_Data!=0xFF)
	{
		CurrentSetTemp=EEPROM_Temp_Data;
	}
	else
	{
		CurrentSetTemp=60;
	}
	/* INIT */
	SevenSegment_voidInitPins();
	PushButtons_voidInit();
	EXTI_voidINT0_Init();
	TemperatureSensor_voidInit();


	while(1)
	{
		switch (EnableDisableFlag) {
		case TRUE:
		{
			if (FALSE==FirstButtonFlag)
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
				INTERNAL_EEPROM_voidWriteByte(EEPROM_TEMPERATURE_ADDRESS,CurrentSetTemp);

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

