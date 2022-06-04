#!/usr/bin/env python

import rospy
from math import sin, cos, pi

from geometry_msgs.msg import Quaternion
from geometry_msgs.msg import Twist
from nav_msgs.msg import Odometry
from tf.broadcaster import TransformBroadcaster
from geometry_msgs.msg import Vector3Stamped


class DifferencialTf:
    def __init__(self):
        rospy.init_node("differential_tf")
        self.nodename = rospy.get_name()
        rospy.loginfo("-I- %s started" % self.nodename)

        #Parameters
        self.base_width = float(rospy.get_param('~base_width', 0.3525)) # The wheel base width in meters
        self.base_frame_id = rospy.get_param('~base_frame_id','base_link') # the name of the base frame of the robot
        self.odom_frame_id = rospy.get_param('~odom_frame_id', 'odom') # the name of the odometry reference frame

        rospy.loginfo("Params")
        rospy.loginfo("Base Width: " + str(self.base_width))
        rospy.loginfo("Base Frame ID: " + self.base_frame_id)
        rospy.loginfo("Odom Frame ID: " + self.odom_frame_id)

        self.x = 0                  # position in xy plane 
        self.y = 0
        self.th = 0
        self.dx = 0                 # speeds in x/rotation
        self.dr = 0

        # subscriptions
        rospy.Subscriber("speed", Vector3Stamped, self.speedCallback)
        self.odomPub = rospy.Publisher("odom", Odometry, queue_size=10)
        self.odomBroadcaster = TransformBroadcaster()

        rospy.spin()

    def speedCallback(self, msg):
        speedLeft = msg.vector.x # actucal speed (m/s) values coming robot
        speedRight = msg.vector.y
        speedDelta = msg.vector.z # in seconds

        # calculate distance travelled by left and right wheels in delta time
        d_left = speedLeft * speedDelta
        d_right = speedRight * speedDelta
        
        # distance traveled is the average of the two wheels 
        d = ( d_left + d_right ) / 2
        # this approximation works (in radians) for small angles
        th = ( d_right - d_left ) / self.base_width

        # calculate velocities
        self.dx = d / speedDelta
        self.dr = th / speedDelta

        if (d != 0):
            # calculate distance traveled in x and y
            x = cos( th ) * d
            y = -sin( th ) * d
            # calculate the final position of the robot
            self.x = self.x + ( cos( self.th ) * x - sin( self.th ) * y )
            self.y = self.y + ( sin( self.th ) * x + cos( self.th ) * y )
        if( th != 0):
            self.th = self.th + th

        # publish the odom information
        quaternion = Quaternion()
        quaternion.x = 0.0
        quaternion.y = 0.0
        quaternion.z = sin( self.th / 2 )
        quaternion.w = cos( self.th / 2 )
        self.odomBroadcaster.sendTransform(
            (self.x, self.y, 0),
            (quaternion.x, quaternion.y, quaternion.z, quaternion.w),
            rospy.Time.now(),
            self.base_frame_id,
            self.odom_frame_id
            )
        
        odom = Odometry()
        odom.header.stamp = rospy.Time.now()
        odom.header.frame_id = self.odom_frame_id
        odom.pose.pose.position.x = self.x
        odom.pose.pose.position.y = self.y
        odom.pose.pose.position.z = 0
        odom.pose.pose.orientation = quaternion
        odom.child_frame_id = self.base_frame_id
        odom.twist.twist.linear.x = self.dx
        odom.twist.twist.linear.y = 0
        odom.twist.twist.angular.z = self.dr
        self.odomPub.publish(odom)




if __name__ == '__main__':
    """ main """
    try:
        DifferencialTf()
    except rospy.ROSInterruptException:
        pass