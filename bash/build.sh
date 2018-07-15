#!/bin/bash

# Create build directory
BUILD_DIR="../build"
mkdir -p $BUILD_DIR && cd $BUILD_DIR

# Install dependencies
conan install ..

# Create Makefiles and compile
cmake ..
make
