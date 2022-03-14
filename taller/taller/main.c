/*
 * taller.c

 * Created: 6/19/2020 1:24:56 PM
 * Author : el_lu
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>
#define VEOLTAJE_MAXIMO_PERMITIDO_SENSOR_1 90

#define RESOLUTION0 0.175781 //0.0048875855
#define BIT0 0
#define BIT1 1

uint16_t VAR_REGISTRO_ADC1=0;
uint16_t VAR_VOLTAJE_ENTRADA1=0;

int LUIS1=1;


void CONTROL_CONVERSOR_ANLOGICO_DIGITAL();

uint16_t SENSOR1();
uint8_t TR,AUTO;
uint8_t RT;


uint16_t SENSOR1(){
	ADMUX=0x01;
	ADCSRA=(BIT1<<ADEN)|(BIT1<<ADSC);
	while(ADCSRA&(BIT1<<ADSC)){}
	ADCSRA&=~(BIT1<<ADEN);
	VAR_REGISTRO_ADC1=ADC;
	VAR_VOLTAJE_ENTRADA1=(uint16_t)VAR_REGISTRO_ADC1*RESOLUTION0;
	ADMUX&=(BIT0<<MUX0);
return	VAR_VOLTAJE_ENTRADA1;}

void CONTROL_CONVERSOR_ANLOGICO_DIGITAL(){
	DDRB=0b00000000;
DDRD=0b00001101;}



int main(void){
	
	CONTROL_CONVERSOR_ANLOGICO_DIGITAL();

	/*FUNCION QUE OPTIENE Y CONVIERTE LOS DATOS DEL VOLTAJE GENERADOS POR EL SENSOR1 */

	while (1){


		AUTO=PINB;

		if (AUTO==0x02){
			/***/

			while(SENSOR1()!=5){
			PORTD|=0b00001000;}
			PORTD&=~(0b00001000);



			_delay_ms(1000);
			while(!(SENSOR1()==151)){
			PORTD|=0b00000100;}
			PORTD&=~(0b00000100);

			_delay_ms(50);

			while(SENSOR1()!=5){
			PORTD|=0b00001000;}
		PORTD&=~(0b00001000);}


		else{
			TR=PINB;
			RT=PINB;

			if ((RT==0x08)&&!(TR==0x04))
			{PORTD|=0b00001000;
				}else{PORTD&=~(0b00001000);}

				_delay_ms(50);

				if ((TR==0x04)&&!(RT==0x08))
				{PORTD|=0b00000100;
					}else{PORTD&=~(0b00000100);}
				}}}

