cmake_minimum_required(VERSION 3.15)
project(maze C)

set(CMAKE_C_STANDARD 99)

add_executable(maze
        main.c constants.h stack.h list.h stack.c list.c maze.h maze.c string_utils.h string_utils.c persistence.h
        persistence.c point.h point.c)