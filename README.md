# Battery-state-of-charge
This project is about system calculates the SoC by using current integration method which measure the current passing through current sensor while charging or discharging the battery and then integrating it in a time.
The system based on Atmega32 microcontroller with software architecture in the picture attached with this project. 
EEPROM is included in the system to save the previous value of SoC after restarting the system and calculate the new state based on the previous one.
Timer (CTC Mode) and interrupt are used to return the number of milliseconds passed since the MCU began running the current program.
