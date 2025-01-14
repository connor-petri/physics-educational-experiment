#include <iostream>

#include "tests/PeeTest.h"
#include "tests/Test.h"
#include <vector>

int add(int x, int y) {
    return x + y;
}

int main()
{
    using namespace peeTest;

    PeeTest::add(new Test(5, add, 2, 3));
    PeeTest::add(new Test(8, add, -5, 13));
    PeeTest::add(new Test(9, add, 4, 4));
    PeeTest::add(new Test(3, add, 2, 1));

    PeeTest::runall();

}
