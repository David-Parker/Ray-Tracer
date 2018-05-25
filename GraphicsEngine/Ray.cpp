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
