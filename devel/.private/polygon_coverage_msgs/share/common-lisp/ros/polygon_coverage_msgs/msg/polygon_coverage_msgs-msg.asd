
(cl:in-package :asdf)

(defsystem "polygon_coverage_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "PolygonWithHoles" :depends-on ("_package_PolygonWithHoles"))
    (:file "_package_PolygonWithHoles" :depends-on ("_package"))
    (:file "PolygonWithHolesStamped" :depends-on ("_package_PolygonWithHolesStamped"))
    (:file "_package_PolygonWithHolesStamped" :depends-on ("_package"))
  ))