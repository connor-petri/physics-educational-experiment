cmake_minimum_required(VERSION 3.24)
project(physics_educational_experiment)

set(CMAKE_CXX_STANDARD 23)

add_executable(physics_educational_experiment main.cpp vectors/Vector3.cpp vectors/Vector3.h tests/Test.h tests/ITest.h tests/PeeTest.cpp tests/PeeTest.h)
