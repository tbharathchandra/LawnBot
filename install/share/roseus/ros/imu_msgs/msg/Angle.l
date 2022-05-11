;; Auto-generated. Do not edit!


(when (boundp 'imu_msgs::Angle)
  (if (not (find-package "IMU_MSGS"))
    (make-package "IMU_MSGS"))
  (shadow 'Angle (find-package "IMU_MSGS")))
(unless (find-package "IMU_MSGS::ANGLE")
  (make-package "IMU_MSGS::ANGLE"))

(in-package "ROS")
;;//! \htmlinclude Angle.msg.html


(defclass imu_msgs::Angle
  :super ros::object
  :slots (_TimeStamp _roll _pitch _yaw ))

(defmethod imu_msgs::Angle
  (:init
   (&key
    ((:TimeStamp __TimeStamp) (instance ros::time :init))
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    ((:yaw __yaw) 0.0)
    )
   (send-super :init)
   (setq _TimeStamp __TimeStamp)
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   (setq _yaw (float __yaw))
   self)
  (:TimeStamp
   (&optional __TimeStamp)
   (if __TimeStamp (setq _TimeStamp __TimeStamp)) _TimeStamp)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:serialization-length
   ()
   (+
    ;; time _TimeStamp
    8
    ;; float64 _roll
    8
    ;; float64 _pitch
    8
    ;; float64 _yaw
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _TimeStamp
       (write-long (send _TimeStamp :sec) s) (write-long (send _TimeStamp :nsec) s)
     ;; float64 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _TimeStamp
     (send _TimeStamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _TimeStamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _roll
     (setq _roll (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pitch
     (setq _pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get imu_msgs::Angle :md5sum-) "663b245e480fb01f85d7fed608e522b5")
(setf (get imu_msgs::Angle :datatype-) "imu_msgs/Angle")
(setf (get imu_msgs::Angle :definition-)
      "time TimeStamp
float64 roll
float64 pitch
float64 yaw

")



(provide :imu_msgs/Angle "663b245e480fb01f85d7fed608e522b5")


