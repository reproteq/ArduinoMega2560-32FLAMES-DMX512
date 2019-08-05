/*
FLAME CONTROLLER FOR FIREONE 32CUE + ARDUINO MEGA 2560 + DMX SHIELD CTC-DRA-10-R2 
-------------------------------------------------------------
Flame machine DMX512 COMMANDS
1 CH  FLAME 1         0-255 : 0-199 OFF   200-255 ON 
2 CH  FLAME 2         0-255 : 0-199 OFF   200-255 ON
3 CH  FLAME 3         0-255 : 0-199 OFF   200-255 ON
4 CH  FLAME 4         0-255 : 0-199 OFF   200-255 ON
5 CH  FLAME 5         0-255 : 0-199 OFF   200-255 ON
6 CH  FLAME PILOT     0-255 : 0-199 OFF   200-255 ON 
-------------------------------------------------------------
DMX SHIELD CTC-DRA-10-R2  
jumpers config:
EN(run) <==  EN¯ (updt fw) ! Para actualizar el firmware de arduino desconectar la bateria tan solo conectar usb
Slave   ==>  DE  (master)
TX-io   <==  TX-uart
RX-io   <==  RX-uart
Pins 2,3,4 pines usados para trasnmitir las señales DMX
------------------------------------------------------------
libs
//https://github.com/PaulStoffregen/DmxSimple
---------------------------------------------------------
Arduino buttons pullup hardware layout:
5V___Button____R10k ___Gnd
           |___Arduino pins                   
---------------------------------------------------------
Display   :  Arduino
        
1  VSS GND     marron
2 VDD +5V     rojo
3 V0 --> R450Ohm >> gnd   rosa
4 RS PIN7     amar
5 RW GND      
6 EN PIN8     azul-marino
7 D0      
8 D1      
9 D2      
10  D3      
11  D4 pin 9      marron
12  D5 pin 10     rojo
13  D6 pin 11     rosa
14  D7 pin 12     amar
15  A -> R220 ->5v    verde
16  K  gnd      azul-marino
---------------------------------------------------------
*/

// incluimos librerias dmx y lcd
#include <DmxSimple.h> 
#include <LiquidCrystal.h>

// configuramos los pines que usara el LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //    ( RS, EN, d4, d5, d6, d7)

// variables para la asignacion de pines de arduino a botones 
const int buttonPin1 =  22;      
const int buttonPin2 =  23;     
const int buttonPin3 =  24;     
const int buttonPin4 =  25;     
const int buttonPin5 =  26;    
const int buttonPin6 =  27;     
const int buttonPin7 =  28;    
const int buttonPin8 =  29;     
const int buttonPin9 =  30;
const int buttonPin10 = 31;        
const int buttonPin11 = 32;       
const int buttonPin12 = 33;                            
const int buttonPin13 = 34;       
const int buttonPin14 = 35;        
const int buttonPin15 = 36; 
const int buttonPin16 = 37; 
const int buttonPin17 = 38; 
const int buttonPin18 = 39; 
const int buttonPin19 = 40; 
const int buttonPin20 = 41; 
const int buttonPin21 = 42; 
const int buttonPin22 = 43; 
const int buttonPin23 = 44; 
const int buttonPin24 = 45; 
const int buttonPin25 = 46; 
const int buttonPin26 = 47; 
const int buttonPin27 = 48; 
const int buttonPin28 = 49; 
const int buttonPin29 = 50; 
const int buttonPin30 = 51; 
const int buttonPin31 = 52; 
const int buttonPin32 = 53;

// variables para el estado de los botones
int buttonState1;                        
int buttonState2;                        
int buttonState3;
int buttonState4; 
int buttonState5; 
int buttonState6; 
int buttonState7; 
int buttonState8; 
int buttonState9; 
int buttonState10;
int buttonState11;
int buttonState12;
int buttonState13;
int buttonState14;
int buttonState15;
int buttonState16; 
int buttonState17;
int buttonState18;
int buttonState19;
int buttonState20;
int buttonState21;
int buttonState22;
int buttonState23;
int buttonState24;
int buttonState25;
int buttonState26;
int buttonState27;
int buttonState28;
int buttonState29;
int buttonState30;
int buttonState31;
int buttonState32;

// variables para el estado del retraso del rebote del boton
int buttonStateDebounced1;                       
int buttonStateDebounced2;                      
int buttonStateDebounced3; 
int buttonStateDebounced4; 
int buttonStateDebounced5; 
int buttonStateDebounced6; 
int buttonStateDebounced7; 
int buttonStateDebounced8; 
int buttonStateDebounced9; 
int buttonStateDebounced10; 
int buttonStateDebounced11; 
int buttonStateDebounced12; 
int buttonStateDebounced13; 
int buttonStateDebounced14; 
int buttonStateDebounced15; 
int buttonStateDebounced16; 
int buttonStateDebounced17; 
int buttonStateDebounced18; 
int buttonStateDebounced19; 
int buttonStateDebounced20; 
int buttonStateDebounced21; 
int buttonStateDebounced22; 
int buttonStateDebounced23; 
int buttonStateDebounced24; 
int buttonStateDebounced25; 
int buttonStateDebounced26; 
int buttonStateDebounced27; 
int buttonStateDebounced28;
int buttonStateDebounced29; 
int buttonStateDebounced30; 
int buttonStateDebounced31; 
int buttonStateDebounced32; 

// variables para mantener el estado del boton
int buttonStateSave1;               
int buttonStateSave2;                 
int buttonStateSave3; 
int buttonStateSave4; 
int buttonStateSave5; 
int buttonStateSave6; 
int buttonStateSave7; 
int buttonStateSave8; 
int buttonStateSave9; 
int buttonStateSave10; 
int buttonStateSave11; 
int buttonStateSave12; 
int buttonStateSave13; 
int buttonStateSave14; 
int buttonStateSave15; 
int buttonStateSave16; 
int buttonStateSave17; 
int buttonStateSave18; 
int buttonStateSave19; 
int buttonStateSave20; 
int buttonStateSave21; 
int buttonStateSave22; 
int buttonStateSave23; 
int buttonStateSave24; 
int buttonStateSave25; 
int buttonStateSave26; 
int buttonStateSave27; 
int buttonStateSave28;
int buttonStateSave29; 
int buttonStateSave30; 
int buttonStateSave31; 
int buttonStateSave32; 

//variable para estado de la  bandera de trabajo 
int working = 0; // inicializamos la variable bandera de trabajo abajo
  
//setup
void setup() {    
  lcd.begin(16, 2); // inicializar el LCD
  lcd.setCursor(0, 0); //inicializamos la posicion del cursor lcd a la primera linea
  lcd.print("PIROTOMAS   2019"); // Enviar el mensaje     
  lcd.setCursor(0, 1); //inicializamos la posicion del cursor lcd a la segunda linea
  lcd.print("FLAMEONE TT FW.6"); // Enviar el mensaje 
  pinMode(2, OUTPUT); // inicializamos el pin de salida para el shield dmx
  digitalWrite(2, HIGH); // inicializamos el pin de escritura para el shield dmx
  DmxSimple.usePin(4); // // inicializamos el pin  para el shield dmx
  DmxSimple.maxChannel(6); //number of channels
  
  // inicializamos los pins de arduino como botones de entradas
  pinMode(buttonPin1, INPUT);     
  pinMode(buttonPin2, INPUT);     
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin8, INPUT);
  pinMode(buttonPin9, INPUT);
  pinMode(buttonPin10, INPUT);
  pinMode(buttonPin11, INPUT);
  pinMode(buttonPin12, INPUT);
  pinMode(buttonPin13, INPUT);
  pinMode(buttonPin14, INPUT);
  pinMode(buttonPin15, INPUT);
  pinMode(buttonPin16, INPUT);
  pinMode(buttonPin17, INPUT);
  pinMode(buttonPin18, INPUT);
  pinMode(buttonPin19, INPUT);
  pinMode(buttonPin20, INPUT);
  pinMode(buttonPin21, INPUT);
  pinMode(buttonPin22, INPUT);
  pinMode(buttonPin23, INPUT);
  pinMode(buttonPin24, INPUT);
  pinMode(buttonPin25, INPUT);
  pinMode(buttonPin26, INPUT);
  pinMode(buttonPin27, INPUT);
  pinMode(buttonPin28, INPUT);
  pinMode(buttonPin29, INPUT);
  pinMode(buttonPin30, INPUT);
  pinMode(buttonPin31, INPUT);
  pinMode(buttonPin32, INPUT);
  
  // leemos y almacenamos el estado inicial de los pins de los botones
  buttonStateSave1 = digitalRead(buttonPin1); 
  buttonStateSave2 = digitalRead(buttonPin2);  
  buttonStateSave3 = digitalRead(buttonPin2);
  buttonStateSave4 = digitalRead(buttonPin2); 
  buttonStateSave5 = digitalRead(buttonPin2); 
  buttonStateSave6 = digitalRead(buttonPin2); 
  buttonStateSave7 = digitalRead(buttonPin2); 
  buttonStateSave8 = digitalRead(buttonPin2); 
  buttonStateSave9 = digitalRead(buttonPin2); 
  buttonStateSave10 = digitalRead(buttonPin2);
  buttonStateSave11 = digitalRead(buttonPin2);
  buttonStateSave12 = digitalRead(buttonPin2);
  buttonStateSave13 = digitalRead(buttonPin2);
  buttonStateSave14 = digitalRead(buttonPin2);
  buttonStateSave15 = digitalRead(buttonPin2);
  buttonStateSave16 = digitalRead(buttonPin2); 
  buttonStateSave17 = digitalRead(buttonPin2);
  buttonStateSave18 = digitalRead(buttonPin2);
  buttonStateSave19 = digitalRead(buttonPin2);
  buttonStateSave20 = digitalRead(buttonPin2);
  buttonStateSave21 = digitalRead(buttonPin2);
  buttonStateSave22 = digitalRead(buttonPin2);
  buttonStateSave23 = digitalRead(buttonPin2);
  buttonStateSave24 = digitalRead(buttonPin2);
  buttonStateSave25 = digitalRead(buttonPin2);
  buttonStateSave26 = digitalRead(buttonPin2);
  buttonStateSave27 = digitalRead(buttonPin2);
  buttonStateSave28 = digitalRead(buttonPin2);
  buttonStateSave29 = digitalRead(buttonPin2);
  buttonStateSave30 = digitalRead(buttonPin2);
  buttonStateSave31 = digitalRead(buttonPin2);
  buttonStateSave32 = digitalRead(buttonPin2);
}

//bucle
void loop(){

  // leemos los botones de entrada y almacenamos su estado
  buttonState1 = digitalRead(buttonPin1);  
  buttonState2 = digitalRead(buttonPin2);   
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  buttonState5 = digitalRead(buttonPin5);
  buttonState6 = digitalRead(buttonPin6);
  buttonState7 = digitalRead(buttonPin7);
  buttonState8 = digitalRead(buttonPin8);
  buttonState9 = digitalRead(buttonPin9);
  buttonState10 = digitalRead(buttonPin10);
  buttonState11 = digitalRead(buttonPin11);
  buttonState12 = digitalRead(buttonPin12);
  buttonState13 = digitalRead(buttonPin13);
  buttonState14 = digitalRead(buttonPin14);
  buttonState15 = digitalRead(buttonPin15);
  buttonState16 = digitalRead(buttonPin16);
  buttonState17 = digitalRead(buttonPin17);
  buttonState18 = digitalRead(buttonPin18);
  buttonState19 = digitalRead(buttonPin19);
  buttonState20 = digitalRead(buttonPin20);
  buttonState21 = digitalRead(buttonPin21);
  buttonState22 = digitalRead(buttonPin22);
  buttonState23 = digitalRead(buttonPin23);
  buttonState24 = digitalRead(buttonPin24);
  buttonState25 = digitalRead(buttonPin25);
  buttonState26 = digitalRead(buttonPin26);
  buttonState27 = digitalRead(buttonPin27);
  buttonState28 = digitalRead(buttonPin28);
  buttonState29 = digitalRead(buttonPin29);
  buttonState30 = digitalRead(buttonPin30);
  buttonState31 = digitalRead(buttonPin31);
  buttonState32 = digitalRead(buttonPin32);  
  
  //espera de ajuste
  delay(10); 
  
  // leemos otra vez y almacenamos en otra variable distinta para luego comprobar posibles saltos
  buttonStateDebounced1 = digitalRead(buttonPin1); 
  buttonStateDebounced2 = digitalRead(buttonPin2);
  buttonStateDebounced3 = digitalRead(buttonPin3);
  buttonStateDebounced4 = digitalRead(buttonPin4);
  buttonStateDebounced5 = digitalRead(buttonPin5);
  buttonStateDebounced6 = digitalRead(buttonPin6);
  buttonStateDebounced7 = digitalRead(buttonPin7);
  buttonStateDebounced8 = digitalRead(buttonPin8);
  buttonStateDebounced9 = digitalRead(buttonPin9);
  buttonStateDebounced10 = digitalRead(buttonPin10);
  buttonStateDebounced11 = digitalRead(buttonPin11);
  buttonStateDebounced12 = digitalRead(buttonPin12);
  buttonStateDebounced13 = digitalRead(buttonPin13);
  buttonStateDebounced14 = digitalRead(buttonPin14);
  buttonStateDebounced15 = digitalRead(buttonPin15);
  buttonStateDebounced16 = digitalRead(buttonPin16);
  buttonStateDebounced17 = digitalRead(buttonPin17);
  buttonStateDebounced18 = digitalRead(buttonPin18);
  buttonStateDebounced19 = digitalRead(buttonPin19);
  buttonStateDebounced20 = digitalRead(buttonPin20);
  buttonStateDebounced21 = digitalRead(buttonPin21);
  buttonStateDebounced22 = digitalRead(buttonPin22);
  buttonStateDebounced23 = digitalRead(buttonPin23);
  buttonStateDebounced24 = digitalRead(buttonPin24);
  buttonStateDebounced25 = digitalRead(buttonPin25);
  buttonStateDebounced26 = digitalRead(buttonPin26);
  buttonStateDebounced27 = digitalRead(buttonPin27);
  buttonStateDebounced28 = digitalRead(buttonPin28);
  buttonStateDebounced29 = digitalRead(buttonPin29);
  buttonStateDebounced30 = digitalRead(buttonPin30);
  buttonStateDebounced31 = digitalRead(buttonPin31);
  buttonStateDebounced32 = digitalRead(buttonPin32);   
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia 1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState1 == buttonStateDebounced1) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState1 != buttonStateSave1) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState1 == LOW) {          // comprueba si el boton esta pulsado
       //secuencia  1 200ms
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.1       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1               "); // Enviar el mensaje 
       DmxSimple.write(1, 255 );
       delay (200 );
       DmxSimple.write(1, 0 );         
       working = 0; // variable bandera de trabajo abajo
      }
    }
    buttonStateSave1 = buttonState1;  // guardar el nuevo estado en la variable
  }
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
//secuencia2  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
  if (working == 0 && buttonState2 == buttonStateDebounced2) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState2 != buttonStateSave2) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState2 == LOW) {          // comprueba si el boton esta pulsado
       //secuencia  2 200ms
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.2       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("2               "); // Enviar el mensaje 
       DmxSimple.write(2, 255 );
       delay (200 );
       DmxSimple.write(2, 0 );    
       working = 0; // variable bandera de trabajo abajo 
      }
    }
    buttonStateSave2 = buttonState2;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState3 == buttonStateDebounced3) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState3 != buttonStateSave3) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState3 == LOW) {  // comprobamos si el boton esta presionado
       //secuencia  3 200ms
       working = 1; // variable bandera de trabajo arriba 
       lcd.setCursor(0, 0);
       lcd.print("SW.3       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje 
       DmxSimple.write(3, 255 );
       delay (200 );
       DmxSimple.write(3, 0 );  
       working = 0; // variable bandera de trabajo abajo 
      }
    }
    buttonStateSave3 = buttonState3;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia4 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState4 == buttonStateDebounced4) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState4 != buttonStateSave4) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState4 == LOW) {  // comprobamos si el boton esta presionado
       //secuencia  4 200ms
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.4       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("4               "); // Enviar el mensaje        
       DmxSimple.write(4, 255 );
       delay (200 );
       DmxSimple.write(4, 0 );  
       working = 0; // variable bandera de trabajo abajo    
      }
    }
    buttonStateSave4 = buttonState4;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia5  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState5 == buttonStateDebounced5) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState5 != buttonStateSave5) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState5 == LOW) {  // comprobamos si el boton esta presionado
       //secuencia  5 200ms
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.5       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5               "); // Enviar el mensaje 
       DmxSimple.write(5, 255 );
       delay (200 );
       DmxSimple.write(5, 0 );  
       working = 0; // variable bandera de trabajo abajo 
      }
    }
    buttonStateSave5 = buttonState5;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia6 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState6 == buttonStateDebounced6) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState6 != buttonStateSave6) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState6 == LOW) {          // comprueba si el boton esta pulsado   
       //secuencia  1 600ms
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.6       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1               "); // Enviar el mensaje        
       DmxSimple.write(1, 255 );
       delay (600 );
       DmxSimple.write(1, 0 );  
       working = 0; // variable bandera de trabajo abajo          
      }
    }
    buttonStateSave6 = buttonState6;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia7
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState7 == buttonStateDebounced7) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState7 != buttonStateSave7) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState7 == LOW) {          // comprueba si el boton esta pulsado 
       //secuencia  2 600ms
     working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.7       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("2               "); // Enviar el mensaje   
       DmxSimple.write(2, 255 );
       delay (600 );
       DmxSimple.write(2, 0 );   
       working = 0; // variable bandera de trabajo abajo   
      }
    }
    buttonStateSave7 = buttonState7;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia8
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState8 == buttonStateDebounced8) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState8 != buttonStateSave8) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState8 == LOW) {  // comprobamos si el boton esta presionado
        //secuencia  3 600ms
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.8       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje        
       DmxSimple.write(3, 255 );
       delay (600 );
       DmxSimple.write(3, 0 );  
       working = 0; // variable bandera de trabajo abajo 
      }
    }
    buttonStateSave8 = buttonState8;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia9  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState9 == buttonStateDebounced9) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState9 != buttonStateSave9) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState9 == LOW) {          // comprueba si el boton esta pulsado  
       //secuencia  4 600ms
     working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.9       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("4               "); // Enviar el mensaje 
       DmxSimple.write(4, 255 );
       delay (600 );
       DmxSimple.write(4, 0 );   
       working = 0; // variable bandera de trabajo abajo 
      }
    }
    buttonStateSave9 = buttonState9;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia10  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState10 == buttonStateDebounced10) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState10 != buttonStateSave10) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState10 == LOW) {  // comprobamos si el boton esta presionado
       //secuencia  5 600ms
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.10      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5               "); // Enviar el mensaje                  
       DmxSimple.write(5, 255 );
       delay (600 );
       DmxSimple.write(5, 0 );  
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave10 = buttonState10;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia11  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState11 == buttonStateDebounced11) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState11 != buttonStateSave11) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState11 == LOW) {  // comprobamos si el boton esta presionado
       // simultanea  2,4  600ms
     working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.11      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("24              "); // Enviar el mensaje 
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (600 );  
       DmxSimple.write(2, 0 );   
       DmxSimple.write(4, 0 ); 
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave11 = buttonState11;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia12  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState12 == buttonStateDebounced12) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState12 != buttonStateSave12) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState12 == LOW) {  // comprobamos si el boton esta presionado
       // simultanea  1,3,5  600ms 
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.12      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("135             "); // Enviar el mensaje 
       DmxSimple.write(1, 255 );
       DmxSimple.write(3, 255 );
       DmxSimple.write(5, 255 );
       delay (600 );  
       DmxSimple.write(1, 0 );   
       DmxSimple.write(3, 0 );
       DmxSimple.write(5, 0 );       
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave12 = buttonState12;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia13  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState13 == buttonStateDebounced13) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState13 != buttonStateSave13) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState13 == LOW) {  // comprobamos si el boton esta presionado
       // simultanea 1,2,3,4,5 600ms 
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.13      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("12345           "); // Enviar el mensaje 
       // abrir todos los inyectores 
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );  
       DmxSimple.write(3, 255 );  
       DmxSimple.write(4, 255 );  
       DmxSimple.write(5, 255 );
       delay (600 );    
       // cerrar todos los inyectores
       DmxSimple.write(1, 0 );  
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 0 );  
       DmxSimple.write(4, 0 );  
       DmxSimple.write(5, 0 );    
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave13 = buttonState13;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia14  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState14 == buttonStateDebounced14) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState14 != buttonStateSave14) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState14 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 1,2,3,4,5 200ms 
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.14      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5          "); // Enviar el mensaje 
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (200 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (200 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (200 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (200 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (200 );    
       DmxSimple.write(5, 0 );       
       working = 0; // variable bandera de trabajo abajo   
      }
    }
    buttonStateSave14 = buttonState14;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia15  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState15 == buttonStateDebounced15) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState15 != buttonStateSave15) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState15 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 5,4,3,2,1 200ms
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.15      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5 -> 1          "); // Enviar el mensaje
       // abrir cerrar uno a uno 
       DmxSimple.write(5, 255 );
       delay (200 ); 
       DmxSimple.write(5, 0 ); 
       DmxSimple.write(4, 255 );
       delay (200 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (200 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (200 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (200 );    
       DmxSimple.write(1, 0 );         
       working = 0; // variable bandera de trabajo abajo    
      }
    }
    buttonStateSave15 = buttonState15;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia16  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState16 == buttonStateDebounced16) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState16 != buttonStateSave16) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState3 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 1,2,3,4,5,4,3,2,1 200ms 
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.16      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5 -> 1     "); // Enviar el mensaje 
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (200 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (200 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (200 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (200 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (200 );    
       DmxSimple.write(5, 0 );   
       DmxSimple.write(4, 255 );
       delay (200 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (200 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (200 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (200 );    
       DmxSimple.write(1, 0 );       
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave16 = buttonState16;  // guardar el nuevo estado en la variable
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState17 == buttonStateDebounced17) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState17 != buttonStateSave1) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState17 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 5,4,3,2,1,2,3,4,5  200ms  
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.17      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5 -> 1 -> 5     "); // Enviar el mensaje
       // abrir cerrar uno a uno 
       DmxSimple.write(5, 255 );
       delay (200 ); 
       DmxSimple.write(5, 0 ); 
       DmxSimple.write(4, 255 );
       delay (200 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (200 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (200 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (200 );    
       DmxSimple.write(1, 0 );   
       DmxSimple.write(2, 255 );
       delay (200 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (200 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (200 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (200 );    
       DmxSimple.write(5, 0 );  
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave17 = buttonState17;  // guardar el nuevo estado en la variable
  }
  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
//secuencia18  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
  if (working == 0 && buttonState18 == buttonStateDebounced18) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState18 != buttonStateSave18) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState18 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 3,2-4, 1-5, 2-4, 3  200ms
     working = 1; // variable bandera de trabajo arriba   
       lcd.setCursor(0, 0);
       lcd.print("SW.18      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3,24,15,24,3    "); // Enviar el mensaje
       // abrir cerrar uno a uno 
       DmxSimple.write(3, 255 );
       delay (200 ); 
       DmxSimple.write(3, 0 ); 
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (200 );  
       DmxSimple.write(2, 0 );
       DmxSimple.write(4, 0 );
       DmxSimple.write(1, 255 );
       DmxSimple.write(5, 255 );
       delay (200 ); 
       DmxSimple.write(1, 0 );
       DmxSimple.write(5, 0 );
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (200 );  
       DmxSimple.write(2, 0 );
       DmxSimple.write(4, 0 );                       
       DmxSimple.write(3, 255 );
       delay (200 );  
       DmxSimple.write(3, 0 );      
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave18 = buttonState18;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState19 == buttonStateDebounced19) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState19 != buttonStateSave19) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState19 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 1-5, 2-4, 3, 2-4, 1-5 200ms
     working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.19      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("15,24,3,24,15   "); // Enviar el mensaje
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       DmxSimple.write(5, 255 );
       delay (200 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(5, 0 );
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (200 );  
       DmxSimple.write(2, 0 );
       DmxSimple.write(4, 0 );
       DmxSimple.write(3, 255 );
       delay (200 ); 
       DmxSimple.write(3, 0 );
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (200 );  
       DmxSimple.write(2, 0 );
       DmxSimple.write(4, 0 );                        
       DmxSimple.write(1, 255 );
       DmxSimple.write(5, 255 );
       delay (200 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(5, 0 );
       working = 0; // variable bandera de trabajo abajo    
      }
    }
    buttonStateSave19 = buttonState19;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia20
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState20 == buttonStateDebounced20) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState20 != buttonStateSave20) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState20 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 1-5, 2-4, 3, 2-4, 1-5 200ms 
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.20      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("15,24,3,24,15   "); // Enviar el mensaje
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       DmxSimple.write(5, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(5, 0 );
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (100 );  
       DmxSimple.write(2, 0 );
       DmxSimple.write(4, 0 );
       DmxSimple.write(3, 255 );
       delay (100 ); 
       DmxSimple.write(3, 0 );
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (100 );  
       DmxSimple.write(2, 0 );
       DmxSimple.write(4, 0 );                        
       DmxSimple.write(1, 255 );
       DmxSimple.write(5, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(5, 0 );
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave20 = buttonState20;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState21 == buttonStateDebounced21) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState21 != buttonStateSave21) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState21 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 1,2,3,4,5 100ms  x3
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.21   100ms x3"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5          "); // Enviar el mensajeje    
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (100 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (100 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (100 );    
       DmxSimple.write(5, 0 );  
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (100 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (100 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (100 );    
       DmxSimple.write(5, 0 );  
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (100 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (100 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (100 );    
       DmxSimple.write(5, 0 );       
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave21 = buttonState21;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState22 == buttonStateDebounced22) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState22 != buttonStateSave22) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState22 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 5,4,3,2,1 100ms x3
       working = 1; // variable bandera de trabajo arriba   
       lcd.setCursor(0, 0);
       lcd.print("SW.22   100ms x3"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5 -> 1          "); // Enviar el mensaje
       // abrir cerrar uno a uno 
       DmxSimple.write(5, 255 );
       delay (100 ); 
       DmxSimple.write(5, 0 ); 
       DmxSimple.write(4, 255 );
       delay (100 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (100 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (100 );    
       DmxSimple.write(1, 0 );    
       // abrir cerrar uno a uno 
       DmxSimple.write(5, 255 );
       delay (100 ); 
       DmxSimple.write(5, 0 ); 
       DmxSimple.write(4, 255 );
       delay (100 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (100 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (100 );    
       DmxSimple.write(1, 0 );  
       // abrir cerrar uno a uno 
       DmxSimple.write(5, 255 );
       delay (100 ); 
       DmxSimple.write(5, 0 ); 
       DmxSimple.write(4, 255 );
       delay (100 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (100 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (100 );    
       DmxSimple.write(1, 0 );       
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave22 = buttonState22;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia23
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState23 == buttonStateDebounced23) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState23 != buttonStateSave23) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState23 == LOW) {  // comprobamos si el boton esta presionado
       //consecutivas 1,2,3,4,5,4,3,2,1 100ms x3
       working = 1; // variable bandera de trabajo arriba    
       lcd.setCursor(0, 0);
       lcd.print("SW.23   100ms x3"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5 -> 1     "); // Enviar el mensaje
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (100 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (100 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (100 );    
       DmxSimple.write(5, 0 );   
       DmxSimple.write(4, 255 );
       delay (100 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (100 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (100 );    
       DmxSimple.write(1, 0 );    
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (100 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (100 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (100 );    
       DmxSimple.write(5, 0 );   
       DmxSimple.write(4, 255 );
       delay (100 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (100 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (100 );    
       DmxSimple.write(1, 0 );   
       // abrir cerrar uno a uno 
       DmxSimple.write(1, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 ); 
       DmxSimple.write(2, 255 );
       delay (100 );        
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(4, 255 );  
       delay (100 );  
       DmxSimple.write(4, 0 );          
       DmxSimple.write(5, 255 );
       delay (100 );    
       DmxSimple.write(5, 0 );   
       DmxSimple.write(4, 255 );
       delay (100 );        
       DmxSimple.write(4, 0 );  
       DmxSimple.write(3, 255 );  
       delay (100 ); 
       DmxSimple.write(3, 0 );      
       DmxSimple.write(2, 255 );  
       delay (100 );  
       DmxSimple.write(2, 0 );          
       DmxSimple.write(1, 255 );
       delay (100 );    
       DmxSimple.write(1, 0 ); 
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave23 = buttonState23;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState24 == buttonStateDebounced24) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState24 != buttonStateSave24) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState24 == LOW) {  // comprobamos si el boton esta presionado
       //secuencia 24 battuka
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.24   batukada"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("12 -> 45        "); // Enviar el mensaje
       //battuka iz
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );
       delay (400 );  
       DmxSimple.write(1, 0 );
       DmxSimple.write(2, 0 );
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );
       delay (200 );  
       DmxSimple.write(1, 0 );
       DmxSimple.write(2, 0 );
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );
       delay (200 );  
       DmxSimple.write(1, 0 );
       DmxSimple.write(2, 0 );
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );  
       delay (100 ); 
       DmxSimple.write(1, 0 );
       DmxSimple.write(2, 0 );
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );  
       delay (100 ); 
       DmxSimple.write(1, 0 );
       DmxSimple.write(2, 0 );
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 );
       DmxSimple.write(2, 0 );
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );
       delay (100 ); 
       DmxSimple.write(1, 0 );
       DmxSimple.write(2, 0 );   
       delay (200 );     
       //battuka de
       DmxSimple.write(4, 255 );
       DmxSimple.write(5, 255 );
       delay (400 );  
       DmxSimple.write(4, 0 );
       DmxSimple.write(5, 0 );
       DmxSimple.write(4, 255 );
       DmxSimple.write(5, 255 );
       delay (200 );  
       DmxSimple.write(4, 0 );
       DmxSimple.write(5, 0 );
       DmxSimple.write(4, 255 );
       DmxSimple.write(5, 255 );
       delay (200 );  
       DmxSimple.write(4, 0 );
       DmxSimple.write(5, 0 );
       DmxSimple.write(4, 255 );
       DmxSimple.write(5, 255 );  
       delay (100 ); 
       DmxSimple.write(4, 0 );
       DmxSimple.write(5, 0 );
       DmxSimple.write(4, 255 );
       DmxSimple.write(5, 255 );  
       delay (100 ); 
       DmxSimple.write(4, 0 );
       DmxSimple.write(5, 0 );
       DmxSimple.write(4, 255 );
       DmxSimple.write(5, 255 );
       delay (100 ); 
       DmxSimple.write(4, 0 );
       DmxSimple.write(5, 0 );
       DmxSimple.write(4, 255 );
       DmxSimple.write(5, 255 );
       delay (100 ); 
       DmxSimple.write(4, 0 );
       DmxSimple.write(5, 0 );  
       working = 0; // variable bandera de trabajo abajo
      }
    }
    buttonStateSave24 = buttonState24;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia25 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState25 == buttonStateDebounced25) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState25 != buttonStateSave25) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState25 == LOW) {          // comprueba si el boton esta pulsado     working = 1; // variable bandera de trabajo arriba
       //secuencia 25 vacia 
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.25           "); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("                "); // Enviar el mensaje 
       working = 0; // variable bandera de trabajo abajo          
      }
    }
    buttonStateSave25 = buttonState25;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia26  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState26 == buttonStateDebounced26) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState26 != buttonStateSave26) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState26 == LOW) {  // comprobamos si el boton esta presionado
       //secuencia 26 vacia 
       working = 1; // variable bandera de trabajo arriba 
       lcd.setCursor(0, 0);
       lcd.print("SW.26           "); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("                "); // Enviar el mensaje  
       working = 0; // variable bandera de trabajo abajo          
      }
    }
    buttonStateSave26 = buttonState26;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia27
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState27 == buttonStateDebounced27) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState27 != buttonStateSave27) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState27 == LOW) {  // comprobamos si el boton esta presionado
       // secuencia 27 abrir 3
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.27         ON"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje
       DmxSimple.write(3, 255 );  
       working = 0; // variable bandera de trabajo abajo 
      }
    }
    buttonStateSave27 = buttonState27;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState28 == buttonStateDebounced28) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState28 != buttonStateSave28) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState28 == LOW) {  // comprobamos si el boton esta presionado
       // cerrar 3
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.28        OFF"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje 
       DmxSimple.write(3, 0 );  
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave28 = buttonState28;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia29
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState29 == buttonStateDebounced29) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState29 != buttonStateSave29) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState29 == LOW) {  // comprobamos si el boton esta presionado
       // abrir todos los inyectores
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.29         ON"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("TODOS           "); // Enviar el mensaje      
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );  
       DmxSimple.write(3, 255 );  
       DmxSimple.write(4, 255 );  
       DmxSimple.write(5, 255 );  
       working = 0; // variable bandera de trabajo abajo   
      }
    }
    buttonStateSave29 = buttonState29;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia30 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState30 == buttonStateDebounced30) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState30 != buttonStateSave30) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState30 == LOW) {  // comprobamos si el boton esta presionado
       // cerrar todos los inyectores
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.30        OFF"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("TODOS           "); // Enviar el mensaje
       DmxSimple.write(1, 0 );  
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 0 );  
       DmxSimple.write(4, 0 );  
       DmxSimple.write(5, 0 );    
       working = 0; // variable bandera de trabajo abajo  
      }
    }
    buttonStateSave30 = buttonState30;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia31
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState31 == buttonStateDebounced31) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState31 != buttonStateSave31) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState31 == LOW) {  // comprobamos si el boton esta presionado
       // encender piloto
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.31         ON"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("PILOTOS         "); // Enviar el mensaje
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
       working = 0; // variable bandera de trabajo abajo           
      }
    }
    buttonStateSave31 = buttonState31;  // guardar el nuevo estado en la variable
  }
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//secuencia32 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState32 == buttonStateDebounced32) { // comprobamos si esta trabajando dentro de alguna secuencia y nos aseguramos que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState32 != buttonStateSave32) {     // comprobamos si esta trabajando dentro de alguna secuencia y si el estado de botón ha cambiado!
      if (buttonState32 == LOW) {  // comprobamos si el boton esta presionado
       // apagar piloto
       working = 1; // variable bandera de trabajo arriba
       lcd.setCursor(0, 0);
       lcd.print("SW.32        OFF"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("PILOTOS         "); // Enviar el mensaje 
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto  
       working = 0; // variable bandera de trabajo abajo 
      }
    }
    buttonStateSave32 = buttonState32;  // guardar el nuevo estado en la variable
  }
  
/////////////////////////////////////////////////fin de las secuencias/////////////////////////////////////////////////////////////////  

}                ////////////////////////////////////////  fin loop ///////////////////////////////////////////////////
                         /////////////////////////////////fin de programa ///////////////////////////////////
