#include "Sensor.h"

const int sensor1 = A0;
const int sensor2 = A1;
const int sensor3 = A2;
const int delayms = 10;

Sensor S1;
Sensor S2;
Sensor S3;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Keyboard.begin();
  delay(1000);
  Serial.begin(115200);
  delay(1000);
  pinMode(13, OUTPUT); //ピンモードを指定する
  
  S1 = Sensor(sensor1, 'k');
  //S2 = Sensor(sensor2, 'a');
  //S3 = Sensor(sensor3, 'f');
  S1.init();
  //S2.init();
  //S3.init();

}

// the loop function runs over and over again forever
void loop() {
  
  S1.Check();
  //S2.Check();
  //S3.Check();
  delay(delayms);

  S1.Write();
  //S2.Write();
  //S3.Write();
  Serial.println(",min:0,max:1024");
  
  

}


