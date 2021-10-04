cmake_minimum_required(VERSION 2.8)
project(oop-hardware-platform-simulator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(simulator src/main.cpp)
