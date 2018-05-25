#pragma once
#include "Material.h"
#include "Vector3.h"

class Lambertian : public Material
{
private:
	Vector3 alebdo;

public:
	Lambertian(const Vector3& alebdo) : alebdo(alebdo) {}
	~Lambertian();

	virtual bool Scatter(const Ray& ray, const Hit& hit, Vector3& attenuation, Ray& scattered);
};

