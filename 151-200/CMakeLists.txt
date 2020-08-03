cmake_minimum_required(VERSION 3.14)
project(151_200)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem151.cpp
        problem152.cpp
        problem153.cpp
        problem158.cpp
        problem160.cpp
        problem162.cpp
        problem164.cpp
        problem169.cpp
        problem173.cpp
        problem188.cpp
        problem189.cpp
        problem199.cpp
        problem200.cpp)

add_executable(151_200 ${SRC})