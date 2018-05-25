#include "Material.h"

Material::Material()
{
}

Material::~Material()
{
}

Vector3 Material::GetRandomUnitSphereDirection()
{
	Vector3 point;

	do
	{
		point = 2.0*Vector3(CoolMath::RandomScalar(), CoolMath::RandomScalar(), CoolMath::RandomScalar()) - Vector3(1, 1, 1);
	} while (point.SquaredLength() >= 1.0);

	return point;
}