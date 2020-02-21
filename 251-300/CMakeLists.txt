cmake_minimum_required(VERSION 3.14)
project(251_300)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem274.cpp
        problem275.cpp)

add_executable(251_300 ${SRC})