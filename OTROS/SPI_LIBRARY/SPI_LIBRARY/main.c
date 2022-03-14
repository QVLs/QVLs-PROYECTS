/*
 * SPI_LIBRARY.c
 *
 * Created: 4/10/2020 5:36:06 AM
 * Author : el_lu
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/SPI_INTERRUP.h>

 char S=0xff;
ISR(INT0_vect){



}


int main(void){
/*DDRB=0b1111011;*/
SPI_Slave_Init();
// cli();
// EICRA=0b00000010;
// EIMSK=0b00000001;
// EIFR =0b00000000;
// sei();




	while (1){
	S=SPI_RECEIVE_MODE_Slave_();
if(S==0x02){
DDRC=0b0101010;
PORTC=0b0101010;
}
	

	}
}

