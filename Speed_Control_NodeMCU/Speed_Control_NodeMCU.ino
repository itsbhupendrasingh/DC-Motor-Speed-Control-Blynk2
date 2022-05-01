/*
 * you need to select the board as NodeMCU 1.0(ESP12E Module). for this syou can watch our other tutorials in our channel. 
 * you can also take the help from this link. and also select the COM port to uplaod the program. 
 */
// Fill-in information from your Blynk Template here

#define BLYNK_TEMPLATE_ID "TMPLw42khV1z"
#define BLYNK_DEVICE_NAME "Speed Control"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

int fan=D6, en=D7; 

BLYNK_WRITE(V0)
{
  int s0 = param.asInt(); 
  analogWrite(en, s0);
  Blynk.virtualWrite(V1, s0);
}

void setup()
{
  Serial.begin(9600);
  pinMode(en, OUTPUT);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, HIGH);
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
}
