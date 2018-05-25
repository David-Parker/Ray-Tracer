#include "Camera.h"

Vector3 Camera::GetPixelColor(const Ray& ray, Scene* scene, int depth)
{
	std::vector<SceneObject*> objects = scene->GetObjects();
	Vector3 sky = ray.Color();
	Hit closestHit;
	float minDistance = INFINITY;

	for each(auto& obj in objects)
	{
		Hit hit;

		if (obj->Intersects(ray, hit, 0.001, INFINITY) == true)
		{
			if (hit.distance < minDistance)
			{
				closestHit = hit;
				minDistance = hit.distance;
			}
		}
	}

	if (minDistance != INFINITY)
	{
		Ray scattered;
		Vector3 attenuation;

		if (depth < 50 && closestHit.material->Scatter(ray, closestHit, attenuation, scattered))
		{
			return attenuation*GetPixelColor(scattered, scene, ++depth);
		}
		else
		{
			return Vector3(0, 0, 0);
		}
	}

	return sky;
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

				pixel += GetPixelColor(ray, scene, 0);
			}

			pixel /= antiAliasingSamples;
			pixel = Vector3(sqrt(pixel.x()), sqrt(pixel.y()), sqrt(pixel.z()));

			pixels.push_back(pixel);
		}
	}

	PPMFile picture = PPMFile(this->window.Width(), this->window.Height(), pixels);
	picture.WriteToFile(fileName);

	return fileName;
}
