//
// Created by connor on 1/31/25.
//

#include "Vector2Test.h"

namespace peeTest {

    Vector2Test::Vector2Test(float x1, float y1, float x2, float y2) {
        this->v1 = new Vector2(x1, y1);
        this->v2 = new Vector2(x2, y2);
    }

    Vector2Test::~Vector2Test() {
        delete this->v1;
        delete this->v2;
    }

    Result Vector2Test::run() {
        if (this->v1->z() != 0.0f || this->v2->z() != 0.0f) {
            this->result->append("Vector2Test::run() -> Vector2.z() should always return 0");
            this->result->setFail();
        }

        Vector3 v = *this->v1 % *this->v2;
        if (v.x() != 0.0f || v.y() != 0.0f) {
            this->result->append("Vector2Test::run() -> The cross product between 2 Vector2 should always be 0.");
            this->result->setFail();
        }

        return *this->result;
    }

} // peeTest