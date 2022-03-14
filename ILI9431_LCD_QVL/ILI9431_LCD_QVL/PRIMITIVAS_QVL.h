/*
 * PRIMITIVAS_QVL.h
 *
 * Created: 11/8/2020 4:25:38 PM
 *  Author: el_lu
 */


#ifndef PRIMITIVAS_QVL_H_
#define PRIMITIVAS_QVL_H_
#include "LIBRERIA_SPI_LCD_QVL.h"
#include <avr/io.h>
/*-----------------------------------------------*/
void LINEAS_DRAW(const int16_t,const int16_t,const int16_t,const int16_t);
void LINEAS_DRAW(const int16_t x0,const int16_t y0,const int16_t x1,const int16_t y1){


int16_t incY,incYr;
int16_t incX,incXr;
int16_t pk_0;
int16_t x_fin,avR,Avi,Av;
int16_t x,x_1;
int16_t y,y_1;
int16_t d_x=x1-x0,d_y=y1-y0;
y_1=y1;
y=y0;
x_1=x1;
x=x0;


if(x0>x1){
d_x=x0-x1;
x=x1;
x_1=x0;}



if (d_y>=0){
incY=1;}
else{
d_y=-d_y;
incY=-1;}

if (d_x>=0){
incX=1;}
else{
d_x=-d_x;
incX=-1;}

if (d_x>=d_y){
incYr=0;
incXr=incX;}
else{
incXr=0;
incYr=incY;
pk_0=d_x;
d_x=d_y;
d_y=pk_0;}

avR=2*d_y;
Av=avR-d_x;
Avi=Av-d_x;

if(x==x_1){
while(y<=y_1){GENERADOR_DE_FORMAS(1,1,x,y,0,0x0c);y+=1;}

while(y>=y_1){GENERADOR_DE_FORMAS(1,1,x,y,0,0x0c);y-=1;}}

else{
while(x<=x_1){
GENERADOR_DE_FORMAS(1,1,x,y,0,0x0c);
if(Av>=0){
x=x+incX;
y=y+incY;
Av=Av+Avi;}
else{
x=x+incXr;
y=y+incYr;
Av=Av+avR;}
}}
}
void CIRCULOS_DRAW(const int16_t,const int16_t,const int16_t);
void CIRCULOS_DRAW(const int16_t COO_X,const int16_t COO_Y,const int16_t RADIUS){
int16_t P_0=1-RADIUS;
int16_t Y_INITIAL=RADIUS;
int16_t X_INITIAL=0;
while (X_INITIAL<=Y_INITIAL){
/*OCTANTE 1 Y 2*/
GENERADOR_DE_FORMAS(1,1,COO_X+X_INITIAL,COO_Y+Y_INITIAL,0,0x0c);
GENERADOR_DE_FORMAS(1,1,COO_Y+Y_INITIAL,COO_X+X_INITIAL,0,0x0c);
/*OCTANTE 3 Y 4*/
GENERADOR_DE_FORMAS(1,1,COO_X-X_INITIAL,COO_Y+Y_INITIAL,0,0x0c);
GENERADOR_DE_FORMAS(1,1,COO_Y-Y_INITIAL,COO_X+X_INITIAL,0,0x0c);
/*OCTANTE 5 Y 6*/
GENERADOR_DE_FORMAS(1,1,COO_X+X_INITIAL,COO_Y-Y_INITIAL,0,0x0c);
GENERADOR_DE_FORMAS(1,1,COO_Y+Y_INITIAL,COO_X-X_INITIAL,0,0x0c);
/*OCTANTE 7 Y 8*/
GENERADOR_DE_FORMAS(1,1,COO_X-X_INITIAL,COO_Y-Y_INITIAL,0,0x0c);
GENERADOR_DE_FORMAS(1,1,COO_Y-Y_INITIAL,COO_X-X_INITIAL,0,0x0c);

if (P_0<=0){
X_INITIAL+=1;
P_0=P_0+2*X_INITIAL+3;
}else{
X_INITIAL+=1;
Y_INITIAL-=1;
P_0=P_0+2*X_INITIAL-2*Y_INITIAL+1;}}
}

void GENERADOR_GEOMETRICO(uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint8_t);
void GENERADOR_GEOMETRICO(uint16_t ALTO,uint16_t ANCHO,uint16_t COOR_X,uint16_t COOR_Y,uint16_t CONTORNO,uint16_t COLOR,uint8_t CONTROL_){
uint16_t COLORS=COLOR;
GENERADOR_DE_FORMAS(ALTO,CONTORNO,COOR_X,COOR_Y,COLORS,CONTROL_);
GENERADOR_DE_FORMAS(CONTORNO,ALTO,COOR_X,COOR_Y,COLORS,CONTROL_);
GENERADOR_DE_FORMAS(ALTO,CONTORNO,COOR_X+ALTO-CONTORNO,COOR_Y,COLORS,CONTROL_);
GENERADOR_DE_FORMAS(CONTORNO,ALTO,COOR_X,COOR_Y+ALTO-CONTORNO,COLORS,CONTROL_);
}
void ELIPSE_DRAW(uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint16_t,uint8_t);
void ELIPSE_DRAW(uint16_t Rx,uint16_t Ry,uint16_t COOR_X,uint16_t COOR_Y,uint16_t CONTORNO,uint16_t COLOR,uint8_t CONTROL_){
int32_t Ry2=Ry*Ry;
int32_t Rx2=Rx*Rx;
int32_t _Y=Ry;
int32_t _X=0;
int32_t Rx_Y=2*Rx2*_Y;
int32_t Ry_X=2*Ry2*_X;
int32_t P1_0=(Ry2)-(Ry*Rx2)+(0.25*Rx2);
int32_t P2_0=0;
GENERADOR_DE_FORMAS(1,1,_X+COOR_X,_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,_X+COOR_X,-_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,-_X+COOR_X,_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,-_X+COOR_X,-_Y+COOR_Y,0x0FF0,0x0C);
while(Ry_X<Rx_Y){
_X+=1;
Ry_X=2*Ry2*_X;
if (P1_0<0){
P1_0=P1_0+(2*Ry2*_X)+(Ry2);
}else{
_Y-=1;
Rx_Y=2*Rx2*_Y;
P1_0=P1_0+(Ry_X)+(Ry2)-(Rx_Y);}
GENERADOR_DE_FORMAS(1,1,_X+COOR_X,_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,_X+COOR_X,-_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,-_X+COOR_X,_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,-_X+COOR_X,-_Y+COOR_Y,0x0FF0,0x0C);
}
P2_0=Ry2*(_X+0.5)*(_X+0.5)+Rx2*(_Y-1)*(_Y-1)-(Ry2*Rx2);
Rx_Y=2*Rx2*_Y;

while (_Y>0){
_Y-=1;
Rx_Y=2*Rx2*_Y;
if (P2_0>0){
P2_0=P2_0+Rx2-Rx_Y;}
else{
_X+=1;
Ry_X=2*Ry2*_X;
P2_0=P2_0+(Ry_X)+(Rx2)-(Rx_Y);}
GENERADOR_DE_FORMAS(1,1,_X+COOR_X,_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,_X+COOR_X,-_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,-_X+COOR_X,_Y+COOR_Y,0x0FF0,0x0C);
GENERADOR_DE_FORMAS(1,1,-_X+COOR_X,-_Y+COOR_Y,0x0FF0,0x0C);
}
}



#endif /* PRIMITIVAS_QVL_H_ */