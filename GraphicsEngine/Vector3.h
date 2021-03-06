#pragma once
#include <math.h>

/* Represents a vector with 3 components */
class Vector3
{
private:
	float data[3];

// Internal properties
#define X data[0]
#define Y data[1]
#define Z data[2]

public:
	inline float x() const { return X; }
	inline float y() const { return Y; }
	inline float z() const { return Z; }

	Vector3(float x, float y, float z);
	Vector3();

	// Operators
	inline const Vector3& operator+() const
	{
		return *this;
	}

	inline Vector3 operator-() const
	{
		return Vector3(-X, -Y, -Z);
	}

	inline float operator[](int index) const
	{
		if (index >= 3 || index < 0)
		{
			throw "Index out of range";
		}

		return data[index];
	}

	inline float& operator[](int index)
	{
		if (index >= 3 || index < 0)
		{
			throw "Index out of range";
		}

		return data[index];
	}

	inline Vector3& operator+=(const Vector3& rhs) {
		X += rhs.x();
		Y += rhs.y();
		Z += rhs.z();

		return *this;
	}

	inline Vector3& operator-=(const Vector3& rhs)
	{
		X -= rhs.x();
		Y -= rhs.y();
		Z -= rhs.z();

		return *this;
	}

	inline Vector3& operator*=(const Vector3& rhs)
	{
		X *= rhs.x();
		Y *= rhs.y();
		Z *= rhs.z();

		return *this;
	}

	inline Vector3& operator/=(const Vector3& rhs)
	{
		X /= rhs.x();
		Y /= rhs.y();
		Z /= rhs.z();

		return *this;
	}

	inline Vector3& operator*=(const float scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;

		return *this;
	}

	inline Vector3& operator/=(const float scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;

		return *this;
	}

	// Methods
	inline float Length() const;
	inline float SquaredLength() const { return (X*X + Y*Y + Z*Z); }
	inline float Dot(const Vector3& rhs) const { return X*rhs.x() + Y*rhs.y() + Z*rhs.z(); }
	inline Vector3& Normalize();
	inline Vector3 Cross(const Vector3& rhs)
	{
		return Vector3(Y * rhs.z() - Z * rhs.y(), -(X * rhs.z() - Z * rhs.x()), X * rhs.y() - Y * rhs.x());
	}
	inline float AngleBetween(const Vector3& rhs);

	// Static methods
	static Vector3 Reflect(const Vector3& vec, const Vector3& normal);
	static bool Refract(const Vector3& vec, const Vector3& normal, float refracticeIndex, Vector3& refracted);
	static Vector3 Unit(const Vector3& v);
	static Vector3 Lerp(const Vector3& lhs, const Vector3& rhs, const float t);
	static Vector3 Left() { return Vector3(1.0f, 0.0f, 0.0f); }
	static Vector3 Up() { return Vector3(0.0f, 1.0f, 0.0f); }
	static Vector3 Forward() { return Vector3(0.0f, 0.0f, -1.0f); }
};

inline Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z());
}

inline Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z());
}

inline Vector3 operator*(const Vector3& rhs, const Vector3& lhs)
{
	return Vector3(rhs.x() * lhs.x(), rhs.y() * lhs.y(), rhs.z() * lhs.z());
}

inline Vector3 operator/(const Vector3& lhs, const Vector3& rhs)
{
	return Vector3(lhs.x() / rhs.x(), lhs.y() / rhs.y(), lhs.z() / rhs.z());
}

inline Vector3 operator*(const float& lhs, const Vector3& rhs)
{
	return Vector3(lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z());
}

inline Vector3 operator/(const float& lhs, const Vector3& rhs)
{
	return Vector3(lhs / rhs.x(), lhs / rhs.y(), lhs / rhs.z());
}

inline Vector3 operator*(const Vector3& lhs, const float& rhs)
{
	return Vector3(lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs);
}

inline Vector3 operator/(const Vector3& lhs, const float& rhs)
{
	return Vector3(lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs);
}


