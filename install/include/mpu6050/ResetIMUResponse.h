// Generated by gencpp from file mpu6050/ResetIMUResponse.msg
// DO NOT EDIT!


#ifndef MPU6050_MESSAGE_RESETIMURESPONSE_H
#define MPU6050_MESSAGE_RESETIMURESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mpu6050
{
template <class ContainerAllocator>
struct ResetIMUResponse_
{
  typedef ResetIMUResponse_<ContainerAllocator> Type;

  ResetIMUResponse_()
    : result()
    , message()  {
    }
  ResetIMUResponse_(const ContainerAllocator& _alloc)
    : result(_alloc)
    , message(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _result_type;
  _result_type result;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _message_type;
  _message_type message;





  typedef boost::shared_ptr< ::mpu6050::ResetIMUResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mpu6050::ResetIMUResponse_<ContainerAllocator> const> ConstPtr;

}; // struct ResetIMUResponse_

typedef ::mpu6050::ResetIMUResponse_<std::allocator<void> > ResetIMUResponse;

typedef boost::shared_ptr< ::mpu6050::ResetIMUResponse > ResetIMUResponsePtr;
typedef boost::shared_ptr< ::mpu6050::ResetIMUResponse const> ResetIMUResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mpu6050::ResetIMUResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mpu6050::ResetIMUResponse_<ContainerAllocator1> & lhs, const ::mpu6050::ResetIMUResponse_<ContainerAllocator2> & rhs)
{
  return lhs.result == rhs.result &&
    lhs.message == rhs.message;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mpu6050::ResetIMUResponse_<ContainerAllocator1> & lhs, const ::mpu6050::ResetIMUResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mpu6050

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mpu6050::ResetIMUResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mpu6050::ResetIMUResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu6050::ResetIMUResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b32ef3c4a478327333bfd0b603b07edb";
  }

  static const char* value(const ::mpu6050::ResetIMUResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb32ef3c4a4783273ULL;
  static const uint64_t static_value2 = 0x33bfd0b603b07edbULL;
};

template<class ContainerAllocator>
struct DataType< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mpu6050/ResetIMUResponse";
  }

  static const char* value(const ::mpu6050::ResetIMUResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string result\n"
"string message\n"
"\n"
;
  }

  static const char* value(const ::mpu6050::ResetIMUResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
      stream.next(m.message);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ResetIMUResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mpu6050::ResetIMUResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mpu6050::ResetIMUResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.result);
    s << indent << "message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.message);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MPU6050_MESSAGE_RESETIMURESPONSE_H
