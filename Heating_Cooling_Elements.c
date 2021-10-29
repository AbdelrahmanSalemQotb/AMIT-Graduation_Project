/*
 * Heating_Cooling_Elements.c
 *
 *  Created on: Oct 29, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "Heating_Cooling_Elements_Config.h"
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

void COOLING_voidInit (void)
{
	DIO_u8SetPinDirection(HEATING_COOLING_ELEMENT_LED_PIN,HEATING_COOLING_ELEMENT_LED_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(COOLING_ELEMENT_PIN,COOLING_ELEMENT_PORT,PIN_OUTPUT);

}
void COOLING_voidEnable (void)
{

	DIO_u8SetPinValue(HEATING_COOLING_ELEMENT_LED_PIN,HEATING_COOLING_ELEMENT_LED_PORT,PIN_HIGH);

	DIO_u8SetPinValue(COOLING_ELEMENT_PIN,COOLING_ELEMENT_PORT,PIN_HIGH);

}
void COOLING_voidDisable (void)
{
	DIO_u8SetPinValue(COOLING_ELEMENT_PIN,COOLING_ELEMENT_PORT,PIN_LOW);

}

void HEATING_COOLING_voidLED_Disable(void)
{
	DIO_u8SetPinValue(HEATING_COOLING_ELEMENT_LED_PIN,HEATING_COOLING_ELEMENT_LED_PORT,PIN_LOW);

}



