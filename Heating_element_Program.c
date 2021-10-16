/*
 * Heating_element_Program.c
 *
 *  Created on: Oct 15, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "Heating_element_Config.h"
#include "DIO_Interface.h"
u8 Heating_LED_Count=0;
void HEATING_voidInit (void)
{
	DIO_u8SetPinDirection(HEATING_ELEMENT_PIN,HEATING_ELEMENT_PORT,PIN_OUTPUT);

}
void HEATING_voidEnable (void)
{
	if (9<=Heating_LED_Count)
	{
		DIO_u8TogglePinValue(HEATING_COOLING_ELEMENT_LED_PIN,HEATING_COOLING_ELEMENT_LED_PORT);
		Heating_LED_Count=0;
	}
	else
	{
		/* NOTHING */
	}
	DIO_u8SetPinValue(HEATING_ELEMENT_PIN,HEATING_ELEMENT_PORT,PIN_HIGH);

}
void HEATING_voidDisable (void)
{
	DIO_u8SetPinValue(HEATING_ELEMENT_PIN,HEATING_ELEMENT_PORT,PIN_LOW);

}

