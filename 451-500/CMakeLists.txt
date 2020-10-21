cmake_minimum_required(VERSION 3.14)
project(451_500)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem452.cpp
        problem463.cpp
        problem468.cpp
        problem480.cpp
        problem490.cpp
        problem494.cpp
        problem498.cpp
        main.cpp)

add_executable(451_500 ${SRC})