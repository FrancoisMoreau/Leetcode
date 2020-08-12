cmake_minimum_required(VERSION 3.14)
project(1201_1250)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem1249.cpp
        main.cpp)

add_executable(1201_1250 ${SRC})