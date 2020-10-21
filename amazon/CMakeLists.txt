cmake_minimum_required(VERSION 3.14)
project(amazon)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_INCLUDE_CURRENT_DIR})

add_executable(amazon
        main.cpp
        cutoff_rank.cpp
        laboratory.cpp
        earliest_time.cpp
        LRUcache.cpp
        gateway.cpp
        rearrange_string.cpp
        stock_price.cpp
        slowest_key.cpp
        two_sum_pair.cpp
        consecutive_sum.cpp
        highest_profit.cpp
        substring_pattern.cpp
        getStrictIncreaseDecrease.cpp
        maximalSquare.cpp
        )