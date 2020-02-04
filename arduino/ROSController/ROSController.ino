#include <ros.h>
#include <Sabertooth.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;

Sabertooth ST(130, Serial1);

void messageCb( const std_msgs::Empty& toggle_msg) {
  digitalWrite(13, HIGH-digitalRead(13));   // blink the led
}

void drive_cb(const geometry_msgs::Twist& drive_cmd) {
  int leftPower = 127 * (-drive_cmd.linear.x + drive_cmd.angular.z);
  int rightPower = 127 * (-drive_cmd.linear.x - drive_cmd.angular.z);
  ST.motor(1, rightPower);
  ST.motor(2, leftPower);
}

ros::Subscriber<std_msgs::Empty> sub("toggle_led", messageCb );

ros::Subscriber<geometry_msgs::Twist> drive_sub("cmd_vel", drive_cb);

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
  Serial1.begin(9600);
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  nh.subscribe(drive_sub);
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1);
}
