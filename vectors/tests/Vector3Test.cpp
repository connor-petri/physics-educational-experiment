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

        // Scalar Multiplication
        std::vector<float> mCases = { 5.3f, -1.0f, 0.0f, 442.42f, -399.23f, 0.001f, 0.00001f, 1.0f };

        for (const float num : mCases) {
            v = *this->v1 * num;
            if (!assertEqual(v.x(), this->v1->x() * num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator*(float) -> x values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.y(), this->v1->y() * num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator*(float) -> y values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.z(), this->v1->z() * num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator*(float) -> z values do not match.");
                this->result->setFail();
            }
        }

        // Scalar Division
        for (const float num : mCases) {
            v = *this->v1 / num;
            if (!assertEqual(v.x(), this->v1->x() * 1.0f/num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator/(float) -> x values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.y(), this->v1->y() * 1.0f/num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator/(float) -> y values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.z(), this->v1->z() * 1.0f/num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator/(float) -> z values do not match.");
                this->result->setFail();
            }
        }


    }

    Result Vector3Test::run() {
        this->boolOps();
        this->arithmeticOps();

        return *this->result;
    }

} // pee