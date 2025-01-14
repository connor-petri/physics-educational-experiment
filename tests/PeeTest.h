//
// Created by Connor Petri on 1/14/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_PEETEST_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_PEETEST_H

#include <vector>
#include "Test.h"

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

    // TODO: Fix circular import
    std::vector<ITest*>* PeeTest::_tests = new std::vector<ITest*>;

} // peeTest

#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_PEETEST_H
