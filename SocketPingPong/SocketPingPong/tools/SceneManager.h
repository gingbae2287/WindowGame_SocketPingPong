#pragma once
#include "Scene.h"
enum SCENE_TYPE {
	START,
	END,
};
class SceneManager {
private:
	Scene* scene[SCENE_TYPE::END];
	Scene* curScene;
public:
	void Update() {curScene->Update();}
	void Render() { curScene->Render(); }
};