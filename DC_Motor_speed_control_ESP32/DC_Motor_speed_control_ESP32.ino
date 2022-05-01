/*
 * This program is property of SME Dehradun. for any query related to this program, 
 * contact us at www.smedehradn.com
 * if your want any soluiton related for any IoT Customized Boards and Sensor, 
 * then contact to www.nuttyengineer.com 
 */
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLw42khV1z"
#define BLYNK_DEVICE_NAME "Speed Control"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#include "BlynkEdgent.h"

int fan=14, en=5; 
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  ledcWrite(ledChannel, s0);
}

void setup()
{
  Serial.begin(9600);
  ledcSetup(ledChannel, freq, resolution);
  pinMode(en, OUTPUT);
  ledcAttachPin(en, ledChannel);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, HIGH);
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
}
