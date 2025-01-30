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
        Vector3Test(float x1, float y1, float z1, float x2, float y2, float z2);
        ~Vector3Test() override;

        Result run() override;

    private:
        Result *r;
        Vector3 *v1 = nullptr;
        Vector3 *v2 = nullptr;

        // Tests
        Result & operators(Result &r);
        Result & arithmetic(Result &r);
    };

} // pee

#endif //VECTOR3TEST_H
