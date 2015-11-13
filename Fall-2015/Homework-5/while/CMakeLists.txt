cmake_minimum_required(VERSION 3.3)
project(while)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

add_executable(while-type-1 while-1.c)
add_executable(while-type-2 while-2.c)