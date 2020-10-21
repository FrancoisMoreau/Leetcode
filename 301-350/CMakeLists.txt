cmake_minimum_required(VERSION 3.14)
project(301_350)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem301.cpp
        problem304.cpp
        problem309.cpp
        problem311.cpp
        problem314.cpp
        problem315.cpp
        problem316.cpp
        problem322.cpp
        problem329.cpp
        problem332.cpp
        problem336.cpp
        problem339.cpp
        problem340.cpp
        problem344.cpp
        problem347.cpp
        problem349.cpp
        problem350.cpp
        )

add_executable(301_350 ${SRC})