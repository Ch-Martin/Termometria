#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
//Declaremos los pines CE y el CSN
#define CE_PIN 9
#define CSN_PIN 10
 
//Variable con la dirección del canal que se va a leer
byte direccion[5] ={'c','a','n','a','l'}; 

//creamos el objeto radio (NRF24L01)
RF24 radio(CE_PIN, CSN_PIN);

//vector para los datos recibidos
int datos[5];


int tempe1, tempe2,tempe3, tempe4, tempe5;
int tempe6, tempe7,tempe8, tempe9,tempe10;
int tempe11, tempe12,tempe13, tempe14,tempe15;

void setup()
{
 //inicializamos el NRF24L01 
  radio.begin();
  //inicializamos el puerto serie
  Serial.begin (115200);//(115200);
  
  //Abrimos el canal de Lectura
  radio.openReadingPipe(1, direccion);
  
    //empezamos a escuchar por el canal
  radio.startListening();
 
}
 
void loop() {
 uint8_t numero_canal;
 if ( radio.available(&numero_canal) )
 
 if ( radio.available() )
 {    
     //Leemos los datos y los guardamos en la variable datos[]
     radio.read(datos,sizeof(datos));
    
    //reportamos por el puerto serial los datos recibidos
   // Serial.println ("Cable 1");
   //  Serial.println (datos[0]);
    // Serial.println (datos[1]);
    // Serial.println (datos[2]);
 }


     
        //Leemos los datos y los guardamos en la variable datos[]
   // radio.read(datos,sizeof(datos));
     if (datos[0] == 26){
     //reportamos por el puerto serial los datos recibidos
    /*Serial.println ("Cable A");
     Serial.println (datos[0]);
     Serial.println (datos[1]);
     Serial.println (datos[2]);*/

     tempe1=datos[0];
     tempe2=datos[1];
     tempe3=datos[2];
     tempe4=datos[3];
     tempe5=datos[4];
     
     }



     if (datos[0] == 18){
     //reportamos por el puerto serial los datos recibidos
   /* Serial.println ("Cable B");
     Serial.println (datos[0]);
     Serial.println (datos[1]);
     Serial.println (datos[2]);*/

     tempe6=datos[0];
     tempe7=datos[1];
     tempe8=datos[2];
     tempe9=datos[3];
     tempe10=datos[4];
     
     
     }



    //  if (datos[0] == 81){
     //reportamos por el puerto serial los datos recibidos
   /* Serial.println ("Cable C");
     Serial.println (datos[0]);
     Serial.println (datos[1]);
     Serial.println (datos[2]);*/

    // tempe11=datos[0];
    // tempe12=datos[1];
    // tempe13=datos[2];
    // tempe14=datos[3];
    // tempe15=datos[4];
     
     
     //}
 
      
// else
// {
   
     //Serial.println("No hay datos de radio disponibles");
 //}
 

 delay(1000);



  {
  /*
Serial.println ("Cable A");
Serial.println(tempe1);
Serial.println(tempe2);
Serial.println(tempe3);
Serial.println(tempe4);
Serial.println(tempe5);

Serial.println ("Cable B");
Serial.println(tempe6);
Serial.println(tempe7);
Serial.println(tempe8);
Serial.println(tempe9);
Serial.println(tempe10);


Serial.println ("Cable C");
Serial.println(tempe11);
Serial.println(tempe12);
Serial.println(tempe13);
Serial.println(tempe14);
Serial.println(tempe15);
*/
    
Serial.write(tempe1);
Serial.write(tempe2);
Serial.write(tempe3);
Serial.write(tempe4);
Serial.write(tempe5);
Serial.write(tempe6);
Serial.write(tempe7);
Serial.write(tempe8);
Serial.write(tempe9);
Serial.write(tempe10);
    
    }
   
 }
