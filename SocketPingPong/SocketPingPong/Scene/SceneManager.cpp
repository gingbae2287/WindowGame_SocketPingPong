#include"SceneManager.h"
#include "Scene1.h"
SceneManager::SceneManager() :
	scene{}, curScene(nullptr)
{
	/*for (int i = 0; i < SCENE_TYPE::END; i++) {
		scene[i] = new Scene;
	}*/
	//ChangeScene(SCENE_TYPE::START);
}


SceneManager::~SceneManager() {
	for (int i = 0; i < SCENE_TYPE::END; i++) {
		if(scene[i]!=nullptr) delete(scene[i]);
	}
}
void SceneManager::Init() {
	scene[SCENE_TYPE::START] = new Scene1;
	ChangeScene(SCENE_TYPE::START);

	curScene->Start();
}


void SceneManager::Update() { 
	curScene->Update(); 
}
void SceneManager::Render(HDC hdc) {
	curScene->Render(hdc);
}
void SceneManager::ChangeScene(SCENE_TYPE sceneNum) {
	curScene = scene[sceneNum];
	ColliderManager::Instance()->ChangeScene(curScene);
}

void SceneManager::AddObject(OBJ* obj) {
	curScene->AddObject(obj);
}
void SceneManager::AddObject(OBJ*obj , SCENE_TYPE sceneNum) {
	scene[sceneNum]->AddObject(obj);
}

