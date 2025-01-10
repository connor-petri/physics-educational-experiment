//
// Created by Connor Petri on 1/9/25.
//

#include "Vectors.h"
#include <cmath>

using pee::Vector3;
using pee::Vector2;

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