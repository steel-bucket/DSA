cmake_minimum_required(VERSION 3.28)
project(salary)

set(CMAKE_CXX_STANDARD 17)

add_executable(salary main.cpp
        buffer.txt
        doneones.cpp
        doneones.h
        betterimplementations.cpp
        betterimplementations.h)
