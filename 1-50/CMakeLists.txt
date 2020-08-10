cmake_minimum_required(VERSION 3.14)
project(1_50)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem3.cpp
        problem5.cpp
        problem17.cpp
        problem20.cpp
        problem23.cpp
        problem22.cpp
        problem29.cpp
        problem31.cpp
        problem33.cpp
        problem34.cpp
        problem49.cpp
        problem50.cpp)

add_executable(1_50 ${SRC})