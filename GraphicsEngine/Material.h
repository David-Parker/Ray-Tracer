#pragma once
#include "CoolMath.h"
#include "Hit.h"
#include "Ray.h"
#include "Vector3.h"

struct Hit;

class Material
{
protected:
	Vector3 GetRandomUnitSphereDirection();

public:
	Material();
	~Material();

	virtual bool Scatter(const Ray& ray, const Hit& hit, Vector3& attenuation, Ray& scattered) = 0;
};

