cmake_minimum_required(VERSION 3.14)
project(951_1000)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem973.cpp
        problem987.cpp
        main.cpp)

add_executable(951_1000 ${SRC})