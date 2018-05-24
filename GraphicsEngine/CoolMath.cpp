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
