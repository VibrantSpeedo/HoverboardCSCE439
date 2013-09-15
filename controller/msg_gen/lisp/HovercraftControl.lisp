; Auto-generated. Do not edit!


(cl:in-package controller-msg)


;//! \htmlinclude HovercraftControl.msg.html

(cl:defclass <HovercraftControl> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (power
    :reader power
    :initarg :power
    :type cl:fixnum
    :initform 0)
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
   (green_led
    :reader green_led
    :initarg :green_led
    :type cl:fixnum
    :initform 0)
   (red_led
    :reader red_led
    :initarg :red_led
    :type cl:fixnum
    :initform 0))
)

(cl:defclass HovercraftControl (<HovercraftControl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <HovercraftControl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'HovercraftControl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controller-msg:<HovercraftControl> is deprecated: use controller-msg:HovercraftControl instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <HovercraftControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:header-val is deprecated.  Use controller-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'power-val :lambda-list '(m))
(cl:defmethod power-val ((m <HovercraftControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:power-val is deprecated.  Use controller-msg:power instead.")
  (power m))

(cl:ensure-generic-function 'rotation-val :lambda-list '(m))
(cl:defmethod rotation-val ((m <HovercraftControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:rotation-val is deprecated.  Use controller-msg:rotation instead.")
  (rotation m))

(cl:ensure-generic-function 'x_translation-val :lambda-list '(m))
(cl:defmethod x_translation-val ((m <HovercraftControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:x_translation-val is deprecated.  Use controller-msg:x_translation instead.")
  (x_translation m))

(cl:ensure-generic-function 'y_translation-val :lambda-list '(m))
(cl:defmethod y_translation-val ((m <HovercraftControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:y_translation-val is deprecated.  Use controller-msg:y_translation instead.")
  (y_translation m))

(cl:ensure-generic-function 'green_led-val :lambda-list '(m))
(cl:defmethod green_led-val ((m <HovercraftControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:green_led-val is deprecated.  Use controller-msg:green_led instead.")
  (green_led m))

(cl:ensure-generic-function 'red_led-val :lambda-list '(m))
(cl:defmethod red_led-val ((m <HovercraftControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:red_led-val is deprecated.  Use controller-msg:red_led instead.")
  (red_led m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <HovercraftControl>) ostream)
  "Serializes a message object of type '<HovercraftControl>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'power)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
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
  (cl:let* ((signed (cl:slot-value msg 'green_led)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'red_led)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <HovercraftControl>) istream)
  "Deserializes a message object of type '<HovercraftControl>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'power) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
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
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'green_led) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'red_led) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<HovercraftControl>)))
  "Returns string type for a message object of type '<HovercraftControl>"
  "controller/HovercraftControl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'HovercraftControl)))
  "Returns string type for a message object of type 'HovercraftControl"
  "controller/HovercraftControl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<HovercraftControl>)))
  "Returns md5sum for a message object of type '<HovercraftControl>"
  "3e703ba01a482dfbf906246fb0b9dfdf")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'HovercraftControl)))
  "Returns md5sum for a message object of type 'HovercraftControl"
  "3e703ba01a482dfbf906246fb0b9dfdf")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<HovercraftControl>)))
  "Returns full string definition for message of type '<HovercraftControl>"
  (cl:format cl:nil "Header header~%~%int8 power~%float32 rotation~%float32 x_translation~%float32 y_translation~%int8 green_led~%int8 red_led~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'HovercraftControl)))
  "Returns full string definition for message of type 'HovercraftControl"
  (cl:format cl:nil "Header header~%~%int8 power~%float32 rotation~%float32 x_translation~%float32 y_translation~%int8 green_led~%int8 red_led~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <HovercraftControl>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4
     4
     4
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <HovercraftControl>))
  "Converts a ROS message object to a list"
  (cl:list 'HovercraftControl
    (cl:cons ':header (header msg))
    (cl:cons ':power (power msg))
    (cl:cons ':rotation (rotation msg))
    (cl:cons ':x_translation (x_translation msg))
    (cl:cons ':y_translation (y_translation msg))
    (cl:cons ':green_led (green_led msg))
    (cl:cons ':red_led (red_led msg))
))
