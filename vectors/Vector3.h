//
// Copyright 2025 Connor Petri <conn.petri@gmail.com>
// Physics Educational Experiment
//

#pragma once

namespace pee
{
    class Vector3 {
    public:
        // Constructors
        explicit Vector3(double x = 0.0, double y = 0.0, double z = 0.0);
        explicit Vector3(int x = 0, int y = 0, int z = 0);

        ~Vector3();

        // Properties
        double x() const;
        double y() const;
        virtual double z() const;
        double magnitude() const;
        double mag() const { return this->magnitude(); }

        // TODO: Account for the range of the arccos function in the angle methods
        // Angles
        double angleAlpha() const; // Angle alpha in radians
        double angleAlphaDeg() const; // Angle alpha in degrees
        double angleBeta() const; // Angle beta in radians
        double angleBetaDeg() const; // Angle Beta in Degrees
        virtual double angleGamma() const; // Angle gamma in radians
        virtual double angleGammaDeg() const; // Angle gamma in degrees

        double angleX() const { return this->angleAlpha(); } // Angle from the positive x-axis in radians
        double angleXDeg() const { return this->angleAlphaDeg(); } // Angle from the positive x-axis in degrees
        double angleY() const { return this->angleBeta(); } // Angle from the positive y-axis in radians
        double angleYDeg() const { return this->angleBetaDeg(); } // Angle from the positive y-axis in degrees
        virtual double angleZ() const { return this->angleGamma(); } // Angle from the positive z-axis in radians
        virtual double angleZDeg() const { return this->angleGammaDeg(); } // Angle from the positive z-axis in degrees

        // Operations
        double dot(const Vector3 &other) const;
        Vector3 cross(const Vector3 &other) const;
        Vector3 unitVector() const; // returns a unit vector in the direction of this one
        void normalize(); // normalizes this vector

        // Operator Overloads
        Vector3 operator+(const Vector3 &other) const;
        Vector3 operator-(const Vector3 &other) const;

        Vector3 operator*(double other) const; // Scalar Multiplication
        Vector3 operator*(int other) const; // Scalar Multiplication

        double operator*(const Vector3 &other) const; // Dot product
        Vector3 operator%(const Vector3 &other) const; // Cross product

        Vector3 operator/(double other) const; // Scalar Division
        Vector3 operator/(int other) const; // Scalar Division

        Vector3& operator=(const Vector3 &other);

        // Boolean Operator Overloads
        bool operator==(const Vector3 &other) const;
        bool operator!=(const Vector3 &other) const;


    protected:
        double *_x;
        double *_y;
        double *_z;
    };
}
