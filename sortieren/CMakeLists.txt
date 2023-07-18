cmake_minimum_required(VERSION 3.24)
project(sortieren C)

set(CMAKE_C_STANDARD 23)

add_executable(sortieren main.c lib.h lib.c)
