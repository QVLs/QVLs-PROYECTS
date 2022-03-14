/*
 * GccApplication1.c
 *
 * Created: 6/16/2019 5:36:23 PM
 * Author : el_lu
 */ 

#include <avr/io.h>
//#include "avr/delay.h"
#define F_CPU 8000000UL
#define BIT1 1
#define BIT0 0


void PAUSE_FLUJO(uint16_t DELAY,int CS_12,int CS_11,int CS_10);


void PAUSE_FLUJO(uint16_t DELAY,int CS_12,int CS_11,int CS_10){
   int C_12=CS_12;
   int C_11=CS_11;
   int C_10=CS_10;
   int TEMP=DELAY;
   if ((C_12==BIT0)&&(C_11==BIT1)&&(C_10==BIT1)){TCCR1B=0x03;}else{
   if((C_12==BIT0)&&(C_11==BIT1)&&(C_10==BIT0)){TCCR1B=0x02;}else{
   if((C_12==BIT1)&&(C_11==BIT0)&&(C_10==BIT1)){TCCR1B=0x05;}else{
   if((C_12==BIT1)&&(C_11==BIT1)&&(C_10==BIT0)){TCCR1B=0x04;}else{
   if((C_12==BIT0)&&(C_11==BIT0)&&(C_10==BIT1)){TCCR1B=0x01;}}}}}
   /*INDICADOR DEL VALOR DE PRESCALER*/
   // if(TCCR1B&(BIT1<<CS12)){PORTB|=(BIT1<<PORTB4);}
   // if(TCCR1B&(BIT1<<CS11)){PORTB|=(BIT1<<PORTB5);}
   // if(TCCR1B&(BIT1<<CS10)){PORTB|=(BIT1<<PORTB6);}
   /*INDICADOR DEL VALOR DE PRESCALER*/
   TCNT1=0;
   while(TCNT1!=TEMP){}
TCNT1=0;}


int main(void)
{

 
   DDRD=0xFF;  
   DDRB=0x07; 
   DDRC=0x3F; 
    /* Replace with your application code */
    while (1) 
    {
  PORTD=0xFF;
  PORTC=0x3F;
  PORTB=0x07;
  //_delay_ms(1000);
  PAUSE_FLUJO(60000,0,1,0);
   PORTD=0x00;
   PORTC=0x00;
   PORTB=0x00;
  //_delay_ms(1000);
  PAUSE_FLUJO(25000,0,1,0);


    }
}
