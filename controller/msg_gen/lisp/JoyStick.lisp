; Auto-generated. Do not edit!


(cl:in-package controller-msg)


;//! \htmlinclude JoyStick.msg.html

(cl:defclass <JoyStick> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (power
    :reader power
    :initarg :power
    :type cl:boolean
    :initform cl:nil)
   (rotation
    :reader rotation
    :initarg :rotation
    :type cl:float
    :initform 0.0)
   (x_translation
    :reader x_translation
    :initarg :x_translation
    :type cl:float
    :initform 0.0)
   (y_translation
    :reader y_translation
    :initarg :y_translation
    :type cl:float
    :initform 0.0)
   (lift
    :reader lift
    :initarg :lift
    :type cl:float
    :initform 0.0)
   (angle
    :reader angle
    :initarg :angle
    :type cl:float
    :initform 0.0)
   (add90
    :reader add90
    :initarg :add90
    :type cl:boolean
    :initform cl:nil)
   (subtract90
    :reader subtract90
    :initarg :subtract90
    :type cl:boolean
    :initform cl:nil)
   (joystickControl
    :reader joystickControl
    :initarg :joystickControl
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass JoyStick (<JoyStick>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <JoyStick>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'JoyStick)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controller-msg:<JoyStick> is deprecated: use controller-msg:JoyStick instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:header-val is deprecated.  Use controller-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'power-val :lambda-list '(m))
(cl:defmethod power-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:power-val is deprecated.  Use controller-msg:power instead.")
  (power m))

(cl:ensure-generic-function 'rotation-val :lambda-list '(m))
(cl:defmethod rotation-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:rotation-val is deprecated.  Use controller-msg:rotation instead.")
  (rotation m))

(cl:ensure-generic-function 'x_translation-val :lambda-list '(m))
(cl:defmethod x_translation-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:x_translation-val is deprecated.  Use controller-msg:x_translation instead.")
  (x_translation m))

(cl:ensure-generic-function 'y_translation-val :lambda-list '(m))
(cl:defmethod y_translation-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:y_translation-val is deprecated.  Use controller-msg:y_translation instead.")
  (y_translation m))

(cl:ensure-generic-function 'lift-val :lambda-list '(m))
(cl:defmethod lift-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:lift-val is deprecated.  Use controller-msg:lift instead.")
  (lift m))

(cl:ensure-generic-function 'angle-val :lambda-list '(m))
(cl:defmethod angle-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:angle-val is deprecated.  Use controller-msg:angle instead.")
  (angle m))

(cl:ensure-generic-function 'add90-val :lambda-list '(m))
(cl:defmethod add90-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:add90-val is deprecated.  Use controller-msg:add90 instead.")
  (add90 m))

(cl:ensure-generic-function 'subtract90-val :lambda-list '(m))
(cl:defmethod subtract90-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:subtract90-val is deprecated.  Use controller-msg:subtract90 instead.")
  (subtract90 m))

(cl:ensure-generic-function 'joystickControl-val :lambda-list '(m))
(cl:defmethod joystickControl-val ((m <JoyStick>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:joystickControl-val is deprecated.  Use controller-msg:joystickControl instead.")
  (joystickControl m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <JoyStick>) ostream)
  "Serializes a message object of type '<JoyStick>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'power) 1 0)) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'rotation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'x_translation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'y_translation))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'lift))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'angle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'add90) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'subtract90) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'joystickControl) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <JoyStick>) istream)
  "Deserializes a message object of type '<JoyStick>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:slot-value msg 'power) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'rotation) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x_translation) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y_translation) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'lift) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'angle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'add90) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'subtract90) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'joystickControl) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<JoyStick>)))
  "Returns string type for a message object of type '<JoyStick>"
  "controller/JoyStick")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'JoyStick)))
  "Returns string type for a message object of type 'JoyStick"
  "controller/JoyStick")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<JoyStick>)))
  "Returns md5sum for a message object of type '<JoyStick>"
  "966c67514a77c19671b218791981fb9c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'JoyStick)))
  "Returns md5sum for a message object of type 'JoyStick"
  "966c67514a77c19671b218791981fb9c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<JoyStick>)))
  "Returns full string definition for message of type '<JoyStick>"
  (cl:format cl:nil "Header header~%~%bool power~%float32 rotation~%float32 x_translation~%float32 y_translation~%float32 lift~%float32 angle~%bool add90~%bool subtract90~%bool joystickControl~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'JoyStick)))
  "Returns full string definition for message of type 'JoyStick"
  (cl:format cl:nil "Header header~%~%bool power~%float32 rotation~%float32 x_translation~%float32 y_translation~%float32 lift~%float32 angle~%bool add90~%bool subtract90~%bool joystickControl~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <JoyStick>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4
     4
     4
     4
     4
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <JoyStick>))
  "Converts a ROS message object to a list"
  (cl:list 'JoyStick
    (cl:cons ':header (header msg))
    (cl:cons ':power (power msg))
    (cl:cons ':rotation (rotation msg))
    (cl:cons ':x_translation (x_translation msg))
    (cl:cons ':y_translation (y_translation msg))
    (cl:cons ':lift (lift msg))
    (cl:cons ':angle (angle msg))
    (cl:cons ':add90 (add90 msg))
    (cl:cons ':subtract90 (subtract90 msg))
    (cl:cons ':joystickControl (joystickControl msg))
))
