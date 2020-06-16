cmake_minimum_required(VERSION 3.14)
project(101_150)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem101.cpp
        problem102.cpp
        problem103.cpp
        problem105.cpp
        problem114.cpp
        problem116.cpp
        problem118.cpp
        problem119.cpp
        problem121.cpp
        problem122.cpp
        problem123.cpp
        problem124.cpp
        problem126.cpp
        problem127.cpp
        problem128.cpp
        problem129.cpp
        problem133.cpp
        problem134.cpp
        problem138.cpp
        problem139.cpp
        problem140.cpp
        problem143.cpp
        problem146.cpp
        problem148.cpp)

add_executable(101_150 ${SRC})