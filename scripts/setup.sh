#!/bin/bash

# BUILDING THE PROJECT, BUT IT IS BETTER TO USE THE VSCODE CMAKE EXTENSION

# DEPENDENCIES: CMAKE, CTEST

if [[ $1 == "--reconfigure" ]]; then
    echo it works yeak > working
    ./scripts/clear.sh
fi

cmake --version
if [ "$?" -ne "0" ]; then
    echo "Installing cmake..."
    sudo apt-get install cmake
	if [ "&?" -ne "0" ]; then
		echo "could not install cmake, please install it on your own before proceeding" &1>2
		exit 1
	fi
fi

ls build > /dev/null 2>&-
if [ "$?" -ne "0" ]; then
    rm -rf build
    mkdir build
fi

cmake -DCMAKE_C_COMPILER:FILEPATH=clang -DCMAKE_CXX_COMPILER:FILEPATH=clang++ -H. -B./build -G "Unix Makefiles"

cd build
make