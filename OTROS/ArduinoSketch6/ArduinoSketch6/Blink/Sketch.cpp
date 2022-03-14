/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */


//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
#include false 0;
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
const byte rows = 4;
const byte cols = 4;
char CLAVE[5];

int CONTROL=0;
int CONTROL_1=0;
int CLAVE_CONSTANTE=0;
byte rowPins[rows] = {3, 4, 5, 6};
byte colPins[cols] = {7, 8, 9, 10};
int position = 0;
int redPin = 13;
int greenPin = 11;


char* secretCode = "123";
char keys[rows][cols] = 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

  char key=' ';
  int ELEMENTO_1,ELEMENTO_2,RESULTADO_1;
  char CONTROL_S_R_M_D,RESULTADO_2;
  int CONTROL_2;
  
  /*-----------------------------------------------------------PROTOTIPOS DE FUNCIONES-----------------------------------------------------------------*/
int PRODUCTO(int RESULTADO_1);
int DIVISION(int RESULTADO_1);
int RESTA(int RESULTADO_1);
int SUMA(int RESULTADO_1);
char PROCESAMIENTO(char RESULTADO_2);
/*-----------------------------------------------------------PROTOTIPOS DE FUNCIONES-----------------------------------------------------------------*/


int SUMA(int R){

int RESULTADO=R;

return RESULTADO;
}



int RESTA(int R){

int RESULTADO=R;

return RESULTADO;
}

int PRODUCTO(int R){

int RESULTADO=R;

return RESULTADO;
}



int DIVISION(int R){

int RESULTADO=R;

return RESULTADO;
}





char PROCESAMIENTO(char R){

char RESULTADO=R;

switch(CONTROL_S_R_M_D){
case 'A':
SUMA(1);

break;


case'B':
RESTA(1);

break;


case'C':
PRODUCTO(1);

break;


case'D':
DIVISION(1);

break;
//case:
//break;



}





return RESULTADO;
}






Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);
//-------------------------
// Configuración
//-------------------------
void setup(){


/*lcd.init();  
lcd.backlight();
lcd.setCursor(0,0);
lcd.print(" CARGANDO.............."); 
delay(5000); 
lcd.clear();
lcd.setCursor(0, 0);
lcd.print(" BIENVENIDO"); 
lcd.setCursor(0, 1);
lcd.print("QVL services");    
delay(2000); 
lcd.clear();
 for(int o=0;o<5;o++){
   delay(500);
lcd.scrollDisplayLeft();}*/ 




  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  setLocked(true);}
//-------------------------
// Bucle principal
//-------------------------
void loop(){

delay(5000);
  while(key != '*' || key != '#'){
       position = 0;
       
       
       
       
       
       
       
/*--------------------------------------------------------------ADQUISICION DE DATOS POR TECLADO--------------------------------------------------------------*/
while(CONTROL_1!=3){
  key = keypad.getKey();
if(key == '0' || key == '1'|| key == '2'|| key == '3'|| key == '4'|| key == '5'|| key == '6'|| key == '7'|| key == '8'|| key == '9' /* || key == 'A'|| key == 'B'|| key == 'C'|| key == 'D'*/){
CLAVE[CONTROL_1]=key;
Serial.println(CLAVE[CONTROL_1]);
CONTROL_1=CONTROL_1+1;
Serial.println(key);
if (key == secretCode[position]){
Serial.println(secretCode[position]);
position ++;}
if(position == 3){
setLocked(false);}
delay(100);
  }
/*--------------------------------------------------------------ADQUISICION DE DATOS POR TECLADO--------------------------------------------------------------*/
  
  
  
  
  
/*--------------------------------------------------------------EN ESTA PARTE SE REALIZA LA LLAMADA A LA FUNCION DE PROCESAMIENTO DE LOS OPERADORES--------------------------------------------------------------*/
  if(key == '*' || key == '#'){  
  PROCESAMIENTO(key);
      setLocked(true);
    position=0;
    CONTROL_1=0;}
/*--------------------------------------------------------------EN ESTA PARTE SE REALIZA LA LLAMADA A LA FUNCION DE PROCESAMIENTO DE LOS OPERADORES--------------------------------------------------------------*/
   
  }    
  
  
  
  
    }
    
  delay(100);
    
  }

void setLocked(int locked){
  if (locked){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);}
  else{
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);}}

