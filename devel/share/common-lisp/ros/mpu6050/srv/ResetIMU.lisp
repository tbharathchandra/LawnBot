; Auto-generated. Do not edit!


(cl:in-package mpu6050-srv)


;//! \htmlinclude ResetIMU-request.msg.html

(cl:defclass <ResetIMU-request> (roslisp-msg-protocol:ros-message)
  ((command
    :reader command
    :initarg :command
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ResetIMU-request (<ResetIMU-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ResetIMU-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ResetIMU-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mpu6050-srv:<ResetIMU-request> is deprecated: use mpu6050-srv:ResetIMU-request instead.")))

(cl:ensure-generic-function 'command-val :lambda-list '(m))
(cl:defmethod command-val ((m <ResetIMU-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpu6050-srv:command-val is deprecated.  Use mpu6050-srv:command instead.")
  (command m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ResetIMU-request>) ostream)
  "Serializes a message object of type '<ResetIMU-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'command) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ResetIMU-request>) istream)
  "Deserializes a message object of type '<ResetIMU-request>"
    (cl:setf (cl:slot-value msg 'command) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ResetIMU-request>)))
  "Returns string type for a service object of type '<ResetIMU-request>"
  "mpu6050/ResetIMURequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetIMU-request)))
  "Returns string type for a service object of type 'ResetIMU-request"
  "mpu6050/ResetIMURequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ResetIMU-request>)))
  "Returns md5sum for a message object of type '<ResetIMU-request>"
  "093924429c8ce590aa2b41b10a45ad80")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ResetIMU-request)))
  "Returns md5sum for a message object of type 'ResetIMU-request"
  "093924429c8ce590aa2b41b10a45ad80")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ResetIMU-request>)))
  "Returns full string definition for message of type '<ResetIMU-request>"
  (cl:format cl:nil "bool command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ResetIMU-request)))
  "Returns full string definition for message of type 'ResetIMU-request"
  (cl:format cl:nil "bool command~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ResetIMU-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ResetIMU-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ResetIMU-request
    (cl:cons ':command (command msg))
))
;//! \htmlinclude ResetIMU-response.msg.html

(cl:defclass <ResetIMU-response> (roslisp-msg-protocol:ros-message)
  ((result
    :reader result
    :initarg :result
    :type cl:string
    :initform "")
   (message
    :reader message
    :initarg :message
    :type cl:string
    :initform ""))
)

(cl:defclass ResetIMU-response (<ResetIMU-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ResetIMU-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ResetIMU-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name mpu6050-srv:<ResetIMU-response> is deprecated: use mpu6050-srv:ResetIMU-response instead.")))

(cl:ensure-generic-function 'result-val :lambda-list '(m))
(cl:defmethod result-val ((m <ResetIMU-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpu6050-srv:result-val is deprecated.  Use mpu6050-srv:result instead.")
  (result m))

(cl:ensure-generic-function 'message-val :lambda-list '(m))
(cl:defmethod message-val ((m <ResetIMU-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader mpu6050-srv:message-val is deprecated.  Use mpu6050-srv:message instead.")
  (message m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ResetIMU-response>) ostream)
  "Serializes a message object of type '<ResetIMU-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'result))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'result))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'message))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'message))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ResetIMU-response>) istream)
  "Deserializes a message object of type '<ResetIMU-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'result) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'result) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'message) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'message) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ResetIMU-response>)))
  "Returns string type for a service object of type '<ResetIMU-response>"
  "mpu6050/ResetIMUResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetIMU-response)))
  "Returns string type for a service object of type 'ResetIMU-response"
  "mpu6050/ResetIMUResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ResetIMU-response>)))
  "Returns md5sum for a message object of type '<ResetIMU-response>"
  "093924429c8ce590aa2b41b10a45ad80")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ResetIMU-response)))
  "Returns md5sum for a message object of type 'ResetIMU-response"
  "093924429c8ce590aa2b41b10a45ad80")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ResetIMU-response>)))
  "Returns full string definition for message of type '<ResetIMU-response>"
  (cl:format cl:nil "string result~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ResetIMU-response)))
  "Returns full string definition for message of type 'ResetIMU-response"
  (cl:format cl:nil "string result~%string message~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ResetIMU-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'result))
     4 (cl:length (cl:slot-value msg 'message))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ResetIMU-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ResetIMU-response
    (cl:cons ':result (result msg))
    (cl:cons ':message (message msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ResetIMU)))
  'ResetIMU-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ResetIMU)))
  'ResetIMU-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ResetIMU)))
  "Returns string type for a service object of type '<ResetIMU>"
  "mpu6050/ResetIMU")