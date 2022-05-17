#!usr/bin/bash
g++-11 -c ../src/Exercises/exercise1_8.cpp
mv  exercise1_8.o ../Builds/obj/ 
g++-11 -o ../Builds/example1_8 ../src/Exercises/exercise1_8.cpp ../src/Exercises/main-test-file.cpp

../Builds/example1_8
