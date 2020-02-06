#!/usr/bin/env python


## Simple demo that publishes std_msgs/Strings messages
## to the 'toggle_motor' topic
"""
To run:
make a package + make a scripts folder + put this in catkin package folder
run catkin_make
cd catkin_ws && source ./devel/setup.bash
run roscore
run rosrun <Package Name> talker.py
"""
import rospy
from std_msgs.msg import Float64


def talker():
    leftMotor = rospy.Publisher('leftMotor', Float64, queue_size=10)
    rightMotor = rospy.Publisher('rightMotor', Float64, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    #rate = rospy.Rate(1) # 10hz
    left, right = 0, 0
    while not rospy.is_shutdown():
        left, right = 1,1
        rospy.loginfo("Right: {} Left: {}".format(left, right))
        leftMotor.publish(left)
        rightMotor.publish(right)

        rospy.sleep(5.)
        left, right = 0,0
        rospy.loginfo("Right: {} Left: {}".format(left, right))
        leftMotor.publish(left)
        rightMotor.publish(right)
        rospy.sleep(5.)


if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
