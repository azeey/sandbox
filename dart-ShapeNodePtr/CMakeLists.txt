cmake_minimum_required(VERSION 3.5)

project(testShapeNodePtr)

find_package(DART 6.9.0 REQUIRED)

function(add_test target source)
  add_executable(${target} ${source})
  # target_compile_options(${target} PRIVATE -fsanitize=address -fno-omit-frame-pointer)
  # target_link_libraries(${target} PRIVATE  -fsanitize=address dart)
  target_link_libraries(${target} PRIVATE dart)
endfunction()

add_test(good good.cc)
add_test(test1 test1.cc)
add_test(test2 test2.cc)
