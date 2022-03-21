#define digitalReadPin 35
#define LED 32
bool BOTON;
//bool pinStatus;

void setup() {
  //Serial.begin(115200);
  pinMode(digitalReadPin,INPUT);
  pinMode(LED,OUTPUT);
}

void loop() {
  //pinStatus = digitalRead(digitalReadPin);
  //Serial.println(digitalRead(digitalReadPin));

  //Hacer una subrutina que encienda el LED si el botón está presionado
  //Si no lo está, entonces que lo apague
  //.....
   BOTON = digitalRead(digitalReadPin);
  if (digitalReadPin == HIGH){
    digitalWrite(LED,HIGH);
    }else{
    digitalWrite(LED,LOW);
    }


  //.....
}
