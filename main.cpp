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
    AddTest t1(2, 3, 5);
    AddTest t2(3, 3, 5);
    AddTest t3(1, 2, 3);
    AddTest t4(2, 2, 4);
    AddTest t5(5, 5, 10);

    peeTest::PeeTest::runAll();
}
