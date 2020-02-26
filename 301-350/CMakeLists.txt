cmake_minimum_required(VERSION 3.14)
project(301_350)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem309.cpp)

add_executable(301_350 ${SRC})