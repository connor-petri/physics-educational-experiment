//
// Created by connor on 1/31/25.
//

#include "Vector2.h"

namespace pee {

    Vector2::Vector2(float x, float y) : Vector3(x, y, 0.0) {}

    Vector2::Vector2(int x, int y) : Vector3(x, y, 0.0) {}

    float Vector2::z() const {
        return 0.0f;
    }

    Vector2 Vector2::unitVector() const {
        return Vector2(*this->_x / this->mag(), *this->_y / this->mag());
    }

} // pee