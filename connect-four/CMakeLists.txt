# Specify the minimum version of CMake
cmake_minimum_required(VERSION 3.30)

# Set the project name
project(connectfour)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add the executables
file(GLOB SOURCES "src/*.cpp")
add_executable(connectfour ${SOURCES})

# Include header files directory
target_include_directories(connectfour PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(connectfour ${SDL2_LIBRARIES})

