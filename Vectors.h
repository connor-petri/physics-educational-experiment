//
// Copywrite 2025 Connor Petri <conn.petri@gmail.com>
// Physics Educational Experiment
//

#ifndef PHYSICS_EDUCATIONAL_EXPERIMENT_VECTORS_H
#define PHYSICS_EDUCATIONAL_EXPERIMENT_VECTORS_H

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

        // Angles
        double angleAlpha() const; // Angle alpha in radians
        double angleAlphaDeg() const; // Angle alpha in degrees
        double angleBeta() const; // Angle beta in radians
        double angleBetaDeg(); // Angle Beta in Degrees
        virtual double angleGamma() const; // Angle gamma in radians
        virtual double angleGammaDeg() const; // Angle gamma in degrees

        double angleX() const { return this->angleAlpha(); } // Angle from the positive x-axis in radians
        double angleXDeg() const { return this->angleAlphaDeg(); } // Angle from the positive x-axis in degrees
        double angleY() const { return this->angleBeta(); } // Angle from the positive y-axis in radians
        double angleYDeg() const { return this->angleBetaDeg(); } // Angle from the positive y-axis in degrees
        double angleZ() const { return this->angleGamma(); } // Angle from the positive z-axis in radians
        double angleZDeg() const { return this->angleGammaDeg(); } // Angle from the positive z-axis in degrees

        // Operations
        double dot(Vector3 &other) const;
        Vector3 cross(Vector3 &other) const;
        Vector3 unitVector(Vector3 &other) const;
        void normalize();

        // Operator Overloads
        Vector3& operator+(Vector3 &other) const;
        Vector3& operator-(Vector3 &other) const;

        Vector3& operator*(int other) const; // Scalar Multiplication
        Vector3& operator*(double other) const;

        double operator*(Vector3 &other) const { return this->dot(other); } // Dot product
        Vector3& operator%(Vector3 &other) const { return this->cross(other); } // Cross product

        void operator=(Vector3 &other) const;

        // TODO: Boolean operators

    protected:
        double *_x;
        double *_y;
        double *_z;

        Vector3 cross(Vector3 &other);
    };


    class Vector2 : Vector3 {
    public:
        // Constructors
        Vector2(double x, double y);
        Vector2(int x, int y);

        ~Vector2();

        double z() const override;

        double angleGamma() const override;
        double angleGammaDeg() const override;

    protected:
        const double *_z;
    };
}

#endif //PHYSICS_EDUCATIONAL_EXPERIMENT_VECTORS_H
