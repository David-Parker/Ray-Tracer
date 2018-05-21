#include "PPMViewer.h"

#ifdef  _WIN32
#include <Windows.h>
#endif  // _WIN32

PPMViewer::PPMViewer()
{
}

PPMViewer::~PPMViewer()
{
}

/*	Function implementation will be platform specific.
	Do not use with inputs over a network, directory traversal attack is possible */
void PPMViewer::OpenAndViewImage(const std::string& pathToViewer, const std::string& file)
{
	if (file.empty())
	{
		throw "file cannot be empty.";
	}

#ifndef _WIN32
	throw "Function is not currently supported on platforms other than Windows";
#endif // !_WIN32

#ifdef _WIN32
	std::string path = pathToViewer + " " + file;

	LPTSTR cmdArgs = const_cast<char *>(path.c_str());
	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;

	if (CreateProcess(NULL, cmdArgs, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
	{
		WaitForSingleObject(processInfo.hProcess, INFINITE);
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
	else
	{
		throw "Image viewer process failed to launch.";
	}
#endif // _WIN32
}
