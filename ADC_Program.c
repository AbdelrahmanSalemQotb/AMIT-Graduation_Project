/*
 * ADC_Program.c
 *
 *  Created on: Sep 19, 2021
 *      Author: msqotb
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_Config.h"
#include "ADC_Private.h"

void (*ADC_Callback_Function)(void);

u16 ADC_u16DigitalRead(void)
{
	if (LOC_ADC_InterruptFlag==FALSE)
	{
		/* POLLING */
		while(GET_BIT(ADCSRA,4)==0);
		/* Clear ADIF Flag */
		SET_BIT(ADCSRA,4);

	}
	else
	{
		/* NOTHING */
	}
#if ADC_RESLOUTION==ADC_RESLOUTION_10BIT
	if(ADC_ADJUST==L_Adjust)
	{
		return (ADC>>6);
	}
	else
	{
	}
	return ADC;
#else
	if(ADC_ADJUST==L_Adjust)
	{
		return (ADC>>8);
	}
	else
	{
	}
	return (ADC>>2);
#endif


}

void ADC_voidInit(Reference_voltage_ADC Copy_u8VREF  ,ADC_Prescaler Copy_u8ADCPrescaler ,BOOL Copy_BOOL_ADCInterrupt )
{
	/*1-select Reference voltage */

	switch (Copy_u8VREF)
	{
	case Reference_voltage_ADC_AVCC:
		SET_BIT(ADMUX,6);
		CLR_BIT(ADMUX,7);
		break;
	case Reference_voltage_ADC_2_56V:
		SET_BIT(ADMUX,6);
		SET_BIT(ADMUX,7);
		break;
	default:
		break;
	}

	/*2-Select Left or Right adjust  --> (Right adjust) */
	CLR_BIT(ADMUX,5);
	ADMUX|=(ADC_ADJUST<<5);

	/* clear prescaler bits*/
	ADCSRA&=0xF8;
	/*3- Select Prescaler  */
	ADCSRA|=Copy_u8ADCPrescaler;

	/*4- Enable ADC*/
	SET_BIT(ADCSRA,7);


	switch (Copy_BOOL_ADCInterrupt) {
		case TRUE:
			/*ADC Interrupt Enable*/
			LOC_ADC_InterruptFlag=1;
			SET_BIT(ADCSRA,3);
			break;
		default:
			LOC_ADC_InterruptFlag=0;
			break;
		}

}

void ADC_voidStartConversion(Input_Channel_ADC Copy_u8Channel , MODES_ADC Copy_u8ADCMode)
{

	/* MASK The 5 LSB In ADMUX Register */
	ADMUX&=0xE0;

	/* Set Your channel */
	ADMUX|=Copy_u8Channel;

	if (Copy_u8ADCMode!=MODES_ADC_SINGLE_CONVERSION)
	{
		/* AUTO TRIGGER MODE SELECT */
		SFIOR&=0x1F;
		SFIOR|=(Copy_u8ADCMode<<5);
		/* AUTO TRIGGER ENABLE */
		SET_BIT(ADCSRA,5);
	}
	else
	{

	}

	/* Start Conversion */
	SET_BIT(ADCSRA,6);
}
void ADC_voidSet_CallbackFunction (void (*Copy_ADC_Callback_Function)(void))
{
	ADC_Callback_Function=Copy_ADC_Callback_Function;
}

void __vector_16(void) __attribute__((signal));
void __vector_16 (void)
{
	ADC_Callback_Function();
}

