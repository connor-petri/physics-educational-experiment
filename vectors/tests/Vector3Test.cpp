//
// Created by connor on 1/29/25.
//

#include "Vector3Test.h"

#define assert PeeTest::assert

namespace pee {

    Vector3Test::Vector3Test(float x, float y, float z) {
        *this->_v[0] = x;
        *this->_v[1] = y;
        *this->_v[2] = z;
    }

    Vector3Test::~Vector3Test() {
        delete[] this->_v;
    }

    // Tests
    Result & Vector3Test::constructors(Result &r) {
        Vector3 v(*this->_v[0], *this->_v[1], *this->_v[2]);
        if (!assert(this->x(), v.x())) {
            r.append("Vector3::Vector3(float x, float y, float z) -> x values do not match.");
            r.setFail();
        }
        if (!assert(this->y(), v.y())) {
            r.append("Vector3::Vector3(float x, float y) -> y values do not match.");
            r.setFail();
        }
        if (!assert(this->z(), v.z())) {
            r.append("Vector3::Vector3(float x, float y) -> z values do not match.");
        }

        v = Vector3(std::floor(v.x()), std::floor(v.y()), std::floor(v.z()));

        if (!assert(this->x(), v.x())) {
            r.append("Vector3::Vector3(int x, int y, int z) -> x values do not match.");
            r.setFail();
        }
        if (!assert(this->y(), v.y())) {
            r.append("Vector3::Vector3(int x, int y) -> y values do not match.");
            r.setFail();
        }
        if (!assert(this->z(), v.z())) {
            r.append("Vector3::Vector3(int x, int y) -> z values do not match.");
            r.setFail();
        }

        //TODO: Copy constructor and array constructor
        //TODO: Decide if Vector3Test should hold 2 Vectors

        return r;
    }

    Result Vector3Test::run() {
        Result r(Status::SUCCESS);

        return r;
    }

} // pee