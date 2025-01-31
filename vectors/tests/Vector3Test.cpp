//
// Created by connor on 1/29/25.
//

#include "Vector3Test.h"

#define assertEqual PeeTest::assertEqual

namespace peeTest {

    // Constructors ===================================================================================================
    Vector3Test::Vector3Test(float x1, float y1, float z1, float x2, float y2, float z2) {
        this->v1 = new Vector3(x1, y1, z1);
        this->v2 = new Vector3(x2, y2, z2);
    }

    Vector3Test::~Vector3Test() {
        delete this->v1;
        delete this->v2;
    }


    // Run ============================================================================================================
    Result Vector3Test::run() {
        this->boolOps();
        this->arithmeticOps();
        this->vectorOps();

        return *this->result;
    }


    // Bool Operator Tests ============================================================================================
    void Vector3Test::boolOps() const {
        // =
        Vector3 v = *this->v1;
        if (!assertEqual(v.x(), this->v1->x())) {
            this->result->append("Vector3Test::operators -> Vector3::operator= -> x values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.y(), this->v1->y())) {
            this->result->append("Vector3Test::operators -> Vector3::operator= -> y values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.z(), this->v1->z())) {
            this->result->append("Vector3Test::operators -> Vector3::operator= -> z values do not match.");
            this->result->setFail();
        }

        // == !=
        if (v != *this->v1) {
            this->result->append(   "Vector3Test::operators -> Vector3::operator== -> v == v1 should return true."
                                    + this->result->fail() ? "Possibly a cascading error. See previous log entry" : "");
        }
    }


    // Arithmetic Operator Tests ======================================================================================
    void Vector3Test::arithmeticOps() const {
        // + ------------------------------------------
        Vector3 v = *this->v1 + *this->v2;
        if (!assertEqual(v.x(), this->v1->x() + this->v2->x())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator+ -> x values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.y(), this->v1->y() + this->v2->y())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator+ -> y values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.z(), this->v1->z() + this->v2->z())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator+ -> z values do not match.");
            this->result->setFail();
        }


        // - ------------------------------------------
        v = *this->v1 - *this->v2;
        if (!assertEqual(v.x(), this->v1->x() - this->v2->x())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator- -> x values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.y(), this->v1->y() - this->v2->y())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator- -> y values do not match.");
            this->result->setFail();
        }
        if (!assertEqual(v.z(), this->v1->z() - this->v2->z())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::operator- -> z values do not match.");
            this->result->setFail();
        }


        // Scalar Multiplication ----------------------
        std::vector<float> mCases = { 5.3f, -1.0f, 0.0f, 442.42f, -399.23f, 0.001f, 0.00001f, 1.0f };

        for (const float num : mCases) {
            v = *this->v1 * num;
            if (!assertEqual(v.x(), this->v1->x() * num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator*(float) -> x values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.y(), this->v1->y() * num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator*(float) -> y values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.z(), this->v1->z() * num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator*(float) -> z values do not match.");
                this->result->setFail();
            }
        }


        // Scalar Division ------------------------------
        for (const float num : mCases) {
            v = *this->v1 / num;
            if (!assertEqual(v.x(), this->v1->x() * 1.0f/num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator/(float) -> x values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.y(), this->v1->y() * 1.0f/num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator/(float) -> y values do not match.");
                this->result->setFail();
            }
            if (!assertEqual(v.z(), this->v1->z() * 1.0f/num)) {
                this->result->append("Vector3Test::arithmeticOps -> Vector3::operator/(float) -> z values do not match.");
                this->result->setFail();
            }
        }


        // Magnitude -----------------------------------
        using std::sqrt;
        using std::pow;
        v = *this->v1 + *this->v2;
        float expectedMag = sqrt(pow(this->v1->x() + this->v2->x(), 2)
                                    + pow(this->v1->y() + this->v2->y(), 2)
                                    + pow(this->v1->z() + this->v2->z(), 2));

        if (!assertEqual(expectedMag, v.magnitude())) {
            this->result->append("Vector3Test::arithmeticOps -> Vector3::magnitude() -> Magnitude result incorrect");
            this->result->append("Result was ," + std::to_string(v.magnitude()));
            this->result->append("Expected Magnitude result is " + std::to_string(expectedMag));;
            this->result->setFail();
        }
    }


    // Vector Operator Tests ==========================================================================================
    void Vector3Test::vectorOps() const {
        // Dot Product ----------------------------------
        float expectedDot = this->v1->x() * this->v2->x()
                            + this->v1->y() * this->v2->y()
                            + this->v1->z() * this->v2->z();

        if (!assertEqual(expectedDot, *this->v1 * *this->v2)) {
            this->result->append("Vector3Test::vectorOps -> Vector3::operator*(const Vector3 &other) -> dot product result incorrect");
            this->result->append("Result was : " + std::to_string(*this->v1 * *this->v2));
            this->result->append("Expected Dot product result is " + std::to_string(expectedDot));
            this->result->setFail();
        }


        // Cross Product --------------------------------
        Vector3 expectedVector( (this->v1->y() * this->v2->z()) - (this->v1->z() * this->v2->y()),
                                (this->v1->z() * this->v2->x()) - (this->v1->x() * this->v2->z()),
                                (this->v1->x() * this->v2->y()) - (this->v1->y() * this->v2->x()) );

        if (expectedVector != *this->v1 % *this->v2) {
            this->result->append("Vector3Test::vectorOps -> Vector3::operator% -> Cross product result incorrect.");
            this->result->append("Result was : " + (*this->v1 % *this->v2).toString());
            this->result->append("Expected cross product result is " + expectedVector.toString());
            this->result->setFail();
        }


        // Unit Vector and normalization
        Vector3 v = *this->v1 + *this->v2 * 5.2f;
        if (v.unitVector() != v / v.magnitude()) {
            this->result->append("Vector3Test::vectorOps -> Vector3::unitVector() -> Unit Vector result incorrect.");
            this->result->append("Result was : " + v.unitVector().toString());
            this->result->append("Expected unit Vector result is " + v.toString());
            this->result->setFail();
        }

        Vector3 expectedNormalized = v.unitVector();
        v.normalize();
        if (v != expectedNormalized) {
            this->result->append("Vector3::vectorOps -> Vector3::normalize() -> Normalized result incorrect");
            this->result->append("Result was : " + v.toString());
            this->result->append("Expected normalized result is " + expectedNormalized.toString());
            this->result->setFail();
        }
    }

} // pee