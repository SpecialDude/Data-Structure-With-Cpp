#!/usr/bin/bash


if [ "$1" = "" ];
then
    # Running the script from the root (project) directory
    g++-11 -c ./src/Exercises/exercise1_8.cpp
    mv  exercise1_8.o ./Builds/obj/ 
    g++-11 -o ./Builds/exercise1_8 ./src/Exercises/exercise1_8.cpp ./src/Exercises/main-test-file.cpp # -save-temps

    ./Builds/exercise1_8
    exit
fi

if [ "$1" = "clean" ];
then
    # Remove all build files
    rm -v ./Builds/*
    rm -v ./Builds/obj/*
    rm -v ./Builds/debug/*
fi

if [ "$1" = "debug" ];
then
    # Compile and run in debug mode
    if [ "$2" = "save" ];
    then
        ARGS="-save-temps"
    else
        ARGS=""
    fi
    g++-11 -Wall -g -o ./Builds/debug/exercise1_8 ./src/Exercises/exercise1_8.cpp ./src/Exercises/main-test-file.cpp $ARGS

    ./Builds/debug/exercise1_8
    exit
fi

if [ "$1" = "shared" ];
then
    # Build to shared Library
    g++-11 -shared -fPIC ./src/Exercises/exercise1_8.cpp -o ./Builds/obj/exercise1_8.so
    exit
fi


# Running Script in the containing directory

# g++-11 -c ../src/Exercises/exercise1_8.cpp
# mv  exercise1_8.o ../Builds/obj/ 
# g++-11 -o ../Builds/exercise1_8 ../src/Exercises/exercise1_8.cpp ../src/Exercises/main-test-file.cpp