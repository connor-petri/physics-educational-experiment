//
// Created by Connor Petri on 1/12/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H

#include <tuple>
#include <utility>

#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */

namespace peeTest {

    enum Status {
        NONE,
        SUCCESS,
        FAILURE
    };

    template <typename TOutput, typename TFunction, typename... Inputs>
    class Test {
    public:
        Test(TOutput expectedOutput, TFunction function, Inputs... inputs)
        : _func(function), _expectedOutput(expectedOutput), _inputs(std::make_tuple(inputs...)) {
            this->_id = this->_next_id++;
        }

        Status run() {
            std::cout << BLUE << "Running Test " << this->_id << "...\n";

            TOutput result = std::apply(_func, _inputs);

            Status status = result == _expectedOutput ? Status::SUCCESS : Status::FAILURE;

            if (status == Status::FAILURE) {
                std::cout   << RED << "Test " << this->_id << " failed -> Returned: "
                            << result << " Expected: " << this->_expectedOutput << std::endl;

                return Status::FAILURE;
            }

            std::cout << GREEN << "Test " << this->_id << " was successful." << std::endl;
            return Status::SUCCESS;
        }

        unsigned int id() { return this->_id; }

    protected:
        unsigned int _id;
        static unsigned int _next_id;

        TFunction _func;
        TOutput _expectedOutput;
        std::tuple<Inputs...> _inputs;
    };

    template <typename TFunction, typename TOutput, typename... Inputs>
    unsigned int Test<TFunction, TOutput, Inputs...>::_next_id = 0;

}


#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_TEST_H
