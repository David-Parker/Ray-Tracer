#pragma once
#include <unordered_map>
#include <string>
#include "Camera.h"

class SceneManager
{
private:
	Camera* mainCamera;
	Scene* currentScene;
	std::unordered_map<std::string, Scene*> scenes;

public:
	SceneManager(Camera* mainCamera, Scene* currentScene) : mainCamera(mainCamera), currentScene(currentScene) {}
	~SceneManager();

	void AddScene(Scene* scene);
	void SetCurrentScene(const std::string& name);
	std::string RenderCurrentScene();
};

