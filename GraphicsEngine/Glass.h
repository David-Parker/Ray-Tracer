#pragma once
#include "Material.h"
#include "CoolMath.h"

class Glass : public Material
{
private:
	float Schlick(float cos, float refractiveIndex);

public:
	Glass();
	~Glass();

	virtual bool Scatter(const Ray& ray, const Hit& hit, Vector3& attenuation, Ray& scattered);
};

