// Generated by gencpp from file go_to_poi/poi.msg
// DO NOT EDIT!


#ifndef GO_TO_POI_MESSAGE_POI_H
#define GO_TO_POI_MESSAGE_POI_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>

namespace go_to_poi
{
template <class ContainerAllocator>
struct poi_
{
  typedef poi_<ContainerAllocator> Type;

  poi_()
    : poi()  {
    }
  poi_(const ContainerAllocator& _alloc)
    : poi(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::geometry_msgs::Point_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::geometry_msgs::Point_<ContainerAllocator> >> _poi_type;
  _poi_type poi;





  typedef boost::shared_ptr< ::go_to_poi::poi_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::go_to_poi::poi_<ContainerAllocator> const> ConstPtr;

}; // struct poi_

typedef ::go_to_poi::poi_<std::allocator<void> > poi;

typedef boost::shared_ptr< ::go_to_poi::poi > poiPtr;
typedef boost::shared_ptr< ::go_to_poi::poi const> poiConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::go_to_poi::poi_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::go_to_poi::poi_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::go_to_poi::poi_<ContainerAllocator1> & lhs, const ::go_to_poi::poi_<ContainerAllocator2> & rhs)
{
  return lhs.poi == rhs.poi;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::go_to_poi::poi_<ContainerAllocator1> & lhs, const ::go_to_poi::poi_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace go_to_poi

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::go_to_poi::poi_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::go_to_poi::poi_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::go_to_poi::poi_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::go_to_poi::poi_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::go_to_poi::poi_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::go_to_poi::poi_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::go_to_poi::poi_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d4ec992df6b6add1e81dc8da9c38c0ab";
  }

  static const char* value(const ::go_to_poi::poi_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd4ec992df6b6add1ULL;
  static const uint64_t static_value2 = 0xe81dc8da9c38c0abULL;
};

template<class ContainerAllocator>
struct DataType< ::go_to_poi::poi_<ContainerAllocator> >
{
  static const char* value()
  {
    return "go_to_poi/poi";
  }

  static const char* value(const ::go_to_poi::poi_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::go_to_poi::poi_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Point[] poi\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::go_to_poi::poi_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::go_to_poi::poi_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.poi);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct poi_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::go_to_poi::poi_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::go_to_poi::poi_<ContainerAllocator>& v)
  {
    s << indent << "poi[]" << std::endl;
    for (size_t i = 0; i < v.poi.size(); ++i)
    {
      s << indent << "  poi[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "    ", v.poi[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // GO_TO_POI_MESSAGE_POI_H