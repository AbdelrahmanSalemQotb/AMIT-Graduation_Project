/*
 * EXTI_Program.c
 *
 *  Created on: Sep 12, 2021
 *      Author: msqotb
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_Private.h"
#include "EXTI_Config.h"

void (*EXTI0Callback_Function)(void);
void (*EXTI1Callback_Function)(void);
void (*EXTI2Callback_Function)(void);

void EXTI_voidINT0_Init(void)
{
	/*Init MCUCR*/
	MCUCR&=0xFC;
	/*select Sense Control*/
	MCUCR|=EXTI0_Sense;
	/*Enable PIE INT0*/
	SET_BIT(GICR,6);
}
void EXTI_voidINT1_Init(void)
{
	/*Init MCUCR*/
	MCUCR&=0xF3;
	/*select Sense Control*/
	MCUCR|=(EXTI1_Sense<<2);
	/*Enable PIE INT1*/
	SET_BIT(GICR,7);
}
void EXTI_voidINT2_Init(void)
{
	/*select Sense Control*/
	CLR_BIT(MCUCSR,6);
	MCUCSR|=(EXTI2_Sense<<6);
	/*Enable PIE INT2*/
	SET_BIT(GICR,5);
}

void EXTI_voidINT0_Disable(void)
{
	/*DISABLE PIE INT0*/
	CLR_BIT(GICR,6);

}
void EXTI_voidINT1_Disable(void)
{
	/*DISABLE PIE INT1*/
	CLR_BIT(GICR,7);

}

void EXTI_voidINT2_Disable(void)
{
	/*DISABLE PIE INT2*/
	CLR_BIT(GICR,5);

}



void EXTI0_voidSet_SenseControl (EXTI01_Sense Copy_EXTI01_Sense_SenseControl)
{
	/*Init MCUCR*/
	MCUCR&=0xFC;
	/*select Sense Control*/
	MCUCR|=Copy_EXTI01_Sense_SenseControl;
}
void EXTI1_voidSet_SenseControl (EXTI01_Sense Copy_EXTI01_Sense_SenseControl)
{
	/*Init MCUCR*/
	MCUCR&=0xF3;
	/*select Sense Control*/
	MCUCR|=(Copy_EXTI01_Sense_SenseControl<<2);
}
void EXTI2_voidSet_SenseControl (EXTI_2_Sense Copy_EXTI2_Sense_SenseControl)
{
	/*select Sense Control (Falling edge)*/
	CLR_BIT(MCUCSR,6);
	MCUCSR|=(Copy_EXTI2_Sense_SenseControl<<6);
}

void EXTI0_voidSet_CallbackFunction (void (*Copy_EXTI0Callback_Function)(void))
{
	EXTI0Callback_Function=Copy_EXTI0Callback_Function;
}
void EXTI1_voidSet_CallbackFunction (void (*Copy_EXTI1Callback_Function)(void))
{
	EXTI1Callback_Function=Copy_EXTI1Callback_Function;
}
void EXTI2_voidSet_CallbackFunction (void (*Copy_EXTI2Callback_Function)(void))
{
	EXTI2Callback_Function=Copy_EXTI2Callback_Function;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	EXTI0Callback_Function();
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	EXTI1Callback_Function();
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	EXTI2Callback_Function();
}

