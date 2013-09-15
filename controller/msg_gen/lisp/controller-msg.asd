
(cl:in-package :asdf)

(defsystem "controller-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "HovercraftControl" :depends-on ("_package_HovercraftControl"))
    (:file "_package_HovercraftControl" :depends-on ("_package"))
  ))