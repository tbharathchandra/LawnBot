;; Auto-generated. Do not edit!


(when (boundp 'polygon_coverage_msgs::PlannerService)
  (if (not (find-package "POLYGON_COVERAGE_MSGS"))
    (make-package "POLYGON_COVERAGE_MSGS"))
  (shadow 'PlannerService (find-package "POLYGON_COVERAGE_MSGS")))
(unless (find-package "POLYGON_COVERAGE_MSGS::PLANNERSERVICE")
  (make-package "POLYGON_COVERAGE_MSGS::PLANNERSERVICE"))
(unless (find-package "POLYGON_COVERAGE_MSGS::PLANNERSERVICEREQUEST")
  (make-package "POLYGON_COVERAGE_MSGS::PLANNERSERVICEREQUEST"))
(unless (find-package "POLYGON_COVERAGE_MSGS::PLANNERSERVICERESPONSE")
  (make-package "POLYGON_COVERAGE_MSGS::PLANNERSERVICERESPONSE"))

(in-package "ROS")

(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(if (not (find-package "TRAJECTORY_MSGS"))
  (ros::roseus-add-msgs "trajectory_msgs"))


(defclass polygon_coverage_msgs::PlannerServiceRequest
  :super ros::object
  :slots (_start_pose _goal_pose ))

(defmethod polygon_coverage_msgs::PlannerServiceRequest
  (:init
   (&key
    ((:start_pose __start_pose) (instance geometry_msgs::PoseStamped :init))
    ((:goal_pose __goal_pose) (instance geometry_msgs::PoseStamped :init))
    )
   (send-super :init)
   (setq _start_pose __start_pose)
   (setq _goal_pose __goal_pose)
   self)
  (:start_pose
   (&rest __start_pose)
   (if (keywordp (car __start_pose))
       (send* _start_pose __start_pose)
     (progn
       (if __start_pose (setq _start_pose (car __start_pose)))
       _start_pose)))
  (:goal_pose
   (&rest __goal_pose)
   (if (keywordp (car __goal_pose))
       (send* _goal_pose __goal_pose)
     (progn
       (if __goal_pose (setq _goal_pose (car __goal_pose)))
       _goal_pose)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/PoseStamped _start_pose
    (send _start_pose :serialization-length)
    ;; geometry_msgs/PoseStamped _goal_pose
    (send _goal_pose :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/PoseStamped _start_pose
       (send _start_pose :serialize s)
     ;; geometry_msgs/PoseStamped _goal_pose
       (send _goal_pose :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/PoseStamped _start_pose
     (send _start_pose :deserialize buf ptr-) (incf ptr- (send _start_pose :serialization-length))
   ;; geometry_msgs/PoseStamped _goal_pose
     (send _goal_pose :deserialize buf ptr-) (incf ptr- (send _goal_pose :serialization-length))
   ;;
   self)
  )

(defclass polygon_coverage_msgs::PlannerServiceResponse
  :super ros::object
  :slots (_success _sampled_plan ))

(defmethod polygon_coverage_msgs::PlannerServiceResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:sampled_plan __sampled_plan) (instance trajectory_msgs::MultiDOFJointTrajectory :init))
    )
   (send-super :init)
   (setq _success __success)
   (setq _sampled_plan __sampled_plan)
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:sampled_plan
   (&rest __sampled_plan)
   (if (keywordp (car __sampled_plan))
       (send* _sampled_plan __sampled_plan)
     (progn
       (if __sampled_plan (setq _sampled_plan (car __sampled_plan)))
       _sampled_plan)))
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; trajectory_msgs/MultiDOFJointTrajectory _sampled_plan
    (send _sampled_plan :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; trajectory_msgs/MultiDOFJointTrajectory _sampled_plan
       (send _sampled_plan :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; trajectory_msgs/MultiDOFJointTrajectory _sampled_plan
     (send _sampled_plan :deserialize buf ptr-) (incf ptr- (send _sampled_plan :serialization-length))
   ;;
   self)
  )

(defclass polygon_coverage_msgs::PlannerService
  :super ros::object
  :slots ())

(setf (get polygon_coverage_msgs::PlannerService :md5sum-) "041d814b74649941198af640c3963ac3")
(setf (get polygon_coverage_msgs::PlannerService :datatype-) "polygon_coverage_msgs/PlannerService")
(setf (get polygon_coverage_msgs::PlannerService :request) polygon_coverage_msgs::PlannerServiceRequest)
(setf (get polygon_coverage_msgs::PlannerService :response) polygon_coverage_msgs::PlannerServiceResponse)

(defmethod polygon_coverage_msgs::PlannerServiceRequest
  (:response () (instance polygon_coverage_msgs::PlannerServiceResponse :init)))

(setf (get polygon_coverage_msgs::PlannerServiceRequest :md5sum-) "041d814b74649941198af640c3963ac3")
(setf (get polygon_coverage_msgs::PlannerServiceRequest :datatype-) "polygon_coverage_msgs/PlannerServiceRequest")
(setf (get polygon_coverage_msgs::PlannerServiceRequest :definition-)
      "#request fields
geometry_msgs/PoseStamped start_pose #start pose for the planner
geometry_msgs/PoseStamped goal_pose #start pose for the planner

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
# True on success, false on planning failure
bool success
# Either contains a polynomial trajectory:
trajectory_msgs/MultiDOFJointTrajectory sampled_plan


================================================================================
MSG: trajectory_msgs/MultiDOFJointTrajectory
# The header is used to specify the coordinate frame and the reference time for the trajectory durations
Header header

# A representation of a multi-dof joint trajectory (each point is a transformation)
# Each point along the trajectory will include an array of positions/velocities/accelerations
# that has the same length as the array of joint names, and has the same order of joints as 
# the joint names array.

string[] joint_names
MultiDOFJointTrajectoryPoint[] points

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: trajectory_msgs/MultiDOFJointTrajectoryPoint
# Each multi-dof joint can specify a transform (up to 6 DOF)
geometry_msgs/Transform[] transforms

# There can be a velocity specified for the origin of the joint 
geometry_msgs/Twist[] velocities

# There can be an acceleration specified for the origin of the joint 
geometry_msgs/Twist[] accelerations

duration time_from_start

================================================================================
MSG: geometry_msgs/Transform
# This represents the transform between two coordinate frames in free space.

Vector3 translation
Quaternion rotation

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular
")

(setf (get polygon_coverage_msgs::PlannerServiceResponse :md5sum-) "041d814b74649941198af640c3963ac3")
(setf (get polygon_coverage_msgs::PlannerServiceResponse :datatype-) "polygon_coverage_msgs/PlannerServiceResponse")
(setf (get polygon_coverage_msgs::PlannerServiceResponse :definition-)
      "#request fields
geometry_msgs/PoseStamped start_pose #start pose for the planner
geometry_msgs/PoseStamped goal_pose #start pose for the planner

================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w
---
# True on success, false on planning failure
bool success
# Either contains a polynomial trajectory:
trajectory_msgs/MultiDOFJointTrajectory sampled_plan


================================================================================
MSG: trajectory_msgs/MultiDOFJointTrajectory
# The header is used to specify the coordinate frame and the reference time for the trajectory durations
Header header

# A representation of a multi-dof joint trajectory (each point is a transformation)
# Each point along the trajectory will include an array of positions/velocities/accelerations
# that has the same length as the array of joint names, and has the same order of joints as 
# the joint names array.

string[] joint_names
MultiDOFJointTrajectoryPoint[] points

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: trajectory_msgs/MultiDOFJointTrajectoryPoint
# Each multi-dof joint can specify a transform (up to 6 DOF)
geometry_msgs/Transform[] transforms

# There can be a velocity specified for the origin of the joint 
geometry_msgs/Twist[] velocities

# There can be an acceleration specified for the origin of the joint 
geometry_msgs/Twist[] accelerations

duration time_from_start

================================================================================
MSG: geometry_msgs/Transform
# This represents the transform between two coordinate frames in free space.

Vector3 translation
Quaternion rotation

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular
")



(provide :polygon_coverage_msgs/PlannerService "041d814b74649941198af640c3963ac3")


