cmake_minimum_required(VERSION 2.6)
project(compchemue)

add_executable(compchemue_00_01 00_01.cpp)

install(TARGETS compchemue_00_01 RUNTIME DESTINATION bin)
