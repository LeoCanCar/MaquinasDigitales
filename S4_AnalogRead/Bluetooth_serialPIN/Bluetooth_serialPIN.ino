//Copiamos todo una vez más
#include <Adafruit_BMP280.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

const int LED_SENSOR = 27;
const int LED_BT = 32;
const int LED_BT_PARING = 33;
const int PHOTORES = 35;
const int PARING_BUTTON = 34;

Adafruit_BMP280 bme;
char payload[50];

BluetoothSerial SerialBT; //Objeto bluetooth
boolean confirmRequestPending = false;

void BTConfirmRequestCallback(uint32_t numVal)
{
  confirmRequestPending = true;
  Serial.println(numVal);
  Serial.println("¿De acuerdo con el emparejamiento?");
}

void BTAuthCompleteCallback(boolean success)
{
  confirmRequestPending = false;
  if (success)
  {
    Serial.println("Pairing success!!");
  }
  else
  {
    Serial.println("Pairing failed, rejected by user!!");
  }
}

void setup() {
  Serial.begin(115200); //Se inicializa el Serial
  bme.begin(0x76);
  
  pinMode(LED_SENSOR,OUTPUT);
  pinMode(LED_BT,OUTPUT);
  pinMode(LED_BT_PARING,OUTPUT);
  pinMode(PARING_BUTTON,INPUT);

  SerialBT.enableSSP();
  SerialBT.onConfirmRequest(BTConfirmRequestCallback);
  SerialBT.onAuthComplete(BTAuthCompleteCallback);
  SerialBT.begin("Axolote_ESP32"); //Se inicializa, ya que hereda todas las funciones de stream
  //Serial.println("The device started, now you can pair it with bluetooth");

}

void loop() {
  confirmRequestPending = digitalRead(PARING_BUTTON); //Si no está presionado = false
  if (confirmRequestPending){
    digitalWrite(LED_BT_PARING,HIGH);
    delay(10);
    //if (Serial.available()){
      //int dat = Serial.read();
      //if (dat == 'Y' || dat == 'y')
      //{
        SerialBT.confirmReply(true);
      //}
      //else
      //{
        //SerialBT.confirmReply(false);
      //}
    //}
    digitalWrite(LED_BT_PARING,LOW);
    delay(10);
  }
  else{
/*    if (Serial.available())
    {
      SerialBT.write(Serial.read());
    }
    if (SerialBT.available())
    {
      Serial.write(SerialBT.read());
    }
    delay(20); 
  }
*/ //Esto no recuerdo que era

  //digitalWrite(LED_SENSOR,HIGH); //Prende cuando empieza a leer
  sprintf(payload,"%04d,%06.2f", analogRead(PHOTORES),bme.readPressure()/100); //Parecido a .format de python
  //digitalWrite(LED_SENSOR,LOW);

  digitalWrite(LED_BT,HIGH); //Prende cuando empiece a escribir
  Serial.println(payload);
  SerialBT.println(payload);
  digitalWrite(LED_BT,LOW);

  }

  delay(50);
}
