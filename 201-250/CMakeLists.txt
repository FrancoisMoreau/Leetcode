cmake_minimum_required(VERSION 3.14)
project(201_250)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem217.cpp
        problem219.cpp
        problem220.cpp
        problem229.cpp
        problem243.cpp
        problem244.cpp
        problem245.cpp)

add_executable(201_250 ${SRC})