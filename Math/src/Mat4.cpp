//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{
	// ============================
	// Big Four
	// ============================

	Mat4::Mat4()
		:_m0(0), _m1(0), _m2(0), _m3(0),
		_m4(0), _m5(0), _m6(0), _m7(0),
		_m8(0), _m9(0), _m10(0), _m11(0),
		_m12(0), _m13(0), _m14(0), _m15(0)
	{
	}

	Mat4& Mat4::operator=(const Mat4& A)
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

	Mat4::Mat4(const Mat4& tM)
	{
		this->_v0 = tM._v0;
		this->_v1 = tM._v1;
		this->_v2 = tM._v2;
		this->_v3 = tM._v3;
	}

	Mat4::~Mat4()
	{
	}

	// ============================
	// Constructors
	// ============================

	Mat4::Mat4(const Vec4& tV0, const Vec4& tV1, const Vec4& tV2, const Vec4& tV3)
	{
		this->_v0 = tV0;
		this->_v1 = tV1;
		this->_v2 = tV2;
		this->_v3= tV3;
	}


	Mat4::Mat4(const Special type)
	{
		if (type == Special::Identity)
		{
			this->_v0 = Vec4(1.0f, 0.0f, 0.0f, 0.0f);
			this->_v1 = Vec4(0.0f, 1.0f, 0.0f, 0.0f);
			this->_v2 = Vec4(0.0f, 0.0f, 1.0f, 0.0f);
			this->_v3 = Vec4(0.0f, 0.0f, 0.0f, 1.0f);

			
		}
		else
		{
			this->_v0 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
			this->_v1 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
			this->_v2 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
			this->_v3 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
		}
	}



	// ============================
	// Setters
	// ============================

	void Mat4::set(const Mat4& mIn)
	{
		this->_v0 = mIn._v0;
		this->_v1 = mIn._v1;
		this->_v2 = mIn._v2;
		this->_v3 = mIn._v3;
	}

	void Mat4::set(const Special type)
	{
		if (type == Special::Identity)
		{
			this->_v0 = Vec4(1.0f, 0.0f, 0.0f, 0.0f);
			this->_v1 = Vec4(0.0f, 1.0f, 0.0f, 0.0f);
			this->_v2 = Vec4(0.0f, 0.0f, 1.0f, 0.0f);
			this->_v3 = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
		}
		else
		{
			this->_v0 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
			this->_v1 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
			this->_v2 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
			this->_v3 = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
		}
	}

	void Mat4::set(const Row4 type, const Vec4& V)
	{
		if (type == Row4::i0)
		{
			this->_v0 = V;
		}
		else if (type == Row4::i1)
		{
			this->_v1 = V;
		}
		else if (type == Row4::i2)
		{
			this->_v2 = V;
		}
		else
		{
			this->_v3 = V;
		}
	}


	void Mat4::set(const Vec4& V0, const Vec4& V1, const Vec4& V2, const Vec4& V3)
	{
		this->_v0 = Vec4(V0);
		this->_v1 = Vec4(V1);
		this->_v2 = Vec4(V2);
		this->_v3 = Vec4(V3);
	}

	void Mat4::m0(const float v)
	{
		this->_m0 = v;
	}

	void Mat4::m1(const float v)
	{
		this->_m1 = v;
	}

	void Mat4::m2(const float v)
	{
		this->_m2 = v;
	}

	void Mat4::m3(const float v)
	{
		this->_m3 = v;
	}

	void Mat4::m4(const float v)
	{
		this->_m4 = v;
	}

	void Mat4::m5(const float v)
	{
		this->_m5 = v;
	}

	void Mat4::m6(const float v)
	{
		this->_m6 = v;
	}

	void Mat4::m7(const float v)
	{
		this->_m7 = v;
	}

	void Mat4::m8(const float v)
	{
		this->_m8 = v;
	}

	void Mat4::m9(const float v)
	{
		this->_m9 = v;
	}

	void Mat4::m10(const float v)
	{
		this->_m10 = v;
	}

	void Mat4::m11(const float v)
	{
		this->_m11 = v;
	}

	void Mat4::m12(const float v)
	{
		this->_m12 = v;
	}

	void Mat4::m13(const float v)
	{
		this->_m13 = v;
	}

	void Mat4::m14(const float v)
	{
		this->_m14 = v;
	}

	void Mat4::m15(const float v)
	{
		this->_m15 = v;
	}


	// ============================
	// Brackets
	// ============================

	float& Mat4::operator[] (const enum m0_enum)
	{
		return this->_m0;
	}

	float& Mat4::operator[] (const enum m1_enum)
	{
		return this->_m1;
	}

	float& Mat4::operator[] (const enum m2_enum)
	{
		return this->_m2;
	}

	float& Mat4::operator[] (const enum m3_enum)
	{
		return this->_m3;
	}

	float& Mat4::operator[] (const enum m4_enum)
	{
		return this->_m4;
	}

	float& Mat4::operator[] (const enum m5_enum)
	{
		return this->_m5;
	}

	float& Mat4::operator[](const enum m6_enum)
	{
		return this->_m6;
	}

	float& Mat4::operator[] (const enum m7_enum)
	{
		return this->_m7;
	}

	float& Mat4::operator[](const enum m8_enum)
	{
		return this->_m8;
	}

	float& Mat4::operator[](const enum m9_enum)
	{
		return this->_m9;
	}

	float& Mat4::operator[](const enum m10_enum)
	{
		return this->_m10;
	}

	float& Mat4::operator[] (const enum m11_enum)
	{
		return this->_m11;
	}

	float& Mat4::operator[] (const enum m12_enum)
	{
		return this->_m12;
	}

	float& Mat4::operator[] (const enum m13_enum)
	{
		return this->_m13;
	}

	float& Mat4::operator[] (const enum m14_enum)
	{
		return this->_m14;
	}

	float& Mat4::operator[] (const enum m15_enum)
	{
		return this->_m15;
	}

	// Const version

	float Mat4::operator[](const m0_enum) const
	{
		return this->_m0;
	}

	float Mat4::operator[](const m1_enum) const
	{
		return this->_m1;
	}

	float Mat4::operator[](const m2_enum) const
	{
		return this->_m2;
	}

	float Mat4::operator[](const m3_enum) const
	{
		return this->_m3;
	}

	float Mat4::operator[](const m4_enum) const
	{
		return this->_m4;
	}

	float Mat4::operator[](const m5_enum) const
	{
		return this->_m5;
	}

	float Mat4::operator[](const m6_enum) const
	{
		return this->_m6;
	}

	float Mat4::operator[](const m7_enum) const
	{
		return this->_m7;
	}

	float Mat4::operator[](const m8_enum) const
	{
		return this->_m8;
	}

	float Mat4::operator[](const m9_enum) const
	{
		return this->_m9;
	}

	float Mat4::operator[](const m10_enum) const
	{
		return this->_m10;
	}

	float Mat4::operator[](const m11_enum) const
	{
		return this->_m11;
	}

	float Mat4::operator[](const m12_enum) const
	{
		return this->_m12;
	}

	float Mat4::operator[](const m13_enum) const
	{
		return this->_m13;
	}

	float Mat4::operator[](const m14_enum) const
	{
		return this->_m14;
	}

	float Mat4::operator[](const m15_enum) const
	{
		return this->_m15;
	}


	// ============================
	// Accessors
	// ============================

	Vec4 Mat4::get(const Row4 type) const
	{
		if (type == Row4::i0)
		{
			return this->_v0;
		}
		else if (type == Row4::i1)
		{
			return this->_v1;
		}
		else if (type == Row4::i2)
		{
			return this->_v2;
		}
		else
		{
			return this->_v3;
		}
	}

	float Mat4::m0() const
	{
		return this->_m0;
	}

	float Mat4::m1() const
	{
		return this->_m1;
	}

	float Mat4::m2() const
	{
		return this->_m2;
	}

	float Mat4::m3() const
	{
		return this->_m3;
	}

	float Mat4::m4() const
	{
		return this->_m4;
	}

	float Mat4::m5() const
	{
		return this->_m5;
	}

	float Mat4::m6() const
	{
		return this->_m6;
	}

	float Mat4::m7() const
	{
		return this->_m7;
	}

	float Mat4::m8() const
	{
		return this->_m8;
	}

	float Mat4::m9() const
	{
		return this->_m9;
	}

	float Mat4::m10() const
	{
		return this->_m10;
	}

	float Mat4::m11() const
	{
		return this->_m11;
	}

	float Mat4::m12() const
	{
		return this->_m12;
	}

	float Mat4::m13() const
	{
		return this->_m13;
	}

	float Mat4::m14() const
	{
		return this->_m14;
	}

	float Mat4::m15() const
	{
		return this->_m15;
	}


	// ============================
	// Utility Functions
	// ============================

	float Mat4::det() const
	{
		float det;

		// Compute the determinant using cofactor expansion on the first row
		det = _m0 * (
			_m5 * (_m10 * _m15 - _m11 * _m14) -
			_m6 * (_m9 * _m15 - _m11 * _m13) +
			_m7 * (_m9 * _m14 - _m10 * _m13)
			);
		det -= _m1 * (
			_m4 * (_m10 * _m15 - _m11 * _m14) -
			_m6 * (_m8 * _m15 - _m11 * _m12) +
			_m7 * (_m8 * _m14 - _m10 * _m12)
			);
		det += _m2 * (
			_m4 * (_m9 * _m15 - _m11 * _m13) -
			_m5 * (_m8 * _m15 - _m11 * _m12) +
			_m7 * (_m8 * _m13 - _m9 * _m12)
			);
		det -= _m3 * (
			_m4 * (_m9 * _m14 - _m10 * _m13) -
			_m5 * (_m8 * _m14 - _m10 * _m12) +
			_m6 * (_m8 * _m13 - _m9 * _m12)
			);

		return det;
	}

	Mat4& Mat4::T(void)
	{
		Mat4 M = this->getT();
		this->set(M);
		return *this;
	}

	Mat4 Mat4::getT(void) const
	{
		Mat4 M;

		// First column
		M._m0 = this->_m0;
		M._m4 = this->_m1;
		M._m8 = this->_m2;
		M._m12 = this->_m3;

		// Second column
		M._m1 = this->_m4;
		M._m5 = this->_m5;
		M._m9 = this->_m6;
		M._m13 = this->_m7;

		// Third column
		M._m2 = this->_m8;
		M._m6 = this->_m9;
		M._m10 = this->_m10;
		M._m14 = this->_m11;

		// Fourth column
		M._m3 = this->_m12;
		M._m7 = this->_m13;
		M._m11 = this->_m14;
		M._m15 = this->_m15;

		return M;
	}

	// ******* Inverse ******* //

	Mat4 Mat4::getInv(void) const
	{
		Mat4 M(*this);
		float determinant = M.det();
		assert(determinant != 0);
		float invDeterminate = 1.0f / determinant;
		M = invDeterminate * M.getAdjugate();
		return M;
	}

	Mat4& Mat4::inv(void)
	{
		float determinant = this->det();
		assert(determinant != 0);

		float invDeterminate = 1.0f / determinant;
		*this = invDeterminate * this->getAdjugate();
		return *this;
	}

	Mat4 Mat4::getAdjugate() const
	{
		Mat4 adj;

		// Compute each cofactor, manually compute determinants of the 3x3 submatrices, and transpose
		adj._m0 = _m5 * _m10 * _m15 + _m6 * _m11 * _m13 + _m7 * _m9 * _m14 - _m7 * _m10 * _m13 - _m6 * _m9 * _m15 - _m5 * _m11 * _m14;
		adj._m1 = -(_m1 * _m10 * _m15 + _m2 * _m11 * _m13 + _m3 * _m9 * _m14 - _m3 * _m10 * _m13 - _m2 * _m9 * _m15 - _m1 * _m11 * _m14);
		adj._m2 = _m1 * _m6 * _m15 + _m2 * _m7 * _m13 + _m3 * _m5 * _m14 - _m3 * _m6 * _m13 - _m2 * _m5 * _m15 - _m1 * _m7 * _m14;
		adj._m3 = -(_m1 * _m6 * _m11 + _m2 * _m7 * _m9 + _m3 * _m5 * _m10 - _m3 * _m6 * _m9 - _m2 * _m5 * _m11 - _m1 * _m7 * _m10);

		adj._m4 = -(_m4 * _m10 * _m15 + _m6 * _m11 * _m12 + _m7 * _m8 * _m14 - _m7 * _m10 * _m12 - _m6 * _m8 * _m15 - _m4 * _m11 * _m14);
		adj._m5 = _m0 * _m10 * _m15 + _m2 * _m11 * _m12 + _m3 * _m8 * _m14 - _m3 * _m10 * _m12 - _m2 * _m8 * _m15 - _m0 * _m11 * _m14;
		adj._m6 = -(_m0 * _m6 * _m15 + _m2 * _m7 * _m12 + _m3 * _m4 * _m14 - _m3 * _m6 * _m12 - _m2 * _m4 * _m15 - _m0 * _m7 * _m14);
		adj._m7 = _m0 * _m6 * _m11 + _m2 * _m7 * _m8 + _m3 * _m4 * _m10 - _m3 * _m6 * _m8 - _m2 * _m4 * _m11 - _m0 * _m7 * _m10;

		adj._m8 = _m4 * _m9 * _m15 + _m5 * _m11 * _m12 + _m7 * _m8 * _m13 - _m7 * _m9 * _m12 - _m5 * _m8 * _m15 - _m4 * _m11 * _m13;
		adj._m9 = -(_m0 * _m9 * _m15 + _m1 * _m11 * _m12 + _m3 * _m8 * _m13 - _m3 * _m9 * _m12 - _m1 * _m8 * _m15 - _m0 * _m11 * _m13);
		adj._m10 = _m0 * _m5 * _m15 + _m1 * _m7 * _m12 + _m3 * _m4 * _m13 - _m3 * _m5 * _m12 - _m1 * _m4 * _m15 - _m0 * _m7 * _m13;
		adj._m11 = -(_m0 * _m5 * _m11 + _m1 * _m7 * _m8 + _m3 * _m4 * _m9 - _m3 * _m5 * _m8 - _m1 * _m4 * _m11 - _m0 * _m7 * _m9);

		adj._m12 = -(_m4 * _m9 * _m14 + _m5 * _m10 * _m12 + _m6 * _m8 * _m13 - _m6 * _m9 * _m12 - _m5 * _m8 * _m14 - _m4 * _m10 * _m13);
		adj._m13 = _m0 * _m9 * _m14 + _m1 * _m10 * _m12 + _m2 * _m8 * _m13 - _m2 * _m9 * _m12 - _m1 * _m8 * _m14 - _m0 * _m10 * _m13;
		adj._m14 = -(_m0 * _m5 * _m14 + _m1 * _m6 * _m12 + _m2 * _m4 * _m13 - _m2 * _m5 * _m12 - _m1 * _m4 * _m14 - _m0 * _m6 * _m13);
		adj._m15 = _m0 * _m5 * _m10 + _m1 * _m6 * _m8 + _m2 * _m4 * _m9 - _m2 * _m5 * _m8 - _m1 * _m4 * _m10 - _m0 * _m6 * _m9;

		return adj;
	}


	// ============================
	// Comparison Functions
	// ============================

	bool Mat4::isEqual(const Mat4& A, const float epsilon) const
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

		if (!this->_v3.isEqual(A._v3, epsilon))
		{
			return false;
		}

		return true;
	}

	bool Mat4::isIdentity(const float epsilon) const
	{
		return this->isEqual(Mat4(Special::Identity), epsilon);
	}



	//bool Mat4::isRotation(const float epsilon) const
	//{
	//	return false;
	//}

	// ============================
	// Operators
	// ============================

	// ******* Addition ******* //

	Mat4 Mat4::operator+(void) const
	{
		return *this;
	}

	Mat4 Mat4::operator+(const Mat4& A) const
	{
		Mat4 M;
		M._v0 = A._v0 + this->_v0;
		M._v1 = A._v1 + this->_v1;
		M._v2 = A._v2 + this->_v2;
		M._v3 = A._v3 + this->_v3;
		return M;
	}

	Mat4& Mat4::operator+=(const Mat4& A)
	{
		this->_v0 = A._v0 + this->_v0;
		this->_v1 = A._v1 + this->_v1;
		this->_v2 = A._v2 + this->_v2;
		this->_v3 = A._v3 + this->_v3;
		return *this;
	}

	// ******* Subtraction ******* //

	Mat4 Mat4::operator-(void) const
	{
		Mat4 M;
		M._v0 = -this->_v0;
		M._v1 = -this->_v1;
		M._v2 = -this->_v2;
		M._v3 = -this->_v3;
		return M;
	}

	Mat4 Mat4::operator-(const Mat4& A) const
	{
		Mat4 M;
		M._v0 = this->_v0 - A._v0;
		M._v1 = this->_v1 - A._v1;
		M._v2 = this->_v2 - A._v2;
		M._v3 = this->_v3 - A._v3;
		return M;
	}

	Mat4& Mat4::operator-=(const Mat4& A)
	{
		this->_v0 = this->_v0 - A._v0;
		this->_v1 = this->_v1 - A._v1;
		this->_v2 = this->_v2 - A._v2;
		this->_v3 = this->_v3 - A._v3;
		return *this;
	}

	// ******* Scaling ******* //

	Mat4 Mat4::operator*(const float s) const
	{
		Mat4 M;
		M._v0 = this->_v0 * s;
		M._v1 = this->_v1 * s;
		M._v2 = this->_v2 * s;
		M._v3 = this->_v3 * s;
		return M;
	}

	Mat4& Mat4::operator*=(const float scale)
	{
		this->_v0 *= scale;
		this->_v1 *= scale;
		this->_v2 *= scale;
		this->_v3 *= scale;
		return *this;
	}

	Mat4 operator*(const float scale, const Mat4& A)
	{
		Mat4 M;
		M._v0 = A._v0 * scale;
		M._v1 = A._v1 * scale;
		M._v2 = A._v2 * scale;
		M._v3 = A._v3 * scale;
		return M;
	}

	// ******* Multiplication ******* //

	Mat4 Mat4::operator*(const Mat4& A) const
	{
		Mat4 res;
		Mat4 M = A.getT();


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

		res._m12 = _v3.dot(M._v0);
		res._m13 = _v3.dot(M._v1);
		res._m14 = _v3.dot(M._v2);
		res._m15 = _v3.dot(M._v3);

		return res;
	}

	Mat4& Mat4::operator*=(const Mat4& A)
	{
		Mat4 temp;
		Mat4 M = A.getT();

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

		temp._m12 = this->_v3.dot(M._v0);
		temp._m13 = this->_v3.dot(M._v1);
		temp._m14 = this->_v3.dot(M._v2);
		temp._m15 = this->_v3.dot(M._v3);

		*this = temp;
		return *this;
	}



}

// ---  End of File ---
