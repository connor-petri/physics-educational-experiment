#include <iostream>

#include "PeeTest/PeeTest.h"
#include <vector>

class AddTest : public peeTest::TestCase {
public:
    AddTest(int x, int y, int expected) {
        this->x = x;
        this->y = y;
        this->expected = expected;
    }

    peeTest::Result run() override {
        return this->x + this->y == this->expected  ? peeTest::Result(peeTest::Status::SUCCESS)
                                                    : peeTest::Result(peeTest::Status::FAILURE);
    }

private:
    int x;
    int y;
    int expected;
};

int main()
{
    AddTest(2, 3, 5);
    AddTest(3, 3, 5);
    AddTest(1, 2, 3);
    AddTest(2, 2, 4);
    AddTest(5, 5, 10);

    peeTest::PeeTest::runall();
}
