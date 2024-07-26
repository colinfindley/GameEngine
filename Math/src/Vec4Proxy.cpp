

#include "MathEngine.h"

namespace Azul
{
	// Add Proxy here

	Vec4Proxy::Vec4Proxy(float a, float b, float c, float d)
		:x(a), y(b), z(c), w(d)
	{
	}


	// *** Operators *** //

	Vec4Proxy::operator float() const
	{
		return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w));
	}

	float Vec4Proxy::operator*(const Vec4Proxy& r) const
	{
		return (float)*this * (float)r;
	}

	bool Vec4Proxy::operator>(const Vec4Proxy& r) const
	{
		return len(*this) > len(r);
	}

	bool Vec4Proxy::operator<(const Vec4Proxy& r) const
	{
		return len(*this) < len(r);
	}

	bool Vec4Proxy::operator==(const Vec4Proxy& r) const
	{
		return len(*this) == len(r);
	}

	bool Vec4Proxy::operator>=(const Vec4Proxy& r) const
	{
		return len(*this) >= len(r);
	}

	bool Vec4Proxy::operator<=(const Vec4Proxy& r) const
	{
		return len(*this) <= len(r);
	}

	bool Vec4Proxy::operator!=(const Vec4Proxy& r) const
	{
		return len(*this) != len(r);
	}

	float Vec4Proxy::len(Vec4Proxy V) const
	{
		return (V.x * V.x) + (V.y * V.y) + (V.z * V.z) + (V.w * V.w);
	}


}

//--- End of File ---
