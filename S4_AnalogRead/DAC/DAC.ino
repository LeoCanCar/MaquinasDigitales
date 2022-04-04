#include <math.h>

const int DAC_PIN = 25;
const int DAC_PIN2 = 26;

int t=0; //Tiempo
float x; //Señal del DAC
String payload; //String que manda por serial

void setup() {
  Serial.begin(115200);
}

void loop() {
  x=127*sin(2*PI*t/256)+128;
  t++;

  if(t>256){
    t=0;
   }

  //Serial.println(x);
  Serial.print(x); Serial.print('\t'); Serial.println(t);

  //Sumando strings
  //payload= Strings(x)+"  "+String(+)";
  //Serial.println(payload)

  //Escribir en el DAC
  dacWrite(DAC_PIN,x);
  dacWrite(DAC_PIN2,t);

  delay(10);
}
