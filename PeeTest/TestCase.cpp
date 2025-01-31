//
// Created by connor on 1/23/25.
//

#include "TestCase.h"
#include "PeeTest.h"

namespace peeTest {

    TestCase::TestCase() {
        *this->_id = TestCase::_nextId++;
        this->result = new Result(Status::SUCCESS);
        PeeTest::add(this);
    }

    TestCase::~TestCase() {
        delete this->_id;
    }

    unsigned int TestCase::id() const {
        return *this->_id;
    }

    unsigned int TestCase::_nextId = 0;

} // peeTest