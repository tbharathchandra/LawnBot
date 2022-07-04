; Auto-generated. Do not edit!


(cl:in-package polygon_coverage_msgs-msg)


;//! \htmlinclude PolygonWithHolesStamped.msg.html

(cl:defclass <PolygonWithHolesStamped> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (polygon
    :reader polygon
    :initarg :polygon
    :type polygon_coverage_msgs-msg:PolygonWithHoles
    :initform (cl:make-instance 'polygon_coverage_msgs-msg:PolygonWithHoles)))
)

(cl:defclass PolygonWithHolesStamped (<PolygonWithHolesStamped>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PolygonWithHolesStamped>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PolygonWithHolesStamped)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name polygon_coverage_msgs-msg:<PolygonWithHolesStamped> is deprecated: use polygon_coverage_msgs-msg:PolygonWithHolesStamped instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <PolygonWithHolesStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader polygon_coverage_msgs-msg:header-val is deprecated.  Use polygon_coverage_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'polygon-val :lambda-list '(m))
(cl:defmethod polygon-val ((m <PolygonWithHolesStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader polygon_coverage_msgs-msg:polygon-val is deprecated.  Use polygon_coverage_msgs-msg:polygon instead.")
  (polygon m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PolygonWithHolesStamped>) ostream)
  "Serializes a message object of type '<PolygonWithHolesStamped>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'polygon) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PolygonWithHolesStamped>) istream)
  "Deserializes a message object of type '<PolygonWithHolesStamped>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'polygon) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PolygonWithHolesStamped>)))
  "Returns string type for a message object of type '<PolygonWithHolesStamped>"
  "polygon_coverage_msgs/PolygonWithHolesStamped")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PolygonWithHolesStamped)))
  "Returns string type for a message object of type 'PolygonWithHolesStamped"
  "polygon_coverage_msgs/PolygonWithHolesStamped")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PolygonWithHolesStamped>)))
  "Returns md5sum for a message object of type '<PolygonWithHolesStamped>"
  "11ecbf0df20ddfcc1b6166cf645d78f1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PolygonWithHolesStamped)))
  "Returns md5sum for a message object of type 'PolygonWithHolesStamped"
  "11ecbf0df20ddfcc1b6166cf645d78f1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PolygonWithHolesStamped>)))
  "Returns full string definition for message of type '<PolygonWithHolesStamped>"
  (cl:format cl:nil "# A stamped polygon with holes.~%std_msgs/Header header~%polygon_coverage_msgs/PolygonWithHoles polygon~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: polygon_coverage_msgs/PolygonWithHoles~%# A message to define a polygon with holes.~%geometry_msgs/Polygon hull~%geometry_msgs/Polygon[] holes~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PolygonWithHolesStamped)))
  "Returns full string definition for message of type 'PolygonWithHolesStamped"
  (cl:format cl:nil "# A stamped polygon with holes.~%std_msgs/Header header~%polygon_coverage_msgs/PolygonWithHoles polygon~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: polygon_coverage_msgs/PolygonWithHoles~%# A message to define a polygon with holes.~%geometry_msgs/Polygon hull~%geometry_msgs/Polygon[] holes~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PolygonWithHolesStamped>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'polygon))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PolygonWithHolesStamped>))
  "Converts a ROS message object to a list"
  (cl:list 'PolygonWithHolesStamped
    (cl:cons ':header (header msg))
    (cl:cons ':polygon (polygon msg))
))
