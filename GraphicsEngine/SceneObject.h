#pragma once
#include <vector>
#include "Hit.h"
#include "Vector3.h"
#include "Ray.h"

class SceneObject
{
protected:
	Vector3 center;

public:
	SceneObject(const Vector3& position) :center(position) {}
	~SceneObject() {}

	Vector3 GetPosition() { return center; }
	virtual bool Intersects(const Ray& ray, Hit& hit) = 0;
	virtual Vector3 GetReflectionVector(const Hit& hit) = 0;
};

