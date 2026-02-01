#include "Collision.h"

bool Glib::AABB::intersect(const Glib::Vec3& point)
{
	return min.x >= point.x && max.x <= point.x &&
		min.y >= point.y && max.y <= point.y &&
		min.z >= point.z && max.z <= point.z;
}

bool Glib::AABB::contains(const AABB& other)
{
	return min.x >= other.min.x && max.x <= other.max.x &&
		min.y >= other.min.y && max.y <= other.max.y &&
		min.z >= other.min.z && max.z <= other.max.z;
}