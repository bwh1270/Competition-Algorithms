
(cl:in-package :asdf)

(defsystem "go_to_poi-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "poi" :depends-on ("_package_poi"))
    (:file "_package_poi" :depends-on ("_package"))
  ))