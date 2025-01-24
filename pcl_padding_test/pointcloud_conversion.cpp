// Originally written by @ntfshard (see https://github.com/gazebosim/gz-sensors/pull/493)
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "std_msgs/msg/header.hpp"
#include <cstdint>
#include <iostream>
#include <pcl/PCLPointCloud2.h>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/point_cloud2_iterator.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>

struct GzPoint {
    uint32_t x;
    uint32_t y;
    uint8_t intensity;
    uint32_t z;
};

POINT_CLOUD_REGISTER_POINT_STRUCT(GzPoint,
    (uint32_t, x, x)
    (uint32_t, y, y)
    (uint8_t, intensity, intensity)
    (uint32_t, z, z)
)

sensor_msgs::msg::PointCloud2 createFromPCL(int count, int init_offset = 0) {
  pcl::PointCloud<GzPoint> myPointCloud;
  for (size_t i = 0; i < count; ++i) {
    GzPoint myPoint;
    myPoint.x = static_cast<uint32_t>(i + init_offset);
    myPoint.y = static_cast<uint32_t>(i + init_offset * 2);
    myPoint.z = static_cast<uint32_t>(i + init_offset * 3 );
    myPoint.intensity = static_cast<uint8_t>(i + init_offset * 4) ;
    myPointCloud.push_back(myPoint);
  }

  std::cout << myPointCloud << std::endl;

  sensor_msgs::msg::PointCloud2 ros_cloud;
  pcl::toROSMsg(myPointCloud, ros_cloud);
  //
  return ros_cloud;
}

sensor_msgs::msg::PointCloud2 createFromMsg(int count, int init_offset = 0) {
  sensor_msgs::msg::PointCloud2 ros_cloud;

  ros_cloud.width = count;  // Number of points
  ros_cloud.height = 1; // Unorganized point cloud
  ros_cloud.is_dense = true;

  // Define fields (x, y, z, and intense)
  int offset = 0;
  offset = addPointField(ros_cloud, "x", 1,
                         sensor_msgs::msg::PointField::UINT32, offset);
  offset = addPointField(ros_cloud, "y", 1,
                         sensor_msgs::msg::PointField::UINT32, offset);
  offset = addPointField(ros_cloud, "intensity", 1,
                         sensor_msgs::msg::PointField::UINT8, offset);
  offset = addPointField(ros_cloud, "z", 1,
                         sensor_msgs::msg::PointField::UINT32, offset);

  ros_cloud.point_step = offset;
  ros_cloud.row_step = ros_cloud.width * ros_cloud.point_step;
  ros_cloud.data.resize(ros_cloud.height * ros_cloud.row_step);

  // Populate data
  sensor_msgs::PointCloud2Iterator<uint32_t> iter_x(ros_cloud, "x");
  sensor_msgs::PointCloud2Iterator<uint32_t> iter_y(ros_cloud, "y");
  sensor_msgs::PointCloud2Iterator<uint32_t> iter_z(ros_cloud, "z");
  sensor_msgs::PointCloud2Iterator<uint8_t> iter_intensity(ros_cloud,
                                                           "intensity");

  for (size_t i = 0; i < ros_cloud.width;
       ++i, ++iter_x, ++iter_y, ++iter_z, ++iter_intensity) {
    *iter_x = static_cast<uint32_t>(i + init_offset);
    *iter_y = static_cast<uint32_t>(i + init_offset * 2);
    *iter_z = static_cast<uint32_t>(i + init_offset * 3 );
    *iter_intensity = static_cast<uint8_t>(i + init_offset * 4) ;
  }

  return ros_cloud;
}

void verify(const sensor_msgs::msg::PointCloud2& ros_cloud){

  std::cout << "Message Debug:" << sensor_msgs::msg::to_yaml(ros_cloud, true) << std::endl;
  std::cout << "Data size:" << ros_cloud.data.size() << std::endl;
  rclcpp::Serialization<sensor_msgs::msg::PointCloud2> pclSerializer;
  rclcpp::SerializedMessage serialized_msg;
  pclSerializer.serialize_message(&ros_cloud, &serialized_msg);
  std::cout << "Serialized Message size:" << serialized_msg.size() << std::endl;
  std::cout << "Point step:" << ros_cloud.point_step << std::endl;

  {
    pcl::PointCloud<GzPoint> pcl_cloud;
    pcl::fromROSMsg(ros_cloud, pcl_cloud);
    // Verify the conversion
    std::cout << "Converted PCL Point Cloud:" << std::endl;
    for (const auto &point : pcl_cloud.points) {
      std::cout << "x: " << point.x << ", y: " << point.y << ", z: " << point.z
        << ", intensity: " << static_cast<unsigned int>(point.intensity)
        << std::endl;
    }
  }


  {
    // This conversion is used in older versions of PCL
    pcl::PointCloud<GzPoint> pcl_cloud;
    pcl::PCLPointCloud2 pcl_pc2;
    pcl_conversions::toPCL(ros_cloud, pcl_pc2);
    pcl::fromPCLPointCloud2(pcl_pc2, pcl_cloud);
    // Verify the conversion
    std::cout << "Converted PCL Point Cloud2:" << std::endl;
    for (const auto &point : pcl_cloud.points) {
      std::cout << "x: " << point.x << ", y: " << point.y << ", z: " << point.z
        << ", intensity: " << static_cast<unsigned int>(point.intensity)
        << std::endl;
    }
  }

  std::cout << "\n\n";
}

int main(int argc, char **argv) {


  verify(createFromPCL(2, 10));
  verify(createFromMsg(2, 10));

  return 0;
}
