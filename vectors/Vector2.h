//
// Created by connor on 1/31/25.
//

#ifndef VECTOR2_H
#define VECTOR2_H

#include "Vector3.h"

namespace pee {

    class Vector2 : public Vector3 {
    public:
        Vector2(float x = 0.0f, float y = 0.0f);
        Vector2(int x, int y);
        Vector2(const Vector3 &v);

        ~Vector2() = default;

        std::string toString() const override;

        float z() const override;
        void z(float z) override;

        Vector2 unitVector() const;
    };

} // pee

#endif //VECTOR2_H
