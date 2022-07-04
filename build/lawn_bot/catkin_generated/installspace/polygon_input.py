#!/usr/bin/env python3

import rospy

from geometry_msgs.msg import Twist, Point32, Polygon, PoseStamped
from nav_msgs.msg import Odometry
from polygon_coverage_msgs.msg import PolygonWithHolesStamped
from polygon_coverage_msgs.srv import PolygonService, PlannerService

import sys, select, termios, tty

msg = """
Control Your Lawn Bot and provide your lawn boundary infromation!
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .

q/z : increase/decrease max speeds by 10%
w/x : increase/decrease only linear speed by 10%
e/c : increase/decrease only angular speed by 10%
space key, k : force stop
anything else : stop smoothly

b: boundary mode
h: hole mode
d: drop point
p: publish polygon
r: reset

CTRL-C to quit
"""

moveBindings = {
        'i':(1,0),
        'o':(1,-1),
        'j':(0,1),
        'l':(0,-1),
        'u':(1,1),
        ',':(-1,0),
        '.':(-1,1),
        'm':(-1,-1),
           }

speedBindings={
        'q':(1.1,1.1),
        'z':(.9,.9),
        'w':(1.1,1),
        'x':(.9,1),
        'e':(1,1.1),
        'c':(1,.9),
          }

boundaryMode = False
holeMode = False
odomX = 0.0
odomY = 0.0
boundary = []
holes = []
hole = []


def getKey():
    tty.setraw(sys.stdin.fileno())
    rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
    if rlist:
        key = sys.stdin.read(1)
    else:
        key = ''

    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
    return key

speed = .2
turn = 1

def vels(speed,turn):
    return "currently:\tspeed %s\tturn %s " % (speed,turn)

def poseCallback(odom_message):
    global odomX, odomY
    odomX = odom_message.pose.pose.position.x
    odomY = odom_message.pose.pose.position.y


def handleDropPoint():
    if boundaryMode:
        boundary.append((odomX, odomY))
        print('Added '+str(odomX)+' '+str(odomY)+' point to boundary')
    elif holeMode:
        hole.append((odomX, odomY))
        print('Added '+str(odomX)+' '+str(odomY)+' point to temporary hole')

def publishPolygonWithHoles(polygonPub):
    if len(boundary)>0:
        msgPolygon = PolygonWithHolesStamped()
        msgPolygon.header.frame_id='map'
        msgPolygon.header.stamp=rospy.Time.now()
        for x, y in boundary:
            point = Point32()
            point.x = float(x)
            point.y = float(y)
            point.z = 0.0
            msgPolygon.polygon.hull.points.append(point)
        if len(holes) > 0:
            print(str(len(holes))+' holes added')
            for i in range(len(holes)):
                polygon = Polygon()
                for j in range(len(holes[i])):
                    x, y = holes[i][j]
                    point = Point32()
                    point.x = float(x)
                    point.y = float(y)
                    point.z = 0.01
                    polygon.points.append(point)
                msgPolygon.polygon.holes.append(polygon)
        
        polygonPub.publish(msgPolygon)

        setPolygon = rospy.ServiceProxy('/coverage_planner/set_polygon', PolygonService)
        polygonOK = False
        try:
            polygonOK = setPolygon(msgPolygon)
        except rospy.ServiceException as exc:
            print("Polygon Service did not process request: " + str(exc))

        if polygonOK:
            print('Polygon set success, sending the message to planner')
            startPoint = msgPolygon.polygon.hull.points[0]
            startPose = PoseStamped()
            startPose.header.stamp=rospy.Time.now()
            startPose.header.frame_id='map'
            startPose.pose.position.x = startPoint.x
            startPose.pose.position.y = startPoint.y
            startPose.pose.position.z = 0.0
            startPose.pose.orientation.x = 0.0
            startPose.pose.orientation.y = 0.0
            startPose.pose.orientation.z = 0.0
            startPose.pose.orientation.w = 0.0
            endPose = startPose
            planPolygon = rospy.ServiceProxy('/coverage_planner/plan_path', PlannerService)
            planOK = False
            try:
                resp= planPolygon(startPose, endPose)
                planOK = resp.success
            except rospy.ServiceException as exc:
                print("Polygon Planner Service did not process request: " + str(exc))

            if planOK:
                print("Plan generated successfully")
                print(resp.sampled_plan)
            
            rospy.signal_shutdown("Plan generated successfully")


        boundaryMode = False
        holeMode = False
        boundary.clear()
        holes.clear()
        hole.clear()



if __name__=="__main__":
    settings = termios.tcgetattr(sys.stdin)
    
    rospy.init_node('polygon_input')
    pub = rospy.Publisher('cmd_vel', Twist, queue_size=5)
    polygonPub  = rospy.Publisher('polygon', PolygonWithHolesStamped, queue_size=1)
    # subscriptions
    rospy.Subscriber("odometry/filtered", Odometry, poseCallback)

    x = 0
    th = 0
    status = 0
    count = 0
    acc = 0.1
    target_speed = 0
    target_turn = 0
    control_speed = 0
    control_turn = 0
    try:
        print(msg)
        print(vels(speed,turn))
        while(1):
            key = getKey()
            if key in moveBindings.keys():
                x = moveBindings[key][0]
                th = moveBindings[key][1]
                count = 0
            elif key in speedBindings.keys():
                speed = speed * speedBindings[key][0]
                turn = turn * speedBindings[key][1]
                count = 0

                print(vels(speed,turn))
                if (status == 14):
                    print(msg)
                status = (status + 1) % 15
            elif key == ' ' or key == 'k' :
                x = 0
                th = 0
                control_speed = 0
                control_turn = 0
            elif key == 'b':
                boundaryMode = True
                holeMode = False
                print('Boundary mode activated')
            elif key == 'h':
                if len(hole) > 0 and holeMode:
                    holes.append(hole.copy())
                    hole.clear()
                    holeMode = False
                    boundaryMode = False
                    print('Temporary hole added and Holes mode deactivated')
                else:
                    boundaryMode = False
                    holeMode = True
                    print('Holes mode activated')
            elif key == 'd':
                handleDropPoint()
            elif key == 'r':
                boundaryMode = False
                holeMode = False
                boundary.clear()
                holes.clear()
                hole.clear()
                print('Cleared all boundary and holes data')
            elif key == 'p':
                publishPolygonWithHoles(polygonPub)
            else:
                count = count + 1
                if count > 4:
                    x = 0
                    th = 0
                if (key == '\x03'):
                    break

            target_speed = speed * x
            target_turn = turn * th

            if target_speed > control_speed:
                control_speed = min( target_speed, control_speed + 0.02 )
            elif target_speed < control_speed:
                control_speed = max( target_speed, control_speed - 0.02 )
            else:
                control_speed = target_speed

            if target_turn > control_turn:
                control_turn = min( target_turn, control_turn + 0.1 )
            elif target_turn < control_turn:
                control_turn = max( target_turn, control_turn - 0.1 )
            else:
                control_turn = target_turn

            twist = Twist()
            twist.linear.x = control_speed; twist.linear.y = 0; twist.linear.z = 0
            twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = control_turn
            pub.publish(twist)

            #print("loop: {0}".format(count))
            #print("target: vx: {0}, wz: {1}".format(target_speed, target_turn))
            #print("publihsed: vx: {0}, wz: {1}".format(twist.linear.x, twist.angular.z))

    except Exception as e:
        print(e)

    finally:
        twist = Twist()
        twist.linear.x = 0; twist.linear.y = 0; twist.linear.z = 0
        twist.angular.x = 0; twist.angular.y = 0; twist.angular.z = 0
        pub.publish(twist)

    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, settings)
