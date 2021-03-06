// Generated by gencpp from file vicon/GazeboState.msg
// DO NOT EDIT!


#ifndef VICON_MESSAGE_GAZEBOSTATE_H
#define VICON_MESSAGE_GAZEBOSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace vicon
{
template <class ContainerAllocator>
struct GazeboState_
{
  typedef GazeboState_<ContainerAllocator> Type;

  GazeboState_()
    : position()
    , quaternion()  {
      position.assign(0.0);

      quaternion.assign(0.0);
  }
  GazeboState_(const ContainerAllocator& _alloc)
    : position()
    , quaternion()  {
  (void)_alloc;
      position.assign(0.0);

      quaternion.assign(0.0);
  }



   typedef boost::array<double, 3>  _position_type;
  _position_type position;

   typedef boost::array<double, 4>  _quaternion_type;
  _quaternion_type quaternion;





  typedef boost::shared_ptr< ::vicon::GazeboState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vicon::GazeboState_<ContainerAllocator> const> ConstPtr;

}; // struct GazeboState_

typedef ::vicon::GazeboState_<std::allocator<void> > GazeboState;

typedef boost::shared_ptr< ::vicon::GazeboState > GazeboStatePtr;
typedef boost::shared_ptr< ::vicon::GazeboState const> GazeboStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vicon::GazeboState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vicon::GazeboState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vicon

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'vicon': ['/home/charlie/projects/position_controller/src/vicon/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vicon::GazeboState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vicon::GazeboState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon::GazeboState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon::GazeboState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon::GazeboState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon::GazeboState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vicon::GazeboState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "79dd5bb01ac0c08d4da2875a050d64ea";
  }

  static const char* value(const ::vicon::GazeboState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x79dd5bb01ac0c08dULL;
  static const uint64_t static_value2 = 0x4da2875a050d64eaULL;
};

template<class ContainerAllocator>
struct DataType< ::vicon::GazeboState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vicon/GazeboState";
  }

  static const char* value(const ::vicon::GazeboState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vicon::GazeboState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# GazeboState\n\
#\n\
# Rikky Duivenvoorden 2017-01-31 -- For use in AER1217 Winter 2017\n\
#\n\
# Data communicates the position in a three element array [x, y, z] and the \n\
# rotation in the form of a quaternion in a four element array [x, y, z, w].\n\
\n\
float64[3] position\n\
\n\
float64[4] quaternion\n\
";
  }

  static const char* value(const ::vicon::GazeboState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vicon::GazeboState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
      stream.next(m.quaternion);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GazeboState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vicon::GazeboState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vicon::GazeboState_<ContainerAllocator>& v)
  {
    s << indent << "position[]" << std::endl;
    for (size_t i = 0; i < v.position.size(); ++i)
    {
      s << indent << "  position[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.position[i]);
    }
    s << indent << "quaternion[]" << std::endl;
    for (size_t i = 0; i < v.quaternion.size(); ++i)
    {
      s << indent << "  quaternion[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.quaternion[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // VICON_MESSAGE_GAZEBOSTATE_H
