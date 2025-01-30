//
// Created by connor on 1/29/25.
//

#ifndef VECTOR3TEST_H
#define VECTOR3TEST_H

#include "../../PeeTest/PeeTest.h"
#include "../Vector3.h"

using peeTest::Result;
using peeTest::Status;
using peeTest::PeeTest;

namespace pee {

    class Vector3Test : peeTest::TestCase {
    public:
        Vector3Test(float x, float y, float z);
        ~Vector3Test() override;

        float x() { return *this->_v[0]; }
        float y() { return *this->_v[1]; }
        float z() { return *this->_v[2]; }

        Result run() override;

    private:
        float **_v = new float*[3];

        // Tests
        Result & constructors(Result &r);
    };

} // pee

#endif //VECTOR3TEST_H
