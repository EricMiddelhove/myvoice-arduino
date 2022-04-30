# myVoice-Arduino

The code in this respository is running on the Arduino Nano microcontroller of the myVoice gesture detection device. It is  responsible for collecting data from the sensor(s) and transmitting it to the Raspberry Pi for further processing.

---  

## Gyro.h 
The Gyro files contain the methods responsible for pulling data from the Gyrosensors. The Gyrosensor is connected via an I2C Bus.
The Gyrosensor can provide information about the rotation on the every spatial axis. Furthermore it can provide information on the current acceleration acting on the sensor - also for every spatial axis. 

You can retrieve this information via the **getAccelerometerData()** and **getGyroData()** methods. Both methods return arrays containg three values. 
> Note: The values in the array are sorted by the following scheme: [xAxis, yAxis, zAxis]

---

## .ino File
This file contains the main code running on the Arduino. The Arduino constantly transmits the data it detects at the sensors. It does this as fast as the hardware makes it possible. 

The Arduino has two modes that it can run in. The _ploemOnButtonPress_ mode and the _randomPloem_ mode. When running in _ploemOnButtonPress_ mode, the hardware button soldered on the perfboard triggeres a cpu interrupt, which transmits the value "--PLÖM--". This can be interpreted on the Raspberry Pi. When running in _randomPloem_ mode this value gets send randomly every 2,5 to 5 seconds. You can enable _randomPloem_ mode by pressing the ploem button on startup of the arduino. You will see the built in LED on the arduino blink  5 times as a confirmation of _randomPloem_ mode.
