#include "CoolMath.h"

CoolMath::CoolMath()
{
}

CoolMath::~CoolMath()
{
}

float CoolMath::RandomScalar()
{
	return ((float)rand() / (RAND_MAX));
}

Vector3 CoolMath::RandomVectorInUnitDisk()
{
	Vector3 p;
	do
	{
		p = 2.0*Vector3(RandomScalar(), RandomScalar(), 0) - Vector3(1, 1, 0);
	} while (p.Dot(p) >= 1.0);

	return p;
}
