/*
 * HABILITACION_DE_INTERRUPCIONES_GLOBALES.c
 *
 * Created: 4/10/2020 2:24:49 AM
 * Author : el_lu
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/SENSOR_CONTROL_AVR.h>
#include <avr/interrupt.h>
void SPI_MASTER_INIT(void);
void SPI_MASTER_TRANSMITION(char);
void SPI_MASTER_INIT_INTERRUPTION(void);
void SPI_Slave_Init_Interrupt(void);
void SPI_Slave_Init(void);
char SPI_Slave_RECEIVE(void);


ISR(SPI_STC_vect){
	
	
	
}

int main(void)
{
DDRC|=0b1111111;

PAUSE_FLUJO(2000,1,0,1);
SPI_MASTER_INIT();
SPI_MASTER_TRANSMITION(0x8f);
    while (1)
    {


    }
}

void SPI_MASTER_INIT_INTERRUPTION(void){
sei();
	DDRB|=(1<<DDB3)|(1<<DDB5);
	SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);}

void SPI_MASTER_INIT(void){
DDRB|=(1<<DDB3)|(1<<DDB5);
SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0);}

void SPI_MASTER_TRANSMITION(char DATE){
SPDR=DATE;
while(!(SPSR&(1<<SPIF)));
}

void SPI_Slave_Init_Interrupt(void){
sei();
DDRB=(1<<DDB4);
SPCR=(1<<SPE);}

void SPI_Slave_Init(void){
		DDRB=(1<<DDB4);
		SPCR=(1<<SPE);}

char SPI_Slave_RECEIVE(void){
while(!(SPSR&(1<<SPIF)));
return SPDR;}



