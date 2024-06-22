// Blynk
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6OyvuYfWM"
#define BLYNK_TEMPLATE_NAME "Laser"
#define BLYNK_AUTH_TOKEN "BEYAI_XNLuUknBNirgS4_6rOznBFihEA"

#include "Wire.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

int button = 0;

// Wifi
char ssid[] = "TP-Link_A287"; // ใส่ชื่อ fifi
char pass[] = "66845355";     // ใส่รหัส wifi

// Relay
#define RELAY_PIN 13

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop()
{
  Blynk.run();
  Blynk.virtualWrite(V1, button);
  Blynk.virtualWrite(V0, button);
  digitalWrite(RELAY_PIN, button);
}

BLYNK_WRITE(V3)
{
  button = param.asInt(); // Get value as integer
}
