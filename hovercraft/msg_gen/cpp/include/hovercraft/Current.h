/* Auto-generated by genmsg_cpp for file /mnt/hgfs/groovy_workspace/sandbox/HoverboardCSCE439/hovercraft/msg/Current.msg */
#ifndef HOVERCRAFT_MESSAGE_CURRENT_H
#define HOVERCRAFT_MESSAGE_CURRENT_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"

namespace hovercraft
{
template <class ContainerAllocator>
struct Current_ {
  typedef Current_<ContainerAllocator> Type;

  Current_()
  : header()
  , current(0.0)
  {
  }

  Current_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , current(0.0)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef double _current_type;
  double current;


  typedef boost::shared_ptr< ::hovercraft::Current_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hovercraft::Current_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Current
typedef  ::hovercraft::Current_<std::allocator<void> > Current;

typedef boost::shared_ptr< ::hovercraft::Current> CurrentPtr;
typedef boost::shared_ptr< ::hovercraft::Current const> CurrentConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::hovercraft::Current_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::hovercraft::Current_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace hovercraft

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::hovercraft::Current_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::hovercraft::Current_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::hovercraft::Current_<ContainerAllocator> > {
  static const char* value() 
  {
    return "0f12dc28919a92ca29c78429b7b11164";
  }

  static const char* value(const  ::hovercraft::Current_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x0f12dc28919a92caULL;
  static const uint64_t static_value2 = 0x29c78429b7b11164ULL;
};

template<class ContainerAllocator>
struct DataType< ::hovercraft::Current_<ContainerAllocator> > {
  static const char* value() 
  {
    return "hovercraft/Current";
  }

  static const char* value(const  ::hovercraft::Current_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::hovercraft::Current_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
\n\
#The current in Amps\n\
float64 current \n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
";
  }

  static const char* value(const  ::hovercraft::Current_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::hovercraft::Current_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::hovercraft::Current_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::hovercraft::Current_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.current);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Current_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hovercraft::Current_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::hovercraft::Current_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "current: ";
    Printer<double>::stream(s, indent + "  ", v.current);
  }
};


} // namespace message_operations
} // namespace ros

#endif // HOVERCRAFT_MESSAGE_CURRENT_H

