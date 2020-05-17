cmake_minimum_required(VERSION 3.14)
project(401_450)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem437.cpp
        problem449.cpp
        main.cpp)

add_executable(401_450 ${SRC})