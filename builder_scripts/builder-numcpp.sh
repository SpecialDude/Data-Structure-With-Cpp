#!/bin/bash

# Compile and link (Essentially, complete build)
g++-11 -o ./Builds/mainNumcppTest src/numcpp.cpp src/main-practice-file-numcpp.cpp


# Run the program
./Builds/mainNumcppTest
