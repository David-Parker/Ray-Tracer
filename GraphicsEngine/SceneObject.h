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
	virtual bool Intersects(const Ray& ray, std::vector<Hit>& hits) = 0;
};

