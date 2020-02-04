/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */
//To run:
//rosrun rosserial_python serial_node.py /dev/ttyACM0


#include <ros.h>
#include <std_msgs/String.h>
#include <Sabertooth.h>

ros::NodeHandle  nh;
Sabertooth ST(130, Serial1);

bool motorState = false;

void messageCb( const std_msgs::String& toggle_msg){
  String msg = toggle_msg.data;
  if (msg == "Move") {
    ST.motor(1, 127);
    motorState = true;
  } else if (msg == "Stop"){
    ST.motor(1, 0);
    motorState = false;
  }
}

ros::Subscriber<std_msgs::String> sub("toggle_motor", &messageCb );

void setup()
{ 
  Serial1.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
