#ifndef I2C_AVR_TEMP_SENSOR
#define I2C_AVR_TEMP_SENSOR
#define ADDRESS__W0 0x90
#define ADDRESS__R0 0x91
#define ADDRESS__W1 0x92
#define ADDRESS__R1 0x93
#define LEER_TEMPERATURA 0xAA
#define ACCESO_TEMPERATURE_ALTA 0xA1
#define ACCESO_TEMPERATURE_BAJA 0xA2
#define ACCESO_CONFIGURACION 0xAC
#define LEER_COUNTER 0xA8
#define LEER_SLOPE 0xA9
#define STAR_CONVERSION_TEMPERATURA 0xEE
#define STOP_CONVERSION_TEMPERATURA 0x22
/*uint8_t W;*/
void F_LEER_TEMPERATURA( char ADDRESS_W, char ADDRESS_R);
void F_ACCESO_TEMPERATURE_ALTA( char ADDRESS_W_R, char TEMPERATURA_H_PRIMER_BYTE, char TEMPERATURA_H_SEGUNDO_BYTE);
void F_ACCESO_TEMPERATURE_BAJA( char ADDRESS_W_R, char TEMPERATURA_L_PRIMER_BYTE, char TEMPERATURA_L_SEGUNDO_BYTE);
void F_ACCESO_CONFIGURACION( char ADDRESS_W_R, char BYTE_DE_CONFIGURACION);
void F_LEER_COUNTER( char ADDRESS_W_R);
void F_LEER_SLOPE( char ADDRESS_W_R);
void F_STAR_CONVERSION_TEMPERATURA( char ADDRESS_W_R);
void F_STOP_CONVERSION_TEMPERATURA( char ADDRESS_W_R);
void F_LEER_TEMPERATURA( char ADDRESS_W,  char ADDRESS_R){
/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W);
	ESPERA_I2C();
	WRITE_I2C(LEER_TEMPERATURA);
	ESPERA_I2C();
	START_COMUNICATION_I2C();
	WRITE_I2C(ADDRESS_R);
	ESPERA_I2C();	
	READ_I2C_ACK();
	ESPERA_I2C();
	READ_I2C_NACK();
    ESPERA_I2C();	
	/*--------------------------*/}
void F_ACCESO_TEMPERATURE_ALTA( char ADDRESS_W_R,char TEMPERATURA_H_PRIMER_BYTE,char TEMPERATURA_H_SEGUNDO_BYTE){
	/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W_R);
	ESPERA_I2C();
	WRITE_I2C(ACCESO_TEMPERATURE_ALTA);
	ESPERA_I2C();
	WRITE_I2C(TEMPERATURA_H_PRIMER_BYTE);
	ESPERA_I2C();
	WRITE_I2C(TEMPERATURA_H_SEGUNDO_BYTE);	
	ESPERA_I2C();
	/*--------------------------*/}
void F_ACCESO_TEMPERATURE_BAJA( char ADDRESS_W_R, char TEMPERATURA_L_PRIMER_BYTE, char TEMPERATURA_L_SEGUNDO_BYTE){
	/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W_R);
	ESPERA_I2C();
	WRITE_I2C(ACCESO_TEMPERATURE_BAJA);
	ESPERA_I2C();
	WRITE_I2C(TEMPERATURA_L_PRIMER_BYTE);
	ESPERA_I2C();
	WRITE_I2C(TEMPERATURA_L_SEGUNDO_BYTE);
	ESPERA_I2C();
	/*--------------------------*/}
void F_LEER_SLOPE( char ADDRESS_W_R){
	/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W_R);
	ESPERA_I2C();
	WRITE_I2C(LEER_SLOPE);
	ESPERA_I2C();
	/*--------------------------*/}
void F_LEER_COUNTER( char ADDRESS_W_R){
	/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W_R);
	ESPERA_I2C();
	WRITE_I2C(LEER_COUNTER);
	ESPERA_I2C();
	/*--------------------------*/}
void F_ACCESO_CONFIGURACION( char ADDRESS_W_R, char BYTE_DE_CONFIGURACION){
	/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W_R);
	ESPERA_I2C();
	WRITE_I2C(ACCESO_CONFIGURACION);
	ESPERA_I2C();
	WRITE_I2C(BYTE_DE_CONFIGURACION);
	ESPERA_I2C();
	/*--------------------------*/}
void F_STAR_CONVERSION_TEMPERATURA( char ADDRESS_W_R){
	/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W_R);
	ESPERA_I2C();
	WRITE_I2C(STAR_CONVERSION_TEMPERATURA);
	ESPERA_I2C();
	/*--------------------------*/}
void F_STOP_CONVERSION_TEMPERATURA( char ADDRESS_W_R){
	/*--------------------------*/
	START_COMUNICATION_I2C();
	ESPERA_I2C();
	WRITE_I2C(ADDRESS_W_R);
	ESPERA_I2C();
	WRITE_I2C(STOP_CONVERSION_TEMPERATURA);
	ESPERA_I2C();
	/*--------------------------*/}
#endif