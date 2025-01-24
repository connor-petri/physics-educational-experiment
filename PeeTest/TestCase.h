//
// Created by connor on 1/23/25.
//

#pragma once

#include "Result.h"

namespace peeTest {

    class TestCase {
    public:
        TestCase();
        virtual ~TestCase();

        unsigned int id() const;
        virtual Result run() = 0;

    protected:
        unsigned int *_id = new unsigned int;
        static unsigned int _nextId;
    };

} // peeTest
