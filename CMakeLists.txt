cmake_minimum_required(VERSION 3.24)
project(physics_educational_experiment)

set(CMAKE_CXX_STANDARD 23)
set(SFML_DIR "~/users/connor/Projects/External\ Libraries/SFML/")

add_executable(physics_educational_experiment main.cpp vectors/Vector3.cpp vectors/Vector3.h PeeTest/PeeTest.cpp PeeTest/PeeTest.h PeeTest/Result.cpp PeeTest/Result.h
        PeeTest/TestCase.cpp
        PeeTest/TestCase.h
        vectors/tests/Vector3Test.cpp
        vectors/tests/Vector3Test.h
        vectors/Vector2.cpp
        vectors/Vector2.h
)
