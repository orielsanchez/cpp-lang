# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.30)

# Set the project name
project(tm)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executables
file(GLOB SOURCES "src/*.cpp")
add_executable(tm ${SOURCES})

# Include header files directory
target_include_directories(tm PRIVATE ${CMAKE_SOURCE_DIR}/include)

