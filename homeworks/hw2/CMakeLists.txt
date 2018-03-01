cmake_minimum_required(VERSION 3.9)
project(hw2)

set(CMAKE_CXX_STANDARD 11)

add_executable(hw2-1
        hw2-problem1/functions.c
        hw2-problem1/functions.h
        hw2-problem1/hw2-problem1.c)

add_executable(hw2-2
        hw2-problem2/hw2-problem2.c)

add_executable(hw2-3
        hw2-problem3/functions.c
        hw2-problem3/functions.h
        hw2-problem3/hw2-problem3.c)

add_executable(hw2-4
        hw2-problem4/functions.c
        hw2-problem4/functions.h
        hw2-problem4/hw2-problem4.c)
