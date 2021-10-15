/*
 * Temperature_Sensor_Interface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: msqotb
 */

#ifndef TEMPERATURE_SENSOR_INTERFACE_H_
#define TEMPERATURE_SENSOR_INTERFACE_H_

extern u8 TOVFLAG;
void TemperatureSensor_voidInit(void);
u16 TemperatureSensor_u8GetTempValue (void);
u16 TemperatureSensor_u8GetTempAverage (void);


#endif /* TEMPERATURE_SENSOR_INTERFACE_H_ */
