; Auto-generated. Do not edit!


(cl:in-package polygon_coverage_msgs-srv)


;//! \htmlinclude PolygonService-request.msg.html

(cl:defclass <PolygonService-request> (roslisp-msg-protocol:ros-message)
  ((polygon
    :reader polygon
    :initarg :polygon
    :type polygon_coverage_msgs-msg:PolygonWithHolesStamped
    :initform (cl:make-instance 'polygon_coverage_msgs-msg:PolygonWithHolesStamped)))
)

(cl:defclass PolygonService-request (<PolygonService-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PolygonService-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PolygonService-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name polygon_coverage_msgs-srv:<PolygonService-request> is deprecated: use polygon_coverage_msgs-srv:PolygonService-request instead.")))

(cl:ensure-generic-function 'polygon-val :lambda-list '(m))
(cl:defmethod polygon-val ((m <PolygonService-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader polygon_coverage_msgs-srv:polygon-val is deprecated.  Use polygon_coverage_msgs-srv:polygon instead.")
  (polygon m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PolygonService-request>) ostream)
  "Serializes a message object of type '<PolygonService-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'polygon) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PolygonService-request>) istream)
  "Deserializes a message object of type '<PolygonService-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'polygon) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PolygonService-request>)))
  "Returns string type for a service object of type '<PolygonService-request>"
  "polygon_coverage_msgs/PolygonServiceRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PolygonService-request)))
  "Returns string type for a service object of type 'PolygonService-request"
  "polygon_coverage_msgs/PolygonServiceRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PolygonService-request>)))
  "Returns md5sum for a message object of type '<PolygonService-request>"
  "7c41cb26384cf37ba066f9b416bd9391")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PolygonService-request)))
  "Returns md5sum for a message object of type 'PolygonService-request"
  "7c41cb26384cf37ba066f9b416bd9391")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PolygonService-request>)))
  "Returns full string definition for message of type '<PolygonService-request>"
  (cl:format cl:nil "# A service to set a new polygon with holes.~%# Request fields:~%polygon_coverage_msgs/PolygonWithHolesStamped polygon # The new polygon.~%~%================================================================================~%MSG: polygon_coverage_msgs/PolygonWithHolesStamped~%# A stamped polygon with holes.~%std_msgs/Header header~%polygon_coverage_msgs/PolygonWithHoles polygon~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: polygon_coverage_msgs/PolygonWithHoles~%# A message to define a polygon with holes.~%geometry_msgs/Polygon hull~%geometry_msgs/Polygon[] holes~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PolygonService-request)))
  "Returns full string definition for message of type 'PolygonService-request"
  (cl:format cl:nil "# A service to set a new polygon with holes.~%# Request fields:~%polygon_coverage_msgs/PolygonWithHolesStamped polygon # The new polygon.~%~%================================================================================~%MSG: polygon_coverage_msgs/PolygonWithHolesStamped~%# A stamped polygon with holes.~%std_msgs/Header header~%polygon_coverage_msgs/PolygonWithHoles polygon~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: polygon_coverage_msgs/PolygonWithHoles~%# A message to define a polygon with holes.~%geometry_msgs/Polygon hull~%geometry_msgs/Polygon[] holes~%~%================================================================================~%MSG: geometry_msgs/Polygon~%#A specification of a polygon where the first and last points are assumed to be connected~%Point32[] points~%~%================================================================================~%MSG: geometry_msgs/Point32~%# This contains the position of a point in free space(with 32 bits of precision).~%# It is recommeded to use Point wherever possible instead of Point32.  ~%# ~%# This recommendation is to promote interoperability.  ~%#~%# This message is designed to take up less space when sending~%# lots of points at once, as in the case of a PointCloud.  ~%~%float32 x~%float32 y~%float32 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PolygonService-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'polygon))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PolygonService-request>))
  "Converts a ROS message object to a list"
  (cl:list 'PolygonService-request
    (cl:cons ':polygon (polygon msg))
))
;//! \htmlinclude PolygonService-response.msg.html

(cl:defclass <PolygonService-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass PolygonService-response (<PolygonService-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PolygonService-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PolygonService-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name polygon_coverage_msgs-srv:<PolygonService-response> is deprecated: use polygon_coverage_msgs-srv:PolygonService-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <PolygonService-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader polygon_coverage_msgs-srv:success-val is deprecated.  Use polygon_coverage_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PolygonService-response>) ostream)
  "Serializes a message object of type '<PolygonService-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PolygonService-response>) istream)
  "Deserializes a message object of type '<PolygonService-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PolygonService-response>)))
  "Returns string type for a service object of type '<PolygonService-response>"
  "polygon_coverage_msgs/PolygonServiceResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PolygonService-response)))
  "Returns string type for a service object of type 'PolygonService-response"
  "polygon_coverage_msgs/PolygonServiceResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PolygonService-response>)))
  "Returns md5sum for a message object of type '<PolygonService-response>"
  "7c41cb26384cf37ba066f9b416bd9391")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PolygonService-response)))
  "Returns md5sum for a message object of type 'PolygonService-response"
  "7c41cb26384cf37ba066f9b416bd9391")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PolygonService-response>)))
  "Returns full string definition for message of type '<PolygonService-response>"
  (cl:format cl:nil "# Response fields:~%bool success # True on success, false on polygon error.~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PolygonService-response)))
  "Returns full string definition for message of type 'PolygonService-response"
  (cl:format cl:nil "# Response fields:~%bool success # True on success, false on polygon error.~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PolygonService-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PolygonService-response>))
  "Converts a ROS message object to a list"
  (cl:list 'PolygonService-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'PolygonService)))
  'PolygonService-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'PolygonService)))
  'PolygonService-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PolygonService)))
  "Returns string type for a service object of type '<PolygonService>"
  "polygon_coverage_msgs/PolygonService")