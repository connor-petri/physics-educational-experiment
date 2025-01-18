//
// Created by Connor Petri on 1/14/25.
//
#include "PeeTest.h"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define WHITE   "\033[37m"

namespace peeTest {

    void PeeTest::add(ITest *test) {
        PeeTest::_tests->push_back(test);
    }

    void PeeTest::runall() {
        for (ITest *test : *PeeTest::_tests) {
            std::cout << BLUE << "Running Test " << test->id() << "...\n";

            Result r = test->run();

            if (r.status() == Status::SUCCESS) {
                std::cout << GREEN << "Test " << test->id() << " passed.";
            } else {
                std::cout << RED << "Test " << test->id() << " has "
                << (r.status() == Status::ERROR ? "encountered an error:\n" : "failed:\n") << r.details();
            }

            std::cout << WHITE << "\n\n";
        }
    }

    std::vector<ITest*> * PeeTest::_tests = new std::vector<ITest*>;

}