/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */
//To run:
//rosrun rosserial_python serial_node.py /dev/ttyACM0


#include <ros.h>
#include <std_msgs/Float64.h>
#include <Sabertooth.h>

ros::NodeHandle  nh;
Sabertooth ST(130, Serial1);

void leftMtrCb( const std_msgs::Float64& toggle_msg){
  double msg = toggle_msg.data;
  if (msg == 1) {
    ST.motor(2, 127);
  } else if (msg == 0){
    ST.motor(2, 0);
  }
}
void rightMtrCb( const std_msgs::Float64& toggle_msg){
  double msg = toggle_msg.data;
  if (msg == 1) {
    ST.motor(1, 127);
  } else if (msg == 0){
    ST.motor(1, 0);
  }
}

ros::Subscriber<std_msgs::Float64> leftMtrSub("leftMotor", &leftMtrCb );
ros::Subscriber<std_msgs::Float64> rightMtrSub("rightMotor", &rightMtrCb );

void setup()
{ 
  Serial1.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(leftMtrSub);
  nh.subscribe(rightMtrSub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
