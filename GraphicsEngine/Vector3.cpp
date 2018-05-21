#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
{
	X = x;
	Y = y;
	Z = z;
}

inline const Vector3& Vector3::operator+() const
{
	return *this;
}

inline Vector3 Vector3::operator-() const
{
	return Vector3(-X, -Y, -Z);
}

inline float Vector3::operator[](int index) const
{
	if (index >= 3 || index < 0)
	{
		throw "Index out of range";
	}

	return data[index];
}

inline float& Vector3::operator[](int index)
{
	if (index >= 3 || index < 0)
	{
		throw "Index out of range";
	}

	return data[index];
}

inline Vector3& Vector3::operator+=(const Vector3& rhs)
{
	X += rhs.x();
	Y += rhs.y();
	Z += rhs.z();

	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& rhs)
{
	X -= rhs.x();
	Y -= rhs.y();
	Z -= rhs.z();

	return *this;
}

inline Vector3& Vector3::operator*=(const Vector3& rhs)
{
	X *= rhs.x();
	Y *= rhs.y();
	Z *= rhs.z();

	return *this;
}

inline Vector3& Vector3::operator/=(const Vector3& rhs)
{
	X /= rhs.x();
	Y /= rhs.y();
	Z /= rhs.z();

	return *this;
}

inline Vector3& Vector3::operator*=(const float scalar)
{
	X *= scalar;
	Y *= scalar;
	Z *= scalar;

	return *this;
}

inline Vector3& Vector3::operator/=(const float scalar)
{
	X /= scalar;
	Y /= scalar;
	Z /= scalar;

	return *this;
}

inline Vector3 Vector3::operator+(const Vector3 & rhs)
{
	return Vector3(X + rhs.x(), Y + rhs.y(), Z + rhs.z());
}

inline Vector3 Vector3::operator-(const Vector3 & rhs)
{
	return Vector3(X - rhs.x(), Y - rhs.y(), Z - rhs.z());
}

inline Vector3 Vector3::operator*(const Vector3 & rhs)
{
	return Vector3(X * rhs.x(), Y * rhs.y(), Z * rhs.z());
}

inline Vector3 Vector3::operator/(const Vector3 & rhs)
{
	return Vector3(X / rhs.x(), Y / rhs.y(), Z / rhs.z());
}

inline float Vector3::Length()
{
	return sqrtf(X*X + Y*Y + Z*Z);
}

inline float Vector3::Dot(const Vector3& rhs)
{
	return X*rhs.x() + Y*rhs.y() + Z*rhs.z();
}

inline Vector3& Vector3::Normalize()
{
	return *this /= Length();
}

inline Vector3 Vector3::Cross(const Vector3& rhs)
{
	return Vector3(Y * rhs.z() - Z * rhs.y(), -(X * rhs.z() - Z * rhs.x()), X * rhs.y() - Y * rhs.x());
}
