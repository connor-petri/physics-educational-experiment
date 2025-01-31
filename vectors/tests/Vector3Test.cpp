//
// Created by connor on 1/29/25.
//

#include "Vector3Test.h"

#define assertEqual PeeTest::assertEqual

namespace peeTest {

    Vector3Test::Vector3Test(float x1, float y1, float z1, float x2, float y2, float z2) {
        this->v1 = new Vector3(x1, y1, z1);
        this->v2 = new Vector3(x2, y2, z2);
    }

    Vector3Test::~Vector3Test() {
        delete this->v1;
        delete this->v2;
    }

    // Tests
    void Vector3Test::boolOps() {
        // =
        Vector3 v = *this->v1;
        if (!assertEqual(v.x(), this->v1->x())) {
            this->result->append("Vector3Test::operators -> Vector3::operator= -> x values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.y(), this->v1->y())) {
            this->result->append("Vector3Test::operators -> Vector3::operator= -> y values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.z(), this->v1->z())) {
            this->result->append("Vector3Test::operators -> Vector3::operator= -> z values do not match.");
            this->result->setFail();
        }

        // == !=
        if (v != *this->v1) {
            this->result->append(   "Vector3Test::operators -> Vector3::operator== -> v == v1 should return true."
                        + this->result->fail() ? "Possibly a cascading error. See previous log entry" : "");
        }
    }

    void Vector3Test::arithmeticOps() {
        // +
        Vector3 v = *this->v1 + *this->v2;
        if (!assertEqual(v.x(), this->v1->x() + this->v2->x())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator+ -> x values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.y(), this->v1->y() + this->v2->y())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator+ -> y values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.z(), this->v1->z() + this->v2->z())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator+ -> z values do not match.");
            this->result->setFail();
        }

        // -
        v = *this->v1 - *this->v2;
        if (!assertEqual(v.x(), this->v1->x() - this->v2->x())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator- -> x values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.y(), this->v1->y() - this->v2->y())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator- -> y values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.z(), this->v1->z() - this->v2->z())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator- -> z values do not match.");
            this->result->setFail();
        }
    }

    Result Vector3Test::run() {
        this->boolOps();
        this->arithmeticOps();

        return *this->result;
    }

} // pee