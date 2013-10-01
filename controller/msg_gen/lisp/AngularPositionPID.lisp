; Auto-generated. Do not edit!


(cl:in-package controller-msg)


;//! \htmlinclude AngularPositionPID.msg.html

(cl:defclass <AngularPositionPID> (roslisp-msg-protocol:ros-message)
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
   (thruster4
    :reader thruster4
    :initarg :thruster4
    :type cl:float
    :initform 0.0)
   (thruster5
    :reader thruster5
    :initarg :thruster5
    :type cl:float
    :initform 0.0))
)

(cl:defclass AngularPositionPID (<AngularPositionPID>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AngularPositionPID>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AngularPositionPID)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controller-msg:<AngularPositionPID> is deprecated: use controller-msg:AngularPositionPID instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <AngularPositionPID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:header-val is deprecated.  Use controller-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'power-val :lambda-list '(m))
(cl:defmethod power-val ((m <AngularPositionPID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:power-val is deprecated.  Use controller-msg:power instead.")
  (power m))

(cl:ensure-generic-function 'x_translation-val :lambda-list '(m))
(cl:defmethod x_translation-val ((m <AngularPositionPID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:x_translation-val is deprecated.  Use controller-msg:x_translation instead.")
  (x_translation m))

(cl:ensure-generic-function 'y_translation-val :lambda-list '(m))
(cl:defmethod y_translation-val ((m <AngularPositionPID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:y_translation-val is deprecated.  Use controller-msg:y_translation instead.")
  (y_translation m))

(cl:ensure-generic-function 'lift-val :lambda-list '(m))
(cl:defmethod lift-val ((m <AngularPositionPID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:lift-val is deprecated.  Use controller-msg:lift instead.")
  (lift m))

(cl:ensure-generic-function 'thruster4-val :lambda-list '(m))
(cl:defmethod thruster4-val ((m <AngularPositionPID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:thruster4-val is deprecated.  Use controller-msg:thruster4 instead.")
  (thruster4 m))

(cl:ensure-generic-function 'thruster5-val :lambda-list '(m))
(cl:defmethod thruster5-val ((m <AngularPositionPID>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:thruster5-val is deprecated.  Use controller-msg:thruster5 instead.")
  (thruster5 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AngularPositionPID>) ostream)
  "Serializes a message object of type '<AngularPositionPID>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'power) 1 0)) ostream)
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
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'thruster4))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'thruster5))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AngularPositionPID>) istream)
  "Deserializes a message object of type '<AngularPositionPID>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:slot-value msg 'power) (cl:not (cl:zerop (cl:read-byte istream))))
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
    (cl:setf (cl:slot-value msg 'thruster4) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'thruster5) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AngularPositionPID>)))
  "Returns string type for a message object of type '<AngularPositionPID>"
  "controller/AngularPositionPID")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AngularPositionPID)))
  "Returns string type for a message object of type 'AngularPositionPID"
  "controller/AngularPositionPID")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AngularPositionPID>)))
  "Returns md5sum for a message object of type '<AngularPositionPID>"
  "d0f1d2a1c6d53a1bb4c2f6ea9cec80f4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AngularPositionPID)))
  "Returns md5sum for a message object of type 'AngularPositionPID"
  "d0f1d2a1c6d53a1bb4c2f6ea9cec80f4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AngularPositionPID>)))
  "Returns full string definition for message of type '<AngularPositionPID>"
  (cl:format cl:nil "Header header~%~%bool power~%float32 x_translation~%float32 y_translation~%float32 lift~%float32 thruster4~%float32 thruster5~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AngularPositionPID)))
  "Returns full string definition for message of type 'AngularPositionPID"
  (cl:format cl:nil "Header header~%~%bool power~%float32 x_translation~%float32 y_translation~%float32 lift~%float32 thruster4~%float32 thruster5~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AngularPositionPID>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AngularPositionPID>))
  "Converts a ROS message object to a list"
  (cl:list 'AngularPositionPID
    (cl:cons ':header (header msg))
    (cl:cons ':power (power msg))
    (cl:cons ':x_translation (x_translation msg))
    (cl:cons ':y_translation (y_translation msg))
    (cl:cons ':lift (lift msg))
    (cl:cons ':thruster4 (thruster4 msg))
    (cl:cons ':thruster5 (thruster5 msg))
))
