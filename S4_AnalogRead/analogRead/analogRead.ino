const int analogReadPin = 34;
const int ledPin = 32;
const int THRESHOLD = 2000;
float luz;

//El ADC tiene 0.8 mV de resolución
//El DAC tiene 12 mv de resolución

void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  //Serial.println(analogRead(analogReadPin));
  //delay(10);
/*  luz = analogRead(analogReadPin);
  Serial.println(luz);
  if(luz >= THRESHOLD){
    digitalWrite(ledPin, HIGH);
    }else{
    digitalWrite(ledPin, HIGH);
    }
*/
 luz = analogRead(analogReadPin);
 ledSwitch(luz);

  //No es necearia la variable "luz", solo necesitas el analog read
  //ledSwitch(analogRead(analogReadPin)):

 delay(10);
}

//2.- tarea: volver la actividad 1 una función llamada "ledSwitch"
//Hay que hacer el refactor
//QUEREMOS

void ledSwitch(){

  Serial.println(value):
  if (value<=THRESHOLD){
    digitalWrite(ledPin,HIGH);
  }
  else{
    digitalWrite(ledPin,LOW);
  }
}
