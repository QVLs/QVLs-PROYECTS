/*COMETARIOS.c
*Created:10/3/2020 12:11:15 PM
*Author:el_lu*/
//_MEMORY_SD_INFO();
//EJEMPLO_0
//GENERADOR_DE_FORMAS_SD(206,320,0,0,835,512,1,320,0b01001100,AREA_SCROLL,1,1);
//EJEMPLO_1
//QQQQQ.BMP
//PRUEBA.BMP
//LUIS.bmp
//LL16.BMP
//QWE16.BMP
//IMG16.BMP
//ICON016.BMP
//GENERADOR_DE_FORMAS_SD(240,320,0,0,SEARCH_CLUSTER_FILE(512,R),512,320,1,0b01001100,AREA_SCROLL,1,1);
//GENERADOR_DE_FORMAS_SD(240,320,0,0,SEARCH_CLUSTER_FILE(512,"IMG16.BMP"),512,320,1,0b01001100,AREA_SCROLL,1,1);
//GENERADOR_DE_CADENAS("LUIS JAVIER",0,210);
//GENERADOR_DE_CADENAS("QUINONEZ",0,175);
//GENERADOR_DE_CADENAS("VERNAZA",0,125);
//GENERADOR_DE_FORMAS_SD(192,340,20,0,POSITION_DIR_ROOT(512,"QQQQQ.BMP"),512,320,1,0b01001100,AREA_SCROLL,1,1);
//GENERADOR_DE_FORMAS_SD(206,320,20,0,POSITION_DIR_ROOT(512,"LL16.BMP"),512,320,1,0b01001100,AREA_SCROLL,1,1);
//EJEMPLO_2
//GENERADOR_DE_FORMAS_SD(240,320,0,0,835,512,160,1,0b01000100,AREA_SCROLL,0,1);
//EJEMPLO_3
//GENERADOR_DE_FORMAS_SD(80,80,150,50,1139,512,1,0,0b01001100,AREA_SCROLL,0,1);
//QQQQQ.BMP
//PRUEBA.BMP
//LUIS.bmp
//LL16.BMP
//QWE16.BMP
//IMG16.BMP
//ICON016.BM
//switch(OP){
//case 4:
//OP=1;
//R="IMG16.BMP";
//WR=320;
//WE=240;
//break;
//case 2:"JOLA.TXT";
//R="IMG16.BMP";
//WR=320;
//WE=240;
//break;
//case 3:
//R="QQQQQ.BMP";
//WR=340;
//WE=192;
//break;
// case 0:
//R="LL16.BMP";
//WR=320;
//WE=206;
//OP=0;
//break;
//}

// DDRB=(1<<DDB3/*MOSI*/)|(1<<DDB5/*SCKL*/)|(1<<DDB2)/*SS*//*|(1<<DDB0SS)*/;
// SPSR=(1<<SPI2X);
// SPCR=0b01010000;
//
// 	SPDR=0xe4;
// while(!(SPSR&(1<<SPIF)));

//
// COMMAND_ILI9431_8_BITS(0x21);

/*APAGAR_PANTALLA();*/

/****************************************************************/
// ESTADO_L=0;
// START_COMUNICATION_I2C();
// ESPERA_I2C();
// WRITE_I2C(0x41);
// ESPERA_I2C();
// PAUSE_FLUJO(50,1,0,1);
// ESTADO_L=READ_I2C_ACK();
// ESPERA_I2C();
// ESTADO_H=READ_I2C_NACK();
// ESPERA_I2C();
// STOP_COMUNICATION_I2C();
// ESTADO_T=ESTADO_H;
// ESTADO_T=ESTADO_L|(ESTADO_T<<8);

/****************************************************************/


/*****************************************************************/
// if (1){
// if (ESTADO_T==0x01){
// if (OP>1){GENERADOR_GEOMETRICO(20,100,0,49*(OP-1),1,0xffff);}
// if (OP>3){OP=1;}
// PAUSE_FLUJO(5000,1,0,1);
// GENERADOR_GEOMETRICO(20,100,0,49*OP,1,0x0000);
// OP++;}}
/*****************************************************************/

// for(uint16_t CA1=1;CA1!=90;CA1++){
// GENERADOR_GEOMETRICO(20,CA1,110,218,1,0xffff);}
// //GENERADOR_DE_CADENAS("QVLsoft",110,220,16);
// CONVER_INT_CHAR_ILI9431(0,110,220);
// for(uint16_t CA=1;CA!=4;CA++){
// for(uint16_t CA1=1;CA1!=100;CA1++){
// GENERADOR_GEOMETRICO(20,CA1,0,49*CA,1,0xffff);}}
// char *R;
// uint8_t OP=1,WE=0,WR=0,UI=0;
// const char *LUu;
// for(uint16_t CA=1;CA!=4;CA++){
// LUu=PANTALLA_1[CA-1];
// R="           ";
// for (uint16_t CO=0;(R[CO]!='\0');CO++){
// R[CO]=pgm_read_byte(LUu++);
// }GENERADOR_DE_CADENAS(R,2,50*CA,16);}
/*****************************************************************/

// ENABLE_I2C_PULL_UP(4,0,0);
// PAUSE_FLUJO(25,1,0,1);
// uint8_t ESTADO_H=0,ESTADO_L;

// void READ_MEMORY_SD_INFO();
// void READ_MEMORY_SD_INFO(){
	// LCD_PRINT("FAT:",13,0);CONVER_INT_CHAR(TYPPE_FAT,17,0);LCD_PRINT("]\0",19,0);
	// LCD_PRINT("[#Sec*Clus:\0",0,0);CONVER_INT_CHAR(BPB_SecPerClus,11,0);
	// LCD_PRINT("#Clusters:\0",0,1);CONVER_INT_CHAR(CountofClusters/1000,10,1);LCD_PRINT("[Mil]\0",15,1);
	// LCD_PRINT("#FATs:",0,2);CONVER_INT_CHAR(BPB_NumFATs,6,2);
	// LCD_PRINT("VOLUMEN:\0",0,3);CONVER_INT_CHAR(((DskSize*512)/1024000),8,3);LCD_PRINT("[MB]\0",16,3);
	// PAUSE_FLUJO(20000,1,0,1);
	// LIMPIAR_PANTALLA();
	// LCD_PRINT("#SECTORS:\0",0,0);CONVER_INT_CHAR(((float)DskSize/1000),9,0);LCD_PRINT("[Mil]\0",15,0);
	// LCD_PRINT("#Sec_D&F:\0",0,1);CONVER_INT_CHAR((float)FAT_AND_DATA_REGION/1000,9,1);LCD_PRINT("[Mil]\0",15,1);
	// LCD_PRINT("#MBR:",0,2);CONVER_INT_CHAR(F_MBR,5,2);LCD_PRINT("[DEC]\0",15,2);
	// LCD_PRINT("#SecReserv:\0",0,3);CONVER_INT_CHAR(BPB_RsvdSecCnt,11,3);
	// PAUSE_FLUJO(20000,1,0,1);
	// LIMPIAR_PANTALLA();
	// LCD_PRINT("#PRIMER SECTOR DATOS\0",0,0);
	// CONVER_INT_CHAR(FirstDataSector,0,1);
	// LCD_PRINT("#PRIMER SEC DIR RAIZ\0",0,2);
	// CONVER_INT_CHAR(FirstRootDirSecNum,0,3);
	// PAUSE_FLUJO(20000,1,0,1);
	// LIMPIAR_PANTALLA();
	// LCD_PRINT("#Bytes Por Sector\0",0,0);
	// CONVER_INT_CHAR(BPB_BytsPerSec,0,1);
	// PAUSE_FLUJO(15000,1,0,1);
//}

// // //STATE_SD_MMC();
// // /*LIMPIAR_PANTALLA();*/
//
// //
//
// //
//
// void INT_SD_MMC(void){
/*CMD1*//*41 00 00 00 00 ff*/
// PORTC^=(1<<PORTC0);
// CUSTOM_CMD_SET_SD(1,0,0,0xff,0x01);/*INICIALISCION DE LA TARJETA SD*/
// PORTC^=(1<<PORTC0);

// 	RESET_SD_MMC();
// CUSTOM_CMD_SET_SD_MMC(0x00,0x00,0x00,0x95);/*CMD0 INICIALISACION DE LA SD/MMC*/
// CUSTOM_CMD_SET_SD_MMC(0x01,0x00,0x00,0xff);/*CMD1 RESET DEL SOFTWRE DE LA SD/MMC*/
// CUSTOM_CMD_SET_SD_MMC(0x10,0x00,0x200,0xff);/*CMD10 SET THE SIZE BLOCK*/// READ_MBR(512);
//}

//GENERADOR_DE_CADENAS(PANTALLA_1[rtw],0,24*rtw,16,0xE310,0x00);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[1],0,25,16,0x7C10,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[2],0,50,16,0xE010,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[3],0,75,16,0xEC10,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[4],0,100,16,0xEC0,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[5],0,125,16,0xC10,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[6],0,150,16,0xE0,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[7],0,175,16,0xE310,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[8],0,200,16,0x840,0x0000);
//
// GENERADOR_DE_CADENAS(PANTALLA_1[9],0,225,16,0xEA0,0x0000);
//uint16_t COLORS/*[(ALTO*2)+(ANCHO*2)]*/=COLOR;
//for(uint16_t i=0;i!=((ALTO*2)+(ANCHO*2));i++){COLORS[i]=COLOR;}
	
	
	
	
	
/*

PESO_FILE_BYTE=0x00000000;

unsigned int CLOUSTER=0x0000;
int NAMEP=0,PLO=0;
uint8_t READ_DATA_Root_dir_1[SIZE_SECTOR];/ *AQUI GUARDAMOS EL PRIMER SECTOR DEL DIRECTORIO RAIZ A MAPEAR* /
uint8_t READ_DATA_Root_dir_2[SIZE_SECTOR];/ *AQUI GUARDAMOS EL SECTOR DEL SIGUIENTE DIRECTORIO RAIZ A MAPEAR* /
char DATA_Root_dir[512];/ *AQUI ALMACENAMOS EL DIRECTORIO DE [N*32 Bytes] QUE VAYAMOS LEYENDO* /
uint8_t ARCHIVO_ENCONTRADO=0,CONTROL_DIRECTORIO=0,A=0,Var3=0;
uint32_t VALID=0;
while (VALID!=10){/ *ESTE WHILE SE ENCARGA DE HACER EL CORRIDO DE CADA SECTOR QUE COMPONE EL DIRECTORIO RAIZ* /
NUM_SECTORE=NUM_SECTORE+VALID;/ *LA VARIABLE VALID APORTA CON UN CONTADOR DE 0 a N* /
Var1=1,Var2=0,R_N=0,Var5=0,Var4=0,B=0,Ord=0x40;

/ *LEEMOS EL PRIMER SECTOR QUE CONTIENE LOS DATOS DEL DIRECTORIO RAIZ* /
PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,((NUM_SECTORE*SIZE_SECTOR)>>16),(NUM_SECTORE*SIZE_SECTOR),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
PAUSE_FLUJO(2000,1,0,1);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_DATA_Root_dir_1[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0x1100);
PORTC^=(1<<PORTC0);
/ *LEEMOS EL PRIMER SECTOR QUE CONTIENE LOS DATOS DEL DIRECTORIO RAIZ* /


if (CONTROL_DIRECTORIO==1){
Var1=Var3;
Var2=A;
}else{
Var1=0;
Var2=0;}



while(Var1<17){/ *CADA SECTOR DE 512 Bytes PUEDE CONTIENER UN MAXIMO DE 16 DIRECTORIOS DE 32 Bytes AQUI NOS ASEGURAMOS DE QUE EN CADA SECTOR SE CUENTE TODOS LOS DIRECTORIOS DE ESE SECTOR* /
Ord=0x40;
for(uint16_t i=0;i!=(512);i++){DATA_Root_dir[i]=0x00;}/ *PONEMOS EN CERO EL VECTOR QUE CONTENDRA DE MANERA TEMPORAL EL DIRECTORIO DE N ARCHIVO* /

for(int i=0;i!=(32);i++){DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}/ *ALMACENAMOS EL DIRECTORIO DE N ARCHIVO EN LA VECTOR TEMPORAL [DATA_Root_dir] PARA PODER CREAR NUESTRO SISTEMA DE BUSQUEDA DE ARCHIVOS* /

/ *EN ESTA VIFURCACION DETERMINAMOS SI EL ARCHIVO ES DE NOMBRE LARGO O DE NOMBRE CORTO* /

if((DATA_Root_dir[11]==0x0f)&&(DATA_Root_dir[12]==0x00))//SI ESTA VIFURCACION ES VERDADERA EN TONCES ES UN ARCHIVO DE NOMBRE LARGO
{
Ord=DATA_Root_dir[0]-Ord+1;/ *AQUI DETERMINAMOS EL NUMERO DE DIRECTORIOS DE 32 Bytes QUE OCUPA ESE ARCHIVO DE NOMBRE LARGO* /
Var1=Var1+(Ord);/ *COMO UN ARCHIVO DE NOMBRE LARGO CONTIENE MAS DE UN DIRECTORIO DE 32 Bytes DEBO INCREMENTARLE A LA Var1 EL NUMERO DE DIRECTORIOS QUE OCUPA ESE ARCHIVO* /
R_N=((Ord)*32);/ *AQUI CALCULAMOS EL NUMERO DE Bytes QUE CONTIENE EL DIRECTORIO DEL ARCHIVO DE NOMBRE LARGO* /



if(Var1>16){
CONTROL_DIRECTORIO=1;
Var3=(Var1-16);/ *NUMERO DE DIRCTORIOS QUE SE DEBEN LEER DEL SIGUIENTE SECTOR DEL DIRECTORIO  RAIZ* /
Var4=(Ord-Var3);/ *NUMERO DE DIRCTORIOS QUE SE PUEDEN LEER DEL ACTUAL SECTOR DEL DIRECTORIO  RAIZ* /
A=Var3*32;/ *NUMERO DE Bytes DEL SIGUIENTE SECTOR DEL DIRECTORIO  RAIZ* /
B=Var4*32;/ *NUMERO DE Bytes DEL ACTUAL SECTOR DEL DIRECTORIO  RAIZ* /


PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,(((NUM_SECTORE+1)*SIZE_SECTOR)>>16),((NUM_SECTORE+1)*SIZE_SECTOR),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
PAUSE_FLUJO(500,1,0,1);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_DATA_Root_dir_2[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0x1100);
PORTC^=(1<<PORTC0);


for(uint16_t i=0;i!=(B);i++){
DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}


for(uint16_t i=0;i!=(A);i++){
DATA_Root_dir[i+(B)]=READ_DATA_Root_dir_2[i];}
}



else{
if ((Var1>=0)&&(Var1<=16)){
CONTROL_DIRECTORIO=0;
for(uint16_t i=0;i!=(R_N);i++){DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}
}
}Var2=Var2+(32*Ord);}





/ *ESTE ELSE DE CONTROL SE ENCARGA DE----------------------------------------------- * /
else{
if ((Var1>=0)&&(Var1<=16)){
CONTROL_DIRECTORIO=0;


for(int i=0;i!=(32);i++){
DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}


NAMEP=0;
WRITE_MEMORY_SD_MMC(DATA_Root_dir,512,(100000+PLO));

for(int i=0;i!=(11);i++){
if (DATA_Root_dir[i]==Dir_Root[i]){
NAMEP++;}}
if((NAMEP==11)){
ARCHIVO_ENCONTRADO=1;
/ *sacamos los 4 bytes que nos dicen el peso del archivo* /
for(int luis=31;luis!=27;luis--){
									
PESO_FILE_BYTE=(PESO_FILE_BYTE<<8)|DATA_Root_dir[luis];}
PESO_FILE=PESO_FILE_BYTE/1024;

for(int luis=27;luis!=25;luis--){
CLOUSTER=(CLOUSTER<<8)|DATA_Root_dir[luis];}}
Var2=Var2+32;}


Var1++;}
/ *ESTE ELSE DE CONTROL SE ENCARGA DE----------------------------------------------- * /



PLO++;
}
VALID++;}
if(ARCHIVO_ENCONTRADO==0){CLOUSTER=0;}*/
	
	// if (y>=y1)
	// {
	//
	// while(x<=x1){
	// GENERADOR_DE_FORMAS(1,1,x,y,0,0x0c);
	// //x+=1;
	// if(Av>=0){
	// x=x+incX;
	// y=y+incY;
	// Av=Av+Avi;
	// }
	// else{
	// x=x+incXr;
	// y=y+incYr;
	// Av=Av+avR;
	//
	// }}
	//
	//
	// }else{}
/*
uint16_t incY,incYr;
uint16_t incX,incXr;
uint16_t pk_0;

uint16_t x_fin,avR,Avi,Av;
uint16_t x;
uint16_t y;
uint16_t d_x=x1-x0,d_y=y1-y0;


if (d_y>=0)
{
	incY=1;

}
else
{
	d_y=-d_y;
	incY=-1;
}




if (d_x>=0)
{
	incX=1;

}
else
{
	d_x=-d_x;
	incX=-1;
}




if (d_x>=d_y)
{
	incYr=0;
	incXr=incX;

}
else
{
	incXr=0;
	incYr=incY;
	pk_0=d_x;
	d_x=d_y;
	d_y=pk_0;
}
x=x0;
y=y0;
avR=2*d_y;
Av=avR-d_x;
Avi=Av-d_x;






while(x<=x1)
{	GENERADOR_DE_FORMAS(1,1,y,x,0xffff,0x0c);
	//	x+=1;

	if(Av>=0)
	{
		x=x+incX;
		y=y+incY;
		Av=Av+Avi;

	}
	else
	{
		x=x+incXr;
		y=y+incYr;
		Av=Av+avR;
	}

}








}
*/