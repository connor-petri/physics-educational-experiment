//
// Created by Connor Petri on 1/14/25.
//

#pragma once

#include <vector>
#include <iostream>

#include "Result.h"
#include "Test.h"

namespace peeTest
{

    enum Status;
    class Result;
    class ITest;

    class PeeTest
    {
    public:
        static void add(ITest *test);

        static void runall();

    private:
        static std::vector<ITest*> *_tests;
    };

} // peeTest

