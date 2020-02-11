/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle  nh;

void messageCb(const std_msgs::Float64& toggle_msg){
  double msg = toggle_msg.data;
  if(msg == 1){
    digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // blink the led
  }
  else{
    digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // don't blink the led
  }
}

ros::Subscriber<std_msgs::Float64> sub("toggle_motor", &messageCb );

void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
