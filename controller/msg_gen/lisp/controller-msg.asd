
(cl:in-package :asdf)

(defsystem "controller-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "AngularPositionPID" :depends-on ("_package_AngularPositionPID"))
    (:file "_package_AngularPositionPID" :depends-on ("_package"))
    (:file "Arbitrator" :depends-on ("_package_Arbitrator"))
    (:file "_package_Arbitrator" :depends-on ("_package"))
    (:file "HovercraftControl" :depends-on ("_package_HovercraftControl"))
    (:file "_package_HovercraftControl" :depends-on ("_package"))
    (:file "JoyAngleIntegrator" :depends-on ("_package_JoyAngleIntegrator"))
    (:file "_package_JoyAngleIntegrator" :depends-on ("_package"))
    (:file "JoyStick" :depends-on ("_package_JoyStick"))
    (:file "_package_JoyStick" :depends-on ("_package"))
    (:file "Triangle" :depends-on ("_package_Triangle"))
    (:file "_package_Triangle" :depends-on ("_package"))
  ))