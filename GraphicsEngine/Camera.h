#pragma once
#include <string>
#include <vector>
#include "CoolMath.h"
#include "PPMFile.h"
#include "Ray.h"
#include "Scene.h"
#include "SceneObject.h"
#include "Window.h"
#include "Vector3.h"
#include <ppl.h>

#define _USE_MATH_DEFINES
#include <math.h>

/* Represents an object that contains a window. */
class Camera
{
private:
	Vector3 lowerLeft;
	Vector3 horizontal;
	Vector3 vertical;
	Vector3 direction;
	Window window;
	Vector3 position;
	std::vector<Vector3> pixels;
	const float antiAliasingSamples = 100.0;
	Vector3 x, y, w;
	float fov;
	float aspectRatio;
	float lensRadius;
	float focusDistance;
	float aperature;

	Vector3 GetPixelColor(const Ray& ray, Scene* scene, int depth);
	Ray GetRay(float u, float v);

public:
	Camera(const Window& window, const Vector3& position, const Vector3& direction, float fov) : window(window), position(position), direction(direction), fov(fov)
	{
		aperature = 0.08;
		focusDistance = (position - direction).Length();
		lensRadius = aperature / 2;

		pixels = std::vector<Vector3>(window.height * window.width);
		aspectRatio = float(window.width) / float(window.height);
		float theta = fov*M_PI / 180;
		float halfHeight = tan(theta / 2);
		float halfWidth = aspectRatio * halfHeight;
		w = Vector3::Unit(position - direction);
		x = Vector3::Unit(Vector3::Up().Cross(w));
		y = w.Cross(x);
		lowerLeft = position - halfWidth*focusDistance*x - halfHeight*focusDistance*y - focusDistance*w;
		horizontal = 2 * halfWidth*focusDistance*x;
		vertical = 2 * halfHeight*focusDistance*y;
	}

	~Camera();

	void Move(const Vector3& delta);
	std::string RenderScene(Scene* scene);
};

