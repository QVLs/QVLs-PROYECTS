#ifndef SPI_QVL
#define SPI_QVL
#include <avr/interrupt.h>
#include <avr/io.h>
/*#include <LIB/LIBRERIA_DELAY_QVL.h>*/
/*PROTOTIPOS DE FUNCIONES*/
void SPI_MASTER_INIT(void);
void SPI_STOP(void);
void SPI_MASTER_TRANSMITION_8_BITS(char);
void SPI_MASTER_TRANSMITION_16_BITS( int16_t);
void SPI_MASTER_INIT_INTERRUPTION(void);
void SPI_Slave_Init_Interrupt(void);
void SPI_Slave_Init(void);
char SPI_RECEIVE_MODE_MASTER_(void);
char SPI_RECEIVE_MODE_Slave_(void);
int16_t SPI_RECEIVE_MODE_SLAVE_16BITS_(void);
int16_t SPI_RECEIVE_MODE_MASTER_16BITS_(void);
/*PROTOTIPOS DE FUNCIONES*/

/*ESTA FUNCION SE ENCARGA DE DETENER LA COMUNICACION SPI*/
void SPI_STOP(void){
DDRB=0b00000000;
SPCR=0b00000000;}
/*------------------------------------------------------*/

/*ESTA FUNCION SE ENCARGA DE INICIAR LA COMUNICACION SPI
A DEMAS DE HABILITAR EL LAS INTERRUPCION POR CADA
 TRANSFERENCIA QUE SE COMPLETE
ISR(SPI_STC_vect){
	//ESTA FUNCION SE EJECUTA INMEDIATAMENTESE
	//TERMINE LA LA TRANSFERNCIA DE DATOS DEL
	//SPI SEA ESTA DE ENVIO O RECEPCION
}*/

void SPI_MASTER_INIT_INTERRUPTION(void){
sei();
DDRB=(1<<DDB3)|(1<<DDB5)|(1<<DDB2);
/*SPCR|=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);*/
SPCR=0b11010001;}
/*------------------------------------------------------*/


/*ESTA FUNCION SE ENCARGA DE INICIAR LA COMUNICACION SPI*/
void SPI_MASTER_INIT(void){
cli();
DDRB=(1<<DDB3/*MOSI*/)|(1<<DDB5/*SCKL*/)|(1<<DDB2/*SS*/);
SPCR=0b01010001;}
/*------------------------------------------------------*/


/*ESTA FUNCION SE ENCARGA DE TRANSFERIR 1 bytes DE DATOS DESDE EL MAESTRO AL ESCLAVO */
void SPI_MASTER_TRANSMITION_8_BITS(char DATE){
SPDR=DATE;
while(!(SPSR&(1<<SPIF)));}
/*------------------------------------------------------*/

/*ESTA FUNCION SE ENCARGA DE TRANSFERIR 1 bytes DE DATOS DESDE EL MAESTRO AL ESCLAVO */
void SPI_MASTER_TRANSMITION_16_BITS( int16_t DATE){
SPDR=(DATE>>8);
while(!(SPSR&(1<<SPIF)));
SPDR=DATE;
while(!(SPSR&(1<<SPIF)));}
/*------------------------------------------------------*/

/*ESTA FUNCION SE ENCARGA DE INICIALIZAR EL MICRO
CONTROLADOR EN EL MODO ESCLAVO MAS LA ACTIVACION
DE LAS INTERRUPCIONES CADA VES QUE COMPLETA UNA
TRANSFERENCIA DE DATOS RECIBIDOS*/
void SPI_Slave_Init_Interrupt(void){sei();
DDRB=(1<<DDB4/*MISO*/);
SPCR|=(1<<SPE)|(1<<SPIE);}
/*------------------------------------------------------*/

/*ESTA FUNCION SE ENCARGA DE INICIALIZAR EL MICRO
CONTROLADOR EN EL MODO ESCLAVO*/
void SPI_Slave_Init(void){
DDRB=(1<<DDB4/*MISO*/);
SPCR=(1<<SPE);}
/*------------------------------------------------------*/


/*ESTA FUNCION SE ENCARGA DE RECIBIR 1bytes DE DATOS CON EL MICRO
 CONTROLADOR EN EL MODO ESCLAVO*/
char SPI_RECEIVE_MODE_Slave_(void){
while(!(SPSR&(1<<SPIF)));
return SPDR;}
/*------------------------------------------------------*/




/*ESTA FUNCION SE ENCARGA DE RECIBIR 2bytes DE DATOS CON EL MICRO
 CONTROLADOR EN EL MODO ESCLAVO*/
int16_t SPI_RECEIVE_MODE_SLAVE_16BITS_(void){
	int16_t DATA_16_BITS;
	SPDR=0xff;
	while(!(SPSR&(1<<SPIF)));
	DATA_16_BITS=(SPDR);
	DATA_16_BITS=(DATA_16_BITS<<8);
	SPDR=0xff;
	while(!(SPSR&(1<<SPIF)));
	DATA_16_BITS|=(SPDR);
return DATA_16_BITS;}
/*------------------------------------------------------*/




/*ESTA FUNCION SE ENCARGA DE RECIBIR 1bytes DE DATOS CON EL MICRO
 CONTROLADOR EN EL MODO MAESTRO */
char SPI_RECEIVE_MODE_MASTER_(void){
	SPDR=0xff;
	while(!(SPSR&(1<<SPIF)));
return SPDR;}
/*------------------------------------------------------*/




/*ESTA FUNCION SE ENCARGA DE RECIBIR LOS DATOS CON EL MICRO
 CONTROLADOR EN EL MODO MAESTRO*/
int16_t SPI_RECEIVE_MODE_MASTER_16BITS_(void){
	int16_t DATA_16_BITS;
	SPDR=0xff;
	while(!(SPSR&(1<<SPIF)));
	DATA_16_BITS=(SPDR);
	DATA_16_BITS=(DATA_16_BITS<<8);
	SPDR=0xff;
	while(!(SPSR&(1<<SPIF)));
	DATA_16_BITS|=(SPDR);
return DATA_16_BITS;}
/*------------------------------------------------------*/
#endif