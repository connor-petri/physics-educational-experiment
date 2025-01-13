//
// Created by Connor Petri on 1/12/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H

#include <tuple>
#include <utility>

namespace peeTest {
    enum Status {
        NONE,
        SUCCESS,
        FAILURE
    };

    template <typename TFunction, typename TOutput, typename... Inputs>
    class Test {
    public:
        Test(TFunction function, TOutput expectedOutput, Inputs... inputs)
        : _func(function), _expectedOutput(expectedOutput), _inputs(std::make_tuple(inputs...)) {}

        Status run() {
            TOutput result = std::apply(_func, _inputs);
            return result == _expectedOutput ? Status::SUCCESS : Status::FAILURE;
        }

    protected:
        TFunction _func;
        TOutput _expectedOutput;
        std::tuple<Inputs...> _inputs;
    };
}


#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H
