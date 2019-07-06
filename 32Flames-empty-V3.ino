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
*/


#include <DmxSimple.h> 


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
       
      }

  
    if (buttonState2 == LOW)  // Button 2
      {
     
      } 
     
 
    if (buttonState3 == LOW)  // Button 3  
      {
    
      }   

 
    if (buttonState4 == LOW)  // Button 4 
      { 
 
      }


 
    if (buttonState5 == LOW)  // Button 5 
      { 

      }


 
    if (buttonState6 == LOW)  // Button 6 
      { 

      }


 
    if (buttonState7 == LOW)  // Button 7 
      { 
 
      }

 
    if (buttonState8 == LOW)  // Button 8 
      { 
 
      }

  
    if (buttonState9 == LOW)  // Button 9
      { 
 
      }


    if (buttonState10 == LOW)  // Button 10 
      { 

      }


    if (buttonState11 == LOW)  // Button 11  
      { 

      }

 
    if (buttonState12 == LOW)  // Button 12 
      { 
  
      }


 
    if (buttonState13 == LOW)  // Button 13 
      { 
  
      }



    if (buttonState14 == LOW)  // Button 14  
      {      
 
      }


    if (buttonState15 == LOW)  // Button 15  
      { 

      }
    
 
    if (buttonState16 == LOW)  // Button 16 
      { 
  
      }
    
    
    if (buttonState17 == LOW)  // Button 17 
      { 
  
      }

    if (buttonState18 == LOW)  // Button 18 
      { 
  
      }   

    if (buttonState19 == LOW)  // Button 19 
      { 
  
      }   
    
    if (buttonState20 == LOW)  // Button 20 
      { 
  
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
  
      } 

    if (buttonState32 == LOW)  // Button 32
      { 
  
      } 
  
      
}
