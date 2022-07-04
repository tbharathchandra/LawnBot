
(cl:in-package :asdf)

(defsystem "polygon_coverage_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :polygon_coverage_msgs-msg
               :trajectory_msgs-msg
)
  :components ((:file "_package")
    (:file "PlannerService" :depends-on ("_package_PlannerService"))
    (:file "_package_PlannerService" :depends-on ("_package"))
    (:file "PolygonService" :depends-on ("_package_PolygonService"))
    (:file "_package_PolygonService" :depends-on ("_package"))
  ))