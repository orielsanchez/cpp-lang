#!/bin/bash

# Save file as build.sh and make file executable:
# chmod +x build.sh
# run with ./build.sh


# Define the build directory
BUILD_DIR="build"

# Default build type is Debug
BUILD_TYPE="Debug"

# Check if a build type is passed as an argument
if [ "$1" == "release" ]; then
  BUILD_TYPE="Release"
elif [ "$1" == "clean" ]; then
  echo "Cleaning build directory..."
  rm -rf "$BUILD_DIR"
  # Shift to check if a build type is specified after "clean"
  shift
  if [ "$1" == "release" ]; then
    BUILD_TYPE="Release"
  fi
fi

echo "Build type: $BUILD_TYPE"

# Check if the build directory exists
if [ ! -d "$BUILD_DIR" ]; then
  # Create the build directory
  mkdir "$BUILD_DIR"
fi

# Navigate to the build directory
cd "$BUILD_DIR"

# Run CMake to configure the project with the specified build type
cmake -DCMAKE_BUILD_TYPE=$BUILD_TYPE ..

# Build the project
cmake --build .

# Return to the root directory
cd ..
