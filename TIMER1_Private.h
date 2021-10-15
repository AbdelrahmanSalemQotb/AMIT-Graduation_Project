/*
 * TIMER1_Private.h
 *
 *  Created on: Sep 25, 2021
 *      Author: msqotb
 */

#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
/* REGISTERS */
#define TCCR1A	*((volatile u8*)0x4F)
#define TCCR1B	*((volatile u8*)0x4E)
#define TIMSK	*((volatile u8*)0x59)
#define	OCR1A	*((volatile u16*)0x4A)
#define	OCR1B	*((volatile u16*)0x48)
#define	ICR1	*((volatile u16*)0x46)
#define TCNT1	*((volatile u16*)0x4C)


/* Timer1 Mode options */
#define TIMER1_MODE_NORMAL										0
#define TIMER1_MODE_PWM_PHASECORRECT_8BITS						1
#define TIMER1_MODE_PWM_PHASECORRECT_9BITS						2
#define TIMER1_MODE_PWM_PHASECORRECT_10BITS						3
#define TIMER1_MODE_CTC_TOP_OCR1A								4
#define TIMER1_MODE_PWM_FAST_8BITS								5
#define TIMER1_MODE_PWM_FAST_9BITS								6
#define TIMER1_MODE_PWM_FAST_10BITS								7
#define TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_TOP_ICR1		8
#define TIMER1_MODE_PWM_PHASE_FREQUENCY_CORRECT_TOP_OCR1A		9
#define TIMER1_MODE_PWM_PHASECORRECT_TOP_ICR1					10
#define TIMER1_MODE_PWM_PHASECORRECT_TOP_OCR1A					11
#define TIMER1_MODE_CTC_TOP_ICR1								12
#define TIMER1_MODE_PWM_FAST_TOP_ICR1							14
#define TIMER1_MODE_PWM_FAST_TOP_OCR1A							15

/* prescaler select */
#define TIMER1_BITMASK_PRESCALER	0xF8

#define TIMER1_NO_PRESCALER				1
#define TIMER1_8_PRESCALER				2
#define TIMER1_64_PRESCALER				3
#define TIMER1_256_PRESCALER			4
#define TIMER1_1024_PRESCALER			5

#define TIMER1_EXTERNAL_SOURCE_FALLING	6
#define TIMER1_EXTERNAL_SOURCE_RISING	7

/*OC1 CONFIG*/
#define	OC1_PIN_DISCONNECTED	0
#define OC1_PIN_TOGGLE			1
#define	OC1_PIN_CLEAR			2
#define OC1_PIN_SET				3

/* ICU PIN */
#define ICU_PORT_NUMBER		DIO_PORTD
#define ICU_PIN_NUMBER		DIO_PIN6
/* ICU PIN STATE */
#define	FLOATING	0
#define PULL_UP		1



#endif /* TIMER1_PRIVATE_H_ */
