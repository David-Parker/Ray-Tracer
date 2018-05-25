#include "Metal.h"

Metal::Metal()
{
}

Metal::~Metal()
{
}

bool Metal::Scatter(const Ray& ray, const Hit& hit, Vector3& attenuation, Ray& scattered)
{
	Vector3 reflection = ray.direction().Reflect(hit.normal);
	scattered = Ray(hit.point, Vector3::Unit(reflection));
	attenuation = Vector3(0.5,0.5,0.5);
	return (scattered.direction().Dot(hit.normal) > 0);
}
