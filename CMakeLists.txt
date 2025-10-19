cmake_minimum_required(VERSION 4.0)
project(Task_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Task_1
        dynamic_array.h
        dynamic_array.hpp
        List.h
        List.hpp
        Stack.h
        "Task#1.cpp")
