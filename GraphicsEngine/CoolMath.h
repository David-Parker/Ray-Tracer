#pragma once
#include <random>
#include "Vector3.h"

class CoolMath
{
public:
	CoolMath();
	~CoolMath();

	static float RandomScalar();
	static Vector3 RandomVectorInUnitDisk();
};

