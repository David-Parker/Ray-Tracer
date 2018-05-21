#include "PPMFile.h"

PPMFile::PPMFile(int width, int height, const std::vector<Vector3>& pixelData) : width(width), height(height), pixelData(pixelData)
{
}

PPMFile::~PPMFile()
{
}

void PPMFile::WriteToFile(std::string filePath)
{
	std::string fileName = filePath;
	std::ofstream myfile;
	myfile.open(fileName);

	myfile << "P3" << std::endl;
	myfile << width << " " << height << std::endl;
	myfile << "255" << std::endl;

	for each (Vector3 pixel in pixelData)
	{
		int ir = int(255.99*pixel.x());
		int ig = int(255.99*pixel.y());
		int ib = int(255.99*pixel.z());

		myfile << ir << " " << ig << " " << ib << std::endl;
	}

	myfile.close();
}
