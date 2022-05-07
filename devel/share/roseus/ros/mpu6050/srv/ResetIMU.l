;; Auto-generated. Do not edit!


(when (boundp 'mpu6050::ResetIMU)
  (if (not (find-package "MPU6050"))
    (make-package "MPU6050"))
  (shadow 'ResetIMU (find-package "MPU6050")))
(unless (find-package "MPU6050::RESETIMU")
  (make-package "MPU6050::RESETIMU"))
(unless (find-package "MPU6050::RESETIMUREQUEST")
  (make-package "MPU6050::RESETIMUREQUEST"))
(unless (find-package "MPU6050::RESETIMURESPONSE")
  (make-package "MPU6050::RESETIMURESPONSE"))

(in-package "ROS")





(defclass mpu6050::ResetIMURequest
  :super ros::object
  :slots (_command ))

(defmethod mpu6050::ResetIMURequest
  (:init
   (&key
    ((:command __command) nil)
    )
   (send-super :init)
   (setq _command __command)
   self)
  (:command
   (&optional (__command :null))
   (if (not (eq __command :null)) (setq _command __command)) _command)
  (:serialization-length
   ()
   (+
    ;; bool _command
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _command
       (if _command (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _command
     (setq _command (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass mpu6050::ResetIMUResponse
  :super ros::object
  :slots (_result _message ))

(defmethod mpu6050::ResetIMUResponse
  (:init
   (&key
    ((:result __result) "")
    ((:message __message) "")
    )
   (send-super :init)
   (setq _result (string __result))
   (setq _message (string __message))
   self)
  (:result
   (&optional __result)
   (if __result (setq _result __result)) _result)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; string _result
    4 (length _result)
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _result
       (write-long (length _result) s) (princ _result s)
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _result
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _result (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass mpu6050::ResetIMU
  :super ros::object
  :slots ())

(setf (get mpu6050::ResetIMU :md5sum-) "093924429c8ce590aa2b41b10a45ad80")
(setf (get mpu6050::ResetIMU :datatype-) "mpu6050/ResetIMU")
(setf (get mpu6050::ResetIMU :request) mpu6050::ResetIMURequest)
(setf (get mpu6050::ResetIMU :response) mpu6050::ResetIMUResponse)

(defmethod mpu6050::ResetIMURequest
  (:response () (instance mpu6050::ResetIMUResponse :init)))

(setf (get mpu6050::ResetIMURequest :md5sum-) "093924429c8ce590aa2b41b10a45ad80")
(setf (get mpu6050::ResetIMURequest :datatype-) "mpu6050/ResetIMURequest")
(setf (get mpu6050::ResetIMURequest :definition-)
      "bool command
---
string result
string message

")

(setf (get mpu6050::ResetIMUResponse :md5sum-) "093924429c8ce590aa2b41b10a45ad80")
(setf (get mpu6050::ResetIMUResponse :datatype-) "mpu6050/ResetIMUResponse")
(setf (get mpu6050::ResetIMUResponse :definition-)
      "bool command
---
string result
string message

")



(provide :mpu6050/ResetIMU "093924429c8ce590aa2b41b10a45ad80")


