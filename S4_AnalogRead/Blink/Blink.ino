const int digitalWritePin = 32;
//const int digitalReadPin2 = 34;
//#define digitalReadPin34

void setup() {
  pinMode(digitalWritePin, OUTPUT);
  //pinMode(digitalReadPin, INPUT);
  //Serial.begin(115200);
}

void loop() {
  digitalWrite(digitalWritePin,HIGH);
  //Serial.println(digitalRead(digitalReadPin));
  //digitalWrite(digitalWritePin,1); Equivalente, menos legible
  delay(500);
  digitalWrite(digitalWritePin,LOW);
  //Serial.println(digitalRead(digitalReadPin));
  //digitalWrite(digitalWritePin,1; Equivalente, menos legible
  delay(500);
}
