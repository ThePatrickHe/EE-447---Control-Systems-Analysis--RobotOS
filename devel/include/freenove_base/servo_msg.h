// Generated by gencpp from file freenove_base/servo_msg.msg
// DO NOT EDIT!


#ifndef FREENOVE_BASE_MESSAGE_SERVO_MSG_H
#define FREENOVE_BASE_MESSAGE_SERVO_MSG_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace freenove_base
{
template <class ContainerAllocator>
struct servo_msg_
{
  typedef servo_msg_<ContainerAllocator> Type;

  servo_msg_()
    : horizontal(0)
    , vertical(0)  {
    }
  servo_msg_(const ContainerAllocator& _alloc)
    : horizontal(0)
    , vertical(0)  {
  (void)_alloc;
    }



   typedef int32_t _horizontal_type;
  _horizontal_type horizontal;

   typedef int32_t _vertical_type;
  _vertical_type vertical;





  typedef boost::shared_ptr< ::freenove_base::servo_msg_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::freenove_base::servo_msg_<ContainerAllocator> const> ConstPtr;

}; // struct servo_msg_

typedef ::freenove_base::servo_msg_<std::allocator<void> > servo_msg;

typedef boost::shared_ptr< ::freenove_base::servo_msg > servo_msgPtr;
typedef boost::shared_ptr< ::freenove_base::servo_msg const> servo_msgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::freenove_base::servo_msg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::freenove_base::servo_msg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::freenove_base::servo_msg_<ContainerAllocator1> & lhs, const ::freenove_base::servo_msg_<ContainerAllocator2> & rhs)
{
  return lhs.horizontal == rhs.horizontal &&
    lhs.vertical == rhs.vertical;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::freenove_base::servo_msg_<ContainerAllocator1> & lhs, const ::freenove_base::servo_msg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace freenove_base

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::freenove_base::servo_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::freenove_base::servo_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::freenove_base::servo_msg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::freenove_base::servo_msg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::freenove_base::servo_msg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::freenove_base::servo_msg_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::freenove_base::servo_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "811a705e34a03723eca077ed4732bcd1";
  }

  static const char* value(const ::freenove_base::servo_msg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x811a705e34a03723ULL;
  static const uint64_t static_value2 = 0xeca077ed4732bcd1ULL;
};

template<class ContainerAllocator>
struct DataType< ::freenove_base::servo_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "freenove_base/servo_msg";
  }

  static const char* value(const ::freenove_base::servo_msg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::freenove_base::servo_msg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 horizontal\n"
"int32 vertical\n"
;
  }

  static const char* value(const ::freenove_base::servo_msg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::freenove_base::servo_msg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.horizontal);
      stream.next(m.vertical);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct servo_msg_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::freenove_base::servo_msg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::freenove_base::servo_msg_<ContainerAllocator>& v)
  {
    s << indent << "horizontal: ";
    Printer<int32_t>::stream(s, indent + "  ", v.horizontal);
    s << indent << "vertical: ";
    Printer<int32_t>::stream(s, indent + "  ", v.vertical);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FREENOVE_BASE_MESSAGE_SERVO_MSG_H