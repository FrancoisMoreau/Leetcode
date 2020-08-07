cmake_minimum_required(VERSION 3.14)
project(351_400)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem352.cpp
        problem378.cpp
        problem380.cpp
        problem387.cpp
        problem394.cpp
        problem398.cpp
        main.cpp)

add_executable(351_400 ${SRC})