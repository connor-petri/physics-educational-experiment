//
// Created by Connor Petri on 1/17/25.
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_RESULT_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_RESULT_H

#include <string>

namespace peeTest
{

    enum Status {
        NONE,
        SUCCESS,
        FAILURE,
        ERROR = -1
    };

    class Result {
    public:
        Result();
        explicit Result(const Status &status);
        Result(const Status &status, const std::string &details);

        ~Result();

        const Status status() const { return *this->_status; }
        void status(const Status &status) { *this->_status = status; }

        void setFail() { *this->_status = Status::FAILURE; }
        void setError() { *this->_status = Status::ERROR; }

        bool fail() const { return *this->_status == Status::FAILURE; }
        bool ok() const { return *this->_status == Status::SUCCESS; }
        bool error() const { return *this->_status == Status::ERROR; }

        const std::string & details() const { return *this->_details; }

        void append(const std::string &detail);

    protected:
        enum Status *_status = new enum Status;
        std::string *_details = new std::string;
    };

} // peeTest

#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_RESULT_H
