#pragma once
#include <string>
#include <vector>
#include "SceneObject.h"

class Scene
{
private:
	std::string name;
	std::vector<SceneObject*> objects;

public:
	Scene(const std::string& name, const std::vector<SceneObject*> objects) : name(name), objects(objects) {}
	Scene(const std::string& name) : name(name), objects() {}
	~Scene();

	void AddObject(SceneObject* object);
	std::vector<SceneObject*>& GetObjects();
	std::string& GetName();
};

