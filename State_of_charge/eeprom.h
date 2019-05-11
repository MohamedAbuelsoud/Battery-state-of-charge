/*
 * eeprom.h
 *
 * Created: 5/10/2019 1:00:53 PM
 *  Author: Mohamed Alaa
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_


#include "micro_config.h"
#include "std_types.h"
 
 void EEPROM_write(sint32 uiAddress,uint8 ucData);
 unsigned char EEPROM_read(sint32 uiAddress);
 void EEPROM_write_int(sint32 uiAddress, sint32 uiData);
sint32 EEPROM_read_int(sint32 uiAddress);


#endif /* EEPROM_H_ */