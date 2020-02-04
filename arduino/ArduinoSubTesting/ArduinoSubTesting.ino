/* 
 * rosserial Subscriber Example
 * Blinks an LED on callback
 */

#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle  nh;

void messageCb( const std_msgs::String& toggle_msg){
  String msg = toggle_msg.data;
  if(msg == "Test"){
    digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // blink the led
  }
  else{
    digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));   // don't blink the led
  }
}

ros::Subscriber<std_msgs::String> sub("toggle_led", &messageCb );

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
