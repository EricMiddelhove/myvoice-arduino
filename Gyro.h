#include <Arduino.h>
#include <Wire.h>

class Gyro {
 private:
  int16_t accelerometer[3];  //[accX, accY, accZ]
  int accelerometer_registers[3] = {0x3B, 0x3C, 0x3D};
  int16_t gyro[3];  //[gyrX, gyrY, gyrZ]
  int gyro_registers[3] = {0x43, 0x44, 0x45};

  const int MPU6050_ADRESS = 0x68;

  const int PWR_MGMT = 0x6B;

 public:
  Gyro();

  int* getAccelerometerData();

  int* getGyroData();

  void sleep();

  void wake();
};
