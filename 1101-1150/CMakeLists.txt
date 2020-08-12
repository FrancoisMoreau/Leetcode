cmake_minimum_required(VERSION 3.14)
project(1101_1150)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

set(SRC
        main.cpp
        problem1130.cpp)


add_executable(1101_1150 ${SRC})