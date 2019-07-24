cmake_minimum_required(VERSION 2.8.3)
project(ros_high_cpu)
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/ros_high_cpu_node.cpp)
target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})
