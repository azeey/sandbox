cmake_minimum_required(VERSION 3.5.1)

project(testDartLargeTorque)

find_package(DART 6.6.0 REQUIRED)

file(GLOB srcs "*.cpp" "*.hpp")
add_executable(${PROJECT_NAME} ${srcs})
target_link_libraries(${PROJECT_NAME} PUBLIC dart)
