cmake_minimum_required(VERSION 3.8)
project(test_ament_pkg)

find_package(ament_cmake REQUIRED)

# Uncommenting the following line will fix the issue, but it shouldn't be necessary to have a dummy .sh file
# ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/hooks/test_hook.sh")
ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/hooks/test_hook.dsv")
ament_package()
