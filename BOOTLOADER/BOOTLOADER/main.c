/*
 * BOOTLOADER.c
 *
 * Created: 7/12/2020 8:41:55 PM
 * Author : el_lu
 */

#define F_CPU 10000000L
#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
DDRC=0x01;
while(1){
PORTC^=0x01;
_delay_ms(10);
asm{
	
	
	
}
asm("jmp 0x0004");
    /* Replace with your application code */
	
	
}}

