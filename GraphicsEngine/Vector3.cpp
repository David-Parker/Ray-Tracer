#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

Vector3::Vector3()
{
	X = 0.0f;
	Y = 0.0f;
	Z = 0.0f;
}

float Vector3::Length() const
{
	return sqrtf(X*X + Y*Y + Z*Z);
}

Vector3& Vector3::Normalize()
{
	return *this /= Length();
}

Vector3 Vector3::Reflect(const Vector3 & vec, const Vector3 & normal)
{
	return vec - 2 * (vec.x()*normal.x() + vec.y()*normal.y() + vec.z()*normal.z())*normal;
}

bool Vector3::Refract(const Vector3 & vec, const Vector3 & normal, float refracticeIndex, Vector3 & refracted)
{
	Vector3 unitRay = Vector3::Unit(vec);
	float dt = unitRay.Dot(normal);
	float discriminant = 1.0 - refracticeIndex*(1 - dt*dt);

	if (discriminant > 0)
	{
		refracted = refracticeIndex*(unitRay - normal*dt) - normal*sqrt(discriminant);
		return true;
	}
	else
	{
		return false;
	}
}

float Vector3::AngleBetween(const Vector3 & rhs)
{
	return acosf(Unit(*this).Dot(Unit(rhs)));
}

Vector3 Vector3::Unit(const Vector3& v)
{
	float l = v.Length();
	return Vector3(v.x() / l, v.y() / l, v.z() / l);
}

Vector3 Vector3::Lerp(const Vector3& lhs, const Vector3 & rhs, const float t)
{
	if (t > 1.0f || t < 0)
	{
		throw "t must be a value between 0.0 and 1.0";
	}

	return (1.0f - t) * lhs + t* rhs;
}
