#pragma once
#include <math.h>
#include "CoolMath.h"
#include "Hit.h"
#include "SceneObject.h"

/* Sphere */
class SphereObject : public SceneObject
{
private:
	float radius;
	Vector3 GetRandomUnitSphereDirection();

public:
	SphereObject(const Vector3& position, const float& radius) : SceneObject(position), radius(radius) {}
	~SphereObject();

	virtual bool Intersects(const Ray& ray, Hit& hit);
	virtual Vector3 GetReflectionVector(const Hit& hit);
};

