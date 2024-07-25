//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "MathEngine.h"

namespace Azul
{

	// ============================
	// Constructors
	// ============================

	Rot::Rot()
	{
		this->_m0 = 0;
		this->_m1 = 0;
		this->_m2 = 0;
		this->_m3 = 0;
		this->_m4 = 0;
		this->_m5 = 0;
		this->_m6 = 0;
		this->_m7 = 0;
		this->_m8 = 0;
		this->_m9 = 0;
		this->_m10 = 0;
		this->_m11 = 0;
		this->_m12 = 0;
		this->_m13 = 0;
		this->_m14 = 0;
		this->_m15 = 0;
	}

	Rot::Rot(Mat4 M)
	{
		this->_m0 = M._m0;
		this->_m1 = M._m1;
		this->_m2 = M._m2;
		this->_m3 = M._m3;
		this->_m4 = M._m4;
		this->_m5 = M._m5;
		this->_m6 = M._m6;
		this->_m7 = M._m7;
		this->_m8 = M._m8;
		this->_m9 = M._m9;
		this->_m10 =M._m10;
		this->_m11 =M._m11;
		this->_m12 =M._m12;
		this->_m13 =M._m13;
		this->_m14 =M._m14;
		this->_m15 =M._m15;
	}



	Rot::Rot(const Rot1 type, const float angle)
	{
		float c = cos(angle);
		float s = sin(angle);

		if (type == Rot1::X)
		{
			_m1 = _m2 = _m3 = _m11 = 0.0f;
			_m4 = _m7 = _m8 = _m9 = _m12 = _m13 = _m14 = 0.0f;
			_m0 = _m15 = 1.0f;

			// Set the elements that depend on the angle
			_m5 = c;
			_m6 = s;
			_m9 = -s;
			_m10 = c;
		}
		else if (type == Rot1::Y)
		{
			_m1 = _m3 = _m4 = _m6 = _m7 = _m9 = _m11 = _m12 = _m13 = _m14 = 0.0f;
			_m5 = _m15 = 1.0f;

			_m0 = c;
			_m2 = -s;
			_m8 = s;
			_m10 = c;

		}
		else
		{
			_m2 = _m3 = _m6 = _m7 = _m9 = _m11 = _m12 = _m13 = _m14 = 0.0f;
			_m10 = _m15 = 1.0f;

			_m0 = c;
			_m5 = c;
			_m1 = s;
			_m4 = -s;

		}

	}

	Rot::Rot(const Rot3 mode, const float angle_0, const float angle_1, const float angle_2)
	{
		Rot x(Rot1::X, angle_0);
		Rot y(Rot1::Y, angle_1);
		Rot z(Rot1::Z, angle_2);

		if (mode == Rot3::XYZ)
		{
			*this = Rot(x* y* z);
			
		} 
		else if (mode == Rot3::XZY)
		{
			*this = Rot(x * z * y);
		}
		else if (mode == Rot3::YXZ)
		{
			*this = Rot(y * x * z);
		}
		else if (mode == Rot3::YZX)
		{
			*this = Rot(y * z * x);
		}
		else if (mode == Rot3::ZXY)
		{
			*this = Rot(z * x * y);
		}
		else if (mode == Rot3::ZYX)
		{
			*this = Rot(z * y * x);
		}

	}

	Rot::Rot(const Axis axis, const Vec3& vAxis, const float angle)
	{
		const float angle_a = 0.5f * angle;
		float cos_a;
		float sin_a;

		Trig::cossin(cos_a, sin_a, angle_a);

		Vec3 qV = (axis == Axis::AxisAngle) ? vAxis.getNorm() : vAxis;

		qV *= sin_a;

		Vec4 Q;
		Q[x] = qV[x];
		Q[y] = qV[y];
		Q[z] = qV[z];
		Q[w] = cos_a;

		// this function has been transposed
		float x2, y2, z2;
		float xx, xy, xz;
		float yy, yz, zz;
		float wx, wy, wz;

		x2 = Q[x] + Q[x];
		y2 = Q[y] + Q[y];
		z2 = Q[z] + Q[z];

		xx = Q[x] * x2;
		xy = Q[x] * y2;
		xz = Q[x] * z2;

		yy = Q[y] * y2;
		yz = Q[y] * z2;
		zz = Q[z] * z2;

		wx = Q[w] * x2;
		wy = Q[w] * y2;
		wz = Q[w] * z2;

		this->_m0 = 1.0f - (yy + zz);
		this->_m1 = xy + wz;
		this->_m2 = xz - wy;
		this->_m3 = 0.0f;

		this->_m4 = xy - wz;
		this->_m5 = 1.0f - (xx + zz);
		this->_m6 = yz + wx;
		this->_m7 = 0.0f;

		this->_m8 = xz + wy;
		this->_m9 = yz - wx;
		this->_m10 = 1.0f - (xx + yy);
		this->_m11 = 0.0f;

		this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);

	}

	Rot::Rot(const Orient type, const Vec3& dof, const Vec3& up)
	{
		if (type == Orient::LocalToWorld)
		{

		}
		const Vec3 rz = dof.getNorm();

		/* find rx */
		Vec3 rx = up.cross(rz);
		rx.norm();

		/* find ry */
		Vec3 ry = rz.cross(rx);
		ry.norm();


		if (type == Orient::LocalToWorld)
		{
			this->Mat4::set(Vec4(rx, 0), Vec4(ry, 0), Vec4(rz, 0), Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		}
		else
		{
			this->Mat4::set(Vec4(rx._vx, ry._vx, rz._vx, 0),
				Vec4(rx._vy, ry._vy, rz._vy, 0),
				Vec4(rx._vz, ry._vz, rz._vz, 0),
				Vec4(0, 0, 0, 1));
		}

		this->_m3 = 0.0f;
		this->_m7 = 0.0f;
		this->_m11 = 0.0f;
		this->_m15 = 1.0f;

	}


	void Rot::set(Axis axis, const Vec3& vAxis, const float angle)
	{

			const float angle_a = 0.5f * angle;
			float cos_a;
			float sin_a;

			Trig::cossin(cos_a, sin_a, angle_a);

			Vec3 qV = (axis == Axis::AxisAngle) ? vAxis.getNorm() : vAxis;

			qV *= sin_a;

			Vec4 Q;
			Q[x] = qV[x];
			Q[y] = qV[y];
			Q[z] = qV[z];
			Q[w] = cos_a;

			// this function has been transposed
			float x2, y2, z2;
			float xx, xy, xz;
			float yy, yz, zz;
			float wx, wy, wz;

			x2 = Q[x] + Q[x];
			y2 = Q[y] + Q[y];
			z2 = Q[z] + Q[z];

			xx = Q[x] * x2;
			xy = Q[x] * y2;
			xz = Q[x] * z2;

			yy = Q[y] * y2;
			yz = Q[y] * z2;
			zz = Q[z] * z2;

			wx = Q[w] * x2;
			wy = Q[w] * y2;
			wz = Q[w] * z2;

			this->_m0 = 1.0f - (yy + zz);
			this->_m1 = xy + wz;
			this->_m2 = xz - wy;
			this->_m3 = 0.0f;

			this->_m4 = xy - wz;
			this->_m5 = 1.0f - (xx + zz);
			this->_m6 = yz + wx;
			this->_m7 = 0.0f;

			this->_m8 = xz + wy;
			this->_m9 = yz - wx;
			this->_m10 = 1.0f - (xx + yy);
			this->_m11 = 0.0f;

			this->_v3.set(0.0f, 0.0f, 0.0f, 1.0f);

	}

	void Rot::set(const Orient type, const Vec3& dof, const Vec3& up)
	{

		const Vec3 rz = dof.getNorm();

		/* find rx */
		Vec3 rx = up.cross(rz);
		rx.norm();

		/* find ry */
		Vec3 ry = rz.cross(rx);
		ry.norm();

		if (type == Orient::LocalToWorld)
		{
			this->Mat4::set(Vec4(rx, 0), Vec4(ry, 0), Vec4(rz, 0), Vec4(0.0f, 0.0f, 0.0f, 1.0f));
		}
		else
		{
			this->Mat4::set(Vec4(rx._vx, ry._vx, rz._vx, 0), 
				Vec4(rx._vy, ry._vy, rz._vy, 0),
				Vec4(rx._vz, ry._vz, rz._vz, 0),
				Vec4(0, 0, 0, 1));
		}
		



		this->_m3 = 0.0f;
		this->_m7 = 0.0f;
		this->_m11 = 0.0f;
		this->_m15 = 1.0f;
	}

	void Rot::set(const Rot1 type, const float angle)
	{
		// Compute cos and sin of the given angle
		float c = cos(angle);
		float s = sin(angle);

		if (type == Rot1::X)
		{
			_m1 = _m2 = _m3 = _m11 = 0.0f;
			_m4 = _m7 = _m8 = _m9 = _m12 = _m13 = _m14 = 0.0f;
			_m0 = _m15 = 1.0f;

			// Set the elements that depend on the angle
			_m5 = c;
			_m6 = s;
			_m9 = -s;
			_m10 = c;
		}
		else if (type == Rot1::Y)
		{
			_m1 = _m3 = _m4 = _m6 = _m7 = _m9 = _m11 = _m12 = _m13 = _m14 = 0.0f;
			_m5 = _m15 = 1.0f;

			_m0 = c;
			_m2 = -s;
			_m8 = s;
			_m10 = c;

		}
		else
		{
			_m2 = _m3 = _m6 = _m7 = _m9 = _m11 = _m12 = _m13 = _m14 = 0.0f;
			_m10 = _m15 = 1.0f;

			_m0 = c;
			_m5 = c;
			_m1 = s;
			_m4 = -s;

		}
	}

	void Rot::set(const Rot3 mode, const float angle_0, const float angle_1, const float angle_2)
	{
		Rot x(Rot1::X, angle_0);
		Rot y(Rot1::Y, angle_1);
		Rot z(Rot1::Z, angle_2);

		if (mode == Rot3::XYZ)
		{
			*this = Rot(x * y * z);

		}
		else if (mode == Rot3::XZY)
		{
			*this = Rot(x * z * y);
		}
		else if (mode == Rot3::YXZ)
		{
			*this = Rot(y * x * z);
		}
		else if (mode == Rot3::YZX)
		{
			*this = Rot(y * z * x);
		}
		else if (mode == Rot3::ZXY)
		{
			*this = Rot(z * x * y);
		}
		else if (mode == Rot3::ZYX)
		{
			*this = Rot(z * y * x);
		}
	}




}

// ---  End of File ---
