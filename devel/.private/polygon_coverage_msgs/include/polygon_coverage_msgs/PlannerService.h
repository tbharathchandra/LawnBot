// Generated by gencpp from file polygon_coverage_msgs/PlannerService.msg
// DO NOT EDIT!


#ifndef POLYGON_COVERAGE_MSGS_MESSAGE_PLANNERSERVICE_H
#define POLYGON_COVERAGE_MSGS_MESSAGE_PLANNERSERVICE_H

#include <ros/service_traits.h>


#include <polygon_coverage_msgs/PlannerServiceRequest.h>
#include <polygon_coverage_msgs/PlannerServiceResponse.h>


namespace polygon_coverage_msgs
{

struct PlannerService
{

typedef PlannerServiceRequest Request;
typedef PlannerServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct PlannerService
} // namespace polygon_coverage_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::polygon_coverage_msgs::PlannerService > {
  static const char* value()
  {
    return "041d814b74649941198af640c3963ac3";
  }

  static const char* value(const ::polygon_coverage_msgs::PlannerService&) { return value(); }
};

template<>
struct DataType< ::polygon_coverage_msgs::PlannerService > {
  static const char* value()
  {
    return "polygon_coverage_msgs/PlannerService";
  }

  static const char* value(const ::polygon_coverage_msgs::PlannerService&) { return value(); }
};


// service_traits::MD5Sum< ::polygon_coverage_msgs::PlannerServiceRequest> should match
// service_traits::MD5Sum< ::polygon_coverage_msgs::PlannerService >
template<>
struct MD5Sum< ::polygon_coverage_msgs::PlannerServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::polygon_coverage_msgs::PlannerService >::value();
  }
  static const char* value(const ::polygon_coverage_msgs::PlannerServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::polygon_coverage_msgs::PlannerServiceRequest> should match
// service_traits::DataType< ::polygon_coverage_msgs::PlannerService >
template<>
struct DataType< ::polygon_coverage_msgs::PlannerServiceRequest>
{
  static const char* value()
  {
    return DataType< ::polygon_coverage_msgs::PlannerService >::value();
  }
  static const char* value(const ::polygon_coverage_msgs::PlannerServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::polygon_coverage_msgs::PlannerServiceResponse> should match
// service_traits::MD5Sum< ::polygon_coverage_msgs::PlannerService >
template<>
struct MD5Sum< ::polygon_coverage_msgs::PlannerServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::polygon_coverage_msgs::PlannerService >::value();
  }
  static const char* value(const ::polygon_coverage_msgs::PlannerServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::polygon_coverage_msgs::PlannerServiceResponse> should match
// service_traits::DataType< ::polygon_coverage_msgs::PlannerService >
template<>
struct DataType< ::polygon_coverage_msgs::PlannerServiceResponse>
{
  static const char* value()
  {
    return DataType< ::polygon_coverage_msgs::PlannerService >::value();
  }
  static const char* value(const ::polygon_coverage_msgs::PlannerServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // POLYGON_COVERAGE_MSGS_MESSAGE_PLANNERSERVICE_H