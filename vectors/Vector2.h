//
// Created by Connor Petri on 1/12/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_VECTOR2_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_VECTOR2_H

#include "Vector3.h"

namespace pee {

    class Vector2 : public Vector3 {
    public:
        explicit Vector2(float x = 0.0, float y = 0.0);
        explicit Vector2(int x = 0, int y = 0);

        double z() override;

        double angleGamma() override;
        double angleGammaDegrees() override;
    };

}


#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_VECTOR2_H
