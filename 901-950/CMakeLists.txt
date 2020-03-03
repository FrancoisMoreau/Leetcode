cmake_minimum_required(VERSION 3.14)
project(901_950)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

set(SRC
        main.cpp
        problem937.cpp)

add_executable(901_950 ${SRC})