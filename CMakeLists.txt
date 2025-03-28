#[[
    @file CMakeLists.txt
    @brief Configuration file for building the cpp-oop-review project with CMake.
    @author IoT Solution Development Staff
    @date 2025-03-27
    @version 1.0
    @license MIT

    This file configures the build for cpp-oop-review, a C++ console application designed to
    illustrate Object-Oriented Programming (OOP) concepts using a process simulation. It models
    a compilation pipeline with Processes and Tasks utilizing Consumable (Memory) and Usable (CPU)
    resources, showcasing encapsulation, inheritance, polymorphism, and abstraction. Classes are
    organized in separate files under include/ and src/ directories. Built with C++17 features.
]]
# Minimum required CMake version for compatibility
cmake_minimum_required(VERSION 3.30)

# Project name
project(cpp_oop_review)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_EXTENSIONS ON)

# Include the directories containing the header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
        src/Resource.cpp
        src/ConsumableResource.cpp
        src/UsableResource.cpp
        src/Executable.cpp
        src/Task.cpp
        src/Process.cpp
        main.cpp)
# Define the executable target
add_executable(cpp_oop_review ${SOURCES})
