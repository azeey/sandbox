cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

project(protobuf_in_plugins)

find_package(gz-plugin2 REQUIRED COMPONENTS loader register)

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME}
  gz-plugin2::loader
  )
find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
add_subdirectory(msg1)
add_subdirectory(msg2)

add_library(test-plugin1 SHARED TestPlugin.cc)
target_link_libraries(test-plugin1 PRIVATE
  gz-plugin2::register
  ${Protobuf_LIBRARIES}
  test-plugin-msgs1
)
add_library(test-plugin2 SHARED TestPlugin.cc)
target_link_libraries(test-plugin2 PRIVATE
  gz-plugin2::register
  ${Protobuf_LIBRARIES}
  test-plugin-msgs2
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
  "PLUGIN_LIB_PATH1=\"$<TARGET_FILE:test-plugin1>\""
  "PLUGIN_LIB_PATH2=\"$<TARGET_FILE:test-plugin2>\""
  )


