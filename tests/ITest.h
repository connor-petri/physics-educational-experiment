//
// Created by Connor Petri on 1/14/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_ITEST_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_ITEST_H

namespace peeTest
{

    enum Status {
        NONE,
        SUCCESS,
        FAILURE
    };

    class ITest
    {
    public:
        virtual Status run() = 0;
    };

} // peeTest

#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_ITEST_H
