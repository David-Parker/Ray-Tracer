#pragma once
#include "Vector3.h"
#include "Material.h"

/* Represents a hit on a surface from a ray cast */

class Material;

struct Hit
{
public:
	float t;
	float distance;
	Vector3 point;
	Vector3 normal;
	Material* material;

	Hit();
	~Hit();
};

