//
// Created by Connor Petri on 1/17/25.
//

#include "Result.h"

namespace peeTest
{
    Result::Result() {
        *this->_status = Status::NONE;
    }

    Result::Result(const enum Status &status) {
        *this->_status = status;
    }

    Result::Result(const enum Status &status, const std::string &details) {
        *this->_status = status;
        *this->_details = details;
    }

    Result::~Result() {
        delete this->_status;
        delete this->_details;
    }

    void Result::append(const std::string &detail) {
        *this->_details += (detail + "\n");
    }

} // peeTest