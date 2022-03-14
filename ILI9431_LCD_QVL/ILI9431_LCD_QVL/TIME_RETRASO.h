#ifndef DELAY_QVL
#define DELAY_QVL
#include <avr/io.h>
void PAUSE_FLUJO(uint16_t DELAY,int CS_12,int CS_11,int CS_10);
void PAUSE_FLUJO(uint16_t DELAY,int CS_12,int CS_11,int CS_10){
	int C_12=CS_12;
	int C_11=CS_11;
	int C_10=CS_10;
	int TEMP=DELAY;
	if ((C_12==0)&&(C_11==1)&&(C_10==1)){TCCR1B=0x03;}else{
	if((C_12==0)&&(C_11==1)&&(C_10==0)){TCCR1B=0x02;}else{
	if((C_12==1)&&(C_11==0)&&(C_10==1)){TCCR1B=0x05;}else{
	if((C_12==1)&&(C_11==1)&&(C_10==0)){TCCR1B=0x04;}else{
	if((C_12==0)&&(C_11==0)&&(C_10==1)){TCCR1B=0x01;}}}}}
	TCNT1=0;
	while((TCNT1<TEMP)){}
TCNT1=0;}
#endif


