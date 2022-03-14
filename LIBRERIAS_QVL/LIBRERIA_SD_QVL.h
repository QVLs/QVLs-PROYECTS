#ifndef  SD_QVL_LIBRARY
#define SD_QVL_LIBRARY

#include <avr/io.h>
#include "LIBRERIA_DELAY_QVL.h"

/*PROTOTIPOS DE FUNCIONES*/
void WRITE_MEMORY_SD_MMC(int8_t[],int16_t,int16_t,int16_t);
void READ_MEMORY_SD_MMC(int16_t,int16_t,int16_t);
void INT_SD_MMC(void);
void RESET_SD_MMC(void);
void BLOCK_MEMORY_SET_SD_MMC(void);
/*PROTOTIPOS DE FUNCIONES*/

void RESET_SD_MMC(void){
/*CMD0*/
/*40 00 00 00 95*/
for (int i=0;i!=1000;i++)
{PAUSE_FLUJO(0,1,0,1);
PORTC^=(0b0000001<<PORTC3);}
PORTC^=(1<<PORTC0);
/*RESET POR SOFTWARE DEL LA TARJETA SD*/
SPI_MASTER_TRANSMITION_8_BITS(0b01000000);
SPI_MASTER_TRANSMITION_16_BITS(0b0000000000000000);
SPI_MASTER_TRANSMITION_16_BITS(0b0000000000000000);
SPI_MASTER_TRANSMITION_8_BITS(0b10010101);
SPI_RECEIVE_MODE_MASTER_16BITS_();
PORTC^=(1<<PORTC0);}


void INT_SD_MMC(void){
/*CMD1*/
/*41 00 00 00 00 ff*/
PORTC^=(1<<PORTC0);
/*INICIALISCION DE LA TARJETA SD*/
SPI_MASTER_TRANSMITION_8_BITS(0b01000001);
SPI_MASTER_TRANSMITION_16_BITS(0b0000000000000000);
SPI_MASTER_TRANSMITION_16_BITS(0b0000000000000000);
SPI_MASTER_TRANSMITION_8_BITS(0b11111111);
SPI_RECEIVE_MODE_MASTER_16BITS_();
PORTC^=(1<<PORTC0);}


void BLOCK_MEMORY_SET_SD_MMC(void){
/*CMD0*/
/*50 00 000 00 08 ff*/
PORTC^=(1<<PORTC0);
/*CONFIGURACION DEL TAMA�O DEL BLOQUE DE MEMORIA QUE SE USARA PARA GUARDAR DATOS VALOR ES DE DEFAULT 512 bytes*/
SPI_MASTER_TRANSMITION_8_BITS(0b01010000);
SPI_MASTER_TRANSMITION_16_BITS(0);
SPI_MASTER_TRANSMITION_16_BITS(8);
SPI_MASTER_TRANSMITION_8_BITS(0b11111111);
SPI_RECEIVE_MODE_MASTER_16BITS_();
PORTC^=(1<<PORTC0);}


void WRITE_MEMORY_SD_MMC(int8_t DATA[],int16_t longitud_de_bytes,int16_t CMD_ARGUMENT_MSB,int16_t CMD_ARGUMENT_LSB){
/*58 00 00 00 01 ff*/
PORTC^=(1<<PORTC0);
/*ESCRITURA DE DATOS A LA SD*/
SPI_MASTER_TRANSMITION_8_BITS(0b01011000);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_MSB);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_LSB);
SPI_MASTER_TRANSMITION_8_BITS(0b11111111);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0x00);
SPI_MASTER_TRANSMITION_8_BITS(0xfe);
for(int i=0;i!=longitud_de_bytes;i++){
SPI_MASTER_TRANSMITION_8_BITS(DATA[i]);}
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0x05);
PORTC^=(1<<PORTC0);}


void READ_MEMORY_SD_MMC(int16_t longitud_de_bytes,int16_t CMD_ARGUMENT_MSB,int16_t CMD_ARGUMENT_LSB){
/*51 00 00 00 01 ff*/
int8_t READ_DATA[longitud_de_bytes];
PORTC^=(1<<PORTC0);
/*LECTURA DE DATOS A LA SD*/
SPI_MASTER_TRANSMITION_8_BITS(0b01010001);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_MSB);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_LSB);
SPI_MASTER_TRANSMITION_8_BITS(0b11111111);
SPI_RECEIVE_MODE_MASTER_16BITS_();
SPI_MASTER_TRANSMITION_8_BITS(0xfe);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
for(int i=0;i!=longitud_de_bytes;i++){
READ_DATA[longitud_de_bytes]=SPI_RECEIVE_MODE_MASTER_();}
PORTC^=(1<<PORTC0);}
#endif