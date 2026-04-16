#include "imu.h"

LSM6DS3 imu;
bool imu_initialized = false;

void imu_setup() {
    Wire.begin(imu_sda, imu_scl);
    if (imu.begin() == 0) {
        Serial.println("IMU pass");
        imu_initialized=true;
    }
}

bool imu_getStatus(){
    return imu_initialized;
}

void imu_test(){
    Serial.print("ax:");
    Serial.print(imu.readFloatAccelX());
    Serial.print(" ");

    Serial.print("ay:");
    Serial.print(imu.readFloatAccelY());
    Serial.print(" ");

    Serial.print("az:");
    Serial.print(imu.readFloatAccelZ());
    Serial.print(" ");

    Serial.print("gx:");
    Serial.print(imu.readFloatGyroX());
    Serial.print(" ");

    Serial.print("gy:");
    Serial.print(imu.readFloatGyroY());
    Serial.print(" ");

    Serial.print("gz:");
    Serial.println(imu.readFloatGyroZ());
}

Accel imu_read() {
    Accel data;

    data.ax = imu.readFloatAccelX();
    data.ay = imu.readFloatAccelY();
    data.az = imu.readFloatAccelZ();

    data.gx = imu.readFloatGyroX();
    data.gy = imu.readFloatGyroY();
    data.gz = imu.readFloatGyroZ();

    return data;
}