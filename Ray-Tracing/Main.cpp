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
	std::vector<Vector3> pixels;

	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			Vector3 rgb = Vector3(float(j) / float(width), float(i) / float(height), 0.2f);

			pixels.push_back(rgb);
		}
	}

	PPMFile picture = PPMFile(200, 100, pixels);
	picture.WriteToFile(fileName);

	PPMViewer viewer;

	viewer.OpenAndViewImage(viewerExe, fileName);
	return 0;
}