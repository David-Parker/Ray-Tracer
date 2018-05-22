#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "PPMViewer.h"
#include "PPMFile.h"
#include "Vector3.h"
#include "Ray.h"
#include "SceneObject.h"
#include "SphereObject.h"
#include "Window.h"
#include "SceneManager.h"

const std::string viewerExe = ".\\OpenSeeIt\\OpenSeeIt.exe";

int main(char** argv, int argc)
{
	Window window = Window(200, 100);
	Camera camera = Camera(window, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0));
	Scene scene = Scene("Test");
	SceneObject* sphere = new SphereObject(Vector3(0.0, 0.0, -1.0), 0.5);
	SceneObject* sphere2 = new SphereObject(Vector3(0.0, -100.5, -1.0), 100.0);
	scene.AddObject(sphere2);
	scene.AddObject(sphere);
	SceneManager sm = SceneManager(&camera, &scene);

	PPMViewer viewer;

	viewer.OpenAndViewImage(viewerExe, sm.RenderCurrentScene());
	return 0;
}