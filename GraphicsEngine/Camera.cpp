#include "Camera.h"

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
			float u = float(j) / float(this->window.Width());
			float v = float(i) / float(this->window.Height());
			Vector3 offset = lowerLeft + u*horizontal + v*vertical;

			Ray ray = Ray(this->position, offset);

			std::vector<SceneObject*> objects = scene->GetObjects();
			Vector3 pixel = ray.Color();

			for each(auto& obj in objects)
			{
				std::vector<Hit> hits;

				if (obj->Intersects(ray, hits) == true)
				{
					Vector3 normal = hits[0].normal;

					Vector3 color = 0.5f * (normal + Vector3(1.0f, 1.0f, 1.0f));

					pixel = color;
				}
			}

			pixels.push_back(pixel);
		}
	}

	PPMFile picture = PPMFile(this->window.Width(), this->window.Height(), pixels);
	picture.WriteToFile(fileName);

	return fileName;
}
