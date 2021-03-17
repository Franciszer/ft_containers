#!/bin/bash

rm -rf build

if [[ $1 == "dependencies" ]]; then
    sudo apt-get remove cmake
fi