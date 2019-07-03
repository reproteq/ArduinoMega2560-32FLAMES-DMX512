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
                   

pin A15 led 
--------------------------------------------------------- 

*/


#include <DmxSimple.h> 


const int buttonPin1 =  5;      
const int buttonPin2 =  6;     
const int buttonPin3 =  7;     
const int buttonPin4 =  8;     
const int buttonPin5 =  9;    
const int buttonPin6 =  10;     
const int buttonPin7 =  11;    
const int buttonPin8 =  12;     
const int buttonPin9 =  13;
const int buttonPin10 = 14;        
const int buttonPin11 = 15;       
const int buttonPin12 = 16;                            
const int buttonPin13 = 17;       
const int buttonPin14 = 18;        
const int buttonPin15 = 19; 
const int buttonPin16 = 20; 
const int buttonPin17 = 21; 
const int buttonPin18 = A0; 
const int buttonPin19 = A1; 
const int buttonPin20 = A2; 
const int buttonPin21 = A3; 
const int buttonPin22 = A4; 
const int buttonPin23 = A5; 
const int buttonPin24 = A6; 
const int buttonPin25 = A7; 
const int buttonPin26 = A8; 
const int buttonPin27 = A9; 
const int buttonPin28 = A10; 
const int buttonPin29 = A11; 
const int buttonPin30 = A12; 
const int buttonPin31 = A13; 
const int buttonPin32 = A14;

const int ledPin      = A15; //led pin
        

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
      //secuencia  1,2,3,4,5 cada una 200ms
      DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
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
      }

  
    if (buttonState2 == LOW)  // Button 2
      {
      //secuencia  1,2,3,4,5 cada una 600ms
      DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
      DmxSimple.write(1, 255 );
      delay (600 );
      DmxSimple.write(1, 0 );     

      DmxSimple.write(2, 255 );
      delay (600 );
      DmxSimple.write(2, 0 ); 
      
      DmxSimple.write(3, 255 );
      delay (600 );
      DmxSimple.write(3, 0 );       
      
      DmxSimple.write(4, 255 );
      delay (600 );
      DmxSimple.write(4, 0 );    

      DmxSimple.write(5, 255 );
      delay (600 );
      DmxSimple.write(5, 0 );  

      DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto        
      } 

       

 
    if (buttonState3 == LOW)  // Button 3  
      {
      // simultanea  2,4  600ms
      DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
      DmxSimple.write(2, 255 );
      DmxSimple.write(4, 255 );
      delay (600 );  
      DmxSimple.write(2, 0 );   
      DmxSimple.write(4, 0 );
      
      DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto      
      }   


 
    if (buttonState4 == LOW)  // Button 4 
      { 
      // simultanea  1,3,5  600ms       
      DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
      DmxSimple.write(1, 255 );
      DmxSimple.write(3, 255 );
      DmxSimple.write(5, 255 );
      delay (600 );  
      DmxSimple.write(1, 0 );   
      DmxSimple.write(3, 0 );
      DmxSimple.write(5, 0 );
      
      DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto           
      }


 
    if (buttonState5 == LOW)  // Button 5 
      { 
      // simultanea 1,2,3,4,5 600ms  
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
      }


 
    if (buttonState6 == LOW)  // Button 6 
      { 
      //consecutivas 1,2,3,4,5 200ms
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
      }


 
    if (buttonState7 == LOW)  // Button 7 
      { 
      //consecutivas 5,4,3,2,1 200ms
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
      }

 
    if (buttonState8 == LOW)  // Button 8 
      { 
      //consecutivas 1,2,3,4,5,4,3,2,1 200ms 
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
      }

  
    if (buttonState9 == LOW)  // Button 9
      { 
      //consecutivas 5,4,3,2,1,2,3,4,5  200ms  
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
      }


    if (buttonState10 == LOW)  // Button 10 
      { 
      //consecutivas 3,2-4, 1-5, 2-4, 3  200ms  
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
      }


    if (buttonState11 == LOW)  // Button 11  
      { 
      //consecutivas 1-5, 2-4, 3, 2-4, 1-5  200ms  
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
      }

 
    if (buttonState12 == LOW)  // Button 12 
      { 
      //consecutivas 1-5, 2-4, 3, 2-4, 1-5  200ms  
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
      }


 
    if (buttonState13 == LOW)  // Button 13 
      { 
  
      }



    if (buttonState14 == LOW)  // Button 14  
      {      
      DmxSimple.write(6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir todos los inyectores 
      DmxSimple.write(1, 255 );
      DmxSimple.write(2, 255 );  
      DmxSimple.write(3, 255 );  
      DmxSimple.write(4, 255 );  
      DmxSimple.write(5, 255 );       
      }


    if (buttonState15 == LOW)  // Button 15  
      { 
      // cerrar todos los inyectores
      DmxSimple.write(1, 0 );  
      DmxSimple.write(2, 0 );  
      DmxSimple.write(3, 0 );  
      DmxSimple.write(4, 0 );  
      DmxSimple.write(5, 0 );   
      DmxSimple.write(6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
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
