//
// Copyright 2025 Connor Petri <conn.petri@gmail.com>
// Physics Educational Experiment
//

#pragma once

#include <string>

namespace pee
{
    class Vector3 {
    public:
        // Constructors
        explicit Vector3(float x = 0.0, float y = 0.0, float z = 0.0);
        explicit Vector3(int x = 0, int y = 0, int z = 0);
        Vector3(const Vector3 &v);
        Vector3(float v[3]);

        ~Vector3();

        std::string toString() const;

        // Properties
        float x() const;
        float y() const;
        virtual float z() const;
        float magnitude() const;
        float mag() const { return this->magnitude(); }

        // TODO: Account for the range of the arccos function in the angle methods
        // Angles
        float angleAlpha() const; // Angle alpha in radians
        float angleAlphaDeg() const; // Angle alpha in degrees
        float angleBeta() const; // Angle beta in radians
        float angleBetaDeg() const; // Angle Beta in Degrees
        virtual float angleGamma() const; // Angle gamma in radians
        virtual float angleGammaDeg() const; // Angle gamma in degrees

        float angleX() const { return this->angleAlpha(); } // Angle from the positive x-axis in radians
        float angleXDeg() const { return this->angleAlphaDeg(); } // Angle from the positive x-axis in degrees
        float angleY() const { return this->angleBeta(); } // Angle from the positive y-axis in radians
        float angleYDeg() const { return this->angleBetaDeg(); } // Angle from the positive y-axis in degrees
        virtual float angleZ() const { return this->angleGamma(); } // Angle from the positive z-axis in radians
        virtual float angleZDeg() const { return this->angleGammaDeg(); } // Angle from the positive z-axis in degrees

        // Operations
        float dot(const Vector3 &other) const;
        Vector3 cross(const Vector3 &other) const;
        Vector3 unitVector() const; // returns a unit vector in the direction of this one
        void normalize(); // normalizes this vector

        // Operator Overloads
        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator-(const Vector3 &other) const;

        Vector3 operator*(float other) const; // Scalar Multiplication
        Vector3 operator*(int other) const; // Scalar Multiplication

        float operator*(const Vector3 &other) const; // Dot product
        Vector3 operator%(const Vector3 &other) const; // Cross product

        Vector3 operator/(float other) const; // Scalar Division
        Vector3 operator/(int other) const; // Scalar Division

        Vector3& operator=(const Vector3 &other);

        // Boolean Operator Overloads
        bool operator==(const Vector3 &other) const;
        bool operator!=(const Vector3 &other) const;


    protected:
        float *_x = new float;
        float *_y = new float;
        float *_z = new float;
    };
}
