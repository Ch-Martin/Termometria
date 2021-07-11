#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//Declaremos los pines CE y el CSN
#define CE_PIN 9
#define CSN_PIN 10
 
//Variable con la dirección del canal por donde se va a transmitir
byte direccion[5] ={'c','a','n','a','l'};

//creamos el objeto radio (NRF24L01)
RF24 radio(CE_PIN, CSN_PIN);

//vector con los datos a enviar
int datos[3];

void setup()
{
  //inicializamos el NRF24L01 
  radio.begin();
  //inicializamos el puerto serie
  Serial.begin(115200); 
 
//Abrimos un canal de escritura
 radio.openWritingPipe(direccion);
 
}
 
void loop()
{ 
 //cargamos los datos en la variable datos[]
 datos[0]=26;
 datos[1]=29;
 datos[2]=20;
 //enviamos los datos
 bool ok = radio.write(datos, sizeof(datos));
  //reportamos por el puerto serial los datos enviados 
  if(ok)
  {
     Serial.print("Datos enviados: "); 
     Serial.print(datos[0]); 
     Serial.print(" , "); 
     Serial.print(datos[1]); 
     Serial.print(" , "); 
     Serial.println(datos[2]); 
  }
  else
  {
     Serial.println("no se ha podido enviar");
  }
  delay(1000);
}
