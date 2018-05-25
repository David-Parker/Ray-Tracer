#include "Camera.h"

Vector3 Camera::GetPixelColor(const Ray& ray, Scene* scene, int depth)
{
	std::vector<SceneObject*> objects = scene->GetObjects();
	Vector3 sky = ray.Color();
	Hit closestHit;
	float minDistance = INFINITY;

	for (int i = 0; i < objects.size(); ++i)
	{
		SceneObject* obj = objects[i];
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

		if (depth < 20 && closestHit.material->Scatter(ray, closestHit, attenuation, scattered))
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
	int height = this->window.height;
	int width = this->window.width;

	for (int i = height - 1; i >= 0; --i)
	{
		size_t t = width;

		concurrency::parallel_for(size_t(0), t, [&](size_t j)
		{
			Vector3 pixel;

			for (int k = 0; k < antiAliasingSamples; k++)
			{
				float r = CoolMath::RandomScalar();

				float u = float(j + r) / float(width);
				float v = float(i + r) / float(height);
				Vector3 offset = lowerLeft + u*horizontal + v*vertical - this->position;

				Ray ray = Ray(this->position, offset);

				pixel += GetPixelColor(ray, scene, 0);
			}

			pixel /= antiAliasingSamples;
			pixel = Vector3(sqrt(pixel.x()), sqrt(pixel.y()), sqrt(pixel.z()));

			pixels[((height - i - 1)*width) + j] = pixel;
		});
	}

	PPMFile picture = PPMFile(this->window.width, this->window.height, pixels);
	picture.WriteToFile(fileName);

	return fileName;
}
