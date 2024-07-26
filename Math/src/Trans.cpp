

#include "MathEngine.h"

namespace Azul
{
	// Do your magic here

	Trans::Trans()
	{
		this->_m0 = 1.0f;
		this->_m1 = 0.0f;
		this->_m2 = 0.0f;
		this->_m3 = 0.0f;
		this->_m4 = 0.0f;
		this->_m5 = 1.0f;
		this->_m6 = 0.0f;
		this->_m7 = 0.0f;
		this->_m8 = 0;
		this->_m9 = 0;
		this->_m10 = 1.0f;
		this->_m11 = 0;
		this->_m12 = 0.0f;
		this->_m13 = 0.0f;
		this->_m14 = 0.0f;
		this->_m15 = 1.0f;
	}

	Trans::Trans(const float tx, const float ty, const float tz)
	{
		this->_m0 = 1.0f;
		this->_m1 = 0.0f;
		this->_m2 = 0.0f;
		this->_m3 = 0.0f;
		this->_m4 = 0.0f;
		this->_m5 = 1.0f;
		this->_m6 = 0.0f;
		this->_m7 = 0.0f;
		this->_m8 = 0;
		this->_m9 = 0;
		this->_m10 = 1.0f;
		this->_m11 = 0;
		this->_m12 = tx;
		this->_m13 = ty;
		this->_m14 = tz;
		this->_m15 = 1.0f;
	}

	Trans::Trans(const Vec3& vTrans)
	{
		this->_m0 = 1.0f;
		this->_m5 = 1.0f;
		this->_m10 = 1.0f;
		this->_m15 = 1.0f;
		this->_m12 = vTrans._vx;
		this->_m13 = vTrans._vy;
		this->_m14 = vTrans._vz;
	}

	void Trans::set(const float tx, const float ty, const float tz)
	{
		this->_m0 = 1.0f;
		this->_m1 = 0.0f;
		this->_m2 = 0.0f;
		this->_m3 = 0.0f;
		this->_m4 = 0.0f;
		this->_m5 = 1.0f;
		this->_m6 = 0.0f;
		this->_m7 = 0.0f;
		this->_m8 = 0;
		this->_m9 = 0;
		this->_m10 = 1.0f;
		this->_m11 = 0;
		this->_m12 = tx;
		this->_m13 = ty;
		this->_m14 = tz;
		this->_m15 = 1.0f;
	}

	void Trans::set(const Vec3& vTrans)
	{
		this->_m0 = 1.0f;
		this->_m5 = 1.0f;
		this->_m10 = 1.0f;
		this->_m15 = 1.0f;
		this->_m12 = vTrans._vx;
		this->_m13 = vTrans._vy;
		this->_m14 = vTrans._vz;
	}

}

// ---  End of File ---
