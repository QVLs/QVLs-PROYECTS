/*
 * GENERATOR_C.c
 *
 * Created: 7/23/2020 9:07:38 AM
 * Author : LUIS_QV
 */

#include <avr/io.h>
void _FLUJO(uint8_t ,uint8_t );
void _FLUJO(uint8_t DELAY,uint8_t REGISTRE){
uint8_t TEMP=DELAY;
TCCR0B=REGISTRE;
TCNT0=0;
while((TCNT0<TEMP)){}
TCNT1=0;}
int main(void)
{
/* Replace with your application code */
DDRD=0x01;
while (1){
PORTD=0x01;
_FLUJO(100,0x05);
PORTD=0x00;
_FLUJO(100,0x05);
}
}

