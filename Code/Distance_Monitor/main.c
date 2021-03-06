 /******************************************************************************
 *
 * Module: Main Application
 *
 * File Name: main.c
 *
 * Description: Source file for the application's implementation
 *
 * Author: Ahmed Alaa
 *
 *******************************************************************************/

#define F_CPU 8000000UL

#include "HCSR04_ultrasonic_sensor.h"
#include "lcd.h"
#include "util/delay.h"
#include "std_types.h"
#include "common_macros.h"
#include "avr/io.h"

int main(void)
{
	/* Setup Configurations */
	SREG |= (1 << 7);
	register volatile uint16 distance = 0;
	LCD_init();
	LCD_displayString("Distance = ");
	LCD_moveCursor(0, 14);
	LCD_displayString("cm");
	Ultrasonic_init();

	/* Super Loop */
	while(1)
	{
		distance = Ultrasonic_readDistance();
		_delay_ms(10);

		LCD_moveCursor(0, 11);
		LCD_intgerToString(distance);
	}
}
