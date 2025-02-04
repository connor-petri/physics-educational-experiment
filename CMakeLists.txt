cmake_minimum_required(VERSION 3.24)
project(physics_educational_experiment)

set(CMAKE_CXX_STANDARD 23)

# Dependencies
include(FetchContent)

set(SFML_VERSION 3.0.0)
FetchContent_Declare(
        sfml
        URL https://github.com/SFML/SFML/archive/refs/tags/${SFML_VERSION}.zip
        FIND_PACKAGE_ARGS ${SFML_VERSION}
)

FetchContent_MakeAvailable(sfml)


add_executable(physics_educational_experiment
        main.cpp
        vectors/Vector3.cpp
        vectors/Vector3.h
        PeeTest/PeeTest.cpp
        PeeTest/PeeTest.h
        PeeTest/Result.cpp
        PeeTest/Result.h
        PeeTest/TestCase.cpp
        PeeTest/TestCase.h
        vectors/tests/Vector3Test.cpp
        vectors/tests/Vector3Test.h
        vectors/Vector2.cpp
        vectors/Vector2.h
        vectors/tests/Vector2Test.cpp
        vectors/tests/Vector2Test.h
)
