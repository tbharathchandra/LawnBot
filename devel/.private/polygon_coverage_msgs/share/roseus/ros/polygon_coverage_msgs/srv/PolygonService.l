;; Auto-generated. Do not edit!


(when (boundp 'polygon_coverage_msgs::PolygonService)
  (if (not (find-package "POLYGON_COVERAGE_MSGS"))
    (make-package "POLYGON_COVERAGE_MSGS"))
  (shadow 'PolygonService (find-package "POLYGON_COVERAGE_MSGS")))
(unless (find-package "POLYGON_COVERAGE_MSGS::POLYGONSERVICE")
  (make-package "POLYGON_COVERAGE_MSGS::POLYGONSERVICE"))
(unless (find-package "POLYGON_COVERAGE_MSGS::POLYGONSERVICEREQUEST")
  (make-package "POLYGON_COVERAGE_MSGS::POLYGONSERVICEREQUEST"))
(unless (find-package "POLYGON_COVERAGE_MSGS::POLYGONSERVICERESPONSE")
  (make-package "POLYGON_COVERAGE_MSGS::POLYGONSERVICERESPONSE"))

(in-package "ROS")





(defclass polygon_coverage_msgs::PolygonServiceRequest
  :super ros::object
  :slots (_polygon ))

(defmethod polygon_coverage_msgs::PolygonServiceRequest
  (:init
   (&key
    ((:polygon __polygon) (instance polygon_coverage_msgs::PolygonWithHolesStamped :init))
    )
   (send-super :init)
   (setq _polygon __polygon)
   self)
  (:polygon
   (&rest __polygon)
   (if (keywordp (car __polygon))
       (send* _polygon __polygon)
     (progn
       (if __polygon (setq _polygon (car __polygon)))
       _polygon)))
  (:serialization-length
   ()
   (+
    ;; polygon_coverage_msgs/PolygonWithHolesStamped _polygon
    (send _polygon :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; polygon_coverage_msgs/PolygonWithHolesStamped _polygon
       (send _polygon :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; polygon_coverage_msgs/PolygonWithHolesStamped _polygon
     (send _polygon :deserialize buf ptr-) (incf ptr- (send _polygon :serialization-length))
   ;;
   self)
  )

(defclass polygon_coverage_msgs::PolygonServiceResponse
  :super ros::object
  :slots (_success ))

(defmethod polygon_coverage_msgs::PolygonServiceResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass polygon_coverage_msgs::PolygonService
  :super ros::object
  :slots ())

(setf (get polygon_coverage_msgs::PolygonService :md5sum-) "7c41cb26384cf37ba066f9b416bd9391")
(setf (get polygon_coverage_msgs::PolygonService :datatype-) "polygon_coverage_msgs/PolygonService")
(setf (get polygon_coverage_msgs::PolygonService :request) polygon_coverage_msgs::PolygonServiceRequest)
(setf (get polygon_coverage_msgs::PolygonService :response) polygon_coverage_msgs::PolygonServiceResponse)

(defmethod polygon_coverage_msgs::PolygonServiceRequest
  (:response () (instance polygon_coverage_msgs::PolygonServiceResponse :init)))

(setf (get polygon_coverage_msgs::PolygonServiceRequest :md5sum-) "7c41cb26384cf37ba066f9b416bd9391")
(setf (get polygon_coverage_msgs::PolygonServiceRequest :datatype-) "polygon_coverage_msgs/PolygonServiceRequest")
(setf (get polygon_coverage_msgs::PolygonServiceRequest :definition-)
      "# A service to set a new polygon with holes.
# Request fields:
polygon_coverage_msgs/PolygonWithHolesStamped polygon # The new polygon.

================================================================================
MSG: polygon_coverage_msgs/PolygonWithHolesStamped
# A stamped polygon with holes.
std_msgs/Header header
polygon_coverage_msgs/PolygonWithHoles polygon

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
MSG: polygon_coverage_msgs/PolygonWithHoles
# A message to define a polygon with holes.
geometry_msgs/Polygon hull
geometry_msgs/Polygon[] holes

================================================================================
MSG: geometry_msgs/Polygon
#A specification of a polygon where the first and last points are assumed to be connected
Point32[] points

================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
---
# Response fields:
bool success # True on success, false on polygon error.

")

(setf (get polygon_coverage_msgs::PolygonServiceResponse :md5sum-) "7c41cb26384cf37ba066f9b416bd9391")
(setf (get polygon_coverage_msgs::PolygonServiceResponse :datatype-) "polygon_coverage_msgs/PolygonServiceResponse")
(setf (get polygon_coverage_msgs::PolygonServiceResponse :definition-)
      "# A service to set a new polygon with holes.
# Request fields:
polygon_coverage_msgs/PolygonWithHolesStamped polygon # The new polygon.

================================================================================
MSG: polygon_coverage_msgs/PolygonWithHolesStamped
# A stamped polygon with holes.
std_msgs/Header header
polygon_coverage_msgs/PolygonWithHoles polygon

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
MSG: polygon_coverage_msgs/PolygonWithHoles
# A message to define a polygon with holes.
geometry_msgs/Polygon hull
geometry_msgs/Polygon[] holes

================================================================================
MSG: geometry_msgs/Polygon
#A specification of a polygon where the first and last points are assumed to be connected
Point32[] points

================================================================================
MSG: geometry_msgs/Point32
# This contains the position of a point in free space(with 32 bits of precision).
# It is recommeded to use Point wherever possible instead of Point32.  
# 
# This recommendation is to promote interoperability.  
#
# This message is designed to take up less space when sending
# lots of points at once, as in the case of a PointCloud.  

float32 x
float32 y
---
# Response fields:
bool success # True on success, false on polygon error.

")



(provide :polygon_coverage_msgs/PolygonService "7c41cb26384cf37ba066f9b416bd9391")


