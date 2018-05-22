#include "Scene.h"

Scene::~Scene()
{
}

void Scene::AddObject(SceneObject * object)
{
	if (object == nullptr)
	{
		throw "Argument null: objects";
	}

	this->objects.push_back(object);
}

std::vector<SceneObject*>& Scene::GetObjects()
{
	return this->objects;
}

std::string& Scene::GetName()
{
	return name;
}
