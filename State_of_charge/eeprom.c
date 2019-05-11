/*
 * eeprom.c
 *
 * Created: 5/10/2019 1:00:39 PM
 *  Author: Mohamed Alaa
 */ 
/*
 * CFile1.c
 *
 * Created: 13/2/2019 12:17:21 AM
 *  Author: elkhedewy
 */ 
#include "eeprom.h"
void EEPROM_write(sint32 uiAddress, uint8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE));
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}
unsigned char EEPROM_read(sint32 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}
void EEPROM_write_int(sint32 uiAddress, sint32 uiData)
{
	char i;
	for(i = 0; i < 4; i++)
	{
		EEPROM_write(uiAddress+i, (uint8) (uiData>>(i*8)));
	}
}sint32 EEPROM_read_int(sint32 uiAddress)
{
	unsigned int result;
	char i;
	for(i = 0; i < 4; i++)
	{
		result+= EEPROM_read(uiAddress+i)<<(i*8);
	}
	return result;
}