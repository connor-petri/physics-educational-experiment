//
// Created by connor on 1/31/25.
//

#include "Vector2.h"

namespace pee {

    Vector2::Vector2(float x, float y)
        : Vector3(x, y, 0.0) {}

    Vector2::Vector2(int x, int y)
        : Vector3(x, y, 0.0) {}

    Vector2::Vector2(const Vector3 &v)
        : Vector3(v.x(), v.y(), 0.0) {}

    std::string Vector2::toString() const {
        return "Vector2(" + std::to_string(*this->_x) + ", " + std::to_string(*this->_y) + ")";
    }

    float Vector2::z() const {
        return 0.0f;
    }

    void Vector2::z(float z) {
        // Left empty on purpose. This is not to be used on Vector2 objects
    }

    Vector2 Vector2::unitVector() const {
        return Vector2(*this->_x / this->mag(), *this->_y / this->mag());
    }

} // pee