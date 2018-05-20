#pragma once
#include "ColorVec3.h"
#include <string>
#include <vector>
#include <fstream>

/* Represents a vector of pixels as a PPM file. */
class PPMFile
{
private:
	int width;
	int height;
	std::vector<ColorVec3> pixelData;
public:
	PPMFile(int width, int height, const std::vector<ColorVec3>& pixelData);
	~PPMFile();

	void WriteToFile(std::string filePath);
};

