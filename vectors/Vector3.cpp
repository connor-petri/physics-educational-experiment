//
// Created by Connor Petri on 1/9/25.
//

#include "Vector3.h"
#include "../PeeTest/PeeTest.h"
#include <cmath>
#include <cfloat>

#define assertEqual peeTest::PeeTest::assertEqual

using pee::Vector3;
using std::sqrt;
using std::pow;
using std::acos;

namespace pee {

    Vector3::Vector3(float x, float y, float z) {
        *this->_x = x;
        *this->_y = y;
        *this->_z = z;
    }

    Vector3::Vector3(int x, int y, int z) {
        *this->_x = float(x);
        *this->_y = float(y);
        *this->_z = float(z);
    }

    Vector3::Vector3(const Vector3 &v) {
        *this->_x = v.x();
        *this->_y = v.y();
        *this->_z = v.z();
    }

    Vector3::~Vector3() {
        delete this->_x;
        delete this->_y;
        delete this->_z;
    }

    std::string Vector3::toString() const {
        return "Vector3(x: " + std::to_string(*this->_x) + ", y: " + std::to_string(*this->_y) + ", z: " + std::to_string(*this->_z);
    }

    // Properties
    float Vector3::x() const {
        return *this->_x;
    }

    void Vector3::x(float x) {
        *this->_x = x;
    }

    float Vector3::y() const {
        return *this->_y;
    }

    void Vector3::y(float y) {
        *this->_y = y;
    }

    float Vector3::z() const {
        return *this->_z;
    }

    void Vector3::z(float z) {
        *this->_z = z;
    }

    float Vector3::magnitude() const {
        return sqrt(pow(*this->_x, 2.0f) + pow(*this->_y, 2.0f) + pow(*this->_z, 2.0f));
    }

    // Operations
    float Vector3::dot(const Vector3 &other) const {
        return *this->_x * other.x() + *this->_y * other.y() + *this->_z * other.z();
    }

    Vector3 Vector3::cross(const Vector3 &other) const {
        float x = (*this->_y * other.z()) - (*this->_z * other.y());
        float y = (*this->_z * other.x()) - (*this->_x * other.z());
        float z = (*this->_x * other.y()) - (*this->_y * other.x());

        return Vector3(x, y, z);
    }

    Vector3 Vector3::unitVector() const {
        if (this->magnitude() == 0.0f) {
            return Vector3(0.0f, 0.0f, 0.0f);
        }

        return Vector3(*this->_x/this->magnitude(),
                       *this->_y/this->magnitude(),
                       *this->_z/this->magnitude());
    }

    void Vector3::normalize() {
        *this = this->unitVector();
    }

    // Operator overloads

    Vector3 Vector3::operator+(const Vector3 &other) const {
        return Vector3(*this->_x + other.x(),
                       *this->_y + other.y(),
                       *this->_z + other.z());
    }

    Vector3 Vector3::operator-(const Vector3 &other) const {
        return Vector3(*this->_x - other.x(),
                       *this->_y - other.y(),
                       *this->_z - other.z());
    }

    Vector3 Vector3::operator*(float other) const {
        return Vector3(other * *this->_x,
                       other * *this->_y,
                       other * *this->_z);
    }

    Vector3 Vector3::operator*(int other) const {
        return this->operator*(float(other));
    }

    float Vector3::operator*(const Vector3 &other) const {
        return this->dot(other);
    }

    Vector3 Vector3::operator%(const Vector3 &other) const {
        return this->cross(other);
    }

    Vector3 Vector3::operator/(float other) const{
        return this->operator*(1.0f/other);
    }

    Vector3 Vector3::operator/(int other) const {
        return this->operator/(float(other));
    }

    // Assignment operator
    Vector3& Vector3::operator=(const Vector3 &other) {
        if (this != &other) {
            *this->_x = other.x();
            *this->_y = other.y();
            *this->_z = other.z();
        }

        return *this;
    }

    // Boolean Operators
    bool Vector3::operator==(const Vector3 &other) const {
        return assertEqual(*this->_x, other.x()) && assertEqual(*this->_y, other.y()) && assertEqual(*this->_z, other.z());
    }

    bool Vector3::operator!=(const Vector3 &other) const {
        return !this->operator==(other);
    }
}