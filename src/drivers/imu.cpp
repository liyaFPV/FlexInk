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
    Accel d = imu_read();

    Serial.print("ax: "); Serial.print(d.ax);
    Serial.print(" ay: "); Serial.print(d.ay);
    Serial.print(" az: "); Serial.print(d.az);
    Serial.print(" gx: "); Serial.print(d.gx);
    Serial.print(" gy: "); Serial.print(d.gy);
    Serial.print(" gz: "); Serial.println(d.gz);
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