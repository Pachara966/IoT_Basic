// Blynk
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "xxx"
#define BLYNK_TEMPLATE_NAME "xxx"
#define BLYNK_AUTH_TOKEN "xxx"

#include "Wire.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Wifi
char ssid[] = "TP-Link_A287"; // ใส่ชื่อ fifi
char pass[] = "66845355";  // ใส่รหัส wifi

void setup()
{
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop()
{
  Blynk.run();
  Blynk.virtualWrite(V0, 1); // V0 = Pin, 0 = ดับ || 1 = ติด
  delay(1000);
  Blynk.virtualWrite(V0, 0);
  delay(1000);
}
