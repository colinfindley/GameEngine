//-----------------------------------------------------------------------------
// Copyright 2023, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef ENGINE_MATH_TRANS_4x4_H
#define ENGINE_MATH_TRANS_4x4_H

#include "Mat4.h"

namespace Azul
{
	class Trans final : public Mat4
	{
	public:

		// Do your magic here

		// Big 4
		Trans();
		Trans &operator = (const Trans &A) = default;
		Trans(const Trans &tM) = default;
		~Trans() = default;

		// Big 6
		Trans(Trans &&) = default;
		Trans &operator = (Trans &&) = default;

		// Constructors
		Trans(const float tx, const float ty, const float tz);
		Trans(const Vec3 &vTrans);

		// Set 
		void set(const float tx, const float ty, const float tz);
		void set(const Vec3 &vTrans);

	};
}

#endif

//--- End of File ---
