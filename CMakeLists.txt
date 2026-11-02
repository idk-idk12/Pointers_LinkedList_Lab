cmake_minimum_required(VERSION 4.0)
project(First_List)

set(CMAKE_CXX_STANDARD 20)

add_executable(First_List main.cpp
        Book.cpp
        Book.h
        Inventory.cpp
        Inventory.h)
