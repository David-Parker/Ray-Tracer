#include "Glass.h"

float Glass::Schlick(float cos, float refractiveIndex)
{
	float r0 = (1 - refractiveIndex) / (1 + refractiveIndex);
	r0 = r0*r0;
	return r0 + (1 - r0)*pow((1 - cos), 5);
}

Glass::Glass()
{
}

Glass::~Glass()
{
}

bool Glass::Scatter(const Ray& ray, const Hit& hit, Vector3& attenuation, Ray& scattered)
{
	Vector3 outwardNormal;
	Vector3 rayDirection = ray.direction();
	Vector3 reflected = Vector3::Reflect(rayDirection, hit.normal);
	float refracticeIndex;
	attenuation = Vector3(1.0, 1.0, 1.0);
	Vector3 refracted;
	float reflect_prob;
	float cosine;

	if (rayDirection.Dot(hit.normal) > 0)
	{
		outwardNormal = -hit.normal;
		refracticeIndex = 1.5f;
		cosine = refracticeIndex * rayDirection.Dot(hit.normal) / rayDirection.Length();
	}
	else
	{
		outwardNormal = hit.normal;
		refracticeIndex = 1.0f / 1.5f;
		cosine = -(rayDirection.Dot(hit.normal)) / rayDirection.Length();
	}

	if (Vector3::Refract(rayDirection, outwardNormal, refracticeIndex, refracted))
	{
		reflect_prob = Schlick(cosine, 1.5f);
	}
	else
	{
		scattered = Ray(hit.point, reflected);
		reflect_prob = 1.0;
	}

	if (CoolMath::RandomScalar() < reflect_prob)
	{
		scattered = Ray(hit.point, reflected);
	}
	else
	{
		scattered = Ray(hit.point, refracted);
	}

	return true;
}
