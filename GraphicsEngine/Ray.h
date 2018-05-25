#pragma once
#include "Vector3.h"

/* Represents a ray that can be cast into the scene. */
class Ray
{
private:
	Vector3 a;
	Vector3 b;

public:
	Ray();
	Ray(const Vector3& x, const Vector3& y);
	~Ray();

	inline Vector3 origin() const { return a; }
	inline Vector3 direction() const { return b; }
	inline Vector3 Fire(const float time) const { return a + time*b; }
	inline Vector3 Color() const
	{
		Vector3 unitDirection = Vector3::Unit(direction());
		float t = 0.5f * (unitDirection.y() + 1.0f);
		return Vector3::Lerp(Vector3(1.0f, 1.0f, 1.0f), Vector3(0.5f, 0.7f, 1.0f), t);
	}
};

