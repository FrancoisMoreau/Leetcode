cmake_minimum_required(VERSION 3.14)
project(51_100)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem55.cpp
        problem68.cpp
        problem76.cpp)

add_executable(51_100 ${SRC})