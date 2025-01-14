//
// Created by Connor Petri on 1/14/25.
//
#pragma once

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

