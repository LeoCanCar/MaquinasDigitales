const int TEMP_SENSOR = 13; //Este pin es el buenardo
const int LED_PIN = 32;
//La resolución del sensor es de 0.8mV = 0.008 °C

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN,OUTPUT);

}

void loop() {
  //Serial.println(analogRead(TEMP_SENSOR));
  //Se esperan lecturas de 250
  //El numero digital está bien, pero queremos temperatura
  //Serial.println(analogRead(TEMP_SENSOR)*0.8); //milivolt
  Serial.println(adc2celcius(analogRead(TEMP_SENSOR))); // °C
  
  delay(10);
}

float  adc2celcius(float adc_value){
  return adc_value*0.08;
  }
