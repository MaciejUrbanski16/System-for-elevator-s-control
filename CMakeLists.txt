cmake_minimum_required(VERSION 3.15)
project(elevators C)

set(CMAKE_C_STANDARD 99)

add_executable(elevators main.c elevator.c elevator.h status.c status.h)