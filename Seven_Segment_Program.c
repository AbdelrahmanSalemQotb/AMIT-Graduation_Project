/*
 * Seven_Segment_Program.c
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "Seven_Segment_Config.h"
#include "util/delay.h"
void SevenSegment_voidInitPins (void)
{
	DIO_u8SetPinDirection(SEVEN_SEGMENT_ENABLE2_PIN,SEVEN_SEGMENT_ENABLE_PORT,PIN_OUTPUT);
	DIO_u8SetPinDirection(SEVEN_SEGMENT_ENABLE1_PIN,SEVEN_SEGMENT_ENABLE_PORT,PIN_OUTPUT);
	DIO_u8SetNippleBitsDirection(SEVEN_SEGMENT_DATA_PORT,SEVEN_SEGMENT_DATA_PINS_NIPPLE,0xFF);
}

void SevenSegment_voidSendNumber (u8 Copy_u8Number)
{
	u8 i;
	u8 temp1=0,temp2=0;
	temp1=(Copy_u8Number%10)|((Copy_u8Number%10)<<4);
	temp2=(Copy_u8Number/10)|((Copy_u8Number/10)<<4);

		for (i=0;i<2;i++)
		{
			if (0==i)
			{
				DIO_u8SetNippleBitsValue(SEVEN_SEGMENT_DATA_PORT,SEVEN_SEGMENT_DATA_PINS_NIPPLE,temp2);
				DIO_u8SetPinValue(SEVEN_SEGMENT_ENABLE1_PIN,SEVEN_SEGMENT_ENABLE_PORT,PIN_HIGH);
				_delay_ms(5);
				DIO_u8SetPinValue(SEVEN_SEGMENT_ENABLE1_PIN,SEVEN_SEGMENT_ENABLE_PORT,PIN_LOW);

			}
			else
			{
				DIO_u8SetNippleBitsValue(SEVEN_SEGMENT_DATA_PORT,SEVEN_SEGMENT_DATA_PINS_NIPPLE,temp1);
				DIO_u8SetPinValue(SEVEN_SEGMENT_ENABLE2_PIN,SEVEN_SEGMENT_ENABLE_PORT,PIN_HIGH);
				_delay_ms(5);
				DIO_u8SetPinValue(SEVEN_SEGMENT_ENABLE2_PIN,SEVEN_SEGMENT_ENABLE_PORT,PIN_LOW);

			}
		}


}
void SevenSegment_voidDisable (void)
{
	DIO_u8SetNippleBitsValue(SEVEN_SEGMENT_DATA_PORT,SEVEN_SEGMENT_DATA_PINS_NIPPLE,0x00);
	DIO_u8SetPinValue(SEVEN_SEGMENT_ENABLE1_PIN,SEVEN_SEGMENT_ENABLE_PORT,PIN_LOW);

}

