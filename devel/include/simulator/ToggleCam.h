// Generated by gencpp from file simulator/ToggleCam.msg
// DO NOT EDIT!


#ifndef SIMULATOR_MESSAGE_TOGGLECAM_H
#define SIMULATOR_MESSAGE_TOGGLECAM_H

#include <ros/service_traits.h>


#include <simulator/ToggleCamRequest.h>
#include <simulator/ToggleCamResponse.h>


namespace simulator
{

struct ToggleCam
{

typedef ToggleCamRequest Request;
typedef ToggleCamResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct ToggleCam
} // namespace simulator


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::simulator::ToggleCam > {
  static const char* value()
  {
    return "8fc5f5608d6072d9e82dd30f42a4228c";
  }

  static const char* value(const ::simulator::ToggleCam&) { return value(); }
};

template<>
struct DataType< ::simulator::ToggleCam > {
  static const char* value()
  {
    return "simulator/ToggleCam";
  }

  static const char* value(const ::simulator::ToggleCam&) { return value(); }
};


// service_traits::MD5Sum< ::simulator::ToggleCamRequest> should match 
// service_traits::MD5Sum< ::simulator::ToggleCam > 
template<>
struct MD5Sum< ::simulator::ToggleCamRequest>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::ToggleCam >::value();
  }
  static const char* value(const ::simulator::ToggleCamRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::ToggleCamRequest> should match 
// service_traits::DataType< ::simulator::ToggleCam > 
template<>
struct DataType< ::simulator::ToggleCamRequest>
{
  static const char* value()
  {
    return DataType< ::simulator::ToggleCam >::value();
  }
  static const char* value(const ::simulator::ToggleCamRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::simulator::ToggleCamResponse> should match 
// service_traits::MD5Sum< ::simulator::ToggleCam > 
template<>
struct MD5Sum< ::simulator::ToggleCamResponse>
{
  static const char* value()
  {
    return MD5Sum< ::simulator::ToggleCam >::value();
  }
  static const char* value(const ::simulator::ToggleCamResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::simulator::ToggleCamResponse> should match 
// service_traits::DataType< ::simulator::ToggleCam > 
template<>
struct DataType< ::simulator::ToggleCamResponse>
{
  static const char* value()
  {
    return DataType< ::simulator::ToggleCam >::value();
  }
  static const char* value(const ::simulator::ToggleCamResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SIMULATOR_MESSAGE_TOGGLECAM_H
