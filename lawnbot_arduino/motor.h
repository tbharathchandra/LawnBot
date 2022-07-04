#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

/***
 * Member Variables
 * r_pwm - forward PWM pin
 * l_pwm - backward PWM pin
 * c_a - encoder channel 1
 * c_b - encoder channel 2
 * 
 * Functions
 * void rotate (int value) - if value greater than 0, forward rotation based value mapping between 0 to 100 and vice versa.
***/


class Motor {
  public:
    
    Motor(int r_pwm, int l_pwm, int c_a, int c_b);
    Motor(int r_pwm, int l_pwm);
    
    void rotate(int value);
    int r_pwm;
    int l_pwm;
    int c_a;
    int c_b;
};

#endif
