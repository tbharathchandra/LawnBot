;; Auto-generated. Do not edit!


(when (boundp 'polygon_coverage_msgs::PolygonWithHoles)
  (if (not (find-package "POLYGON_COVERAGE_MSGS"))
    (make-package "POLYGON_COVERAGE_MSGS"))
  (shadow 'PolygonWithHoles (find-package "POLYGON_COVERAGE_MSGS")))
(unless (find-package "POLYGON_COVERAGE_MSGS::POLYGONWITHHOLES")
  (make-package "POLYGON_COVERAGE_MSGS::POLYGONWITHHOLES"))

(in-package "ROS")
;;//! \htmlinclude PolygonWithHoles.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass polygon_coverage_msgs::PolygonWithHoles
  :super ros::object
  :slots (_hull _holes ))

(defmethod polygon_coverage_msgs::PolygonWithHoles
  (:init
   (&key
    ((:hull __hull) (instance geometry_msgs::Polygon :init))
    ((:holes __holes) ())
    )
   (send-super :init)
   (setq _hull __hull)
   (setq _holes __holes)
   self)
  (:hull
   (&rest __hull)
   (if (keywordp (car __hull))
       (send* _hull __hull)
     (progn
       (if __hull (setq _hull (car __hull)))
       _hull)))
  (:holes
   (&rest __holes)
   (if (keywordp (car __holes))
       (send* _holes __holes)
     (progn
       (if __holes (setq _holes (car __holes)))
       _holes)))
  (:serialization-length
   ()
   (+
    ;; geometry_msgs/Polygon _hull
    (send _hull :serialization-length)
    ;; geometry_msgs/Polygon[] _holes
    (apply #'+ (send-all _holes :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; geometry_msgs/Polygon _hull
       (send _hull :serialize s)
     ;; geometry_msgs/Polygon[] _holes
     (write-long (length _holes) s)
     (dolist (elem _holes)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; geometry_msgs/Polygon _hull
     (send _hull :deserialize buf ptr-) (incf ptr- (send _hull :serialization-length))
   ;; geometry_msgs/Polygon[] _holes
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _holes (let (r) (dotimes (i n) (push (instance geometry_msgs::Polygon :init) r)) r))
     (dolist (elem- _holes)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get polygon_coverage_msgs::PolygonWithHoles :md5sum-) "172a5c8423a33d0cd317c84e16aead83")
(setf (get polygon_coverage_msgs::PolygonWithHoles :datatype-) "polygon_coverage_msgs/PolygonWithHoles")
(setf (get polygon_coverage_msgs::PolygonWithHoles :definition-)
      "# A message to define a polygon with holes.
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
float32 z
")



(provide :polygon_coverage_msgs/PolygonWithHoles "172a5c8423a33d0cd317c84e16aead83")


