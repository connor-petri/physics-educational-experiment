//
// Created by Connor Petri on 1/14/25.
//

#pragma once

#include <vector>
#include "ITest.h"

namespace peeTest
{

    class PeeTest
    {
    public:
        static void add(ITest* test);

        static Status runall();

    private:
        static std::vector<ITest*> *_tests;
    };

} // peeTest

