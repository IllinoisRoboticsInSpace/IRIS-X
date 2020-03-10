/* 
 * A Simple Arduino Rosnode Subscriber
 * Subscribes to Twist msgs on the rosTopic "driveMotor"
 * 
 * To Run:
 * Upload to Arduino
 * rosrun rosserial_python serial_node.py /dev/ttyACM0
 * 
 */


#include <ros.h>
#include <Sabertooth.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle  nh;
Sabertooth ST(130, Serial1);

void drive_cb(const geometry_msgs::Twist& drive_cmd) {
  int leftPower = 127 * (-drive_cmd.linear.x + drive_cmd.angular.z);
  int rightPower = 127 * (-drive_cmd.linear.x - drive_cmd.angular.z);
  ST.motor(1, rightPower);
  ST.motor(2, leftPower);
}


ros::Subscriber<geometry_msgs::Twist> drive_sub("driveMotor", drive_cb);

void setup()
{ 
  Serial1.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(drive_sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
