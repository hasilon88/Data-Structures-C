cmake_minimum_required(VERSION 3.27)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructures
        ArrayList/ArrayList.c
        ArrayList/ArrayList.h
        Tests/ArrayListTests.c)
