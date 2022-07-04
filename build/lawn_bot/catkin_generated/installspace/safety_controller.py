import rospy
from std_msgs.msg import Float32, Bool


class SafetyController:

    DISTANCE_THRESHOLD_IN_CM = 20

    def sonarCallback(self, msg):
        self.sonar_distance = msg.data

    def __init__(self):
        rospy.init_node("safety_controller")
        self.nodename = rospy.get_name()
        rospy.loginfo("-I- %s started" % self.nodename)
        self.rate = rospy.Rate(5) # 5hz

        self.sonar_distance = 200 #in cm
        # subscriptions
        rospy.Subscriber("sonar_dist", Float32, self.sonarCallback)
        
        self.pub = rospy.Publisher("/safety_stop", Bool, queue_size = 1)
         

    def update(self):
        msg = Bool()
        if self.sonar_distance <= self.DISTANCE_THRESHOLD_IN_CM:
            msg.data = True
        else:
            msg.data = False
        self.pub.publish(msg)

    def spin(self):
        while not rospy.is_shutdown():
            self.update()

            # Sleeps @ rate "5 loop/second"
            self.rate.sleep()

if __name__ == '__main__':
    """ main """
    try:
        sc = SafetyController()
        sc.spin()
    except rospy.ROSInterruptException:
        pass