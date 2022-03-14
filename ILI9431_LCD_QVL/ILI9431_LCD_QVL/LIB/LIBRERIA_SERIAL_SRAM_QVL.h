#ifndef SRAM_SERIAL_QVL_LIBRABRY
#define SRAM_SERIAL_QVL_LIBRABRY

#include <avr/interrupt.h>
#include "LIBRERIA_DELAY_QVL.h"

#define _BYTEMODE_MEMORY_SPI_ 0x00
#define _PAGEMODE_MEMORY_SPI_ 0x80
#define _SEQUENTIALMODE_MEMORY_SPI_ 0x40
#define _REGISTER_MODE_MEMORY_READ_ 0x05
#define _REGISTER_MODE_MEMORY_WRITE_ 0x01
#define _WRITE_MEMORY_SPI_ 0x02
#define _READ_MEMORY_SPI_ 0x03

/*PROTOTIPOS DE FUNCIONES*/
int16_t READ_MEMORY_16_BIT(int8_t,int16_t);
int8_t READ_MEMORY_8_BIT(int8_t,int16_t);
void WRITE_MEMORY_8_BITS(int8_t,int16_t,int8_t DATE);
void WRITE_MEMORY_16_BITS(int8_t,int16_t,int16_t DATE);
void WRITE_MEMORY_8_BITS_MODE_REGISTER(int8_t COMAND,int8_t MODE_REGISTER);
int8_t READ_MEMORY_8_BITS_MODE_REGISTER(int8_t COMAND);
/*PROTOTIPOS DE FUNCIONES*/

/*ESTAS DOS RUTINAS TIENEN LA FUNCION DE ESCRIBIR Y LEER EL REGISTRO DE CONTROL DE LA MEMORIA */
/* DEFINICIONES IMPORTANTES
#define _BYTEMODE_MEMORY_SPI_ 0x00			 DEFINIMOS EL MODO (R/W) A 8bits(1bytes)
#define _PAGEMODE_MEMORY_SPI_ 0x80			 DEFINIMOS EL MODO (R/W) A 16bits(2bytes)
#define _SEQUENTIALMODE_MEMORY_SPI_ 0x40     DEFINIMOS EL MODO (R/W) A (n)bits ((n)bytes)
#define _REGISTER_MODE_MEMORY_READ_ 0x05	 DEFINIMOS EL COMANDO PARA LEER EL REGISTRO DE CONTROL DE LA MEMORIA
#define _REGISTER_MODE_MEMORY_WRITE_ 0x01    DEFINIMOS EL COMANDO PARA ESCRIBIR EL REGISTRO DE CONTROL DE LA MEMORIA
MODE REGISTER=[x x 0 0 0 0 0 0 ]; DONDE LAS (x) SON LOS VALORES A MODIFICAR PARA ELEGIR ENTRE LOS TRES MODOS DE TRABAJO*/
void WRITE_MEMORY_8_BITS_MODE_REGISTER(int8_t COMAND,int8_t MODE_REGISTER){
PORTC^=(1<<PORTC2);/* SELECCIONA EL ESCLAVO ASOCIADO A ESTE PIN*/
PAUSE_FLUJO(0,1,0,1);
SPI_MASTER_TRANSMITION_8_BITS(COMAND);
SPI_MASTER_TRANSMITION_8_BITS(MODE_REGISTER);
PORTC^=(1<<PORTC2);}
int8_t READ_MEMORY_8_BITS_MODE_REGISTER(int8_t COMAND){
int8_t MEMORY_DATA=0x00;
PORTC^=(1<<PORTC2);
PAUSE_FLUJO(0,1,0,1);
SPI_MASTER_TRANSMITION_8_BITS(COMAND);
MEMORY_DATA=SPI_RECEIVE_MODE_MASTER_();
PORTC^=(1<<PORTC2);
return MEMORY_DATA;}
/*ESTAS DOS RUTINAS TIENEN LA FUNCION DE ESCRIBIR Y LEER EL REGISTRO DE CONTROL DE LA MEMORIA */

/*ESTAS FUNCIONES NOS SIRVEN PARA LA LECTURA Y ESCRITURA DE DATOS A LA MEMORIA SRAM TRABAJA ENVIANDO 1 byte*/
int8_t READ_MEMORY_8_BIT(int8_t COMAND,int16_t ADDRES){
int8_t MEMORY_DATA=0x00;
PORTC^=(1<<PORTC2);/* SELECCIONA EL ESCLAVO ASOCIADO A ESTE PIN*/
PAUSE_FLUJO(0,1,0,1);
SPI_MASTER_TRANSMITION_8_BITS(COMAND);
SPI_MASTER_TRANSMITION_16_BITS(ADDRES);
MEMORY_DATA=SPI_RECEIVE_MODE_MASTER_();
PORTC^=(1<<PORTC2);
return MEMORY_DATA;}
void WRITE_MEMORY_8_BITS(int8_t COMAND,int16_t ADDRES,int8_t DATE){
PORTC^=(1<<PORTC2);/* SELECCIONA EL ESCLAVO ASOCIADO A ESTE PIN*/
PAUSE_FLUJO(0,1,0,1);
SPI_MASTER_TRANSMITION_8_BITS(COMAND);
SPI_MASTER_TRANSMITION_16_BITS(ADDRES);
SPI_MASTER_TRANSMITION_8_BITS(DATE);
PORTC^=(1<<PORTC2);}
/*EJEMPLOS DE USO PARA ESCRIRURA Y LECTURA EN LA POSICION de 2bytes(0x0000) DE LA MEMORIA
WRITE_MEMORY_8_BITS(_WRITE_MEMORY_SPI_,0,0xf3);
READ_MEMORY_8_BIT(_READ_MEMORY_SPI_,0);
EJEMPLOS DE USO*/
/*ESTAS FUNCIONES NOS SIRVEN PARA LA LECTURA Y ESCRITURA DE DATOS A LA MEMORIA SRAM TRABAJA ENVIANDO 1 byte*/


/*ESTAS FUNCIONES NOS SIRVEN PARA LA LECTURA Y ESCRITURA DE DATOS A LA MEMORIA SRAM TRABAJA ENVIANDO PAGINAS(2 bytes)*/
void WRITE_MEMORY_16_BITS(int8_t COMAND,int16_t ADDRES,int16_t DATE){
PORTC^=(1<<PORTC2);/* SELECCIONA EL ESCLAVO ASOCIADO A ESTE PIN*/
SPI_MASTER_TRANSMITION_8_BITS(COMAND);
SPI_MASTER_TRANSMITION_16_BITS(ADDRES);
SPI_MASTER_TRANSMITION_8_BITS(DATE>>8);
SPI_MASTER_TRANSMITION_8_BITS(DATE);
PORTC^=(1<<PORTC2);}
int16_t READ_MEMORY_16_BIT(int8_t COMAND,int16_t ADDRES){
int16_t MEMORY_DATA=0x0000;
PORTC^=(1<<PORTC2);/* SELECCIONA EL ESCLAVO ASOCIADO A ESTE PIN*/
SPI_MASTER_TRANSMITION_8_BITS(COMAND);
SPI_MASTER_TRANSMITION_16_BITS(ADDRES);
MEMORY_DATA=SPI_RECEIVE_MODE_MASTER_();
MEMORY_DATA=(MEMORY_DATA<<8);
MEMORY_DATA=MEMORY_DATA|SPI_RECEIVE_MODE_MASTER_();
PORTC^=(1<<PORTC2);
return MEMORY_DATA;}
/*EJEMPLOS DE USO PARA ESCRIRURA Y LECTURA A 2bytes(PAGINA) DE LA MEMORIA SRAM
WRITE_MEMORY_16_BITS(_WRITE_MEMORY_SPI_,0x00000,0xffee);
READ_MEMORY_16_BIT(_READ_MEMORY_SPI_,0);
EJEMPLOS DE USO*/
/*ESTAS FUNCIONES NOS SIRVEN PARA LA LECTURA Y ESCRITURA DE DATOS A LA MEMORIA SRAM TRABAJA ENVIANDO PAGINAS(2 bytes)*/
#endif
