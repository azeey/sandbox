cmake_minimum_required(VERSION 3.5.1)

project(testDartWarpSpeed)

find_package(DART 6.9.0 REQUIRED COMPONENTS collision-ode collision-bullet utils-urdf gui-osg)

add_executable(${PROJECT_NAME} Main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC dart dart-collision-ode dart-collision-bullet dart-utils-urdf dart-gui-osg)
target_compile_definitions(${PROJECT_NAME} PRIVATE "TEST_SKEL_FILE=\"${CMAKE_CURRENT_SOURCE_DIR}/rolling_sphere.skel\"")
