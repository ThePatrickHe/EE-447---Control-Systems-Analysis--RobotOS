// Generated by gencpp from file freenove_base/ultrasonic_srvRequest.msg
// DO NOT EDIT!


#ifndef FREENOVE_BASE_MESSAGE_ULTRASONIC_SRVREQUEST_H
#define FREENOVE_BASE_MESSAGE_ULTRASONIC_SRVREQUEST_H


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
struct ultrasonic_srvRequest_
{
  typedef ultrasonic_srvRequest_<ContainerAllocator> Type;

  ultrasonic_srvRequest_()
    : activate(false)  {
    }
  ultrasonic_srvRequest_(const ContainerAllocator& _alloc)
    : activate(false)  {
  (void)_alloc;
    }



   typedef uint8_t _activate_type;
  _activate_type activate;





  typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct ultrasonic_srvRequest_

typedef ::freenove_base::ultrasonic_srvRequest_<std::allocator<void> > ultrasonic_srvRequest;

typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvRequest > ultrasonic_srvRequestPtr;
typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvRequest const> ultrasonic_srvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator1> & lhs, const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.activate == rhs.activate;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator1> & lhs, const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace freenove_base

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b15627a984ebdd591b2ee87ce75c4d06";
  }

  static const char* value(const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb15627a984ebdd59ULL;
  static const uint64_t static_value2 = 0x1b2ee87ce75c4d06ULL;
};

template<class ContainerAllocator>
struct DataType< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "freenove_base/ultrasonic_srvRequest";
  }

  static const char* value(const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool activate\n"
;
  }

  static const char* value(const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.activate);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ultrasonic_srvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::freenove_base::ultrasonic_srvRequest_<ContainerAllocator>& v)
  {
    s << indent << "activate: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.activate);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FREENOVE_BASE_MESSAGE_ULTRASONIC_SRVREQUEST_H
