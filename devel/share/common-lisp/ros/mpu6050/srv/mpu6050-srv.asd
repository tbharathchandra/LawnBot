
(cl:in-package :asdf)

(defsystem "mpu6050-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ResetIMU" :depends-on ("_package_ResetIMU"))
    (:file "_package_ResetIMU" :depends-on ("_package"))
  ))