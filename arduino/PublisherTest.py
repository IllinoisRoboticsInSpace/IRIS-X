#!/usr/bin/env python


## Simple demo that publishes std_msgs/Strings messages
## to the 'toggle_motor' topic
"""
To run:
make a package + make a scripts folder + put this in catkin package folder
run catkin_make
run roscore
run rosrun <Package Name> talker.py
"""
import rospy
from std_msgs.msg import String

def talker():
    pub = rospy.Publisher('toggle_motor', String, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    #rate = rospy.Rate(1) # 10hz
    while not rospy.is_shutdown():
        rospy.loginfo("Move")
        pub.publish("Move")
        rospy.sleep(5.)
        rospy.loginfo("Stop")
        pub.publish("Stop")
        rospy.sleep(5.)




if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
