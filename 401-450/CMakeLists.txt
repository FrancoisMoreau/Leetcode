cmake_minimum_required(VERSION 3.14)
project(401_450)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        problem410.cpp
        problem415.cpp
        problem417.cpp
        problem419.cpp
        problem426.cpp
        problem437.cpp
        problem438.cpp
        problem442.cpp
        problem443.cpp
        problem445.cpp
        problem449.cpp
        main.cpp)

add_executable(401_450 ${SRC})