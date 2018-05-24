#include "SphereObject.h"

Vector3 SphereObject::GetRandomUnitSphereDirection()
{
	Vector3 point;

	do
	{
		point = 2.0*Vector3(CoolMath::RandomScalar(), CoolMath::RandomScalar(), CoolMath::RandomScalar()) - Vector3(1, 1, 1);
	} 
	while (point.SquaredLength() >= 1.0);

	return point;
}

SphereObject::~SphereObject()
{
}

bool SphereObject::Intersects(const Ray& ray, Hit& hit)
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

		if (t > 0)
		{
			hit.t = t;
			hit.point = ray.Fire(t);
			hit.distance = hit.point.Length();
			hit.normal = Vector3::Unit(hit.point - this->center);

			return true;
		}

		t = (-b + sqrtf(descriminant)) / (2.0f * a);

		if (t > 0)
		{
			hit.t = t;
			hit.point = ray.Fire(t);
			hit.distance = hit.point.Length();
			hit.normal = Vector3::Unit(hit.point - this->center);

			return true;
		}
	}

	return false;
}

Vector3 SphereObject::GetReflectionVector(const Hit& hit)
{
	Vector3 direction = this->GetRandomUnitSphereDirection();

	return hit.normal + direction;
}
