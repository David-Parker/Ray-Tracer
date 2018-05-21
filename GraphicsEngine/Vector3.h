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
	inline Vector3 operator+(const Vector3& rhs);
	inline Vector3 operator-(const Vector3& rhs);
	inline Vector3 operator*(const Vector3& rhs);
	inline Vector3 operator/(const Vector3& rhs);

	// Methods
	inline float Length();
	inline float Dot(const Vector3& rhs);
	inline Vector3& Normalize();
	inline Vector3 Cross(const Vector3& rhs);
};
