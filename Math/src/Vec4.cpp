//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
    
    // ============================
    // Big Four
    // ============================


    Vec4::Vec4()
        :_vx(0), _vy(0), _vz(0), _vw(0)
    {
    }

    Vec4::Vec4(const Vec4& inV)
    {
        this->_vx = inV._vx;
        this->_vy = inV._vy;
        this->_vz = inV._vz;
        this->_vw = inV._vw;
    }

    Vec4& Vec4::operator=(const Vec4& v)
    {
        if (this == &v)
        {
            return *this;
        }

        this->_vx = v._vx;
        this->_vy = v._vy;
        this->_vz = v._vz;
        this->_vw = v._vw;

        return *this;
    }

    Vec4::~Vec4()
    {
    }

    // ============================
    // Constructors
    // ============================


    Vec4::Vec4(const float in_x, const float in_y, const float in_z, const float in_w)
        :_vx(in_x), _vy(in_y), _vz(in_z), _vw(in_w)
    {

    }


    // ============================
    // Brackets
    // ============================

    float& Vec4::operator[] (const x_enum)
    {
        return this->_vx;
    }

    float& Vec4::operator[] (const y_enum)
    {
        return this->_vy;
    }

    float& Vec4::operator[] (const z_enum)
    {
        return this->_vz;
    }

    float& Vec4::operator[] (const w_enum)
    {
        return this->_vw;
    }

    float Vec4::operator[](const x_enum) const
    {
        return this->_vx;
    }

    float Vec4::operator[](const y_enum) const
    {
        return this->_vy;
    }
    float Vec4::operator[](const z_enum) const
    {
        return this->_vz;
    }

    float Vec4::operator[](const w_enum) const
    {
        return this->_vw;
    }



    // ============================
    // Accessors
    // ============================

    float Vec4::x() const
    {
        return this->_vx;
    }
    float Vec4::y() const
    {
        return this->_vy;
    }
    float Vec4::z() const
    {
        return this->_vz;
    }
    float Vec4::w() const
    {
        return this->_vw;
    }
    

    // ============================
    // Setters
    // ============================

    void Vec4::x(const float v)
    {
        this->_vx = v;
    }

    void Vec4::y(const float v)
    {
        this->_vy = v;
    }

    void Vec4::z(const float v)
    {
        this->_vz = v;
    }

    void Vec4::w(const float v)
    {
        this->_vw = v;
    }

    void Vec4::set(const float inX, const float inY, const float inZ, const float inW)
    {
        this->_vx = inX;
        this->_vy = inY;
        this->_vz = inZ;
        this->_vw = inW;
    }

    void Vec4::set(const Vec4& A)
    {
        this->_vx = A._vx;
        this->_vy = A._vy;
        this->_vz = A._vz;
        this->_vw = A._vw;
    }

    void Vec4::set(const Vec3& v, const float w)
    {
        this->_vx = v._vx;
        this->_vy = v._vy;
        this->_vz = v._vz;
        this->_vw = w;
    }

    // ============================
    // Operators
    // ============================

    // ******* Addition ******* //

    Vec4 Vec4::operator+(void) const
    {
        return Vec4(this->_vx, this->_vy, this->_vz, this->_vw);
    }

    Vec4 Vec4::operator+(const Vec4& inV) const
    {
        return Vec4(this->_vx + inV._vx, this->_vy + inV._vy, this->_vz + inV._vz, this->_vw + inV._vw);
    }

    Vec4& Vec4::operator+=(const Vec4& inV)
    {
        this->_vx += inV._vx;
        this->_vy += inV._vy;
        this->_vz += inV._vz;
        this->_vw += inV._vw;
        return *this;
    }

    // ******* Subtraction ******* //

    Vec4 Vec4::operator-(void) const
    {
        return Vec4(-1 * this->_vx, -1 * this->_vy, -1 * this->_vz, -1 * this->_vw);
    }

    Vec4 Vec4::operator-(const Vec4& inV) const
    {
        return Vec4(this->_vx - inV._vx, this->_vy - inV._vy, this->_vz - inV._vz, this->_vw - inV._vw);
    }

    Vec4& Vec4::operator-=(const Vec4& inV)
    {
        this->_vx -= inV._vx;
        this->_vy -= inV._vy;
        this->_vz -= inV._vz;
        this->_vw -= inV._vw;
        return *this;
    }

    // ============================
    // Casting
    // ============================

    Vec4::Vec4(const Vec3& v, const float w)
    {
        this->_vx = v._vx;
        this->_vy = v._vy;
        this->_vz = v._vz;
        this->_vw = w;

    }

    // ============================
    // Scale Operators
    // ============================

    Vec4 Vec4::operator*(const float scale) const
    {
        return Vec4(scale * this->_vx, scale * this->_vy, scale * this->_vz, scale * this->_vw);
    }

    Vec4 operator*(const float scale, const Vec4& inV)
    {
        return Vec4(scale * inV._vx, scale * inV._vy, scale * inV._vz, scale * inV._vw);
    }

    Vec4& Vec4::operator*=(const float scale)
    {
        this->_vx *= scale;
        this->_vy *= scale;
        this->_vz *= scale;
        this->_vw *= scale;
        return *this;
    }

    
    // ============================
    // Matrix Multiplication
    // ============================

    Vec4 Vec4::operator*(const Mat4& m) const
    {
        Vec4 res;
        Mat4 M = m.getT();

        res._vx = this->dot(M._v0);
        res._vy = this->dot(M._v1);
        res._vz = this->dot(M._v2);
        res._vw = this->dot(M._v3);

        return res;
    }

    Vec4& Vec4::operator*=(const Mat4& m)
    {
        Vec4 temp;
        Mat4 M = m.getT();

        temp._vx = this->dot(M._v0);
        temp._vy = this->dot(M._v1);
        temp._vz = this->dot(M._v2);
        temp._vw = this->dot(M._v3);

        *this = temp;
        return *this;
    }
    
    // ============================
    // Utility Functions
    // ============================

    Vec4& Vec4::norm(void)
    {
        float magnitude = this->magnitude();
        if (magnitude == 0) 
        {
            this->_vx = 0;
            this->_vy = 0;
            this->_vz = 0;
            this->_vw = 0;
        }

        this->_vx = _vx / magnitude;
        this->_vy = _vy / magnitude;
        this->_vz = _vz / magnitude;
        this->_vw = _vw / magnitude;
        return *this;
    }

    Vec4 Vec4::getNorm(void) const
    {
        float magnitude = this->magnitude();
        if (magnitude == 0)
        {
            return Vec4(0, 0, 0, 0); // Handle divide by zero by returning zero vector
        }
        return Vec4(_vx / magnitude, _vy / magnitude, _vz / magnitude, _vw / magnitude);
    }

    float Vec4::dot(const Vec4& vIn) const
    {
        return 
            this->_vx * vIn._vx + 
            this->_vy * vIn._vy + 
            this->_vz * vIn._vz + 
            this->_vw * vIn._vw;
    }

    Vec4Proxy Vec4::len() const
    {
        return Vec4Proxy(_vx, _vy, _vz, _vw);
    }

    float Vec4::magnitude() const
    {
        return Trig::sqrt(_vx * _vx + _vy * _vy + _vz * _vz + _vw * _vw);
    }


    // ============================
    // Comparison Functions
    // ============================

    bool Vec4::isEqual(const Vec4& v, const float epsilon) const
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
        if (fabs(this->_vw - v._vw) > epsilon)
        {
            return false;
        }
        
        return true; // if passed all checks, they are equal
    }

    bool Vec4::isZero(const float epsilon) const
    {
        return (fabs(_vx) <= epsilon) &&
            (fabs(_vy) <= epsilon) &&
            (fabs(_vz) <= epsilon) &&
            (fabs(_vw) <= epsilon);
    }





}

//--- End of File ---
