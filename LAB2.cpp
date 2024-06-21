#include "Adafruit_VL53L1X.h"

Adafruit_VL53L1X vl53 = Adafruit_VL53L1X();

void setup() {
  Serial.begin(115200);
  Wire.begin();
  vl53.begin(0x29, &Wire);
  vl53.startRanging();
  vl53.setTimingBudget(50);
}

void loop() {
  int16_t distance;
  vl53.dataReady();
  distance = vl53.distance();
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" mm");
  vl53.clearInterrupt();
}
