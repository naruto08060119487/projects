cmake_minimum_required(VERSION 3.29)
project(clionProject)

set(CMAKE_CXX_STANDARD 20)

add_executable(clionProject main.cpp
        grade.cpp
        grade.h
        reg.cpp
        reg.h)
