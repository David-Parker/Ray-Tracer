#pragma once
#include <math.h>
#include "Hit.h"
#include "SceneObject.h"

/* Sphere */
class SphereObject : public SceneObject
{
private:
	float radius;

public:
	SphereObject(const Vector3& position, const float& radius) : SceneObject(position), radius(radius) {}
	~SphereObject();

	virtual bool Intersects(const Ray& ray, std::vector<Hit>& hits);
};

