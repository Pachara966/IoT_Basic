// VL53L1X วัดระยะทาง
#include "Adafruit_VL53L1X.h"
Adafruit_VL53L1X vl53 = Adafruit_VL53L1X();

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

  Wire.begin();
  vl53.begin(0x29, &Wire);
  vl53.startRanging();
  vl53.setTimingBudget(50);
}

void loop()
{
  Blynk.run();
  Blynk.virtualWrite(V0, 1); // V0 = Pin, 0 = ดับ || 1 = ติด

  int16_t distance;
  vl53.dataReady();
  distance = vl53.distance();
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" mm");

  Blynk.virtualWrite(V6,distance);

  vl53.clearInterrupt();   
  
  delay(1000);
  Blynk.virtualWrite(V0, 0);
  delay(1000);
}
