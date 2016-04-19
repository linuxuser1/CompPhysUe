cmake_minimum_required(VERSION 2.6)
project(compchemue)

add_executable(compchemue main.cpp)

install(TARGETS compchemue RUNTIME DESTINATION bin)
