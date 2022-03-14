#ifndef SPI_LCD_LIBRARY
#define SPI_LCD_LIBRARY


#include <avr/io.h>
#include <avr/pgmspace.h>
#include "ARIAL_14_SIZE.h"
#include "LIBRERIA_SPI_QVL.h"
#include "LIBRERIA_DELAY_QVL.h"
#include "LIBRERIA_SD_QVL.h"









#define NO_OPERATION 0x00/*COMANDO VACIO SIN NINGUN EFECTO EN EL MODULO ILI9341*/
#define SOFTWARE_RESET 0x01/*REINICIO DEL MODULO ILI9341 CON SUS (REGISTROS DE COMANDOS Y PARAMETROS) A SUS VALORES DE FABRICA*/
#define READ_IDENTIFICATION_DISPLAY_INFORMATION 0x04/*ESTE COMANDO SIRVE PARA LEER INFORMACION DE IDENTIFICACION DEL MODULO IL9341*/
#define READ_DISPLAY_STATUS 0x09/*ESTE COMANDO SIRVE PARA OBTENER EL ESTADO ACTUAL DE LA PANTALLA. "LEER TABLA DE REFERENCIA EN LA HOJA DE DATOS"*/
#define READ_DISPLAY_POWER_MODE 0x0A/*ESTE COMANDO SIRVE PARA OBTENER EL ESTADO ACTUAL DE LA PANTALLA. "LEER TABLA DE REFERENCIA EN LA HOJA DE DATOS"*/
#define READ_DISPLAY_MADCTL 0x0B/*ESTE COMANDO SIRVE PARA OBTENER EL ESTADO ACTUAL DE LA PANTALLA. "LEER TABLA DE REFERENCIA EN LA HOJA DE DATOS"*/
#define READ_DISPLAY_PIXEL_FORMAT 0x0C/*ESTE COMANDO SIRVE PARA OBTENER EL ESTADO ACTUAL DE LA PANTALLA. "LEER TABLA DE REFERENCIA EN LA HOJA DE DATOS"*/
#define READ_DISPLAY_IMAGE_FORMAT 0x0D/*ESTE COMANDO SIRVE PARA OBTENER EL ESTADO ACTUAL DE LA PANTALLA. "LEER TABLA DE REFERENCIA EN LA HOJA DE DATOS"*/
#define READ_DISPLAY_SIGNAL_MODE 0x0E/*ESTE COMANDO SIRVE PARA OBTENER EL ESTADO ACTUAL DE LA PANTALLA. "LEER TABLA DE REFERENCIA EN LA HOJA DE DATOS"*/

#define READ_DISPLAY_SELF_DIAGNOSTIC_RESULT 0x0F/*ESTE COMANDO SIRVE PARA OBTENER EL ESTADO ACTUAL DE LA PANTALLA. "LEER TABLA DE REFERENCIA EN LA HOJA DE DATOS"*/
#define ENTER_SLEEP_MODE 0x10/*ESTE COMANDO SIRVE PARA PONER EL MODULO LCD EN MINIMO CONSUMO DE ENERGIA*/
#define SLEEP_OUTPUT 0x11/*ESTE COMANDO SIRVE PARA SACAR AL MODULO LC DEL MINIMO CONSUMO DE ENERGIA*/
#define PATRIAL_MODE_ON 0x12/*ACTIVA EL MODO PARCIAL(DESACTIVA EL MODO NORMAL)*/
#define NORMAL_DISPLAY_MODE_ON 0x13/*ACTIVA EL MODO NORMAL(DESACTIVA EL MODO PARCIAL)*/
#define DISPLAY_INVERSION_ON 0x21/*ESTE COMANDO SIRVE PARA INVERTIR LOS COLORES DEL PANEL LCD DESDE LA MAMORIA DE CUADROS*/
#define DISPLAY_INVERSION_OFF 0x20/*ESTE COMANDO SIRBE PARA DESACTIVA LA INVERSION DE COLORES*/
#define GAMMA_SET 0x26/*ESTE COMANDO SIRBE PARA SELECIONAR LA CURVA GAMMA DESEADA "MAS INFORMACION EN LA HOJA DE DATOS"*/
#define DISPLAY_OFF 0x28/*ESTE COMANDO SIRBE PARA APGAR LA PANTALLA SIN A FECTAR AL CONTENIDO Y REGISTROS DE LA MISMA*/
#define DISPLAY_ON 0x29/*ESTE COMANDO SIRVE PARA ENCENDER LA PANTALLA */

/*DEFINE EL AREA DE DEL CONTENIDO AL LA CUAL SE ENVIARAN LOS DATOS DE COLOR EN LA MEMORIA DE CUADROS*/
#define COLUMN_ADDRESS_SET 0x2A
#define PAGE_ADDRESS_SET 0x2B
/*DEFINE EL AREA DE DEL CONTENIDO AL CUAL SE ESCRIBIRAN LOS DATOS DE COLOR EN LA MEMORIA DE CUADROS*/

#define MEMORY_WRITE 0x2C/*ESCRIBE DATOS DE COLOR EN LA MEMORIA DE CUADROS*/

#define COLOR_SET 0x2D/*SE USA PARA CONVERSION DE PROFUNDIDAD DE COLOR DE 16BITS A 18BITS REALMENTE NO TENGO IDE DE QUE HACE PERO HAY VEREMOS COMO LO USO EN EL FUTURE JEJEJEJEEJJE XD*/
#define MEMORY_READ 0x2E/*HACE LO INVERSO A LO QUE HACE MEMORY_WRITE JAJAJAJAJA QUE COSAS NO */
#define PATRIAL_AREA 0x30/*SE USA PARA DEFINIR UN AREA EN LA CUAL SE INPRIMEN DATOS DE IMAGEN COMO DISE SU NOMBRE SIRVE PARA ACTIVAR PARCIALMENTE EL DISPLAY*/
#define VERTICAL_SCROLLING_DEFINITION 0x33/*ESTE COMANDO SIRVE PARA DEFINIR EL AREA DEL DISPLAY QUE SE VA ADESPLAZAR VERTICALMENTE*/
#define TEARING_EFFECT_LINE_OFF 0x34/*SEGUN DICE SIRVE PARA DESACTIVAR LA SE�AL DE SALIDA DEL EFECTO DE RASGADO DE LA LINEA DE SE�AL*/
#define TEARING_EFFECT_LINE_ON 0x35/*HACE ESCATAMENTE LO CONTRARIO A LO QUE  HACE TEARING_EFFECT_LINE_OFF USTEDES ME ENTIENDEN*/
#define MEMORY_ACCESS_CONTROL 0x36 /*ESTA PARAMETRO IRVE PARA CONFIGURAR  LA DIRECCION DE EXPLORACON DE LA MEMORIA A CUADROS CAMBIA LA ORIENTACION DE LO QUE SE IMPRIME EN PANTALLA PARA QUE ME ENTIENDAN */
#define VERTICAL_SCROLLING_START_ADDRESS 0x37/*ESTE COMANDO DEFINE LA DIRECCION DEL DESPLAZAMIENTO DE LA IMAGEN EN EL LCD*/
#define IDLE_MODE_OFF 0x38/*ESTE COMANDO SIRVE PARA DESACTIVAR EL MODO INACTIVO DEL MODULO ILI9341*/
#define IDLE_MODE_ON 0x39/*ESTE COMANDO HACE LO CONTRARIO A LO QUE HACE IDLE_MODE_OFF*/
#define PIXEL_FORMAT_SET 0x3A/*SELECION EL FORMATO DE PIXELES A UTILIZAR SEA ESTE DE 18BITS O 16 BITS*/
#define WRITE_MEMORY_CONTINUE 0x3C/*ESTE COMANDO SIRVE PARA TRANSFERIR DATOS DE IMAGEN DEL MICRO AL MODULO DEL DISPLAY */
#define READ_MEMORY_CONTINUE 0x3E/*ESTE COMANDO SIRVE PARA LEER DATOS DE IMAGEN DEL MICRO AL MODULO DEL DISPLAY*/
#define SET_TEAR_SCANLINE 0x44/*ESTE COMANDO ENCIENDE LA SE�AL DE SALIDA DEL EFECTO DESGRRO DE LA PATALLA EN LA LINEA DE SE�AL TE CUANDO LA PANTALLA ALCANZA STS SI ENTENDIERON ME LO EXPLICAN POR FAVOR :,( */
#define GET_SCANLINE 0x45/*BUENO YA LES COCA REVISAR EL PDF DEL MODULO ILI9341 */
#define WRITE_DISPLAY_BRIGHTNESS 0x51/*ESTE COMANDO TAN GUAPO SIRVE PAR AJUSTAR EL BRILLO DE LA PANTALLA DEL MODULO ILI9431*/


#define READ_DISPLAY_BRIGHTNESS 0x52/*ESTE COMANDO ME PERMITE LEER EL NIVEL DE BRILLO EN EL QUE ESTA LA PANTALLA DEL MODULO ILI9431*/
#define WRITE_CTRL_DISPLAY 0x53/*ESTE COMANDO SIRVE ARA  CONTROLAR LOS NIVELES DE BRILLO DE LA PANTALLA DEL MODULO BLA BLA BLA*/
#define READ_CTRL_DISPLAY 0x54/*ESTE COMANDO SIRVE PARA LEER LA CONFIGURACION DE BRILLO ACTUAL*/
#define WRITE_CONTENT_ADAPTATIVE_BRIGHTNESS_CONTROL 0x55/*COMO DECIRLO SOLO DIRE QUE SIRBE PRA ADAPTAR EL BRILLO EN BASE A 4 MODOS DESCRITOS EN LA HOJA DE DATOS*/
#define READ_CONTENT_ADAPTATIVE_BRIGHTNESS_CONTROL 0x56/*ESTE COMANDO SIRVE PARA LEER LA CONFIGURACION DE BRILLO ADAPTATIVO ACTUAL*/
#define WRITE_CABC_MINIMUN_BRIGHTNESS 0x5E/*ESTE COMANDO SIRBE PARA DEFINIR UN NIVEL DE BRILLO MINIMO EN LA PANTALLA DEL MODULO ILI9431*/
#define READ_CABC_MINIMUN_BRIGHTNESS 0x5F/*ESTE COMANDO SIRBE PARA LEER EL NIVEL DE BRILLO MINIMO EN LA PANTALLA DEL MODULO ILI9431*/
#define READ_ID1 0xDA/*ESTE COMANDO SIRVE PARA LEER EL ID DEL FABRICANTDEL MODULO ILI9431E*/
#define READ_ID2 0xDB/*ESTE COMANDO SIRVE PARA LEER LA VERSION DEL MODULO ILI9431E*/
#define READ_ID3 0xDC/*ESTE COMANDO SIRVE PARA LEER EL MODULO ILI9431E*/
#define RGB_INTERFACE_SINGNAL_CONTROL 0x00/*ESTE COMANDO ESTABLECE EL ESTADO DE FUNCIONAMIENTO DE LA INTERFAZ DEL MUDULO ILI9341*/
#define FRAME_CONTROL_EN_MODO_NORMAL 0x00/**/
#define FRAME_CONTROL_EN_IDLE_MODO 0x00/**/
#define FRAME_CONTROL_EN_MODO_PARCIAL 0x00/**/
#define DISPLAY_INVERSION_CONTROL 0x00/**/
#define BLANKING_PORCH_CONTROL 0x00/**/
#define DISPLAY_FUNCION_CONTROL 0x00/**/
#define ENTRY_MODE_SET 0x00/**/
#define BLACKILIHT_CONTROL1 0x00/**/
#define BLACKILIHT_CONTROL2 0x00/**/
#define BLACKILIHT_CONTROL3 0x00/**/
#define BLACKILIHT_CONTROL4 0x00/**/
#define BLACKILIHT_CONTROL5 0x00/**/
#define BLACKILIHT_CONTROL6 0x00/**/
#define BLACKILIHT_CONTROL7 0x00/**/
#define BLACKILIHT_CONTROL8 0x00/**/
#define POWER_CONTROL1 0x00/**/
#define POWER_CONTROL2 0x00/**/
#define VCOM_CONTROL1 0x00/**/
#define VCOM_CONTROL2 0x00/**/
#define NV_MEMORY_WRITE 0x00/**/
#define NV_MEMORY_PROTECTION_KEY 0x00/**/
#define NV_STATUS_READ 0x00/**/




#define NO_OPERATION 0x00
#define NO_OPERATION 0x00
#define NO_OPERATION 0x00
#define NO_OPERATION 0x00
#define NO_OPERATION 0x00



#define PIMM PORTC
void GENERADOR_DE_FORMAS_SD(uint16_t ,uint16_t ,int16_t ,int16_t,uint32_t,uint16_t,uint16_t,uint16_t,uint8_t,uint8_t[],int,uint8_t);
void GENERADOR_DE_LETRAS(uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,const char);
void GENERADOR_DE_CADENAS(const  char[],uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint8_t);

void CONVER_INT_CHAR_ILI9431(const float,uint16_t,uint16_t, uint16_t,uint16_t);

void _READ_PARAMETER_ILI9431_8_BITS(uint8_t,uint16_t);
void _WRITE_PARAMETER_ILI9431_16_BITS(uint8_t,uint8_t,uint16_t);
void _WRITE_PARAMETER_ILI9431_8_BITS(uint8_t,uint8_t,uint8_t[]);


void SCROLLING(uint16_t,uint16_t,uint8_t [],uint16_t);
void GENERADOR_DE_COLOR(uint16_t,uint16_t, uint16_t);
void GENERADOR_DE_FORMAS(uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint8_t);
void COMMAND_ILI9431(uint8_t);
void PARAMETER_ILI9431_16_BITS(uint16_t);
void PARAMETER_ILI9431_8_BITS(uint8_t);
void ENCENDER_PANTALLA(void);
void APAGAR_PANTALLA(void);



/*FUNCION QUE SE ENCARGA DE RECVIR COMANDOS QUE SE ENVIARAN AL LCD-TFT*/
void COMMAND_ILI9431_8_BITS(uint8_t COMMANDS){
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(COMMANDS);
PORTC^=(1<<PORTC2);
PORTC^=(1<<PORTC1);}




/*FUNCION QUE SE ENCARGA DE RECVIR Y ENVIAR AL LCD-TFT UN PARAMETRO*/
void PARAMETER_ILI9431_8_BITS(uint8_t PARAMETER){
PORTC^=(1<<PORTC2);//CS-LOW
SPI_MASTER_TRANSMITION_8_BITS(PARAMETER);
PORTC^=(1<<PORTC2);}



/*FUNCION QUE SE ENCARGA DE RECVIR Y ENVIAR AL LCD-TFT UN COMANDO SEGUIDO DE MULTIPLES PARAMETROS EN FORMA DE UN ARREGLO*/
void _WRITE_PARAMETER_ILI9431_8_BITS(uint8_t COMMAND,uint8_t NUM_PARAMETER,uint8_t PARAMETERS[]){
/*PAUSE_FLUJO(1000,1,0,1);*/
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(COMMAND);
PORTC^=(1<<PORTC1);
for(int L=0;L!=NUM_PARAMETER;L++){SPI_MASTER_TRANSMITION_8_BITS(PARAMETERS[L]);}
PORTC^=(1<<PORTC2);}

/*ESTA FUNCION SIRVE PARA CREAR UN SCROLLING DE LA PANTALLA */
void SCROLLING(uint16_t NUM_SCROLLING,uint16_t TIME_SCROLLING,uint8_t AREA_SCROLL[],uint16_t PASOS_SCROLL){
_WRITE_PARAMETER_ILI9431_8_BITS(0x33,6,AREA_SCROLL);
for (uint16_t NUM_SCROLL=0;NUM_SCROLL!=NUM_SCROLLING;NUM_SCROLL++){
for (uint16_t i=0;i!=PASOS_SCROLL;i++){
_WRITE_PARAMETER_ILI9431_16_BITS(0x37,1,i);
PAUSE_FLUJO(TIME_SCROLLING,1,0,1);}}}
/*ESTA FUNCION SIRVE PARA CREAR UN SCROLLING DE LA PANTALLA */



/*ESTA FUNCION SE ENCARGA DE ENVIAR COMANDOS  SEGUIDO DE UN SOLO PARAMETRO CONSECUTIVO DE 16bits*/
void _WRITE_PARAMETER_ILI9431_16_BITS(uint8_t COMMAND,uint8_t NUM_PARAMETER,uint16_t PARAMETERS){
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(COMMAND);
PORTC^=(1<<PORTC1);
for(int L=0;L!=NUM_PARAMETER;L++){SPI_MASTER_TRANSMITION_16_BITS(PARAMETERS);}
PORTC^=(1<<PORTC2);}



/*ESTA FUNCION SE ENCARGA DE ENVIAR COMANDOS DE LECTURA Y LEER CADENAS DE PARAMETROS CONSECUTIVOS DEVUELTOS POR EL LCD-TFT*/
void _READ_PARAMETER_ILI9431_8_BITS(uint8_t COMMAND,uint16_t NUM_PARAMETER){
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(COMMAND);
PORTC^=(1<<PORTC1);
SPI_RECEIVE_MODE_MASTER_();
for(int L=0;L!=NUM_PARAMETER;L++){SPI_RECEIVE_MODE_MASTER_();}
PORTC^=(1<<PORTC2);}
/*ESTA FUNCION SE ENCARGA DE ENVIAR COMANDOS Y LEER CADENAS DE PARAMETROS CONSECUTIVOS*/




/*ESTA FUNCION SIRBE PARA EL ENVIO DE PARAMETROS DE INSTRUCCIONES DE 2 bytes AL CONTROLADOR LCD ILI9341*/
void PARAMETER_ILI9431_16_BITS(uint16_t PARAMETER){
PORTC^=(1<<PORTC2);//CS-LOW
SPI_MASTER_TRANSMITION_16_BITS(PARAMETER);
PORTC^=(1<<PORTC2);}




/*ESTA FUNCION CARGA LA SECUENCIA DE INICIALIZACION DEL MODULO LCD-TFT*/
void ENCENDER_PANTALLA(void){

COMMAND_ILI9431_8_BITS(0x01);//RESET_SOFTWARE
PAUSE_FLUJO(5000,1,0,1);

//CONTROL POTENCIA A
uint8_t PARAMETROS1[]={0x39,0x2C,0x00,0x34,0x02};
_WRITE_PARAMETER_ILI9431_8_BITS(0xCB,5,PARAMETROS1);

//CONTROL POTENCIA B
uint8_t PARAMETROS2[]={0x00,0xC1,0x30};
_WRITE_PARAMETER_ILI9431_8_BITS(0xCF,3,PARAMETROS2);

//CONTROL TIEMPO CONDUCTOR A
uint8_t PARAMETROS3[]={0x85,0x00,0x78};
_WRITE_PARAMETER_ILI9431_8_BITS(0xE8,3,PARAMETROS3);

//CONTROL TIEMPO CONDUCTOR B
uint8_t PARAMETROS4[]={0x00,0x00};
_WRITE_PARAMETER_ILI9431_8_BITS(0xEA,2,PARAMETROS4);

//POWER ON SEQUENCE CONTROL
uint8_t PARAMETROS5[]={0x64,0x03,0x12,0x81};
_WRITE_PARAMETER_ILI9431_8_BITS(0xED,4,PARAMETROS5);


//CONTROL DE RELACION DE BOMBEO
uint8_t PARAMETROS6[]={0x20};
_WRITE_PARAMETER_ILI9431_8_BITS(0xF7,1,PARAMETROS6);


//CONTROL DE POTENCIA VRH
uint8_t PARAMETROS7[]={0x23};
_WRITE_PARAMETER_ILI9431_8_BITS(0xC0,1,PARAMETROS7);

//CONTROL DE ENERGIA SAP
uint8_t PARAMETROS8[]={0x10};
_WRITE_PARAMETER_ILI9431_8_BITS(0xC1,1,PARAMETROS8);

//CONTROL VCM
uint8_t PARAMETROS9[]={0xE3,0x28};
_WRITE_PARAMETER_ILI9431_8_BITS(0xC5,2,PARAMETROS9);

//CONTROL VCM 2
uint8_t PARAMETROS10[]={0x86};
_WRITE_PARAMETER_ILI9431_8_BITS(0xC7,1,PARAMETROS10);

//CONTROL DE ACCESO A LA MEMORIA
uint8_t PARAMETROS11[]={0b00001100/**/};
_WRITE_PARAMETER_ILI9431_8_BITS(0x36,1,PARAMETROS11);

//FERMATO DE PIXELES
uint8_t PARAMETROS12[]={0x55};
_WRITE_PARAMETER_ILI9431_8_BITS(0x3A,1,PARAMETROS12);

uint8_t PARAMETROS13[]={0x00,0x18};
_WRITE_PARAMETER_ILI9431_8_BITS(0xB1,2,PARAMETROS13);

uint8_t PARAMETROS14[]={0x08,0x82,0x27};
_WRITE_PARAMETER_ILI9431_8_BITS(0xB6,3,PARAMETROS14);

uint8_t PARAMETROS15[]={0x00};
_WRITE_PARAMETER_ILI9431_8_BITS(0xF2,1,PARAMETROS15);

uint8_t PARAMETROS16[]={0x01};
_WRITE_PARAMETER_ILI9431_8_BITS(0x26,1,PARAMETROS16);

uint8_t PARAMETROS17[]={0x0F,0x31,0x2B,0x0C,0x0E,0x08,0x4E,0xF1,0x37,0x07,0x10,0x03,0x0E,0x09,0x00};
_WRITE_PARAMETER_ILI9431_8_BITS(0xE0,15,PARAMETROS17);

uint8_t PARAMETROS18[]={0x00,0xE0,0x14,0x03,0x11,0x07,0x31,0xC1,0x48,0x08,0x0F,0x0C,0x31,0x36,0x0F};
_WRITE_PARAMETER_ILI9431_8_BITS(0xE1,15,PARAMETROS18);


COMMAND_ILI9431_8_BITS(0x11);//SALIR_SLEEP_MODE
PAUSE_FLUJO(1000,1,0,1);

COMMAND_ILI9431_8_BITS(0x29);//DISPLAY_ON
PAUSE_FLUJO(500,1,0,1);}


void APAGAR_PANTALLA(void){
COMMAND_ILI9431_8_BITS(0x28);}




/*****************************************************************/

void CONVER_INT_CHAR_ILI9431(const float NUMERO_LUIS, uint16_t POS_X, uint16_t POS_Y,uint16_t COLOR_TEXT,uint16_t BACKGROUND_TEXT){
uint16_t C[6]={1,10,100,1000,10000,65535};
char N[9]={'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
uint16_t ENTERO=NUMERO_LUIS;
uint8_t DECIMAL=((float)(NUMERO_LUIS-ENTERO))*100;
uint8_t N_INTERACCIONES=0,CONTROL=1;
if (NUMERO_LUIS<0)
{
	DECIMAL=(-1)*DECIMAL;
	ENTERO=(-1)*ENTERO;
}

if(ENTERO>0xffff){
N[0]='N';N[1]='a';N[2]='N';}

else{
if (ENTERO==0){
N[CONTROL-1]=0;
N[CONTROL-1]=N[CONTROL-1]+48;
CONTROL++;}

if (ENTERO>0){
if(ENTERO>=10000&&ENTERO<=65500){N_INTERACCIONES=5;
}else{
if(ENTERO>=1000&&ENTERO<=9999){N_INTERACCIONES=4;
}else{
if(ENTERO>=100&&ENTERO<=999){N_INTERACCIONES=3;
}else{
if(ENTERO>=10&&ENTERO<=99){N_INTERACCIONES=2;
}else{
if(ENTERO>=1&&ENTERO<=9){N_INTERACCIONES=1;}}}}}
N_INTERACCIONES=N_INTERACCIONES+CONTROL;

while(CONTROL!=N_INTERACCIONES){
N[CONTROL-1]=(uint8_t)(ENTERO/C[N_INTERACCIONES-CONTROL-1]);
ENTERO=ENTERO-N[CONTROL-1]*C[N_INTERACCIONES-CONTROL-1];
N[CONTROL-1]=N[CONTROL-1]+48;
CONTROL++;}}


ENTERO=DECIMAL;
if (ENTERO>0){
N[CONTROL-1]='.';
CONTROL++;
if(ENTERO>=10&&ENTERO<=99){N_INTERACCIONES=2;
N_INTERACCIONES=N_INTERACCIONES+CONTROL;
while(CONTROL!=N_INTERACCIONES){
N[CONTROL-1]=(uint8_t)(ENTERO/C[N_INTERACCIONES-CONTROL-1]);
ENTERO=ENTERO-N[CONTROL-1]*C[N_INTERACCIONES-CONTROL-1];
N[CONTROL-1]=N[CONTROL-1]+48;
CONTROL++;}
}else{
if(ENTERO>=1&&ENTERO<=9){N_INTERACCIONES=1;
N_INTERACCIONES=N_INTERACCIONES+CONTROL;
N[CONTROL-1]=0;
N[CONTROL-1]=N[CONTROL-1]+48;
CONTROL++;
N[CONTROL-1]=(uint8_t)(ENTERO/C[N_INTERACCIONES-CONTROL]);
ENTERO=ENTERO-N[CONTROL-1]*C[N_INTERACCIONES-CONTROL];
N[CONTROL-1]=N[CONTROL-1]+48;}}
}}GENERADOR_DE_CADENAS(N,POS_X,POS_Y,16, COLOR_TEXT, BACKGROUND_TEXT,0b00001100);}



/*****************************************************************/
void GENERADOR_DE_CADENAS_PROGMEM(const char*,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t);
void GENERADOR_DE_CADENAS_PROGMEM(const char *String_1,uint16_t POSX,uint16_t POSY,uint16_t SIZE_CHAR,uint16_t COLOR_TEXT,uint16_t BACKGROUND_TEXT){
uint16_t PoX=POSX,PoY=POSY;
unsigned char LUW4;
uint8_t COLUM,SPACIO=0;
const char *LUW1,*LUW3;
LUW3=String_1;
for (uint8_t SECUE=0;pgm_read_byte(&LUW3[SECUE])!='\0';SECUE++){
LUW4=pgm_read_byte(&LUW3[SECUE]);
LUW1=ARIAL_FONT_32[LUW4-32];
COLUM=pgm_read_byte(&LUW1[0]);
if(LUW4==' '){SPACIO=0;}else{SPACIO=1;}
GENERADOR_DE_LETRAS(SIZE_CHAR,COLUM,PoX,PoY,COLOR_TEXT,BACKGROUND_TEXT,LUW4);
PoX=PoX+COLUM+SPACIO;
if (PoX>320){PoX=0;PoY=PoY+31;}
if(PoY>240){PoY=0;}}}



void GENERADOR_DE_CADENAS(const char String_[100],uint16_t POSX,uint16_t POSY,uint16_t SIZE_CHAR_1,uint16_t COLOR_TEXT_1,uint16_t BACKGROUND_TEXT_1,uint8_t MDCTL_CADENAS){
if(MDCTL_CADENAS>0){uint8_t MDCTRL_[1]={MDCTL_CADENAS};_WRITE_PARAMETER_ILI9431_8_BITS(0x36,1,MDCTRL_);}
uint16_t PoX=POSX,PoY=POSY;
uint8_t COLUM_1,SPACIO=0;
const static char *LUW1;
for (uint8_t SECUE_C=0;String_[SECUE_C]!='\0';SECUE_C++){
LUW1=ARIAL_FONT_32[String_[SECUE_C]-32];
COLUM_1=pgm_read_byte(&LUW1[0]);
if(String_[SECUE_C]==' '){SPACIO=0;}else{SPACIO=2;}
GENERADOR_DE_LETRAS(SIZE_CHAR_1,COLUM_1,PoX,PoY,COLOR_TEXT_1,BACKGROUND_TEXT_1,String_[SECUE_C]);
PoX=PoX+COLUM_1+SPACIO;
if (PoX>320){PoX=0;PoY=PoY+32;}
if(PoY>240){PoY=0;}}}



void GENERADOR_DE_LETRAS(
uint16_t BASE,uint16_t ALTURA,
uint16_t ADDRES_X,uint16_t ADDRES_Y,
uint16_t COLOR_TEXT_,uint16_t BACKGROUND_TEXT,
const char Char_){
uint8_t LETR[129];
int16_t DIMENSIONES[2];
int16_t COORDENADAS[2];
COORDENADAS[1]=ADDRES_X;
COORDENADAS[0]=ADDRES_Y;
DIMENSIONES[0]=BASE-1;
DIMENSIONES[1]=ALTURA-1;
char COMANDO[2]={0x2a,0x2b};
for(int CICLO=0;CICLO!=2;CICLO++){
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(COMANDO[CICLO]);
PORTC^=(1<<PORTC1);
SPI_MASTER_TRANSMITION_16_BITS(0+COORDENADAS[CICLO]);
SPI_MASTER_TRANSMITION_16_BITS(DIMENSIONES[CICLO]+COORDENADAS[CICLO]);
PORTC^=(1<<PORTC2);}
uint8_t COTADORES_DE_BITS=0,CONTROL_DE_BYTES=0;
uint8_t BYTE_DATA=0;
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(0x2c);
PORTC^=(1<<PORTC1);


uint8_t LU=0;
const char *LUW=ARIAL_FONT_32[Char_-32];
while(LU!=129){
LETR[LU]=pgm_read_byte(LUW++);
LU++;}
for(uint16_t LUIS=0;LUIS!=(BASE*ALTURA);LUIS++){
BYTE_DATA=BYTE_DATA&0b00000000;
BYTE_DATA=(LETR[CONTROL_DE_BYTES+1]>>COTADORES_DE_BITS);
BYTE_DATA=BYTE_DATA&0b00000001;
COTADORES_DE_BITS++;
if (COTADORES_DE_BITS==8){CONTROL_DE_BYTES++;COTADORES_DE_BITS=0;}
if (BYTE_DATA==1){
SPI_MASTER_TRANSMITION_16_BITS(COLOR_TEXT_);
}else{SPI_MASTER_TRANSMITION_16_BITS(BACKGROUND_TEXT);/*COLOR DE FONDO DE LETRA*/}}
PORTC=(1<<PORTC2)|(1<<PORTC2)|(1<<PORTC1)|(1<<PORTC0);
/************************************************************************/
}


/*ESTA FUNCION SIRVE PARA RELLENAR EL CONTENIDO PREBIAMENTE DEFINIDO POR EL LA FUNCION GENERADOR_DE_FORMAS*/
void GENERADOR_DE_COLOR(uint16_t X,uint16_t Y, uint16_t DATA_IMAGES){
uint32_t TOTALLY=(uint32_t)X*Y;
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(0x2c);
PORTC^=(1<<PORTC1);
for(uint32_t LUIS=0;LUIS!=TOTALLY;LUIS++){
SPI_MASTER_TRANSMITION_16_BITS_LCD(DATA_IMAGES);}
PORTC^=(1<<PORTC1);}


/*ESTA FUNCION ES DE MUCHA IMPORTANCIA YA QUE SIRVE PARA DEFINIR EL AREA DE LA MEMORIA A
CUADROS DE LA PANALLA QUE SERAN COLOREADAS PARA GENERAR FORMAS CUADRDAS Y
RECTANGULARES ADEMAS DE GENERAR PUNTOS EN CUALQUIER PARTE DEL PLANO DE LA PANTALLA TFT*/
void GENERADOR_DE_FORMAS(uint16_t BASE,uint16_t ALTURA,uint16_t ADDRES_X,uint16_t ADDRES_Y,uint16_t COLOR,uint8_t MDCTL_FORMAS){
	if(MDCTL_FORMAS>0){uint8_t MDCTRL_FO[1]={MDCTL_FORMAS};_WRITE_PARAMETER_ILI9431_8_BITS(0x36,1,MDCTRL_FO);}
uint16_t DIMENSIONES[2];
uint16_t COORDENADAS[2];
COORDENADAS[0]=ADDRES_Y;
COORDENADAS[1]=ADDRES_X;
DIMENSIONES[0]=BASE-1;
DIMENSIONES[1]=ALTURA-1;
char COMANDO[2]={0x2a,0x2b};
for(int CICLO=0;CICLO!=2;CICLO++){
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(COMANDO[CICLO]);
PORTC^=(1<<PORTC1);
SPI_MASTER_TRANSMITION_16_BITS(COORDENADAS[CICLO]);
SPI_MASTER_TRANSMITION_16_BITS(DIMENSIONES[CICLO]+COORDENADAS[CICLO]);
PORTC^=(1<<PORTC2);}
GENERADOR_DE_COLOR(BASE,ALTURA,COLOR);
PORTC=(1<<PORTC2)|(1<<PORTC1)|(1<<PORTC0);}
/*ESTA FUNCION SIRVE PARA DEFINIR EL AREA DE LA MEMORIA A CUADROS DE LA PANALLA QUE SERAN COLOREADAS*/




/*ESTA FUNCION LEE IMAGENES DE FORMATO.bmp (MAPA DE BIT)*/
void GENERADOR_DE_FORMAS_SD(uint16_t BASE_1,uint16_t ALTURA_1,
int16_t ADDRES_X_1,int16_t ADDRES_Y_1,
uint32_t NUM_SECTORE_1,uint16_t SIZE_SECTOR_1,
uint16_t SCROLL_1,uint16_t NUM_SCROLLS_1,
uint8_t MDCTRL,uint8_t AREA_SCROLL[],int RESET_POSITION_IMAGEN,uint8_t MDCTL){

/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
uint32_t BASE1,ALTURA1;
uint16_t LCD,LCD_L=0x00;
uint16_t DATA[256];
uint16_t DATA1[256];
uint32_t RE;
uint16_t DIMENSIONES_1[2];
int16_t COORDENADAS_1[2];
COORDENADAS_1[0]=ADDRES_Y_1;
COORDENADAS_1[1]=ADDRES_X_1;
DIMENSIONES_1[0]=BASE_1-1;
DIMENSIONES_1[1]=ALTURA_1-1;
char COMANDO[2]={0x2a,0x2b};
BASE1=BASE_1;
ALTURA1=ALTURA_1;
for(int CICLO=0;CICLO!=2;CICLO++){
PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(COMANDO[CICLO]);

PORTC^=(1<<PORTC1);
SPI_MASTER_TRANSMITION_16_BITS(COORDENADAS_1[CICLO]);//DIRECCION CON (CICLO=0)SC[15:0],CON (CICLO=1)SP[15:0]
SPI_MASTER_TRANSMITION_16_BITS(DIMENSIONES_1[CICLO]+COORDENADAS_1[CICLO]);//DIRECCION CON (CICLO=0)[15:0],CON (CICLO=1)EP[15:0]
PORTC^=(1<<PORTC2);}


if(MDCTL>0){uint8_t MDCTRL_0[1]={MDCTRL};_WRITE_PARAMETER_ILI9431_8_BITS(0x36,1,MDCTRL_0);}

PORTC^=(1<<PORTC2);//CS-LOW
PORTC^=(1<<PORTC1);//DC-LOW
SPI_MASTER_TRANSMITION_8_BITS(0x2c);
PORTC^=(1<<PORTC1);
PORTC^=(1<<PORTC2);
RE=BASE1*ALTURA1;
//RE*2
RE=((PESO_FILE_BYTE)*0.001953125);
for(uint16_t IS=0;IS!=RE;IS++){

PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,((NUM_SECTORE_1*SIZE_SECTOR_1)>>16),(NUM_SECTORE_1*SIZE_SECTOR_1),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
for (int i=0;i!=256;i++){
LCD_L=SPI_RECEIVE_MODE_MASTER_();
LCD=SPI_RECEIVE_MODE_MASTER_();
LCD=(LCD_L<<8)|LCD;
DATA[i]=LCD;}
NUM_SECTORE_1++;
PAUSE_FLUJO(10,1,0,1);
CUSTOM_CMD_SET_SD(17,((NUM_SECTORE_1*SIZE_SECTOR_1)>>16),(NUM_SECTORE_1*SIZE_SECTOR_1),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
for(int i=0;i!=256;i++){
LCD_L=SPI_RECEIVE_MODE_MASTER_();
LCD=SPI_RECEIVE_MODE_MASTER_();
LCD=(LCD_L<<8)|LCD;
DATA1[i]=LCD;}
PORTC^=(1<<PORTC0);

PORTC^=(1<<PORTC2);
for(uint16_t o=35;o!=256;o++){SPI_MASTER_TRANSMITION_16_BITS_LCD(DATA[o]);}
for(uint16_t o=0;o!=35;o++){SPI_MASTER_TRANSMITION_16_BITS_LCD(DATA1[o]);}
PORTC^=(1<<PORTC2);

}
if(NUM_SCROLLS_1>0){}PORTC=(1<<PORTC2)|(1<<PORTC2)|(1<<PORTC1)|(1<<PORTC0);

/*---------------------------------------------------------------*/
if(SCROLL_1>0){ SCROLLING(NUM_SCROLLS_1,100,AREA_SCROLL,SCROLL_1);}
/*---------------------------------------------------------------*/
/*POSIBLE BUG OJO JJAJAJAJAJJA*/
if(RESET_POSITION_IMAGEN){
COMMAND_ILI9431_8_BITS(0x01);
COMMAND_ILI9431_8_BITS(0x29);

}
/*COMMAND_ILI9431_8_BITS(SLEEP_OUTPUT);*/




}





//SE ENCARGA DE GENERAR FIGURAS CUADRADAS O RECTANGULARES
















#endif
