// Chage These Credentials with your Blynk Template credentials 

#define BLYNK_TEMPLATE_ID "YOUR TEMPLATE ID"
#define BLYNK_TEMPLATE_NAME "YOUR TEMPLATE NAME"
#define BLYNK_AUTH_TOKEN "YOUR AUTH TOKEN"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "********"; // Change your Wifi/ Hotspot Name
char pass[] = "********"; // Change your Wifi/ Hotspot Password

#define Device1 13
#define Device2 12
#define Device3 14
#define Device4 27

BLYNK_WRITE(V0)
{
  digitalWrite(Device1, param.asInt());  
  Serial.println(String("V0 Data: ") + param.asInt());
  delay(10);
}
BLYNK_WRITE(V1)
{
  digitalWrite(Device2, param.asInt());
  Serial.println(String("V1 Data: ") + param.asInt());
  delay(10);
}
BLYNK_WRITE(V2)
{
  digitalWrite(Device3, param.asInt());
  Serial.println(String("V2 Data: ") + param.asInt());
  delay(10);
}
BLYNK_WRITE(V3)
{
  digitalWrite(Device4, param.asInt());
  Serial.println(String("V3 Data: ") + param.asInt());
  delay(10);
}

void setup() 
{
  Serial.begin(9600); //Start the serial output at 9600 baud
  pinMode(Device1, OUTPUT);
  pinMode(Device2, OUTPUT);
  pinMode(Device3, OUTPUT);
  pinMode(Device4, OUTPUT);
  
  digitalWrite(Device1, LOW);
  digitalWrite(Device2, LOW);
  digitalWrite(Device3, LOW);
  digitalWrite(Device4, LOW);

  Blynk.begin(auth, ssid, pass);//Splash screen delay
  delay(2000);
}

void loop() //Loop function
{
  Blynk.run();
}
