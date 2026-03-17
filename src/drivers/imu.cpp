#include "imu.h"

LSM6DS3 imu;

void imu_setup() {
    Wire.begin(imu_sda, imu_scl);
    if (imu.begin() != 0) {
        Serial.println("Failed to initialize IMU");
    }
}

void imu_test(){
    Serial.print("\nAccelerometer:\n");
    Serial.print(" X = ");
    Serial.println(imu.readFloatAccelX(), 4);
    Serial.print(" Y = ");
    Serial.println(imu.readFloatAccelY(), 4);
    Serial.print(" Z = ");
    Serial.println(imu.readFloatAccelZ(), 4);

    Serial.print("\nGyroscope:\n");
    Serial.print(" X = ");
    Serial.println(imu.readFloatGyroX(), 4);
    Serial.print(" Y = ");
    Serial.println(imu.readFloatGyroY(), 4);
    Serial.print(" Z = ");
    Serial.println(imu.readFloatGyroZ(), 4);
}

void imu_comTest(){
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