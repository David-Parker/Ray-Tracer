#include <iostream>
#include <fstream>
#include <string>

int main(char** argv, int argc)
{
	std::ofstream myfile;
	myfile.open("test.ppm");

	int xl = 200;
	int yl = 100;

	myfile << "P3" << std::endl;
	myfile << xl << " " << yl << std::endl;
	myfile << "255" << std::endl;

	for (int i = yl - 1; i >= 0; i--)
	{
		for (int j = 0; j < xl; j++)
		{
			float r = float(j) / float(xl);
			float g = float(i) / float(yl);
			float b = 0.2f;
			int ir = int(255.99*r);
			int ig = int(255.99*g);
			int ib = int(255.99*b);

			myfile << ir << " " << ig << " " << ib << std::endl;
		}
	}

	myfile.close();
	return 0;
}