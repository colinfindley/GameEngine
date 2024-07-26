

#include "MathEngine.h"

namespace Azul
{

	Scale::Scale()
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
		this->_m15 = 1;
	}

	Scale::Scale(const float sx, const float sy, const float sz)
	{
		this->_m0 = sx;
		this->_m1 = 0;
		this->_m2 = 0;
		this->_m3 = 0;
		this->_m4 = 0;
		this->_m5 = sy;
		this->_m6 = 0;
		this->_m7 = 0;
		this->_m8 = 0;
		this->_m9 = 0;
		this->_m10 = sz;
		this->_m11 = 0;
		this->_m12 = 0;
		this->_m13 = 0;
		this->_m14 = 0;
		this->_m15 = 1;
	}

	Scale::Scale(const Vec3& vScale)
	{
		this->_m0 = vScale._vx;
		this->_m1 = 0;
		this->_m2 = 0;
		this->_m3 = 0;
		this->_m4 = 0;
		this->_m5 = vScale._vy;
		this->_m6 = 0;
		this->_m7 = 0;
		this->_m8 = 0;
		this->_m9 = 0;
		this->_m10 = vScale._vz;
		this->_m11 = 0;
		this->_m12 = 0;
		this->_m13 = 0;
		this->_m14 = 0;
		this->_m15 = 1;
	}

	void Scale::set(const float sx, const float sy, const float sz)
	{
		this->_m0 = sx;
		this->_m5 = sy;
		this->_m10 = sz;
		this->_m15 = 1;
	}

	void Scale::set(const Vec3& vScale)
	{
		this->_m0 = vScale._vx;
		this->_m5 = vScale._vy;
		this->_m10 = vScale._vz;
		this->_m15 = 1;
	}

}

// ---  End of File ---
