cmake_minimum_required(VERSION 3.14)
project(501_550)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem515.cpp
        problem523.cpp
        problem528.cpp
        problem539.cpp
        problem540.cpp
        problem543.cpp)

add_executable(501_550 ${SRC})