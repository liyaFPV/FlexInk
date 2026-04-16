#include <Wire.h>
#include "SparkFunLSM6DS3.h"
#include "config.h"

struct Accel {
  float ax;
  float ay;
  float az;
  float gx;
  float gy;
  float gz;
};


void imu_setup();
bool imu_getStatus();
void imu_test();
Accel imu_read();

/*
Accel d = imu_read();
Serial.print("ax: "); Serial.print(d.ax);
Serial.print(" ay: "); Serial.print(d.ay);
Serial.print(" az: "); Serial.print(d.az);
Serial.print(" gx: "); Serial.print(d.gx);
Serial.print(" gy: "); Serial.print(d.gy);
Serial.print(" gz: "); Serial.println(d.gz);
*/