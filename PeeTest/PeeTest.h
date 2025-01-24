//
// Created by Connor Petri on 1/14/25.
//

#pragma once

#include <vector>
#include <iostream>

#include "Result.h"
#include "TestCase.h"

namespace peeTest
{

    enum Status;
    class Result;

    class PeeTest
    {
    public:
        static void add(TestCase *test);

        static void runall();

    private:
        static std::vector<TestCase*> *_tests;
    };

} // peeTest

