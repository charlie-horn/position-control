// Generated by gencpp from file simulator/ToggleCamResponse.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_TOGGLECAMRESPONSE_H
#define SIMULATOR_MESSAGE_TOGGLECAMRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace simulator
{
template <class ContainerAllocator>
struct ToggleCamResponse_
{
  typedef ToggleCamResponse_<ContainerAllocator> Type;

  ToggleCamResponse_()
    : Status()  {
    }
  ToggleCamResponse_(const ContainerAllocator& _alloc)
    : Status(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _Status_type;
  _Status_type Status;





  typedef boost::shared_ptr< ::simulator::ToggleCamResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::simulator::ToggleCamResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ToggleCamResponse_

typedef ::simulator::ToggleCamResponse_<std::allocator<void> > ToggleCamResponse;

typedef boost::shared_ptr< ::simulator::ToggleCamResponse > ToggleCamResponsePtr;
typedef boost::shared_ptr< ::simulator::ToggleCamResponse const> ToggleCamResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::simulator::ToggleCamResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::simulator::ToggleCamResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace simulator

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'simulator': ['/home/charlie/projects/position_controller/src/simulator/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::simulator::ToggleCamResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::simulator::ToggleCamResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::ToggleCamResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::simulator::ToggleCamResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::ToggleCamResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::simulator::ToggleCamResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::simulator::ToggleCamResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8fc5f5608d6072d9e82dd30f42a4228c";
  }

  static const char* value(const ::simulator::ToggleCamResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8fc5f5608d6072d9ULL;
  static const uint64_t static_value2 = 0xe82dd30f42a4228cULL;
};

template<class ContainerAllocator>
struct DataType< ::simulator::ToggleCamResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "simulator/ToggleCamResponse";
  }

  static const char* value(const ::simulator::ToggleCamResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::simulator::ToggleCamResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string Status\n\
\n\
";
  }

  static const char* value(const ::simulator::ToggleCamResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::simulator::ToggleCamResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.Status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ToggleCamResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::simulator::ToggleCamResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::simulator::ToggleCamResponse_<ContainerAllocator>& v)
  {
    s << indent << "Status: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.Status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SIMULATOR_MESSAGE_TOGGLECAMRESPONSE_H
