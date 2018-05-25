#include "Lambertian.h"

Lambertian::~Lambertian()
{
}

bool Lambertian::Scatter(const Ray& ray, const Hit& hit, Vector3& attenuation, Ray& scattered)
{
	Vector3 target = hit.point + hit.normal + this->GetRandomUnitSphereDirection();
	scattered = Ray(hit.point, target - hit.point);
	attenuation = alebdo;

	return true;
}
