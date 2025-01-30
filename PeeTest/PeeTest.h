//
// Created by Connor Petri on 1/14/25.
//

#pragma once

#include <vector>
#include <iostream>

#include "Result.h"
#include "TestCase.h"
#include <cmath>

#define SIGFIGS 5

namespace peeTest
{

    enum Status;
    class Result;

    class PeeTest
    {
    public:
        // main functionality
        static void add(TestCase *test);
        static void runAll();

        // misc functions
        static bool assertEqual(float a, float b);

    private:
        static std::vector<TestCase*> *_tests;
    };

} // peeTest

