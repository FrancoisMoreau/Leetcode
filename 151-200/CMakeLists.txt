cmake_minimum_required(VERSION 3.14)
project(151_200)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem169.cpp)

add_executable(151_200 ${SRC})