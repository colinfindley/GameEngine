

#include "MathEngine.h"

namespace Azul
{
	// Add Proxy here

	Vec3Proxy::Vec3Proxy(float a, float b, float c)
		:x(a), y(b), z(c)
	{
	}

	Vec3Proxy::operator float() const
	{
		return sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	}

	float Vec3Proxy::operator*(const Vec3Proxy& r) const
	{
		return (float)*this * (float)r;
	}

	bool Vec3Proxy::operator>(const Vec3Proxy& r) const
	{
		return len(*this) > len(r);
	}

	bool Vec3Proxy::operator<(const Vec3Proxy& r) const
	{
		return len(*this) < len(r);
	}

	bool Vec3Proxy::operator==(const Vec3Proxy& r) const
	{
		return len(*this) == len(r);
	}

	bool Vec3Proxy::operator>=(const Vec3Proxy& r) const
	{
		return len(*this) >= len(r);
	}

	bool Vec3Proxy::operator<=(const Vec3Proxy& r) const
	{
		return len(*this) <= len(r);
	}

	bool Vec3Proxy::operator!=(const Vec3Proxy& r) const
	{
		return len(*this) != len(r);
	}

	float Vec3Proxy::len(Vec3Proxy V) const
	{
		return (V.x * V.x) + (V.y * V.y) + (V.z * V.z);
	}

}

//--- End of File ---
