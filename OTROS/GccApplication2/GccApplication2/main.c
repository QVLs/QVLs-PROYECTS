/*
 * GccApplication2.c
 *
 * Created: 7/2/2019 2:43:57 PM
 * Author : el_lu
 */ 
#define TIMER_RETARDO_TIMER1_EMULATE_DELAY 25000
#include <avr/io.h>
#include "avr/i2c.h"
#include "avr/SENSOR_CONTROL_AVR.h"
#include "avr/SENSOR_TEMPERATURA_DS1621_AVR.h"

int main(void)
{
	DDRD=0xff;
    /* Replace with your application code */
    while (1) 
    {
	PORTD|=(PORTD7<<1);
	PAUSE_FLUJO(TIMER_RETARDO_TIMER1_EMULATE_DELAY,BIT1,BIT0,BIT0);
	PORTD&=~(PORTD7<<1);
		
    }
}

