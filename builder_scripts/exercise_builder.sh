#!/usr/bin/bash


# g++-11 -c ../src/Exercises/exercise1_8.cpp
# mv  exercise1_8.o ../Builds/obj/ 
# g++-11 -o ../Builds/exercise1_8 ../src/Exercises/exercise1_8.cpp ../src/Exercises/main-test-file.cpp

# Running the script from the root (project) directory
# g++-11 -c ./src/Exercises/exercise1_8.cpp
# mv  exercise1_8.o ./Builds/obj/ 
g++-11 -o ./Builds/exercise1_8 ./src/Exercises/exercise1_8.cpp ./src/Exercises/main-test-file.cpp


# Build to shared Library
# g++-11 -shared -fPIC ./src/Exercises/exercise1_8.cpp -o ./Builds/obj/exercise1_8.so

./Builds/exercise1_8