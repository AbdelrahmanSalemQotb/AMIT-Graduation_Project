/*
 * TIMER1_Program.c
 *
 *  Created on: Sep 25, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_Private.h"
#include "TIMER1_Config.h"
#include "DIO_Interface.h"
void (*TIMER1_CTCA_CallBackFunction)(void);
void (*TIMER1_CTCB_CallBackFunction)(void);

void TIMER1_voidInit(PIN_OC1 Copy_OC1_PINUnitSelect)
{
	/* Select MODE */
#if 	TIMER1_MODE==TIMER1_MODE_NORMAL

	CLR_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	/* Enable OVERFLOW FLAG */
	SET_BIT(TIMSK,2);

#elif	TIMER1_MODE==TIMER1_MODE_PWM_PHASECORRECT_8BITS
	CLR_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_PHASECORRECT_9BITS
	CLR_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_PHASECORRECT_10BITS
	CLR_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_CTC_TOP_OCR1A
	CLR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	/*Enable compare interrupt*/
	switch (Copy_OC1_PINUnitSelect) {
	case PIN_OC1A:		SET_BIT(TIMSK,4);		break;
	case PIN_OC1B: 		SET_BIT(TIMSK,3); 		break;
	default:									break;}

#elif	TIMER1_MODE==TIMER1_MODE_PWM_FAST_8BITS
	CLR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_FAST_9BITS
	CLR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_FAST_10BITS
	CLR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_TOP_ICR1
	SET_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_TOP_OCR1A
	SET_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_PHASECORRECT_TOP_ICR1
	SET_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_PHASECORRECT_TOP_OCR1A
	SET_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_CTC_TOP_ICR1
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	/*Enable compare interrupt*/
	switch (Copy_OC1_PINUnitSelect) {
	case PIN_OC1A:		SET_BIT(TIMSK,4);		break;
	case PIN_OC1B: 		SET_BIT(TIMSK,3); 		break;
	default:									break;}
#elif	TIMER1_MODE==TIMER1_MODE_PWM_FAST_TOP_ICR1
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
#elif	TIMER1_MODE==TIMER1_MODE_PWM_FAST_TOP_OCR1A
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);
#else
#error"You have error in set TIMER1 MODE"
#endif



	/*Set Prescaler*/

	TCCR1B&=TIMER1_BITMASK_PRESCALER;
	TCCR1B|=TIMER1_PRESCALER;


	/* OC1 MODE */
	switch (Copy_OC1_PINUnitSelect) {
	case PIN_OC1A:
		TCCR1A&=0x3F;
		TCCR1A|=(OC1A_PIN_MODE<<6);
		break;
	case PIN_OC1B:
		TCCR1A&=0xCF;
		TCCR1A|=(OC1B_PIN_MODE<<4);

		break;
	default:
		break;
	}

	if (OC1A_PIN_MODE!=OC1_PIN_DISCONNECTED)
	{
		DIO_u8SetPinDirection(OC1A_PIN_NUMBER,OC1A_PORT_NUMBER,PIN_OUTPUT);
	}
	else
	{

	}
}
void TIMER1_voidSetCTCValue(PIN_OC1 Copy_OC1_PINUnitSelect,u16 Copy_u8CTC_Value)
{
	/* OC1 MODE */
	switch (Copy_OC1_PINUnitSelect) {
	case PIN_OC1A:
		OCR1A=Copy_u8CTC_Value;
		break;
	case PIN_OC1B:
		OCR1B=Copy_u8CTC_Value;
		break;
	default:
		break;
	}
}
void TIMER1_voidSet_ICRValue(u16 Copy_u8CTC_Value)
{
	ICR1=Copy_u8CTC_Value;
}

u16 TIMER1_u16Read_Timer_Register (void)
{
	return TCNT1;
}

void TIMER1_voidICU_Init (void)
{
	/* ICU PIN INPUT */
	DIO_u8SetPinDirection(ICU_PIN_NUMBER,ICU_PORT_NUMBER,PIN_INPUT);

#if		ICU_PIN_STATE==FLOATING
	DIO_u8SetPinValue(ICU_PIN_NUMBER,ICU_PORT_NUMBER,PIN_LOW);
#elif	ICU_PIN_STATE==PULL_UP
	DIO_u8SetPinValue(ICU_PIN_NUMBER,ICU_PORT_NUMBER,PIN_HIGH);
#endif

	/*Set Prescaler*/

	TCCR1B&=TIMER1_BITMASK_PRESCALER;
	TCCR1B|=TIMER1_PRESCALER;

	/* ICU EDGE SELECT */
#if 	TIMER1_ICU_EDGE_SELECT==ICU_FALLING_EDGE
	CLR_BIT(TCCR1B,6);
#elif TIMER1_ICU_EDGE_SELECT==ICU_RISING_EDGE
	SET_BIT(TCCR1B,6);
#endif
	/* ICU NOISE CANCELER */
#if		ICU_NOISE_CANCELR==FALSE
	CLR_BIT(TCCR1B,7);
#elif 	ICU_NOISE_CANCELR==TRUE
	SET_BIT(TCCR1B,7);
#endif

	/* INIT TIMER1 IN NORMAL MODE */
	CLR_BIT(TCCR1B,4);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1A,0);
	/* Enable OVERFLOW FLAG */
	SET_BIT(TIMSK,2);

	/* ICU INTERRUPT ENABLE */
	SET_BIT(TIMSK,5);

}
void TIMER1_ICU_EdgeSelect(ICU_EDGE_SELECT Copy_u8Edge)
{
	switch(Copy_u8Edge)
	{
	case ICU_RISING_EDGE:
		SET_BIT(TCCR1B,6);
		break;
	case ICU_FALLING_EDGE:
		CLR_BIT(TCCR1B,6);
		break;
	}

}

u32 TIMER1_voidICU_Event_TimeValue (void)
{
	return ICR1;
}

void TIMER1_voidSetCTCA_CallBackFunction	(void (*Copy_void_CTCA_CallBackFunction)(void))
{
	TIMER1_CTCA_CallBackFunction=Copy_void_CTCA_CallBackFunction;
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	TIMER1_CTCA_CallBackFunction();
}


void TIMER1_voidSetCTCB_CallBackFunction	(void (*Copy_void_CTCB_CallBackFunction)(void))
{
	TIMER1_CTCB_CallBackFunction=Copy_void_CTCB_CallBackFunction;
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	TIMER1_CTCB_CallBackFunction();
}
