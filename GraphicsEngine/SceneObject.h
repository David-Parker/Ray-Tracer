#pragma once
#include <vector>
#include "Hit.h"
#include "Vector3.h"
#include "Ray.h"

class SceneObject
{
protected:
	Vector3 position;

public:
	SceneObject(const Vector3& position) :position(position) {}
	~SceneObject() {}

	Vector3 GetPosition() { return position; }
	virtual bool Intersects(const Ray& ray, std::vector<Hit>& hits) = 0;
};

