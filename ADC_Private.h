/*
 * ADC_Private.h
 *
 *  Created on: Sep 19, 2021
 *      Author: msqotb
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADC			*((volatile u16*)0x24)
#define SFIOR		*((volatile u8*)0x50)

/*  Left OR Right adjust */
#define R_Adjust	0
#define L_Adjust	1

u8 LOC_ADC_InterruptFlag=0;

#define ADC_RESLOUTION_8BIT		0
#define ADC_RESLOUTION_10BIT	1




/*ADC Interrupt Flag bit number in ADCSRA register*/
#define  ADC_Interrupt_Flag_BIT		4

#endif /* ADC_PRIVATE_H_ */
