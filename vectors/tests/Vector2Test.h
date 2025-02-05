//
// Created by connor on 1/31/25.
//

#ifndef VECTOR2TEST_H
#define VECTOR2TEST_H

#include "../../PeeTest/PeeTest.h"
#include "../Vector2.h"
#include "../Vector3.h"

using pee::Vector2, pee::Vector3;

namespace peeTest {

    class Vector2Test : public TestCase {
    public:
        Vector2Test(float x1, float y1, float x2, float y2);
        ~Vector2Test() override;

        Result run() override;

    private:
        Vector2 *v1 = nullptr;
        Vector2 *v2 = nullptr;
    };

} // peeTest

#endif //VECTOR2TEST_H
