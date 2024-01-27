cmake_minimum_required(VERSION 3.26)
project(Project_5)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(startercode)

add_executable(Project_5
        startercode/catch.hpp
        startercode/priorityqueue.h
        startercode/tests.cpp
        catch.hpp
        priorityqueue.h
        tests.cpp)
