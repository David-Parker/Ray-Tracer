#include "SphereObject.h"

SphereObject::~SphereObject()
{
	delete material;
}

bool SphereObject::Intersects(const Ray& ray, Hit& hit, float minTime, float maxTime)
{
	Vector3 direction = ray.direction();
	Vector3 oc = ray.origin() - this->center;

	float a = direction.Dot(direction);
	float b = 2.0f * oc.Dot(direction);
	float c = oc.Dot(oc) - (this->radius * this->radius);

	float descriminant = b*b - (4.0f * a*c);

	if (descriminant > 0)
	{
		float t = (-b - sqrtf(descriminant)) / (2.0f * a);

		if (t > minTime && t < maxTime)
		{
			hit.t = t;
			hit.point = ray.Fire(t);
			hit.distance = hit.point.Length();
			hit.material = this->material;
			hit.normal = Vector3::Unit(hit.point - this->center);

			return true;
		}

		t = (-b + sqrtf(descriminant)) / (2.0f * a);

		if (t > minTime && t < maxTime)
		{
			hit.t = t;
			hit.point = ray.Fire(t);
			hit.distance = hit.point.Length();
			hit.material = this->material;
			hit.normal = Vector3::Unit(hit.point - this->center);

			return true;
		}
	}

	return false;
}
