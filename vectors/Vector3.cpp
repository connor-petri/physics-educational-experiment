//
// Created by Connor Petri on 1/9/25.
//

#include "Vector3.h"
#include <cmath>

using pee::Vector3;

Vector3::Vector3(double x, double y, double z) {
    *this->_x = x;
    *this->_y = y;
    *this->_z = z;
}

Vector3::Vector3(int x, int y, int z) {
    *this->_x = double(x);
    *this->_y = double(y);
    *this->_z = double(z);
}

Vector3::~Vector3() {
    delete this->_x;
    delete this->_y;
    delete this->_z;
}

// Properties
double Vector3::x() const {
    return *this->_x;
}

double Vector3::y() const {
    return *this->_y;
}

double Vector3::z() const {
    return *this->_z;
}

double Vector3::magnitude() const {
    return sqrt(pow(*this->_x, 2) + pow(*this->_y, 2) + pow(*this->_z, 2));
}

// Angles
double Vector3::angleAlpha() const {
    return acos(*this->_x / this->magnitude());
}

double Vector3::angleAlphaDeg() const
{
    return this->angleAlpha() / M_2_PI * 360;
}

double Vector3::angleBeta() const {
    return acos(*this->_y / this->magnitude());
}

double Vector3::angleBetaDeg() const {
    return this->angleBeta() / M_2_PI * 360;
}

double Vector3::angleGamma() const {
    return acos(*this->_z / this->magnitude());
}

double Vector3::angleGammaDeg() const {
    return this->angleGamma() / M_2_PI * 360;
}

// Operations
double Vector3::dot(const Vector3 &other) const {
    return *this->_x * other.x() + *this->_y * other.y() + *this->_z * other.z();
}

Vector3 Vector3::cross(const Vector3 &other) const {
    double x = (*this->_y * other.z()) - (*this->_z * other.y());
    double y = (*this->_z * other.x()) - (*this->_x * other.z());
    double z = (*this->_z * other.y()) - (*this->_y * other.x());

    return Vector3(x, y, z);
}

Vector3 Vector3::unitVector() const {
    return Vector3(*this->_x/this->magnitude(),
                   *this->_y/this->magnitude(),
                   *this->_z/this->magnitude());
}

void Vector3::normalize() {
    *this->_x /= this->magnitude();
    *this->_y /= this->magnitude();
    *this->_z /= this-> magnitude();
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

Vector3 Vector3::operator*(double other) const {
    return Vector3(other * *this->_x,
                   other * *this->_y,
                   other * *this->_z);
}

Vector3 Vector3::operator*(int other) const {
    return this->operator*(double(other));
}

double Vector3::operator*(const Vector3 &other) const {
    return this->dot(other);
}

Vector3 Vector3::operator%(const Vector3 &other) const {
    return this->cross(other);
}

Vector3 Vector3::operator/(double other) const{
    return this->operator*(1.0/other);
}

Vector3 Vector3::operator/(int other) const {
    return this->operator/(double(other));
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
    return *this->_x == other.x() && *this->_y == other.y() && *this->_z == other.z();
}

bool Vector3::operator!=(const Vector3 &other) const {
    return !this->operator==(other);
}