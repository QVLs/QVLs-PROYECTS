/*
 * PWM AVR.c
 *
 * Created: 7/3/2019 10:13:05 AM
 * Author : el_lu
 */ 
#define F_CPU 8000000ul
#include <avr/io.h>


int main(void)
{
DDRD|=(1<<3);
TCCR2A=0b00100011;
TCCR2B=0b00000001;
OCR2B=127;

    while (1) 
    {

		
    }
}

