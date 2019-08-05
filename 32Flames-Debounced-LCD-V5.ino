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


int buttonState1;                        // variable para lectura del estado del pin 
int buttonState2;                        // variable para lectura del estado del pin 
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


int buttonStateDebounced1;                       // variable para leer el estado delayed/debounced
int buttonStateDebounced2;                       // variable para leer el estado delayed/debounced
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
 

int buttonStateSave1;                // variable para mantener el estado del botón
int buttonStateSave2;                // variable para mantener el estado del botón
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

int working = 0;
  
void setup() {  
  Serial.begin(9600);                // Comunicación serie puesta a 9600bps
  Serial.println("DBG Setup");
  pinMode(ledPin, OUTPUT); 
  lcd.begin(16, 2); // inicializar el LCD
  lcd.setCursor(0, 0);
  lcd.print("PIROTOMAS   2019"); // Enviar el mensaje     
  lcd.setCursor(0, 1);
  //lcd.print((char) 126); //flecha 0111 1110  
  lcd.print("FLAMEONE TT FW.5"); // Enviar el mensaje 
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  DmxSimple.usePin(4);
  DmxSimple.maxChannel(6); //number of channels

  
  pinMode(buttonPin1, INPUT);    // pone el pin switch como entrada
  pinMode(buttonPin2, INPUT);    // pone el pin switch como entrada
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

  buttonStateSave1 = digitalRead(buttonPin1);  // lee el estado inicial
  buttonStateSave2 = digitalRead(buttonPin2);  // lee el estado inicial
  buttonStateSave3 = digitalRead(buttonPin3);
  buttonStateSave4 = digitalRead(buttonPin4); 
  buttonStateSave5 = digitalRead(buttonPin5); 
  buttonStateSave6 = digitalRead(buttonPin6); 
  buttonStateSave7 = digitalRead(buttonPin7); 
  buttonStateSave8 = digitalRead(buttonPin8); 
  buttonStateSave9 = digitalRead(buttonPin9); 
  buttonStateSave10 = digitalRead(buttonPin10);
  buttonStateSave11 = digitalRead(buttonPin11);
  buttonStateSave12 = digitalRead(buttonPin12);
  buttonStateSave13 = digitalRead(buttonPin13);
  buttonStateSave14 = digitalRead(buttonPin14);
  buttonStateSave15 = digitalRead(buttonPin15);
  buttonStateSave16 = digitalRead(buttonPin16); 
  buttonStateSave17 = digitalRead(buttonPin17);
  buttonStateSave18 = digitalRead(buttonPin18);
  buttonStateSave19 = digitalRead(buttonPin19);
  buttonStateSave20 = digitalRead(buttonPin20);
  buttonStateSave21 = digitalRead(buttonPin21);
  buttonStateSave22 = digitalRead(buttonPin22);
  buttonStateSave23 = digitalRead(buttonPin23);
  buttonStateSave24 = digitalRead(buttonPin24);
  buttonStateSave25 = digitalRead(buttonPin25);
  buttonStateSave26 = digitalRead(buttonPin26);
  buttonStateSave27 = digitalRead(buttonPin27);
  buttonStateSave28 = digitalRead(buttonPin28);
  buttonStateSave29 = digitalRead(buttonPin29);
  buttonStateSave30 = digitalRead(buttonPin30);
  buttonStateSave31 = digitalRead(buttonPin31);
  buttonStateSave32 = digitalRead(buttonPin32);
}

void loop(){

  buttonState1 = digitalRead(buttonPin1);  // lee el buttonState1or de entrada y almacénlo en buttonState1
  buttonState2 = digitalRead(buttonPin2);  // lee el buttonState1or de entrada y almacénlo en buttonState1
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
  
  
  
  delay(10);                     // 10 milisegundos son una cantidad de tiempo buena
  
  buttonStateDebounced1 = digitalRead(buttonPin1); // lea la entrada otra vez para comprobar saltos
  buttonStateDebounced2 = digitalRead(buttonPin2); // lea la entrada otra vez para comprobar saltos
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
//1
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState1 == buttonStateDebounced1) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState1 != buttonStateSave1) {     // el estado de botón ha cambiado!
      if (buttonState1 == LOW) {          // compruebe si el botón es presionado 
      working = 1;
       Serial.println("secuencia1");
       //secuencia  1 200ms
       lcd.setCursor(0, 0);
       lcd.print("SW.1       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(1, 255 );
       delay (200 );
       DmxSimple.write(1, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off 
        working = 0;
      }
    }
    buttonStateSave1 = buttonState1;               // guardar el nuevo estado en la variable
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
//2  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
  if (working == 0 && buttonState2 == buttonStateDebounced2) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState2 != buttonStateSave2) {     // el estado de botón ha cambiado!
      if (buttonState2 == LOW) {          // compruebe si el botón es presionado 
     working = 1;
       Serial.println("secuencia2");
       //secuencia  2 200ms

       lcd.setCursor(0, 0);
       lcd.print("SW.2       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("2               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(2, 255 );
       delay (200 );
       DmxSimple.write(2, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off    
       working = 0; 
      }
    }
    buttonStateSave2 = buttonState2;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//3
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState3 == buttonStateDebounced3) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState3 != buttonStateSave3) {     // el estado de botón ha cambiado!
      if (buttonState3 == LOW) {          // compruebe si el botón es presionado
     working = 1;	  
    Serial.println("secuencia3");

       //secuencia  3 200ms
       lcd.setCursor(0, 0);
       lcd.print("SW.3       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(3, 255 );
       delay (200 );
       DmxSimple.write(3, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off 
	   working = 0;    
        
      }
    }
    buttonStateSave3 = buttonState3;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//4 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState4 == buttonStateDebounced4) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState4 != buttonStateSave4) {     // el estado de botón ha cambiado!
      if (buttonState4 == LOW) {          // compruebe si el botón es presionado
     working = 1;
	  Serial.println("secuencia4");

       //secuencia  4 200ms
       lcd.setCursor(0, 0);
       lcd.print("SW.4       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("4               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on     
       DmxSimple.write(4, 255 );
       delay (200 );
       DmxSimple.write(4, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave4 = buttonState4;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//5  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState5 == buttonStateDebounced5) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState5 != buttonStateSave5) {     // el estado de botón ha cambiado!
      if (buttonState5 == LOW) {          // compruebe si el botón es presionado
     working = 1;
	  Serial.println("secuencia5");

       //secuencia  5 200ms
       lcd.setCursor(0, 0);
       lcd.print("SW.5       200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5               "); // Enviar el mensaje 
             
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(5, 255 );
       delay (200 );
       DmxSimple.write(5, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave5 = buttonState5;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//6 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState6 == buttonStateDebounced6) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState6 != buttonStateSave6) {     // el estado de botón ha cambiado!
      if (buttonState6 == LOW) {          // compruebe si el botón es presionado
	 working = 1;
    Serial.println("secuencia6");

        //secuencia  1 600ms
       lcd.setCursor(0, 0);
       lcd.print("SW.6       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(1, 255 );
       delay (600 );
       DmxSimple.write(1, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;  
        
      }
    }
    buttonStateSave6 = buttonState6;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//7 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState7 == buttonStateDebounced7) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState7 != buttonStateSave7) {     // el estado de botón ha cambiado!
      if (buttonState7 == LOW) {          // compruebe si el botón es presionado
     working = 1; 
     Serial.println("secuencia7");

       //secuencia  2 600ms
       lcd.setCursor(0, 0);
       lcd.print("SW.7       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("2               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on       
       DmxSimple.write(2, 255 );
       delay (600 );
       DmxSimple.write(2, 0 );   
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave7 = buttonState7;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//8
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState8 == buttonStateDebounced8) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState8 != buttonStateSave8) {     // el estado de botón ha cambiado!
      if (buttonState8 == LOW) {          // compruebe si el botón es presionado
     working = 1;
	  Serial.println("secuencia8");

        //secuencia  3 600ms
       lcd.setCursor(0, 0);
       lcd.print("SW.8       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on         
       DmxSimple.write(3, 255 );
       delay (600 );
       DmxSimple.write(3, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave8 = buttonState8;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//9  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState9 == buttonStateDebounced9) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState9 != buttonStateSave9) {     // el estado de botón ha cambiado!
      if (buttonState9 == LOW) {          // compruebe si el botón es presionado
     working = 1;
	  Serial.println("secuencia9");

       //secuencia  4 600ms
       lcd.setCursor(0, 0);
       lcd.print("SW.9       600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("4               "); // Enviar el mensaje 
        
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(4, 255 );
       delay (600 );
       DmxSimple.write(4, 0 );   
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave9 = buttonState9;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//10  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState10 == buttonStateDebounced10) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState10 != buttonStateSave10) {     // el estado de botón ha cambiado!
      if (buttonState10 == LOW) {          // compruebe si el botón es presionado
     working = 1; 
      Serial.println("secuencia10");

        //secuencia  5 600ms
       lcd.setCursor(0, 0);
       lcd.print("SW.10      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5               "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on               
       DmxSimple.write(5, 255 );
       delay (600 );
       DmxSimple.write(5, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;  
        
      }
    }
    buttonStateSave10 = buttonState10;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//11  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState11 == buttonStateDebounced11) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState11 != buttonStateSave11) {     // el estado de botón ha cambiado!
      if (buttonState11 == LOW) {          // compruebe si el botón es presionado
	       working = 1;
    Serial.println("secuencia11");

        // simultanea  2,4  600ms
       lcd.setCursor(0, 0);
       lcd.print("SW.11      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("24              "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on    
       DmxSimple.write(2, 255 );
       DmxSimple.write(4, 255 );
       delay (600 );  
       DmxSimple.write(2, 0 );   
       DmxSimple.write(4, 0 ); 
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;  
        
      }
    }
    buttonStateSave11 = buttonState11;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//12  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState12 == buttonStateDebounced12) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState12 != buttonStateSave12) {     // el estado de botón ha cambiado!
      if (buttonState12 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia12");

        // simultanea  1,3,5  600ms 
       lcd.setCursor(0, 0);
       lcd.print("SW.12      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("135             "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on        
       DmxSimple.write(1, 255 );
       DmxSimple.write(3, 255 );
       DmxSimple.write(5, 255 );
       delay (600 );  
       DmxSimple.write(1, 0 );   
       DmxSimple.write(3, 0 );
       DmxSimple.write(5, 0 );       
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave12 = buttonState12;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//13  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState13 == buttonStateDebounced13) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState13 != buttonStateSave13) {     // el estado de botón ha cambiado!
      if (buttonState13 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia13");

       // simultanea 1,2,3,4,5 600ms 
       lcd.setCursor(0, 0);
       lcd.print("SW.13      600ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("12345           "); // Enviar el mensaje 
       
       digitalWrite(ledPin, HIGH); // led pin 13on    
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave13 = buttonState13;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//14  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState14 == buttonStateDebounced14) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState14 != buttonStateSave14) {     // el estado de botón ha cambiado!
      if (buttonState14 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia14");

       //consecutivas 1,2,3,4,5 200ms 
       lcd.setCursor(0, 0);
       lcd.print("SW.14      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5          "); // Enviar el mensaje 
           
       digitalWrite(ledPin, HIGH); // led pin 13on  
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave14 = buttonState14;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//15  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState15 == buttonStateDebounced15) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState15 != buttonStateSave15) {     // el estado de botón ha cambiado!
      if (buttonState15 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia15");

      //consecutivas 5,4,3,2,1 200ms
       lcd.setCursor(0, 0);
       lcd.print("SW.15      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5 -> 1          "); // Enviar el mensaje 

       digitalWrite(ledPin, HIGH); // led pin 13on
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave15 = buttonState15;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//16  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState16 == buttonStateDebounced16) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState16 != buttonStateSave16) {     // el estado de botón ha cambiado!
      if (buttonState3 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia16");

       //consecutivas 1,2,3,4,5,4,3,2,1 200ms 
       lcd.setCursor(0, 0);
       lcd.print("SW.16      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5 -> 1     "); // Enviar el mensaje 
              
 
       digitalWrite(ledPin, HIGH); // led pin 13on
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave16 = buttonState16;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//17
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState17 == buttonStateDebounced17) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState17 != buttonStateSave1) {     // el estado de botón ha cambiado!
      if (buttonState17 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia17");

       //consecutivas 5,4,3,2,1,2,3,4,5  200ms  
       lcd.setCursor(0, 0);
       lcd.print("SW.17      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5 -> 1 -> 5     "); // Enviar el mensaje
        
       digitalWrite(ledPin, HIGH); // led pin 13on      
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;  
       
      }
    }
    buttonStateSave17 = buttonState17;               // guardar el nuevo estado en la variable
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
//18  
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   
  if (working == 0 && buttonState18 == buttonStateDebounced18) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState18 != buttonStateSave18) {     // el estado de botón ha cambiado!
      if (buttonState18 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia18");

       //consecutivas 3,2-4, 1-5, 2-4, 3  200ms
       lcd.setCursor(0, 0);
       lcd.print("SW.18      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3,24,15,24,3    "); // Enviar el mensaje
       
       digitalWrite(ledPin, HIGH); // led pin 13on
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;      
        
      }
    }
    buttonStateSave18 = buttonState18;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//19
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState19 == buttonStateDebounced19) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState19 != buttonStateSave19) {     // el estado de botón ha cambiado!
      if (buttonState19 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia19");

       //consecutivas 1-5, 2-4, 3, 2-4, 1-5 200ms
       lcd.setCursor(0, 0);
       lcd.print("SW.19      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("15,24,3,24,15   "); // Enviar el mensaje
       
       lcd.print("S19 1-5, 2-4, 3, 2-4, 1-5 200ms"); // Enviar el mensaje  
       digitalWrite(ledPin, HIGH); // led pin 13on       
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave19 = buttonState19;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//20
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState20 == buttonStateDebounced20) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState20 != buttonStateSave20) {     // el estado de botón ha cambiado!
      if (buttonState20 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia20");

       //consecutivas 1-5, 2-4, 3, 2-4, 1-5 200ms 
       lcd.setCursor(0, 0);
       lcd.print("SW.20      200ms"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("15,24,3,24,15   "); // Enviar el mensaje
       
       digitalWrite(ledPin, HIGH); // led pin 13on      
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;  
        
      }
    }
    buttonStateSave20 = buttonState20;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//21
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState21 == buttonStateDebounced21) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState21 != buttonStateSave21) {     // el estado de botón ha cambiado!
      if (buttonState21 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia21");

         //consecutivas 1,2,3,4,5 100ms  x3
       lcd.setCursor(0, 0);
       lcd.print("SW.21   100ms x3"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5          "); // Enviar el mensaje
               
       lcd.print("S21 1,2,3,4,5 100ms x3"); // Enviar el mensaje    
       digitalWrite(ledPin, HIGH); // led pin 13on  
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;  
        
      }
    }
    buttonStateSave21 = buttonState21;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//22
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState22 == buttonStateDebounced22) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState22 != buttonStateSave22) {     // el estado de botón ha cambiado!
      if (buttonState22 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia22");


        //consecutivas 5,4,3,2,1 100ms x3
       lcd.setCursor(0, 0);
       lcd.print("SW.22   100ms x3"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("5 -> 1          "); // Enviar el mensaje
               
       digitalWrite(ledPin, HIGH); // led pin 13on
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
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave22 = buttonState22;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//23
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState23 == buttonStateDebounced23) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState23 != buttonStateSave23) {     // el estado de botón ha cambiado!
      if (buttonState23 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia23");

     //consecutivas 1,2,3,4,5,4,3,2,1 100ms x3
       lcd.setCursor(0, 0);
       lcd.print("SW.23   100ms x3"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("1 -> 5 -> 1     "); // Enviar el mensaje
               
       digitalWrite(ledPin, HIGH); // led pin 13on
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
       digitalWrite(ledPin, LOW);  // led pin 13off 
	   working = 0;   
        
      }
    }
    buttonStateSave23 = buttonState23;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//24
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState24 == buttonStateDebounced24) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState24 != buttonStateSave24) {     // el estado de botón ha cambiado!
      if (buttonState24 == LOW) {          // compruebe si el botón es presionado
      working = 1;
      Serial.println("secuencia24");

        //secuencia  battuka
       lcd.setCursor(0, 0);
       lcd.print("SW.24   batukada"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("12 -> 45        "); // Enviar el mensaje
        

       digitalWrite(ledPin, HIGH); // led pin 13on   
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


       digitalWrite(ledPin, LOW);  // led pin 13off    
        working = 0;
      }
    }
    buttonStateSave24 = buttonState24;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//25 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState25 == buttonStateDebounced25) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState25 != buttonStateSave25) {     // el estado de botón ha cambiado!
      if (buttonState25 == LOW) {          // compruebe si el botón es presionado      working = 1;
    Serial.println("secuencia25");

        lcd.setCursor(0, 0);
       lcd.print("SW.25           "); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("                "); // Enviar el mensaje 
	   working = 0;          
      }
    }
    buttonStateSave25 = buttonState25;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//26  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState26 == buttonStateDebounced26) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState26 != buttonStateSave26) {     // el estado de botón ha cambiado!
      if (buttonState26 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia26 vacia");

       lcd.setCursor(0, 0);
       lcd.print("SW.26           "); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("                "); // Enviar el mensaje  
	   working = 0;          
      }
    }
    buttonStateSave26 = buttonState26;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//27
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState27 == buttonStateDebounced27) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState27 != buttonStateSave27) {     // el estado de botón ha cambiado!
      if (buttonState27 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia27 vacia");

       // abrir 3
       lcd.setCursor(0, 0);
       lcd.print("SW.27         ON"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje
              
       digitalWrite(ledPin, HIGH); // led pin 13on        
       DmxSimple.write(3, 255 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave27 = buttonState27;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//28
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState28 == buttonStateDebounced28) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState28 != buttonStateSave28) {     // el estado de botón ha cambiado!
      if (buttonState28 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia28");

       // cerrar 3
       lcd.setCursor(0, 0);
       lcd.print("SW.28        OFF"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("3               "); // Enviar el mensaje
              
       digitalWrite(ledPin, HIGH); // led pin 13on        
       DmxSimple.write(3, 0 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;    
        
      }
    }
    buttonStateSave28 = buttonState28;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//29
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState29 == buttonStateDebounced29) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState29 != buttonStateSave29) {     // el estado de botón ha cambiado!
      if (buttonState29 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia29");

         // abrir todos los inyectores
       lcd.setCursor(0, 0);
       lcd.print("SW.29         ON"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("TODOS           "); // Enviar el mensaje
               
       digitalWrite(ledPin, HIGH); // led pin 13on        
       DmxSimple.write(1, 255 );
       DmxSimple.write(2, 255 );  
       DmxSimple.write(3, 255 );  
       DmxSimple.write(4, 255 );  
       DmxSimple.write(5, 255 );  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave29 = buttonState29;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//30 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState30 == buttonStateDebounced30) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState30 != buttonStateSave30) {     // el estado de botón ha cambiado!
      if (buttonState30 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia30");

         // cerrar todos los inyectores
       lcd.setCursor(0, 0);
       lcd.print("SW.30        OFF"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("TODOS           "); // Enviar el mensaje
                
       digitalWrite(ledPin, HIGH); // led pin 13on
       DmxSimple.write(1, 0 );  
       DmxSimple.write(2, 0 );  
       DmxSimple.write(3, 0 );  
       DmxSimple.write(4, 0 );  
       DmxSimple.write(5, 0 );    
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;  
        
      }
    }
    buttonStateSave30 = buttonState30;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//31
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState31 == buttonStateDebounced31) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState31 != buttonStateSave31) {     // el estado de botón ha cambiado!
      if (buttonState31 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia31");

       // encender piloto
       lcd.setCursor(0, 0);
       lcd.print("SW.31         ON"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("PILOTOS         "); // Enviar el mensaje
              
       digitalWrite(ledPin, HIGH); // led pin 13on        
       DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave31 = buttonState31;               // guardar el nuevo estado en la variable
  }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//32 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
  if (working == 0 && buttonState32 == buttonStateDebounced32) {             // asegúrar que conseguimos 2 lecturas constantes
    if (working == 0 && buttonState32 != buttonStateSave32) {     // el estado de botón ha cambiado!
      if (buttonState32 == LOW) {          // compruebe si el botón es presionado
      working = 1;
    Serial.println("secuencia32");

       // apagar piloto
       lcd.setCursor(0, 0);
       lcd.print("SW.32        OFF"); // Enviar el mensaje 
       lcd.setCursor(0, 1);
       lcd.print("PILOTOS         "); // Enviar el mensaje 
       digitalWrite(ledPin, HIGH); // led pin 13on   
       DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto  
       digitalWrite(ledPin, LOW);  // led pin 13off
	   working = 0;   
        
      }
    }
    buttonStateSave32 = buttonState32;               // guardar el nuevo estado en la variable
  }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

}
