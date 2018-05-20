#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "PPMViewer.h"
#include "PPMFile.h"

const std::string viewerExe = ".\\OpenSeeIt\\OpenSeeIt.exe";

int main(char** argv, int argc)
{
	std::string fileName = "HelloWorld.ppm";

	int width = 200;
	int height = 100;
	std::vector<ColorVec3> pixels;

	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			float r = float(j) / float(width);
			float g = float(i) / float(height);
			float b = 0.99f;

			pixels.push_back(ColorVec3(r, g, b));
		}
	}

	PPMFile picture = PPMFile(200, 100, pixels);
	picture.WriteToFile(fileName);

	PPMViewer viewer;

	viewer.OpenAndViewImage(viewerExe, fileName);
	return 0;
}