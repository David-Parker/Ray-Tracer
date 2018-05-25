#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const Vector3& origin, const Vector3& direction) : a(origin), b(direction)
{
}

Ray::~Ray()
{
}

Vector3 Ray::origin() const
{
	return a;
}

Vector3 Ray::direction() const
{
	return b;
}

Vector3 Ray::Fire(const float time) const
{
	return a + time*b;
}

Vector3 Ray::Color() const
{
	Vector3 unitDirection = Vector3::Unit(direction());
	float t = 0.5f * (unitDirection.y() + 1.0f);
	return Vector3::Lerp(Vector3(1.0f, 1.0f, 1.0f), Vector3(0.5f, 0.7f, 1.0f), t);
}
