#pragma once
#include "Vectors.h"

namespace Glib
{
	struct AABB
	{
		Vec3 min;
		Vec3 max;

		bool intersect(const Vec3& point);
		bool contains(const AABB& other);
	};
}