cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
project(project2)

set(CMAKE_FIND_DEBUG_MODE TRUE)
find_program(tool_var NAME "my_project1_tool" REQUIRED)

