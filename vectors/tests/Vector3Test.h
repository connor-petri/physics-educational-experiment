//
// Created by connor on 1/29/25.
//

#ifndef VECTOR3TEST_H
#define VECTOR3TEST_H

#include "../../PeeTest/PeeTest.h"
#include "../Vector3.h"

namespace pee {
    class Vector3Test : peeTest::TestCase {
    public:
        Vector3Test(float x, float y, float z);
        ~Vector3Test();

        peeTest::Result run() override;

    private:
        Vector3 *_v;
    };

} // pee

#endif //VECTOR3TEST_H
