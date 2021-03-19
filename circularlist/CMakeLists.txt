cmake_minimum_required(VERSION 3.14)
project(CircularList C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(CircularList
        lista.c
        lista.h
        main.c)
