cmake_minimum_required(VERSION 3.14)
project(51_100)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

SET(SRC
        main.cpp
        problem54.cpp
        problem55.cpp
        problem56.cpp
        problem57.cpp
        problem62.cpp
        problem63.cpp
        problem65.cpp
        problem67.cpp
        problem68.cpp
        problem70.cpp
        problem71.cpp
        problem73.cpp
        problem74.cpp
        problem75.cpp
        problem76.cpp
        problem78.cpp
        problem79.cpp
        problem81.cpp
        problem88.cpp
        problem91.cpp
        problem92.cpp
        problem93.cpp
        problem95.cpp
        problem96.cpp
        problem98.cpp
        problem99.cpp)

add_executable(51_100 ${SRC})