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

const Vector3& Vector3::operator+() const
{
	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-X, -Y, -Z);
}

float Vector3::operator[](int index) const
{
	if (index >= 3 || index < 0)
	{
		throw "Index out of range";
	}

	return data[index];
}

float& Vector3::operator[](int index)
{
	if (index >= 3 || index < 0)
	{
		throw "Index out of range";
	}

	return data[index];
}

float Vector3::Length() const
{
	return sqrtf(X*X + Y*Y + Z*Z);
}

Vector3& Vector3::Normalize()
{
	return *this /= Length();
}

Vector3 Vector3::Cross(const Vector3& rhs)
{
	return Vector3(Y * rhs.z() - Z * rhs.y(), -(X * rhs.z() - Z * rhs.x()), X * rhs.y() - Y * rhs.x());
}

Vector3 Vector3::Reflect(const Vector3 & vec, const Vector3 & normal)
{
	return vec - 2 * (vec.x()*normal.x() + vec.y()*normal.y() + vec.z()*normal.z())*normal;
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
