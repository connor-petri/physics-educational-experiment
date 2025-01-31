#include <iostream>

#include "PeeTest/PeeTest.h"
#include "vectors/tests/Vector3Test.h"
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
    using peeTest::Vector3Test;
    Vector3Test t0(1,1,1,1,1,1);
    Vector3Test t1(1,0,0,2,0,0); // Parallel
    Vector3Test t2(1,0,0,0,1,0); // Orthogonal

    peeTest::PeeTest::runAll();
}
