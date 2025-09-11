cmake_minimum_required(VERSION 3.22.0 FATAL_ERROR)

project(sdf_memory)

find_package(gz-cmake REQUIRED)
find_package(sdformat REQUIRED)
find_package(tinyxml2 REQUIRED)
# find_package(mimalloc REQUIRED)

include(GzPkgConfig)
gz_pkg_check_modules(gperftools libprofiler)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE
  sdformat::core
  TINYXML2::TINYXML2
  # mimalloc
  gperftools::gperftools
)
