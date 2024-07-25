//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{

	// ============================
	// Big Four
	// ============================

	Mat3::Mat3()
	:_m0(0), _m1(0), _m2(0), _m3(0),
	_m4(0), _m5(0), _m6(0), _m7(0),
	_m8(0), _m9(0), _m10(0), _m11(0),
	_m12(0), _m13(0), _m14(0), _m15(1)
	{
	}

	Mat3& Mat3::operator=(const Mat3& A)
	{
		if (this == &A)
		{
			return *this;
		}

		this->_v0 = A._v0;
		this->_v1 = A._v1;
		this->_v2 = A._v2;
		this->_v3 = A._v3;

		return *this;
	}

	Mat3::Mat3(const Mat3& tM)
	{
		this->_v0 = tM._v0;
		this->_v1 = tM._v1;
		this->_v2 = tM._v2;
		this->_v3 = tM._v3;
	}

	Mat3::~Mat3()
	{
	}

	// ============================
	// Constructors
	// ============================

	Mat3::Mat3(const Vec3& tV0, const Vec3& tV1, const Vec3& tV2)
		:_m12(0), _m13(0), _m14(0), _m15(1)
	{
		this->_v0 = Vec4(tV0, 0);
		this->_v1 = Vec4(tV1, 0);
		this->_v2 = Vec4(tV2, 0);
	}

	Mat3::Mat3(const Mat4& m)
		:/*_m3(0), _m7(0), _m11(0),*/ _m12(0), _m13(0), _m14(0), _m15(1)
	{
		this->_v0 = m._v0;
		this->_m3 = 0; // Set value in last row to zero for conversion

		this->_v1 = m._v1;
		this->_m7 = 0;

		this->_v2 = m._v2;
		this->_m11 = 0;
	}

	Mat3::Mat3(const Special type)
	{
		if (type == Special::Identity)
		{
			Vec3 v0(1.0f, 0.0f, 0.0f);
			Vec3 v2(0.0f, 1.0f, 0.0f);
			Vec3 v3(0.0f, 0.0f, 1.0f);
			this->set(v0, v2, v3);
		}
		else
		{
			Vec3 v0(0.0f, 0.0f, 0.0f);
			Vec3 v2(0.0f, 0.0f, 0.0f);
			Vec3 v3(0.0f, 0.0f, 0.0f);
			this->set(v0, v2, v3);
		}
	}



	// ============================
	// Setters
	// ============================

	void Mat3::set(const Mat3& mIn)
	{
		this->_v0 = mIn._v0;

		this->_v1 = mIn._v1;

		this->_v2 = mIn._v2;
	}

	void Mat3::set(const Special type)
	{
		if (type == Special::Identity)
		{
			Vec3 v0(1.0f, 0.0f, 0.0f);
			Vec3 v2(0.0f, 1.0f, 0.0f);
			Vec3 v3(0.0f, 0.0f, 1.0f);
			this->set(v0, v2, v3);
		}
		else
		{
			Vec3 v0(0.0f, 0.0f, 0.0f);
			Vec3 v2(0.0f, 0.0f, 0.0f);
			Vec3 v3(0.0f, 0.0f, 0.0f);
			this->set(v0, v2, v3);
		}
	}

	void Mat3::set(const Row3 type, const Vec3& V)
	{
		if (type == Row3::i0)
		{
			this->_v0 = Vec4(V, 0);
		}
		else if (type == Row3::i1)
		{
			this->_v1 = Vec4(V, 0);
		}
		else
		{
			this->_v2 = Vec4(V, 0);
		}
	}


	void Mat3::set(const Vec3& V0, const Vec3& V1, const Vec3& V2)
	{
		this->_v0 = Vec4(V0, 0);
		this->_v1 = Vec4(V1, 0);
		this->_v2 = Vec4(V2, 0);
	}

	void Mat3::m0(const float v)
	{
		this->_m0 = v;
	}

	void Mat3::m1(const float v)
	{
		this->_m1 = v;
	}

	void Mat3::m2(const float v)
	{
		this->_m2 = v;
	}

	void Mat3::m4(const float v)
	{
		this->_m4 = v;
	}

	void Mat3::m5(const float v)
	{
		this->_m5 = v;
	}

	void Mat3::m6(const float v)
	{
		this->_m6 = v;
	}

	void Mat3::m8(const float v)
	{
		this->_m8 = v;
	}

	void Mat3::m9(const float v)
	{
		this->_m9 = v;
	}

	void Mat3::m10(const float v)
	{
		this->_m10 = v;
	}

	// ============================
	// Brackets
	// ============================

	float& Mat3::operator[] (const enum m0_enum)
	{
		return this->_m0;
	}

	float& Mat3::operator[] (const enum m1_enum)
	{
		return this->_m1;
	}

	float& Mat3::operator[] (const enum m2_enum)
	{
		return this->_m2;
	}

	float& Mat3::operator[] (const enum m4_enum)
	{
		return this->_m4;
	}

	float& Mat3::operator[] (const enum m5_enum)
	{
		return this->_m5;
	}

	float& Mat3::operator[](const enum m6_enum) 
	{
		return this->_m6;
	}

	float& Mat3::operator[](const enum m8_enum) 
	{
		return this->_m8;
	}

	float& Mat3::operator[](const enum m9_enum) 
	{
		return this->_m9;
	}

	float& Mat3::operator[](const enum m10_enum)
	{
		return this->_m10;
	}

	// Const version

	float Mat3::operator[](const m0_enum) const
	{
		return this->_m0;
	}

	float Mat3::operator[](const m1_enum) const
	{
		return this->_m1;
	}

	float Mat3::operator[](const m2_enum) const
	{
		return this->_m2;
	}

	float Mat3::operator[](const m4_enum) const
	{
		return this->_m4;
	}

	float Mat3::operator[](const m5_enum) const
	{
		return this->_m5;
	}

	float Mat3::operator[](const m6_enum) const
	{
		return this->_m6;
	}

	float Mat3::operator[](const m8_enum) const
	{
		return this->_m8;
	}

	float Mat3::operator[](const m9_enum) const
	{
		return this->_m9;
	}

	float Mat3::operator[](const m10_enum) const
	{
		return this->_m10;
	}



	// ============================
	// Accessors
	// ============================
	
	Vec3 Mat3::get(const Row3 type) const
	{
		if (type == Row3::i0)
		{
			return Vec3(this->_v0);
		}
		else if (type == Row3::i1)
		{
			return Vec3(this->_v1);
		}
		else
		{
			return Vec3(this->_v2);
		}
	}

	float Mat3::m0() const
	{
		return this->_m0;
	}

	float Mat3::m1() const
	{
		return this->_m1;
	}

	float Mat3::m2() const
	{
		return this->_m2;
	}

	float Mat3::m4() const
	{
		return this->_m4;
	}

	float Mat3::m5() const
	{
		return this->_m5;
	}

	float Mat3::m6() const
	{
		return this->_m6;
	}

	float Mat3::m8() const
	{
		return this->_m8;
	}

	float Mat3::m9() const
	{
		return this->_m9;
	}

	float Mat3::m10() const
	{
		return this->_m10;
	}


	// ============================
	// Operators
	// ============================

	// ******* Addition ******* //

	Mat3 Mat3::operator+(void) const
	{
		return *this; // Problematic?
	}

	Mat3 Mat3::operator+(const Mat3& A) const
	{
		Mat3 M;
		M._v0 = A._v0 + this->_v0;
		M._v1 = A._v1 + this->_v1;
		M._v2 = A._v2 + this->_v2;
		return M;
	}

	Mat3& Mat3::operator+=(const Mat3& A)
	{
		this->_v0 = A._v0 + this->_v0;
		this->_v1 = A._v1 + this->_v1;
		this->_v2 = A._v2 + this->_v2;
		return *this;
	}


	// ******* Subtraction ******* //

	Mat3 Mat3::operator-(void) const
	{
		Mat3 M;
		M._v0 = -this->_v0;
		M._v1 = -this->_v1;
		M._v2 = -this->_v2;
		return M;
	}

	Mat3 Mat3::operator-(const Mat3& A) const
	{
		Mat3 M;
		M._v0 = this->_v0 - A._v0;
		M._v1 = this->_v1 - A._v1;
		M._v2 = this->_v2 - A._v2;
		return M;
	}

	Mat3& Mat3::operator-=(const Mat3& A)
	{
		this->_v0 = this->_v0 - A._v0;
		this->_v1 = this->_v1 - A._v1;
		this->_v2 = this->_v2 - A._v2;
		return *this;
	}


	// ******* Scaling ******* //

	Mat3 Mat3::operator*(const float s) const
	{
		Mat3 M;
		M._v0 = this->_v0 * s;
		M._v1 = this->_v1 * s;
		M._v2 = this->_v2 * s;
		return M;
	}

	Mat3& Mat3::operator*=(const float scale)
	{
		this->_v0 *= scale;
		this->_v1 *= scale;
		this->_v2 *= scale;
		return *this;
	}

	Mat3 operator*(const float scale, const Mat3& A)
	{
		Mat3 M;
		M._v0 = A._v0 * scale;
		M._v1 = A._v1 * scale;
		M._v2 = A._v2 * scale;
		return M;
	}

	// ******* Multiplication ******* //

	Mat3 Mat3::operator*(const Mat3& A) const
	{
		Mat3 res;
		Mat3 M = A.getT();


		res._m0 = _v0.dot(M._v0);
		res._m1 = _v0.dot(M._v1);
		res._m2 = _v0.dot(M._v2);
		res._m3 = _v0.dot(M._v3);

		res._m4 = _v1.dot(M._v0);
		res._m5 = _v1.dot(M._v1);
		res._m6 = _v1.dot(M._v2);
		res._m7 = _v1.dot(M._v3);

		res._m8 = _v2.dot(M._v0);
		res._m9 = _v2.dot(M._v1);
		res._m10 = _v2.dot(M._v2);
		res._m11 = _v2.dot(M._v3);

		return res;
	}

	Mat3& Mat3::operator*=(const Mat3& A)
	{
		Mat3 temp;
		Mat3 M = A.getT();

		temp._m0 = this->_v0.dot(M._v0);
		temp._m1 = this->_v0.dot(M._v1);
		temp._m2 = this->_v0.dot(M._v2);
		temp._m3 = this->_v0.dot(M._v3);

		temp._m4 = this->_v1.dot(M._v0);
		temp._m5 = this->_v1.dot(M._v1);
		temp._m6 = this->_v1.dot(M._v2);
		temp._m7 = this->_v1.dot(M._v3);

		temp._m8 = this->_v2.dot(M._v0);
		temp._m9 = this->_v2.dot(M._v1);
		temp._m10 = this->_v2.dot(M._v2);
		temp._m11 = this->_v2.dot(M._v3);

		*this = temp;
		return *this;
	}

	// ============================
	// Comparison functions
	// ============================

	bool Mat3::isEqual(const Mat3& A, const float epsilon) const
	{
		if (!this->_v0.isEqual(A._v0, epsilon))
		{
			return false;
		}

		if (!this->_v1.isEqual(A._v1, epsilon))
		{
			return false;
		}

		if (!this->_v2.isEqual(A._v2, epsilon))
		{
			return false;
		}

		return true;
	}

	bool Mat3::isIdentity(const float epsilon) const
	{
		return this->isEqual(Mat3(Special::Identity), epsilon);
	}

	// ============================
	// Utility functions
	// ============================
	
	float Mat3::det() const
	{
		
		return
			(_m0 * _m5 * _m10) + (_m1 * _m6 * _m8) +
			(_m2 * _m4 * _m9) - (_m2 * _m5 * _m8) -
			(_m1 * _m4 * _m10) - (_m0 * _m6 * _m9);

	}

	Mat3& Mat3::T(void)
	{
		Mat3 M = this->getT();
		this->set(M);
		return *this;
	}

	Mat3 Mat3::getT(void) const
	{
		Mat3 M;

		// First column
		M._m0 = this->_m0;
		M._m4 = this->_m1;
		M._m8 = this->_m2;

		// Second column
		M._m1 = this->_m4;
		M._m5 = this->_m5;
		M._m9 = this->_m6;

		// Third column
		M._m2 = this->_m8;
		M._m6 = this->_m9;
		M._m10 = this->_m10;
		
		return M;
	}

	Mat3 Mat3::getInv(void) const
	{
		Mat3 M(*this);
		float determinant = M.det();
		assert(determinant != 0);
		float invDeterminate = 1.0f / determinant;
		M = invDeterminate * M.getAdjugate();
		return M;
	}

	Mat3& Mat3::inv(void)
	{
		float determinant = this->det();
		assert(determinant != 0); 

		float invDeterminate = 1.0f / determinant;
		*this = invDeterminate * this->getAdjugate(); 
		return *this; 
	}

	Mat3 Mat3::getAdjugate() const
	{
		Mat3 adj;

		// Get cofactors and transpose
		adj._m0 = (_m5 * _m10 - _m6 * _m9);
		adj._m4 = -(_m4 * _m10 - _m6 * _m8);
		adj._m8 = (_m4 * _m9 - _m5 * _m8);

		adj._m1 = -(_m1 * _m10 - _m2 * _m9);
		adj._m5 = (_m0 * _m10 - _m2 * _m8);
		adj._m9 = -(_m0 * _m9 - _m1 * _m8);

		adj._m2 = (_m1 * _m6 - _m2 * _m5);
		adj._m6 = -(_m0 * _m6 - _m2 * _m4);
		adj._m10 = (_m0 * _m5 - _m1 * _m4);

		return adj;

	}

}

// ---  End of File ---
