#pragma once
#include "Vector3.h"

/* Represents a hit on a surface from a ray cast */
struct Hit
{
public:
	float t;
	Vector3 point;
	Vector3 normal;

	Hit();
	~Hit();
};

