#pragma once
#include "Vector3.h"

/* Represents a ray that can be cast into the scene. */
class Ray
{
private:
	Vector3 a;
	Vector3 b;

public:
	Ray(const Vector3& x, const Vector3& y);
	~Ray();

	Vector3 origin() const;
	Vector3 direction() const;

	Vector3 Fire(const float time) const;
	Vector3 Color() const;
};

