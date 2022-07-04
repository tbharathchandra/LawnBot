import rospy
import math
from geometry_msgs.msg import PointStamped, PoseArray
from tf.transformations import euler_from_quaternion
from nav_msgs.msg import Odometry
from math import atan2, sqrt


class SimpleSeq():
    def __init__(self):
        rospy.init_node('simple_sequencer')
        self.nodename = rospy.get_name()
        rospy.loginfo("-I- %s started" % self.nodename)
        rospy.loginfo("Waiting for waypoints...")
        self.pose_seq = list()
        self.goal_cnt = 0
        self.odomX = 0
        self.odomY = 0
        self.odomTheta = 0

        self.rate = rospy.Rate(1) # 1hz

        rospy.Subscriber("/waypoint_list", PoseArray, self.waypointsCallbak)
        rospy.Subscriber("/odometry/filtered", Odometry, self.newOdom)
        self.pub = rospy.Publisher("/clicked_point", PointStamped, queue_size = 1)
    
    def waypointsCallbak(self, msg):
        self.pose_seq = msg.poses
        rospy.loginfo("waypoints received: "+str(len(self.pose_seq)))
        self.publishFirstGoal()
    
    def newOdom(self, msg):
        self.odomX = msg.pose.pose.position.x
        self.odomY = msg.pose.pose.position.y

        rot_q = msg.pose.pose.orientation
        (roll, pitch, theta) = euler_from_quaternion([rot_q.x, rot_q.y, rot_q.z, rot_q.w])
        self.odomTheta = theta

    def publishFirstGoal(self):
        newGoalX = self.pose_seq[self.goal_cnt].position.x
        newGoalY = self.pose_seq[self.goal_cnt].position.y
        pointStamped = PointStamped()
        pointStamped.point.x = newGoalX
        pointStamped.point.y = newGoalY
        pointStamped.header.stamp = rospy.Time.now()
        pointStamped.header.frame_id = "map"
        self.pub.publish(pointStamped)
        rospy.loginfo("New Goal published")


    def checkPositionAndSendGoal(self):
        
        if len(self.pose_seq) == 0:
            return

        rospy.loginfo("Checking current location")
        goalX = self.pose_seq[self.goal_cnt].position.x
        goalY = self.pose_seq[self.goal_cnt].position.y
        rot_q = self.pose_seq[self.goal_cnt].orientation
        (roll, pitch, theta) = euler_from_quaternion([rot_q.x, rot_q.y, rot_q.z, rot_q.w])
        goalTheta = theta
        
        inc_x = goalX - self.odomX
        inc_y = goalY - self.odomY

        distance = abs(sqrt((inc_x*inc_x) + (inc_y*inc_y)))

        angle_to_goal = atan2(inc_y, inc_x)

        if distance < 0.1: # Goal Reached
            self.goal_cnt += 1
            
            if self.goal_cnt == len(self.pose_seq):
                self.goal_cnt = 0
                rospy.loginfo("Restarting sequence!!")

            newGoalX = self.pose_seq[self.goal_cnt].position.x
            newGoalY = self.pose_seq[self.goal_cnt].position.y
            pointStamped = PointStamped()
            pointStamped.point.x = newGoalX
            pointStamped.point.y = newGoalY
            pointStamped.header.stamp = rospy.Time.now()
            pointStamped.header.frame_id = "map"
            self.pub.publish(pointStamped)
            rospy.loginfo("New Goal published")

    def spin(self):
        while not rospy.is_shutdown():
            self.checkPositionAndSendGoal()

            # Sleeps @ rate "1 loop/second"
            self.rate.sleep()

    

if __name__ == '__main__':
    """ main """
    try:
        ss = SimpleSeq()
        ss.spin()
    except rospy.ROSInterruptException:
        pass