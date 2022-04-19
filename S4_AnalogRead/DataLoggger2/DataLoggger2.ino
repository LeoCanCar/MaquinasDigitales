#include <SD.h> //Es la biblioteca
#include <Adafruit_BME280.h>
File archivo;

const int LED_SENSOR = 33;
const int LED_SD = 32;
const int PHOTORES = 35;
Adafruit_BME280 bme;
char payload[50];

void setup() {
  Serial.begin(115200); //Se inicializa el Serial
  SD.begin(); //Se inicializa, ya que hereda todas las funciones de stream

  bme.begin(0x76);
  
  pinMode(LED_SENSOR,OUTPUT);
  pinMode(LED_SD,OUTPUT);

}

void loop() {

  digitalWrite(LED_SENSOR,HIGH); //Prende cuando empieza a leer
  sprintf(payload,"%04d,%06.2f", analogRead(PHOTORES),bme.readPressure()/100); //Parecido a .format de python
  digitalWrite(LED_SENSOR,LOW);
  //payload = analogRead(PHOTORES);
  
  digitalWrite(LED_SD,HIGH); //Prende cuando empiece a escribir
  Serial.println(payload); //Manda por serial lo que se va a escribir
  archivo = SD.open("/Luz_Presion.csv",FILE_APPEND); //Abre el archivo
  archivo.println(payload); //Escribe en el archivo
  archivo.close();//Cierra el archivo
  digitalWrite(LED_SD,LOW); //Apaga el led cuando termina7

  delay(100);
}
