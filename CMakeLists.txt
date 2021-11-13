cmake_minimum_required(VERSION 2.8.12)
project(oop-hardware-platform-simulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_executable(simulator
               src/args.cpp
               src/bus.cpp
               src/busdefinition.cpp
               src/cpu.cpp
               src/cpudefinition.cpp
               src/datavalue.cpp
               src/definition.cpp
               src/display.cpp
               src/displaydefinition.cpp
               src/instruction.cpp
               src/main.cpp
               src/memory.cpp
               src/memorydefinition.cpp
               src/platform.cpp
               src/program.cpp
               src/register.cpp
               )
