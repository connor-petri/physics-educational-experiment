#include <iostream>

#include "tests/Test.h"
#include <vector>

int add(int x, int y) {
    return x + y;
}

int main()
{
    using namespace peeTest;

    std::vector<Test<int, int (*)(int, int), int, int>> tests = { Test(5, add, 2, 3),
                                Test(8, add, -5, 13),
                                Test(9, add, 4, 4),
                                Test(3, add, 2, 1) };

    for (Test test : tests) {
        test.run();
    }

}
