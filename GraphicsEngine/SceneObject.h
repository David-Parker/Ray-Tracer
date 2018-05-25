#pragma once
#include <vector>
#include "Hit.h"
#include "Material.h"
#include "Vector3.h"
#include "Ray.h"

class SceneObject
{
protected:
	Vector3 center;
	Material* material;

public:
	SceneObject(const Vector3& position, Material* material) :center(position), material(material) {}
	~SceneObject() {}

	Vector3 GetPosition() { return center; }
	virtual bool Intersects(const Ray& ray, Hit& hit, float minTime, float maxTime) = 0;
};

