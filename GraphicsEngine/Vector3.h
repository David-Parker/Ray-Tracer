#pragma once
#include <math.h>

/* Represents a vector with 3 components */
struct Vector3
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
	inline const Vector3& operator+() const;
	inline Vector3 operator-() const;
	inline float operator[](int index) const;
	inline float& operator[](int index);
	inline Vector3& operator+=(const Vector3& rhs);
	inline Vector3& operator-=(const Vector3& rhs);
	inline Vector3& operator*=(const Vector3& rhs);
	inline Vector3& operator/=(const Vector3& rhs);
	inline Vector3& operator*=(const float scalar);
	inline Vector3& operator/=(const float scalar);

	// Methods
	inline float Length() const;
	inline float SquaredLength() const;
	inline float Dot(const Vector3& rhs) const;
	inline Vector3& Normalize();
	inline Vector3 Cross(const Vector3& rhs);
	inline float AngleBetween(const Vector3& rhs);

	// Static methods
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


