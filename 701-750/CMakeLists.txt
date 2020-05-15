cmake_minimum_required(VERSION 3.14)
project(701_750)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem703.cpp
        main.cpp)

add_executable(701_750 ${SRC})