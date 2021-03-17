#!/bin/bash

# BUILDING THE PROJECT, BUT IT IS BETTER TO USE THE VSCODE CMAKE EXTENSION

# DEPENDENCIES: CMAKE, CTEST

cmake --version
if [ "$?" -ne "0" ]; then
    echo "Installing cmake..."
    sudo apt-get install cmake
fi

ls build > /dev/null 2>&-
if [ "$?" -ne "0" ]; then
    rm -rf build
    mkdir build
fi

cd build
cmake ..
make