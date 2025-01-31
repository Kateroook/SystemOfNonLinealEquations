cmake_minimum_required(VERSION 3.29)
project(SystemOfNonLinealEquations)

set(CMAKE_CXX_STANDARD 20)

add_executable(SystemOfNonLinealEquations main.cpp
        Functions.cpp
        Functions.h
        relaxation.cpp
        newtonModified.cpp)
