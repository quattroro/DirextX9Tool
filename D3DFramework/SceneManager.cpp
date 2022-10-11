#include "pch.h"
#include "SceneManager.h"


//void SceneManager::Update()
//{
//	if (_activeScene == nullptr)
//		return;
//
//	_activeScene->Update();
//	_activeScene->LateUpdate();
//	_activeScene->FinalUpdate();
//}

//// TEMP
//void SceneManager::Render()
//{
//	if (_activeScene == nullptr)
//		return;
//
//	const vector<shared_ptr<GameObject>>& gameObjects = _activeScene->GetGameObjects();
//	for (auto& gameObject : gameObjects)
//	{
//		if (gameObject->GetCamera() == nullptr)
//			continue;
//
//		gameObject->GetCamera()->Render();
//	}
//}

//void Engine::Update()
//{
//	GET_SINGLE(Input)->Update();
//	GET_SINGLE(Timer)->Update();
//	GET_SINGLE(SceneManager)->Update();
//
//	Render();
//
//	ShowFps();
//}