#pragma once
#include "Scene.h"
#include "windows.h"

class Scene0:public Scene {
	HWND button_test;
public:
	Scene0() {}
	~Scene0() {}
	virtual void Start() override;

};