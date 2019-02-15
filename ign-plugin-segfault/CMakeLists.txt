cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(ign_plugin_segfault_test)

find_package(ignition-plugin1 REQUIRED COMPONENTS loader register)

add_executable(test1 test1.cc)
add_executable(test2 test2.cc)

set(CMAKE_CXX_STANDARD 17)

add_library(SingletonResource SHARED SingletonResource.cc)

target_link_libraries(test1
  ignition-plugin1::loader
  SingletonResource
  )

target_link_libraries(test2
  SingletonResource
  )

add_library(test-plugin SHARED TestPlugin.cc)
target_link_libraries(test-plugin
  ignition-plugin1::register
  SingletonResource
  )

target_compile_definitions(test1 PRIVATE
  "PLUGIN_LIB_PATH=\"$<TARGET_FILE:test-plugin>\"")
