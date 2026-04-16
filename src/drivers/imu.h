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