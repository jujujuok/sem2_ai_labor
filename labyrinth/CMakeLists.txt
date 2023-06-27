cmake_minimum_required(VERSION 3.24)
project(labyrinth C)

set(CMAKE_C_STANDARD 23)

add_executable(labyrinth main.c library.c terrain_maze.h terrain_maze.c)
