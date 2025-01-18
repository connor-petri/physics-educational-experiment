//
// Created by Connor Petri on 1/17/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_RESULT_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_RESULT_H

#include <string>

namespace peeTest
{

    enum Status {
        ERROR = -1,
        NONE = 0,
        SUCCESS  = 1,
        FAILURE = 2
    };

    class Result {
    public:
        explicit Result(const Status &status);
        Result(const Status &status, const std::string &details);
        Result();

        ~Result();

        const Status status() const { return *this->_status; }
        const void Status(const Status &status) { *this->_status = status; }

        const std::string & details() const { return *this->_details; }

        void append(const std::string &detail);

    protected:
        enum Status *_status = new enum Status;
        std::string *_details = new std::string;
    };

} // peeTest

#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_RESULT_H
