cmake_minimum_required(VERSION 3.14)
project(951_1000)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem953.cpp
        problem958.cpp
        problem969.cpp
        problem973.cpp
        problem977.cpp
        problem986.cpp
        problem987.cpp
        problem1000.cpp
        main.cpp)

add_executable(951_1000 ${SRC})