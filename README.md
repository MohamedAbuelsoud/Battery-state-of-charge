# Battery-state-of-charge
This project is used to get the state of charge (SOC) for a lithium-ion battery based on the current integration method which measure the current through a wire while charging or discharging the battery and then integrating the measurements.
The system was implemented to Atmega32 microcontroller with software architecture attached to this project.
EEPROM was included in the project to save the readings and recover them after restarting the system. 
Timer (CTC Mode) and interrupts were used to return the number of milliseconds passed since the MCU began running the program.
