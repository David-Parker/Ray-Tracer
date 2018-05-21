#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Vector3.h"

/* Represents a vector of pixels as a PPM file. */
class PPMFile
{
private:
	int width;
	int height;
	std::vector<Vector3> pixelData;
public:
	PPMFile(int width, int height, const std::vector<Vector3>& pixelData);
	~PPMFile();

	void WriteToFile(std::string filePath);
};

