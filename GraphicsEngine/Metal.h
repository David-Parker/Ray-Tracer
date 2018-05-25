#pragma once
#include "Material.h"

class Metal : public Material
{
public:
	Metal();
	~Metal();

	virtual bool Scatter(const Ray& ray, const Hit& hit, Vector3& attenuation, Ray& scattered);
};

