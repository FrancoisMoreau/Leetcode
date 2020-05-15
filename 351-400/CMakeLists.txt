cmake_minimum_required(VERSION 3.14)
project(351_400)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem378.cpp
        main.cpp)

add_executable(351_400 ${SRC})