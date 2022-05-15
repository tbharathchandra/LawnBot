#include "Arduino.h"
#include "Motor.h"


Motor::Motor(int r_pwm, int l_pwm, int c_a, int c_b) {
  pinMode(r_pwm,OUTPUT);
  pinMode(l_pwm,OUTPUT);
  pinMode(c_a,INPUT_PULLUP);
  pinMode(c_b,INPUT_PULLUP);
  Motor::r_pwm = r_pwm;
  Motor::l_pwm = l_pwm;
  Motor::c_a = c_a;
  Motor::c_b = c_b;
}

void Motor::rotate(int value) {
  if(value>=0){
    int out = map(value, 0, 100, 0, 255);
    analogWrite(r_pwm,out);
    analogWrite(l_pwm,0);
  }else{
    int out = map(value, 0, -100, 0, 255);
    analogWrite(r_pwm,0);
    analogWrite(l_pwm,out);
  }
}
