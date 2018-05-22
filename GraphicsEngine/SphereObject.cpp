#include "SphereObject.h"

SphereObject::~SphereObject()
{
}

bool SphereObject::Intersects(const Ray& ray, std::vector<Hit>& hits)
{
	Vector3 direction = ray.direction();
	Vector3 vecBetweenRayAndObjectCenter = ray.origin() - this->position;

	float a = direction.Dot(direction);
	float b = 2.0f * direction.Dot(vecBetweenRayAndObjectCenter);
	float c = vecBetweenRayAndObjectCenter.Dot(vecBetweenRayAndObjectCenter) - this->radius * this->radius;

	float quadrant = b*b - 4.0f * a*c;

	if (quadrant < 0)
	{
		return false;
	}
	if (quadrant == 0)
	{
		float t1 = -b / 2.0f * a;
		Hit h;
		h.t = t1;
		h.point = ray.Fire(t1);
		h.normal = Vector3::Unit(h.point - this->position);

		hits.push_back(h);

		return true;
	}
	else
	{
		float t1 = (-b + sqrtf(quadrant)) / 2.0f * a;
		float t2 = (-b - sqrtf(quadrant)) / 2.0f * a;

		Hit h1;
		h1.t = t1;
		h1.point = ray.Fire(t1);
		h1.normal = Vector3::Unit(h1.point - this->position);

		Hit h2;
		h2.t = t2;
		h2.point = ray.Fire(t2);
		h2.normal = Vector3::Unit(h2.point - this->position);

		hits.push_back(h1);
		hits.push_back(h2);

		return true;
	}
}
