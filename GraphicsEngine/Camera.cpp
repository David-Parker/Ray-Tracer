#include "Camera.h"

Vector3 Camera::GetPixelColor(const Ray& ray, Scene* scene)
{
	std::vector<SceneObject*> objects = scene->GetObjects();
	Vector3 pixel = ray.Color();
	Hit closestHit;
	SceneObject* closestObject = nullptr;
	float minDistance = INFINITY;

	for each(auto& obj in objects)
	{
		Hit hit;

		if (obj->Intersects(ray, hit) == true)
		{
			if (hit.distance < minDistance)
			{
				closestHit = hit;
				closestObject = obj;
				minDistance = hit.distance;
			}
		}
	}

	if (minDistance != INFINITY)
	{
		Vector3 reflection = closestObject->GetReflectionVector(closestHit);
		Vector3 color = 0.5f * GetPixelColor(Ray(closestHit.point, reflection), scene);

		pixel = color;
	}

	return pixel;
}

Camera::~Camera()
{
}

void Camera::Move(const Vector3& delta)
{
	this->position += delta;
}

std::string Camera::RenderScene(Scene* scene)
{
	if (scene == nullptr)
	{
		throw "Argument null: scene";
	}

	std::string fileName = scene->GetName() + ".ppm";

	for (int i = this->window.Height() - 1; i >= 0; i--)
	{
		for (int j = 0; j < this->window.Width(); j++)
		{
			Vector3 pixel;

			for (int k = 0; k < antiAliasingSamples; k++)
			{
				float r = CoolMath::RandomScalar();

				float u = float(j + r) / float(this->window.Width());
				float v = float(i + r) / float(this->window.Height());
				Vector3 offset = lowerLeft + u*horizontal + v*vertical - this->position;

				Ray ray = Ray(this->position, offset);

				pixel += GetPixelColor(ray, scene);
			}

			pixels.push_back(pixel / antiAliasingSamples);
		}
	}

	PPMFile picture = PPMFile(this->window.Width(), this->window.Height(), pixels);
	picture.WriteToFile(fileName);

	return fileName;
}
