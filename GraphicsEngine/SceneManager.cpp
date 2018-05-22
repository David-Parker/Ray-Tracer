#include "SceneManager.h"

SceneManager::~SceneManager()
{
}

void SceneManager::AddScene(Scene* scene)
{
	this->scenes[scene->GetName()] = scene;
}

void SceneManager::SetCurrentScene(const std::string& name)
{
	if (this->scenes.count(name) == false)
	{
		throw "Scene not found.";
	}

	this->currentScene = this->scenes[name];
}

std::string SceneManager::RenderCurrentScene()
{
	return this->mainCamera->RenderScene(this->currentScene);
}
