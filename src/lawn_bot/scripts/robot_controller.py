import rospy
from nav_msgs.msg import Odometry
from tf.transformations import euler_from_quaternion
from geometry_msgs.msg import PointStamped, Twist
from math import atan2

class RobotController:
    def __init__(self):
        rospy.init_node("robot_controller")
        self.nodename = rospy.get_name()
        rospy.loginfo("-I- %s started" % self.nodename)

        self.odomX = 0
        self.odomY = 0
        self.odomTheta = 0
        self.goalX = None
        self.goalY = None

        self.rate = rospy.Rate(1) # 1hz

        # Subscribes
        rospy.Subscriber("odom", Odometry, self.newOdom)
        rospy.Subscriber("clicked_point", PointStamped, self.newGoal)

        # Publishes
        self.pub = rospy.Publisher("/cmd_vel", Twist, queue_size = 1)


    def updateTwist(self):
        
        if(self.goalX == None or self.goalY == None):
            return

        speed = Twist()

        inc_x = self.goalX - self.odomX
        inc_y = self.goalY - self.odomY

        angle_to_goal = atan2(inc_y, inc_x)

        if abs(angle_to_goal - self.odomTheta) > 0.1:
            speed.linear.x = 0.0
            speed.angular.z = 0.3
        else:
            speed.linear.x = 0.5
            speed.angular.z = 0.0

        self.pub.publish(speed)

    def newOdom(self, msg):
        self.odomX = msg.pose.pose.position.x
        self.odomY = msg.pose.pose.position.y

        rot_q = msg.pose.pose.orientation
        (roll, pitch, theta) = euler_from_quaternion([rot_q.x, rot_q.y, rot_q.z, rot_q.w])
        self.odomTheta = theta
    
    def newGoal(self, msg):
        self.goalX = msg.point.x
        self.goalY = msg.point.y


    def spin(self):
        while not rospy.is_shutdown():
            self.updateTwist()

            # Sleeps @ rate "1 loop/second"
            self.rate.sleep()

    

if __name__ == '__main__':
    """ main """
    try:
        rc = RobotController()
        rc.spin()
    except rospy.ROSInterruptException:
        pass