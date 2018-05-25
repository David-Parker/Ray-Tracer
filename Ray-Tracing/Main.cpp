#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Metal.h"
#include "Lambertian.h"
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
	Window window = Window(400, 200);
	Camera camera = Camera(window, Vector3(0.0, 0.0, 0.0), Vector3(0.0, 0.0, 0.0));
	/*Scene scene = Scene("Test");
	SceneObject* sphere1 = new SphereObject(Vector3(0.0, 0.0, -1.0), 0.5, new Lambertian(Vector3(0.2,0.9,0.3)));
	SceneObject* sphere2 = new SphereObject(Vector3(-1.0, 0.0, -1.0), 0.5, new Metal());
	SceneObject* sphere3 = new SphereObject(Vector3(1.0, 0.0, -1.0), 0.5, new Metal());
	SceneObject* sphere4 = new SphereObject(Vector3(0.0, -100.5, -1.0), 100.0, new Lambertian(Vector3(0.8, 0.3, 0.3)));
	scene.AddObject(sphere1);
	scene.AddObject(sphere2);
	scene.AddObject(sphere3);
	scene.AddObject(sphere4);
	SceneManager sm = SceneManager(&camera, &scene);

	PPMViewer viewer;

	viewer.OpenAndViewImage(viewerExe, sm.RenderCurrentScene());*/

	return 0;
}