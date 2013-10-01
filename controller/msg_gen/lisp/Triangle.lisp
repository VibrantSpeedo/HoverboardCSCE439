; Auto-generated. Do not edit!


(cl:in-package controller-msg)


;//! \htmlinclude Triangle.msg.html

(cl:defclass <Triangle> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header)))
)

(cl:defclass Triangle (<Triangle>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Triangle>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Triangle)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name controller-msg:<Triangle> is deprecated: use controller-msg:Triangle instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Triangle>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader controller-msg:header-val is deprecated.  Use controller-msg:header instead.")
  (header m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Triangle>) ostream)
  "Serializes a message object of type '<Triangle>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Triangle>) istream)
  "Deserializes a message object of type '<Triangle>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Triangle>)))
  "Returns string type for a message object of type '<Triangle>"
  "controller/Triangle")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Triangle)))
  "Returns string type for a message object of type 'Triangle"
  "controller/Triangle")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Triangle>)))
  "Returns md5sum for a message object of type '<Triangle>"
  "d7be0bb39af8fb9129d5a76e6b63a290")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Triangle)))
  "Returns md5sum for a message object of type 'Triangle"
  "d7be0bb39af8fb9129d5a76e6b63a290")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Triangle>)))
  "Returns full string definition for message of type '<Triangle>"
  (cl:format cl:nil "Header header~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Triangle)))
  "Returns full string definition for message of type 'Triangle"
  (cl:format cl:nil "Header header~%~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Triangle>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Triangle>))
  "Converts a ROS message object to a list"
  (cl:list 'Triangle
    (cl:cons ':header (header msg))
))
