/*
 * Test_millies.c
 *
 * Created: 5/6/2019 9:36:08 PM
 *  Author: Mohamed Alaa
 */ 


//#include <stdlib.h>
#include "adc.h"
#include "lcd.h"
#include "millies.h"
#include "eeprom.h"
#include "stdlib.h"

uint32 milliseconds_current ;
uint32 milliseconds_previous ;
uint32 samples ;
uint32 sensor ;
uint8 soc ;
uint32 ADC_value;

void main(void)
{
	
	LCD_init();                                                                  // initialize LCD driver
	ADC_init();                                                                  // initialize ADC driver 
	LCD_clearScreen();                                                           // clear LCD at the beginning.
    LCD_displayString("The state of  ");
	LCD_goToRowColumn(1,0);
	LCD_displayString("charge =   ");

	  millis_int();

		


	
	while(1)
	{
		
		milliseconds_current = millis();
                                      
	    ADC_value = ADC_readChannel(0);
		sensor = (ADC_value -516 ) * 6.25 ;                                 // to offset and scale the ADC reading 
		
		samples= EEPROM_read_int(0x00);
		
		samples += sensor * (milliseconds_current-milliseconds_previous) ;

      	EEPROM_write_int(0x00,samples);
		
		soc = samples / 288;                                               // calculating state of charge for 8 A.H battery. 
	
		LCD_goToRowColumn(1,11);
		LCD_intgerToString(soc);
		
		
	     
	     milliseconds_previous =milliseconds_current ;
	
	}		    
					 
					  }
					
					

		
	 
	 

	







	
	