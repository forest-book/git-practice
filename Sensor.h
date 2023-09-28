#include "Arduino.h"
#include "Keyboard.h"
#define THRESHOLD 10  //閾値
#define N 5  //データ点数


class Sensor{
public:
  char text = '\0';
  int monitor[N]={0};
  int sub = 0;
  float result = 0;
  int sum = 0;
  int key = 0;
  int loop = 0;
  
  Sensor(){}
  Sensor(int pin_num, char letter){
    pinMode(pin_num, INPUT);
    key = pin_num;
    text = letter;
  }
  
  void init(){
    monitor[N]={0};
    result = 0;
  }
  
  void Write(){
    Serial.print(text);
    Serial.print(':');
    Serial.print(result);
    if(result > THRESHOLD){
      //Keyboard.press(text);
    }
    else{
      //Keyboard.releaseAll();
    }

  }

  void Check(){
    monitor[sub] = analogRead(key);
    sub++;
    sub%=N;
    sum = 0;
    for(loop = 0;loop < N; loop++){
      sum += monitor[loop];
    }
    result = sum/N;
    
  }

private:
};


