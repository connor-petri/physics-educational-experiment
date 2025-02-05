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

        ~Vector3();

        virtual std::string toString() const;

        // Properties
        float x() const;
        void x(float x);

        float y() const;
        void y(float y);

        virtual float z() const;
        virtual void z(float z);

        float magnitude() const;
        float mag() const { return this->magnitude(); }

        // Add trig functions when needed

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
