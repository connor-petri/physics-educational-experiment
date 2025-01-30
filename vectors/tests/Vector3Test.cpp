//
// Created by connor on 1/29/25.
//

#include "Vector3Test.h"

#define assertEqual PeeTest::assertEqual

namespace pee {

    Vector3Test::Vector3Test(float x1, float y1, float z1, float x2, float y2, float z2) {
        this->r = new Result(Status::SUCCESS);
        this->v1 = new Vector3(x1, y1, z1);
        this->v2 = new Vector3(x2, y2, z2);
    }

    Vector3Test::~Vector3Test() {
        delete this->v1;
        delete this->v2;
    }

    // Tests
    Result & Vector3Test::operators(Result &r) {
        Vector3 v = *this->v1;
        if (!assertEqual(v.x(), this->v1->x())) {
            r.append("Vector3Test::operators -> Vector3::operator= -> x values do not match.");
            r.setFail();
        }
        if (!assertEqual(v.y(), this->v2->y())) {
            r.append("Vector3Test::operators -> Vector3::operator= -> y values do not match.");
            r.setFail();
        }
        if (!assertEqual(v.z(), this->v1->z())) {
            r.append("Vector3Test::operators -> Vector3::operator= -> z values do not match.");
            r.setFail();
        }

        return r;
    }

    Result Vector3Test::run() {

        return *this->r;
    }

} // pee