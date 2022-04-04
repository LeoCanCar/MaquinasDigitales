//Instalar biblioteca si no la tienen
//#include "Adafruit_BMP085_U.h"
#include <Wire.h>
//#include <Adafruit_I2CDevice.h>
#include <Adafruit_BME280.h>

//Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified();
Adafruit_BME280 BMP; //Profe


void setup() {
 Serial.begin(115200);
 //bmp.begin(0x76);
 if (!bmp.begin()) {
 Serial.println("Could not find a valid BMP085 sensor, check wiring!");
 while (1) {}
  }
}

void loop() {
/*
  Serial.print("Pressure= ");
  Serial.print(bmp.readPressure());
  Serial.println("Pa");
*/
}
