#pragma once
#include <define.h>
#include <windows.h>
class Scene;
class OBJ;
class SceneManager {
	SINGLETON(SceneManager)
private:
	Scene* scene[SCENE_TYPE::END];
	SceneManager();
	~SceneManager();

public:
	Scene* curScene;
	void Init();
	void Update();
	void Render(HDC);
	void ChangeScene(SCENE_TYPE);
	void AddObject(OBJ*);
	void AddObject(OBJ*, SCENE_TYPE);
};