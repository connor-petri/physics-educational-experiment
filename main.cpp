#include <iostream>

#include "PeeTest/PeeTest.h"
#include "vectors/tests/Vector3Test.h"
#include "vectors/tests/Vector2Test.h"
#include <vector>

int main()
{
    using peeTest::Vector3Test, peeTest::Vector2Test;
    Vector3Test t0(1,1,1,1,1,1);
    Vector3Test t1(1,0,0,2,0,0); // Parallel
    Vector3Test t2(1,0,0,0,1,0); // Orthogonal
    Vector2Test t3(1,1,1,1);

    peeTest::PeeTest::runAll();
}
