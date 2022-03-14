/*
 * GccApplication4.c
 *
 * Created: 2/1/2020 10:07:41 PM
 * Author : el_lu
 */
#define F_CPU 1000000ul
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
int DATA;
	DDRB|=(1<<2);
	TCCR1A=0b00100010;
	TCCR1B=0b00001001;

	DDRD|=(1<<6);
	TCCR0A=0b10000001;
	TCCR0B=0b00000001;
	
	
	ADMUX=0b01000101;
	ADCSRA=0b11000011;
	DIDR0|=(1<<3);
    /* Replace with your application code */
    while (1)
    {
		ADCSRA|=(1<<ADEN)|(1<<ADSC);
		while(ADCSRA&(1<<ADSC)){}
		ADCSRA&=~(1<<ADEN);
	    DATA=ADC;
		_delay_ms(200);
		OCR1B=DATA*0.7;
		OCR0A=DATA*0.7;
		
    }
}

