//
// Created by connor on 1/31/25.
//

#ifndef VECTOR2_H
#define VECTOR2_H

#include "Vector3.h"

namespace pee {

    class Vector2 : public Vector3 {
    public:
        Vector2(float x, float y);
        ~Vector2() = default;

        float z() const override;
        Vector2 unitVector() const;
    };

} // pee

#endif //VECTOR2_H
