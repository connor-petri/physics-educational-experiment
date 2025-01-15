//
// Created by Connor Petri on 1/14/25.
//
#include "PeeTest.h"

namespace peeTest {

    void PeeTest::add(ITest *test) {
        PeeTest::_tests->push_back(test);
    }

    void PeeTest::runall() {
        for (ITest *test : *PeeTest::_tests) {
            test->run();
        }
    }

    std::vector<ITest*> * PeeTest::_tests = new std::vector<ITest*>;

}