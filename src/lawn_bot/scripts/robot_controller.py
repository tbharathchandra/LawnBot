import rospy
from nav_msgs.msg import Odometry
from tf.transformations import euler_from_quaternion
from geometry_msgs.msg import PointStamped, Twist
from math import atan2, sqrt
from std_msgs.msg import Bool


class RobotController:

    PI_IN_RADIANS = 3.14159
    FOWARD_SPEED = 0.11 #in m/s
    ROTATION_SPEED = 0.22

    def __init__(self):
        rospy.init_node("robot_controller")
        self.nodename = rospy.get_name()
        rospy.loginfo("-I- %s started" % self.nodename)

        self.odomX = 0
        self.odomY = 0
        self.odomTheta = 0
        self.goalX = None
        self.goalY = None
        self.safety_stop = False

        self.rate = rospy.Rate(5) # 5hz

        # Subscribes
        rospy.Subscriber("odometry/filtered", Odometry, self.newOdom)
        rospy.Subscriber("clicked_point", PointStamped, self.newGoal)
        rospy.Subscriber("safety_stop", Bool, self.safetyCallback)

        # Publishes
        self.pub = rospy.Publisher("/cmd_vel", Twist, queue_size = 1)

    def safetyCallback(self, msg):
        self.safety_stop = msg.data

    def updateTwist(self):
        
        if(self.goalX == None or self.goalY == None):
            return
        

        speed = Twist()

        inc_x = self.goalX - self.odomX
        inc_y = self.goalY - self.odomY

        # Calculating the cartesian distance between current and goal point
        distance = abs(sqrt((inc_x*inc_x) + (inc_y*inc_y)))

        angle_to_goal = atan2(inc_y, inc_x)
        # rospy.loginfo("angle to goal: " + str(angle_to_goal) + "-- yaw theta: " + str(self.odomTheta))
        if self.safety_stop or distance < 0.1:
            self.pub.publish(speed)
            return

        if self.angleBetween(angle_to_goal, self.odomTheta) > 0.15:
            speed.linear.x = 0.0
            if (angle_to_goal > 0 and self.odomTheta > 0) or (angle_to_goal < 0 and self.odomTheta < 0):
                if (angle_to_goal > self.odomTheta):
                    speed.angular.z = self.ROTATION_SPEED
                else:
                    speed.angular.z = -self.ROTATION_SPEED
            elif (angle_to_goal > 0 and self.odomTheta < 0) or (angle_to_goal < 0 and self.odomTheta > 0):
                if self.odomTheta > self.complimentaryAngle(angle_to_goal):
                    speed.angular.z = self.ROTATION_SPEED
                else:
                    speed.angular.z = -self.ROTATION_SPEED
            else: 
                speed.angular.z = self.ROTATION_SPEED

        else:
            speed.linear.x = self.FOWARD_SPEED
            speed.angular.z = 0.0

        self.pub.publish(speed)

    def complimentaryAngle(self, angle):
        if (angle > 0):
            return -(self.PI_IN_RADIANS - angle)
        else:
            return (self.PI_IN_RADIANS - angle)

    def angleBetween(self, angle_to_goal, odomTheta):
        angle = abs(angle_to_goal - odomTheta)
        if angle > self.PI_IN_RADIANS:
            angle = (2*self.PI_IN_RADIANS) - angle
        return angle

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

            # Sleeps @ rate "5 loop/second"
            self.rate.sleep()

    

if __name__ == '__main__':
    """ main """
    try:
        rc = RobotController()
        rc.spin()
    except rospy.ROSInterruptException:
        pass