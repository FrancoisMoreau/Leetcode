cmake_minimum_required(VERSION 3.14)
project(601_650)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem609.cpp)

add_executable(601_650 ${SRC})