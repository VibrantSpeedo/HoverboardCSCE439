
(cl:in-package :asdf)

(defsystem "rxtx-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "rxtxData" :depends-on ("_package_rxtxData"))
    (:file "_package_rxtxData" :depends-on ("_package"))
  ))