
(cl:in-package :asdf)

(defsystem "gps-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Gps" :depends-on ("_package_Gps"))
    (:file "_package_Gps" :depends-on ("_package"))
  ))