cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

project(ecm_from_shared_lib)

find_package(ignition-gazebo6 REQUIRED)
find_package(ignition-plugin1 REQUIRED COMPONENTS loader register)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME}
  ignition-gazebo6::core
  ignition-plugin1::loader
  )

add_library(test-plugin SHARED TestPlugin.cc)
target_link_libraries(test-plugin
  ignition-plugin1::register
  ignition-gazebo6::core
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
  "PLUGIN_LIB_PATH=\"$<TARGET_FILE:test-plugin>\"")

