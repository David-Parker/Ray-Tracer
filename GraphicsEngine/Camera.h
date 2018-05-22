#pragma once
#include <math.h>
#include <string>
#include <vector>
#include "PPMFile.h"
#include "Ray.h"
#include "Scene.h"
#include "SceneObject.h"
#include "Window.h"
#include "Vector3.h"

/* Represents an object that contains a window. */
class Camera
{
private:
	Vector3 lowerLeft = Vector3(-2.0f, -1.0f, -1.0f);
	Vector3 horizontal = Vector3(4.0f, 0.0f, 0.0f);
	Vector3 vertical = Vector3(0.0f, 2.0f, 0.0f);
	Vector3 direction;
	Window window;
	Vector3 position;
	std::vector<Vector3> pixels;

public:
	Camera(const Window& window, const Vector3& position, const Vector3& direction) : window(window), position(position), direction(direction), pixels() {}
	~Camera();

	void Move(const Vector3& delta);
	std::string RenderScene(Scene* scene);
};

