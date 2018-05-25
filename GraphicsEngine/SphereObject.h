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

public:
	SphereObject(const Vector3& position, const float& radius, Material* material) : SceneObject(position, material), radius(radius) {}
	~SphereObject();

	inline virtual bool Intersects(const Ray& ray, Hit& hit, float minTime, float maxTime);
};

