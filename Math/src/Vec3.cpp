//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{

    // ============================
    // Big Four
    // ============================

    Vec3::Vec3()
        :_vx(0), _vy(0), _vz(0)
    {
    }

    Vec3::Vec3(const Vec3& inV)
    {
        this->_vx = inV._vx;
        this->_vy = inV._vy;
        this->_vz = inV._vz;
    }

    Vec3& Vec3::operator=(const Vec3& v)
    {
        if (this == &v)
        {
            return *this;
        }

        this->_vx = v._vx;
        this->_vy = v._vy;
        this->_vz = v._vz;

        return *this;
    }

    Vec3::~Vec3()
    {
    }

    // ============================
    // Constructors
    // ============================

    Vec3::Vec3(const float in_x, const float in_y, const float in_z)
        :_vx(in_x), _vy(in_y), _vz(in_z)
    {
    }


    // ============================
    // Brackets
    // ============================

    float& Vec3::operator[] (const x_enum) 
    {
        return this->_vx;
    }

    float& Vec3::operator[] (const y_enum)
    {
        return this->_vy;
    }

    float& Vec3::operator[] (const z_enum)
    {
        return this->_vz;
    }

    float Vec3::operator[](const x_enum) const
    {
        return this->_vx;
    }

    float Vec3::operator[](const y_enum) const
    {
        return this->_vy;
    }
    float Vec3::operator[](const z_enum) const
    {
        return this->_vz;
    }


    // ============================
    // Accessors
    // ============================

    float Vec3::x() const
    {
        return this->_vx;
    }
    float Vec3::y() const
    {
        return this->_vy;
    }
    float Vec3::z() const
    {
        return this->_vz;
    }


    // ============================
    // Setters
    // ============================

    void Vec3::set(const float inX, const float inY, const float inZ)
    {
        this->_vx = inX;
        this->_vy = inY;
        this->_vz = inZ;
    }

    void Vec3::set(const Vec3& A)
    {
        this->_vx = A._vx;
        this->_vy = A._vy;
        this->_vz = A._vz;
    }

    void Vec3::set(const Vec4& A)
    {
        this->_vx = A._vx;
        this->_vy = A._vy;
        this->_vz = A._vz;
    }

    void Vec3::x(const float v)
    {
        this->_vx = v;
    }

    void Vec3::y(const float v)
    {
        this->_vy = v;
    }

    void Vec3::z(const float v)
    {
        this->_vz = v;
    }

    // ============================
    // Operators
    // ============================

    // ******* Addition ******* //

    Vec3 Vec3::operator+(void) const
    {
        return Vec3(this->_vx, this->_vy, this->_vz);
    }

    Vec3 Vec3::operator+(const Vec3& inV) const
    {
        return Vec3(this->_vx + inV._vx, this->_vy + inV._vy, this->_vz + inV._vz);
    }

    Vec3& Vec3::operator+=(const Vec3& inV)
    {
        this->_vx += inV._vx;
        this->_vy += inV._vy;
        this->_vz += inV._vz;
        return *this;
    }

    // ******* Subtraction ******* //

    Vec3 Vec3::operator-(void) const
    {
        return Vec3(-1 * this->_vx, -1 * this->_vy, -1 * this->_vz);
    }

    Vec3 Vec3::operator-(const Vec3& inV) const
    {
        return Vec3(this->_vx - inV._vx, this->_vy - inV._vy, this->_vz - inV._vz);

    }

    Vec3& Vec3::operator-=(const Vec3& inV)
    {
        this->_vx -= inV._vx;
        this->_vy -= inV._vy;
        this->_vz -= inV._vz;
        return *this;
    }

    // ******* Matrix multiplication ******* //


    Vec3 Vec3::operator*(const Mat3& m) const
    {
        Vec3 res;
        Mat3 M = m.getT();

        res._vx = this->dot(Vec3(M._v0));
        res._vy = this->dot(Vec3(M._v1));
        res._vz = this->dot(Vec3(M._v2));

        return res;
    }

    Vec3& Vec3::operator*=(const Mat3& m)
    {
        Mat3 M = m.getT();  // Assuming getT() returns a transposed version of the matrix

        // Temporarily store the results to avoid modifying `this` during calculations
        float new_vx = this->dot(Vec3(M._v0));
        float new_vy = this->dot(Vec3(M._v1));
        float new_vz = this->dot(Vec3(M._v2));

        // Now update `this` directly
        this->_vx = new_vx;
        this->_vy = new_vy;
        this->_vz = new_vz;

        // Return a reference to this object
        return *this;

    }



    // ============================
    // Casting
    // ============================

    Vec3::Vec3(const Vec4& v)
    {
        this->_vx = v._vx;
        this->_vy = v._vy;
        this->_vz = v._vz;
    }

    Vec3& Vec3::operator=(const Vec4& v)
    {
        this->_vx = v._vx;
        this->_vy = v._vy;
        this->_vz = v._vz;
        return *this;
    }


    // ============================
    // Scaling
    // ============================

    Vec3 Vec3::operator*(const float scale) const
    {
        return Vec3(scale * this->_vx, scale * this->_vy, scale * this->_vz);
    }

    Vec3& Vec3::operator*=(const float scale)
    {
        this->_vx *= scale;
        this->_vy *= scale;
        this->_vz *= scale;
        return *this;
    }

    Vec3 operator*(const float scale, const Vec3& inV)
    {
        return Vec3(scale * inV._vx, scale * inV._vy, scale * inV._vz);
    }


    // ============================
    // Utility functions
    // ============================

    Vec3& Vec3::norm(void)
    {
        float magnitude = this->magnitude();
        if (magnitude == 0)
        {
            this->_vx = 0;
            this->_vy = 0;
            this->_vz = 0;
        }

        this->_vx = _vx / magnitude;
        this->_vy = _vy / magnitude;
        this->_vz = _vz / magnitude;
        return *this;
    }

    Vec3 Vec3::getNorm(void) const
    {
        float magnitude = this->magnitude();
        if (magnitude == 0)
        {
            return Vec3(0, 0, 0); // Handle divide by zero by returning zero vector
        }
        return Vec3(_vx / magnitude, _vy / magnitude, _vz / magnitude);
    }

    float Vec3::dot(const Vec3& vIn) const
    {
        return
            this->_vx * vIn._vx +
            this->_vy * vIn._vy +
            this->_vz * vIn._vz;
    }

    Vec3 Vec3::cross(const Vec3& vIn) const
    {

        return Vec3(
            this->_vy * vIn._vz - this->_vz * vIn._vy,  
            this->_vz * vIn._vx - this->_vx * vIn._vz,  
            this->_vx * vIn._vy - this->_vy * vIn._vx   
        );
    }

    Vec3Proxy Vec3::len(void) const
    {
        return Vec3Proxy(this->_vx, this->_vy, this->_vz);
    }

    float Vec3::getAngle(const Vec3& vIn) const
    {
        float magA = this->magnitude();
        float magB = vIn.magnitude();

        if (magA == 0 || magB == 0) {
            return 0.0f; // Return 0 if either vector is a zero vector
        }

        float dotProduct = this->dot(vIn);
        float cosTheta = dotProduct / (magA * magB);

        // Clamp the cosine value to the interval [-1, 1] to avoid numerical issues
        cosTheta = std::max(-1.0f, std::min(1.0f, cosTheta));

        return std::acos(cosTheta); // Return the angle in radians
    }

    float Vec3::magnitude() const
    {
        return Trig::sqrt(_vx * _vx + _vy * _vy + _vz * _vz);
    }

    // ============================
    // Comparison
    // ============================

    bool Vec3::isEqual(const Vec3& v, const float epsilon) const
    {
        if (fabs(this->_vx - v._vx) > epsilon)
        {
            return false;
        }
        if (fabs(this->_vy - v._vy) > epsilon)
        {
            return false;
        }
        if (fabs(this->_vz - v._vz) > epsilon)
        {
            return false;
        }

        return true; // if passed all checks, they are equal
    }

    bool Vec3::isZero(const float epsilon) const
    {
        return (fabs(_vx) <= epsilon) &&
            (fabs(_vy) <= epsilon) &&
            (fabs(_vz) <= epsilon);
    }

}

//--- End of File ---
