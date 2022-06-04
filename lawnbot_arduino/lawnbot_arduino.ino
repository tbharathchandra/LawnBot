#include "motor.h"
#include <PID_v1.h>

#include <ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <ros/time.h>

ros::NodeHandle  nh;


#define LOOPTIME 10

Motor right(10,11,2,7);
Motor left(5,6,3,4);

volatile long encoder0Pos = 0;    // Left wheel encoder count
volatile long encoder1Pos = 0;    //  Right wheel encoder count

double left_kp = 22 , left_ki = 0 , left_kd = 0.0;             // modify for optimal performance
double right_kp = 38 , right_ki = 0 , right_kd = 0.0;

double right_input = 0, right_output = 0, right_setpoint = 0;
PID rightPID(&right_input, &right_output, &right_setpoint, right_kp, right_ki, right_kd, DIRECT);  

double left_input = 0, left_output = 0, left_setpoint = 0;
PID leftPID(&left_input, &left_output, &left_setpoint, left_kp, left_ki, left_kd, DIRECT);  

float demandx=0; // m/s
float demandz=0;

double demand_speed_left;
double demand_speed_right;

unsigned long currentMillis;
unsigned long prevMillis;

float encoder0Diff;
float encoder1Diff;

float encoder0Error;
float encoder1Error;

float encoder0Prev;
float encoder1Prev;

void cmd_vel_cb( const geometry_msgs::Twist& twist){
  demandx = twist.linear.x;
  demandz = twist.angular.z;
}

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", cmd_vel_cb );
geometry_msgs::Vector3Stamped speed_msg;                                //create a "speed_msg" ROS message
ros::Publisher speed_pub("speed", &speed_msg);                          //create a publisher to ROS topic "speed" using the "speed_msg" type

double speed_act_left = 0;                    //Actual speed for left wheel in m/s
double speed_act_right = 0;  


void setup() {
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(speed_pub);       
  
//  Serial.begin(9600);
  rightPID.SetMode(AUTOMATIC);
  rightPID.SetSampleTime(1);
  rightPID.SetOutputLimits(-100, 100);

  leftPID.SetMode(AUTOMATIC);
  leftPID.SetSampleTime(1);
  leftPID.SetOutputLimits(-100, 100);

  attachInterrupt(digitalPinToInterrupt(right.c_a), change_right_a, CHANGE);
  attachInterrupt(digitalPinToInterrupt(left.c_a), change_left_a, CHANGE);
}

void loop() {
  currentMillis = millis();
  if (currentMillis - prevMillis >= LOOPTIME){
    prevMillis = currentMillis;

//    long currT = micros();
//    float sinv = (sin(currT/1e6)+1)/2; // value between 0 to 1 for PID tuning
//    demandx = sinv*0.08; // max speed = 0.144


    demand_speed_left = demandx - (demandz*0.17625);
    demand_speed_right = demandx + (demandz*0.17625);

    /*PID controller for speed control
      Base speed being 1 ms and the demand_speed variables controlling it at fractions of the base.
      The PID controller keeps trying to match the difference 
      in encoder counts to match with the required amount, hence controlling the speed. */
    encoder0Diff = encoder0Pos - encoder0Prev; // Get difference between ticks to compute speed
    encoder1Diff = encoder1Pos - encoder1Prev;
    

    /* 
     *  Distance between wheels (L) = 0.3525 m
     *  L/2 = 0.17625
     *  Calculate right and left wheel speeds by encoder counts (used to publish odometry data)
     *  Actual Encoded count (AEC) = delta encoder/gear ratio (506.25); no of revolutions =  AEC/CPR (22);
     *  rps = no of rotations/delta time (10 ms = 10/1000); linear speed = rps X pi X dia(14cm = 0.14m);
     *  Performing above calculations speed = delta encoder/295.4313631
    */ 
    speed_act_left = encoder0Diff/253.22688;                    
    speed_act_right = encoder1Diff/253.22688;
  
    encoder0Error = (demand_speed_left*253.22688)-encoder0Diff; 
    encoder1Error = (demand_speed_right*253.22688)-encoder1Diff;
  
    encoder0Prev = encoder0Pos; // Saving values
    encoder1Prev = encoder1Pos;
  
    left_setpoint = demand_speed_left*253.22688;  //Setting required speed as a mul/frac of 1 m/s
    right_setpoint = demand_speed_right*253.22688;
  
    left_input = encoder0Diff;  //Input to PID controller is the current difference
    right_input = encoder1Diff;
    
    leftPID.Compute();
    left.rotate(left_output);
    rightPID.Compute();
    right.rotate(right_output);
//    
//    Serial.println(encoder0Pos);
//    Serial.print(",");
//    Serial.println(encoder1Pos);
  }

  publishSpeed(LOOPTIME);
  nh.spinOnce();
}

//Publish function for odometry, uses a vector type message to send the data (message type is not meant for that but that's easier than creating a specific message type)
void publishSpeed(double time) {
  speed_msg.header.stamp = nh.now();      //timestamp for odometry data
  speed_msg.vector.x = speed_act_left;    //left wheel speed (in m/s)
  speed_msg.vector.y = speed_act_right;   //right wheel speed (in m/s)
  speed_msg.vector.z = time/1000;         //looptime, should be the same as specified in LOOPTIME (in s)
  speed_pub.publish(&speed_msg);
//  nh.loginfo("Publishing odometry");
}


void change_right_a(){  

  // look for a low-to-high on channel A
  if (digitalRead(right.c_a) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(right.c_b) == LOW) {  
      encoder1Pos = encoder1Pos + 1;         // CW
    } 
    else {
      encoder1Pos = encoder1Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(right.c_b) == HIGH) {   
      encoder1Pos = encoder1Pos + 1;          // CW
    } 
    else {
      encoder1Pos = encoder1Pos - 1;          // CCW
    }
  }
 
}

void change_left_a(){  

  // look for a low-to-high on channel A
  if (digitalRead(left.c_a) == HIGH) { 
    // check channel B to see which way encoder is turning
    if (digitalRead(left.c_b) == LOW) {  
      encoder0Pos = encoder0Pos + 1;         // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;         // CCW
    }
  }
  else   // must be a high-to-low edge on channel A                                       
  { 
    // check channel B to see which way encoder is turning  
    if (digitalRead(left.c_b) == HIGH) {   
      encoder0Pos = encoder0Pos + 1;          // CW
    } 
    else {
      encoder0Pos = encoder0Pos - 1;          // CCW
    }
  }
 
}
