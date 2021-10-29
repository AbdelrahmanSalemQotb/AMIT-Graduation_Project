/*
 * Temperature_Sensor_Program.c
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "TIMER1_Config.h"
#include "TIMER1_Interface.h"
#include "GIE_Interface.h"
void TemperatureSensor_voidInit(void)
{
	DIO_u8SetPinDirection(DIO_PIN1,DIO_PORTA,PIN_INPUT);
	ADC_voidInit(Reference_voltage_ADC_AVCC,ADC_PR64,TRUE);
	ADC_voidStartConversion(Input_Channel_ADC_ADC1,MODES_ADC_TIMER1_COMPAR_MATCH_B);
	TIMER1_voidSet_ICRValue(6250);
	TIMER1_voidInit(PIN_OC1B);
	GIE_voidEnable();

}
u16 TemperatureSensor_u8GetTempValue (void)
{

	u16 DigitalTemp=0,CurrentTemperature=0;

	DigitalTemp=ADC_u16DigitalRead();
	/* using 10bit resolution */
	CurrentTemperature=(DigitalTemp*5000UL)/10240;
	return CurrentTemperature;
}
u16 TemperatureSensor_u8GetTempAverage (void)
{
	static u8 Counter=0 ;
	static u16 Current_Values_Temp[10]={0};
	static u16 Temperature_AVERAGE=0;


	Current_Values_Temp[Counter]=TemperatureSensor_u8GetTempValue();

	/*get average*/
	if (9==Counter)
	{
		Temperature_AVERAGE=0;
		for (Counter=0;Counter<10;Counter++)
		{
			Temperature_AVERAGE+=Current_Values_Temp[Counter];
		}
		Counter=0;

		Temperature_AVERAGE/=10;
	}
	else
	{
		Counter++;
	}
	return Temperature_AVERAGE;

}

