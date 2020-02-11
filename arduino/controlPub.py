#!/usr/bin/env python

"""
Simple demo that publishes geometry_msgs/Twist messages to the 'driveMotor' topic
To run:
make a ros package + make a scripts folder + put this pyfile in the catkin package scripts folder
run catkin_make
cd catkin_ws && source ./devel/setup.bash
run roscore
run rosrun <Package Name> controlPub.py
"""

import rospy
from geometry_msgs.msg import Twist


def driveStraight(drive_cmd, speed):
    drive_cmd.linear.x = speed
    drive_cmd.angular.z = 0


def driveTurn(drive_cmd, speed):
    drive_cmd.linear.x = 0
    drive_cmd.angular.z = speed


def talker():
    driveMotor = rospy.Publisher('driveMotor', Twist, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    # rate = rospy.Rate(1)  # 10hz
    drive_cmd = Twist()
    while not rospy.is_shutdown():
        # Move
        driveStraight(drive_cmd, 75)
        rospy.loginfo("Linear.X: {} Angular.Z: {}".format(drive_cmd.linear.x, drive_cmd.angular.z))
        driveMotor.publish(drive_cmd)
        rospy.sleep(3)
        # Stop
        driveStraight(drive_cmd, 0)
        rospy.loginfo("Linear.X: {} Angular.Z: {}".format(drive_cmd.linear.x, drive_cmd.angular.z))
        driveMotor.publish(drive_cmd)
        rospy.sleep(3)
        # Turn
        driveTurn(drive_cmd, 75)
        rospy.loginfo("Linear.X: {} Angular.Z: {}".format(drive_cmd.linear.x, drive_cmd.angular.z))
        driveMotor.publish(drive_cmd)
        rospy.sleep(3)
        # Stop
        driveStraight(drive_cmd, 0)
        rospy.loginfo("Linear.X: {} Angular.Z: {}".format(drive_cmd.linear.x, drive_cmd.angular.z))
        driveMotor.publish(drive_cmd)
        rospy.sleep(3)

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
