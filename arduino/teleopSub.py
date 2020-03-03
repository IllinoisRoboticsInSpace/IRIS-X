#!/usr/bin/env python

"""
Simple demo that publishes drive commands from joycon using teleop_twist_joy ros package

Note: to view joy topic data directly, run: rostopic echo joy
Note 2: if this file is not executable, run chmod +x teleopSub.py

To run:
sudo apt install ros-melodic-teleop-twist-joy
make a ros package + make a scripts folder + put this pyfile in the catkin package scripts folder
cd catkin_ws && catkin_make
cd catkin_ws && source ./devel/setup.bash
roslaunch teleop_twist_joy teleop.launch
rosrun <Package Name> telopSub.py
"""
import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import Joy


drive_cmd = Twist()
def callback(data):
    global drive_cmd
    drive_cmd.linear.x = 127 * data.axes[1]
    drive_cmd.angular.z = 0


def teleopPub():
    global drive_cmd
    driveMotor = rospy.Publisher('driveMotor', Twist, queue_size=10)
    rospy.init_node('teleopPub', anonymous=True)
    # rate = rospy.Rate(1)  # 10hz

    rospy.Subscriber('joy', Joy, callback)
    while not rospy.is_shutdown():
        # Moves when joycon is toggled
        rospy.loginfo("Linear.X: {} Angular.Z: {}".format(drive_cmd.linear.x, drive_cmd.angular.z))
        driveMotor.publish(drive_cmd)
        rospy.sleep(0.1)
    rospy.spin()

if __name__ == '__main__':
    try:
        teleopPub()
    except rospy.ROSInterruptException:
        pass
