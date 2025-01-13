#include <iostream>

#include "tests/Test.h"

int add(int x, int y) {
    return x + y;
}

int main()
{
    peeTest::Test test1(add, 5, 3, 3);

    std::cout << (test1.run() == peeTest::Status::SUCCESS ? "Success" : "Failure");
}
