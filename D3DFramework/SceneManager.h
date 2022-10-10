#pragma once
#include "pch.h"
#include "Scene.h"
#include "Singleton.h"


class SceneManager :public Singleton<SceneManager>
{
public:
	SceneManager();
	virtual ~SceneManager();


	void Update();
	void Render();


	void LoadScene(string sceneName);
	
	void CreateScene();

	

private:
	Scene* Scenes;

};

