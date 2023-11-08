cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

project(sdf_custom_schema)

find_package(sdformat14 REQUIRED)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME}
  sdformat14::core
)
