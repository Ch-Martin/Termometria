#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>



#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"



 
//Declaremos los pines CE y el CSN
#define CE_PIN 9
#define CSN_PIN 10
 
//Variable con la dirección del canal que se va a leer
byte direccion[5] ={'c','a','n','a','l'};


//creamos el objeto radio (NRF24L01)
RF24 radio(CE_PIN, CSN_PIN);

//vector para los datos recibidos
int datos[6];

int temp1, temp2,temp3, temp4, temp5;
int temp6, temp7,temp8, temp9, temp10;






// CONFIGURACION DE UART GSM
#define CONFIG_GSM_RXPIN 4
#define CONFIG_GSM_TXPIN 3
#define CONFIG_GSM_BAUDRATE 115200


// CONFIGURACION DEL NUMERO DESTINO DEL MENSAJE SMS
#define CONFIG_GSM_SMS_DESTINATION "+543413761239"


// PUERTO SERIE EMULADO: EL ARDUINO UNO TIENE SOLO 1 UART
// EN EL CONSTRUCTOR DE SOFTWARESERIAL SE ESPECIFICAN LOS PINES PARA RX Y TX
SoftwareSerial swseri = SoftwareSerial(CONFIG_GSM_RXPIN, CONFIG_GSM_TXPIN);

// OBJETO ADAFRUIT_FONA USADO PARA COMUNICARSE CON EL SIM800L
Adafruit_FONA fona = Adafruit_FONA(10);




void setup()
{
 //inicializamos el NRF24L01 
  radio.begin();
  //inicializamos el puerto serie
  Serial.begin(115200); 
  
  //Abrimos el canal de Lectura
  radio.openReadingPipe(1, direccion);
  
    //empezamos a escuchar por el canal
  radio.startListening();








  // PREPARAR LOS PUERTOS SERIALES A LA VELOCIDAD CONFIGURADA
  swseri.begin(CONFIG_GSM_BAUDRATE);
  

  // INICIAR LA COMUNICACION CON EL MODULO GSM
  // PASAMOS REFERENCIA AL PUERTO SERIE USADO PARA LA COMUNICACION CON EL MODEM
  if (fona.begin(swseri))
    Serial.println(F("MODULO GSM OK"));
  else
  {
    // BLOQUEAR LA EJECUCIÓN EN ESTE PUNTO SI NO SE ENCUENTRA MODULO GSM O FALLA LA COMUNICACIÓN CON ESTE
    Serial.println(F("NO SE ENCUENTRA MODULO GSM"));
    while (1);
  }

  // AQUI SE REALIZA EL ENVIO DEL MENSAJE SMS
  // INDICAMOS EL NUMERO DESTINO Y EL CUERPO DEL MENSAJE
  if (!fona.sendSMS(CONFIG_GSM_SMS_DESTINATION, "Alarma SMS encendiendo!!!")) {
    Serial.println(F("ERROR"));
  } else {
    Serial.println(F("ENVIADO"));
  }
}
 
 
void loop() {
 uint8_t numero_canal;
 //if ( radio.available(&numero_canal) )
 if ( radio.available() )
 {    
     //Leemos los datos y los guardamos en la variable datos[]
     radio.read(datos,sizeof(datos));
     if (datos[5] == 101){
     //reportamos por el puerto serial los datos recibidos

   
     temp1=datos[0];
     temp2=datos[1];
     temp3=datos[2];
     temp4=datos[3];
     temp5=datos[4];
    
     }
     
     //radio.read(datos1,sizeof(datos1));
    if  (datos[5] == 102){
     //reportamos por el puerto serial los datos recibidos
  
     temp6=datos[0];
     temp7=datos[1];
     temp8=datos[2];
     temp9=datos[3];
     temp10=datos[4];
      
     }
 }
 //else

 delay(1000);



{
  /*
Serial.println(temp1);
Serial.println(temp2);
Serial.println(temp3);
Serial.println(temp4);
Serial.println(temp5);
Serial.println(temp6);
Serial.println(temp7);
Serial.println(temp8);
Serial.println(temp9);
Serial.println(temp10);
*/
   
Serial.write(temp1);
Serial.write(temp2);
Serial.write(temp3);
Serial.write(temp4);
Serial.write(temp5);
Serial.write(temp6);
Serial.write(temp7);
Serial.write(temp8);
Serial.write(temp9);
Serial.write(temp10);
    
    }
if (temp1 > 30)
{
(!fona.sendSMS(CONFIG_GSM_SMS_DESTINATION, "MENSAJE DE ALERTA!!!"));
//(!fona.sendSMS(CONFIG_GSM_SMS_DESTINATION, "Termocupla 1 cable 1" temp1));

}

    
 }
