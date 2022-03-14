

/*CUSTOM_CMD_SET_SD_MMC(0x58,0x00,0x00,0xff);
WRITE_MEMORY_SD_MMC(HOLA,512,0,0);*/


/*CMD18 LEER BLOQUE MULTIPLE
CUSTOM_CMD_SET_SD_MMC(0x18,0x00,0x00,0xff);*/

/*CMD24 ESCRIBIR BLOQUE UNICO
CUSTOM_CMD_SET_SD_MMC(0x58,0x00,0x00,0xff);*/


/*CMD25 ESCRIBIR BLOCK MULTIPLE
CUSTOM_CMD_SET_SD_MMC(0x19,0x00,0x00,0xff);*/

/*CMD28 ACTIVA PROTECCION CONTRA ESCRITURA
CUSTOM_CMD_SET_SD_MMC(0x19,0x00,0x00,0xff);*/

/*CMD29 DESACTIVA LA PROTECCION CONTRA ESCRITURA
CUSTOM_CMD_SET_SD_MMC(0x19,0x00,0x00,0xff);*/

/*CMD30 PIDE DETALLES DEL ESTADO DE PROTECCION CONTRA ESCRITURA
CUSTOM_CMD_SET_SD_MMC(0x19,0x00,0x00,0xff);*/

/*CMD32 ESTABLECE LA DIRECION DEL PRIMER BLOQUE QUE SE BORRARA
CUSTOM_CMD_SET_SD_MMC(0x19,0x00,0x00,0xff);*/

/*CMD33 ESTABLECE LA DIRECION DEL ULTIMO BLOQUE QUE SE BORRARA
CUSTOM_CMD_SET_SD_MMC(0x19,0x00,0x00,0xff);*/

/*CMD38 BORRA TODOS LOS BLOQUES SELECCIONADOS PREVIAMNTE
CUSTOM_CMD_SET_SD_MMC(0x19,0x00,0x00,0xff);*/


/*CMD17 LEER BLOQUE UNICO
CUSTOM_CMD_SET_SD_MMC(0x11,0x00,0x00,0xff);*/



#ifndef  SD_QVL_LIBRARY
#define SD_QVL_LIBRARY


#include <avr/io.h>
#include "LIBRERIA_DELAY_QVL.h"
#include "LIBRERIA_SPI_LCD_QVL.h"
uint32_t PESO_FILE_BYTE=0;
uint8_t BPB_NumFATs=0;
uint8_t BPB_SecPerClus=0;
uint8_t BPB_Media=0;
uint16_t FirstSectorofCluster=0;


uint16_t BPB_BytsPerSec=0;
uint16_t BPB_RsvdSecCnt=0;
uint16_t BPB_RootEntCnt=0;
uint16_t BPB_TotSec16=0;


uint32_t BPB_TotSec32=0;
uint16_t BPB_FATz16=0;
uint32_t BPB_FATz32=0;


uint16_t F_MBR,FAT16ClusEntryVal,FirstSectorOfCluster=0;


uint32_t BS_VolID=0;
uint16_t RootDirSectors=0;
uint32_t FATSz=0;


uint32_t TotSec=0;
uint32_t DataSec=0;
uint32_t CountofClusters=0;
uint32_t DskSize=0;

uint32_t FAT_AND_DATA_REGION=0,TmpVal2=0,FirstRootDirSecNum=0,FirstDataSector=0,
TYPPE_FAT=0,SIZE_FAT=0,FAT_Offset=0,NUMERO_CLUSTER_VALIDO=78,ThisFATSecNum=0,ThisFATEntOffset=0,SectorNumber=0,FAT32ClusEntryVal=0;


/*uint8_t READ_DATA[512];*/
uint16_t Var1,Var2,Var3,Var4,Var5,Ord,R_N,A,B,C,C1;
unsigned int READ_Root_Dir_MEMORY_SD_MMC(uint16_t,uint32_t,char[]);
/*PROTOTIPOS DE FUNCIONES*/
/*ESTA FUNCION PERMITE OBTENER LA INFORMACION DE LA PRIMERA PARTICION DEL MASTER BOOT RECORDS*/
unsigned int SEARCH_CLUSTER_FILE(uint16_t,char[]);

/*ESTA FUNCION SIRBE DE BASE PARA CREAR UNA FUNCION QUE PERMITA OBENER LA INFORMACION DEL SECTOR 0 DE LA MBR*/
void READ_MEMORY_SD_MMC_INFO(const uint16_t);

/*ESTA FUNCION SIRBE PARA LA ESCRITURA DE UN SECTOR ARGUMENTO (VECTOR_DE_DATOS_DEL_SECTOR[512],TAMAÑO_DEL_SECTOR=512,UBICACION_DEL_SECTOR_AESCRIBIR=X)*/
void WRITE_MEMORY_SD_MMC(uint8_t[],uint16_t,uint32_t);

/*ESTA FUNCION PARA LEER CUALQUIER SETOR INDIVIDUAL DE LA MEMORIA SD SUS SON PARAMETROS (TAMAÑO_DEL_SECTOR,UBICACION_DEL_SECTOR_A_ESCRIBIR)*/
void READ_MEMORY_SD_MMC(uint16_t,uint32_t);

/*ESTA FUNCION ENVIA EL COMANDO DE INICIALIZACION A LA TARJETA SD*/
void INT_SD_MMC(void);

/*ESTA FUNCION ES INPORTANTE YA QUE LO QUE HACE ES ENVIARLE MAS DE 80 PULSOS DE RELOJ A LA TARJETA SD CON EL OBJETIVO DE QUE ESTA PUED INICIAR EL MODO SPI*/
void RESET_SD_MMC(void);

/*ESTA FUNCION SE ENCARGA DE ESTABLECCER EL TAMAÑO QUE TENDRA CADA SECTOR EN LA TARJETA SD POR DEFECTO ESTE ES DE 512 bytes*/
void BLOCK_MEMORY_SET_SD_MMC(int16_t,int16_t);

/*ESTA FUNCION ME PERMITE ENVIAR COMANDOS, ESTABECIENDO COMO PARAMETROS VALORES ENTEROS (COMANDO_SPI,ARGUMENTO_MSB,ARGUMENTO_LSB,CHECKSUM) */
void CUSTOM_CMD_SET_SD_MMC(uint8_t, uint16_t,uint16_t,uint8_t);

/*ESTA FUNCION ES IGUAL QUE "CUSTOM_CMD_SET_SD_MMC();" SOLO QUE EN ESTA NO SE ACTIVA EL PIN SELET SLAVE*/
void CUSTOM_CMD_SET_SD(uint8_t,uint16_t,uint16_t,uint8_t,uint8_t);

/*ESTA FUNCION PERMITE LEER UN SECTOR DE LA TARJETA SD Y COPIARLO EN OTRO SECTOR QUE EL USUARIO QUIERA PREBIAMENTE HABIENDO ELEGIDO EN 1 EL TERCER PARAMETRO */
void READ_AND_COPY_MEMORY_SD_MMC(uint16_t,uint32_t,int,uint32_t);
/*PROTOTIPOS DE FUNCIONES*/

/*------------------------------------------------------------------*/
void RESET_SD_MMC(void){
for (int i=0;i!=1000;i++){PAUSE_FLUJO(0,1,0,1);PORTC^=(0b0000001<<PORTC3);}}
void INT_SD_MMC(void){/*CMD1*//*41 00 00 00 00 ff*/
PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(1,0,0,0xff,0x01);/*INICIALISCION DE LA TARJETA SD*/
PORTC^=(1<<PORTC0);}


/*------------------------------------------------------------------*/
void BLOCK_MEMORY_SET_SD_MMC(int16_t CMD_ARGUMENT_MSB,int16_t CMD_ARGUMENT_LSB){
/*CMD0*//*50 00 000 00 08 ff*/
PORTC^=(1<<PORTC0);
/*CONFIGURACION DEL TAMAÑO DEL BLOQUE DE MEMORIA QUE SE USARA PARA GUARDAR DATOS VALOR ES DE DEFAULT 512 bytes*/
CUSTOM_CMD_SET_SD(10,0,512,0xff,0x00);
PORTC^=(1<<PORTC0);}


/*------------------------------------------------------------------*/
void CUSTOM_CMD_SET_SD_MMC(uint8_t CMDX,uint16_t CMD_ARGUMENT_MSB,uint16_t CMD_ARGUMENT_LSB,uint8_t CRC){
/*CMD0*//*87 xx xx xx xx ff*/
PORTC^=(1<<PORTC0);
/*CONFIGURACION DEL TAMAÑO DEL BLOQUE DE MEMORIA QUE SE USARA PARA GUARDAR DATOS VALOR ES DE DEFAULT 512 bytes*/
CMDX=(CMDX);
CMDX=(CMDX|0b01000000);
SPI_MASTER_TRANSMITION_8_BITS(CMDX);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_MSB);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_LSB);
SPI_MASTER_TRANSMITION_8_BITS(CRC);
SPI_RECEIVE_MODE_MASTER_16BITS_();
PORTC^=(1<<PORTC0);}


/*------------------------------------------------------------------*/
void CUSTOM_CMD_SET_SD(uint8_t CMDX,uint16_t CMD_ARGUMENT_MSB,uint16_t CMD_ARGUMENT_LSB,uint8_t CRC,uint8_t ERROR){
/*CMD0*/
/*87 xx xx xx xx ff*/
/*CONFIGURACION DEL TAMAÑO DEL BLOQUE DE MEMORIA QUE SE USARA PARA GUARDAR DATOS VALOR ES DE DEFAULT 512 bytes*/
CMDX=(CMDX);
CMDX=(CMDX|0b01000000);
SPI_MASTER_TRANSMITION_8_BITS(CMDX);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_MSB);
SPI_MASTER_TRANSMITION_16_BITS(CMD_ARGUMENT_LSB);
SPI_MASTER_TRANSMITION_8_BITS(CRC);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=ERROR);
}


/*------------------------------------------------------------------*/
void WRITE_MEMORY_SD_MMC(uint8_t DATA[],uint16_t SIZE_SECTOR,uint32_t NUM_SECTORE){
PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(24,((NUM_SECTORE*SIZE_SECTOR)>>16),(NUM_SECTORE*SIZE_SECTOR),0xff,0x00);
SPI_MASTER_TRANSMITION_8_BITS(0xfe);
for(int i=0;i!=SIZE_SECTOR;i++){
SPI_MASTER_TRANSMITION_8_BITS(DATA[i]);}
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0x05);
PORTC^=(1<<PORTC0);
}


/*------------------------------------------------------------------*/
void READ_AND_COPY_MEMORY_SD_MMC(uint16_t SIZE_SECTOR,uint32_t NUM_SECTORE,int COPY,uint32_t NUM_SECTORE_1){
uint8_t READ_DATA[SIZE_SECTOR];
PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,((NUM_SECTORE*SIZE_SECTOR)>>16),(NUM_SECTORE*SIZE_SECTOR),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_DATA[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0x1100);
PORTC^=(1<<PORTC0);
if(COPY){WRITE_MEMORY_SD_MMC(READ_DATA,SIZE_SECTOR,NUM_SECTORE_1);}
}


/*------------------------------------------------------------------*/
void READ_MEMORY_SD_MMC(uint16_t SIZE_SECTOR,uint32_t NUM_SECTORE){
uint8_t READ_DATA[SIZE_SECTOR];
PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,((NUM_SECTORE*SIZE_SECTOR)>>16),(NUM_SECTORE*SIZE_SECTOR),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
PAUSE_FLUJO(2000,1,0,1);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_DATA[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0x1100);
PORTC^=(1<<PORTC0);
}

/*------------------------------------------------------------------*/
/*
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV*/
/*------------------------------------------------------------------*/

/*------------------------------------------------------------------*/

















unsigned int SEARCH_CLUSTER_FILE(uint16_t SIZE_SECTOR,char Y[]){char NOMBRE_DEL_ARCHIVO[11];
for(int i=0;i!=11;i++){
NOMBRE_DEL_ARCHIVO[i]=0x20;}
int i=0,EXTENCION_DEL_FILE=0;
while(i!=8){
if(Y[i]=='.'){EXTENCION_DEL_FILE=i;i=8;}
else{NOMBRE_DEL_ARCHIVO[i]=Y[i];
i++;}}
for(int i=8;i!=11;i++){EXTENCION_DEL_FILE++;
NOMBRE_DEL_ARCHIVO[i]=Y[EXTENCION_DEL_FILE];}
	if(TYPPE_FAT==16){FAT_Offset=READ_Root_Dir_MEMORY_SD_MMC(512,FirstRootDirSecNum,NOMBRE_DEL_ARCHIVO)*2;}else if(TYPPE_FAT==32){FAT_Offset=READ_Root_Dir_MEMORY_SD_MMC(512,FirstRootDirSecNum,NOMBRE_DEL_ARCHIVO)*4;}		ThisFATSecNum=BPB_RsvdSecCnt+(FAT_Offset/BPB_BytsPerSec);ThisFATEntOffset=(FAT_Offset%BPB_BytsPerSec);SectorNumber=(BPB_NumFATs*FATSz)+ThisFATSecNum;


FAT16ClusEntryVal=0;
unsigned int NUMERO_DE_SECTOR=0;
uint8_t READ_FAT[SIZE_SECTOR];


PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,((ThisFATSecNum*SIZE_SECTOR)>>16),(ThisFATSecNum*SIZE_SECTOR),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
PAUSE_FLUJO(2000,1,0,1);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_FAT[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0x1100);
PORTC^=(1<<PORTC0);


uint8_t FAT_L=0;

/*CON ESTAS CONDICIONES SE OPTIENE EL VALOR DE LA POSICION EN DECIMAL DE LA ENTRADA FAT CORRESPONDIENTE AL CLUSTER DESEADO FAT_Offset*/if(TYPPE_FAT==16){FAT_L=3;FAT16ClusEntryVal=READ_FAT[ThisFATEntOffset+1];FAT16ClusEntryVal=(FAT16ClusEntryVal<<8)|READ_FAT[ThisFATEntOffset];}/*------------------------------------------------------------------*/else{FAT_L=9;FAT32ClusEntryVal=READ_FAT[ThisFATEntOffset+1];FAT32ClusEntryVal=(FAT32ClusEntryVal<<8)|READ_FAT[ThisFATEntOffset];}
/*------------------------------------------------------------------*/


/*INDICA EL SECTOR INICIAL DONDE SE ALMACENAN LOS DATOS CORRESPONDIENTE A UN CLUSTER ESPESIFICO*/FirstSectorOfCluster=((FAT16ClusEntryVal-FAT_L)*BPB_SecPerClus)+FirstDataSector;
NUMERO_DE_SECTOR=FirstSectorOfCluster;



return NUMERO_DE_SECTOR;}
/*------------------------------------------------------------------*/
















unsigned int READ_Root_Dir_MEMORY_SD_MMC(uint16_t SIZE_SECTOR,uint32_t NUM_SECTORE,char Dir_Root[]){
PESO_FILE_BYTE=0x00000000;
unsigned int CLOUSTER=0x0000;
int NAMEP=0;
uint8_t READ_DATA_Root_dir_1[SIZE_SECTOR];
uint8_t READ_DATA_Root_dir_2[SIZE_SECTOR];
uint8_t DATA_Root_dir[512];


uint32_t VALID=0;
while (VALID!=1){
NUM_SECTORE=NUM_SECTORE+VALID;
Var1=1,Var2=0,Var3=0,Var4=0x0000,Var5=0,Ord=0x40,R_N=0,A=0,B=0,C=0,C1=0;
C=((NUM_SECTORE*SIZE_SECTOR)>>16);
C1=(NUM_SECTORE*SIZE_SECTOR);


PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,(((NUM_SECTORE+0)*SIZE_SECTOR)>>16),((NUM_SECTORE+0)*SIZE_SECTOR),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
PAUSE_FLUJO(2000,1,0,1);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_DATA_Root_dir_1[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0x1100);
PORTC^=(1<<PORTC0);

while (Var1!=17){
for(uint16_t i=0;i!=(512);i++){
DATA_Root_dir[i]=0x00;}

for(int i=0;i!=(32);i++){
DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}

if((DATA_Root_dir[11]==0x0f)&&(DATA_Root_dir[12]==0x00)){
Ord=DATA_Root_dir[0]-Ord;
Var1=Var1+(Ord);
R_N=((Ord+1)*32);
if((Var1)>16){//15+4
Var3=(Var1-16);//19-16=3
Var4=((Ord)-Var3);//4-3=1
A=Var3*32;
B=Var4*32;

PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,(((NUM_SECTORE+1)*SIZE_SECTOR)>>16),((NUM_SECTORE+1)*SIZE_SECTOR),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
PAUSE_FLUJO(2000,1,0,1);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_DATA_Root_dir_2[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0x1100);
PORTC^=(1<<PORTC0);

for(int i=0;i!=(B);i++){
DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}
for(int i=0;i!=(A);i++){
DATA_Root_dir[i+(B)]=READ_DATA_Root_dir_2[i];}
}else{
if ((Var1>=0)&&(Var1<=16)){
for(int i=0;i!=(R_N);i++){
DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}}}
Var2=Var2+(32*Ord);}



else{
if ((Var1>=0)&&(Var1<=16)){
for(int i=0;i!=(32);i++){
DATA_Root_dir[i]=READ_DATA_Root_dir_1[i+Var2];}


NAMEP=0;

for(int i=0;i!=(11);i++){
if (DATA_Root_dir[i]==Dir_Root[i]){
NAMEP++;}}

if((NAMEP==11)){
/*sacamos los 4 bytes que nos dicen el peso del archivo*/
for(int luis=31;luis!=27;luis--){
PESO_FILE_BYTE=(PESO_FILE_BYTE<<8)|DATA_Root_dir[luis];}



for(int luis=27;luis!=25;luis--){
CLOUSTER=(CLOUSTER<<8)|DATA_Root_dir[luis];}}
Var2=Var2+32;}}
Var1++;}
VALID++;}
return	CLOUSTER;}





































void READ_MBR(uint16_t SIZE_SECTOR);

void READ_MBR(uint16_t SIZE_SECTOR){

uint8_t READ_DATA[SIZE_SECTOR];
for(int i=0;i!=512;i++){
READ_DATA[i]=0x00;}

PORTC^=(1<<PORTC0);
CUSTOM_CMD_SET_SD(17,(0),(0),0xff,0x00);
do {} while (SPI_RECEIVE_MODE_MASTER_()!=0xfe);
for(int i=0;i!=(SIZE_SECTOR);i++){
READ_DATA[i]=SPI_RECEIVE_MODE_MASTER_();}
SPI_MASTER_TRANSMITION_16_BITS(0xEEAA);
PORTC^=(1<<PORTC0);

for (int i=0;i!=SIZE_SECTOR;i++){
/*NUMERO DE BYTE POR BLOQUE(SECTOR)*/
if(i==11){
for(int luis=12;luis!=10;luis--){
BPB_BytsPerSec=(BPB_BytsPerSec<<8)|READ_DATA[luis];}}
/*NUMERO DE BLOQUES(SECTOR) POR CLUSTER(UNIDAD DE ASIGNASION)*/
if(i==13){
BPB_SecPerClus=READ_DATA[13];
if(BPB_SecPerClus==0x04){}}
/*NUMERO DE BLOQUES RESERVADOS*/
if(i==14){
for(int luis=15;luis!=13;luis--){
BPB_RsvdSecCnt=(BPB_RsvdSecCnt<<8)|READ_DATA[luis];}
if(BPB_RsvdSecCnt==0x0001){}}
/*NUMERO DE TABLAS DE ASIGNACION DE ARCHIVOS(FATs)*/
if((i==16)){
BPB_NumFATs=READ_DATA[16];
if(BPB_NumFATs==0x02){}}
/*NUMERO DE ENTRADAS DEL DIRECTORIO RAIZ*/
if(i==17){
for(int luis=18;luis!=16;luis--){
BPB_RootEntCnt=(BPB_RootEntCnt<<8)|READ_DATA[luis];}
if(BPB_RootEntCnt==0x0200){}}
/*NUMERO DE TOTAL DE BLOQUES(SECTORES) EN TODO EL DISCO FTA16*/
if(i==19){
for(int luis=20;luis!=18;luis--){
BPB_TotSec16=(BPB_TotSec16<<8)|READ_DATA[luis];}}
// /*NUMERO DE TOTAL DE BLOQUES(SECTORES) EN TODO EL DISCO FTA32*/
// if(i==19){
// for(int luis=20;luis!=18;luis--){
// BPB_TotSec32=(BPB_TotSec32<<8)|READ_DATA[luis];}
// if(BPB_TotSec32==0x0000){}}
/*DESCRIPTOR DE MEDIOS*/
if((i==21)){
BPB_Media=READ_DATA[21];
if(BPB_Media==0xf8){}}
/*NUMERO DE BLOQUES OCUPADOS POR UNA FAT*/
if(i==22){
for(int luis=23;luis!=21;luis--){
BPB_FATz16=(BPB_FATz16<<8)|READ_DATA[luis];}
if(BPB_FATz16==0x0000){
for(int luis=39;luis!=35;luis--){
BPB_FATz32=(BPB_FATz32<<8)|READ_DATA[luis];}}}
/*NUMERO DE TOTAL DE BLOQUES(SECTORES) EN TODO EL DISCO FTA32*/
if((i==32)){
for(int luis=35;luis!=31;luis--){
BPB_TotSec32=(BPB_TotSec32<<8)|READ_DATA[luis];}
if(BPB_TotSec32==0x0003e5e0){}}
/*NUMERO DE SERIE DEL VOLUMEN*/
if((i==39)){
for(int luis=42;luis!=38;luis--){
BS_VolID=(BS_VolID<<8)|READ_DATA[luis];}
if(BS_VolID==0xf8){}}

/*FIRMA DEL BLOQUE DE ARRANQUE*/
if((i==510)){
for(int luis=511;luis!=509;luis--){
F_MBR=(F_MBR<<8)|READ_DATA[luis];}

}}

/*SECTORES OCUPADOS POR EL DIRECTORIO RAIZ*/
RootDirSectors=((BPB_RootEntCnt*32)+(BPB_BytsPerSec-1))/BPB_BytsPerSec;
/*-------------------------------------------------*/
if(BPB_FATz16==0){FATSz=BPB_FATz32;}
else{FATSz=BPB_FATz16;}
if(BPB_TotSec16==0){TotSec = BPB_TotSec32;}
else{TotSec=BPB_TotSec16;}


/*SECTORES TOTALES QUE CONPONEN LA UNIDAD DE ALMACENAMIENTO SD*/
DskSize=TotSec;
/*SECTORES TOTALES QUE CONPONEN LA REGION DE SOLO DATOS DE LA UNIDAD DE ALMACENAMIENTO SD*/
DataSec=DskSize-(BPB_RsvdSecCnt+(BPB_NumFATs*FATSz)+RootDirSectors);
/*NUMERO DE UNIDADES DE ASIGNACION(CLUSTER) QUE CONTIENE LA UIDAD DE ALMACENAMIENTO SD*/
CountofClusters=DataSec/BPB_SecPerClus;


/*CONDICIONES PARA ELEGIR EL TIPO DE FAT EN FUNCION DEL NUMERO DE UIDADES DE ASIGNACION(CLUSTER)*/
if(CountofClusters<4084){/*Volume is FAT12*/TYPPE_FAT=12;}else{
if(CountofClusters<65524){/*Volume is FAT16*/TYPPE_FAT=16;}
else {/*Volume is FAT32*/TYPPE_FAT=32;}}

/*SECTORES OCUPADOS POR LAS FAT Y LA REGION DE DATOS*/
FAT_AND_DATA_REGION=DskSize-(BPB_RsvdSecCnt+RootDirSectors);
TmpVal2=(256*BPB_SecPerClus)+BPB_NumFATs;


if(TYPPE_FAT==16){TmpVal2=TmpVal2*0.5;}
/*---------------------------------------------------------------------------------------------*/
else{if(TYPPE_FAT==32){BPB_FATz16=0;
BPB_FATz32=FATSz;}}
//else{BPB_FATz16=FATSz;}

SIZE_FAT=(FAT_AND_DATA_REGION+(TmpVal2-1))/TmpVal2;
FirstRootDirSecNum=BPB_RsvdSecCnt+(BPB_NumFATs*BPB_FATz16);
FirstDataSector=BPB_RsvdSecCnt+(BPB_NumFATs*FATSz)+RootDirSectors;}









#endif