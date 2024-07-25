//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include <math.h>    // <--- ONLY location for <math.h> allowed
#include "Trig.h"

namespace Azul
{

	

	float Trig::sqrt(const float val)
	{
		return std::sqrt(val);
	}

	float Trig::rsqrt(const float val)
	{
		if (val == 0) 
		{
			return 0; // Return 0 for zero input to avoid division by zero
		}
		return 1.0f / std::sqrt(val);
	}

	float Trig::cos(const float angle_radians)
	{
		return std::cos(angle_radians);
	}

	float Trig::sin(const float angle_radians)
	{
		return std::sin(angle_radians);
	}

	float Trig::tan(const float val)
	{
		return std::tan(val);
	}

	float Trig::atan(const float val)
	{
		return std::atan(val);
	}

	float Trig::atan2(const float x, const float y)
	{
		return std::atan2(x, y);
	}

	float Trig::acos(const float val)
	{
		return std::acos(val);
	}

	float Trig::asin(const float val)
	{
		return std::asin(val);
	}

	void Trig::cossin(float& cos, float& sin, const float angle_radians)
	{
		cos = std::cos(angle_radians);
		sin = std::sin(angle_radians);
	}

}

//--- End of File ---
