//
// Created by Connor Petri on 1/17/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H

#include <iostream>
#include <string>
#include "Result.h"

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */

namespace peeTest {

    class ITest // Test interface to represent generic Tests independent of template types
    {
    public:
        virtual Result run() = 0;
        virtual unsigned int id() = 0;
    };

    template <typename TOutput, typename TFunction, typename... Inputs>
    class Test : public ITest {
    public:
        Test(TOutput expectedOutput, TFunction function, Inputs... inputs)
                : _id(this->_next_id++), _func(function), _expectedOutput(expectedOutput), _inputs(std::make_tuple(inputs...)) {}

        Result run() override {
            TOutput result = std::apply(_func, _inputs);

            if (result != _expectedOutput) {
                std::string details = "ERROR_DETAILS";
                return Result(Status::FAILURE, details);
            }

            return Result(Status::SUCCESS);
        }

        unsigned int id() override { return this->_id; }

    protected:
        unsigned int _id{};
        static unsigned int _next_id;

        TFunction _func;
        TOutput _expectedOutput;
        std::tuple<Inputs...> _inputs;
    };

    template <typename TFunction, typename TOutput, typename... Inputs>
    unsigned int Test<TFunction, TOutput, Inputs...>::_next_id = 0;

}


#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H
