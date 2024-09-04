# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.30)

# Set the project name
project(workers)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executables
file(GLOB SOURCES "src/*.cpp")
add_executable(workers ${SOURCES})

# Include header files directory
target_include_directories(workers PRIVATE ${CMAKE_SOURCE_DIR}/include)

