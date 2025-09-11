cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

project(sdf_memory)

find_package(sdformat REQUIRED)
find_package(tinyxml2 REQUIRED)
find_package(mimalloc REQUIRED)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE
  sdformat::core
  TINYXML2::TINYXML2
  mimalloc
)
