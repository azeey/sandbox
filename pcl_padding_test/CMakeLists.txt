cmake_minimum_required(VERSION 3.8)
project(pointcloud_conversion)

# Find packages
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(PCL REQUIRED COMPONENTS common io)

# Include directories
include_directories(${PCL_INCLUDE_DIRS})

# Link directories
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

# Define executable
add_executable(pointcloud_conversion pointcloud_conversion.cpp)

# Link dependencies
ament_target_dependencies(pointcloud_conversion
  rclcpp
  sensor_msgs
  pcl_conversions
)

target_link_libraries(pointcloud_conversion
  ${PCL_LIBRARIES}
)

# Install target
install(TARGETS pointcloud_conversion
  DESTINATION lib/${PROJECT_NAME}
)

