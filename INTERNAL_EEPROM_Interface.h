/*
 * INTERNAL_EEPROM_Interface.h
 *
 *  Created on: Oct 21, 2021
 *      Author: msqotb
 */

#ifndef INTERNAL_EEPROM_INTERFACE_H_
#define INTERNAL_EEPROM_INTERFACE_H_

void INTERNAL_EEPROM_voidWriteByte (u16 Copy_u8Address , u8 Copy_u8DataByte);
u8 INTERNAL_EEPROM_voidReadByte (u16 Copy_u8Address);
void INTERNAL_EEPROM_SET_CallbackFunction(void(*Copy_P_Fun_CallbackFunction)(void));


#endif /* INTERNAL_EEPROM_INTERFACE_H_ */
