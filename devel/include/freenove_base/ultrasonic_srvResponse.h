// Generated by gencpp from file freenove_base/ultrasonic_srvResponse.msg
// DO NOT EDIT!


#ifndef FREENOVE_BASE_MESSAGE_ULTRASONIC_SRVRESPONSE_H
#define FREENOVE_BASE_MESSAGE_ULTRASONIC_SRVRESPONSE_H


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
struct ultrasonic_srvResponse_
{
  typedef ultrasonic_srvResponse_<ContainerAllocator> Type;

  ultrasonic_srvResponse_()
    : distance(0)  {
    }
  ultrasonic_srvResponse_(const ContainerAllocator& _alloc)
    : distance(0)  {
  (void)_alloc;
    }



   typedef int32_t _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ultrasonic_srvResponse_

typedef ::freenove_base::ultrasonic_srvResponse_<std::allocator<void> > ultrasonic_srvResponse;

typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvResponse > ultrasonic_srvResponsePtr;
typedef boost::shared_ptr< ::freenove_base::ultrasonic_srvResponse const> ultrasonic_srvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator1> & lhs, const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.distance == rhs.distance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator1> & lhs, const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace freenove_base

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "680f8923bb6b23ec7057fffc11ea7b34";
  }

  static const char* value(const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x680f8923bb6b23ecULL;
  static const uint64_t static_value2 = 0x7057fffc11ea7b34ULL;
};

template<class ContainerAllocator>
struct DataType< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "freenove_base/ultrasonic_srvResponse";
  }

  static const char* value(const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32 distance\n"
;
  }

  static const char* value(const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ultrasonic_srvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::freenove_base::ultrasonic_srvResponse_<ContainerAllocator>& v)
  {
    s << indent << "distance: ";
    Printer<int32_t>::stream(s, indent + "  ", v.distance);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FREENOVE_BASE_MESSAGE_ULTRASONIC_SRVRESPONSE_H
