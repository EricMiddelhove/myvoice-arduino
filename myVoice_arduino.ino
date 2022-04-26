#include <Wire.h>

#include "Gyro.h"

int lastPloem = millis();
bool isPloemming;

bool randomPloemMode = false;

void interruptRoutine() {
  if((millis() - lastPloem) < 1000 && !isPloemming) {
      return;
  }
  isPloemming = true;
  
  Serial.println(lastPloem);
  Serial.println(millis());

  
  lastPloem = millis();
  
  Serial.print("\n--PLÖM--\n");

  isPloemming = false;
}

void setup() {
  Serial.begin(1000000);

  String incomingString = "";

  pinMode(LED_BUILTIN, OUTPUT);
  randomSeed(analogRead(A7));
  
  if(digitalRead(2) == HIGH){
    randomPloemMode = true;

    for(int i = 0; i < 5; i++){
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    }
    
  }else{
    attachInterrupt(digitalPinToInterrupt(2), interruptRoutine, RISING);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
  while (!Serial.find((char)* "--PING--\n"));
  
  Serial.print("--PONG--\n");
  digitalWrite(LED_BUILTIN, HIGH);
}
int randomDelay = 0;
unsigned long lastMillis = millis();
void loop() {

  Gyro gyro;
  int* accData;  // Array of length 3
  int* gyrData;  // Array of length 3
  accData = gyro.getAccelerometerData();
  gyrData = gyro.getGyroData();
  
  Serial.print("[");
  for (int i = 0; i < 3; i++) {
    Serial.print(*(accData++));
    Serial.print(",");
  }

  for (int i = 0; i < 3; i++) {
    Serial.print(*(gyrData++));
    Serial.print(",");
  }
  
  Serial.print("]");
  Serial.print("\n");

  if(randomPloemMode && millis() - lastMillis > randomDelay) {
    Serial.println(randomDelay);
    lastMillis = millis();
    randomDelay = random(2500,5000);
    interruptRoutine();
  }
}
