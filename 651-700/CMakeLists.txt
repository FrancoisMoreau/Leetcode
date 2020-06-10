cmake_minimum_required(VERSION 3.14)
project(651_700)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem662.cpp
        problem692.cpp
        main.cpp)

add_executable(651_700 ${SRC})