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
EN(run) <==  EN¯ (updt fw) ! Please For update firmware disconect battery 7-12v only usb 3.5v or arduino can dead !
Slave   ==>  DE  (master)
TX-io   <==  TX-uart
RX-io   <==  RX-uart
Pins 2,3,4 are used to transmit DMX signals
xlr output to xlr input rgb
------------------------------------------------------------
libs
//https://github.com/PaulStoffregen/DmxSimple
---------------------------------------------------------
Arduino buttons pullup hardware layout:
5V___Button____R10k ___Gnd
           |___Arduino pins
                   

pin 13 led 
---------------------------------------------------------
Display   :  Arduino
        
1	VSS GND			marron
2	VDD +5V			rojo
3	V0 --> R450Ohm >> gnd		rosa
4	RS PIN7			amar
5	RW GND			
6	EN PIN8			azul-marino
7	D0			
8	D1			
9	D2			
10	D3			
11	D4 pin 9 			marron
12	D5 pin 10			rojo
13	D6 pin 11			rosa
14	D7 pin 12			amar
15	A -> R220 ->5v		verde
16	K  gnd			azul-marino


---------------------------------------------------------

*/


#include <DmxSimple.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //    ( RS, EN, d4, d5, d6, d7)

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

const int ledPin      = 13; //led pin
        

int buttonState1  = 0; 
int buttonState2  = 0; 
int buttonState3  = 0;
int buttonState4  = 0; 
int buttonState5  = 0; 
int buttonState6  = 0; 
int buttonState7  = 0; 
int buttonState8  = 0; 
int buttonState9  = 0; 
int buttonState10 = 0; 
int buttonState11 = 0; 
int buttonState12 = 0;
int buttonState13 = 0; 
int buttonState14 = 0; 
int buttonState15 = 0; 
int buttonState16 = 0;  
int buttonState17 = 0; 
int buttonState18 = 0; 
int buttonState19 = 0;
int buttonState20 = 0; 
int buttonState21 = 0; 
int buttonState22 = 0; 
int buttonState23 = 0; 
int buttonState24 = 0; 
int buttonState25 = 0; 
int buttonState26 = 0; 
int buttonState27 = 0; 
int buttonState28 = 0;
int buttonState29 = 0; 
int buttonState30 = 0; 
int buttonState31 = 0;
int buttonState32 = 0;
        
void setup() 
{   
 
  int buttonState1  = 0; 
  int buttonState2  = 0; 
  int buttonState3  = 0;
  int buttonState4  = 0; 
  int buttonState5  = 0; 
  int buttonState6  = 0; 
  int buttonState7  = 0; 
  int buttonState8  = 0; 
  int buttonState9  = 0; 
  int buttonState10 = 0; 
  int buttonState11 = 0; 
  int buttonState12 = 0;
  int buttonState13 = 0; 
  int buttonState14 = 0; 
  int buttonState15 = 0;
  int buttonState16 = 0;  
  int buttonState17 = 0; 
  int buttonState18 = 0; 
  int buttonState19 = 0;
  int buttonState20 = 0; 
  int buttonState21 = 0; 
  int buttonState22 = 0; 
  int buttonState23 = 0; 
  int buttonState24 = 0; 
  int buttonState25 = 0; 
  int buttonState26 = 0; 
  int buttonState27 = 0; 
  int buttonState28 = 0;
  int buttonState29 = 0; 
  int buttonState30 = 0; 
  int buttonState31 = 0;
  int buttonState32 = 0;  
  pinMode(ledPin, OUTPUT); 
  lcd.begin(16, 2); // inicializar el LCD
  lcd.print("PirotecniaTomas"); // Enviar el mensaje 
   
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  DmxSimple.usePin(4);
  DmxSimple.maxChannel(6); //number of channels
  
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
  
}

void loop() 

{
   lcd.setCursor(0, 8);  // set the cursor to column 0, line 1
   buttonState1  = digitalRead(buttonPin1);
   buttonState2  = digitalRead(buttonPin2);
   buttonState3  = digitalRead(buttonPin3);
   buttonState4  = digitalRead(buttonPin4);
   buttonState5  = digitalRead(buttonPin5);
   buttonState6  = digitalRead(buttonPin6);
   buttonState7  = digitalRead(buttonPin7);
   buttonState8  = digitalRead(buttonPin8);
   buttonState9  = digitalRead(buttonPin9);
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
  
  

  
    if (buttonState1 == LOW)  // Button 1 
      { 
       //secuencia  1 200ms
       lcd.print("Programa 1"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(1, 255 );
       delay (200 );
       DmxSimple.write(1, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off        
      }

  
    if (buttonState2 == LOW)  // Button 2
      {
       //secuencia  2 200ms
       lcd.print("Programa 2"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(2, 255 );
       delay (200 );
       DmxSimple.write(2, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off   
      } 
     
 
    if (buttonState3 == LOW)  // Button 3  
      {
       //secuencia  3 200ms
       lcd.print("Programa 3"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(3, 255 );
       delay (200 );
       DmxSimple.write(3, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off     
      }   

 
    if (buttonState4 == LOW)  // Button 4 
      { 
       //secuencia  4 200ms
       lcd.print("Programa 4"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(4, 255 );
       delay (200 );
       DmxSimple.write(4, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off  
      }


 
    if (buttonState5 == LOW)  // Button 5 
      { 
       //secuencia  5 200ms
       lcd.print("Programa 5"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(5, 255 );
       delay (200 );
       DmxSimple.write(5, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off 
      }


 
    if (buttonState6 == LOW)  // Button 6 
      { 
       //secuencia  1 600ms
       lcd.print("Programa 6"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(1, 255 );
       delay (600 );
       DmxSimple.write(1, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off 
      }


 
    if (buttonState7 == LOW)  // Button 7 
      { 
       //secuencia  2 600ms
       lcd.print("Programa 7"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(2, 255 );
       delay (600 );
       DmxSimple.write(2, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off  
      }

 
    if (buttonState8 == LOW)  // Button 8 
      { 
       //secuencia  3 600ms
       lcd.print("Programa 8"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(3, 255 );
       delay (600 );
       DmxSimple.write(3, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off  
      }

  
    if (buttonState9 == LOW)  // Button 9
      { 
       //secuencia  4 600ms
       lcd.print("Programa 9"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(4, 255 );
       delay (600 );
       DmxSimple.write(4, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off  
      }


    if (buttonState10 == LOW)  // Button 10 
      { 
       //secuencia  5 600ms
       lcd.print("Programa 10"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto         
       DmxSimple.write(5, 255 );
       delay (600 );
       DmxSimple.write(5, 0 );  
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off 
      }


    if (buttonState11 == LOW)  // Button 11  
      { 
       // simultanea  2,4  600ms
       lcd.print("Programa 11"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (600 );  
       DmxSimple.write(2, 0 );   
       DmxSimple.write(4, 0 );
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off 
      }

 
    if (buttonState12 == LOW)  // Button 12 
      { 
       // simultanea  1,3,5  600ms 
       lcd.print("Programa 12"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto          
       DmxSimple.write(1, 255 );
       DmxSimple.write(3, 255 );
       DmxSimple.write(5, 255 );
       delay (600 );  
       DmxSimple.write(1, 0 );   
       DmxSimple.write(3, 0 );
       DmxSimple.write(5, 0 );      
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto  
       digitalWrite(ledPin, LOW);  // led pin 13off  
      }


 
    if (buttonState13 == LOW)  // Button 13 
      { 
       // simultanea 1,2,3,4,5 600ms 
       lcd.print("Programa 13"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off   
      }



    if (buttonState14 == LOW)  // Button 14  
      {  
       //consecutivas 1,2,3,4,5 200ms 
       lcd.print("Programa 14"); // Enviar el mensaje    
       digitalWrite(ledPin, HIGH); // led pin 13on  
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto     
       digitalWrite(ledPin, LOW);  // led pin 13off  
      }


    if (buttonState15 == LOW)  // Button 15  
      { 
      //consecutivas 5,4,3,2,1 200ms
       lcd.print("Programa 15"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off  
      }
    
 
    if (buttonState16 == LOW)  // Button 16 
      { 
       //consecutivas 1,2,3,4,5,4,3,2,1 200ms 
       lcd.print("Programa 16"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off    
      }
    
    
    if (buttonState17 == LOW)  // Button 17 
      { 
       //consecutivas 5,4,3,2,1,2,3,4,5  200ms  
       lcd.print("Programa 17"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on      
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto   
       digitalWrite(ledPin, LOW);  // led pin 13off         
      }

    if (buttonState18 == LOW)  // Button 18 
      { 
       //consecutivas 3,2-4, 1-5, 2-4, 3  200ms
       lcd.print("Programa 18"); // Enviar el mensaje   
       digitalWrite(ledPin, HIGH); // led pin 13on
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off             
      }   

    if (buttonState19 == LOW)  // Button 19 
      { 
       //consecutivas 1-5, 2-4, 3, 2-4, 1-5  200ms
       lcd.print("Programa 19"); // Enviar el mensaje  
       digitalWrite(ledPin, HIGH); // led pin 13on       
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto 
       digitalWrite(ledPin, LOW);  // led pin 13off                  
      }   
    
    if (buttonState20 == LOW)  // Button 20 
      { 
       //consecutivas 1-5, 2-4, 3, 2-4, 1-5  200ms 
       lcd.print("Programa 20"); // Enviar el mensaje  
       digitalWrite(ledPin, HIGH); // led pin 13on      
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto  
       digitalWrite(ledPin, LOW);  // led pin 13off                   
      }   

    if (buttonState21 == LOW)  // Button 21 
      { 
  
      } 

    if (buttonState22 == LOW)  // Button 22 
      { 
  
      } 

    if (buttonState23 == LOW)  // Button 23 
      { 
  
      } 

    if (buttonState24 == LOW)  // Button 24 
      { 
  
      } 

    if (buttonState25 == LOW)  // Button 25
      { 
  
      } 

    if (buttonState26 == LOW)  // Button 26
      { 
  
      } 

    if (buttonState27 == LOW)  // Button 27 
      { 
  
      } 

    if (buttonState28 == LOW)  // Button 28 
      { 
  
      } 

    if (buttonState29 == LOW)  // Button 29 
      { 
  
      } 

    if (buttonState30 == LOW)  // Button 30 
      { 
  
      } 

    if (buttonState31 == LOW)  // Button 31
      { 
       // abrir todos los inyectores
       lcd.print("Programa 31"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on        
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );  
       DmxSimple.write(3, 255 );  
       DmxSimple.write(4, 255 );  
       DmxSimple.write(5, 255 );  
       digitalWrite(ledPin, LOW);  // led pin 13off         
      } 

    if (buttonState32 == LOW)  // Button 32
      { 
       // cerrar todos los inyectores
       lcd.print("Programa 32"); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on
       DmxSimple.write(1, 0 );  
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 0 );  
       DmxSimple.write(4, 0 );  
       DmxSimple.write(5, 0 );   
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto  
       digitalWrite(ledPin, LOW);  // led pin 13off        
      } 
  
      
}
