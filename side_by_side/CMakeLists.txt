cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project(side_by_side)

find_package(ignition-transport6 REQUIRED)
find_package(ignition-transport7 REQUIRED)

add_executable(test_transport test_transport.cc)

target_link_libraries(test_transport
  ignition-transport6::ignition-transport6
  ignition-transport7::ignition-transport7
  pthread
)

find_package(SDFormat 6 REQUIRED)
set(sdformat6 ${SDFormat_LIBRARIES})
unset(SDFormat_CONFIG_INCLUDED)

find_package(sdformat8 REQUIRED)
set(sdformat8 ${SDFormat_LIBRARIES})

add_executable(test_sdformat test_sdformat.cc)

target_link_libraries(test_sdformat
  ${sdformat6}
  ${sdformat8}
)
