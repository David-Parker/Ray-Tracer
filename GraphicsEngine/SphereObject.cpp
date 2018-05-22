#include "SphereObject.h"

SphereObject::~SphereObject()
{
}

bool SphereObject::Intersects(const Ray& ray, std::vector<Hit>& hits)
{
	Vector3 direction = ray.direction();
	Vector3 oc = ray.origin() - this->center;

	float a = direction.Dot(direction);
	float b = 2.0f * oc.Dot(direction);
	float c = oc.Dot(oc) - (this->radius * this->radius);

	float radicand = b*b - (4.0f * a*c);

	if (radicand < 0)
	{
		return false;
	}
	else
	{
		float t = (-b - sqrtf(radicand)) / 2.0f * a;

		if (t > 0)
		{
			Hit h;
			h.t = t;
			h.point = ray.Fire(t);
			h.normal = Vector3::Unit(h.point - this->center);
			hits.push_back(h);
		}

		t = (-b + sqrtf(radicand)) / 2.0f * a;

		if (t > 0)
		{
			Hit h;
			h.t = t;
			h.point = ray.Fire(t);
			h.normal = Vector3::Unit(h.point - this->center);
			hits.push_back(h);
		}

		if (hits.size() > 0) return true;

		return false;
	}
}
