#pragma once

#include "vector4D.h"

class matrix4x4
{
public :
	vector4D row0, row1, row2, row3;

	matrix4x4(const vector4D& _r0, const vector4D& _r1, const vector4D& _r2, const vector4D& _r3)
		: row0(_r0), row1(_r1), row2(_r2), row3(_r3)
	{}
	vector4D operator*(const vector4D& rh)
	{
		vector4D ans;

			ans.x_ = row0 * rh;
			ans.y_ = row1 * rh;
			ans.z_ = row2 * rh;
			ans.k_ = row3 * rh;
			return ans;
	}
};