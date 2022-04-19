//Copiamos todo lo del código anterior para el SD
#include <Adafruit_BME280.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int LED_SENSOR = 33;
const int LED_BT = 32;
const int PHOTORES = 35;

Adafruit_BME280 bme;
BluetoothSerial SerialBT; //Objeto bluetooth

char payload[50];

void setup() {
  Serial.begin(115200); //Se inicializa el Serial
  SerialBT.begin("Axolote_ESP32"); //Se inicializa, ya que hereda todas las funciones de stream
  Serial.println("The device started, now you can pair it with bluetooth");

  bme.begin(0x76);
  
  pinMode(LED_SENSOR,OUTPUT);
  pinMode(LED_BT,OUTPUT);
}

void loop() {
  digitalWrite(LED_SENSOR,HIGH); //Prende cuando empieza a leer
  sprintf(payload,"%04d,%06.2f", analogRead(PHOTORES),bme.readPressure()/100); //Parecido a .format de python
  digitalWrite(LED_SENSOR,LOW);

  digitalWrite(LED_BT,HIGH); //Prende cuando empiece a escribir
  Serial.println(payload);
  SerialBT.println(payload);
  digitalWrite(LED_BT,LOW);

  delay(500);
}
