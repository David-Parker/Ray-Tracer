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

Vector3& Vector3::operator+=(const Vector3& rhs)
{
	X += rhs.x();
	Y += rhs.y();
	Z += rhs.z();

	return *this;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
	X -= rhs.x();
	Y -= rhs.y();
	Z -= rhs.z();

	return *this;
}

Vector3& Vector3::operator*=(const Vector3& rhs)
{
	X *= rhs.x();
	Y *= rhs.y();
	Z *= rhs.z();

	return *this;
}

Vector3& Vector3::operator/=(const Vector3& rhs)
{
	X /= rhs.x();
	Y /= rhs.y();
	Z /= rhs.z();

	return *this;
}

Vector3& Vector3::operator*=(const float scalar)
{
	X *= scalar;
	Y *= scalar;
	Z *= scalar;

	return *this;
}

Vector3& Vector3::operator/=(const float scalar)
{
	X /= scalar;
	Y /= scalar;
	Z /= scalar;

	return *this;
}

float Vector3::Length() const
{
	return sqrtf(X*X + Y*Y + Z*Z);
}

float Vector3::SquaredLength() const
{
	return (X*X + Y*Y + Z*Z);
}

float Vector3::Dot(const Vector3& rhs) const
{
	return X*rhs.x() + Y*rhs.y() + Z*rhs.z();
}

Vector3& Vector3::Normalize()
{
	return *this /= Length();
}

Vector3 Vector3::Cross(const Vector3& rhs)
{
	return Vector3(Y * rhs.z() - Z * rhs.y(), -(X * rhs.z() - Z * rhs.x()), X * rhs.y() - Y * rhs.x());
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

Vector3 Vector3::Lerp(const Vector3 & lhs, const Vector3 & rhs, const float t)
{
	if (t > 1.0f || t < 0)
	{
		throw "t must be a value between 0.0 and 1.0";
	}

	return (1.0f - t) * lhs + t* rhs;
}
