/*
 * GccApplication1.c
 *
 * Created: 6/16/2019 5:36:23 PM
 * Author : el_lu
 */ 

#include <avr/io.h>
#include "avr/SENSOR_CONTROL_AVR.h"
#define TIMER_RETARDO_TIMER1_EMULATE_DELAY 200

int main(void)
{

	DDRD=0b10000000;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB|=(1<<PORTB7);
	
	
    }
}

