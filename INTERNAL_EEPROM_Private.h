/*
 * INTERNAL_EEPROM_Private.h
 *
 *  Created on: Oct 21, 2021
 *      Author: msqotb
 */

#ifndef INTERNAL_EEPROM_PRIVATE_H_
#define INTERNAL_EEPROM_PRIVATE_H_

#define EEAR	*((volatile u16*)0x3E)
#define SPMCR	*((volatile u8*)0x57)
#define EECR	*((volatile u8*)0x3C)
#define EEDR	*((volatile u8*)0x3D)

#define INTERNAL_EEPROM_INTERRUPT_ENABLE	1
#define INTERNAL_EEPROM_INTERRUPT_DISABLE	0

#endif /* INTERNAL_EEPROM_PRIVATE_H_ */
