#pragma once
#include <fstream>
#include <string>

/* Execs an exteranl process to view PPM files */
class PPMViewer
{
public:
	PPMViewer();
	~PPMViewer();

	void OpenAndViewImage(const std::string& pathToViewer, const std::string& file);
};

