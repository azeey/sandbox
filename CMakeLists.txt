cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(transport_segfault_test)

find_package(ignition-transport6 REQUIRED)
find_package(ignition-plugin1 REQUIRED COMPONENTS loader register)

add_executable(test1 test1.cc)
add_executable(test2 test2.cc)

#target_compile_features(test1 PUBLIC -std=c++17)
target_link_libraries(test1
  ignition-transport6::ignition-transport6
  ignition-plugin1::loader
  pthread
  )

#target_compile_features(test2 PUBLIC -std=c++17)
target_link_libraries(test2
  ignition-transport6::ignition-transport6
  pthread
  )

add_library(test-subscriber SHARED TestSubscriber.cc)
target_link_libraries(test-subscriber
  ignition-transport6::ignition-transport6
  ignition-plugin1::register
  pthread
  )

target_compile_definitions(test1 PRIVATE
  "SUBSCRIBER_LIB_PATH=\"$<TARGET_FILE:test-subscriber>\"")
