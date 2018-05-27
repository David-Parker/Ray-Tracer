#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Glass.h"
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
	Window window = Window(1920, 1080);
	Vector3 cameraCenter = Vector3(-3.5, 1.5, 1.75);
	Camera camera = Camera(window, cameraCenter, Vector3(0.0, 0.0, -1.0), 75);
	Scene scene = Scene("Test");
	SceneObject* ground = new SphereObject(Vector3(0.0, -1000, 0.0), 1000, new Lambertian(Vector3(0.3, 0.3, 0.4)));
	SceneObject* sphere1 = new SphereObject(Vector3(1.0, 1, 0.0), 1, new Metal());
	SceneObject* sphere2 = new SphereObject(Vector3(1.0, 1, -4.0), 1, new Glass());
	SceneObject* sphere3 = new SphereObject(Vector3(-2.0, 1, -2.0), 1, new Lambertian(Vector3(0.9, 0.2, 0.9)));
	scene.AddObject(ground);
	scene.AddObject(sphere1);
	scene.AddObject(sphere2);
	scene.AddObject(sphere3);
	Vector3 center = Vector3(0, 0, 0);

	for (int i = -11; i < 11; i++)
	{
		for (int j = -11; j < 11; j++)
		{
			float rand = CoolMath::RandomScalar();
			Material* mat;
			SceneObject* obj;
			float radius = 0.2f;
			float randX = (CoolMath::RandomScalar() - 0.5) * 2;
			float randZ = (CoolMath::RandomScalar() - 0.5) * 2;

			Vector3 displacement = Vector3(i + 1.3*randX, 0, j + 1.3*randZ);

			if (rand < 0.7)
			{
				mat = new Lambertian(Vector3(CoolMath::RandomScalar(), CoolMath::RandomScalar(), CoolMath::RandomScalar()));
			}
			else if (rand < 0.85)
			{
				mat = new Metal();
			}
			else
			{
				mat = new Glass();
			}

			if ((displacement - cameraCenter).Length() < 4.0) continue;

			obj = new SphereObject(center + displacement + Vector3(0, radius, 0), radius, mat);

			scene.AddObject(obj);
		}
	}

	SceneManager sm = SceneManager(&camera, &scene);

	PPMViewer viewer;

	viewer.OpenAndViewImage(viewerExe, sm.RenderCurrentScene());

	return 0;
}