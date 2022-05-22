#include <AWS_IOT.h>
#include <WiFi.h>
#include <Adafruit_BMP280.h>

//Wifi & AWS Parameters
#define WIFI_SSID    "INFINITUM12F6_2.4" // SSID of your WIFI
#define WIFI_PASSWORD "hhJS5gYT2d" //your wifi password
#define CLIENT_ID "Axolote_ESP32_Leo"// thing unique ID, this id should be unique among all things associated with your AWS account.
#define MQTT_TOPIC "$aws/things/Axolote_ESP32_Leo/shadow/update" //topic for the MQTT data
#define AWS_HOST "a9zwczf1oqpq2-ats.iot.us-east-1.amazonaws.com" // your host for uploading data to AWS,

const int PHOTORES = 35;

AWS_IOT aws;

Adafruit_BMP280 bme;
char payload [300];
bool status = WL_IDLE_STATUS;

void setup() {
  Serial.begin(115200);
  bme.begin(0x76);

  //Conexion WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Connected to wifi");

  //Conexion AWS
  if(aws.connect(AWS_HOST,CLIENT_ID)== 0){// Connect to AWS using Host Address and Cliend ID
      Serial.println("Connected to AWS");
      delay(1000);
  }
  else{
      Serial.println("AWS connection failed, Check the HOST Address");
      while(1);
  }

}

void loop() {

  sprintf(payload,"{"
   "\"deviceID\":\"AxoloteESP32_Leo\","
   "\"Press_hPA\":%06.2f,"
   "\"Luz_adim\":%04d"
   "}",bme.readPressure()/100,analogRead(PHOTORES));

  //sprintf(payload,"%04d,%06.2f", analogRead(PHOTORES),bme.readPressure()/100);;
  Serial.println("Publishing:- ");
  Serial.println(payload);

  while(!aws.publish(MQTT_TOPIC, payload) == 0){// publishes payload and returns 0 upon success. 
      Serial.print(".");
      delay(50);
  }
  Serial.println("Success!");   
   
  delay(600000);
  ESP.restart();
}
