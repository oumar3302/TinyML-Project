#include <Arduino_LSM9DS1.h>

const unsigned long SAMPLE_PERIOD_MS = 10; // 100 Hz
unsigned long lastSampleTime = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  if (!IMU.begin()) {
    while (1);
  }
}

void loop() {
  unsigned long now = millis();

  if (now - lastSampleTime >= SAMPLE_PERIOD_MS) {
    lastSampleTime = now;

    float ax, ay, az;

    if (IMU.accelerationAvailable()) {
      IMU.readAcceleration(ax, ay, az);

      //Serial.print(now);
      //Serial.print(",");
      Serial.print(ax, 6);
      Serial.print(",");
      Serial.print(ay, 6);
      Serial.print(",");
      Serial.println(az, 6);
    }
  }
}
