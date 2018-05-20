#pragma once

/* Represents the 3 color vectors in a PPM file. */
struct ColorVec3
{
public:
	float R;
	float G;
	float B;

	ColorVec3(float r, float g, float b)
	{
		if (r > 1.0f || r < 0.0f)
		{
			throw "Value out of range. All inputs must be between 0.0f and 1.0f";
		}

		if (g > 1.0f || g < 0.0f)
		{
			throw "Value out of range. All inputs must be between 0.0f and 1.0f";
		}

		if (b > 1.0f || b < 0.0f)
		{
			throw "Value out of range. All inputs must be between 0.0f and 1.0f";
		}

		R = r;
		G = g;
		B = b;
	}
};
